# Hidden protocol commands

MCU: **STM8S003F3P6** (base board, power/output module). Not the STM8S003K3 on the button panel.

Status: recovered from the base-board decompilation (Roadstm8true project,
256/256 functions, sha256 `a730e8b0bd32861a02fdfd75ada5a78f632b85e54de8cb0b6a3d2d85f1dcef62`).

## Frame handler (frame_handler, 0x851A)

`frame_handler` validates the 11-byte checksum and dispatches on `frame_type`
(frame type). If the checksum fails, `noop_c` is called and the function
returns.

| type | handler | behavior |
|---:|---|---|
| 7 | inline | master power / parameter exchange. Expands the 6 payload bytes into 12 nibbles and stores them through a pointer initialized to `0x9E85`. Then calls `config_mode_handler` and posts to `message_post_loop` with the 0x1700 post code. |
| 8 | `button_bitmask_handler` (0x82B3) | button bitmask. Calls `button_bitmask_handler`, sets `_tmp_b0 = (byte *)0x1800`, then calls `post_dispatch`. |
| 0x0B | `cmd_0b_handler` (0x8640) | reserved. See below. |
| 0x0D | `cmd_0d_handler` (0x8689) | reserved. See below. |
| 0x19 | `cmd_19_handler` (0x860C) | reserved. See below. |
| other | `noop_c` | posts to message queue via `message_post_loop`. |

## Type 7 detail (master power / parameter)

```c
if (frame_type == 7) {
  local_12 = frame_flag;
  master_off = (frame_flag == 0);
  _tmp_b0 = &UNK_0221;
  // expand 6 bytes into 12 nibbles at abStack_b
  // 6 iterations: *pbVar2 = byte >> 4; pbVar2[1] = byte & 0x0F
  local_13 = config_mode_handler(abStack_b);
  tmp_w0._0_1_ = 8;
  _tmp_b0 = (byte *)0x1700;
  message_post_loop(frame_base, &local_13);
}
```

## Type 8 detail (button bitmask)

```c
if (frame_type == 8) {
  master_off = 0;
  local_13 = button_bitmask_handler(&frame_flag);
  tmp_w0._0_1_ = 7;
  _tmp_b0 = (byte *)0x1800;
  post_dispatch(&local_13);
}
```

## Type 0x0B handler (cmd_0b_handler, 0x8640)

```c
void cmd_0b_handler(void) {
  _tmp_b0 = (frame_flag << 8) | tmp_b1;
  if (frame_flag != 0 && frame_flag < 0x65 && cfg_value != frame_flag) {
    cfg_value = frame_flag;
    tmp_w0 = frame_flag;
    _tmp_b0 = 0;
    eeprom_write(&eeprom_tx);
    eeprom_sequencer();
    seq_alloc_2();
    tmp_w0 = (1 << 8) | (tmp_w0 & 0xFF);
    _tmp_b0 = (byte *)0x1B02;
    message_post_loop(tmp_w0, &stack0x0001);
  }
}
```

Likely a configuration/state update. Writes to EEPROM via `eeprom_write` and
posts a `0x1B` message.

## Type 0x0D handler (cmd_0d_handler, 0x8689)

```c
void cmd_0d_handler(void) {
  tmp_b0 = frame_flag;
  if (frame_flag == 0) {
    _DAT_02cb = 10000;
    noop_c();
    return;
  }
  if (frame_flag == 1) {
    reset_state();
    cfg_value = 10;
    eeprom_sequencer();
    noop_c();
    return;
  }
}
```

Likely a reset/clear command. `0x0D 0` sets a timer to 10000; `0x0D 1` resets
state and sets `cfg_value = 10`.

## Type 0x19 handler (cmd_19_handler, 0x860C)

```c
void cmd_19_handler(void) {
  tmp_w0 = 0;
  while (true) {
    tmp_w0 &= 0xFF;
    msg_post();
    pcVar1 = (char *)msg_peek(tmp_w0);
    if (*pcVar1 != 0 && pcVar1[6] == 9 && frame_base == pcVar1[4]) break;
    msg_next();
    if (!(carry)) { noop_c(); return; }
  }
  *pcVar1 = 0;
  noop_c();
}
```

Likely a search/poll command. Searches the message queue for a matching
sequence (`frame_base` matches `pcVar1[4]` and `pcVar1[6] == 9`), clears it,
and returns.

## Helper functions (named in Ghidra)

| address | renamed | behavior |
|---:|---|---|
| 0x86CB | `msg_post` | posts a message with the 0x25 code |
| 0x86D1 | `msg_next` | increments the queue index |
| 0x86D8 | `msg_peek` | returns `mul_small() + 0x10` |
| 0x86C2 | `post_dispatch` | does not return; jumps to the message loop |
| 0x86C8 | - | returns immediately |
| 0x86DF | `reset_state` | clears the queue-state bytes |
| 0x86E8 | `eeprom_sequencer` | clears state, then writes EEPROM |
| 0x9927 | `eeprom_write` | writes state to EEPROM |
| 0x9AF3 | `state_clear` | clears the per-channel state at `param_1` |

## What is still open

- Exact semantics of 0x0B, 0x0D, 0x19 need hardware testing.
- `mul_small` (called by `msg_peek`) is not yet fully understood.
- EEPROM byte encoding (0x0D-0x14) for mode settings is not yet decoded.

## Ghidra recording

Recorded in the Roadstm8true project via `tools/ghidra_scripts/build_project.py`
(verified with `ListAnnotations.java`):
- `sub_851a` -> `frame_handler`
- `cmd_0b_handler`/`cmd_0d_handler`/`cmd_19_handler` (0x8640/0x8689/0x860C)
- `sub_86cb`/`sub_86d1`/`sub_86d8` -> `msg_post`/`msg_next`/`msg_peek`
- `sub_9927`/`sub_9af3` -> `eeprom_write`/`state_clear`
- Plate comments on each
