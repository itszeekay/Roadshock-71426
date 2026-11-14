# Quick Start

This page walks you through the full path from a stock 71426 unit to a working
custom firmware: what the hardware is, how to reach the SWIM header, how to build
and flash, how to configure a channel, and what the firmware does with each
setting.

## What you are building

Two boards. The **base board** (STM8S003F3P6) is the power/output module with
the eight fused channels. The **button panel** (STM8S003K3 + ASR5601S) is the
ten-button remote with the RGB LEDs. You are modifying only the base board by
flashing the STM8 through its SWIM header. The panel is left untouched.

See [hardware.md](hardware.md) for board photos, ICs, and connectors, and
[pinouts.md](pinouts.md) for pin maps.

---

## Step 1: Understand the hardware before you touch it

### The base board

The base board is potted with factory silicone. It is the board with the eight
fused outputs (1 through 8), the 12 V high-side switching, and the SWIM header
with no designator. It also has the J2 connector that links to the panel.

Key facts:

- MCU: STM8S003F3P6, TSSOP-20, 8 KB flash, 1 KB RAM, 128 B EEPROM
- Stock clock: HSI 16 MHz master, CPU at 2 MHz
- Link to the panel: UART1, 2400 baud 8N1
- Outputs: 8 channels, 12 V high-side, through a 12-entry pin table
- Input: PA1 = ACC/ignition sense (low disables all outputs)
- Programming: SWIM header (`V+`, `GND`, `SWIM`, `RST`)

### The button panel

The panel is not potted and has three accessible headers:

- J1: panel STM8 SWIM
- J2: base to panel (2400 baud link)
- J3: ASR5601S UART1 (115200 baud display link)

### The middle ECU

You may add a middle microcontroller (Feather, ESP32, or similar) to drive the
panel. Its GPIOs may be used to read the park switch for wiper control. The
base board I/O is not modified. See [wiper_control.md](wiper_control.md).

---

## Step 2: Access the SWIM header

The base board is potted. You must peel the potting up by hand to reach the
SWIM header. Clean residue off the four pads with a stiff nylon bristle brush
and a small amount of IPA. A pogo fixture can replace hand peeling for repeatable
flashing; see [pogo_fixture.md](pogo_fixture.md).

The four SWIM pads are `V+`, `GND`, `SWIM`, `RST`. Pad positions and pitch are
in [pinouts.md](pinouts.md).

---

## Step 3: Build the custom firmware

```bash
cd firmware
make
```

`make` compiles the sources into `build/roadshock.ihx`, the application image.
It does not build the full 8 KB flash image; that lives in
`firmware/prebuilt/roadshock_full.ihx`.

---

## Step 4: Flash the base board

1. **Power off.** The unit must not be powered.
2. Connect the ST-Link to the SWIM header:
   - `V+` to `V+`
   - `GND` to `GND`
   - `SWIM` to `SWIM`
   - `RST` to `RST`
3. Keep the ST-Link on its 3.3 V rails.
4. Flash the full prebuilt image:

   ```bash
   make flash-full
   ```

   Or directly:

   ```bash
   stm8flash -c stlinkv2 -p stm8s003f3 -w firmware/prebuilt/roadshock_full.ihx
   ```

   Or flash the application image built by `make`:

   ```bash
   make flash   # or: stm8flash -c stlinkv2 -p stm8s003f3 -w build/roadshock.ihx
   ```

5. To run, remove the `RST` connection or pull the ST-Link. The MCU is held in
   reset while `RST` is wired.

After flashing, the base board runs the custom firmware. The panel LEDs should
light up and respond to button presses when the unit is powered with the panel
connected via J2.

---

## Step 5: Restore stock if needed

```powershell
# verify only (read-only, default)
powershell -File restore\restore_stock.ps1

# actually restore
powershell -File restore\restore_stock.ps1 -Write
```

The script uses `stm8flash` from `PATH`; pass `-Flash <path>` if needed. It covers
the base board. The panel STM8 images are in `dumps/panel/`; write them with the
same commands and `-p stm8s003k3`.

---

## Step 6: Configure a channel

The custom base accepts type `0x09` on the 2400-baud link to set a channel.
Send from the middle ECU or a host PC over J2.

Frame format (11 bytes):

```
seq  dir  type  flag  p0 p1 p2 p3 p4 p5  sum
  1   00    9     0    ch mode duty freq_lo freq_hi delay  sum
```

Payload: `[channel, mode, duty, freq_lo, freq_hi, delay]`

- `channel`: 1-8 (which output)
- `mode`: `0` = off, `1` = steady on, `2` = PWM
- `duty`: 0-100 (for PWM)
- `freq`: 16-bit little-endian, 50-2000 Hz (bench-tested 200-2000 Hz)
- `delay`: delayed-off seconds (0-255)
- `sum`: sum of all preceding bytes, masked to 8 bits

The reply is an 11-byte frame with `type = 0x19` (`0x09 | 0x10`).

Example: enable Channel 5 as a PWM at 200 Hz, 50% duty, no delay.

```
seq  dir  type  flag  ch mode duty freq_lo freq_hi delay  sum
 1    00   9     0    5    2   50     C8  00        0   sum
```

See [protocol.md](protocol.md) for the full frame format, all message types,
replies, and the display link.

---

## Step 7: Test the channel

1. Power the unit with the panel connected via J2.
2. Send a type `0x09` frame setting the channel.
3. Verify the output with a scope or a 12 V meter.
4. Check the panel LED indicator for the channel.
5. For PWM, confirm the frequency and duty with a scope.

Expected results:

- Channels 1, 3, 4, 5, 6, 7: hardware PWM, smooth
- Channels 2, 8: GPIO only, software PWM if used

---

## Step 8: Understand what the firmware does with settings

### Per-channel modes

The custom base implements four per-channel modes, matching the stock panel's
double-click mode button:

- **Toggle**: press toggles the output on or off
- **Momentary**: on while held, off on release
- **Pulse**: on for a fixed interval (250 ms in this build)
- **Blinking**: toggles every 100 ms (200 ms full cycle, 5 Hz)

Timing values for pulse and blinking are placeholders and must be confirmed on
hardware. See [protocol.md](protocol.md) for the mode dispatch details and the
EEPROM encoding.

### Auto-functions

- **Valet**: hold any button 800 ms, master off (anti-theft)
- **Delayed-off**: enable via type `0x09` with `delay` > 0; on momentary
  release the channel stays on for the configured seconds, then auto-off
- **Double-tap latch**: momentary mode plus the `double_tap_en` flag; two presses
  in under 1 second toggle the latch on/off
- **Force override**: type `0x0B` gives an immediate on/off/toggle that bypasses
  the state machine and is cleared by the next panel event

### EEPROM persistence

Auto-saved on button press/release, master toggle, config (`0x09`), and force
(`0x0B`).

| Address | Contents |
|---------|----------|
| 0x0D-0x14 | Mode (2 bits), on (1 bit), delayed_off_en (1), double_tap_en (1) |
| 0x15-0x1C | Delayed-off seconds per channel (0-255) |

### ACC sense

PA1 low disables all outputs. The input is polled every 2 ms. No MCU reset.

### Status frame

Type `0x0A` requests status. Returns 6 bytes: channels 1-6 on/off state, byte
6 = master state. Request by sending type `0x0A`.

---

## Channel capability summary

Channels 1, 3, 4, 5, 6, 7 have hardware PWM. Channels 2 and 8 are GPIO only.

| Group | Channels | Use |
|-------|----------|-----|
| A (TIM1) | 3, 4, 6, 7 | LED light bar dimming, shared frequency, independent brightness |
| B (TIM2) | 1, 5 | Variable-speed loads (fans, pumps), shared frequency, independent duty |
| GPIO only | 2, 8 | Simple on/off |

For full per-channel detail, frequency groups, software PWM notes, and wiring
assignments, see [channel_guide.md](channel_guide.md).

---

## Wiper control

See [wiper_control.md](wiper_control.md) for wiring the park switch and using
type `0x0D` for wiper control.
