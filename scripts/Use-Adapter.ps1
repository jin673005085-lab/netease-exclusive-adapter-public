[CmdletBinding()]
param(
    [ValidateSet('Menu','Install','Launch','Status','Remove','Check')]
    [string]$Action='Menu',
    [string]$Client=''
)
$ErrorActionPreference='Stop'
# Keep Windows PowerShell modules available when launched from another PowerShell host.
$env:PSModulePath=(@((Join-Path $PSHOME 'Modules'),(Join-Path $env:ProgramFiles 'WindowsPowerShell\Modules'))+@($env:PSModulePath -split ';')) -join ';'
$adapterAction=$Action
$adapterRoot=Split-Path -Parent $PSScriptRoot
$adapterManagerPath=Join-Path $PSScriptRoot 'Manage-AudioExclusive.ps1'
$adapterBundlePath=Join-Path $adapterRoot 'runtime\205529.zip'
$adapterManagerHash='d4979af1b443eef9e216de50f229c2ed3075265032d2b043152db1f676450999'
$adapterBundleHash='c7e6f9653bb8de707fdac11ab0bd49ed726ca182a3ed45996c298d52e7c014e9'
try {
    if ((Get-FileHash -LiteralPath $adapterManagerPath -Algorithm SHA256).Hash -ine $adapterManagerHash) {
        throw '管理脚本校验失败，请重新下载完整脚本包。'
    }
    if ((Get-FileHash -LiteralPath $adapterBundlePath -Algorithm SHA256).Hash -ine $adapterBundleHash) {
        throw '运行文件校验失败，请重新下载完整脚本包。'
    }
    if ($adapterAction -eq 'Menu') {
        Write-Host '网易云音乐独占输出 · 3.1.41.205529 x64' -ForegroundColor Cyan
        Write-Host '1 安装   2 启动   3 查看状态   4 移除   5 检查兼容性'
        $adapterChoice=Read-Host '请选择 [1]'
        if (-not $adapterChoice) {$adapterChoice='1'}
        $adapterActions=@{'1'='Install';'2'='Launch';'3'='Status';'4'='Remove';'5'='Check'}
        if (-not $adapterActions.ContainsKey($adapterChoice)) {throw '请选择 1 至 5。'}
        $adapterAction=$adapterActions[$adapterChoice]
    }
    if ($adapterAction -in @('Install','Check')) {
        Add-Type -AssemblyName System.IO.Compression.FileSystem
        $adapterArchive=[IO.Compression.ZipFile]::OpenRead($adapterBundlePath)
        try {
            $adapterEntry=$adapterArchive.GetEntry('bundle.json')
            $adapterReader=New-Object IO.StreamReader($adapterEntry.Open())
            try {$adapterMeta=$adapterReader.ReadToEnd()|ConvertFrom-Json}
            finally {$adapterReader.Dispose()}
        } finally {$adapterArchive.Dispose()}
        . $adapterManagerPath -LibraryOnly
        $script:Meta=$adapterMeta
        $adapterFound=Find-Application 'NetEase'
        if ($Client) {
            $adapterClientDir=[IO.Path]::GetFullPath($Client.Trim('"'))
            if (-not (Test-Profile 'NetEase' (Join-Path $adapterClientDir 'cloudmusic.exe'))) {
                throw '所选网易云文件与 3.1.41.205529 x64 不匹配，未安装插件。'
            }
        } elseif ($adapterFound.status -eq 'Supported') {
            $adapterClientDir=Split-Path -Parent $adapterFound.path
        } else {
            throw '未找到兼容的网易云，请先打开 3.1.41.205529 x64，再重试。'
        }
        $adapterExpectedExecutable=[IO.Path]::Combine($adapterClientDir,'cloudmusic.exe')
        if ($adapterFound.status -ne 'Supported' -or [IO.Path]::GetFullPath($adapterFound.path) -ine $adapterExpectedExecutable) {
            throw '请先打开所选目录里的网易云，让管理脚本识别该安装位置，再重试。'
        }
        # This ready-made package targets only 205529, even if upstream contains older profiles.
        foreach ($adapterFile in $adapterMeta.applications.NetEase.fingerprints.PSObject.Properties) {
            if (-not (Test-Hash (Join-Path $adapterClientDir $adapterFile.Name) $adapterFile.Value)) {
                throw '仅支持 3.1.41.205529 x64；客户端文件校验失败，未安装插件。'
            }
        }
        Write-Host ('兼容性检查通过：'+$adapterClientDir) -ForegroundColor Green
        if ($adapterAction -eq 'Check') {exit 0}
        Write-Host '安装可能关闭并重新打开网易云；独占播放前请先调低 DAC 硬件音量。' -ForegroundColor Yellow
    }
    $adapterShell=Join-Path $env:WINDIR 'System32\WindowsPowerShell\v1.0\powershell.exe'
    if ($adapterAction -eq 'Install') {
        & $adapterShell -NoLogo -NoProfile -ExecutionPolicy Bypass -File $adapterManagerPath -Action Install -App NetEase -BundlePath $adapterBundlePath -BundleHash $adapterBundleHash -NoMenu
    } else {
        & $adapterShell -NoLogo -NoProfile -ExecutionPolicy Bypass -File $adapterManagerPath -Action $adapterAction -App NetEase -NoMenu
    }
    if ($LASTEXITCODE -ne 0) {throw '操作未完成，请查看上方管理脚本的提示。'}
    if ($adapterAction -eq 'Install') {
        $adapterStatePath=Join-Path $env:LOCALAPPDATA 'AudioExclusive\state\NetEase.json'
        $adapterState=Get-Content -LiteralPath $adapterStatePath -Raw -Encoding UTF8|ConvertFrom-Json
        if (-not $adapterState.enabled -or $adapterState.target -ine $adapterExpectedExecutable) {
            throw '未能确认所选网易云的安装状态，请检查管理脚本输出。'
        }
        Write-Host '安装完成。请从开始菜单 AudioExclusive → 网易云音乐（独占插件）启动，并在播放设置中开启独占。' -ForegroundColor Green
    }
} catch {
    Write-Host ('操作未完成：'+$_.Exception.Message) -ForegroundColor Red
    exit 1
}
