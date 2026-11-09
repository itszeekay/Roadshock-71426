# Pinouts

All port names are STM8 port names. Package pin numbers are in brackets.

## Base board: STM8S003F3P6 (TSSOP-20)

| Pin | Name | Use on this board |
|---:|---|---|
| 1 | PD4 | free |
| 2 | PD5 | UART1 TX (panel link) |
| 3 | PD6 | UART1 RX (panel link) |
| 4 | NRST | reset |
| 5 | PA1 | **ACC / ignition sense** (input) |
| 6 | PA2 | output ch2 |
| 7 | VSS | ground |
| 8 | VCAP | core capacitor |
| 9 | VDD | supply |
| 10 | PA3 | output ch1 |
| 11 | PB4 | spare (also in the output table) |
| 12 | PB5 | free |
| 13 | PC3 | output ch7 |
| 14 | PC4 | output ch6, **TIM1_CH4**, hardware PWM |
| 15 | PC5 | output ch5 |
| 16 | PC6 | output ch4 |
| 17 | PC7 | output ch3 |
| 18 | PD1 | SWIM |
| 19 | PD2 | output ch8 |
| 20 | PD3 | free (AIN4 if analog is ever needed) |

The firmware's output table is 12 records of `{port address, mask}`; channels
1–8 use the pins above and entries 8–11 are PB4 spares.

Per-channel fuse ratings (terminals 1–8): **30, 30, 20, 20, 10, 10, 5, 5 A**.
Channels 1–2 use two **D30PW40A** MOSFETs in parallel; the others use one.

## Button panel: STM8S003K3 (LQFP-32)

| Pin | Name | Use |
|---:|---|---|
| 1 | NRST | reset |
| 2 | PA1 | RGB ch0 pin1 |
| 3 | PA2 | RGB ch0 pin2 |
| 4 | VSS | ground |
| 5 | VCAP | core capacitor |
| 6 | VDD | supply |
| 7 | PA3 | RGB ch0 pin3 |
| 8 | PF4 | RGB ch1 pin1 |
| 9 | PB7 | RGB ch1 pin2 |
| 10 | PB6 | RGB ch1 pin3 |
| 11 | PB5 | RGB ch2 pin1 |
| 12 | PB4 | RGB ch2 pin2 |
| 13 | PB3 | RGB ch2 pin3 |
| 14 | PB2 | RGB ch3 pin1 |
| 15 | PB1 | RGB ch3 pin2 |
| 16 | PB0 | RGB ch3 pin3 |
| 17 | PE5 | RGB ch4 pin1 |
| 18 | PC1 | RGB ch4 pin2 |
| 19 | PC2 | RGB ch4 pin3 |
| 20 | PC3 | RGB ch5 pin1 |
| 21 | PC4 | RGB ch5 pin2 |
| 22 | PC5 | RGB ch5 pin3 |
| 23 | PC6 | RGB ch6 pin1 |
| 24 | PC7 | RGB ch6 pin2 |
| 25 | PD0 | RGB ch6 pin3 |
| 26 | PD1 | SWIM |
| 27 | PD2 | RGB ch7 pin1 |
| 28 | PD3 | RGB ch7 pin2 |
| 29 | PD4 | RGB ch7 pin3 |
| 30 | PD5 | UART1 TX (**115200 display link**) |
| 31 | PD6 | UART1 RX (**115200 display link**) |
| 32 | PD7 | unused |

All 24 RGB pins are outputs (`GPIO_Init` mode `0xF0`, initial high = LED off,
so the LEDs are active-low / common-anode).

### Channel → RGB pins (quick view)

| Ch | pin1 | pin2 | pin3 |
|---|---|---|---|
| 0 | PA1 | PA2 | PA3 |
| 1 | PF4 | PB7 | PB6 |
| 2 | PB5 | PB4 | PB3 |
| 3 | PB2 | PB1 | PB0 |
| 4 | PE5 | PC1 | PC2 |
| 5 | PC3 | PC4 | PC5 |
| 6 | PC6 | PC7 | PD0 |
| 7 | PD2 | PD3 | PD4 |

The R/G/B order within each triplet and the exact color per display nibble
still need a bench confirmation.

## ASR5601S (QFN-48)

Numbering is standard QFN: pin 1 at the dot, counterclockwise. Top edge reads
left→right `48 … 37`; bottom edge `13 … 24`.

| Pin | Signal | Pin | Signal |
|---:|---|---:|---|
| 1 | RFO (RF out) | 25 | VSSD |
| 2 | VCCRFB | 26 | CX2 |
| 3 | P27 / VMICTM | 27 | CX1 |
| 4 | P28 | 28 | VDDFLSH |
| 5 | P29 | 29 | P08 |
| 6 | P23 | 30 | P09 |
| 7 | P24 | 31 | P13 |
| 8 | P15 | 32 | P14 |
| 9 | P16 | 33 | VCCBB |
| 10 | P02 | 34 | P21 |
| 11 | P03 | 35 | P22 |
| 12 | VBATA | 36 | P07 |
| 13 | **P04 / UART1_TXD** | 37 | P06 |
| 14 | **P05 / UART1_RX** | 38 | P11 |
| 15 | P17 | 39 | P12 |
| 16 | P18 | 40 | **P00 / SEL0** |
| 17 | P25 | 41 | **P01 / SEL1** |
| 18 | P26 | 42 | P19 |
| 19 | VDDAO | 43 | P20 |
| 20 | XO32KI | 44 | **RSTN** |
| 21 | VDDDIG | 45 | P10 |
| 22 | VBATB | 46 | XO16MI |
| 23 | VDCSW | 47 | XO16MO |
| 24 | VDCOUT | 48 | VCCRFA |
| 49 | PAD (GND) | | |

`SEL0` (P00) and `SEL1` (P01): `SEL0=0, SEL1=0` boots from flash;
`SEL0=1, SEL1=0` selects UART download on P04/P05. `SEL1` is held low by its
internal pull-down and is not on J3.

Package: QFN48, 6 x 6 mm, 0.4 mm pitch, 30 digital I/O. The datasheet pin mux
puts UART0/1/2/3 on several pins; the display-link candidates are listed in
[asr5601_datasheet.md](asr5601_datasheet.md).

## Headers

### J1: STM8 SWIM

| Pad | Signal |
|---|---|
| `+` | V+ (3.3 V / 5 V) |
| `SWIM` | PD1 |
| `RST` | NRST |

### J3: ASR5601S

| Pad | Signal |
|---|---|
| `GND` | ground |
| `+3.3` | 3.3 V |
| `TX` | ASR P04 / UART1 TX (pin 13) |
| `RX` | ASR P05 / UART1 RX (pin 14) |
| `RST` | ASR RSTN (pin 44) |
| `SEL0` | ASR P00 (pin 40) |

`SEL1` (P01, pin 41) is not brought out; it has an internal pull-down.

### J2: base ↔ panel

Four wires: power, GND, and two 2400-baud signal wires. There is **no CAN and no
address field** on this link.

## Feather RP2040 wiring

### Passive dual-channel listen

| Feather | Board |
|---|---|
| `RX` (GP1) | one signal wire |
| `D9` (GP9) | the other signal wire |
| `GND` | GND |

TX pins are not connected. Check that the idle level is 3.3 V; the RP2040 is
not 5 V tolerant.

### Panel impersonator (drive the base)

| Feather | Base |
|---|---|
| `TX` (GP0) | base RX (panel→base line), panel TX disconnected |
| `RX` (GP1) | base TX (base→panel line) |
| `GND` | GND |

### Base emulator (test the panel standalone)

| Feather | Panel |
|---|---|
| `TX` (GP0) | panel RX (the base→panel line) |
| `RX` (GP1) | panel TX (the panel→base line) |
| `GND` | GND |
