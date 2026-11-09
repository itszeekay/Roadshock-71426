#!/usr/bin/env python3
"""Bench probe helper: continuity checklist and safe hidden-command capture.

Read-only by default. Hidden-command probing requires an explicit
--confirm flag and a written acknowledgement, because those commands
write EEPROM state on the base board.

Safety:
  - Continuity mode only prints a checklist; it never touches hardware.
  - Capture mode listens on the 2400-baud bus (Feather) and logs frames.
  - Probe mode sends hidden type 0x0B/0x0D/0x19 frames; intended only
    with 12 V disconnected from loads and a verified restore image at hand.

Usage:
    python tools/bench_probe.py --checklist continuity
    python tools/bench_probe.py --checklist display-uart
    python tools/bench_probe.py --capture --port COM5
    python tools/bench_probe.py --probe-hidden --port COM5 --type 0x0D --confirm "I understand"
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

import protocol_ref as p  # noqa: E402


CONTINUITY = [
    ("Pin 2 (ch2 = PA2)", "Base board", "Multimeter continuity from PA2 pad to the channel 2 gate resistor",
     "Confirms the inferred ch2 assignment (see firmware/src/board.c)."),
    ("Display UART", "Panel, STM8 PD5 (pin 30)", "Continuity to ASR UART2/UART3 candidate pins",
     "Candidates: UART2 P00/P01, P08/P09, P19/P20, P27, P29; UART3 P06/P07, P10, P13/P14, P25/P26 (see docs/asr5601_datasheet.md)."),
    ("Display UART", "Panel, STM8 PD6 (pin 31)", "Continuity to ASR UART2/UART3 candidate pins (RX side)",
     "Same candidate list. Cross that with the TX side to fix direction."),
    ("J3 vs J2", "Panel J3 TX/RX", "Continuity to J2 signal wires",
     "J3 is the ASR UART1 header; if it does not reach J2, the ASR dump must come from SWD or the monitor."),
    ("LED colors", "Panel, each channel", "Send nibbles 0-7 (tools/led_color_sweep.py), record color",
     "Determines R/G/B order. Nibble->pin pattern is already recovered."),
]


def print_checklist(name):
    items = [c for c in CONTINUITY if name in c[0] or name == "all"]
    if not items:
        items = CONTINUITY
    print("Continuity checklist: %s\n" % name)
    for title, where, how, note in items:
        print("- %s" % title)
        print("    Board: %s" % where)
        print("    Test: %s" % how)
        print("    Note: %s\n" % note)


def capture(port, baud=115200):
    if serial is None:
        print("pyserial not installed.")
        return
    print("Listening on %s at %d baud. Ctrl+C to stop." % (port, baud))
    s = serial.Serial(port, baud, timeout=1.0)
    try:
        while True:
            line = s.readline().decode("latin1", errors="replace").strip()
            if line:
                print(line)
    except KeyboardInterrupt:
        pass
    s.close()


def probe_hidden(port, type_, flag, baud):
    print("\nWARNING: hidden-command probe writes EEPROM state.")
    print("Disconnect loads. Confirm restore images are at hand.")
    if serial is None:
        print("pyserial not installed.")
        return
    frame = p.build(0, type_, flag, bytes(6), direction=0x00)
    s = serial.Serial(port, baud, timeout=1.0)
    time.sleep(0.3)
    s.reset_input_buffer()
    s.write(frame)
    s.flush()
    time.sleep(0.5)
    reply = s.read(256).decode("latin1", errors="replace")
    s.close()
    print("TX %s" % frame.hex(" "))
    print("RX %s" % reply.strip() if reply.strip() else "(no reply)")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--checklist", choices=["continuity", "display-uart", "all"], default=None)
    ap.add_argument("--capture", action="store_true")
    ap.add_argument("--probe-hidden", action="store_true")
    ap.add_argument("--port", default=os.environ.get("ROADSHOCK_PORT", "COM5"))
    ap.add_argument("--baud", type=int, default=115200,
                    help="use 2400 for the base-bus probe, 115200 for the display link")
    ap.add_argument("--type", default="0x0D")
    ap.add_argument("--flag", type=int, default=0)
    ap.add_argument("--confirm", default="")
    args = ap.parse_args()

    if args.checklist:
        print_checklist(args.checklist)
        return
    if args.capture:
        capture(args.port, args.baud)
        return
    if args.probe_hidden:
        if args.confirm != "I understand":
            print("Refusing: pass --confirm \"I understand\" to send hidden commands.")
            return
        type_ = int(args.type, 0)
        # hidden-command probes run on the 2400-baud bus
        probe_hidden(args.port, type_, args.flag, 2400)
        return
    ap.print_help()


if __name__ == "__main__":
    main()
