param(
    [switch]$Runtime,
    [ValidateSet('Debug','Release','Publish')][string]$Configuration = 'Debug',
    [switch]$AllConfigurations,
    [switch]$Native
)
$ErrorActionPreference = 'Stop'
$source = $PSScriptRoot
& python "$source/tools/verify.py"
if ($LASTEXITCODE -ne 0) { throw 'Static verification failed' }
& python "$source/tools/offline.py" --base 0x10000000
if ($LASTEXITCODE -ne 0) { throw 'Offline relocation failed' }
if ($Runtime -or $AllConfigurations) {
    $configurations = @(if ($AllConfigurations) { 'Release'; 'Debug'; 'Publish' } else { $Configuration })
    foreach ($selectedConfiguration in $configurations) {
        & "$PSScriptRoot/Build.ps1" -Configuration $selectedConfiguration -OfflineTests -UiSmoke
    }
    & python "$source/tools/verify_app.py" --configuration @configurations
    if ($LASTEXITCODE -ne 0) { throw '2026 structural verification failed' }
}
if ($Native) { & "$source/tools/Check-Native.ps1" }
