@echo off
setlocal
chcp 65001 >nul
cd /d "%~dp0"
"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoLogo -NoProfile -ExecutionPolicy Bypass -File "%~dp0scripts\Use-Adapter.ps1" %*
if errorlevel 1 goto failed
pause
exit /b 0
:failed
echo 操作未完成，请查看上方提示。
pause
exit /b 1
