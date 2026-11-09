# Roadshock panel impersonator / interactive tester (CircuitPython)
#
# Wiring (base board side):
#   Feather GP0 (UART0 TX)  -> base PD6 "red"   (panel TX must be DISCONNECTED)
#   Feather GP1 (UART0 RX)  <- base PD5 "orange"
#   Feather GND             --  base GND  "brown"
#
# Commands over the USB serial console (COM port), one per line:
#   help
#   k1 .. k8          press+release button N (send bit, then release frame)
#   kd1 .. kd8        hold button N (send bit only, no release)
#   ku                release all (all-zero payload)
#   pwr0 / p1         master off / on (type 07, flag 0x00 / 0x01)
#   raw 08 0c 10 ...  send raw frame bytes (checksum added if omitted)
#   listen on|off     echo received base frames
#   stats
import board
import busio
import supervisor
import select
import sys
import time

BAUD = 2400
GAP_MS = 25

uart = busio.UART(board.TX, board.RX, baudrate=BAUD, timeout=0, receiver_buffer_size=2048)

seq = 0
listen = True
rx_bytes = 0
rx_frames = 0
buf = bytearray()
last = 0


def next_seq():
    global seq
    seq = (seq + 1) & 0xFF
    return seq


def send(payload_type, flag, payload6):
    """Build and send one frame: seq dir type flag p0..p5 sum."""
    body = bytes([next_seq(), 0x00, payload_type, flag]) + bytes(payload6)
    chk = sum(body) & 0xFF
    frame = body + bytes([chk])
    uart.write(frame)
    print("TX " + " ".join("%02x" % b for b in frame))
    time.sleep(0.06)   # let the frame drain at 2400 baud


def key_bit(n):
    """Button n (1..8) -> (byte index, mask)."""
    idx = (n - 1) // 2
    mask = 0x10 if (n % 2 == 1) else 0x01
    return idx, mask


def send_keys(mask_bytes):
    send(0x08, 0x0C, mask_bytes)


def key_down(n):
    idx, mask = key_bit(n)
    p = bytearray(6)
    p[idx] = mask
    send_keys(p)
    return p


def release_all():
    send_keys(bytes(6))


def poll_rx():
    global buf, last, rx_bytes, rx_frames
    now = supervisor.ticks_ms()
    n = uart.in_waiting
    if n:
        data = uart.read(n)
        if data:
            for b in data:
                rx_bytes += 1
                if buf and (now - last) > GAP_MS:
                    if listen:
                        print("RX " + " ".join("%02x" % x for x in buf))
                    rx_frames += 1
                    buf = bytearray()
                buf.append(b)
                last = now
    elif buf and (now - last) > GAP_MS:
        if listen:
            print("RX " + " ".join("%02x" % x for x in buf))
        rx_frames += 1
        buf = bytearray()


print("IMPERSONATOR READY baud=%d" % BAUD)
print("type 'help' for commands")

poll = select.poll()
poll.register(sys.stdin, select.POLLIN)

line = ""
while True:
    poll_rx()
    if poll.poll(0):
        c = sys.stdin.read(1)
        if c:
            if c in ("\r", "\n"):
                cmd = line.strip().lower()
                line = ""
                if not cmd:
                    pass
                elif cmd == "help":
                    print("k1..k8 kd1..kd8 ku pwr0 pwr1 raw <hex> listen on|off stats")
                elif cmd == "stats":
                    print("seq=%d rx_bytes=%d rx_frames=%d" % (seq, rx_bytes, rx_frames))
                elif cmd == "ku":
                    release_all()
                elif cmd in ("pwr0", "p1"):
                    send(0x07, 0x00 if cmd == "pwr0" else 0x01, bytes(6))
                elif cmd.startswith("listen"):
                    listen = cmd.endswith("on")
                    print("listen", listen)
                elif cmd.startswith("raw"):
                    try:
                        parts = [int(x, 16) for x in cmd.split()[1:]]
                    except ValueError:
                        print("bad hex")
                        parts = []
                    if len(parts) >= 4:
                        if len(parts) >= 5 and (sum(parts[:-1]) & 0xFF) == parts[-1]:
                            body = bytes(parts)          # checksum already correct
                        else:
                            body = bytes(parts) + bytes([sum(parts) & 0xFF])
                        uart.write(body)
                        print("TX " + " ".join("%02x" % b for b in body))
                elif cmd.startswith("kd") and cmd[2:].isdigit():
                    n = int(cmd[2:])
                    if 1 <= n <= 8:
                        key_down(n)
                elif cmd.startswith("k") and cmd[1:].isdigit():
                    n = int(cmd[1:])
                    if 1 <= n <= 8:
                        key_down(n)
                        time.sleep(0.15)
                        release_all()
                else:
                    print("? try 'help'")
            else:
                line += c
