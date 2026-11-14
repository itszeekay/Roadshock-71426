#!/usr/bin/env python3
"""Read the ASR5601S SiP flash over SWD with OpenOCD.

Read-only. This tool only issues init, halt, mdw and dump_image, and never
writes to the target.

Examples:

    # Is the debug port open? Prints the IDCODE check and four words.
    python tools/asr5601_swd_dump.py --probe

    # Full 1 MB read, twice, with hashes.
    python tools/asr5601_swd_dump.py --dump dumps/asr --twice

    # 512 KB part
    python tools/asr5601_swd_dump.py --dump dumps/asr --size 512k --twice

Notes:

    Base address is 0x10000000 (bootloader). The layout is documented in
    docs/asr5601_dump.md and reference/asr560x/drive/
    ASR560X_test_image_layout.md.

    If OpenOCD cannot read the IDCODE, the debug port is disabled or the
    wiring is wrong. If the IDCODE reads but 0x10000000 does not, read
    protection is active.
"""
import argparse
import hashlib
import os
import pathlib
import shutil
import subprocess
import sys
import tempfile

BASE = 0x10000000
SIZES = {"1m": 0x100000, "512k": 0x80000}

CFG = pathlib.Path(__file__).resolve().parent / "openocd" / "asr5601_swd.cfg"


def find_openocd() -> str:
    exe = shutil.which("openocd")
    if exe:
        return exe
    candidates = []
    local = os.environ.get("LOCALAPPDATA")
    if local:
        pkgs = pathlib.Path(local) / "Microsoft" / "WinGet" / "Packages"
        candidates.extend(sorted(pkgs.glob("xpack-dev-tools.openocd-*/xpack-openocd-*/bin/openocd.exe")))
    candidates.extend(
        pathlib.Path(p)
        for p in (
            r"C:\Program Files\OpenOCD\bin\openocd.exe",
            r"C:\Program Files (x86)\OpenOCD\bin\openocd.exe",
            "/usr/bin/openocd",
            "/usr/local/bin/openocd",
        )
    )
    for c in candidates:
        if pathlib.Path(c).is_file():
            return str(c)
    raise SystemExit("openocd not found. Install it, or add it to PATH.")


def run_openocd(commands, speed, timeout, verbose=False):
    exe = find_openocd()
    if not CFG.is_file():
        raise SystemExit("missing target config: %s" % CFG)
    args = [
        exe,
        "-f", "interface/stlink.cfg",
        "-f", str(CFG),
        "-c", "adapter speed %d" % speed,
    ]
    for c in commands:
        args.extend(["-c", c])
    args.extend(["-c", "shutdown"])

    print("$ " + " ".join(args))
    proc = subprocess.run(args, capture_output=True, text=True, timeout=timeout)
    out = (proc.stdout or "") + (proc.stderr or "")
    if verbose or proc.returncode != 0:
        print(out)
    return proc.returncode, out


def probe(speed):
    code, out = run_openocd(
        ["init", "halt", "reg pc", "mdw 0x10000000 4", "mdw 0x1000D000 4"],
        speed, 120, verbose=True,
    )
    low = out.lower()
    if "expected" in low and "idcode" in low:
        print("\nRESULT: IDCODE mismatch. Wiring or target power is wrong.")
        return 1
    if "no device found" in low or "open failed" in low or "unable to open" in low:
        print("\nRESULT: ST-Link not found. Check USB and the driver.")
        return 1
    if "0x10000000" in out and code == 0:
        print("\nRESULT: debug port open and memory readable.")
        return 0
    print("\nRESULT: inconclusive, see the OpenOCD output above.")
    return 2


def dump(outdir, size, speed, twice, trim):
    outdir = pathlib.Path(outdir)
    outdir.mkdir(parents=True, exist_ok=True)
    runs = 2 if twice else 1
    paths = []

    # Dump to a local temp file first. The repository may live on a mapped
    # network drive, and OpenOCD's Tcl parser mangles UNC paths.
    tmpdir = pathlib.Path(tempfile.mkdtemp(prefix="asr5601_"))
    try:
        for i in range(runs):
            name = "asr_flash_run%d.bin" % (i + 1) if twice else "asr_flash.bin"
            path = outdir / name
            if path.exists():
                path.unlink()
            raw = tmpdir / name
            print("\n== read %d of %d -> %s" % (i + 1, runs, path))
            code, out = run_openocd(
                ["init", "halt", "dump_image %s 0x%08X 0x%X" % (raw.as_posix(), BASE, size)],
                speed, 3600, verbose=True,
            )
            if code != 0 or not raw.exists():
                print("read failed")
                return 1
            shutil.copy2(raw, path)
            data = path.read_bytes()
            print("read %d bytes" % len(data))
            paths.append(path)
    finally:
        shutil.rmtree(tmpdir, ignore_errors=True)

    if trim:
        for path in paths:
            data = path.read_bytes()
            end = len(data)
            while end > 0 and data[end - 1] == 0xFF:
                end -= 1
            if end != len(data):
                trimmed = data[:end]
                tpath = path.with_name(path.stem + "_trimmed.bin")
                tpath.write_bytes(trimmed)
                print("trimmed %s: %d bytes of 0xFF removed" % (tpath.name, len(data) - end))

    sums = []
    for path in paths:
        digest = hashlib.sha256(path.read_bytes()).hexdigest()
        sums.append((path.name, digest))
        print("%s  %s" % (digest, path.name))

    if twice:
        if sums[0][1] == sums[1][1]:
            print("\nRESULT: the two reads are identical.")
        else:
            print("\nRESULT: the two reads differ. Treat this as no dump.")
            return 1

    sumfile = outdir / "SHA256SUMS"
    with sumfile.open("w", encoding="ascii", newline="\n") as fh:
        for name, digest in sums:
            fh.write("%s  %s\n" % (digest, name))
    print("wrote", sumfile)
    return 0


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--probe", action="store_true", help="check the debug port and memory read access")
    p.add_argument("--dump", metavar="DIR", help="read the flash into DIR")
    p.add_argument("--size", choices=sorted(SIZES), default="1m", help="flash size (default 1m)")
    p.add_argument("--speed", type=int, default=100, help="adapter speed in kHz (default 100)")
    p.add_argument("--twice", action="store_true", help="read twice and compare SHA-256")
    p.add_argument("--trim", action="store_true", help="also write a copy with trailing 0xFF removed")
    args = p.parse_args()

    if not args.probe and not args.dump:
        p.error("choose --probe or --dump DIR")

    if args.probe:
        return probe(args.speed)
    return dump(args.dump, SIZES[args.size], args.speed, args.twice, args.trim)


if __name__ == "__main__":
    sys.exit(main())
