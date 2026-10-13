[CmdletBinding()]
param(
    [Parameter(Position = 0)]
    [string]$Database,
    [ValidateRange(1024, 65535)]
    [int]$Port = 8737,
    [switch]$Background
)

$ErrorActionPreference = 'Stop'
$idaProjectRoot = Split-Path -Parent $PSScriptRoot

try {
    if (-not $Database) {
        $Database = Join-Path $idaProjectRoot 'recovery\sample-2026\San9PKHard.exe'
    }

    $uvx = (Get-Command uvx.exe -ErrorAction Stop).Source
    $idaPython = [Environment]::GetEnvironmentVariable('IDAPYTHON_VENV_EXECUTABLE', 'User')
    if ($idaPython) {
        if (-not (Test-Path -LiteralPath $idaPython -PathType Leaf)) {
            throw "IDA Python environment does not exist: $idaPython"
        }
        $env:IDAPYTHON_VENV_EXECUTABLE = $idaPython
    }

    $serverArgs = @(
        '--exclude-newer=1s', 'ida-mcp', 'http',
        '--host', '127.0.0.1', '--port', [string]$Port,
        '--agent', 'codex', '--idle-timeout', '0'
    )
    $Database = (Resolve-Path -LiteralPath $Database -ErrorAction Stop).ProviderPath
    if (-not (Test-Path -LiteralPath $Database -PathType Leaf)) {
        throw "Database must be an EXE, binary, or IDB file: $Database"
    }
    $serverArgs += @('--database', $Database)

    $probe = [System.Net.Sockets.TcpClient]::new()
    try {
        $connected = $probe.ConnectAsync('127.0.0.1', $Port)
        try { $occupied = $connected.Wait(500) -and $probe.Connected } catch { $occupied = $false }
    } finally { $probe.Dispose() }
    if ($occupied) { throw "Port $Port is already in use. Stop that service or select another -Port." }

    Write-Host "MCP endpoint: http://127.0.0.1:$Port/mcp"
    if ($Database) {
        Write-Host "Headless IDA target: $Database"
        Write-Host 'A valid IDA/idalib license is required. Analysis may take time.'
    }

    if (-not $Background) {
        Write-Host 'Keep this terminal open. Press Ctrl+C to stop.'
        & $uvx @serverArgs
        exit $LASTEXITCODE
    }

    $logDir = Join-Path $idaProjectRoot '.codex\ida-mcp-runtime'
    New-Item -ItemType Directory -Path $logDir -Force | Out-Null
    $stamp = Get-Date -Format 'yyyyMMdd-HHmmss-fff'
    $stdout = Join-Path $logDir "$stamp.stdout.log"
    $stderr = Join-Path $logDir "$stamp.stderr.log"
    # All arguments are fixed switches, integers, or a resolved file path.
    $quotedArgs = $serverArgs | ForEach-Object { '"' + $_ + '"' }
    $process = Start-Process -FilePath $uvx -ArgumentList $quotedArgs -WindowStyle Hidden `
        -WorkingDirectory $PSScriptRoot -RedirectStandardOutput $stdout `
        -RedirectStandardError $stderr -PassThru
    Start-Sleep -Seconds 2
    $process.Refresh()
    if ($process.HasExited) {
        $details = Get-Content -LiteralPath $stderr -Raw -ErrorAction SilentlyContinue
        throw "MCP exited during startup (exit $($process.ExitCode)).`n$details"
    }
    $process.Id | Set-Content -LiteralPath (Join-Path $logDir "$stamp.pid") -Encoding Ascii
    Write-Host "Background process launched: PID $($process.Id). Database readiness is not yet confirmed."
    Write-Host "Output: $stdout"
    Write-Host "Errors: $stderr"
    Write-Host "Stop this process tree: taskkill /PID $($process.Id) /T /F"
} catch {
    Write-Error $_ -ErrorAction Continue
    exit 1
}
