param([ValidateSet('Debug','Release','Publish')][string]$Configuration = 'Debug', [switch]$OfflineTests, [switch]$UiSmoke)
$ErrorActionPreference = 'Stop'
& "$PSScriptRoot/tools/Build-App.ps1" -Configuration $Configuration -OfflineTests:$OfflineTests -UiSmoke:$UiSmoke
