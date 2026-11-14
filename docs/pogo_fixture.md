# Pogo Fixture Design

A pogo fixture lets you flash the base board without removing the lid or
peeling the potting every time. The base board SWIM header (no designator) is
under factory silicone. The fixture pokes through the potting and lands on
the four SWIM pads.

## Why

- Flashing requires a reliable SWIM connection.
- The potting is in the way; hand peeling is slow and risky.
- The fixture gives repeatable contact without damaging the pads.

## Constraints

| Constraint | Value | Source |
|---|---|---|
| Base board SWIM pad pitch | **not yet measured** | To be measured on a known-good unit |
| J3 (panel ASR UART) pad pitch | ~1.27 mm | `asr5601_dump.md` |
| Base board SWIM pad count | 4 (V+, GND, SWIM, RST) | `pinouts.md` |
| Button panel not potted | Yes | `hardware.md` |
| Base board potted with silicone | Yes | `hardware.md` |
| ST-Link 3.3 V must be disconnected | Yes | `reproduce.md` |
| 12 V off during flashing | Yes | `reproduce.md` |

## Fixture requirements

The fixture must:

1. Hold the four pogo pins in alignment with the base board SWIM pads.
2. Apply enough pressure to make reliable contact through the potting.
3. Not damage the SWIM pads or the potting when removed.
4. Be removable without tools.
5. Keep the ST-Link 3.3 V isolated from the SWIM V+ pad.

## Design

```
          +-----------------------------------+
          |      Base board (lid off)         |
          |  [SWIM header pads under pot]     |
          |        +---+---+---+---+          |
          |        |V+ |GND|SWIM|RST|         |
          +-----------------------------------+
                          ^      ^      ^      ^
                          |      |      |      |
                    +-----+------+------+-+
                    |  Fixture (pegs/pogo)
                    |  (4 pogo pins, spring-loaded)
                    +-----+------+------+-+
                          |      |      |      |
                          +------+------+-+
                                 |
                         [ST-Link VCC GND SWIM RST]
                         (3.3V disconnected)
```

### Pogo pins

- **Pitch**: match the base board SWIM header pitch (to be measured). If
  the pitch is 1.27 mm (0.05 in), use 1.27 mm-pitch pogo pins.
- **Pin length**: 3-5 mm, enough to pass through the potting and land on
  the pad. The potting thickness is unknown; measure on your unit.
- **Spring force**: 20-50 g per pin, enough to pierce the potting and
  make contact without bending the pads.
- **Contact tip**: 0.5-1 mm flat or conical, to distribute pressure.

### Housing

A 3D-printed or machined block with four holes (one per pogo pin) aligned
to the SWIM pad positions. The block sits on top of the base board, covering
the lid area. The ST-Link wires exit from the bottom.

### Wire connections

| ST-Link | Pogo pin | SWIM pad |
|---|---|---|
| VCC (3.3 V) | **Do not connect** | - |
| GND | GND pad | `GND` |
| SWIM | SWIM pad | `SWIM` |
| RST | RST pad | `RST` |
| VCC (3.3 V) | - | `V+` (connect separately, 12 V or 5 V) |

The V+ pad needs power from the 12 V supply (or 5 V for bench). The
ST-Link's 3.3 V VCC must **not** be connected to V+; power the board
externally and disconnect the ST-Link 3.3 V pin.

## Measurement procedure

Before building the fixture, measure the base board SWIM header pad pitch:

1. Peel the potting on a spare or test unit (or on the unit you plan to
   flash).
2. Use a digital caliper (0.01 mm) to measure the distance between the
   centers of adjacent SWIM pads.
3. Record the pitch. If it matches ~1.27 mm, the J3 reference holds and a
   1.27 mm pogo block can be used. If different, order custom pogo pins
   at the measured pitch.
4. Measure the potting thickness over the SWIM header. This determines
   the pogo pin length and housing height.

## Testing

1. Build or assemble the fixture.
2. Verify each pogo pin contacts the correct SWIM pad using a multimeter
   in continuity mode. The fixture should be off the board or the board
   should be unpowered.
3. With the board powered (12 V, no panel), verify V+ pad reads 12 V.
4. Connect the ST-Link (3.3 V disconnected) via the fixture pins.
5. Run `stm8flash -c stlinkv2 -p stm8s003f3 -s flash -r test.bin` to
   verify the connection.
6. If the connection is flaky, adjust pogo pin length or spring force.

## Parts list

| Item | Qty | Notes |
|---|---:|---|
| 1.27 mm-pitch pogo pins (3-5 mm) | 4 | Buy in bulk; 1.27 mm pitch is standard |
| ST-Link V2 | 1 | Already owned |
| 12 V bench supply | 1 | 500 mA minimum |
| Digital caliper | 1 | For measuring pitch and potting thickness |
| 3D-printed housing (or machined block) | 1 | Four holes, aligned to pad positions |
| Heat shrink or insulating tubing | 1 | Around the ST-Link connector if needed |
| ST-Link breakout or header pins | 4 | To wire the four ST-Link lines to pogo pins |

## Future work

- Measure the base board SWIM pad pitch and document it in `pinouts.md`.
- If the pitch matches 1.27 mm, share the pogo block with J3 (panel ASR
  UART) for a dual-purpose fixture.
- If the pitch does not match, consider a custom pogo block or a test
  jig that pogo-pins the base board only.
- Document the pogo fixture in `reproduce.md` as an alternative to hand
  peeling.
