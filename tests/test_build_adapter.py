import importlib.util
import json
import os
from pathlib import Path
import tempfile
import unittest


spec = importlib.util.spec_from_file_location(
    "build_adapter", Path(__file__).resolve().parents[1] / "scripts" / "build_adapter.py")
adapter = importlib.util.module_from_spec(spec)
spec.loader.exec_module(adapter)


class BuildGuards(unittest.TestCase):
    def test_existing_output_is_preserved(self):
        with tempfile.TemporaryDirectory() as folder:
            out = Path(folder) / "existing"
            out.mkdir()
            marker = out / "keep.txt"
            marker.write_text("keep", encoding="utf-8")
            with self.assertRaisesRegex(ValueError, "Output already exists"):
                adapter.build(Path(folder) / "missing", Path(folder) / "missing", out,
                              Path(folder) / "missing.ps1")
            self.assertEqual(marker.read_text(encoding="utf-8"), "keep")

    def test_wrong_client_hash_creates_no_output(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / "cloudmusic.exe").write_bytes(b"unsupported client")
            out = root / "output"
            with self.assertRaisesRegex(ValueError, "Client changed: cloudmusic.exe"):
                adapter.build(root / "missing", root, out, root / "missing.ps1")
            self.assertFalse(out.exists())


@unittest.skipUnless(os.getenv("NCE_TEST_CLIENT") and os.getenv("NCE_TEST_PAYLOAD_DIR"),
                     "Optional original payload and exact client are not provided")
class LocalIntegrationGuards(unittest.TestCase):
    def test_edited_manifest_is_rejected(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / "bundle.json").write_text("{}", encoding="utf-8")
            with self.assertRaisesRegex(ValueError, "Expected the original"):
                adapter.build(root, os.environ["NCE_TEST_CLIENT"], root / "output", root / "missing.ps1")
            self.assertFalse((root / "output").exists())

    def test_corrupt_payload_is_rejected(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            manifest = (Path(os.environ["NCE_TEST_PAYLOAD_DIR"]) / "bundle.json").read_bytes()
            (root / "bundle.json").write_bytes(manifest)
            first = json.loads(manifest)["files"][0]["path"]
            target = root / first
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(b"corrupt payload")
            with self.assertRaisesRegex(ValueError, "Original payload changed"):
                adapter.build(root, os.environ["NCE_TEST_CLIENT"], root / "output", root / "missing.ps1")
            self.assertFalse((root / "output").exists())

    def test_modified_management_script_is_rejected(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            manager = root / "manager.ps1"
            manager.write_text("Write-Output 'changed'", encoding="utf-8")
            with self.assertRaisesRegex(ValueError, "Expected the original.*management script"):
                adapter.build(os.environ["NCE_TEST_PAYLOAD_DIR"], os.environ["NCE_TEST_CLIENT"],
                              root / "output", manager)
            self.assertFalse((root / "output").exists())


if __name__ == "__main__":
    unittest.main()
