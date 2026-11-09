#!/usr/bin/env python3
"""Sweep panel LED nibbles and record colors.

Drives the STM8 LED driver over the 115200 display link (ASR -> STM8).
The gateway or Feather must be wired to STM8 PD5 (TX) / PD6 (RX).
Sends a 9-byte frame per nibble value, waits, and asks the user to
record the observed color. Prints a copy-paste table for docs/panel_led_map.md.

Safety: this only drives LEDs. It does not change base-board outputs.
Do not run with 12 V applied to the base board unless intentional.

Usage:
    python tools/led_color_sweep.py --port COM5
    python tools/led_color_sweep.py --port /dev/ttyUSB0 --channel 3
"""
import argparse
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

try:
    import serial
except ImportError:
    serial = None


def build_display_frame(nibbles):
    """nibbles: 8 values 0-15 for channels 0-7. Returns 9-byte frame.

    Frame: 5A b1 b2 b3 b4 b5 b6 b7 EE
    b2 = (ch0 << 4) | ch1, b3 = (ch2 << 4) | ch3,
    b4 = (ch4 << 4) | ch5, b5 = (ch6 << 4) | ch7.
    Bytes 1/6/7 are ignored by the STM8.
    """
    b2 = ((nibbles[0] & 0xF) << 4) | (nibbles[1] & 0xF)
    b3 = ((nibbles[2] & 0xF) << 4) | (nibbles[3] & 0xF)
    b4 = ((nibbles[4] & 0xF) << 4) | (nibbles[5] & 0xF)
    b5 = ((nibbles[6] & 0xF) << 4) | (nibbles[7] & 0xF)
    return bytes([0x5A, 0x00, b2, b3, b4, b5, 0x00, 0x00, 0xEE])


def sweep_channel(channel, port, baud, dwell):
    if serial is None:
        print("pyserial not installed; cannot open serial port.")
        return
    s = serial.Serial(port, baud, timeout=0.2)
    time.sleep(0.3)
    s.reset_input_buffer()
    # reset to all off
    off = build_display_frame([0] * 8)
    s.write(off)
    s.flush()
    time.sleep(0.3)
    results = {}
    for nib in range(8):
        nibbles = [0] * 8
        nibbles[channel] = nib
        frame = build_display_frame(nibbles)
        s.write(frame)
        s.flush()
        print("channel %d nibble %d -> frame %s" % (
            channel, nib, frame.hex(" ")))
        if sys.stdin.isatty():
            ans = input("  observed color (enter to keep, or type color): ").strip()
        else:
            ans = ""
        results[nib] = ans if ans else "<record>"
        time.sleep(dwell)
        s.write(off)
        s.flush()
        time.sleep(0.2)
    s.close()
    print("\nResult for channel %d:" % channel)
    for nib in range(8):
        print("  nibble %d: %s" % (nib, results[nib]))
    return results


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", default=os.environ.get("ROADSHOCK_PORT", "COM5"))
    ap.add_argument("--baud", type=int, default=115200)
    ap.add_argument("--channel", type=int, default=None,
                    help="single channel 0-7; default = all channels")
    ap.add_argument("--dwell", type=float, default=0.5)
    args = ap.parse_args()

    channels = [args.channel] if args.channel is not None else list(range(8))
    all_results = {}
    for ch in channels:
        all_results[ch] = sweep_channel(ch, args.port, args.baud, args.dwell)

    print("\n| Channel | nibble 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |")
    print("|---|---|---|---|---|---|---|---|---|")
    for ch in channels:
        r = all_results[ch]
        print("| %d | %s | %s | %s | %s | %s | %s | %s | %s |" % (
            ch, r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7]))
    print("\nPaste into docs/panel_led_map.md under color map.")


if __name__ == "__main__":
    main()
