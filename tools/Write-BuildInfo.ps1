param([Parameter(Mandatory = $true)][string]$Output)
$ErrorActionPreference = 'Stop'
$projectRoot = Split-Path -Parent $PSScriptRoot
$timestamp = & git -C $projectRoot log -1 --format=%cI
if ($LASTEXITCODE -ne 0 -or -not $timestamp) { throw 'Cannot read the current Git commit time' }
$commitTime = [DateTimeOffset]::Parse($timestamp.Trim(), [Globalization.CultureInfo]::InvariantCulture)
$displayDate = $commitTime.ToOffset([TimeSpan]::FromHours(8)).ToString('yyyy-MM-dd', [Globalization.CultureInfo]::InvariantCulture)
$content = "#pragma once`nnamespace app::build_info`n{`ninline constexpr wchar_t CommitDate[] = L`"$displayDate`";`n}`n"
$outputPath = [IO.Path]::GetFullPath($Output)
[IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($outputPath)) | Out-Null
if (-not [IO.File]::Exists($outputPath) -or [IO.File]::ReadAllText($outputPath) -cne $content) {
    [IO.File]::WriteAllText($outputPath, $content, [Text.UTF8Encoding]::new($false))
}
