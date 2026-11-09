# Base emulator / panel test rig (CircuitPython, RP2040).
#
# Purpose: run the button panel without the stock base board, so its display
# and buttons can be exercised on the bench.
#
# Wiring:
#   Feather TX (GP0) -> panel RX (the line the base normally drives)
#   Feather RX (GP1) <- panel TX (the line the panel drives)
#   GND common
#
# The stock base replies to every panel frame:
#   panel 08 0C <bits>       -> base 18 00 <same bits>
#   panel 07 <flag> ...      -> base 17 00 <flag> ... (12 bytes)
#
# The stock base also sends one unsolicited 0x1B frame during its init:
#   00 FF 1B 02 00 00 00 00 00 00 1C
# This is sent periodically here for a short window because the panel may only
# look for it around its own boot.

import board
import busio
import supervisor
import time

BAUD = 2400
GAP_MS = 25

u = busio.UART(board.TX, board.RX, baudrate=BAUD, timeout=0, receiver_buffer_size=2048)
buf = bytearray()
last = 0


def show(tag, b):
    print(tag, " ".join("%02x" % x for x in b))


def frame(seq, typ, flag, p=b"\x00" * 6):
    body = bytes([seq, 0xFF, typ, flag]) + p
    return body + bytes([sum(body) & 0xFF])


def reply(fr):
    if len(fr) != 11 or fr[1] != 0x00:
        return
    seq, typ, flag = fr[0], fr[2], fr[3]
    p = bytes(fr[4:10])
    if typ == 0x07:
        body = bytes([seq, 0xFF, 0x17, 0x00, flag]) + p
    else:
        body = bytes([seq, 0xFF, typ | 0x10, 0x00]) + p
    out = body + bytes([sum(body) & 0xFF])
    u.write(out)
    show("TX", out)


print("BASE EMU READY")
start = supervisor.ticks_ms()
init_until = start + 30000
next_init = start
ninit = 0

while True:
    now = supervisor.ticks_ms()
    if now < init_until and now >= next_init:
        fl = 0x02 if (ninit % 2 == 0) else 0x00
        f = frame(0, 0x1B, fl)
        u.write(f)
        show("TX", f)
        ninit += 1
        next_init = now + 400

    n = u.in_waiting
    if n:
        d = u.read(n)
        if d:
            for x in d:
                if buf and (now - last) > GAP_MS:
                    show("RX", buf)
                    reply(buf)
                    buf = bytearray()
                buf.append(x)
                last = now
    elif buf and (now - last) > GAP_MS:
        show("RX", buf)
        reply(buf)
        buf = bytearray()
