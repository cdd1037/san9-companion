# Shared build prerequisites; dot-source this file from build/check entry points.
function Get-VisualStudioPath {
    $locator = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio/Installer/vswhere.exe'
    if (-not (Test-Path -LiteralPath $locator)) { throw 'Visual Studio Installer / vswhere not found' }
    $installation = & $locator -latest -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
    if ($LASTEXITCODE -ne 0 -or -not $installation) { throw 'Visual Studio C++ toolchain not found' }
    return $installation
}

function Enter-ProjectDevShell {
    param([string]$Installation)
    Import-Module (Join-Path $Installation 'Common7/Tools/Microsoft.VisualStudio.DevShell.dll')
    Enter-VsDevShell -VsInstallPath $Installation -SkipAutomaticLocation -DevCmdArguments '-arch=x86 -host_arch=x64'
}

function Invoke-Checked {
    param([string]$Program, [string[]]$Arguments)
    & $Program @Arguments
    if ($LASTEXITCODE -ne 0) { throw "$Program failed: $LASTEXITCODE" }
}
