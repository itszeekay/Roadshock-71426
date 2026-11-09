# Passive dual-channel 2400-baud logger for the Roadshock panel <-> base link.
#
# CircuitPython (Feather RP2040 or similar RP2040 board).
#   A = board.RX  (GP1)  - one signal wire
#   B = board.D9  (GP9)  - the other signal wire
#   GND common
#
# Listen only: TX pins are not configured, so the Feather never drives the bus.
# Connect the two Feather RX pins across the two J2 signal wires (and GND).
# Never connect the Feather 3.3 V to the vehicle/board power rail.

import board
import busio
import supervisor

BAUD = 2400
GAP_MS = 25

a = busio.UART(None, board.RX, baudrate=BAUD, timeout=0, receiver_buffer_size=2048)
b = busio.UART(None, board.D9, baudrate=BAUD, timeout=0, receiver_buffer_size=2048)

st = {
    "A": {"n": 0, "f": 0, "buf": bytearray(), "last": 0},
    "B": {"n": 0, "f": 0, "buf": bytearray(), "last": 0},
}


def emit(tag, s, t):
    if s["buf"]:
        s["f"] += 1
        print("F %d %s %s" % (t, tag, " ".join("%02x" % x for x in s["buf"])))
        s["buf"] = bytearray()


print("DUAL LISTEN READY baud=%d" % BAUD)
hb = supervisor.ticks_ms()

while True:
    now = supervisor.ticks_ms()
    for tag, u in (("A", a), ("B", b)):
        s = st[tag]
        n = u.in_waiting
        if n:
            data = u.read(n)
            if data:
                for x in data:
                    s["n"] += 1
                    if s["buf"] and (now - s["last"]) > GAP_MS:
                        emit(tag, s, s["last"])
                    s["buf"].append(x)
                    s["last"] = now
        elif s["buf"] and (now - s["last"]) > GAP_MS:
            emit(tag, s, s["last"])

    if now - hb > 5000:
        hb = now
        print("HB A=%d/%d B=%d/%d" % (st["A"]["n"], st["A"]["f"], st["B"]["n"], st["B"]["f"]))
