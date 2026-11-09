# Stock channel modes - dispatch and timing

Status: mode dispatch recovered from the base-board decompilation (Roadstm8true
project, Ghidra 11.3.1, sha256 `a730e8b0bd32861a02fdfd75ada5a78f632b85e54de8cb0b6a3d2d85f1dcef62`,
256/256 functions). Timing values still need bench confirmation.

## Mode handler (mode_handler, 0x816D)

The handler does two things: convert the incoming mode byte, then dispatch on
the internal mode.

### Conversion (0x817C-0x81A6)

```c
DAT_0000 = *in_stack_00000001;
if (DAT_0000 == 1)      DAT_0000 = 0;
else if (DAT_0000 == 3) DAT_0000 = 2;
else if (DAT_0000 == 5) DAT_0000 = 4;
else if (DAT_0000 == 7) pcVar2 = sub_8490();  // falls through with DAT_0000 unchanged
*pcVar2 = DAT_0000;
```

| incoming | internal | meaning |
|---:|---:|---|
| 1 | 0 | off |
| 3 | 2 | toggle |
| 5 | 4 | momentary |
| 7 | 8 | internal for pulse path (see dispatch) |

Note: 7 is not converted to a constant; it goes through `sub_8490`, which
returns `param_1 + 1`. The dispatch below is on the converted value.

### Dispatch (0x81A7-0x82A5)

```c
cVar1 = *in_stack_00000001;
if (cVar1 == 0) { sub_84b3(); ... }
if (cVar1 == 1) { sVar3 = sub_84b9(); sub_828d(*pbVar4 | 1); }
if (cVar1 == 2) { sVar3 = sub_84c5(); sub_828d(*pbVar4 | 2); }
if (cVar1 == 3) { sVar3 = sub_84b9(); sub_828d(*pbVar4 | 3); }
if (cVar1 == 4) { sVar3 = sub_84c5(); sub_828d(*pbVar4 | 4); }
if (cVar1 == 5) { sVar3 = sub_8485(); sub_828d(*pbVar4 | 5); }
if (cVar1 == 6) { sVar3 = sub_84c5(); sub_828d(*pbVar4 | 6); }
if (cVar1 == 7) { sVar3 = sub_84a5(); sub_828d(*pbVar4 | 7); }
if (cVar1 == 8) { sVar3 = sub_8485(); *pbVar4 |= 8; }
```

Each branch writes `0x10*N` or `*pb | N` via `sub_828d` (or `sub_845d` in
`sub_82b3`). `sub_828d` advances `DAT_000e` and loops while `DAT_000e < 0x0C`.

The four stock modes are:

1. **Toggle** (internal 1): the output flips on every key event.
2. **Momentary** (internal 2): the output follows the key state (on while held).
3. **Pulse** (internal 3): the output turns on for a fixed duration, then off.
4. **Blinking** (internal 4): the output toggles on a timer.

Reserved internal modes 5-8 exist in the dispatch but have no documented UI.
They write `0x50`/`0x60`/`0x70`/`0x80` or `*pb | 5/6/7/8`.

## Helpers (named in Ghidra)

| address | renamed | behavior |
|---:|---|---|
| `sub_848b` | `channel_index_get` | returns `DAT_000e` |
| `sub_8485` | `channel_pair_get` | returns `DAT_000e >> 1` |
| `sub_84b9` | - | returns `DAT_000e >> 1` |
| `sub_84c5` | - | returns `DAT_000e` (thunk) |
| `sub_828d` | `channel_state_write` | writes byte, advances `DAT_000e`, loops while `< 0x0C` |
| `sub_8504` | `channel_advance` | advances per-channel pointer, writes `5` |
| `sub_82a8` | - | sets `DAT_000e = param_1` |

## Frame handler (frame_handler, 0x851A)

`frame_handler` validates the 11-byte checksum and dispatches on `DAT_021f`
(type). See `docs/hidden_commands.md` for the hidden-command handlers.

| type | handler | behavior |
|---:|---|---|
| 7 | inline | master power / parameter (6 bytes -> 12 nibbles at `0x9E85`, post `0x1700`) |
| 8 | `button_bitmask_handler` (0x82B3) | button bitmask (post `0x1800`) |
| 0x0B | `cmd_0b_handler` (0x8640) | reserved |
| 0x0D | `cmd_0d_handler` (0x8689) | reserved |
| 0x19 | `cmd_19_handler` (0x860C) | reserved |
| other | `sub_86c8` | posts to message queue |

## EEPROM encoding (0x0D-0x14)

Eight bytes, one per channel. Factory dump: `07 02 05 01 02 00 00 02`; after
bench: `00 00 00 00 00 00 00 00`.

The encoding is not yet fully decoded. Each byte likely encodes:

- Low 3 bits: mode (0=off, 1=toggle, 2=momentary, 3=pulse, 4=blink)
- High bits: rate/duration or parameters

`eeprom_write` (0x9927) and `sub_86e8` write to EEPROM. `sub_86e8` calls
`state_clear` (0x9AF3) then `eeprom_write` with `DAT_0002 = &UNK_03e8`.

## Timing sources

The blink/pulse timing is driven by the main loop (`x_8080`) and the TIM4
tick. Relevant RAM:

| RAM | purpose |
|---|---|
| `0x000E` | current channel/mode index (0-11) |
| `0x000D` | channel index |
| `0x02DF` | 12-entry `{ODR address, mask}` pin table |
| `0x023E` | 32-byte RX frame buffer |
| `0x025E` | RX frame length |

The exact blink period and pulse duration are likely fixed constants in the
mode handler or derived from the EEPROM settings. They need bench measurement
(set each mode, measure the output).

## What is still open

- Exact blink period and pulse duration (bench measurement needed).
- EEPROM byte encoding (mode, rate, duration fields not yet split).
- Hidden command semantics (0x0B, 0x0D, 0x19) - likely manufacturer config,
  need hardware testing.
- Bytes 1/6/7 of the display frame (ignored by STM8, may carry ASR command).

## Ghidra recording

Recorded in the Roadstm8true project via `tools/ghidra_scripts/build_project.py`
(run with Ghidra 11.3.1 headless; verified with `ListAnnotations.java`):
- `x_816d` -> `mode_handler`, `sub_851a` -> `frame_handler`
- `sub_8640`/`sub_8689`/`sub_860c` -> `cmd_0b_handler`/`cmd_0d_handler`/`cmd_19_handler`
- `sub_848b`/`sub_8485`/`sub_828d`/`sub_8504` -> `channel_index_get`/`channel_pair_get`/`channel_state_write`/`channel_advance`
- `sub_86cb`/`sub_86d1`/`sub_86d8` -> `msg_post`/`msg_next`/`msg_peek`
- `sub_9927`/`sub_9af3` -> `eeprom_write`/`state_clear`
- Plate comments on each
