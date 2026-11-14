#!/usr/bin/env python3
"""Run a J3-only ASR5601S flash dump through the Feather helper.

Prerequisites:

  - the Feather runs rp2040/asr_mon.py
  - the panel is powered with SEL0 high, so the ROM monitor is running
  - the Feather UART is wired to J3 TX/RX/GND at 115200

The tool sends the dump stub over the monitor `boot` command, tells the Feather
to capture, and waits for the capture to finish. Copy the capture file from the
CIRCUITPY drive, then rebuild the image with tools/asr5601_j3_dump.py.

    python tools/asr5601_j3_capture.py --port COM4 --seconds 600
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


def raw_line(data: bytes) -> str:
    return "raw " + " ".join("%02x" % b for b in data)


def send(ser, text: str, wait: float = 0.5) -> bytes:
    ser.reset_input_buffer()
    ser.write((text + "\r\n").encode())
    time.sleep(wait)
    return ser.read(8192)


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--port", default="COM4")
    p.add_argument("--payload", default=str(DEFAULT_PAYLOAD))
    p.add_argument("--load", default="0x20010000")
    p.add_argument("--seconds", type=int, default=600)
    p.add_argument("--feather-path", default="/dump.txt")
    p.add_argument("--drive", help="CIRCUITPY drive letter to copy the capture from, for example D:")
    p.add_argument("--out", default="dump.txt", help="local capture file")
    args = p.parse_args()

    payload = pathlib.Path(args.payload).read_bytes()
    size = 0x80 + len(payload)
    image = asr_ram_boot.build(payload, bytes(32), secure=False)

    print("payload %d bytes, image %d bytes, load %s" % (len(payload), size, args.load))

    ser = serial.Serial(args.port, 115200, timeout=0.5)
    time.sleep(0.4)

    send(ser, raw_line(HANDSHAKE + b"\r\n"), 1.0)
    send(ser, raw_line(b"boot\r\n"), 0.4)
    send(ser, raw_line((args.load + "\r\n").encode()), 0.4)
    send(ser, raw_line(("%s\r\n" % hex(size)).encode()), 0.4)
    send(ser, "read 1", 0.8)

    print("sending image and starting the capture")
    ser.reset_input_buffer()
    ser.write((raw_line(image) + "\r\n").encode())
    ser.write(("capture %d %s\r\n" % (args.seconds, args.feather_path)).encode())

    end = time.time() + args.seconds + 60
    buf = bytearray()
    done = False
    while time.time() < end:
        data = ser.read(4096)
        if data:
            buf.extend(data)
            if b"captured" in bytes(buf[-300:]):
                done = True
                break
    ser.close()

    if not done:
        print("capture did not report completion; check the Feather console")
        return 1

    print(bytes(buf[-300:]).decode("utf-8", "replace").strip())

    if args.drive:
        src = pathlib.Path(args.drive.rstrip("\\/") + args.feather_path)
        dst = pathlib.Path(args.out)
        for _ in range(20):
            if src.is_file():
                dst.write_bytes(src.read_bytes())
                print("copied %s to %s" % (src, dst))
                break
            time.sleep(0.5)
        else:
            print("capture file not found at %s" % src)
            return 1

    print("next: python tools/asr5601_j3_dump.py %s --out dumps/asr/j3_flash.bin --compare dumps/asr/asr_flash.bin" % args.out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
