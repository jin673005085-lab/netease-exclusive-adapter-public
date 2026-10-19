"""Build an exact-build compatibility package; never execute or modify CloudMusic."""
from pathlib import Path
import argparse
import copy
import hashlib
import json
import zipfile

import pefile

EXPECTED = {
    "cloudmusic.exe": "16689d9731121f0f15116205d73a472748de932b6a848e36b55b60501cbf0ede",
    "cloudmusic.dll": "7f667f876caf94bc3dac3b0070d3e495117005fafdcf18b6aaa51eb004edac8c",
    "libcef.dll": "a2a441490a9600f7e06b8c4dc609354ff7214add445a55c8fa699760d264e210",
}


def sha(data):
    return hashlib.sha256(data).hexdigest()


def require(condition, message):
    if not condition:
        raise ValueError(message)


def build(source, client, out, manager):
    source, CLIENT, OUT = Path(source), Path(client), Path(out)
    require(not OUT.exists(), "Output already exists; preserve it or choose a fresh directory.")
    for name, digest in EXPECTED.items():
        require(sha((CLIENT / name).read_bytes()) == digest, f"Client changed: {name}")
    binary = (CLIENT / "cloudmusic.dll").read_bytes()
    image = pefile.PE(data=binary, fast_load=True)
    require(image.FILE_HEADER.Machine == 0x8664, "Expected x64 client")
    # shortcut: exact-build coordinates, analyze every different client hash before adding support.
    anchors = {
        0x108F950: "488954241048894c2408555657b8901f",
        0x108FE0D: "4805e8000000",
        0x108FE1A: "4881c130010000",
        0x108FE24: "e877420000",
        0x1090614: "8b9058010000",
        0x1090628: "ff5018",
        0x10940A0: "488954241048894c240855574881ece8000000",
    }
    for rva, encoded in anchors.items():
        wanted = bytes.fromhex(encoded)
        offset = image.get_offset_from_rva(rva)
        require(binary[offset:offset + len(wanted)] == wanted, f"Code anchor differs at {rva:#x}")
    require(binary.count(bytes.fromhex(anchors[0x108F950])) == 1, "Ambiguous native-open prefix")
    manifest = (source / "bundle.json").read_bytes()
    require(sha(manifest) == "4798ae7c73287579b091cb8dc226c123cf8c001f3b768099012ddaa8c1915159",
            "Expected the original 2026.10.15.4 bundle.json; do not edit its hashes")
    meta = json.loads(manifest.decode("utf-8"))
    for record in meta["files"]:
        require(sha((source / record["path"]).read_bytes()) == record["sha256"], "Original payload changed")
    old_profile = meta["applications"]["NetEase"]["profiles"][1]
    require(old_profile["version"] == "3.1.41.205564", "Unexpected profile order")
    require(old_profile["fingerprints"]["libcef.dll"] == EXPECTED["libcef.dll"], "CEF mismatch")
    replacements = {
        "3.1.41.205564": "3.1.41.205529",
        old_profile["fingerprints"]["cloudmusic.exe"]: EXPECTED["cloudmusic.exe"],
        old_profile["fingerprints"]["cloudmusic.dll"]: EXPECTED["cloudmusic.dll"],
    }
    patched = {}
    changes = []
    for filename in ("nc-exclusive-hook.dll", "nc-exclusive-launcher.exe"):
        relative = "NetEase/" + filename
        original = (source / relative).read_bytes()
        modified = original
        for old, new in replacements.items():
            before, after = old.encode("utf-16le"), new.encode("utf-16le")
            require(len(before) == len(after) and modified.count(before) == 1, "Ambiguous replacement")
            offset = modified.index(before)
            changes.append({"file": relative, "offset": offset, "bytes": len(before), "old": old, "new": new})
            modified = modified[:offset] + after + modified[offset + len(before):]
        pe = pefile.PE(data=original, fast_load=True)
        text = next(s for s in pe.sections if s.Name.rstrip(b"\0") == b".text")
        start, size = text.PointerToRawData, text.SizeOfRawData
        require(original[start:start + size] == modified[start:start + size], "Machine code changed")
        require(len(original) == len(modified), "File layout changed")
        allowed = {i for change in changes if change["file"] == relative
                   for i in range(change["offset"], change["offset"] + change["bytes"])}
        require(all(a == b or i in allowed for i, (a, b) in enumerate(zip(original, modified))), "Unexpected diff")
        patched[relative] = modified
    meta = copy.deepcopy(meta)
    app = meta["applications"]["NetEase"]
    app["version"] = "3.1.36.205322 / 3.1.41.205529 x64 (local static candidate)"
    app["supportedVersions"][1] = "3.1.41.205529 x64 (static candidate; playback unverified)"
    app["fingerprints"] = EXPECTED.copy()
    profile = app["profiles"][1]
    profile["version"] = "3.1.41.205529"
    profile["fingerprints"] = EXPECTED.copy()
    profile["profile"] = "Local static compatibility candidate; playback unverified"
    profile.pop("observedInitializeCallReturnRva", None)
    profile["staticInitializeCallReturnRva"] = "0x109062b"
    meta["build"] = "2026.10.15.4-local-205529-static-candidate"
    for record in meta["files"]:
        if record["path"] in patched:
            record["sha256"] = sha(patched[record["path"]])
    for record in app["files"]:
        relative = "NetEase/" + record["name"]
        if relative in patched:
            record["sha256"] = sha(patched[relative])
    manager_bytes = Path(manager).read_bytes()
    require(sha(manager_bytes) == "d4979af1b443eef9e216de50f229c2ed3075265032d2b043152db1f676450999",
            "Expected the original 2026.10.15.4 management script")
    OUT.mkdir(parents=True)
    archive = OUT / "payload.zip"
    with zipfile.ZipFile(archive, "x", compression=zipfile.ZIP_DEFLATED) as z:
        # Only package verified manifest entries, never unrelated local files.
        for relative in sorted([record["path"] for record in meta["files"]] + ["bundle.json"]):
            path = source / relative
            data = patched.get(relative, path.read_bytes())
            if relative == "bundle.json":
                data = (json.dumps(meta, indent=2, ensure_ascii=False) + "\n").encode("utf-8")
            z.writestr(relative, data)
    with zipfile.ZipFile(archive) as z:
        require(z.testzip() is None, "ZIP CRC failure")
        for record in meta["files"]:
            require(sha(z.read(record["path"])) == record["sha256"], "New manifest hash mismatch")
    (OUT / "Manage-AudioExclusive.ps1").write_bytes(manager_bytes)
    result = {"status": "build-checks-passed-playback-not-tested-by-builder", "client_version": "3.1.41.205529",
              "client_sha256": EXPECTED, "changes": changes, "machine_code_unchanged": True,
              "code_anchors": {hex(k): v for k, v in anchors.items()},
              "payload_sha256": sha(archive.read_bytes()), "original_client_unchanged": True}
    for name, digest in EXPECTED.items():
        require(sha((CLIENT / name).read_bytes()) == digest, f"Client changed during build: {name}")
    (OUT / "candidate-checks.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--payload-dir", required=True, type=Path,
                        help="Original extracted payload directory containing bundle.json")
    parser.add_argument("--client", required=True, type=Path, help="CloudMusic installation directory")
    parser.add_argument("--out", required=True, type=Path, help="New output directory; must not exist")
    parser.add_argument("--manager", required=True, type=Path,
                        help="Original management script, supplied locally and verified by SHA-256")
    args = parser.parse_args()
    build(args.payload_dir, args.client, args.out, args.manager)
