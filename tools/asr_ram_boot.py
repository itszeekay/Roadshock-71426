#!/usr/bin/env python3
"""Build and send an ASR5601S RAM boot image over J3.

The ROM monitor `boot` command takes an address and a size, then receives a
header plus payload. The verifier:

  - compares the header start to "ASR SONATA BLE DL NON"
  - expects payload length at 0x20
  - RC4 decrypts the payload with the key at 0x30
  - compares CRC32 of the decrypted payload with the word at 0x4C

After verification the ROM sets VTOR to the image base, disables interrupts and
calls the word at base + 4. The payload therefore starts with a vector table:
[0] stack pointer, [4] entry point.

    python tools/asr_ram_boot.py --hexfile image.hex
"""
import argparse
import pathlib
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


# Payload: vector table, then a stub that writes a marker to RAM and resets.
# 0x00 SP 0x20015000
# 0x04 entry 0x20010009 (thumb)
# 0x08 ldr r0,=0x20000100 ; ldr r1,=0xDEADBEEF ; str r1,[r0]
# 0x0E ldr r0,=0xE000ED0C ; ldr r1,=0x05FA0004 ; str r1,[r0] ; b .
# 0x18 literals
MARKER_STUB = bytes.fromhex(
    "00500120"
    "09000120"
    "0348"
    "0449"
    "0160"
    "0448"
    "0449"
    "0160"
    "fee7"
    "00bf"
    "00010020"
    "efbeadde"
    "0ced00e0"
    "0400fa05"
)


def build(stub: bytes, key: bytes, secure: bool = False) -> bytes:
    header = bytearray(HEADER_LEN)
    header[0:len(MAGIC)] = MAGIC
    struct.pack_into("<I", header, 0x20, len(stub))

    if secure:
        header[0:len(MAGIC)] = b"ASR SONATA BLE DL SEC"
        digest = crc32_msb(stub)
        header[0x30:0x50] = key
        struct.pack_into("<I", header, 0x4C, digest)
        return bytes(header) + rc4(key, stub)

    # Non-secure: payload is taken as-is, no decryption and no digest check.
    return bytes(header) + stub


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--key", default="00112233445566778899aabbccddeeff"
                                     "00112233445566778899aabbccddeeff")
    p.add_argument("--secure", action="store_true", help="use the DL SEC path with RC4 and CRC32")
    p.add_argument("--payload", default=None, help="raw payload binary instead of the built-in marker stub")
    p.add_argument("--hexfile", default=None)
    args = p.parse_args()

    key = bytes.fromhex(args.key)
    payload = MARKER_STUB
    if args.payload:
        payload = pathlib.Path(args.payload).read_bytes()
    img = build(payload, key, args.secure)

    print("payload %d bytes" % len(payload))
    print("total   %d bytes" % len(img))
    print("crc32   0x%08X" % crc32_msb(payload))
    print("stub    %s" % payload.hex())
    print("image   %s" % img.hex())

    if args.hexfile:
        with open(args.hexfile, "w", encoding="ascii") as fh:
            fh.write(img.hex())


if __name__ == "__main__":
    main()
