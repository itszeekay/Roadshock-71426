#!/usr/bin/env python3
"""Validate a dumped STM8 image: integrity, structure, and round-trip to Intel HEX.

Checks:
  * exact size
  * vector table: 32 entries of the form 82 00 <hi> <lo>, targets inside flash
  * reset/handler sanity
  * erased-byte statistics
  * Intel-HEX round trip (image -> hex -> image) byte identical
"""
import hashlib
import os
import sys

BASE = 0x8000


def to_hex(data, base, path):
    def rec(addr, typ, payload):
        b = [len(payload), (addr >> 8) & 0xFF, addr & 0xFF, typ] + list(payload)
        chk = (-sum(b)) & 0xFF
        return ":" + "".join("%02X" % x for x in b + [chk])
    out = [rec(base + i, 0, data[i:i + 16]) for i in range(0, len(data), 16)]
    out.append(rec(0, 1, b""))
    open(path, "w").write("\n".join(out) + "\n")


def from_hex(path):
    img = {}
    for line in open(path):
        line = line.strip()
        if not line.startswith(":"):
            continue
        n = int(line[1:3], 16)
        addr = int(line[3:7], 16)
        typ = int(line[7:9], 16)
        data = bytes(int(line[9 + 2 * i:11 + 2 * i], 16) for i in range(n))
        if typ == 0:
            for i, b in enumerate(data):
                img[addr + i] = b
    return img


def main():
    path = sys.argv[1]
    expect = int(sys.argv[2]) if len(sys.argv) > 2 else 8192
    data = open(path, "rb").read()

    ok = True
    print("file      :", path)
    print("size      :", len(data), "expected", expect,
          "OK" if len(data) == expect else "MISMATCH")
    ok &= len(data) == expect
    print("sha256    :", hashlib.sha256(data).hexdigest())

    if len(data) == 8192:
        print("\nvector table:")
        bad = 0
        for i in range(32):
            e = data[i * 4:i * 4 + 4]
            tgt = (e[2] << 8) | e[3]
            flag = ""
            if e[0] != 0x82 or e[1] != 0x00:
                flag = "  <-- not 82 00"
                bad += 1
            if not (BASE <= tgt <= BASE + 0x1FFF):
                flag += "  <-- target outside flash"
                bad += 1
            if i < 6 or flag:
                print("  vec%02d: %02x %02x %02x %02x -> 0x%04x%s"
                      % (i, e[0], e[1], e[2], e[3], tgt, flag))
        print("  entries with problems:", bad)
        ok &= bad == 0

        ffs = data.count(0xFF)
        print("\n0xFF bytes: %d / %d (%.1f%%)" % (ffs, len(data), 100.0 * ffs / len(data)))
        code = data[0x80:0x1E00]
        print("non-0xFF in 0x8080-0x9DFF: %d/%d" %
              (sum(1 for b in code if b != 0xFF), len(code)))

    # round trip
    hx = path + ".verify.hex"
    to_hex(data, BASE, hx)
    img = from_hex(hx)
    ok_rt = all(img.get(BASE + i, -1) == data[i] for i in range(len(data)))
    print("\nIntel-HEX round trip :", "IDENTICAL" if ok_rt else "MISMATCH", "->", hx)
    ok &= ok_rt

    print("\nRESULT:", "PASS" if ok else "FAIL")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
