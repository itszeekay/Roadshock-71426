# Roadshock base board - custom firmware
# Target: STM8S003F3P6 (8 KB flash, 1 KB RAM)
#
# Requires SDCC with the stm8 backend (sdcc -mstm8).
#   make            -> build/roadshock.ihx
#   make flash      -> program the application image
#   make flash-full -> program the prebuilt full 8 KB image

CC      ?= sdcc
AS      ?= sdasstm8
CFLAGS  ?= -mstm8 --std-sdcc99 -I src
LDFLAGS ?= -mstm8 --out-fmt-ihx

SRC     := src/main.c src/board.c src/protocol.c
OBJ     := $(SRC:src/%.c=build/%.rel)
TARGET  := build/roadshock.ihx

TESTSRC := src/main.c src/board.c src/protocol.c src/test_pattern.c
TESTOBJ := $(TESTSRC:src/%.c=build/test_%.rel)
TESTTARGET := build/testpattern.ihx

all: $(TARGET)

build:
	@mkdir -p build

build/%.rel: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build/test_%.rel: src/%.c | build
	$(CC) $(CFLAGS) -DTEST_PATTERN -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@
	@echo "built $@"

$(TESTTARGET): $(TESTOBJ)
	$(CC) $(LDFLAGS) $(TESTOBJ) -o $@
	@echo "built $@"

testpattern: $(TESTTARGET)

flash: $(TARGET)
	stm8flash -c stlinkv2 -p stm8s003f3 -w $(TARGET)

flash-full:
	stm8flash -c stlinkv2 -p stm8s003f3 -w prebuilt/roadshock_full.ihx

clean:
	rm -rf build

.PHONY: all flash flash-full clean
