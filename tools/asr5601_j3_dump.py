#!/usr/bin/env python3
"""Rebuild an ASR5601S flash image from a J3-only hex capture.

The dump stub prints 32 hex characters per 16-byte line between DUMP START and
DUMP END. This tool keeps exactly those lines, concatenates them, checks the
size, writes the binary, and prints its SHA-256.

    python tools/asr5601_j3_dump.py dump.txt --out dumps/asr/j3_flash.bin
    python tools/asr5601_j3_dump.py dump.txt --out j3.bin --compare dumps/asr/asr_flash.bin
"""
import argparse
import hashlib
import pathlib
import sys

SIZES = {"1m": 0x100000, "512k": 0x80000}


def parse(capture: pathlib.Path) -> bytes:
    out = bytearray()
    for line in capture.read_text(encoding="ascii", errors="ignore").splitlines():
        s = line.strip()
        if len(s) != 32:
            continue
        if any(c not in "0123456789abcdefABCDEF" for c in s):
            continue
        out.extend(bytes.fromhex(s))
    return bytes(out)


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("capture", help="text captured from the J3 link")
    p.add_argument("--out", required=True, help="binary to write")
    p.add_argument("--size", choices=sorted(SIZES), default="1m")
    p.add_argument("--compare", help="reference image to compare against")
    args = p.parse_args()

    data = parse(pathlib.Path(args.capture))
    want = SIZES[args.size]
    print("parsed %d bytes (expected %d)" % (len(data), want))

    if len(data) != want:
        print("size mismatch: capture is incomplete or the stub did not finish")
        return 1

    out = pathlib.Path(args.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_bytes(data)
    digest = hashlib.sha256(data).hexdigest()
    print("sha256 %s" % digest)
    print("wrote %s" % out)

    if args.compare:
        ref = pathlib.Path(args.compare).read_bytes()
        same = hashlib.sha256(ref).hexdigest() == digest and ref == data
        print("compare %s: %s" % (args.compare, "identical" if same else "DIFFERS"))
        if not same:
            return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
