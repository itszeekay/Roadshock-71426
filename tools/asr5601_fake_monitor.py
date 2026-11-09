#!/usr/bin/env python3
"""Fake ASR560X download monitor for testing tools/asr5601_dump.py.

It listens on a TCP port and speaks the same text protocol as the ASR ROM
monitor. Point the dump tool at it with a pyserial socket URL:

    python tools/asr5601_fake_monitor.py --port 5555 --one
    python tools/asr5601_dump.py --port socket://127.0.0.1:5555 --idle 0.5 --dump /tmp/asr-test

This does not emulate the chip. It only exercises the host tool, the framing and
the parser before any hardware is connected.
"""

from __future__ import annotations

import argparse
import socketserver
import sys

BANNER = b"1F2E3D00\r\nwelcome to download\r\n>>>"
PROMPT = b"\r\n>>>"
HANDSHAKE = b"AsrIot560x "

HELP = b"get_chip_type\r\ncoredump flash all\r\n>>>"


def fake_flash() -> bytes:
    data = bytearray(b"\xff" * 64)
    data[0:4] = (0x20012000).to_bytes(4, "little")
    data[4:8] = (0x10000D59).to_bytes(4, "little")
    for i in range(8, len(data)):
        data[i] = i & 0xFF
    return bytes(data)


def chunks(image: bytes, base: int, step: int = 16):
    for offset in range(0, len(image), step):
        block = image[offset:offset + step]
        yield b":0x%08X%s$" % (base + offset, block.hex().upper().encode("ascii"))


class Handler(socketserver.BaseRequestHandler):
    def handle(self) -> None:
        print("client connected: %s" % (self.client_address,), file=sys.stderr)
        self.request.sendall(BANNER)
        buf = b""
        while True:
            data = self.request.recv(1024)
            if not data:
                break
            buf += data

            if buf.strip() == HANDSHAKE.strip():
                self.request.sendall(BANNER)
                buf = b""
                continue

            while b"\n" in buf:
                line, buf = buf.split(b"\n", 1)
                command = line.strip().decode("latin-1")
                print("RX %r" % command, file=sys.stderr)
                if command == "get_chip_type":
                    self.request.sendall(b"CT:0x5601\r\n>>>")
                elif command in ("help", "?"):
                    self.request.sendall(HELP)
                elif command == "coredump flash all":
                    for frame in chunks(fake_flash(), 0x10000000):
                        self.request.sendall(frame)
                    self.request.sendall(PROMPT)
                elif command == "":
                    self.request.sendall(PROMPT)
                else:
                    self.request.sendall(b"unknown command\r\n>>>")


class Server(socketserver.ThreadingTCPServer):
    allow_reuse_address = True
    daemon_threads = True


class OneShotServer(socketserver.TCPServer):
    allow_reuse_address = True


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=5555)
    parser.add_argument("--one", action="store_true",
                        help="serve one connection then exit")
    args = parser.parse_args(argv)

    if args.one:
        with OneShotServer((args.host, args.port), Handler) as server:
            print("listening on %s:%d" % (args.host, args.port), file=sys.stderr)
            server.handle_request()
    else:
        with Server((args.host, args.port), Handler) as server:
            print("listening on %s:%d" % (args.host, args.port), file=sys.stderr)
            server.serve_forever()
    return 0


if __name__ == "__main__":
    sys.exit(main())
