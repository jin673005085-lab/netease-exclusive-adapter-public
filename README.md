# 网易云 WASAPI 独占输出适配脚本

针对 **网易云音乐 Windows x64 3.1.41.205529**，使用本地提供的 AudioExclusive 2026.10.15.4 原始载荷生成兼容包。

适配器核对客户端三个文件的 SHA-256 和关键代码锚点，再替换原 Hook / 启动器内的固定长度版本与指纹数据。`.text` 机器代码和文件长度保持不变；不会取消客户端校验，也不会修改网易云安装目录。

**这是依赖现有插件的适配脚本，不是完整的原生 Hook 工程，也不是开箱即用的独占播放器或 DAC 驱动。**

## 公开内容

| 路径 | 内容 |
| --- | --- |
| `scripts/build_adapter.py` | 精确构建适配器，校验、修改和打包 |
| `tests/test_build_adapter.py` | 输出保护、版本和输入完整性测试 |
| `requirements.txt` | Python 依赖 |
| `PROVENANCE.md` | 外部输入指纹与来源说明 |

仅公开本项目生成的适配代码和说明。原安装包、原管理脚本、设置页 JS、DLL/EXE、反编译记录、个人路径、播放日志、歌曲及桌面伴侣均不随仓库分发。

## 准备本地输入

需要 Python 3.9+、Windows PowerShell，以及：

1. 对应版本的网易云安装目录，其中包含 `cloudmusic.exe`、`cloudmusic.dll` 和 `libcef.dll`。
2. 自行取得的 AudioExclusive **2026.10.15.4** 原始 `payload` 目录（含 `bundle.json` 和其清单文件）。
3. 同一原包中的 `Manage-AudioExclusive.ps1` 管理脚本。

将外部输入保存在被 Git 忽略的 `inputs/` 下。仓库不提供原包下载，不自动下载或执行安装器。输入的预期指纹见 [PROVENANCE.md](PROVENANCE.md)。

```text
inputs/
  Manage-AudioExclusive.ps1
  payload/
    bundle.json
    NetEase/...
    ...原清单中的其他文件
```

## 构建

```powershell
python -m pip install -r requirements.txt
python scripts/build_adapter.py --payload-dir inputs/payload --manager inputs/Manage-AudioExclusive.ps1 --client 'D:\CloudMusic' --out dist/205529
```

将示例客户端路径替换为实际目录。输出目录必须不存在。构建器校验原始清单、所有载荷文件、管理脚本、客户端指纹、x64 架构和代码锚点，并检查改动范围、ZIP CRC 与新清单哈希。任何校验失败都不会安装或运行插件。

生成 `payload.zip`、原样复制的管理脚本和 `candidate-checks.json`。保留原包格式及其他载荷，但只适配网易云的 205564 profile 槽位到 205529；保留的 205322 profile 不属于本项目新增适配或新增验证范围。没有通用版本扫描，也不保证对其他版本有效。

构建脚本只验证构建结果，**不会播放音频**。输出标记保留为待本机验证，不能将脚本成功退出当作音频验收通过。

## 安装和使用

安装和插件启动可能退出并重新打开网易云，请先结束当前播放。构建完成后按需执行：

```powershell
$bundle = (Resolve-Path 'dist/205529/payload.zip').Path
$hash = (Get-FileHash -LiteralPath $bundle -Algorithm SHA256).Hash
& ./dist/205529/Manage-AudioExclusive.ps1 -Action Install -App NetEase -BundlePath $bundle -BundleHash $hash -NoMenu
```

从开始菜单 **AudioExclusive → 网易云音乐（独占插件）** 启动，在网易云播放设置中选择实际 DAC，并打开新增的独占开关。原网易云入口不会自动注入。

查询状态：

```powershell
& ./dist/205529/Manage-AudioExclusive.ps1 -Action Status -App NetEase -NoMenu
```

取消插件：

```powershell
& ./dist/205529/Manage-AudioExclusive.ps1 -Action Remove -App NetEase -NoMenu
```

使用网易云设置页内的开关。外部改写 `settings.ini` 不是经过验证的实时控制方式，不保证暂停恢复就会重读配置。

## 验证范围

2026-10-19，在精确匹配的 205529 构建与 Macaron USB DAC 上，原适配结果的运行日志记录了独占取得、192 kHz / 32 位 / 双声道、非静音数据提交、释放和再次取得设备；所观察快照的欠载计数为 0。公开构建器生成的 Hook / 启动器已与该适配结果逐字节比对。

WASAPI 独占能绕过 Windows 共享混音路径，但这不是全链路 bit-perfect 证明，也不能说明歌曲原本就是 192 kHz。网易云内部音效、音量、重采样以及 DAC 内部处理仍可能改变信号。没有完成 44.1/48 kHz 切换、拔插和长期稳定性验证。

本项目不提供软件旋钮或硬件音量驱动；独占时 Windows 端点音量可能不影响播放。不能把其他应用有没有声音作为唯一验收依据，应核对具体输出端点及实际独占状态。

## 测试

```powershell
python -m unittest discover -s tests -v
```

默认执行两项不依赖客户端的保护测试。提供本地原始输入后再运行，可以执行另外三项集成保护测试：

```powershell
$env:NCE_TEST_CLIENT = 'D:\CloudMusic'
$env:NCE_TEST_PAYLOAD_DIR = (Resolve-Path inputs/payload).Path
python -m unittest discover -s tests -v
```

新增版本需要重新确认函数语义、对象布局和 CEF ABI，并完成实际播放验证；请勿只改哈希强行加载。

## 许可

仓库内适配代码、测试和文档使用 [MIT](LICENSE)。外部提供的 AudioExclusive、原管理脚本、原生组件及其依赖保留各自许可；本仓库许可不覆盖它们，也不替代上游原生工程的对应源码。
