# Hardware

**Product:** ROADSHOCK Universal LED 8 Gang Switch Panel —
**Harbor Freight SKU 71426**.
[Product page](https://www.harborfreight.com/universal-led-8-gang-switch-panel-71426.html) ·
[owner's manual](https://manuals.harborfreight.com/manuals/71000-71999/71426-193175548276.pdf)
(linked, not redistributed).

![Button panel PCB](../images/panel-pcb.jpg)

## Base board (power/output module)

The base is the board with the fused outputs and the switch panel connector.

| Item | Value |
|---|---|
| MCU | **STM8S003F3P6**, TSSOP-20, 8 KB flash, 1 KB RAM |
| Clock (stock) | HSI 16 MHz master, CPU 2 MHz (`CKDIVR = 0x18`) |
| Link | UART1, 2400 8N1, on PD5 (TX) / PD6 (RX) |
| Outputs | 8 channels, active-high, through a 12-entry `{port, mask}` table |
| Input | PA1 = ACC/ignition sense |
| Watchdog | IWDG in the stock image |
| Programming | SWIM header (`V+`, `GND`, `SWIM`, optionally `RST`) |
| Protection | ROP byte `0x00` — **unprotected** |

Output map (verified from the firmware table and by measurement):

| Ch | Pin | Ch | Pin |
|---|---|---|---|
| 1 | PA3 | 5 | PC5 |
| 2 | PA2 | 6 | PC4 (TIM1_CH4) |
| 3 | PC7 | 7 | PC3 |
| 4 | PC6 | 8 | PD2 |

The firmware table has 12 entries; entries 8–11 are PB4 spares.

There is **no current sensing**, no ADC use, and no I2C in the stock firmware.

## Button panel

![Button panel connectors](../images/panel-connectors.jpg)

The panel contains two processors.

| Ref | Part | Role |
|---|---|---|
| **U1** | **ASR5601S** (QFN-48) | Main panel controller: buttons, UI, 2400-baud link, optional BLE |
| **U2** | **STM8S003K3** (LQFP-32) | RGB LED display driver |

### Headers

| Header | Pads | Purpose |
|---|---|---|
| **J1** | `+`, `SWIM`, `RST` | STM8 SWIM programming |
| **J3** | `GND`, `+3.3`, `TX`, `RX`, `RST`, `SEL0` | ASR5601S UART1 / boot mode |
| **J2** | 4-wire cable | To the base: power, GND, two 2400-baud signal wires |
| **PZ20** | 6-pin | Unidentified test/programming header (no code evidence yet) |

### What is on which MCU

| Function | Owner |
|---|---|
| 8 buttons | **ASR5601S** |
| 8 RGB status LEDs | STM8S003K3, driven by the ASR over 115200 |
| Backlight | Separate always-on / ASR-controlled light |
| 2400-baud base link | ASR5601S (UART1) |
| Display link | ASR5601S → STM8, 115200, 9-byte frames |

The STM8 has **no button inputs**. All 24 of its GPIOs are outputs for the RGB
LEDs. This is why the panel works when connected to the base but its status
LEDs stay dark when the base is absent: the ASR is waiting for the base's
startup/handshake.

---

## Identified silicon

| Part | Package | Notes |
|---|---|---|
| STM8S003F3P6 | TSSOP-20 | Base MCU |
| STM8S003K3 | LQFP-32 | Panel RGB LED driver |
| ASR5601S | QFN-48 | Panel controller / BLE SoC |
| 16 MHz crystal | — | ASR clock |
| 32.768 kHz crystal | — | Optional RTC (reference design) |

The panel PCB marking on U1 reads `ASR5601S`, `FD1A21G`, `P19K89-00`.

---

## What is *not* on the hardware

- No CAN transceiver/controller on either stock board.
- No current shunt or current-sense amplifier.
- No external flash on the ASR (1 MB is inside the SiP).
- No light sensor path in the STM8 firmware (no ADC at all).

If an ambient-light sensor exists on the panel, it is on the ASR (which has
ADC pins) or handled by analog backlight circuitry. The ASR firmware has not
been dumped, so that remains **?**.

---

## Power and safety

- The base runs from 12 V automotive power.
- Never connect the ST-Link's 3.3 V while the board is powered from 12 V.
- The ST-Link `RST` wire holds the MCU in reset; remove it to run.
- Fuse every output. Do not work on the unit live.
