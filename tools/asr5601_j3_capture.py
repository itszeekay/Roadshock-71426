#!/usr/bin/env python3
"""Run a J3-only ASR5601S flash dump through the Feather helper.

Prerequisites:

  - the Feather runs rp2040/asr_mon.py
  - the panel is powered with SEL0 high, so the ROM monitor is running
  - the Feather UART is wired to J3 TX/RX/GND at 115200

The tool sends the dump stub over the monitor `boot` command, then asks the
Feather to stream the received text over USB. The capture is written to a local
file. Rebuild the image afterwards with tools/asr5601_j3_dump.py.

    python tools/asr5601_j3_capture.py --port COM4 --out dump.txt
"""
import argparse
import pathlib
import sys
import time

import serial

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import asr_ram_boot  # noqa: E402

HERE = pathlib.Path(__file__).resolve().parent
DEFAULT_PAYLOAD = HERE / "asr_stub" / "dumpstub.bin"
HANDSHAKE = b"AsrIot560x "
CHUNK = 32


def raw_line(data: bytes) -> str:
    return "raw " + " ".join("%02x" % b for b in data)


def send(ser, text: str, wait: float = 0.4) -> bytes:
    ser.reset_input_buffer()
    ser.write((text + "\r\n").encode())
    time.sleep(wait)
    return ser.read(4096)


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--port", default="COM4")
    p.add_argument("--payload", default=str(DEFAULT_PAYLOAD))
    p.add_argument("--load", default="0x20010000")
    p.add_argument("--seconds", type=int, default=600)
    p.add_argument("--out", default="dump.txt")
    args = p.parse_args()

    payload = pathlib.Path(args.payload).read_bytes()
    size = 0x80 + len(payload)
    image = asr_ram_boot.build(payload, bytes(32), secure=False)

    print("payload %d bytes, image %d bytes, load %s" % (len(payload), size, args.load))
    print("stub %s" % args.payload)

    ser = serial.Serial(args.port, 115200, timeout=0.5)
    time.sleep(0.4)

    send(ser, raw_line(HANDSHAKE + b"\r\n"), 1.0)
    send(ser, raw_line(b"boot\r\n"))
    send(ser, raw_line((args.load + "\r\n").encode()))
    send(ser, raw_line(("%s\r\n" % hex(size)).encode()))
    send(ser, "read 1", 0.8)

    print("sending image in %d-byte chunks" % CHUNK)
    for off in range(0, len(image), CHUNK):
        ser.write((raw_line(image[off:off + CHUNK]) + "\r\n").encode())
        time.sleep(0.05)

    print("starting the stream")
    ser.write(("stream %d\r\n" % args.seconds).encode())

    out = pathlib.Path(args.out)
    end = time.time() + args.seconds + 60
    total = 0
    tail = bytearray()
    with out.open("w", encoding="ascii", newline="") as fh:
        while time.time() < end:
            data = ser.read(8192)
            if data:
                total += len(data)
                tail.extend(data)
                if len(tail) > 4096:
                    tail = tail[-4096:]
                fh.write(data.decode("ascii", "ignore"))
                if b"STREAM DONE" in bytes(tail) or b"DUMP END" in bytes(tail):
                    break
    ser.close()

    print("captured %d bytes to %s" % (total, out))
    if b"STREAM DONE" not in bytes(tail) and b"DUMP END" not in bytes(tail):
        print("stream did not report completion")
        return 1

    print("next: python tools/asr5601_j3_dump.py %s --out dumps/asr/j3_flash.bin "
          "--compare dumps/asr/asr_flash.bin" % out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
