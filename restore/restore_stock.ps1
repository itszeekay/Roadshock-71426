# Restore / verify the stock base-board firmware (STM8S003F3P6)
#
# Default action is READ-ONLY verification: compares the device content with
# the restore image. It never writes unless -Write is given explicitly.
#
#   powershell -File restore\restore_stock.ps1            # verify only (safe)
#   powershell -File restore\restore_stock.ps1 -Write     # actually reflash
#
# Wiring: ST-Link on the board's SWIM header (V+, GND, SWIM, RST).
# The board resets when the ST-Link connects - that is expected.
param(
    [switch]$Write,
    [string]$Flash = "stm8flash",
    [string]$Part  = "stm8s003f3",
    [string]$Root  = (Split-Path -Parent $PSScriptRoot)
)

$fw = Join-Path $Root "restore\firmware_stock.ihx"
$ee = Join-Path $Root "restore\eeprom_stock.ihx"

if (-not (Test-Path $fw)) { throw "missing $fw" }

if (-not $Write) {
    Write-Host "== VERIFY ONLY (read-only) =="
    Write-Host "flash  vs $fw"
    & $Flash -c stlinkv2 -p $Part -v $fw 2>&1 | Where-Object { $_ -notmatch 'libusb:info' }
    Write-Host "eeprom vs $ee"
    & $Flash -c stlinkv2 -p $Part -s eeprom -v $ee 2>&1 | Where-Object { $_ -notmatch 'libusb:info' }
    Write-Host ""
    Write-Host "If both report OK, the dump in the repo matches the device exactly."
    Write-Host "Re-run with -Write to reflash."
    return
}

Write-Host "== WRITING STOCK FIRMWARE ==" -ForegroundColor Yellow
Write-Host "This overwrites the device flash with the dumped image."
& $Flash -c stlinkv2 -p $Part -w $fw 2>&1 | Where-Object { $_ -notmatch 'libusb:info' }

Write-Host "== WRITING STOCK EEPROM ==" -ForegroundColor Yellow
& $Flash -c stlinkv2 -p $Part -s eeprom -w $ee 2>&1 | Where-Object { $_ -notmatch 'libusb:info' }

Write-Host ""
Write-Host "Done. Verify with: powershell -File restore\restore_stock.ps1"
