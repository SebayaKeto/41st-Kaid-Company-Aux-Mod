param([Parameter(Mandatory=$true)][string]$AuxPath,[switch]$VerifyOnly)
$ErrorActionPreference='Stop'
$manifest=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'MEAP_MANIFEST.json') -Raw | ConvertFrom-Json
if(@($manifest).Count -ne 6){throw 'Expected the six approved engineering addons'}
$destination=[IO.Path]::GetFullPath($AuxPath)
if(-not (Test-Path -LiteralPath (Join-Path $destination 'Addons') -PathType Container)){throw 'Select an existing Aux folder with an Addons directory'}
$protected=@('C:\Users\Administrator\Desktop\Arma Server\@41st_Elite_Corps_Kaid_Co_Aux_Mod','C:\Users\Administrator\Documents\ModStagingDirectory\3048946639')
if($destination.TrimEnd('\') -in $protected){throw 'This shared Aux is reserved for independent Training; select the separate Main/test copy'}
foreach($item in $manifest){
 if($item.file -notmatch '^Addons/MEAP_[A-Za-z_]+\.pbo$'){throw 'Unexpected manifest path'}
 $source=Join-Path $PSScriptRoot ('Aux-Patch/'+$item.file)
 if((Get-FileHash -LiteralPath $source -Algorithm SHA256).Hash -ne $item.sha256){throw ('Package checksum mismatch: '+$item.file)}
}
if($VerifyOnly){Write-Output 'All six package addon checksums passed; no files changed.';return}
$folderName=Split-Path $destination -Leaf
$active=@(Get-CimInstance Win32_Process -Filter "Name LIKE 'arma3%.exe'" | Where-Object {$_.CommandLine -and ($_.CommandLine.Contains($destination) -or $_.CommandLine.Contains($folderName))})
if($active.Count){throw 'An Arma process is using this Aux copy. Stop that session before installing; no files changed.'}
$backup=Join-Path $PSScriptRoot ('install-backups/'+(Get-Date -Format 'yyyyMMdd-HHmmss'))
$changed=@()
foreach($item in $manifest){
 $source=Join-Path $PSScriptRoot ('Aux-Patch/'+$item.file);$target=Join-Path $destination $item.file
 if(Test-Path -LiteralPath $target){
  if((Get-FileHash -LiteralPath $target).Hash -eq $item.sha256){continue}
  $saved=Join-Path $backup $item.file;New-Item -ItemType Directory -Path (Split-Path $saved -Parent) -Force | Out-Null;Copy-Item -LiteralPath $target -Destination $saved
 }
 $temporary=$target+'.meap-new';Copy-Item -LiteralPath $source -Destination $temporary;Move-Item -LiteralPath $temporary -Destination $target -Force
 if((Get-FileHash -LiteralPath $target).Hash -ne $item.sha256){throw ('Installed checksum mismatch: '+$item.file)}
 $changed+=$item.file
}
[pscustomobject]@{aux=$destination;installed=(Get-Date -Format o);changed=$changed;filesVerified=6} | ConvertTo-Json | Set-Content -LiteralPath (Join-Path $destination 'MEAP-install.json')
Write-Output 'Engineering addons installed and verified. Start a fresh server/mission with matching player and HC Aux copies.'
