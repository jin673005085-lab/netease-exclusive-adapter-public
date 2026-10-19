"""Prepare and manage the 205529 adapter using a locally supplied installer."""
import argparse
import contextlib
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import zipfile

import pefile

from build_adapter import build, require, sha


SETUP_HASH = "deebb7ce9f7aa014330975ef4383e18b2f1275d51e409b98f14d98c9f3a787ac"
MANAGER_HASH = "d4979af1b443eef9e216de50f229c2ed3075265032d2b043152db1f676450999"
PAYLOAD_HASH = "8695c9d18f117533d62520484db742eb5d705b028e92a8ea9d8ae0ba410cf42d"
ROOT = Path(__file__).resolve().parents[1]


def unpack_setup(setup, destination):
    data = Path(setup).read_bytes()
    require(sha(data) == SETUP_HASH, "Installer does not match AudioExclusive 2026.10.15.4.")
    resources = {}
    with pefile.PE(data=data) as image:
        for kind in image.DIRECTORY_ENTRY_RESOURCE.entries:
            if kind.id == 10:
                for entry in kind.directory.entries:
                    if entry.id in (101, 102):
                        require(len(entry.directory.entries) == 1, "Ambiguous installer resource")
                        resource = entry.directory.entries[0].data.struct
                        resources[entry.id] = image.get_data(resource.OffsetToData, resource.Size)
    require(sha(resources.get(101, b"")) == MANAGER_HASH, "Management script integrity check failed.")
    payload = resources.get(102, b"")
    require(sha(payload) == PAYLOAD_HASH, "Plugin archive integrity check failed.")
    destination = Path(destination)
    destination.mkdir(parents=True, exist_ok=True)
    manager = destination / "Manage-AudioExclusive.ps1"
    manager.write_bytes(resources[101])
    # Only extract the exact pinned archive after its SHA-256 check.
    with zipfile.ZipFile(io.BytesIO(payload)) as archive:
        archive.extractall(destination / "payload")
    return destination / "payload", manager


def run_manager(manager, action, client=None, bundle=None, manifest=None):
    require(os.name == "nt", "Installation and management require Windows.")
    manager = Path(manager).resolve()
    require(sha(manager.read_bytes()) == MANAGER_HASH, "Management script integrity check failed.")
    shell = Path(os.environ["WINDIR"]) / "System32/WindowsPowerShell/v1.0/powershell.exe"
    command = [str(shell), "-NoLogo", "-NoProfile", "-ExecutionPolicy", "Bypass"]
    if action != "Install":
        subprocess.run(command + ["-File", str(manager), "-Action", action,
                                  "-App", "NetEase", "-NoMenu"], check=True)
        return
    env = os.environ.copy()
    env.update(NCE_MANAGER=str(manager), NCE_BUNDLE=str(bundle.resolve()),
               NCE_MANIFEST=str(manifest.resolve()), NCE_CLIENT=str(client.resolve()),
               NCE_BUNDLE_HASH=sha(bundle.read_bytes()))
    # Pass paths as environment values, never interpolate them into PowerShell code.
    preflight = r"""
$ErrorActionPreference = 'Stop'
. $env:NCE_MANAGER -LibraryOnly
$script:Meta = Get-Content -LiteralPath $env:NCE_MANIFEST -Raw -Encoding UTF8 | ConvertFrom-Json
$found = Find-Application 'NetEase'
if ($found.status -ne 'Supported' -or [IO.Path]::GetFullPath($found.path) -ine [IO.Path]::Combine($env:NCE_CLIENT, 'cloudmusic.exe')) {
    throw 'The selected CloudMusic installation was not detected. Open that copy of CloudMusic, then retry. No plugin was installed.'
}
& $env:NCE_MANAGER -Action Install -App NetEase -BundlePath $env:NCE_BUNDLE -BundleHash $env:NCE_BUNDLE_HASH -NoMenu
exit $LASTEXITCODE
"""
    subprocess.run(command + ["-Command", preflight], env=env, check=True)
    state = Path(os.environ["LOCALAPPDATA"]) / "AudioExclusive/state/NetEase.json"
    record = json.loads(state.read_text(encoding="utf-8-sig"))
    require(record["enabled"] and Path(record["target"]).resolve() == client.resolve() / "cloudmusic.exe",
            "Installation did not enable the selected client; check the manager output.")


def prompt_path(message):
    return Path(input(message).strip().strip('"')).expanduser().resolve()


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--action", choices=["Install", "Build", "Launch", "Status", "Remove"])
    parser.add_argument("--setup", type=Path, help="Local AudioExclusive 2026.10.15.4 installer")
    parser.add_argument("--client", type=Path, help="CloudMusic installation directory")
    parser.add_argument("--out", type=Path, help="New output directory (optional)")
    args = parser.parse_args(argv)
    if args.action is None:
        print("网易云音乐独占输出适配工具 · 3.1.41.205529 x64")
        print("1 安装   2 启动   3 状态   4 移除   5 仅构建")
        choice = input("请选择 [1]: ").strip() or "1"
        require(choice in "12345" and len(choice) == 1, "Invalid menu choice.")
        args.action = {"1": "Install", "2": "Launch", "3": "Status", "4": "Remove", "5": "Build"}[choice]
    if args.action not in ("Install", "Build"):
        manager = Path(os.environ["LOCALAPPDATA"]) / "AudioExclusive/Manage-AudioExclusive.ps1"
        run_manager(manager, args.action)
        return
    setup = args.setup or prompt_path("AudioExclusive 安装包路径（可拖入文件）: ")
    client = args.client or prompt_path("网易云安装目录（包含 cloudmusic.exe）: ")
    client = client.resolve()
    if args.out is not None:
        require(not args.out.exists(), "Output already exists; choose a fresh directory.")
    if args.action == "Install":
        print("安装可能关闭并重新打开网易云，请先保存播放进度。独占播放前请调低 DAC 音量。")
    with tempfile.TemporaryDirectory(prefix="nce-input-") as work:
        work = Path(work)
        payload, manager = unpack_setup(setup, work)
        if args.out is None:
            (ROOT / "dist").mkdir(exist_ok=True)
            args.out = Path(tempfile.mkdtemp(prefix="205529-", dir=ROOT / "dist")) / "package"
        with contextlib.redirect_stdout(io.StringIO()):
            build(payload, client, args.out, manager)
        print("兼容包已生成:", args.out.resolve())
        if args.action == "Build":
            return
        with zipfile.ZipFile(args.out / "payload.zip") as archive:
            manifest = work / "adapted-bundle.json"
            manifest.write_bytes(archive.read("bundle.json"))
        run_manager(args.out / "Manage-AudioExclusive.ps1", "Install", client,
                    args.out / "payload.zip", manifest)
        print("安装完成。请从开始菜单 AudioExclusive → 网易云音乐（独占插件）启动，并在播放设置中开启独占。")


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError, pefile.PEFormatError) as error:
        print("操作未完成:", error, file=sys.stderr)
        sys.exit(1)
