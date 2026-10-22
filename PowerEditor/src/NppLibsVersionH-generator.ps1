#!/usr/bin/env pwsh

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$outputFile = Join-Path $PSScriptRoot '../../PowerEditor/src/NppLibsVersion.h'
$outputFile = [System.IO.Path]::GetFullPath($outputFile)

if (Test-Path $outputFile) {
    Remove-Item $outputFile -Force
}

function Get-VersionFromFile {
    param(
        [string]$Path,
        [string]$Pattern,
        [string]$DefaultValue = 'N/A'
    )

    if (-not (Test-Path $Path)) {
        return $DefaultValue
    }

    foreach ($line in Get-Content $Path) {
        if ($line -match $Pattern) {
            return $Matches[1]
        }
    }

    return $DefaultValue
}

$sciVerStr = Get-VersionFromFile `
    -Path (Join-Path $PSScriptRoot '../../scintilla/win32/ScintRes.rc') `
    -Pattern 'VERSION_SCINTILLA\s+"([^"]+)"'

$lexVerStr = Get-VersionFromFile `
    -Path (Join-Path $PSScriptRoot '../../lexilla/src/LexillaVersion.rc') `
    -Pattern 'VERSION_LEXILLA\s+"([^"]+)"'

$boostRegexVerStr = Get-VersionFromFile `
    -Path (Join-Path $PSScriptRoot '../../boostregex/boost/version.hpp') `
    -Pattern 'BOOST_LIB_VERSION\s+"([^"]+)"'

$content = @"
#ifndef NPPLIBSVERSION_H
#define NPPLIBSVERSION_H
// NppLibsVersion.h
// - maintained by NppLibsVersionH-generator.ps1
#define NPP_SCINTILLA_VERSION "$sciVerStr"
#define NPP_LEXILLA_VERSION "$lexVerStr"
#define NPP_BOOST_REGEX_VERSION "$boostRegexVerStr"

#endif // NPPLIBSVERSION_H
"@

Set-Content `
    -Path $outputFile `
    -Value $content `
    -Encoding ASCII `
    -NoNewline

Write-Host "Generated $outputFile"
Write-Host "Scintilla : $sciVerStr"
Write-Host "Lexilla   : $lexVerStr"
Write-Host "BoostRegex: $boostRegexVerStr"