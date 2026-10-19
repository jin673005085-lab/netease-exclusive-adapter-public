import importlib.util
import json
import os
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch
import zipfile


sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "scripts"))
spec = importlib.util.spec_from_file_location("use_adapter", Path(sys.path[0]) / "use_adapter.py")
adapter = importlib.util.module_from_spec(spec)
spec.loader.exec_module(adapter)


class SetupGuards(unittest.TestCase):
    def test_bundled_runtime_matches_manifest(self):
        with tempfile.TemporaryDirectory() as folder:
            payload, manager = adapter.unpack_bundled(folder)
            self.assertEqual(adapter.sha(manager.read_bytes()), adapter.MANAGER_HASH)
            meta = json.loads((payload / "bundle.json").read_text(encoding="utf-8"))
            for record in meta["files"]:
                self.assertEqual(adapter.sha((payload / record["path"]).read_bytes()), record["sha256"])

    def test_corrupt_bundled_archive_creates_no_output(self):
        with tempfile.TemporaryDirectory() as folder:
            destination = Path(folder) / "output"
            manager = (adapter.ROOT / "scripts/Manage-AudioExclusive.ps1").read_bytes()
            with self.assertRaisesRegex(ValueError, "Plugin archive integrity"):
                adapter.unpack_runtime(manager, b"corrupt archive", destination)
            self.assertFalse(destination.exists())

    def test_wrong_installer_creates_no_files(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            setup = root / "setup.exe"
            setup.write_bytes(b"not the expected installer")
            with self.assertRaisesRegex(ValueError, "Installer does not match"):
                adapter.unpack_setup(setup, root / "output")
            self.assertFalse((root / "output").exists())

    def test_existing_build_is_preserved_without_installing(self):
        with tempfile.TemporaryDirectory() as folder:
            out = Path(folder) / "existing"
            out.mkdir()
            (out / "keep.txt").write_text("keep", encoding="utf-8")
            with patch.object(adapter, "run_manager") as manager:
                with self.assertRaisesRegex(ValueError, "Output already exists"):
                    adapter.main(["--action", "Install", "--setup", "missing.exe",
                                  "--client", folder, "--out", str(out)])
                manager.assert_not_called()
            self.assertEqual((out / "keep.txt").read_text(encoding="utf-8"), "keep")


@unittest.skipUnless(os.name == "nt", "PowerShell entry requires Windows")
class PowerShellGuards(unittest.TestCase):
    def test_corrupt_ready_runtime_cannot_install(self):
        import subprocess
        shell = Path(os.environ["WINDIR"]) / "System32/WindowsPowerShell/v1.0/powershell.exe"
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / "scripts").mkdir()
            (root / "runtime").mkdir()
            for name in ["Use-Adapter.ps1", "Manage-AudioExclusive.ps1"]:
                (root / "scripts" / name).write_bytes((adapter.ROOT / "scripts" / name).read_bytes())
            (root / "runtime/205529.zip").write_bytes(b"corrupt runtime")
            state = root / "state"
            env = os.environ.copy()
            env["LOCALAPPDATA"] = str(state)
            result = subprocess.run([str(shell), "-NoLogo", "-NoProfile", "-ExecutionPolicy", "Bypass",
                                     "-File", str(root / "scripts/Use-Adapter.ps1"),
                                     "-Action", "Install", "-Client", str(root / "missing")],
                                    env=env, capture_output=True, timeout=30)
            self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
            self.assertFalse(state.exists(), "Corrupt runtime created installation state")


@unittest.skipUnless(os.getenv("NCE_TEST_SETUP") and os.getenv("NCE_TEST_CLIENT"),
                     "Optional installer and exact client are not provided")
class LocalSetupIntegration(unittest.TestCase):
    def test_installer_build_does_not_install_or_change_client(self):
        with tempfile.TemporaryDirectory() as folder:
            out = Path(folder) / "output"
            client = Path(os.environ["NCE_TEST_CLIENT"])
            hashes = {name: adapter.sha((client / name).read_bytes())
                      for name in ("cloudmusic.exe", "cloudmusic.dll", "libcef.dll")}
            with patch.object(adapter, "run_manager") as manager:
                adapter.main(["--action", "Build", "--setup", os.environ["NCE_TEST_SETUP"],
                              "--client", str(client), "--out", str(out)])
                manager.assert_not_called()
            self.assertEqual(adapter.sha((out / "Manage-AudioExclusive.ps1").read_bytes()),
                             adapter.MANAGER_HASH)
            with zipfile.ZipFile(out / "payload.zip") as archive:
                meta = json.loads(archive.read("bundle.json"))
                self.assertEqual(meta["applications"]["NetEase"]["profiles"][1]["version"],
                                 "3.1.41.205529")
                for record in meta["files"]:
                    self.assertEqual(adapter.sha(archive.read(record["path"])), record["sha256"])
            for name, digest in hashes.items():
                self.assertEqual(adapter.sha((client / name).read_bytes()), digest)


@unittest.skipUnless(os.getenv("NCE_TEST_CLIENT"), "Optional exact client is not provided")
class BundledIntegration(unittest.TestCase):
    def test_build_without_installer_does_not_install(self):
        with tempfile.TemporaryDirectory() as folder:
            out = Path(folder) / "package"
            with patch.object(adapter, "unpack_setup") as setup, patch.object(adapter, "run_manager") as manager:
                adapter.main(["--action", "Build", "--client", os.environ["NCE_TEST_CLIENT"],
                              "--out", str(out)])
                setup.assert_not_called()
                manager.assert_not_called()
            with zipfile.ZipFile(out / "payload.zip") as generated, \
                    zipfile.ZipFile(adapter.ROOT / "runtime/205529.zip") as shipped:
                self.assertEqual(generated.namelist(), shipped.namelist())
                for name in generated.namelist():
                    self.assertEqual(generated.read(name), shipped.read(name))

    @unittest.skipUnless(os.name == "nt", "PowerShell entry requires Windows")
    def test_powershell_check_and_rejection_do_not_write_state(self):
        import subprocess
        shell = Path(os.environ["WINDIR"]) / "System32/WindowsPowerShell/v1.0/powershell.exe"
        script = adapter.ROOT / "scripts/Use-Adapter.ps1"
        with tempfile.TemporaryDirectory() as folder:
            state = Path(folder) / "state"
            env = os.environ.copy()
            env["LOCALAPPDATA"] = str(state)
            for client, expected in [(os.environ["NCE_TEST_CLIENT"], 0), (str(Path(folder) / "missing"), 1)]:
                result = subprocess.run([str(shell), "-NoLogo", "-NoProfile", "-ExecutionPolicy", "Bypass",
                                         "-File", str(script), "-Action", "Check", "-Client", client],
                                        env=env, capture_output=True, timeout=30)
                self.assertEqual(result.returncode, expected, result.stdout + result.stderr)
                self.assertFalse(state.exists(), "Compatibility check modified installation state")


if __name__ == "__main__":
    unittest.main()
