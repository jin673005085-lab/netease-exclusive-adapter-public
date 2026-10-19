# 实现原理与逆向材料

此目录保留与网易云独占适配相关的静态分析结果。`decompiled/` 是 Ghidra 生成的 16 个关键函数伪代码，不是原始 C++，也不是能直接编译的工程。局部类型、函数名和间接调用关系可能不完整。第三方代码及其派生材料沿用相应组件许可，见 [组件说明](../PROVENANCE.md)。

## 文件索引

| 文件 | 内容 |
| --- | --- |
| `decompiled/NCExclusiveInitialize.c` | Hook 初始化入口 |
| `decompiled/launcher-main-0x140006710.c` | 启动器主函数 |
| `decompiled/0x18000e8e0.c` | 客户端 profile 选择与音频函数 Hook |
| `decompiled/0x18000c710.c` | 音频打开前后的独占标志及上下文处理 |
| `decompiled/0x18000a290.c` | 设备 Activate 拦截与输出后端选择 |
| `decompiled/0x18000b050.c` | 原始音频客户端 Initialize 路径 |
| `decompiled/0x180017140.c` | WASAPI 客户端初始化 |
| `decompiled/0x180018140.c` | PCM 输出格式协商 |
| `decompiled/` 中其余文件 | 关联初始化、校验及页面处理逻辑 |
| `NetEase-compiled-profiles.json` | 原 DLL 内编译的版本及函数地址表 |
| `NetEase-imports.json` | 原生组件导入信息 |
| `inventory.json` | 原始插件包文件大小与 SHA-256 |
| `settings-extraction-provenance.json` | 设置页资源编号、偏移和文件指纹 |

## 实现链路

管理脚本检查客户端 → 启动器再次校验并挂起启动网易云 → 加载 Hook → 按客户端指纹定位音频打开函数 → 为目标音乐流选择独占输出。

设置页的 JavaScript 通过 CEF 原生桥接读写插件状态；它本身不处理音频。独占开关影响音频对象的模式字段和后端选择，WASAPI 路径再通过 `IAudioClient` 协商并初始化设备。

独占输出绕过 Windows 共享混音路径，但不能仅凭此证明播放器内部没有重采样、音效或音量处理。

## 205529 的适配依据

以下位置针对 [构建脚本](../scripts/build_adapter.py) 中固定的客户端 SHA-256，均为 `cloudmusic.dll` 的模块相对地址：

| 项目 | 值 |
| --- | --- |
| 音频打开函数 RVA | `0x108F950` |
| WAVE 到内部 AudioFormat 转换函数 RVA | `0x10940A0` |
| 音频对象的输出格式偏移 | `0xE8` |
| WAVE 格式偏移 | `0x130` |
| 共享/独占标志偏移 | `0x158` |
| 观察到的 Initialize 调用返回点 RVA | `0x109062B`（静态调用位置） |

205529 的上述函数与字段位置和插件中 205564 的需求匹配，CEF 指纹也相同。适配脚本在 Hook 和启动器中替换固定长度的版本、EXE 指纹及主 DLL 指纹，检查 `.text` 和文件布局不变，并同步更新包清单。

这些位置不是跨版本通用接口。`bundle.json` 记录编译 profile，单独修改 JSON 不会生成新版本支持。

## 范围

静态分析来自用户提供的安装包。伪代码文件保留了已有工具标记和部分证据编号；元数据中的绝对本机路径已替换为占位符。个人播放日志、设备标识及无关桌面程序未纳入此目录。

原始 Hook：`4a9e32cfffaed5b0ec60f3e5844113218245571f66837aae19adb23a149122db`。其他组件指纹可在 `inventory.json` 中查找；它们也保存在仓库的原始构建输入中。
