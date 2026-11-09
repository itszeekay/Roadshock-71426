#!/usr/bin/env python3
"""Offline triage report for one firmware image (no Ghidra needed).

Printed facts: file size, SHA-256, first 16 bytes (vector table head),
entropy, and the reset vector. This is the Ghidra-independent second
opinion used to sanity-check a fresh dump before importing.

Usage:
    python3 tools/triage_firmware.py dumps/base/flash.bin
    python3 tools/triage_firmware.py dumps/panel/flash.bin dumps/panel/eeprom.bin
"""
import hashlib
import math
import sys


def entropy(data):
    if not data:
        return 0.0
    counts = [0] * 256
    for b in data:
        counts[b] += 1
    n = len(data)
    return -sum((c / n) * math.log2(c / n) for c in counts if c)


def triage(path):
    with open(path, "rb") as f:
        data = f.read()
    print("=== %s ===" % path)
    print("size: %d bytes" % len(data))
    print("sha256: %s" % hashlib.sha256(data).hexdigest())
    if len(data) >= 16:
        print("first 16 bytes: %s" % data[:16].hex(" "))
        # STM8 reset vector: bytes 2-3 of slot 0 (0x8000)
        reset = (data[2] << 8) | data[3]
        print("reset vector (slot 0, bytes 2-3): 0x%04X" % reset)
    print("entropy: %.3f bits/byte" % entropy(data))
    print()


def main():
    if len(sys.argv) < 2:
        sys.exit("usage: triage_firmware.py FILE [FILE ...]")
    for path in sys.argv[1:]:
        triage(path)


if __name__ == "__main__":
    main()
