# Firmware

## Base board: stock STM8S003F3P6

Full decompilation: **256 / 256 functions, 0 failures**
(`reverse/base_firmware.c`, `reverse/asm/base.lst`).

### Boot / init

- Clock: HSI 16 MHz as master, `CKDIVR = 0x18` → CPU 2 MHz; all peripheral
  clocks enabled (`PCKENR1/2 = 0xFF`).
- UART1: 8N1, `BRR1 = 0xA0`, `BRR2 = 0x1A` → divider 6666 → **2400 baud**.
- TIM4 tick, IWDG started and refreshed.
- ITC interrupt priorities configured.

### Structure

- A small message queue with producer types `0x17` / `0x18` / `0x1B`.
- A link service: on a complete RX frame it copies the frame out, calls the
  handler, replies, then clears the buffer.
- A 32-byte TX queue drained by the main loop.
- One unsolicited `0x1B` frame is sent during init (see
  [protocol.md](protocol.md#startup-frame-0x1b)).

### Outputs

- A 12-entry table in RAM at `0x02DF`, records `{ODR address, mask}`.
- A generic pin writer does an ODR/DDR/CR1/CR2 read-modify-write.
- Channels 1–8 = PA3, PA2, PC7, PC6, PC5, PC4, PC3, PD2.
- Entries 8–11 are PB4 spares.
- Stock outputs are on/off. No dimming in the stock protocol.
- **PA1 = ACC/ignition sense**; when low the firmware drops the outputs.
- Per-channel settings live in the base EEPROM at `0x0D–0x14`.
- No ADC, no I2C, no SPI.

### Behaviour

- Key frames toggle channels; the base implements the per-channel mode logic
  itself (toggle / momentary / pulse / blinking).
- Master power off forces all outputs off.
- Blinking was observed on a live unit with an injected key frame.

---

## Button panel: STM8S003K3

Full decompilation: **147 / 147 functions, 0 failures**
(`reverse/panel_firmware.c`, `reverse/asm/panel.lst`).

The panel STM8 is **not** a button controller. It is an RGB LED driver:

- 147 functions, but no GPIO input read and no button scan anywhere.
- All 24 descriptor pins are configured as outputs (`GPIO_Init` mode `0xF0`,
  initial high = LED off).
- UART1 is initialised at **115200** (`UART1_Init` baud parameter `0x0001C200`).
- RX is a **9-byte** frame `0x5A … 0xEE`; four payload bytes → 8 nibbles →
  8 groups of 3 pins.
- 8 RGB LEDs, one per channel (see [pinouts.md](pinouts.md)).
- WWDG + TIM4; no ADC, no I2C, no PWM timer.
- No button inputs; the buttons are on the ASR5601S.

The display decoder and pin grouping are in `sub_844C` / `sub_8C52` /
`sub_8510` in the decompiled listing.

---

## Decompilation method

- Ghidra 11.3.1 with the community STM8 SLEIGH module for analysis;
  Ghidra 12.2 (Java scripts) for the final tree.
- Loader: raw binary, base `0x8000`, language `STM8:BE:16`.
- Pipeline: seed vectors → fill gaps → seed after returns → decompile every
  function → export listing.
- The decompiled C is a reconstruction, not original source. Function names are
  addresses; comments were added only where the behaviour is understood.

Function indexes:

- `reverse/base_function_index.md`
- `reverse/panel_function_index.md`

---

## Custom base firmware

Source: `firmware/src/` · build: SDCC 4.5 · prebuilt: `firmware/prebuilt/`.

What it implements:

- 8 outputs with the same pin map.
- Per-channel modes: toggle / momentary / pulse / blinking.
- ACC/ignition gating.
- UART 2400 8N1 with the stock frame format and replies.
- **Hardware PWM** on TIM1 (channel 6 = PC4 = TIM1_CH4).
- Custom type `0x09` for off / on / PWM with duty and frequency.
- EEPROM-backed settings.

Build:

```bash
cd firmware
make            # requires sdcc in PATH
```

Outputs `roadshock.ihx` (application) and the full 8 KB image used for flashing.

Bench-verified:

- UART replies to injected frames.
- Blink on a minimal build.
- Hardware PWM on channel 6 at 1 kHz and 200–2000 Hz, duty 10–100 %.

Not yet implemented:

- The four stock modes are being folded into the production build.
- CAN. The STM8S003 has no CAN controller; the gateway/PDU plan puts a
  companion MCU in the middle.

---

## Firmware sizes

| Image | Size |
|---|---|
| Stock base flash | 8192 B |
| Stock panel flash | 8192 B |
| Custom base app | ~2.6 KB |
| Custom full image | 8192 B |

The remaining flash is available for the PDU features.
