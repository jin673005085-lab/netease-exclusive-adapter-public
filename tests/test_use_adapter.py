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


if __name__ == "__main__":
    unittest.main()
