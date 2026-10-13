@echo off
setlocal
powershell.exe -NoLogo -NoProfile -ExecutionPolicy Bypass -File "%~dp0Start-IdaMcp.ps1" %*
if errorlevel 1 (
    echo.
    echo IDA MCP failed. Review the error above.
    pause
    exit /b 1
)
