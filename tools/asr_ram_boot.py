#!/usr/bin/env python3
"""Build and send an ASR5601S RAM boot image over J3.

The ROM monitor `boot` command takes an address and a size, then receives a
header plus payload. The verifier:

  - compares the header start to "ASR SONATA BLE DL NON"
  - expects payload length at 0x20
  - RC4 decrypts the payload with the key at 0x30
  - compares CRC32 of the decrypted payload with the word at 0x4C

This tool builds such an image for a small Thumb stub and prints the bytes.

    python tools/asr_ram_boot.py --stub marker
"""
import argparse
import struct

MAGIC = b"ASR SONATA BLE DL NON"
HEADER_LEN = 0x80


def crc32_msb(data: bytes) -> int:
    crc = 0xFFFFFFFF
    for b in data:
        crc ^= b << 24
        for _ in range(8):
            if crc & 0x80000000:
                crc = ((crc << 1) & 0xFFFFFFFF) ^ 0x04C11DB7
            else:
                crc = (crc << 1) & 0xFFFFFFFF
    return crc


def rc4(key: bytes, data: bytes) -> bytes:
    s = list(range(256))
    j = 0
    for i in range(256):
        j = (j + s[i] + key[i % len(key)]) & 0xFF
        s[i], s[j] = s[j], s[i]
    out = bytearray()
    i = j = 0
    for b in data:
        i = (i + 1) & 0xFF
        j = (j + s[i]) & 0xFF
        s[i], s[j] = s[j], s[i]
        out.append(b ^ s[(s[i] + s[j]) & 0xFF])
    return bytes(out)


# Thumb stub: write a marker to RAM, then SYSRESETREQ back into the monitor.
# ldr r0,lit; ldr r1,lit; str r1,[r0]; ldr r0,lit; ldr r1,lit; str r1,[r0]; b .
MARKER_STUB = bytes.fromhex(
    "0c48"      # ldr r0, [pc, #0x0c]
    "1049"      # ldr r1, [pc, #0x10]
    "0160"      # str r1, [r0]
    "1048"      # ldr r0, [pc, #0x10]
    "1049"      # ldr r1, [pc, #0x10]
    "0160"      # str r1, [r0]
    "fee7"      # b .
    "00bf"      # nop
    "00010020"  # 0x20000100
    "efbeadde"  # 0xDEADBEEF
    "0ced00e0"  # 0xE000ED0C AIRCR
    "0400fa05"  # 0x05FA0004 VECTKEY | SYSRESETREQ
)


def build(stub: bytes, load: int, key: bytes) -> bytes:
    header = bytearray(HEADER_LEN)
    header[0:len(MAGIC)] = MAGIC
    struct.pack_into("<I", header, 0x20, len(stub))

    digest = crc32_msb(stub)
    header[0x30:0x50] = key
    struct.pack_into("<I", header, 0x4C, digest)

    return bytes(header) + rc4(key, stub)


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--load", default="0x20010000")
    p.add_argument("--key", default="00112233445566778899aabbccddeeff"
                                     "00112233445566778899aabbccddeeff")
    p.add_argument("--stub", choices=["marker"], default="marker")
    p.add_argument("--hexfile", default=None)
    args = p.parse_args()

    stub = MARKER_STUB
    key = bytes.fromhex(args.key)
    img = build(stub, int(args.load, 0), key)

    print("load    %s" % args.load)
    print("payload %d bytes" % len(stub))
    print("total   %d bytes" % len(img))
    print("crc32   0x%08X" % crc32_msb(stub))
    print("stub    %s" % stub.hex())
    print("image   %s" % img.hex())

    if args.hexfile:
        with open(args.hexfile, "w", encoding="ascii") as fh:
            fh.write(img.hex())


if __name__ == "__main__":
    main()
