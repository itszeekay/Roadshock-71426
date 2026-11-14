# ASR5601S control helper for Feather RP2040 (CircuitPython).
#
# Wiring:
#   Feather TX  (GP0)  -> J3 RX
#   Feather RX  (GP1)  <- J3 TX
#   Feather D24 (GP24) -> J3 SEL0
#   Feather D25 (GP25) -> U1 pin 44 RSTN (NOT the J3 pad labelled RST)
#   GND                --  GND
#
# SEL0_AT_BOOT drives SEL0 high as soon as the script starts. That only selects
# the ROM monitor if the Feather is already running when the panel powers up,
# which means the Feather must be powered from USB, not from J3 +3.3.
# Set it to False to keep SEL0 high-Z at boot and drive it by command instead.
SEL0_AT_BOOT = False
#
# Commands on the USB console:
#   help
#   status                 show baud and SEL0 state
#   sel0 0|1               drive SEL0 low or high
#   release                SEL0 back to high-Z
#   reset                  pulse RSTN low 20 ms, then release
#   dl                     SEL0 high, pulse reset, listen 2 s
#   boot                   SEL0 low, pulse reset, listen 2 s
#   baud N                 reinit UART at N
#   read SECS              listen and print text plus hex
#   tx TEXT                send TEXT + CRLF
#   raw HH HH ...          send raw bytes
import board
import busio
import digitalio
import sys
import time

FORBIDDEN = ("erase", "burn", "boot", "write", "program")

uart = busio.UART(board.TX, board.RX, baudrate=115200, timeout=0,
                  receiver_buffer_size=4096)
BAUD = 115200

sel0 = digitalio.DigitalInOut(board.D24)
if SEL0_AT_BOOT:
    sel0.switch_to_output(value=True)
else:
    sel0.switch_to_input(pull=digitalio.Pull.DOWN)
rst = digitalio.DigitalInOut(board.D25)
rst.switch_to_input(pull=digitalio.Pull.UP)


def set_sel0(v):
    # Drive both levels hard. The strap is an input pin, so this is safe and
    # avoids relying on the internal pull-down to fight the board.
    sel0.switch_to_output(value=bool(v))


def pulse_reset():
    rst.switch_to_output(value=False)
    time.sleep(0.02)
    rst.switch_to_input(pull=digitalio.Pull.UP)


def uart_init(baud):
    global uart, BAUD
    try:
        uart.deinit()
    except Exception:
        pass
    uart = busio.UART(board.TX, board.RX, baudrate=baud, timeout=0,
                      receiver_buffer_size=4096)
    BAUD = baud


def send_text(text):
    low = text.lower()
    for bad in FORBIDDEN:
        if bad in low:
            print("REFUSED:", text)
            return
    uart.write(text.encode() + b"\r\n")
    print("TX>", text)


def show(data):
    if not data:
        print("(no data)")
        return
    printable = all(b in (9, 10, 13) or 32 <= b <= 126 for b in data)
    print("-- %d bytes" % len(data))
    if printable:
        print("TEXT:", data.decode("ascii").strip())
    print("HEX:", " ".join("%02x" % b for b in data[:400]))


def read_for(secs):
    end = time.monotonic() + secs
    data = bytearray()
    while time.monotonic() < end:
        n = uart.in_waiting
        if n:
            chunk = uart.read(n)
            if chunk:
                data.extend(chunk)
        else:
            time.sleep(0.002)
    show(bytes(data))


print("ASR MON READY baud=%d sel0=%s" % (BAUD, "high" if sel0.value else "low"))

line = ""
while True:
    c = sys.stdin.read(1)
    if not c:
        continue
    if c in ("\r", "\n"):
        cmd = line.strip()
        line = ""
        low = cmd.lower()
        if not cmd:
            continue
        if low == "help":
            print("status sel0 0|1 release reset dl boot baud N read S tx TEXT raw HH..")
        elif low == "status":
            print("baud=%d sel0=%s" % (BAUD, "high" if sel0.value else "low"))
        elif low == "release":
            sel0.switch_to_input(pull=digitalio.Pull.DOWN)
            print("sel0 released")
        elif low.startswith("sel0"):
            parts = low.split()
            if len(parts) == 2 and parts[1] in ("0", "1"):
                set_sel0(parts[1] == "1")
                print("sel0=%s" % parts[1])
            else:
                print("usage: sel0 0|1")
        elif low == "reset":
            pulse_reset()
            print("reset pulsed")
        elif low == "dl":
            set_sel0(True)
            time.sleep(0.05)
            pulse_reset()
            print("SEL0 high, reset pulsed")
            read_for(2.0)
        elif low == "boot":
            set_sel0(False)
            time.sleep(0.05)
            pulse_reset()
            print("SEL0 low, reset pulsed")
            read_for(2.0)
        elif low.startswith("baud "):
            try:
                uart_init(int(cmd[5:]))
                print("baud=%d" % BAUD)
            except Exception as e:
                print("baud error", e)
        elif low.startswith("read "):
            try:
                read_for(float(cmd[5:]))
            except Exception as e:
                print("read error", e)
        elif low.startswith("tx "):
            send_text(cmd[3:])
        elif low.startswith("raw "):
            try:
                data = bytes(int(x, 16) for x in cmd[4:].split())
                uart.write(data)
                print("TX>", " ".join("%02x" % b for b in data))
            except Exception as e:
                print("raw error", e)
        else:
            print("? try 'help'")
    else:
        line += c
