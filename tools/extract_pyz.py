#!/usr/bin/env python3
"""Extract modules from a PyInstaller PYZ archive.

DOGO's PYZ-00.pyz is a Python 3.5 archive. The header is ``PYZ\\0``, then the
four-byte Python magic, then a big-endian offset to a marshalled table of
contents. Each entry is ``(type, offset, length)`` and the payload is zlib
compressed.

Example:

    python tools/extract_pyz.py PYZ-00.pyz out data pyserial_demo
    python tools/extract_pyz.py PYZ-00.pyz out --list

The output ``.pyc`` files use a twelve-byte Python 3.5 header so a 3.5
interpreter or a 3.5-aware decompiler can load them.
"""

from __future__ import annotations

import argparse
import marshal
import pathlib
import struct
import sys
import zlib


def load_toc(data: bytes) -> tuple[bytes, dict]:
    if data[:4] != b"PYZ\0":
        raise SystemExit("not a PYZ archive: missing PYZ magic")
    magic = data[4:8]
    offset = struct.unpack("!I", data[8:12])[0]
    toc = marshal.loads(data[offset:])
    if isinstance(toc, list):
        toc = dict(toc)
    if not isinstance(toc, dict):
        raise SystemExit("unexpected TOC type: %r" % type(toc))
    return magic, toc


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("pyz", help="path to PYZ-00.pyz")
    parser.add_argument("outdir", help="directory for the extracted .pyc files")
    parser.add_argument("modules", nargs="*", help="module names, default all")
    parser.add_argument("--list", action="store_true", help="list module names")
    args = parser.parse_args(argv)

    data = pathlib.Path(args.pyz).read_bytes()
    magic, toc = load_toc(data)

    if args.list:
        for name in sorted(toc):
            print(name)
        print("%d modules" % len(toc), file=sys.stderr)
        return 0

    wanted = args.modules or sorted(toc)
    outdir = pathlib.Path(args.outdir)
    outdir.mkdir(parents=True, exist_ok=True)
    missing = 0
    for name in wanted:
        if name not in toc:
            print("missing: %s" % name, file=sys.stderr)
            missing += 1
            continue
        _typ, offset, length = toc[name]
        raw = zlib.decompress(data[offset:offset + length])
        target = outdir / (name.replace(".", "_") + ".pyc")
        target.write_bytes(magic + b"\0" * 8 + raw)
        print("%-32s %7d bytes" % (name, len(raw)))
    return 1 if missing else 0


if __name__ == "__main__":
    sys.exit(main())
