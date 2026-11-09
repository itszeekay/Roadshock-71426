# Button panel

![Panel PCB](../images/panel-pcb.jpg)

The panel contains two processors that do different jobs.

```
             ┌──────────────────────────────────────────────┐
   buttons → │ ASR5601S   main controller                   │
             │  · scans 8 buttons                           │
             │  · runs the UI / modes                       │
             │  · 2400-baud base link (UART1, P04/P05)      │
             │  · optional BLE                              │
             │  · 115200 display link (UART2/3)             │
             └───────────────┬──────────────────────────────┘
                             │ 9-byte 0x5A…0xEE, 115200
             ┌───────────────▼──────────────────────────────┐
             │ STM8S003K3   RGB LED driver                  │
             │  · 24 GPIOs, all outputs                     │
             │  · 8 groups of 3 = 8 RGB LEDs                │
             │  · no buttons, no ADC use, no PWM output     │
             └──────────────────────────────────────────────┘
```

## How we know

The STM8 image has no GPIO input read and no button scan. All 24 pins in its
descriptor table are outputs. Its UART runs at 115200, not the 2400-baud base
link, and it receives a 9-byte display frame (`0x5A … 0xEE`). Those 24 pins are
driven as eight groups of three from the frame's eight nibbles.

The eight buttons cannot fit on the STM8: apart from the 24 LED pins, only PD7
would be free. The live capture with the panel connected to the base shows
button frames, so something scans them. The ASR is the only other IC that can.

The ASR datasheet says the chip has a hardware keypad controller with up to 112
keys and `KEY_ROW0..13` / `KEY_COL0..7` alternate functions. The panel's eight
buttons may use that matrix rather than eight plain GPIO inputs. The exact row
and column pins are not confirmed; when the ASR firmware is dumped, check
accesses to the KEYPAD block at `0x4001_5000`.

## Why the status LEDs stay dark without the base

With the panel powered and the base disconnected, the backlight comes on but
the RGB status LEDs do not react to the buttons. The ASR is the LED authority:
it computes the colors and sends display frames to the STM8. Its UI seems to
wait for the base's startup frame (`0x1B`) and the replies to its own `07`/`08`
frames before it advances the display. With no base, it sits in a "no link"
state.

The stock base sends this frame once at boot:

```
00 FF 1B 02 00 00 00 00 00 00 1C
```

`rp2040/base_emulator.py` sends that frame (it alternates two inferred flag
values) and answers panel frames with the stock `18`/`17` replies, so the panel
can be exercised on the bench. We have not proved that the ASR needs that exact
frame; it may accept any valid base reply. The emulator is the experiment.

## Controlling the LEDs

There are two very different levels of control.

### J2 only, stock panel

- Every button frame and every base reply is readable.
- A MITM can modify or inject the base replies.
- No known command on the 2400-baud bus sets an LED. The replies echo the
  panel's request payload; they do not carry LED colors.
- A J2-only gateway can read buttons and drive the base outputs, but it cannot
  flash an arbitrary status LED.

### The private display link

- The ASR-to-STM8 link runs at 115200 and carries the 9-byte display frame.
- Injecting that frame does set the eight LED colors (eight nibbles).
- This needs a tap on the private link (two wires), which is outside a J2-only
  build.
- It is the reliable path for a CAN-driven "flash this light" feature.

For the gateway or PDU, the display-link tap is a deliberate design addition.
Without it, the gateway can only observe the panel. With it, it can control the
LEDs.

## What is still unknown

- The ASR firmware has not been dumped. Its button and UI logic is the
  remaining black box.
- Whether a hidden 2400-baud command can influence the LEDs (possible, but no
  evidence yet).
- The exact color mapping of the eight display nibbles (needs a bench test).
- Which UART2/UART3 pin pair carries the display link. The datasheet pin mux
  narrows the candidates to P00/P01, P08/P09, P19/P20, P27, P29 (UART2) or
  P06/P07, P10, P13/P14, P25/P26 (UART3); identify by continuity from STM8
  PD5/PD6.

See [asr5601.md](asr5601.md) for the ASR pinout, boot mode, and dump options.
