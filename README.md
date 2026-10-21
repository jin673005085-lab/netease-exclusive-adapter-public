# 网易云音乐 WASAPI 独占输出适配工具

适用于 **网易云音乐 Windows x64 3.1.41.205529**。仓库已包含运行组件和相关脚本，克隆或下载解压后，双击 `AudioExclusive.cmd` 即可使用。

**日常使用只需要 Windows 自带的 PowerShell，无需安装 Python，也无需另找 AudioExclusive 安装包。**

**v0.3.1 已加入播放过渡补丁**，处理暂停、继续和切歌时的爆音。在 Macaron USB DAC 上完成试听，反馈没有爆音；其他设备尚未逐一验证。已有用户下载新版后，重新选择 **1 安装** 即可更新。

## 快速使用

1. 克隆仓库，或从 [Releases](https://github.com/jin673005085-lab/netease-exclusive-adapter-public/releases/latest) 下载完整包并解压。
2. 打开需要适配的网易云，双击 `AudioExclusive.cmd`，选择 **1 安装**。
3. 从开始菜单 **AudioExclusive → 网易云音乐（独占插件）** 启动，在播放设置中选择 DAC 并开启独占。

脚本自动识别网易云目录，无需联网下载组件。运行文件和客户端必须通过 SHA-256 校验；同版本号但文件不同也会停止安装。安装可能关闭并重新打开网易云，请先保存播放进度。

**独占播放前请先调低 DAC 硬件音量，Windows 系统音量可能不再生效。**

以后双击同一入口，可选择 **2 启动、3 状态、4 移除、5 检查兼容性**。检查兼容性不会安装或启动插件。

命令行也可指定网易云目录，以下命令按需选择：

```powershell
.\AudioExclusive.cmd -Action Install -Client 'D:\CloudMusic'
.\AudioExclusive.cmd -Action Check -Client 'D:\CloudMusic'
```

独占开关请通过网易云的播放设置控制。启动网易云时使用插件入口。

## 项目内容

| 路径 | 内容 |
| --- | --- |
| `AudioExclusive.cmd` | Windows 双击入口 |
| `scripts/Use-Adapter.ps1` | 无需 Python 的兼容性检查和安装入口 |
| `scripts/Manage-AudioExclusive.ps1` | AudioExclusive 管理脚本，保留原始字节 |
| `scripts/use_adapter.py` | 可选的自动构建与管理入口 |
| `scripts/build_adapter.py` | 兼容包构建、校验和打包 |
| `runtime/205529.zip` | 可直接安装的 205529 适配组件 |
| `runtime/payload.zip` | 构建脚本使用的固定版本输入 |
| `runtime/declick-helper.dll` | 原生过渡补丁的预编译构建组件 |
| `ui/netease-settings.js` | 设置页脚本参考 |
| `reverse-engineering/` | 核心函数伪代码和相关分析 |
| `native/` | 播放过渡补丁源码及构建、验证说明 |
| `tests/` | 文件完整性、构建保护与入口检查 |
| `licenses/upstream/` | 上游许可及组件通知 |

脚本源码可以直接查看和修改。核心 Hook 和启动器以二进制组件提供，目前没有它们的可编译 C++ 工程。反编译伪代码供分析参考；仅修改设置页 JS 也不会替换 DLL 内的嵌入页面。具体来源及许可范围见 [组件说明](PROVENANCE.md)。

## 重新构建（可选）

仅重新构建或运行测试需要 Python 3.9+ 和 `pefile`。构建输入已包含在仓库中，无需外部安装包：

```powershell
python -m pip install -r requirements.txt
python scripts/use_adapter.py --action Build --client 'D:\CloudMusic' --out dist/205529
```

将客户端路径替换为实际目录。输出目录必须不存在。构建器会校验依赖文件、客户端及生成的兼容包；校验失败时停止构建。

输出包含 `payload.zip`、`Manage-AudioExclusive.ps1` 和检查报告 `candidate-checks.json`。修改构建规则后，预构建的 `runtime/205529.zip` 不会自动变化；实际分发新产物前应重新验证并更新入口中的文件校验值。

## 兼容性说明

已在 **3.1.41.205529 x64 + Macaron USB DAC** 上验证独占播放，观察到的输出格式为 **192 kHz / 32 位 / 双声道**。

WASAPI 独占可绕过 Windows 共享混音路径；实际输出仍受播放器处理和设备能力影响，以上结果不代表歌曲原始采样率或全链路 bit-perfect。多采样率切换、设备拔插和长期稳定性尚未完整验证。

升级网易云后请重新确认兼容性，勿修改校验值来强行加载。

过渡补丁只在开始、停止处加入约 5 ms 渐入渐出，连续播放的样本保持不变；过渡段会改变 PCM，不属于全程位完美输出。停止时会额外等待缓冲播放，可能有轻微延迟，详见 [补丁说明](native/README.md)。

## 测试

```powershell
python -m unittest discover -s tests -v
```

提供本地客户端后，可执行无外部安装包的完整构建检查和 PowerShell 兼容性检查：

```powershell
$env:NCE_TEST_CLIENT = 'D:\CloudMusic'
python -m unittest discover -s tests -v
```

## 许可

本项目编写的适配脚本、测试和文档使用 [MIT](LICENSE)；`native/declick.c` 使用 GPL-3.0-only。AudioExclusive 管理脚本、设置页、原生组件及其派生材料保留各自许可，不纳入本项目的 MIT 授权，详见 [组件许可说明](PROVENANCE.md)。
