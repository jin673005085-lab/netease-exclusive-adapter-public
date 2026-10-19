# 组件来源、文件校验与许可

运行组件与管理脚本来自用户提供的 AudioExclusive **2026.10.15.4**。仓库已包含运行和重新构建所需的文件，日常使用不需要外部安装包。下列校验值用于固定依赖版本。

| 输入 | SHA-256 |
| --- | --- |
| 原安装包（来源参考，不随仓库分发） | `deebb7ce9f7aa014330975ef4383e18b2f1275d51e409b98f14d98c9f3a787ac` |
| `runtime/payload.zip`（原始构建输入） | `8695c9d18f117533d62520484db742eb5d705b028e92a8ea9d8ae0ba410cf42d` |
| `runtime/205529.zip`（可安装适配包） | `c7e6f9653bb8de707fdac11ab0bd49ed726ca182a3ed45996c298d52e7c014e9` |
| 原始 `bundle.json`（位于构建输入中） | `4798ae7c73287579b091cb8dc226c123cf8c001f3b768099012ddaa8c1915159` |
| `scripts/Manage-AudioExclusive.ps1` | `d4979af1b443eef9e216de50f229c2ed3075265032d2b043152db1f676450999` |
| `ui/netease-settings.js` | `ac0966c0eb521ddd0920949a601c17af54193675eddddeb904b32f6c08a7c465` |

构建器还会按清单校验各插件文件，请保留依赖文件原样。

预构建适配包中的 Hook 与启动器只替换固定长度的版本和指纹数据，机器代码保持不变。两个压缩包沿用上游文件清单，包含其他应用的组件；本项目入口只管理网易云，不安装 Apple Music 插件。

`ui/netease-settings.js` 是随 Hook 提供的页面脚本副本，供阅读和修改参考。仅修改该文件不会替换 DLL 内的嵌入页面。

目标网易云 x64 **3.1.41.205529** 的文件指纹：

| 文件 | SHA-256 |
| --- | --- |
| `cloudmusic.exe` | `16689d9731121f0f15116205d73a472748de932b6a848e36b55b60501cbf0ede` |
| `cloudmusic.dll` | `7f667f876caf94bc3dac3b0070d3e495117005fafdcf18b6aaa51eb004edac8c` |
| `libcef.dll` | `a2a441490a9600f7e06b8c4dc609354ff7214add445a55c8fa699760d264e210` |

校验值用于识别兼容的客户端构建。即使显示版本号相同，文件校验值不同也需要重新确认兼容性。

## 外部组件许可

AudioExclusive 随附的许可声明中，NCExclusive（含 ASIO 后端）采用 GPL-3.0-only，并列有 MinHook、CEF、Chromium、AMExclusive 等依赖。上游许可和通知原文保存在 [licenses/upstream](licenses/upstream/)。设置页脚本及从原生组件派生的伪代码沿用相应组件的许可；本项目的 MIT 许可不覆盖它们。

上游通知提到相邻的 `backend-source` 和源码压缩包，但用户提供的安装包中没有这些文件，目前未取得核心 Hook 与启动器的可编译 C++ 工程。本仓库包含现有脚本源码、分析材料及运行组件，不声称提供完整的原生对应源码，也不能替代 GPL 对应源码的提供要求。管理脚本未发现单独明确的许可声明，保留原始内容及来源，不将其重新授权为 MIT。

MIT 许可仅覆盖本项目编写的适配代码、测试和说明，不改变第三方组件及其依赖的许可。
