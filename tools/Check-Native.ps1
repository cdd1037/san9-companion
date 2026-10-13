$ErrorActionPreference = 'Stop'
$projectRoot = Split-Path -Parent $PSScriptRoot
. (Join-Path $PSScriptRoot 'VisualStudio.ps1')
$vsPath = Get-VisualStudioPath
Enter-ProjectDevShell -Installation $vsPath
Push-Location $projectRoot
try {
    New-Item -ItemType Directory -Path 'out/native' -Force | Out-Null
    Invoke-Checked 'cmake.exe' @('-S','.', '-B','build/cmake-x86','-G','Ninja','-DCMAKE_BUILD_TYPE=Debug')
    Invoke-Checked 'cmake.exe' @('--build','build/cmake-x86')
    Invoke-Checked 'ctest.exe' @('--test-dir','build/cmake-x86','--output-on-failure')
    Invoke-Checked './build/cmake-x86/san9-static.exe' @('0x10000000','out/native/native_data.bin')
    Invoke-Checked 'python.exe' @('tools/offline.py','--base','0x10000000','--out','out/native/python')
    Invoke-Checked 'python.exe' @('-c', 'from pathlib import Path; import sys; sys.exit(0 if Path("out/native/native_data.bin").read_bytes() == Path("out/native/python/relocated_data.bin").read_bytes() else "Native/Python output differs")')
    $report = [ordered]@{
        architecture = $env:VSCMD_ARG_TGT_ARCH
        cmake_build = 'passed'
        ctest = 'passed'
        native_python_bytes_equal = $true
        live_game_injection = 'not_performed'
    }
    $report | ConvertTo-Json | Set-Content -LiteralPath 'out/native/verification.json' -Encoding utf8
    $report | ConvertTo-Json
} finally { Pop-Location }
