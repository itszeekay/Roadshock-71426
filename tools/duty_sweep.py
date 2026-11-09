#!/usr/bin/env python3
"""Send a duty-cycle sweep to channel 6 and print the replies.

Driven through the CircuitPython impersonator console:

    python tools/duty_sweep.py --port COM5
"""
import argparse
import os
import sys
import time

TOOLS = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, TOOLS)
import protocol_ref as p  # noqa: E402
import serial  # noqa: E402

ap = argparse.ArgumentParser()
ap.add_argument("--port", default=os.environ.get("ROADSHOCK_PORT", "COM4"))
ap.add_argument("--baud", type=int, default=115200)
args = ap.parse_args()

steps = [(d, p.set_output(0x50 + i, 6, 2, d, 1000)) for i, d in enumerate(
    (10, 20, 30, 40, 50, 60, 70, 80, 90, 100))]

s = serial.Serial(args.port, args.baud, timeout=0.3)
time.sleep(0.3)
s.reset_input_buffer()

for duty, frame in steps:
    cmd = "raw " + frame.hex(" ") + "\r\n"
    s.write(cmd.encode())
    s.flush()
    time.sleep(1.2)
    reply = s.read(256)
    txt = reply.decode("latin1").strip().replace("\r", "")
    print("duty %3d%%  TX %s" % (duty, frame.hex(" ")))
    if txt:
        for line in txt.split("\n"):
            if line.startswith("RX"):
                print("            " + line)
    time.sleep(0.8)

s.close()
print("sweep done")
