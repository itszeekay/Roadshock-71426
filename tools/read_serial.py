#!/usr/bin/env python3
"""Read a serial console (e.g. CircuitPython) for N seconds and print it.

    python tools/read_serial.py --port COM5 --seconds 15
"""
import argparse
import time

import serial

p = argparse.ArgumentParser()
p.add_argument("--port", default="COM4")
p.add_argument("--baud", type=int, default=115200)
p.add_argument("--seconds", type=float, default=10.0)
args = p.parse_args()

s = None
for attempt in range(30):
    try:
        s = serial.Serial(args.port, args.baud, timeout=0.2)
        break
    except Exception as e:
        print("open retry %d: %s" % (attempt, e))
        time.sleep(1.0)
if s is None:
    raise SystemExit(2)

time.sleep(0.2)
s.reset_input_buffer()
print("READER READY port=%s" % args.port, flush=True)
end = time.time() + args.seconds
try:
    while time.time() < end:
        data = s.read(4096)
        if data:
            print(data.decode("utf-8", "replace"), end="", flush=True)
finally:
    s.close()
