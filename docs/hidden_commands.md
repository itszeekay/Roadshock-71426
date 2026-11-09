# Hidden protocol commands

Status: recovered from the base-board decompilation (Roadstm8true project,
256/256 functions, sha256 `a730e8b0bd32861a02fdfd75ada5a78f632b85e54de8cb0b6a3d2d85f1dcef62`).

## Frame handler (frame_handler, 0x851A)

`frame_handler` validates the 11-byte checksum and dispatches on `DAT_021f`
(frame type). If the checksum fails, `sub_86c8` is called and the function
returns.

| type | handler | behavior |
|---:|---|---|
| 7 | inline | master power / parameter exchange. Expands the 6 payload bytes into 12 nibbles and stores them through a pointer initialised to `0x9E85`. Then calls `sub_8146` and posts to `x_8080` with `_DAT_0000 = 0x1700`. |
| 8 | `button_bitmask_handler` (0x82B3) | button bitmask. Calls `sub_82b3`, sets `_DAT_0000 = 0x1800`, then calls `sub_86c2`. |
| 0x0B | `cmd_0b_handler` (0x8640) | reserved. See below. |
| 0x0D | `cmd_0d_handler` (0x8689) | reserved. See below. |
| 0x19 | `cmd_19_handler` (0x860C) | reserved. See below. |
| other | `sub_86c8` | posts to message queue via `x_8080`. |

## Type 7 detail (master power / parameter)

```c
if (DAT_021f == 7) {
  local_12 = DAT_0220;
  DAT_01f9 = (DAT_0220 == 0);
  _DAT_0000 = &UNK_0221;
  // expand 6 bytes into 12 nibbles at abStack_b
  // 6 iterations: *pbVar2 = byte >> 4; pbVar2[1] = byte & 0x0F
  local_13 = sub_8146(abStack_b);
  DAT_0002 = 8;
  _DAT_0000 = 0x1700;
  x_8080(DAT_021d, &local_13);
}
```

## Type 8 detail (button bitmask)

```c
if (DAT_021f == 8) {
  DAT_01f9 = 0;
  local_13 = sub_82b3(&DAT_0220);
  DAT_0002 = 7;
  _DAT_0000 = 0x1800;
  sub_86c2(&local_13);
}
```

## Type 0x0B handler (cmd_0b_handler, 0x8640)

```c
void cmd_0b_handler(void) {
  _DAT_0000 = (DAT_0220 << 8) | DAT_0001;
  if (DAT_0220 != 0 && DAT_0220 < 0x65 && DAT_0206 != DAT_0220) {
    DAT_0206 = DAT_0220;
    DAT_0002 = DAT_0220;
    _DAT_0000 = 0;
    eeprom_write(&DAT_01be);
    sub_86e8();
    sub_9f02();
    DAT_0002 = (1 << 8) | (DAT_0002 & 0xFF);
    _DAT_0000 = 0x1B02;
    x_8080(DAT_0002, &stack0x0001);
  }
}
```

Likely a configuration/state update. Writes to EEPROM via `eeprom_write` and
posts a `0x1B` message.

## Type 0x0D handler (cmd_0d_handler, 0x8689)

```c
void cmd_0d_handler(void) {
  DAT_0000 = DAT_0220;
  if (DAT_0220 == 0) {
    _DAT_02cb = 10000;
    sub_86c8();
    return;
  }
  if (DAT_0220 == 1) {
    sub_86df();
    DAT_0206 = 10;
    sub_86e8();
    sub_86c8();
    return;
  }
}
```

Likely a reset/clear command. `0x0D 0` sets a timer to 10000; `0x0D 1` resets
state and sets `DAT_0206 = 10`.

## Type 0x19 handler (cmd_19_handler, 0x860C)

```c
void cmd_19_handler(void) {
  DAT_0002 = 0;
  while (true) {
    DAT_0002 &= 0xFF;
    msg_post();
    pcVar1 = (char *)msg_peek(DAT_0002);
    if (*pcVar1 != 0 && pcVar1[6] == 9 && DAT_021d == pcVar1[4]) break;
    msg_next();
    if (!(carry)) { sub_86c8(); return; }
  }
  *pcVar1 = 0;
  sub_86c8();
}
```

Likely a search/poll command. Searches the message queue for a matching
sequence (`DAT_021d` matches `pcVar1[4]` and `pcVar1[6] == 9`), clears it,
and returns.

## Helper functions (named in Ghidra)

| address | renamed | behavior |
|---:|---|---|
| 0x86CB | `msg_post` | posts a message with `_DAT_0000 = 0x25` |
| 0x86D1 | `msg_next` | increments `DAT_0002` |
| 0x86D8 | `msg_peek` | returns `sub_99b6() + 0x10` |
| 0x86C2 | - | does not return; jumps to `x_8080(DAT_021d)` |
| 0x86C8 | - | returns immediately |
| 0x86DF | - | clears `DAT_0207` and `DAT_021c` |
| 0x86E8 | - | calls `state_clear`, then `eeprom_write` with `DAT_0002 = &UNK_03e8` |
| 0x9927 | `eeprom_write` | writes state to EEPROM |
| 0x9AF3 | `state_clear` | clears the per-channel state at `param_1` |

## What is still open

- Exact semantics of 0x0B, 0x0D, 0x19 need hardware testing.
- `sub_99b6` (called by `msg_peek`) is not yet fully understood.
- EEPROM byte encoding (0x0D-0x14) for mode settings is not yet decoded.

## Ghidra recording

Recorded in the Roadstm8true project via `tools/ghidra_scripts/build_project.py`
(verified with `ListAnnotations.java`):
- `sub_851a` -> `frame_handler`
- `sub_8640`/`sub_8689`/`sub_860c` -> `cmd_0b_handler`/`cmd_0d_handler`/`cmd_19_handler`
- `sub_86cb`/`sub_86d1`/`sub_86d8` -> `msg_post`/`msg_next`/`msg_peek`
- `sub_9927`/`sub_9af3` -> `eeprom_write`/`state_clear`
- Plate comments on each
