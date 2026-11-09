#!/usr/bin/env python3
"""Read-only serial probe and capture tool for ASR5601S / ASR560X.

The ASR ROM download monitor is a text CLI on UART1. It prints
``1F2E3D00`` after reset in download mode and then offers a ``>>>`` prompt.
ASR's ASR582X FAQ documents ``coredump flash all`` as the command that streams
flash contents back over the same UART. It has not yet been proven on the
ASR5601S.

This tool only ever sends that one read command. It refuses any command that
contains erase, burn, boot, write or program.

Usage:

    python asr5601_dump.py --port COM7 --probe
    python asr5601_dump.py --port COM7 --dump dumps/asr
    python asr5601_dump.py --parse dumps/asr/capture-20261109-120000.txt

The board must already be in download mode. On the panel that means SEL0 high
and a reset pulse. See docs/asr5601_dump_plan.md.
"""

from __future__ import annotations

import argparse
import datetime as _dt
import hashlib
import pathlib
import re
import sys
import time

HANDSHAKE = b"AsrIot560x "
READ_COMMAND = "coredump flash all"
DEFAULT_BAUD = 115200
HIGH_BAUD = 921600

# Commands that must never be sent by this tool.
FORBIDDEN = re.compile(r"\b(erase|burn|boot|program|write)\b", re.IGNORECASE)

# Stream formats seen in DOGO:
#   :<10-char label><hex>$   coredump / flash-all stream
#   $<hex>$                  ReadImage capture
CHUNK_RE = re.compile(r":([0-9A-Za-z_.-]{10})([0-9A-Fa-f]+)\$")
IMAGE_RE = re.compile(r"\$([0-9A-Fa-f]{8,})\$")


def _stamp() -> str:
    return _dt.datetime.now().strftime("%Y%m%d-%H%M%S")


def _hex_to_bytes(text: str) -> bytes:
    if len(text) % 2:
        raise ValueError("odd number of hex characters")
    return bytes.fromhex(text)


def _sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def _write_ihex(path: pathlib.Path, data: bytes, base: int) -> None:
    """Write a 32-bit Intel HEX file with extended linear address records."""
    lines: list[str] = []
    upper = None
    for offset in range(0, len(data), 16):
        address = base + offset
        this_upper = (address >> 16) & 0xFFFF
        if this_upper != upper:
            body = bytes([0x02, 0x00, 0x00, 0x04,
                          (this_upper >> 8) & 0xFF, this_upper & 0xFF])
            lines.append(":" + body.hex().upper() + "%02X" % ((0x100 - sum(body)) & 0xFF))
            upper = this_upper
        chunk = data[offset:offset + 16]
        body = bytes([len(chunk), (address >> 8) & 0xFF, address & 0xFF, 0x00]) + chunk
        lines.append(":" + body.hex().upper() + "%02X" % ((0x100 - sum(body)) & 0xFF))
    lines.append(":00000001FF")
    path.write_bytes(("\n".join(lines) + "\n").encode("ascii"))


def _log_line(log, text: str) -> None:
    log.write(text + "\n")
    log.flush()


class Link:
    """Thin pyserial wrapper that logs every byte."""

    def __init__(self, port: str, baud: int, log_path: pathlib.Path):
        import serial  # imported here so --parse works without pyserial

        settings = dict(
            baudrate=baud,
            bytesize=8,
            parity="N",
            stopbits=1,
            timeout=0.2,
            write_timeout=2.0,
        )
        if "://" in port:
            self.ser = serial.serial_for_url(port, **settings)
        else:
            self.ser = serial.Serial(port=port, **settings)
        self.log = open(log_path, "a", encoding="utf-8", errors="replace")
        self.rx = bytearray()
        self.error = None
        _log_line(self.log, "# opened %s at %d 8N1" % (port, baud))

    def close(self) -> None:
        try:
            self.ser.close()
        finally:
            self.log.close()

    def send(self, text: str, newline: bool = True) -> None:
        if FORBIDDEN.search(text):
            raise SystemExit("refusing to send forbidden command: %r" % text)
        payload = text.encode("ascii") + (b"\r\n" if newline else b"")
        self.ser.write(payload)
        self.ser.flush()
        _log_line(self.log, "TX %r" % payload)

    def send_raw(self, payload: bytes) -> None:
        self.ser.write(payload)
        self.ser.flush()
        _log_line(self.log, "TX %r" % payload)

    def read_for(self, seconds: float) -> bytes:
        deadline = time.time() + seconds
        got = bytearray()
        while time.time() < deadline:
            try:
                data = self.ser.read(4096)
            except Exception as exc:
                self.error = exc
                _log_line(self.log, "# read error: %r" % exc)
                break
            if data:
                got.extend(data)
                self.rx.extend(data)
                self.log.write(data.decode("latin-1"))
                self.log.flush()
        return bytes(got)

    def read_until_idle(self, idle: float, maximum: float, start_timeout: float = 20.0) -> bytes:
        start = time.time()
        last = None
        got = bytearray()
        while time.time() - start < maximum:
            try:
                data = self.ser.read(4096)
            except Exception as exc:
                self.error = exc
                _log_line(self.log, "# read error: %r" % exc)
                break
            if data:
                got.extend(data)
                self.rx.extend(data)
                self.log.write(data.decode("latin-1"))
                self.log.flush()
                last = time.time()
            elif last is None:
                if time.time() - start >= start_timeout:
                    break
            elif time.time() - last >= idle:
                break
        return bytes(got)


def _show(label: str, data: bytes) -> None:
    text = data.decode("latin-1", errors="replace")
    print("--- %s (%d bytes) ---" % (label, len(data)))
    print(text if text.strip() else repr(data))
    print("--- end %s ---" % label)


def probe(link: Link) -> int:
    """Non-destructive handshake and prompt discovery."""
    print("Sending bare CRLF. Expect 'welcome to download' and a >>> prompt.")
    link.send("", newline=True)
    reply = link.read_for(2.0)
    _show("CRLF reply", reply)
    saw_any = bool(reply)

    if b">>>" not in reply and b"3D00" not in reply:
        print("No prompt. Sending the ASCII handshake and trying again.")
        link.send_raw(HANDSHAKE)
        reply += link.read_for(2.0)
        saw_any = saw_any or bool(reply)
        if reply:
            _show("handshake reply", reply)
        link.send("", newline=True)
        reply = link.read_for(2.0)
        saw_any = saw_any or bool(reply)
        if reply:
            _show("CRLF after handshake", reply)

    for command in ("get_chip_type", "help", "?"):
        print("\nSending %r" % command)
        link.send(command)
        reply = link.read_for(2.0)
        saw_any = saw_any or bool(reply)
        _show(command, reply)
        if b"1F2E3D00" in reply or b"3D00" in reply:
            print("note: the 3D00 banner appeared in this reply")

    if not saw_any:
        print("No bytes received. Check SEL0, reset, baud, TX/RX and ground.")
        if link.error:
            print("Serial error: %r" % (link.error,))
        return 1
    return 0


def dump(link: Link, outdir: pathlib.Path, idle: float, maximum: float) -> int:
    outdir.mkdir(parents=True, exist_ok=True)
    print("Waiting for the 1F2E3D00 banner and prompt.")
    banner = link.read_for(3.0)
    if banner:
        _show("startup", banner)
    if b">>>" not in banner:
        print("No prompt yet. Sending the ASCII handshake.")
        link.send_raw(HANDSHAKE)
        banner += link.read_for(2.0)
        if banner:
            _show("handshake reply", banner)
    if b">>>" not in banner:
        print("Still no prompt. Sending a bare CRLF.")
        link.send("", newline=True)
        banner += link.read_for(2.0)
        if banner:
            _show("CRLF reply", banner)

    print("\nSending read command: %s" % READ_COMMAND)
    link.send(READ_COMMAND)
    print("Capturing. Idle timeout %.1f s, start timeout 20 s, hard limit %.1f s."
          % (idle, maximum))
    data = link.read_until_idle(idle=idle, maximum=maximum)
    if not data:
        print("No data after the first attempt. Retrying once.")
        link.send(READ_COMMAND)
        data = link.read_until_idle(idle=idle, maximum=maximum)
    capture = outdir / ("capture-%s.txt" % _stamp())
    capture.write_bytes(data)
    print("Captured %d bytes to %s" % (len(data), capture))
    if not data:
        print("Nothing received. Check SEL0, reset, baud and TX/RX swap.")
        if link.error:
            print("Serial error: %r" % (link.error,))
        return 1
    return parse_capture(capture, outdir)


def parse_capture(capture: pathlib.Path, outdir: pathlib.Path | None = None) -> int:
    raw = capture.read_bytes()
    text = raw.decode("latin-1", errors="replace")
    outdir = outdir or capture.parent
    outdir.mkdir(parents=True, exist_ok=True)

    chunks = CHUNK_RE.findall(text)
    images = IMAGE_RE.findall(text)
    print("\nParsing %s" % capture)
    print("  labeled chunks: %d" % len(chunks))
    print("  bare hex blocks: %d" % len(images))

    if not chunks and not images:
        print("No known frame found. The capture is kept for inspection.")
        return 1

    written: list[pathlib.Path] = []

    if chunks:
        by_label: dict[str, bytearray] = {}
        order: list[str] = []
        for label, hexdata in chunks:
            try:
                blob = _hex_to_bytes(hexdata)
            except ValueError:
                print("  skipping malformed chunk at %s" % label)
                continue
            if label not in by_label:
                by_label[label] = bytearray()
                order.append(label)
            by_label[label].extend(blob)

        address_re = re.compile(r"0x[0-9A-Fa-f]{8}")
        addressed = [label for label in order if address_re.fullmatch(label)]
        for label in order:
            blob = bytes(by_label[label])
            path = outdir / (label + ".bin")
            path.write_bytes(blob)
            written.append(path)
            print("  %-12s %7d bytes  sha256 %s" % (label, len(blob), _sha256(blob)[:16]))

        if addressed and len(addressed) == len(order):
            pairs = sorted((int(label, 16), bytes(by_label[label])) for label in order)
            base = pairs[0][0]
            end = max(addr + len(blob) for addr, blob in pairs)
            flat = bytearray(b"\xff" * (end - base))
            for addr, blob in pairs:
                flat[addr - base:addr - base + len(blob)] = blob
            bin_path = outdir / "flash.bin"
            hex_path = outdir / "flash.hex"
            bin_path.write_bytes(flat)
            _write_ihex(hex_path, bytes(flat), base)
            written.extend([bin_path, hex_path])
            print("  flat image   %7d bytes  base 0x%08X  sha256 %s"
                  % (len(flat), base, _sha256(bytes(flat))))
        else:
            print("  labels are not all 8-digit addresses; left as separate files")

    if images:
        blob = b"".join(_hex_to_bytes(h) for h in images)
        path = outdir / "readimage.bin"
        path.write_bytes(blob)
        written.append(path)
        print("  readimage    %7d bytes  sha256 %s" % (len(blob), _sha256(blob)[:16]))

    if written:
        lines = ["%s *%s" % (_sha256(path.read_bytes()), path.name) for path in written]
        (outdir / "SHA256SUMS").write_bytes(("\n".join(lines) + "\n").encode("ascii"))
        print("  wrote        SHA256SUMS (%d files)" % len(written))

    return 0


def selftest() -> int:
    import tempfile

    work = pathlib.Path(tempfile.mkdtemp(prefix="asr5601-selftest-"))
    text = (
        "welcome to download\r\n>>>"
        ":0x10000000DEADBEEF$"
        ":0x10000004CAFEF00D$"
        "\r\n$0011223344556677$\r\n>>>"
    )
    capture = work / "capture.txt"
    capture.write_text(text, encoding="latin-1")
    rc = parse_capture(capture, work)
    if rc:
        return rc
    if (work / "0x10000000.bin").read_bytes() != bytes.fromhex("DEADBEEF"):
        print("selftest failed: first chunk")
        return 1
    if (work / "flash.bin").read_bytes() != bytes.fromhex("DEADBEEFCAFEF00D"):
        print("selftest failed: flat image")
        return 1
    if not (work / "flash.hex").exists():
        print("selftest failed: missing flash.hex")
        return 1
    if not (work / "SHA256SUMS").exists():
        print("selftest failed: missing SHA256SUMS")
        return 1
    if (work / "readimage.bin").read_bytes() != bytes.fromhex("0011223344556677"):
        print("selftest failed: readimage")
        return 1
    print("selftest ok: %s" % work)
    return 0


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--port", help="serial port, for example COM7 or /dev/ttyUSB0")
    parser.add_argument("--baud", type=int, default=DEFAULT_BAUD,
                        help="115200 (default) or 921600 (high speed)")
    parser.add_argument("--probe", action="store_true",
                        help="send CRLF, get_chip_type, help and ? only")
    parser.add_argument("--dump", metavar="DIR",
                        help="send 'coredump flash all' and capture to DIR")
    parser.add_argument("--parse", metavar="FILE",
                        help="parse an existing capture, no serial port needed")
    parser.add_argument("--selftest", action="store_true",
                        help="run the parser against a synthetic capture")
    parser.add_argument("--log", metavar="FILE",
                        help="raw session log (default: next to the capture)")
    parser.add_argument("--idle", type=float, default=10.0,
                        help="stop after this many idle seconds (default 10)")
    parser.add_argument("--max", type=float, default=600.0,
                        help="hard capture limit in seconds (default 600)")
    args = parser.parse_args(argv)

    if args.selftest:
        return selftest()

    if args.parse:
        return parse_capture(pathlib.Path(args.parse))

    if not args.port:
        parser.error("--port is required unless --parse is used")
    if not (args.probe or args.dump):
        parser.error("choose --probe or --dump")

    if args.dump:
        outdir = pathlib.Path(args.dump)
        outdir.mkdir(parents=True, exist_ok=True)
        log_path = pathlib.Path(args.log) if args.log else outdir / ("session-%s.log" % _stamp())
    else:
        log_path = pathlib.Path(args.log) if args.log else pathlib.Path("asr-probe-%s.log" % _stamp())

    print("Opening %s at %d 8N1. Log: %s" % (args.port, args.baud, log_path))
    link = Link(args.port, args.baud, log_path)
    try:
        if args.probe:
            return probe(link)
        return dump(link, pathlib.Path(args.dump), args.idle, args.max)
    finally:
        link.close()


if __name__ == "__main__":
    sys.exit(main())
