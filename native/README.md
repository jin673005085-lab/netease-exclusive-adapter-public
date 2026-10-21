# 播放过渡补丁

用于减轻暂停、继续和切歌时的爆音。2026-10-21 在网易云 3.1.41.205529 x64 与 Macaron USB DAC 上安装后，完成暂停、继续和切歌试听，反馈没有爆音。v0.3.1 的默认安装包已包含补丁；日常安装不需要编译器。

`declick.c` 在原生输出提交 PCM 前，对开始的约 5 ms 做渐入；停止前追加一段从最后提交样本渐出到零的缓冲，再调用原来的 Stop。连续播放的样本不变，过渡段会改变 PCM，因此过渡段不属于位完美输出。

仅接受仓库固定的原版或 205529 适配 DLL；补丁修改两个调用位置，新增分开的 RX 代码节和 RW 状态节，保留地址随机化并合并 Windows 异常展开表。原插件的音源队列和系统音量不变。新增代码使用 GPL-3.0-only，与原插件许可证一致。

重新编译原生补丁需要本地 MinGW-w64 GCC、Python 和 pefile。在仓库根目录运行（输入必须是尚未加入过渡补丁的固定版本 Hook）：

```powershell
python scripts/build_declick.py --hook path/to/nc-exclusive-hook.dll --out artifacts/declick/nc-exclusive-hook.dll --gcc path/to/gcc.exe
gcc -O2 -Wall -Wextra tests/declick_test.c -o artifacts/declick/declick-test.exe
./artifacts/declick/declick-test.exe
python -m unittest discover -s tests -p test_declick.py -v
```

构建脚本不会安装或覆盖现有 DLL。测试覆盖 16/24/32 位 PCM、44.1/48/192 kHz、静音、设备失败、PE 布局、异常表和随机地址下的 Stop 调用。它们不能替代真实 DAC 试听。

`runtime/declick-helper.dll` 是该源码的预编译辅助组件，不单独加载；Python 构建器校验其哈希后将代码合入 Hook。正式包内的 Hook 与本机完成试听的补丁字节一致。修改原生源码后，需要重新编译、更新辅助组件及构建器中的校验值，再重新生成 `runtime/205529.zip` 并更新 PowerShell 入口的包校验值。

停止最多额外等待一个事件（上限 100 ms）和两个缓冲周期加 2 ms。设备释放时的模拟电路爆音可能仍然存在；先降低硬件音量再试听。试用失败时恢复原包，不要继续增大音量。
