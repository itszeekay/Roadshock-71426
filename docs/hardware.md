# Hardware

**Product:** ROADSHOCK Universal LED 8 Gang Switch Panel,
**Harbor Freight SKU 71426**.
[Product page](https://www.harborfreight.com/universal-led-8-gang-switch-panel-71426.html) ·
[owner's manual](https://manuals.harborfreight.com/manuals/71000-71999/71426-193175548276.pdf).

## Base board (power/output module)

![Base/output unit](../images/base-unit.jpg)
*Base/output unit: the eight fused outputs and the switch panel connector, inside its case.*

The base is the board with the fused outputs and the switch panel connector.

![Base MCU close-up](../images/base-stm8.jpg)
*Base MCU: STM8S003F3P6 in TSSOP-20 (marking `003F3P6`, lot `CHN524RLY`).*

| Item | Value |
|------|-------|
| MCU | **STM8S003F3P6**, TSSOP-20, 8 KB flash, 1 KB RAM |
| Clock (stock) | HSI 16 MHz master, CPU 2 MHz (`CKDIVR = 0x18`) |
| Link | UART1, 2400 8N1, on PD5 (TX) / PD6 (RX) |
| Outputs | 8 channels, active-high, through a 12-entry `{port, mask}` table |
| Input | PA1 = ACC/ignition sense |
| Watchdog | IWDG in the stock image |
| Programming | SWIM header (`V+`, `GND`, `SWIM`, optionally `RST`) |
| Protection | ROP byte `0x00` (**unprotected**) |

### Potting

The base board is potted with silicone from the factory. To access the SWIM
programming header, peel the potting up by hand and remove it from the board.
Use a stiff nylon bristle brush and a small amount of IPA to clean residue off
the chips for reading. The button panel is not potted.

Output map (verified from the firmware table and by measurement):

| Ch | Pin | Ch | Pin |
|---|---|---|---|
| 1 | PA3 | 5 | PC5 |
| 2 | PA2 | 6 | PC4 |
| 3 | PC7 | 7 | PC3 |
| 4 | PC6 | 8 | PD2 |

The firmware table has 12 entries; entries 8–11 are PB4 spares.

### Hardware PWM (TIM1 + TIM2) per channel

The STM8S003F3P6 has two 16-bit timers with PWM output:

| Channel | Pin | TIM1 channel | TIM2 channel | Notes |
|---|---|---|---|---|
| 1 | PA3 | - | **CH3 (default)** | **HW PWM** (independent freq & duty) |
| 2 | PA2 | - | - | GPIO only (OSCOUT) |
| 3 | PC7 | CH2 | - | **HW PWM** (shared TIM1 freq) |
| 4 | PC6 | CH1 | - | **HW PWM** (shared TIM1 freq) |
| 5 | PC5 | - | CH1 (AFR0) | HW PWM if remapped |
| 6 | PC4 | CH4 | - | **HW PWM** (shared TIM1 freq) |
| 7 | PC3 | CH3 | - | **HW PWM** (shared TIM1 freq) |
| 8 | PD2 | - | CH3 (AFR1) | HW PWM if remapped |

**TIM1 (channels 3,4,6,7):**
- Four channels share one frequency (ARR/PSC)
- Individual duty cycles via CCRx
- Frequency range 50–2000 Hz (gate driver limit)

**TIM2 (channel 1 by default, 5/8 with AFR remap):**
- Completely independent timer
- Own frequency (1 Hz – 20+ kHz) and duty
- Channel 1 (PA3) works immediately; no remap needed
- Channels 5/8 need option byte AFR0/AFR1 set (one-time)

**Custom firmware support:**
- `PROTO_TYPE_CONFIG` (type 0x09) with `mode=2` enables PWM
- TIM1 channels: shared freq, per-channel duty
- TIM2 channel 1: independent freq + duty
- Unsupported channels fall back to steady on/off

### Output stage

Each gang is high-side switched by a **P-channel D30PW40A** (TO-263 / D2PAK, 30 A / 40 V), driven through a SOT-23 **FMMT493** NPN (marking `493`) with a gate pull-up. MCU high → NPN on → gate low → P-FET on; the channels are active-high.

**Channels 1 and 2 (the 30 A outputs) use two D30PW40A devices in parallel.**
Channels 3–4 (20 A), 5–6 (10 A) and 7–8 (5 A) use one each.

The terminal label inside the lid gives the order:

| Terminal | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|
| Fuse | 30 A | 30 A | 20 A | 20 A | 10 A | 10 A | 5 A | 5 A |

![Terminal positions](../images/terminal-positions.jpg)
*Terminal label inside the lid: 8…1 = 5 A, 5 A, 10 A, 10 A, 20 A, 20 A, 30 A, 30 A.*

![D30PW40A marking](../images/mosfet-d30pw40a.jpg)
*D30PW40A P-channel MOSFET marking (`WM`, `D30PW40A`, `2508`).*

![Output stage](../images/output-stage.jpg)
*Output stage: D30PW40A MOSFETs alongside the fuse holders.*

---

The Roadshock panel has 8 high-side outputs with varying PWM capabilities:
- 6 channels (1, 3, 4, 5, 6, 7) have hardware PWM for smooth speed/dimming control
- 2 channels (2, 8) are GPIO-only (coarse software PWM)
- Hardware PWM channels support 50-2000 Hz frequency with independent duty cycles
- 6 channels support independent duty cycles (TIM1 Group A), 2 channels share frequency (TIM2 Group B)
- All channels are 12 V high-side switched