#!/usr/bin/env python3
"""Build a single-file reconstruction from the ASR5601S DecompileTree output.

    python tools/build_asr_reconstruction.py --decomp <dir> --out reverse/asr/app_firmware.c \
        --title "application" --base 0x10048000

The per-function files stay out of the public repository; this concatenation is
the tracked artifact, matching the STM8 reconstructions.
"""
import argparse
import pathlib
import re
import sys

FUNC = re.compile(r"// FUNC 0x([0-9a-f]{8})\s+(\S+)")


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--decomp", required=True)
    p.add_argument("--out", required=True)
    p.add_argument("--title", required=True)
    p.add_argument("--base", default="0x10000000")
    args = p.parse_args()

    d = pathlib.Path(args.decomp)
    files = sorted(d.glob("*.c"), key=lambda f: int(f.name.split("_")[0], 16))

    funcs = []
    for f in files:
        text = f.read_text(encoding="utf-8", errors="replace")
        m = FUNC.search(text)
        if not m:
            continue
        funcs.append((int(m.group(1), 16), m.group(2), text))

    out = pathlib.Path(args.out)
    with out.open("w", encoding="utf-8", newline="\n") as fh:
        fh.write("/*\n")
        fh.write(" * ASR5601S %s - reconstructed from the SWD dump.\n" % args.title)
        fh.write(" * Image base %s, Ghidra 11.3.1, language ARM:LE:32:Cortex.\n" % args.base)
        fh.write(" * %d functions, address order.\n" % len(funcs))
        fh.write(" *\n")
        fh.write(" * Decompiler output, not original source. Types are approximate.\n")
        fh.write(" * The per-function files and the Ghidra project are kept outside the\n")
        fh.write(" * public repository; this file and the index are the tracked output.\n")
        fh.write(" */\n\n")
        for addr, name, text in funcs:
            fh.write(text.rstrip() + "\n\n")

    print("wrote %s with %d functions" % (out, len(funcs)))


if __name__ == "__main__":
    sys.exit(main())
