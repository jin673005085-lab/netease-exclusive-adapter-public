# 网易云音乐 WASAPI 独占输出适配工具

为 **网易云音乐 Windows x64 3.1.41.205529** 提供 AudioExclusive 兼容包构建工具，配合现有插件使用 WASAPI 独占输出。

双击 `AudioExclusive.cmd`，按提示选择操作。脚本会自动读取本地安装包、检查客户端、生成兼容包并完成安装，也支持启动、查询状态和移除插件。

需要 Python 3.9+ 和自行准备的 **AudioExclusive 2026.10.15.4 安装包**。无需手动拆包；工具只读取安装包，不运行其中的安装器。

## 快速使用

1. 从 [Releases](https://github.com/jin673005085-lab/netease-exclusive-adapter-public/releases/latest) 下载脚本包，解压到一个普通文件夹。
2. 安装 [Python 3.9 或更新版本](https://www.python.org/downloads/windows/)，勾选 **Add Python to PATH**。
3. 打开需要适配的网易云，双击 `AudioExclusive.cmd`，选择 **1 安装**。
4. 按提示填入 AudioExclusive 安装包路径和网易云安装目录，例如 `D:\CloudMusic`。文件路径可以拖入窗口。
5. 完成后，从开始菜单 **AudioExclusive → 网易云音乐（独占插件）** 启动，在播放设置中选择 DAC 并开启独占。

首次运行会通过 pip 安装所需的 `pefile` 库，需要联网。安装包和客户端必须通过文件校验；同版本号但文件不同也会停止安装。安装可能关闭并重新打开网易云，请先保存播放进度。

**独占播放前请先调低 DAC 硬件音量，Windows 系统音量可能不再生效。**

以后双击同一入口，可选择 **2 启动、3 状态、4 移除**。仅安装需要提供安装包，其他操作使用本机已安装的管理脚本。

命令行也可以直接使用（先执行 `python -m pip install -r requirements.txt`）：

```powershell
python scripts/use_adapter.py --action Install --setup 'C:\Downloads\AudioExclusive-Setup.exe' --client 'D:\CloudMusic'
```

只想生成兼容包、不安装时，将 `Install` 改为 `Build`。默认输出到 `dist/` 下的新目录；可用 `--out` 指定尚不存在的输出目录。

## 项目内容

| 路径 | 内容 |
| --- | --- |
| `AudioExclusive.cmd` | Windows 双击入口 |
| `scripts/use_adapter.py` | 安装包读取、自动构建与插件管理 |
| `scripts/build_adapter.py` | 兼容包构建、校验和打包 |
| `tests/test_build_adapter.py` | 输出保护、版本和输入完整性测试 |
| `requirements.txt` | Python 依赖 |
| `PROVENANCE.md` | 构建依赖、文件校验与组件许可 |

## 手动构建（可选）

使用上面的快捷入口时，无需准备以下目录。已有插件文件的开发者可以直接构建。

需要 Python 3.9+、Windows PowerShell，以及：

1. 对应版本的网易云安装目录，其中包含 `cloudmusic.exe`、`cloudmusic.dll` 和 `libcef.dll`。
2. AudioExclusive **2026.10.15.4** 的 `payload` 目录（含 `bundle.json` 和其清单文件）。
3. 同一版本的 `Manage-AudioExclusive.ps1` 管理脚本。

将依赖文件放在 `inputs/` 下，该目录已被 Git 忽略。文件校验值见 [构建依赖说明](PROVENANCE.md)。

```text
inputs/
  Manage-AudioExclusive.ps1
  payload/
    bundle.json
    NetEase/...
    ...清单中的其他文件
```

### 构建命令

```powershell
python -m pip install -r requirements.txt
python scripts/build_adapter.py --payload-dir inputs/payload --manager inputs/Manage-AudioExclusive.ps1 --client 'D:\CloudMusic' --out dist/205529
```

将示例客户端路径替换为实际目录。输出目录必须不存在。构建器会校验依赖文件、客户端及生成的兼容包；校验失败时停止构建。

输出包含 `payload.zip`、`Manage-AudioExclusive.ps1` 和构建检查报告 `candidate-checks.json`。当前适配范围为 **3.1.41.205529 x64**，其他版本需要单独适配。

构建成功后仍需在实际设备上确认播放和独占输出状态。

## 安装和使用

安装和插件启动可能退出并重新打开网易云，请先结束当前播放。构建完成后按需执行：

```powershell
$bundle = (Resolve-Path 'dist/205529/payload.zip').Path
$hash = (Get-FileHash -LiteralPath $bundle -Algorithm SHA256).Hash
& ./dist/205529/Manage-AudioExclusive.ps1 -Action Install -App NetEase -BundlePath $bundle -BundleHash $hash -NoMenu
```

从开始菜单 **AudioExclusive → 网易云音乐（独占插件）** 启动，在网易云播放设置中选择实际 DAC，并打开独占开关。请使用该插件入口启动网易云。

查询状态：

```powershell
& ./dist/205529/Manage-AudioExclusive.ps1 -Action Status -App NetEase -NoMenu
```

取消插件：

```powershell
& ./dist/205529/Manage-AudioExclusive.ps1 -Action Remove -App NetEase -NoMenu
```

独占模式请通过网易云设置页内的开关控制。

## 兼容性说明

已在 **3.1.41.205529 x64 + Macaron USB DAC** 上验证独占播放，观察到的输出格式为 **192 kHz / 32 位 / 双声道**。

WASAPI 独占可绕过 Windows 共享混音路径；实际输出仍受播放器处理和设备能力影响，以上结果不代表歌曲原始采样率或全链路 bit-perfect。多采样率切换、设备拔插和长期稳定性尚未完整验证。

## 测试

```powershell
python -m unittest discover -s tests -v
```

默认执行不依赖客户端的保护测试。提供本地依赖后，可执行完整集成检查：

```powershell
$env:NCE_TEST_CLIENT = 'D:\CloudMusic'
$env:NCE_TEST_PAYLOAD_DIR = (Resolve-Path inputs/payload).Path
$env:NCE_TEST_SETUP = 'C:\Downloads\AudioExclusive-Setup.exe'
python -m unittest discover -s tests -v
```

升级网易云后请重新确认兼容性，勿修改校验值来强行加载。

## 许可

仓库内适配代码、测试和文档使用 [MIT](LICENSE)。AudioExclusive、管理脚本及其依赖保留各自许可，详见 [组件许可说明](PROVENANCE.md)。
