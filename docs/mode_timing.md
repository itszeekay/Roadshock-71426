# Stock channel modes - dispatch and timing

Status: mode dispatch recovered from the base-board decompilation (Roadstm8true
project, Ghidra 11.3.1, sha256 `a730e8b0bd32861a02fdfd75ada5a78f632b85e54de8cb0b6a3d2d85f1dcef62`,
256/256 functions). Timing values still need bench confirmation.

## Manual (source of truth for names and colors)

`docs/71426-manual.pdf` p.6 names four per-channel modes with indicator
colors:

| Mode | Indicator color |
|---|---|
| Toggle | Red |
| Momentary | Blue |
| Pulse | Green |
| Blinking | Yellow |

The manual does not define hold behavior or timing. It also describes the
Mode double-click procedure for changing a channel's mode. Keep the names and
colors from the manual; treat timing and hold behavior as
bench items.

## Dispatchers (same state machine, three entry points)

| Address | Name | Role |
|---:|---|---|
| 0x816D | `mode_handler` | single channel (stack param) |
| 0x833B | `mode_apply_block` | block (pointer + index) |
| 0x8146 | `config_mode_handler` | type-7 12-nibble buffer |

The remaining firmware functions are around bank setters, save/restore
pairs, IWDG/TIM/UART helpers, and unused interrupt-vector filler. Names for
them are in `reverse/base_function_index.md` and the Ghidra project; the
behavioral walkthrough in `docs/firmware.md` covers the state machine.

### Conversion

When the channel edit index is 0 or 4, the dispatchers convert the incoming
mode byte:

```c
if (value == 1) value = 0;
else if (value == 3) value = 2;
else if (value == 5) value = 4;
else if (value == 7) value = 8;  // via set_6() which returns param + 1
```

### Dispatch

The dispatch runs on the converted value:

| Converted value | Write via `channel_state_write` |
|---:|---|
| 0 | clears the state byte |
| 1 | `0x10` or `*pb | 1` |
| 2 | `0x20` or `*pb | 2` |
| 3 | `0x30` or `*pb | 3` |
| 4 | `0x40` or `*pb | 4` |
| 5 | `0x50` or `*pb | 5` |
| 6 | `0x60` or `*pb | 6` |
| 7 | `0x70` or `*pb | 7` |
| 8 | `0x80` or `*pb | 8` |

`channel_state_write` (0x828D) advances `ch_edit` and loops while
`ch_edit < 0x0C`, walking all 12 channels.

The four panel modes select four of these patterns. Which pattern is Toggle
versus Momentary versus Pulse versus Blinking, and the exact hold/timing
behavior, are inferred from the manual colors and the dispatch structure
but are not proven without a stock bench capture.

## What our firmware assumes (custom base)

`firmware/src/main.c` implements the four modes as:

- **Toggle**: press flips the output on or off.
- **Momentary**: on while held, off on release. This is the hold behavior the
  user asked about; the manual does not call it "pulse".
- **Pulse**: press turns the output on for a fixed time, then off. Our build
  uses 250 ms. The stock duration has not been measured.
- **Blinking**: the output toggles every 100 ms (200 ms full cycle, 5 Hz).
  The stock rate has not been measured and may be slower; treat this as a
  placeholder pending a bench capture.

None of these times come from the manual. They are placeholders chosen for
the custom firmware and must be confirmed on hardware.

## EEPROM encoding (0x0D-0x14)

Eight bytes, one per channel. Factory dump: `07 02 05 01 02 00 00 02`; after
bench: `00 00 00 00 00 00 00 00`.

The encoding is not yet fully decoded. Each byte likely encodes the mode plus
timing parameters. `eeprom_write` (0x9927) and `eeprom_sequencer` (0x86E8)
write to EEPROM.

## Timing sources

The blink/pulse timing in the stock firmware is driven by `tim4_isr`
(0x9608) and `mode_tick` (0x8700), advancing scheduler state on the TIM4
tick. The exact blink period, pulse duration, and hold behavior need a bench
measurement: set each mode on the stock firmware and measure the output.

## What is still open

- Exact blink period and pulse duration (bench measurement needed).
- EEPROM byte encoding (mode, rate, duration fields not yet split).
- Hidden command semantics (0x0B, 0x0D, 0x19) - likely manufacturer config,
  need hardware testing.
- Bytes 1/6/7 of the display frame (ignored by STM8, may carry ASR command).
