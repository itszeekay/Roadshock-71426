#!/usr/bin/env python3
"""Characterize channel 6: frequency sweep, duty steps, mode switching.

The base board is driven through the CircuitPython impersonator's USB console
(115200). Run the impersonator on the Feather first, then:

    python tools/pwm_test.py --port COM5
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

s = serial.Serial(args.port, args.baud, timeout=0.3)
time.sleep(0.3)
s.reset_input_buffer()
seq = 0x60


def send(label, frame, settle=1.6):
    global seq
    s.write(("raw " + frame.hex(" ") + "\r\n").encode())
    s.flush()
    time.sleep(settle)
    reply = s.read(256).decode("latin1")
    ok = "RX" in reply
    print("%-26s %s" % (label, "acked" if ok else "NO REPLY"))


def cfg(ch, mode, duty=0, hz=1000):
    global seq
    f = p.set_output(seq, ch, mode, duty, hz)
    seq += 1
    return f


print("== frequency sweep at 50 % duty ==")
for hz in (200, 500, 1000, 1500, 2000):
    send("ch6 PWM 50%% @ %d Hz" % hz, cfg(6, 2, 50, hz), 1.8)

print("\n== duty steps at 1 kHz ==")
for d in range(10, 101, 10):
    send("ch6 duty %d%%" % d, cfg(6, 2, d, 1000), 1.2)

print("\n== mode switching ==")
send("ch6 steady ON", cfg(6, 1), 1.5)
send("ch6 OFF", cfg(6, 0), 1.5)
send("ch6 back to PWM 30%", cfg(6, 2, 30, 1000), 1.5)

s.close()
print("\ndone")
