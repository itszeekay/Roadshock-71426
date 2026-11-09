# Dumps

Stock images read over SWIM from hardware owned by the author. Both flash
images were read twice and the two reads were byte-identical.

| File | Size | Meaning |
|---|---:|---|
| `base/flash.bin` | 8192 | base STM8S003F3P6 flash, corrected |
| `base/flash.raw.bin` | 8284 | raw read (text-mode inflated; see below) |
| `base/flash.hex` | 23053 | Intel HEX of the corrected flash |
| `base/eeprom.bin` | 128 | base EEPROM |
| `base/eeprom.raw.bin` | 129 | raw EEPROM read |
| `base/option_bytes.bin` | 64 | base option bytes |
| `base/ram.bin` | 1024 | 1 KB RAM snapshot (contains the 12-entry pin table at `0x02DF`) |
| `panel/flash.bin` | 8192 | panel STM8S003K3 flash, corrected |
| `panel/flash.raw.bin` | 8249 | raw read (text-mode inflated) |
| `panel/flash.hex` | 23053 | Intel HEX of the corrected flash |
| `panel/eeprom.bin` | 128 | panel EEPROM (all zero) |
| `panel/eeprom.raw.bin` | 128 | raw EEPROM read |
| `panel/option_bytes.bin` | 64 | panel option bytes |

`SHA256SUMS` covers every file in this directory.

## Raw vs corrected

`stm8flash` on Windows writes files in text mode, so every `0x0A` byte becomes
`0x0D 0x0A`. That is why the raw reads are longer:

```
base:  8284 = 8192 + 92
panel: 8249 = 8192 + 57
```

The corrected files are `raw.replace(b"\x0d\x0a", b"\x0a")`. The raw files are
kept as evidence. Always validate after correcting: a corrupted image still
decodes as plausible code.

## Option bytes

Both boards have `ROP = 0x00` (unprotected) and identical option bytes.

## EEPROM

- Base EEPROM contains per-channel settings at `0x0D–0x14`.
- Panel EEPROM is all zero (settings live on the base).

## RAM snapshot

`base/ram.bin` is a 1 KB snapshot of the running base. It is included because it
contains the `{port, mask}` output table at `0x02DF`, which is how the pin map
was confirmed against the firmware. It is device state, not personal data.
