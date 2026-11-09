# Firmware

## Base board: stock STM8S003F3P6

Full decompilation: **256 / 256 functions, 0 failures**
(`reverse/base_firmware.c`). The notes below walk the firmware top to bottom
using the Ghidra names recorded in `tools/ghidra/build_project.py`. They match
`reverse/base_function_index.md` and the decompiled C one-to-one.

### Boot / init

`system_init` (0x8E5C) brings up the board in order:

- `clk_gate_enable_1` / `clk_set_divider` / `clk_switch`: HSI 16 MHz master,
  `CKDIVR = 0x18` so the CPU runs at 2 MHz; `PCKENR1/PCKENR2 = 0xFF`.
- `iwdg_setup` / `iwdg_refresh`: independent watchdog started and refreshed.
- `tim4_egr_set` / `tim4_ier_set` / `tim4_etr_write` / `tim4_enable`: TIM4
  scheduler tick started.
- `uart1_init_2400` (0x9B17): sets `DAT_0007=0x0C`, `DAT_0006=0x80`,
  `DAT_0002=0x960`, then calls `uart1_configure` (0x8F7E). The BRR split is
  done via `shr_4` (`sub_99dc`, `>> 4`). Live value: 2400 baud
  (`BRR1=0xA0`, `BRR2=0x1A`).
- `outputs_init` (0x94D6) and `pa_outputs_init` (0x9B72): `gpio_init`
  (0x9541) on PD and PA, then the 12-entry pin table is applied.
- `state_table_init` (0x917B): builds the scheduler state block at `UNK_01bf`
  and installs the `tx_queue_drain` / `mode_tick` callbacks.
- Enable interrupts, then `message_post_loop` (0x8080) posts the unsolicited
  `0x1B` startup frame (see `protocol.md`).

### Main loops

Two loops run concurrently:

- `link_service_loop` (0x8EE6): waits for `uart_flag_c` (set by
  `uart1_rx_isr`). When set it copies the frame to `DAT_021d`, calls
  `frame_handler`, then clears the length and flags. It also services the
  `DAT_02d5` flag (set when the ACC blackout completes) and the `UNK_01bf`
  state block, and refreshes the watchdog each pass.
- `tim4_isr` (0x9608) / `mode_tick` (0x8700): the TIM4 interrupt walks five
  state blocks, counts `uart_flag_b` down to set `uart_flag_c`, advances
  `DAT_02db` toward `DAT_02d5`, and decrements the `_DAT_02cb` timer. This is
  the scheduler behind blink/pulse timing; exact periods still need bench
  measurement (see `mode_timing.md`).

### Frame handler

`frame_handler` (0x851A) validates the 11-byte additive checksum over
`DAT_021d` and dispatches on `DAT_021f` (type):

| Type | Handler | Effect |
|---:|---|---|
| 7 | inline + `config_mode_handler` (0x8146) | master power / parameter; 6 payload bytes expand to 12 nibbles, then post `0x1700` |
| 8 | `button_bitmask_handler` (0x82B3) | button bitmask into channel state, post `0x1800` |
| 0x0B | `cmd_0b_handler` (0x8640) | config/state update, EEPROM write, post `0x1B02` |
| 0x0D | `cmd_0d_handler` (0x8689) | `0x0D 0` sets `_DAT_02cb=10000`; `0x0D 1` resets state |
| 0x19 | `cmd_19_handler` (0x860C) | searches the message queue for a matching sequence and clears it |
| other | `noop_c` (0x86C8) | acknowledged nowhere; frame dropped |

A bad checksum also drops the frame. Every accepted frame gets a reply with
`dir = 0xFF` and `type | 0x10` (12 bytes for type 7, verified on the wire).

### Modes

`mode_handler` (0x816D) converts the incoming mode byte, then dispatches:

| Incoming | Internal | Meaning |
|---:|---:|---|
| 1 | 0 | off |
| 3 | 2 | toggle |
| 5 | 4 | momentary |
| 7 | 8 | pulse path |

Each internal branch writes `0x10*N` or `*pb | N` through
`channel_state_write` (0x828D), which advances `DAT_000e` and loops while
`DAT_000e < 0x0C`. The type-7 parameter path runs the same logic over 12
nibbles via `config_mode_handler`. The four stock modes (toggle / momentary /
pulse / blinking) are implemented by this dispatch. Exact blink/pulse timing
and EEPROM encoding are bench items; see `mode_timing.md`.

### Outputs

- `outputs_init` initializes PD, then walks the 12-entry RAM table at
  `0x02DF` (`{ODR address, mask}` records) through `gpio_init`.
- `channels_apply` (0x92C2) and `pin_table_apply` (0x9872) are the two
  steady-state apply loops over the same table; `pin_or` / `pin_and`
  (0x9EBA / 0x9F12) are the underlying set/clear primitives.
- Channels 1-8 map to PA3, PA2, PC7, PC6, PC5, PC4, PC3, PD2.
- Entries 8-11 are PB4 spares.
- Stock outputs are on/off. No dimming in the stock protocol.

### ACC and safety paths

- `acc_sense_sample` (0x9223) reads PA_IDR bit1 (PA1) with an 8-sample
  debounce into `DAT_02da`.
- `ext0_pa1_isr` (0x99E1) fires when PA1 is low: it takes the reset path
  (`reset_startup`), sets `DAT_02d4`, and reconfigures the sampler. When the
  ignition sense is low the firmware drops the outputs.
- The master-off path (`DAT_01f9` set by type 7 with a zero payload byte, or
  `cmd_0d_handler` with `0x0D 1`) forces all outputs off.

### RAM globals

The decompiled C uses register-bank temporaries at `0x0000-0x000F` (compiler
spill, e.g. `tmp_b0`, `tmp_ptr`, `ch_edit`) and application state above
`0x0182`. The named application addresses are:

| Address | Name | Meaning |
|---:|---|---|
| `0x0182` | `ch_state` | channel-state array (channels_apply walks 12 entries) |
| `0x01BE` | `eeprom_tx` | EEPROM write buffer |
| `0x01C3` | `sched_block` | scheduler state block |
| `0x01F9` | `master_off` | master-off flag (type 7 with zero payload byte) |
| `0x01FA` | `ch_state_base` | per-channel state base |
| `0x0206` | `cfg_value` | config value for cmd 0x0B |
| `0x021C` | `frame_sum` | RX checksum byte |
| `0x021D` | `frame_base` | RX frame buffer base |
| `0x021E` | `frame_dir` | frame direction |
| `0x021F` | `frame_type` | frame type (7, 8, 0x0B, 0x0D, 0x19) |
| `0x0220` | `frame_flag` | frame flag |
| `0x023D` | `frame_len` | frame length |
| `0x025F` | `acc_count` | ACC sample count |
| `0x0260` | `acc_buf` | ACC sample buffer |
| `0x02B8` | `pin_state_2b8` | pin-state area |
| `0x02CD` | `queue_saved` | saved message-queue head |
| `0x02CE` | `queue_head` | message-queue head |
| `0x02CF` | `seq_counter` | sequence counter |
| `0x02D1` | `tick_flag` | TIM4 tick flag |
| `0x02D4` | `sched_flag` | sampler/reset flag |
| `0x02D5` | `frame_ready` | completed-frame flag |
| `0x02D6` | `block_count` | scheduler block count |
| `0x02D7` | `mode_div` | mode divider (every 3rd tick) |
| `0x02D9` | `acc_index` | ACC sample index |
| `0x02DA` | `acc_data` | ACC sample data |
| `0x02DB` | `sampler_on` | sampler enable |
| `0x02DF` | `pin_table` | 12-entry `{ODR address, mask}` pin table |

These names are recorded in `tools/ghidra/build_project.py` and appear in
`reverse/base_firmware.c`. The `0x0000-0x000F` temporaries are compiler
register-bank spill; application state starts at `0x0182`.

### EEPROM and queue

- `eeprom_write` (0x9927) is called from `eeprom_sequencer` (0x86E8) and from
  `cmd_0b_handler`. `state_clear` (0x9AF3) clears the per-channel state.
- Per-channel settings live at EEPROM `0x0D-0x14` (8 bytes, one per channel).
  The encoding is not yet decoded.
- `tx_queue_drain` (0x935E) drains the message queue via `msg_post` /
  `msg_peek`; `msg_alloc_loop` (0x8A15) allocates sequence numbers.

### Button and reply path

- `button_frame_builder` (0x8B96) is gated by `DAT_01f9` (master on). When the
  master is off it falls back to `idle_reply_builder` (0x8C31), which fills the
  reply payload with `0x88` (idle).
- Replies use `message_post_loop`, which assembles the 11-byte frame and adds
  the 8-bit sum checksum.

### Decompilation method

- Loader: raw binary, base `0x8000`, language `STM8:BE:16`.
- Pipeline: seed vectors -> fill gaps -> seed after returns -> decompile every
  function with `tools/ghidra/DecompileTree.java`.
- The annotation layer (`tools/ghidra/build_project.py`) names the verified
  routines; `tools/build_reconstruction.py` concatenates the per-function
  output into `reverse/base_firmware.c`.
- The decompiled C is a reconstruction, not original source. Generic names
  (`sub_*`, `FUN_*`, `gap_*`, `vec_*`) remain for code that has no confirmed
  role; the named ones above are confirmed against assembly and, where
  possible, the wire.

Function indexes:

- `reverse/base_function_index.md`
- `reverse/panel_function_index.md`

---

## Button panel: STM8S003K3

Full decompilation: **147 / 147 functions, 0 failures**
(`reverse/panel_firmware.c`).

The panel STM8 is **not** a button controller. It is an RGB LED driver:

- 147 functions, but no GPIO input read and no button scan anywhere.
- All 24 descriptor pins are configured as outputs (`gpio_init` mode `0xF0`,
  initial high = LED off).
- UART1 is initialized at **115200** (`uart1_init_115200`, `DAT_0002=0xC200`).
- RX is a **9-byte** frame `0x5A … 0xEE`; four payload bytes -> 8 nibbles ->
  8 groups of 3 pins (`display_frame_handler`, 0x844C).
- 8 RGB LEDs, one per channel (see `pinouts.md` and `panel_led_map.md`).
- WWDG + TIM4; no ADC use, no I2C, no PWM output in the stock firmware.
- No button inputs; the buttons are on the ASR5601S. The `panel_main_loop`
  (0x896D) calls the display handler in a loop and never reads buttons.
- The pin helpers are `pin_set` (0x8F68), `pin_clear` (0x8F65),
  `get_pin1/2/3` (0x8EFD/0x8E7F/0x8E72), and the composed
  `pin1_set_low/high` (0x8F38/0x8F44), `pin2_set_high` (0x8F3E).

---

## Custom base firmware

Source: `firmware/src/` · build: SDCC 4.5 · prebuilt: `firmware/prebuilt/`.

What it implements:

- 8 outputs with the same pin map.
- Per-channel modes: toggle / momentary / pulse / blinking.
- ACC/ignition gating.
- UART 2400 8N1 with the stock frame format and replies.
- **Hardware PWM** on TIM1 (channel 6 = PC4 = TIM1_CH4).
- Blink/pulse timing from the 2 ms TIM4 tick: blink half period 100 ms
  (50 ticks, 200 ms full cycle, 5 Hz); pulse on-time 250 ms (125 ticks).
  These rates are assumed: the manual names the modes and their indicator
  colors but does not state timing, and the stock timing has not been
  measured yet. See `firmware/src/main.c` for the calculation.
- Custom type `0x09` for off / on / PWM with duty and frequency.

Settings are RAM-only for now. The stock base stores per-channel settings in
EEPROM; the custom build does not yet.

Build:

```bash
cd firmware
make
```
