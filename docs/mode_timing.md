# Stock channel modes - dispatch and timing

**Base board:** STM8S003F3P6. Mode dispatch lives in the base firmware.

**Status:** Mode dispatch recovered from base firmware decompilation (Ghidra 11.3.1, SHA256 a730e8b0bd32861a02fdfd75ada5a78f632b85e54de8cb0b6a3d2d85f1dcef62, 256 functions). Timing values need bench confirmation.

## Manual (source of truth)

p.6 of *71426‑manual.pdf* defines four per‑channel modes with indicator colors:

| Mode | Indicator |
|------|-----------|
| Toggle | Red |
| Momentary | Blue |
| Pulse | Green |
| Blinking | Yellow |

Hold behavior and timing are not defined; they must be measured on hardware.

## Dispatchers (same state machine, three entry points)

| Address | Name | Role |
|---------|------|------|
| 0x816D | `mode_handler` | single channel (stack parameter) |
| 0x833B | `mode_apply_block` | block (pointer + index) |
| 0x8146 | `config_mode_handler` | type‑7 12‑nibble buffer |

### Conversion
When the channel edit index is 0 or 4, the dispatcher converts the incoming mode byte:

```c
if (value == 1) value = 0;
else if (value == 3) value = 2;
else if (value == 5) value = 4;
else if (value == 7) value = 8;   // via set_6() (param + 1)
```

### Dispatch
The dispatcher writes to `channel_state_write` (0x828D) based on the converted value:

| Converted value | Write via `channel_state_write` |
|-----------------|---------------------------------|
| 0 | clears state byte |
| 1 | `0x10` or `*pb | 1` |
| 2 | `0x20` or `*pb | 2` |
| 3 | `0x30` or `*pb | 3` |
| 4 | `0x40` or `*pb | 4` |
| 5 | `0x50` or `*pb | 5` |
| 6 | `0x60` or `*pb | 6` |
| 7 | `0x70` or `*pb | 7` |
| 8 | `0x80` or `*pb | 8` |

`channel_state_write` advances `ch_edit` and loops while `ch_edit < 0x0C`, processing all 12 channels.

## Firmware assumptions (custom base)

- **Toggle** – press toggles the output on or off.  
- **Momentary** – on while held, off on release.  
- **Pulse** – turns the output on for a fixed interval (250 ms in this build); stock duration unknown.  
- **Blinking** – toggles every 100 ms (200 ms full cycle, 5 Hz). Stock rate unknown; treat as placeholder.

These timing values are placeholders; confirm on hardware.

## EEPROM encoding (bytes 0x0D‑0x14)

Eight bytes, one per channel. Example factory dump: `07 02 05 01 02 00 00 02`; after bench: `00 00 00 00 00 00 00 00`.

Each byte likely holds mode and timing information. `eeprom_write` (0x9927) and `eeprom_sequencer` (0x86E8) handle EEPROM access.

## Timing sources

Blink and pulse timing are driven by `tim4_isr` (0x9608) and `mode_tick` (0x8700), advancing the scheduler on each TIM4 tick. Exact blink period, pulse length, and hold behavior require bench measurement.

## Open items

- Precise blink period and pulse duration (bench measurement needed).  
- Full decoding of EEPROM byte fields (mode, rate, duration).  
- Hidden command semantics (0x0B, 0x0D, 0x19) – likely manufacturer‑specific; need hardware testing.  
- Bytes 1/6/7 of the display frame (ignored by STM8; may carry ASR commands).