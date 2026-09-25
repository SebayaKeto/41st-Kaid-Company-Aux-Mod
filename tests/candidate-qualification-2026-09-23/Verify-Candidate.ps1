param([string]$ModPath=(Join-Path $PSScriptRoot '@Kaid_Aux_Candidate'))
$ErrorActionPreference='Stop'
$root=(Resolve-Path -LiteralPath $ModPath).Path.TrimEnd('\')
$manifest=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'final-candidate-manifest.json') -Raw | ConvertFrom-Json
$problems=[System.Collections.Generic.List[string]]::new()
$expected=@{}
foreach($entry in $manifest){
    $relative=[string]$entry.File
    $path=[IO.Path]::GetFullPath((Join-Path $root $relative))
    if(-not $path.StartsWith($root+'\',[StringComparison]::OrdinalIgnoreCase)){throw 'Manifest path escapes the mod folder'}
    $expected[$relative.ToLowerInvariant()]=$true
    if(-not (Test-Path -LiteralPath $path -PathType Leaf)){$problems.Add('Missing: '+$relative);continue}
    if((Get-Item -LiteralPath $path).Length -ne $entry.Bytes){$problems.Add('Wrong size: '+$relative);continue}
    if((Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash -ne $entry.SHA256){$problems.Add('Checksum mismatch: '+$relative)}
}
foreach($file in Get-ChildItem -LiteralPath $root -Recurse -File){
    $relative=$file.FullName.Substring($root.Length+1)
    if(-not $expected.ContainsKey($relative.ToLowerInvariant())){$problems.Add('Unexpected file: '+$relative)}
}
if($problems.Count){$problems | ForEach-Object {Write-Output $_};throw ('Candidate verification failed: '+$problems.Count+' problem(s)')}
Write-Output ('PASS: all '+$manifest.Count+' mod files match the qualified candidate; no extra files.')
Write-Output 'This verifies file integrity only. Read TONIGHT.md for remaining gameplay checks.'
