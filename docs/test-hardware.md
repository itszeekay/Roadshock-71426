# Bench and test hardware

MCUs tested: **STM8S003F3P6** (base), **STM8S003K3** (panel), **ASR5601S** (panel main controller).

The hardware used to reverse-engineer and test the 71426. Most of it is not part
of the final product.

## Active

| Item | Role |
|---|---|
| **Adafruit Feather RP2040 DVI** | UART sniffer, panel impersonator, base emulator. CircuitPython 10.3.1; board ID `adafruit_feather_rp2040_dvi`. |
| **ST-Link V2** + `stm8flash` | SWIM dump and flash for both STM8s. |
| **SDCC 4.5** | custom base firmware. |
| 12 V bench supply | board power. |
| Oscilloscope | PWM verification, including the 1 kHz and low-frequency checks. |
| USB-UART adapter | optional console and serial work. |

## CAN bench (not active)

**Adafruit RP2040 CAN Bus Feather** with an **MCP25625**
(MCP2515-compatible controller plus transceiver), Adafruit product 5724.

It was used during early bench testing of the CAN side. It is **not part of the
current design and is not actively used**. The gateway/PDU CAN work is still at
the prototype stage and the final controller choice is open.

Board notes:

- RP2040, 8 MB QSPI flash, 264 KB RAM, 3.3 V logic.
- MCP25625 on SPI: SCK/MOSI/MISO plus CS, INT and standby.
- 5 V charge pump for the transceiver.
- 3.5 mm terminal block: CAN H, CAN L, GND.
- 120 ohm termination fitted; cut the `TERM` jumper to remove it.
- UART0 on TX/RX; UART1 on D24/D25 (or D4/D9/D5, depending on the mux).

Why it is not in the current design:

- The final gateway or PDU may use this Feather, an MCP2515 module, CAN2040
  (PIO), or an ESP32 with TWAI. No decision has been made.
- `rp2040/can_gateway.ino` is a skeleton built around the MCP2515 library. It
  has not been validated on a vehicle.

If it is reused:

- Tie the Feather ground to the bus ground.
- Fit 120 ohm termination only at the two ends of the bus.
- Keep CAN H/L away from the 2400-baud panel link.

## What is not test hardware

- The stock base and panel boards.
- The ASR5601S, which has not been dumped.
- Any vehicle wiring or ECU.
