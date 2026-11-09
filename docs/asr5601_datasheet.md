# ASR5601S datasheet notes

MCU: **ASR5601S** (QFN-48) — the button panel main controller; different from both STM8S003 parts described in `firmware.md`.

These notes are a review of the ASR560X Series Datasheet V1.4.0. The OCR text
and a compressed print are in
[`reference/asr560x/drive/`](../reference/asr560x/drive/), with provenance in
[`reference/asr560x/meta/ASR560X_datasheet_provenance.md`](../reference/asr560x/meta/ASR560X_datasheet_provenance.md).

The datasheet is a raster print, so treat table cells as reading aids, not as
digit-for-digit sources. The pin tables were checked against the QFN48 EVB
schematic, the OCR text and the 150 dpi print.

## Corrections to our notes

### QFN48 pin numbers

The previous ASR pin table had four package pins shifted. The datasheet and the
QFN48 EVB schematic both give:

| Pin | Signal |
|---:|---|
| 29 | P08 |
| 30 | P09 |
| 38 | P11 |
| 45 | P10 |

The rest of the table was correct. `docs/pinouts.md` has been updated.

### 5 V tolerance

The previous note said the ASR I/O is not 5 V tolerant. That is too broad. The
datasheet says:

- P02, P03, P04 and P05 support 5 V GPIO.
- UART0 and UART1 support 5 V.
- The other GPIOs follow VBATB and should not be driven above it.
- P02-P05 follow VBATA. When VBATA is below 3.3 V, all I/O follows VBATA.

The panel runs the ASR at 3.3 V, so this does not change the current wiring. It
does mean the base link on P04/P05 is 5 V capable, and the blanket "not 5 V
tolerant" caution was wrong.

## What the datasheet adds

### Core and memory

| Item | Value |
|---|---|
| Core | ARM Cortex-M0+ with hardware multiplier |
| MCU clock | 16 or 64 MHz, software selected |
| SRAM | 96 KB system RAM, plus two 2 KB retention RAM blocks |
| Flash | 1 MB or 512 KB on-system SiP QSPI flash |
| Boot ROM | Internal ROM boot image, flash programming and secure boot |
| OTP | 1 Kbit |
| Package | QFN48, 6 x 6 mm, 0.4 mm pitch |
| GPIO | 30 digital I/O on the QFN48 |

The panel's exact flash size is still not confirmed. Read 1 MB first and trim a
`0xFF` tail if the part is the 512 KB version.

### UART pin options

The pin mux gives several pins per UART. This narrows the display-link search.

| UART | TX/RX pin options | Notes |
|---|---|---|
| UART0 | P02/P03, P15/P16, P21/P22 | P17/P18 are CTS/RTS |
| UART1 | P04/P05, P11/P12, P23/P24, P27/P28 | P04/P05 is the download and J3 pair |
| UART2 | P00/P01, P08/P09, P19/P20, P27 (RX), P29 (TX) | P00/P01 are boot straps at reset |
| UART3 | P06/P07, P13/P14, P25/P26, P10 (TX) | P06/P07 are SWD by default |

The display link is UART2 or UART3. The continuity check from STM8 PD5/PD6
should target the UART2 and UART3 pins above, not all 30 GPIOs.

### Keypad

The ASR has a hardware keypad controller with up to 112 keys, using
`KEY_ROW0..13` and `KEY_COL0..7` alternate functions. The panel has 10 buttons (8 channel, 1 power, 1 mode),
so it may use the keypad matrix rather than eight plain GPIO inputs.

This is an inference, not a confirmed panel connection. When the ASR firmware is
dumped, check accesses to the KEYPAD block at `0x4001_5000` to identify the row
and column pins.

### Peripheral base addresses

From the datasheet memory map:

| Block | Start | End |
|---|---|---|
| FLASH | `0x1000_0000` | `0x100F_FFFF` |
| SYS RAM | `0x2000_0000` | `0x2001_7FFF` |
| RET RAM0 | `0x2003_0000` | `0x2003_07FF` |
| RET RAM1 | `0x2003_0800` | `0x2003_0FFF` |
| UART0 | `0x4000_0000` | `0x4000_0FFF` |
| UART1 | `0x4000_1000` | `0x4000_1FFF` |
| UART2 | `0x4000_2000` | `0x4000_2FFF` |
| SPI0 | `0x4000_3000` | `0x4000_3FFF` |
| I2C0 | `0x4000_4000` | `0x4000_4FFF` |
| DMA | `0x4000_5000` | `0x4000_5FFF` |
| Watchdog | `0x4000_8000` | `0x4000_8FFF` |
| I2S | `0x4000_9000` | `0x4000_9FFF` |
| TIMER | `0x4001_1000` | `0x4001_1FFF` |
| AUDIO_ADC | `0x4001_3000` | `0x4001_3FFF` |
| Quadrature decoder | `0x4001_4000` | `0x4001_4FFF` |
| KEYPAD | `0x4001_5000` | `0x4001_5FFF` |
| SPI1 | `0x4001_7000` | `0x4001_7FFF` |
| UART3 | `0x4001_8000` | `0x4001_8FFF` |
| I2C1 | `0x4001_9000` | `0x4001_9FFF` |
| AUX ADC | `0x4001_A000` | `0x4001_AFFF` |
| UART4 | `0x4001_B000` | `0x4001_BFFF` |
| PWM0 | `0x4002_0000` | `0x4002_0FFF` |
| GPIO | `0x4003_0000` | `0x4003_0FFF` |
| OTP | `0x4003_2000` | `0x4003_2FFF` |
| BLE/15.4/2.4G | `0x4010_0000` | `0x4010_FFFF` |
| SYS_CON | `0x4011_0000` | `0x4011_FFFF` |

This is the map to use when reading the ASR dump. UART1 accesses identify the
2400 link, UART2/UART3 identify the display link, and KEYPAD or GPIO accesses
identify the button scan.

### Power and clock passives

The datasheet gives reference values. The panel's actual values are not all
confirmed.

| Pin | Signal | Reference connection |
|---:|---|---|
| 12 | VBATA | 1 uF decoupling |
| 19 | VDDAO | 1 uF decoupling |
| 21 | VDDDIG | 1 uF decoupling |
| 22 | VBATB | 1 uF decoupling |
| 23 | VDCSW | 4.7 uH to pin 24 |
| 24 | VDCOUT | 2.2 uF to ground |
| 26/27 | CX2/CX1 | 100 nF flying capacitor |
| 28 | VDDFLSH | 1 uF decoupling |
| 33 | VCCBB | Analog baseband supply |
| 46/47 | XO16MI/XO16MO | 16 MHz crystal |
| 20 | XO32KI | 32.768 kHz crystal input |
| 48 | VCCRFA | RF supply |

The hardware design guide also says the reset pin has an internal 25K pull-up
and an 8 ms startup delay after VBATB reaches 1.7 V.

### SWD

P06/P07 are SWD at the default pin function. The datasheet also lists alternate
SWD sets on P02/P03, P12/P18 and P19/P20 at function 8, but those require the
firmware to remap them. The ROM default is still P06/P07, so the SWD fallback in
the dump plan is unchanged.

## What the datasheet does not change

- It does not document the `welcome to download` / `>>>` monitor.
- It does not document `coredump flash all` or any read-back command.
- It does not say whether the panel's debug port is locked.
- It does not decode the panel's exact part variant or flash size.

The dump plan still starts with the J3 UART probe and falls back to SWD on
P06/P07.

## What to check next

1. Beep STM8 PD5/PD6 against the UART2 and UART3 candidate pins above to find
   the display link.
2. When the ASR dump exists, check KEYPAD and GPIO register accesses to identify
   the button scan.
3. Confirm whether the panel's ASR is the 512 KB or 1 MB part.
4. Compare the panel's actual power passives with the datasheet reference values
   before using them for repair.
