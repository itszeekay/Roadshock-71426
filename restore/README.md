# Restore stock firmware

This directory contains the verified stock images and a script to verify or
restore the base board.

| File | Meaning |
|---|---|
| `firmware_stock.bin` | 8192 B stock base flash, corrected |
| `firmware_stock.ihx` | Intel HEX of the same image (used by stm8flash) |
| `eeprom_stock.bin` | 128 B stock EEPROM |
| `eeprom_stock.ihx` | Intel HEX of the EEPROM |
| `restore_stock.ps1` | verify (default) / write (`-Write`) |

`firmware_stock.bin` is byte-identical to `dumps/base/flash.bin`
(SHA-256 `a730e8b0…`).

## Verify (read-only, default)

```powershell
powershell -File restore\restore_stock.ps1
```

This runs `stm8flash -v` against the flash and EEPROM. It never writes.

## Restore

```powershell
powershell -File restore\restore_stock.ps1 -Write
```

This overwrites the device flash and EEPROM with the stock images.

The script uses `stm8flash` from `PATH`; pass `-Flash <path>` if it is elsewhere.

## Hardware

ST-Link on the SWIM header: `V+`, `GND`, `SWIM`, and `RST` for reliable
flashing. **Do not connect the ST-Link 3.3 V while the board is powered from
12 V.**

The board is held in reset while `RST` is wired; remove it to run.
