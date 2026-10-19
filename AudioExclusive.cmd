@echo off
setlocal
set "PYTHONUTF8=1"
chcp 65001 >nul
cd /d "%~dp0"
python -c "import sys; assert sys.version_info >= (3,9)" >nul 2>&1
if errorlevel 1 goto python_missing
python -c "import pefile; assert pefile.__version__ == '2024.8.26'" >nul 2>&1
if errorlevel 1 python -m pip install -r "%~dp0requirements.txt"
if errorlevel 1 goto failed
python "%~dp0scripts\use_adapter.py" %*
if errorlevel 1 goto failed
pause
exit /b 0
:python_missing
echo 请先安装 Python 3.9 或更新版本，并勾选 Add Python to PATH。
echo https://www.python.org/downloads/windows/
goto failed
:failed
echo 操作未完成，请查看上方提示。
pause
exit /b 1
