#!/usr/bin/env python3
"""Roadshock panel-link protocol reference implementation.

Frame (11 bytes, both directions):

    seq  dir  type  flag  p0 p1 p2 p3 p4 p5  sum

    dir  = 0x00 panel->base, 0xFF base->panel
    type = request type; reply carries type | 0x10
    sum  = sum(frame[:-1]) & 0xFF

Message types seen:
    0x07  master/parameter: flag 0x00 = off, 0x01 = on, other flags accepted
    0x08  button bitmask (flag 0x0C)
    0x0B, 0x0D, 0x19  accepted by the dispatcher, not used by the panel
"""
from dataclasses import dataclass


def checksum(data: bytes) -> int:
    return sum(data) & 0xFF


def build(seq, type_, flag, payload6, direction=0x00):
    payload = bytes(payload6)
    if len(payload) != 6:
        raise ValueError("payload must be 6 bytes")
    body = bytes([seq & 0xFF, 0x00 if direction == 0 else 0xFF,
                  type_ & 0xFF, flag & 0xFF]) + payload
    return body + bytes([checksum(body)])


@dataclass
class Frame:
    seq: int
    direction: int
    type: int
    flag: int
    payload: bytes
    sum_ok: bool

    @property
    def is_reply(self) -> bool:
        return self.direction == 0xFF

    def __str__(self):
        return ("seq=%02x dir=%02x type=%02x flag=%02x payload=%s sum=%s"
                % (self.seq, self.direction, self.type, self.flag,
                   self.payload.hex(" "), "ok" if self.sum_ok else "BAD"))


def parse(buf: bytes) -> Frame:
    if len(buf) < 4:
        raise ValueError("short frame")
    return Frame(buf[0], buf[1], buf[2], buf[3], bytes(buf[4:-1]),
                 checksum(buf[:-1]) == buf[-1])


# ---- semantic helpers -------------------------------------------------------
def key_press(seq, button: int) -> bytes:
    """Button 1..8 -> bitmask frame (press)."""
    if not 1 <= button <= 8:
        raise ValueError("button 1..8")
    idx = (button - 1) // 2
    mask = 0x10 if button % 2 == 1 else 0x01
    payload = bytearray(6)
    payload[idx] = mask
    return build(seq, 0x08, 0x0C, payload)


def key_release(seq) -> bytes:
    return build(seq, 0x08, 0x0C, bytes(6))


def power(seq, on: bool) -> bytes:
    return build(seq, 0x07, 0x01 if on else 0x00, bytes(6))


def build_reply(req) -> bytes:
    """Model the stock base-board reply: dir 0xFF, type|0x10.

    Type 0x07 replies are 12 bytes (an extra 0x00 status byte before the
    payload); every other type replies with the plain 11-byte frame.
    """
    t = req.type | 0x10
    if req.type == 0x07:
        body = bytes([req.seq, 0xFF, t, 0x00, req.flag]) + req.payload
    else:
        body = bytes([req.seq, 0xFF, t, 0x00]) + req.payload
    return body + bytes([checksum(body)])


def set_output(seq, channel: int, mode: int, duty: int = 0, hz: int = 1000) -> bytes:
    """Custom type 0x09: configure one output.

    mode: 0 = off, 1 = steady on, 2 = PWM (duty 0..100, hz 50..2000)
    """
    payload = bytes([channel & 0xFF, mode & 0xFF, duty & 0xFF,
                     hz & 0xFF, (hz >> 8) & 0xFF, 0])
    return build(seq, 0x09, 0x00, payload)


def key_of_payload(payload: bytes):
    """Return the button numbers held in a key payload."""
    buttons = []
    for idx, b in enumerate(payload):
        if b & 0x10:
            buttons.append(idx * 2 + 1)
        if b & 0x01:
            buttons.append(idx * 2 + 2)
    return buttons


if __name__ == "__main__":
    # self-test against frames captured from the real panel
    for raw_hex in (
        "19 00 08 0c 62 40 20 02 00 00 f1",
        "19 ff 18 00 62 40 20 02 00 00 f4",
        "41 00 07 00 00 00 00 00 00 00 48",
        "42 00 07 01 00 00 00 00 00 00 4a",
    ):
        f = parse(bytes(int(x, 16) for x in raw_hex.split()))
        assert f.sum_ok, raw_hex
        print(f)

    # reply-model check against real captured pairs
    pairs = [
        ("19 00 08 0c 62 40 20 02 00 00 f1", "19 ff 18 00 62 40 20 02 00 00 f4"),
        ("41 00 07 00 00 00 00 00 00 00 48", "41 ff 17 00 00 00 00 00 00 00 00 57"),
        ("42 00 07 01 00 00 00 00 00 00 4a", "42 ff 17 00 01 00 00 00 00 00 00 59"),
    ]
    for req_hex, exp_hex in pairs:
        req = parse(bytes(int(x, 16) for x in req_hex.split()))
        got = build_reply(req).hex(" ")
        assert got == exp_hex, (got, exp_hex)
    print("reply model matches all captured pairs")

    for n in range(1, 9):
        fr = key_press(0x30 + n, n)
        assert fr[3] == 0x0C and checksum(fr[:-1]) == fr[-1]
    print("key frames ok, e.g. button 6:", key_press(0x40, 6).hex(" "))
    print("release all:", key_release(0x41).hex(" "))
    print("power on:", power(0x42, True).hex(" "))
