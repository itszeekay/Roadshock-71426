# ASR5601S flash dump

Firmware read from the ASR5601S (QFN-48) on the Roadshock 71426 button panel.

## How it was read

SWD with an ST-Link V2 and OpenOCD 0.12, from the ASR's own debug port:

- `SWCLK` -> U1 pin 37 (`P06`)
- `SWDIO` -> U1 pin 36 (`P07`)
- `GND` -> board ground
- Target held in the ROM download monitor (`SEL0` tied to `+3.3`, then a power
  cycle) because the application disables the SWD pins after boot.
- Adapter speed 950 kHz, memory reads only.

Procedure: [../../docs/asr5601_swd_dump.md](../../docs/asr5601_swd_dump.md).

The part answered with DPIDR `0x0bc11477` (Cortex-M0+ r0p1), and the vector
table at `0x10000000` is valid (`SP=0x20012000`, reset `0x100014C5`).

## Files

| File | Size | SHA-256 |
|---|---|---|
| `asr_flash.bin` | 1048576 | `b7b92dab982a262b6e2dc295bf7b2781ce070091b58d6b82c5a0596a9ba163fb` |
| `asr_flash.hex` | 2949405 | `6e701a31456f89331c6acd7312860a9c54fe644e9b708c72cdcbdd7dd3a388e8` |
| `asr_flash_run1.bin` | 1048576 | `b7b92dab982a262b6e2dc295bf7b2781ce070091b58d6b82c5a0596a9ba163fb` |
| `asr_flash_run2.bin` | 1048576 | `b7b92dab982a262b6e2dc295bf7b2781ce070091b58d6b82c5a0596a9ba163fb` |
| `asr_flash_run1_trimmed.bin` | 375316 | `a3caf7345b50200ffd8924eb8a8a9f77ef088bd19fc486cb7c5489496ca86fde` |
| `asr_flash_run2_trimmed.bin` | 375316 | `a3caf7345b50200ffd8924eb8a8a9f77ef088bd19fc486cb7c5489496ca86fde` |
| `asr_rom.bin` | 8192 | `79ca9db092b1b622c905589ca4c0accf008f1ae51bcc456d07cbce96d19b3dfc` |

The mask ROM at `0x00000000` is 8 KB. It is mirrored four times through the
64 KB read window, so only the first 8 KB is stored. It contains the download
monitor described in [../../docs/asr5601_monitor.md](../../docs/asr5601_monitor.md).

The two independent reads are byte-identical. The trimmed files drop the
trailing `0xFF`, which starts at offset `0x5BA14`.

## Layout

Offsets are from `0x10000000`.

| Offset | Address | Contents |
|---|---|---|
| `0x00000` | `0x10000000` | bootloader, `ASRBOOTLOADER-560X-MX-V2.0.2` |
| `0x08000` | `0x10008000` | OTA tag |
| `0x0D000` | `0x1000D000` | BLE stack ROM, `rom-asr-1.00` |
| `0x48000` | `0x10048000` | application, `app-1.0.2-20240319.1000` |
| `0x5BA14` | `0x1005BA14` | end of programmed content |
| `0xF0000` | `0x100F0000` | ATE partition, blank |

Version strings found in the image:

- bootloader: `ASRBOOTLOADER-560X-MX-V2.0.2`
- BLE ROM: `rom-asr-1.00`
- BLE stack: `ASONATA_BLE_NONOS_V1.4.1`, `BLE-1.0`, `1.0.0.0-LE`
- application: `app-1.0.2-20240319.1000`

The bootloader prints `welcome to bootloader: %s` and `boot mode: jump to app`,
and verifies the application image before jumping.

## Status

Read-only capture. Nothing was written to the chip. There is no factory restore
image for this part, so do not run erase or burn against it.
