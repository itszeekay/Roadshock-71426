#!/usr/bin/env python3
"""Parse the serial tap log: pair panel requests with base responses by seq,
verify the additive checksum, and print the payload history."""
import re
import sys
from collections import OrderedDict

LINE = re.compile(r"FRAME ([AB]) len=(\d+) ((?:[0-9a-f]{2} ?)+)")

frames = []
for line in open(sys.argv[1] if len(sys.argv) > 1 else "captures/first_capture.txt"):
    m = LINE.search(line)
    if not m:
        continue
    ch = m.group(1)
    data = bytes(int(x, 16) for x in m.group(3).split())
    frames.append((ch, data))

print("total frames:", len(frames))

# merge split frames: same channel, previous ended recently -> concatenate
merged = []
for ch, d in frames:
    if merged and merged[-1][0] == ch and len(merged[-1][1]) < 11 and len(merged[-1][1]) + len(d) <= 12:
        merged[-1] = (ch, merged[-1][1] + d)
    else:
        merged.append((ch, d))

print("after merge:", len(merged))


def csum(d):
    return sum(d[:-1]) & 0xFF


good = [d for _, d in merged if len(d) >= 2 and csum(d) == d[-1]]
print("checksum-valid frames:", len(good), "of", len(merged))

pairs = OrderedDict()
for ch, d in merged:
    if len(d) < 2:
        continue
    seq = d[0]
    pairs.setdefault(seq, {})[ch] = d

print("\nseq | panel -> base (B)                          | base -> panel (A)")
print("-" * 100)
for seq, v in pairs.items():
    b = v.get("B", b"").hex(" ")
    a = v.get("A", b"").hex(" ")
    print("%3d | %-42s | %-42s" % (seq, b, a))

print("\nunique B payloads (bytes 3..8):")
seen = OrderedDict()
for seq, v in pairs.items():
    d = v.get("B")
    if d and len(d) >= 9:
        key = d[3:9].hex(" ")
        seen[key] = seen.get(key, 0) + 1
for k, n in seen.items():
    print("  %s  x%d" % (k, n))
