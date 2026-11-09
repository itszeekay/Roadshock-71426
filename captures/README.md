# Captures

Real bus captures from the panel ↔ base link, 2400 8N1.

| File | Contents |
|---|---|
| `button_map.txt` | clean press/release capture used to confirm the button bitmask |
| `first_capture.txt` | early capture showing `08 0C`, `07`, and the replies |
| `panel_base_live.txt` | live dual-channel capture (`F <ms> A/B <bytes>`) |

## `F` format

`rp2040/dual_listen.py` prints:

```
F <ms> A 00 ff 18 00 10 00 00 00 00 00 27
F <ms> B 00 00 08 0c 10 00 00 00 00 00 24
```

- `A` = `board.RX` (GP1)
- `B` = `board.D9` (GP9)

In the reference setup, `B` carried panel→base requests (`dir 0x00`) and `A`
carried base→panel replies (`dir 0xFF`). Use the `dir` byte, not the channel
letter, to identify direction.

## `FRAME` format

Some early captures use:

```
FRAME A len=11 19 ff 18 00 ...
```

`tools/parse_tap.py` understands that format.
