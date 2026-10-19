# 构建依赖与文件校验

快捷入口需要自行提供 AudioExclusive **2026.10.15.4 安装包**，会自动读取其中的插件文件和管理脚本。下列校验值用于确认依赖版本；安装包、内嵌脚本和插件压缩包全部通过检查后才会解包。

| 输入 | SHA-256 |
| --- | --- |
| 安装包（版本参考） | `deebb7ce9f7aa014330975ef4383e18b2f1275d51e409b98f14d98c9f3a787ac` |
| `payload.zip`（版本参考） | `8695c9d18f117533d62520484db742eb5d705b028e92a8ea9d8ae0ba410cf42d` |
| `bundle.json`（构建器校验） | `4798ae7c73287579b091cb8dc226c123cf8c001f3b768099012ddaa8c1915159` |
| `Manage-AudioExclusive.ps1`（构建器校验） | `d4979af1b443eef9e216de50f229c2ed3075265032d2b043152db1f676450999` |

构建器还会按清单校验各插件文件，请保留依赖文件原样。

目标网易云 x64 **3.1.41.205529** 的文件指纹：

| 文件 | SHA-256 |
| --- | --- |
| `cloudmusic.exe` | `16689d9731121f0f15116205d73a472748de932b6a848e36b55b60501cbf0ede` |
| `cloudmusic.dll` | `7f667f876caf94bc3dac3b0070d3e495117005fafdcf18b6aaa51eb004edac8c` |
| `libcef.dll` | `a2a441490a9600f7e06b8c4dc609354ff7214add445a55c8fa699760d264e210` |

校验值用于识别兼容的客户端构建。即使显示版本号相同，文件校验值不同也需要重新确认兼容性。

## 外部组件许可

AudioExclusive 随附的许可声明中，NCExclusive（含 ASIO 后端）采用 GPL-3.0-only，并列有 MinHook、CEF、Chromium、AMExclusive 等依赖。使用或分发相关组件时，请遵守各自的许可及对应源码提供要求。

管理脚本由用户本地提供，仓库不随附分发。MIT 许可仅覆盖本仓库的适配代码、测试和说明，不改变外部组件或本地生成二进制的许可。
