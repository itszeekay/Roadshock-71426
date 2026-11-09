/*
 * Roadshock 8-Gang switch panel - button panel firmware
 * STM8S003K3, 8 KB flash @ 0x8000, 1 KB RAM
 *
 * Reconstructed from the dump (sha256
 * 00ea5024bf5dbdf62edcb86bc1158b5ec1f22a7c82eef7e60a5bd2ab26565fe3)
 * with Ghidra 11.3.1 + STM8 SLEIGH (STM8:BE:16, base 0x8000),
 * project Roadstm8Panel. 147/147 functions decompiled.
 *
 * This is decompiler output, not original source. Types are
 * approximate. Reading order: the function index first, then each
 * function in address order. Names marked here
 * (display_frame_handler, pin1_set_low/high, pin2_set_high,
 * get_pin1/2/3, pin_clear, pin_set, led_gpio_init, gpio_init,
 * uart1_configure) were assigned from call sites and confirmed
 * against assembly; see tools/ghidra/build_panel_project.py and
 * docs/panel_led_map.md. Generic names (sub_*, FUN_*, gap_*, vec_*)
 * are Ghidra defaults for code that has not been given a role yet.
 *
 * The display link runs at 115200 (9-byte 0x5A...0xEE frames).
 * The 24-record pin table is at flash 0x8AB4 (RAM 0x0010).
 * Ghidra 11.3.1 decompilation is the source of truth; cross-check
 * against asm/panel.lst. LEDs are active-low (common-anode).
 */

/* ---- function index -------------------------------
 *  addr  name
 *  8000  VEC00_RESET
 *  8018  VEC06_EXTI1
 *  801C  VEC07_EXTI2
 *  8080  uart1_param_check
 *  816D  x_816d
 *  8237  sub_8237
 *  8252  mul_wide
 *  82DC  sub_82dc
 *  82E1  sub_82e1
 *  82E4  sub_82e4
 *  8351  sub_8351
 *  8362  sub_8362
 *  8367  sub_8367
 *  836C  FUN_836c
 *  837F  sub_837f
 *  838E  sub_838e
 *  8393  sub_8393
 *  8398  sub_8398
 *  839D  sub_839d
 *  83A2  FUN_83a2
 *  83BF  sub_83bf
 *  83CA  sub_83ca
 *  83D5  sub_83d5
 *  83E0  sub_83e0
 *  83EB  FUN_83eb
 *  83F3  sub_83f3
 *  83F6  sub_83f6
 *  83FA  sub_83fa
 *  83FE  sub_83fe
 *  840B  sub_840b
 *  8418  sub_8418
 *  8425  sub_8425
 *  8432  sub_8432
 *  843F  sub_843f
 *  844C  display_frame_handler
 *  8508  sub_8508
 *  8510  gpio_init
 *  85C1  sub_85c1
 *  8841  x_8841
 *  896D  panel_main_loop
 *  89EF  sub_89ef
 *  8A52  sub_8a52
 *  8AB4  led_pin_table_flash
 *  8AC3  ret_8ac3
 *  8AF0  ret_8af0
 *  8B0C  vec_8b0c
 *  8B62  sub_8b62
 *  8B72  sub_8b72
 *  8B7E  sub_8b7e
 *  8B8A  sub_8b8a
 *  8BA9  sub_8ba9
 *  8BE4  sub_8be4
 *  8C1E  sub_8c1e
 *  8C31  x_8c31
 *  8C52  led_gpio_init
 *  8C81  sub_8c81
 *  8CAC  sub_8cac
 *  8CD6  sub_8cd6
 *  8D26  uart1_init_115200
 *  8D4D  vec_8d4d
 *  8D74  sub_8d74
 *  8D81  sub_8d81
 *  8D8E  sub_8d8e
 *  8DA3  sub_8da3
 *  8DBD  sub_8dbd
 *  8DD6  sub_8dd6
 *  8DEF  sub_8def
 *  8E05  sub_8e05
 *  8E1B  sub_8e1b
 *  8E2F  sub_8e2f
 *  8E43  vec_8e43
 *  8E56  sub_8e56
 *  8E65  sub_8e65
 *  8E72  get_pin3
 *  8E7F  get_pin2
 *  8E8C  sub_8e8c
 *  8E99  sub_8e99
 *  8EA1  sub_8ea1
 *  8EA6  sub_8ea6
 *  8EB1  sub_8eb1
 *  8EBC  sub_8ebc
 *  8EC7  sub_8ec7
 *  8ED2  sub_8ed2
 *  8EDD  sub_8edd
 *  8EE8  sub_8ee8
 *  8EF3  sub_8ef3
 *  8EFD  get_pin1
 *  8F06  sub_8f06
 *  8F0F  sub_8f0f
 *  8F18  sub_8f18
 *  8F21  sub_8f21
 *  8F29  sub_8f29
 *  8F31  sub_8f31
 *  8F38  pin1_set_low
 *  8F3E  pin2_set_high
 *  8F44  pin1_set_high
 *  8F4A  sub_8f4a
 *  8F50  FUN_8f50
 *  8F59  sub_8f59
 *  8F5D  sub_8f5d
 *  8F61  sub_8f61
 *  8F65  pin_clear
 *  8F68  pin_set
 *  8F6B  sub_8f6b
 *  8F6E  thunk_FUN_8f77
 *  8F71  sub_8f71
 *  8F74  thunk_FUN_8f50
 *  8F77  FUN_8f77
 *  8F7A  sub_8f7a
 *  8F7C  vec_8f7c
 *  8F7D  vec_8f7d
 *  8F7E  vec_8f7e
 *  8F7F  vec_8f7f
 *  8F80  vec_8f80
 *  8F81  vec_8f81
 *  8F82  vec_8f82
 *  8F83  vec_8f83
 *  8F84  vec_8f84
 *  8F85  vec_8f85
 *  8F86  vec_8f86
 *  8F87  vec_8f87
 *  8F88  vec_8f88
 *  8F89  vec_8f89
 *  8F8A  vec_8f8a
 *  8F8B  vec_8f8b
 *  8F8C  vec_8f8c
 *  8F8D  vec_8f8d
 *  8F8E  sub_8f8e
 *  8F8F  gap_8f8f
 *  8FA0  gap_8fa0
 *  8FA9  uart1_configure
 *  8FB5  x_8fb5
 *  8FBA  gap_8fba
 *  8FCB  gap_8fcb
 *  8FDC  gap_8fdc
 *  8FED  gap_8fed
 *  8FFE  gap_8ffe
 *  908A  x_908a
 *  9510  x_9510
 *  95DE  x_95de
 *  9780  uart1_set_control_bits
 *  97D3  x_97d3
 *  9824  x_9824
 *  9BCF  x_9bcf
 *  9C31  x_9c31
 *  9C5B  x_9c5b
 *  9CD8  reset_startup
 */

// FUNC 0x8000  VEC00_RESET

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* STM8S003 vector area: 32 x 4-byte entries (0x8000-0x807F).
   Entry format: 82 00 <handler_hi> <handler_lo>.
   Parsed: 00=0x9C82 05=0x99E1 15=0x9223 19=0x96CB 20=0x97D3 25=0x9608
   OPEN: reset entry parses to 0x9C82 but real startup (SP init) is 0x9CD8
   and does not appear in this area - unconfirmed until checked on hardware. */

void VEC00_RESET(void)

{
  short sVar1;
  
  _DAT_03fe = 0x8e4a;
  sVar1 = sub_8f71();
  if (sVar1 != 0) {
    _DAT_03fe = 0x8e50;
    sub_8e1b();
  }
  _DAT_03fe = 0x8e53;
  panel_main_loop();
  thunk_FUN_8f50();
  return;
}

// FUNC 0x8018  VEC06_EXTI1

undefined2 VEC06_EXTI1(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x801c  VEC07_EXTI2

undefined2 VEC07_EXTI2(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8080  uart1_param_check

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* UART1 parameter check/checker. Validates DAT_000e/DAT_000c/DAT_000d and
   mask args against valid sets; calls sub_8edd on failure. */

void uart1_param_check(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  byte extraout_A;
  byte extraout_A_00;
  ushort uVar4;
  byte extraout_XL;
  undefined2 uStack_3;
  
  sub_8398();
  sub_839d();
  bVar2 = DAT_0007;
  bVar1 = DAT_0006;
  DAT_000e = sub_8432();
  DAT_000c = DAT_0004;
  DAT_000d = DAT_0005;
  bVar3 = _DAT_0008 < 9;
  if (_DAT_0008 == 9) {
    bVar3 = _DAT_000a < 0x8969;
  }
  if (!bVar3) {
    sub_8edd(0x61);
  }
  if ((DAT_000e != 0) && (DAT_000e != 0x10)) {
    sub_8edd(0x62);
  }
  if ((((DAT_000c != 0) && (DAT_000c != 0x10)) && (DAT_000c != 0x20)) && (DAT_000c != 0x30)) {
    sub_8edd(99);
  }
  if (((DAT_000d != 0) && (DAT_000d != 4)) && (DAT_000d != 6)) {
    sub_8edd(100);
  }
  if (((bVar2 != 8) && (bVar2 != 0x40)) &&
     (((bVar2 != 4 && (((bVar2 != 0x80 && (bVar2 != 0xc)) && (bVar2 != 0x44)))) &&
      ((bVar2 != 0xc0 && (bVar2 != 0x88)))))) {
    sub_8edd(0x65);
  }
  if ((((bVar1 & 0x88) == 0x88) || ((bVar1 & 0x44) == 0x44)) ||
     (((bVar1 & 0x22) == 0x22 || ((bVar1 & 0x11) == 0x11)))) {
    sub_8edd(0x66);
  }
  UART1_CR1 = UART1_CR1 & 0xef;
  UART1_CR3 = UART1_CR3 & 0xcf | DAT_000c;
  UART1_CR1 = (UART1_CR1 | DAT_000e) & 0xf9 | DAT_000d;
  UART1_BRR1 = 0;
  UART1_BRR2 = 0;
  sub_8f29();
  sub_843f();
  sub_8ba9();
  sub_8425();
  sub_82e4();
  uVar4 = sub_8b8a();
  sub_8ba9((char)uVar4,(ushort)extraout_A << 8 | uVar4 >> 8);
  sub_843f();
  uVar4 = sub_8b62();
  sub_8f21((char)uVar4,(ushort)extraout_A_00 << 8 | uVar4 >> 8);
  sub_838e();
  sub_8f29();
  sub_8432();
  sub_840b();
  sub_8f21();
  sub_8418();
  sub_82e4();
  sub_83ca();
  sub_8237();
  sub_8351(4);
  sub_82e1();
  UART1_BRR2 = DAT_0003 & 0xf | UART1_BRR2;
  sub_8ea1(uStack_3);
  UART1_BRR2 = extraout_XL & 0xf0 | UART1_BRR2;
  UART1_BRR1 = (byte)uStack_3 | UART1_BRR1;
  UART1_CR2 = UART1_CR2 & 0xf3;
  if ((bVar2 & 4) != 0) {
    UART1_CR2 = UART1_CR2 | 8;
  }
  if ((bVar2 & 8) != 0) {
    UART1_CR2 = UART1_CR2 | 4;
  }
  if ((bVar1 & 0x80) == 0) {
    UART1_CR3 = bVar1 & 8 | bVar1 & 7 | UART1_CR3 & 0xf8;
  }
  else {
    UART1_CR3 = bVar1 & 7 | UART1_CR3 & 0xf0;
  }
  sub_83f3();
  return;
}

// FUNC 0x816d  x_816d

void x_816d(undefined2 param_1,byte param_2,byte param_3)

{
  byte extraout_A;
  byte extraout_A_00;
  ushort uVar1;
  byte extraout_XL;
  
  UART1_BRR2 = 0;
  sub_8f29();
  sub_843f();
  sub_8ba9();
  sub_8425();
  sub_82e4();
  uVar1 = sub_8b8a();
  sub_8ba9((char)uVar1,(ushort)extraout_A << 8 | uVar1 >> 8);
  sub_843f();
  uVar1 = sub_8b62();
  sub_8f21((char)uVar1,(ushort)extraout_A_00 << 8 | uVar1 >> 8);
  sub_838e();
  sub_8f29();
  sub_8432();
  sub_840b();
  sub_8f21();
  sub_8418();
  sub_82e4();
  sub_83ca();
  sub_8237();
  sub_8351();
  sub_82e1();
  UART1_BRR2 = DAT_0003 & 0xf | UART1_BRR2;
  sub_8ea1(param_1);
  UART1_BRR2 = extraout_XL & 0xf0 | UART1_BRR2;
  UART1_BRR1 = (byte)param_1 | UART1_BRR1;
  UART1_CR2 = UART1_CR2 & 0xf3;
  if ((param_2 & 4) != 0) {
    UART1_CR2 = UART1_CR2 | 8;
  }
  if ((param_2 & 8) != 0) {
    UART1_CR2 = UART1_CR2 | 4;
  }
  if ((param_3 & 0x80) == 0) {
    UART1_CR3 = param_3 & 8 | param_3 & 7 | UART1_CR3 & 0xf8;
  }
  else {
    UART1_CR3 = param_3 & 7 | UART1_CR3 & 0xf0;
  }
  sub_83f3();
  return;
}

// FUNC 0x8237  sub_8237

void sub_8237(void)

{
  DAT_0003 = DAT_0003 - DAT_0007;
  DAT_0002 = (DAT_0002 - DAT_0006) - (DAT_0002 < DAT_0006);
  DAT_0001 = (DAT_0001 - DAT_0005) - (DAT_0001 < DAT_0005);
  DAT_0000 = (DAT_0000 - DAT_0004) - (DAT_0000 < DAT_0004);
  return;
}

// FUNC 0x8252  mul_wide

/* Wide multiply helper (MUL with carry), panel twin of base mul_wide. */

void mul_wide(void)

{
  ushort *puVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  short sVar7;
  
  puVar1 = (ushort *)sub_8d8e();
  uVar3 = *puVar1;
  DAT_0004 = (char)(uVar3 >> 8);
  DAT_0005 = (char)uVar3;
  uVar5 = puVar1[1];
  DAT_0006 = (byte)(uVar5 >> 8);
  DAT_0007 = (char)uVar5;
  sVar2 = (uVar3 & 0xff) * (ushort)DAT_0003 +
          (ushort)DAT_0006 * (ushort)DAT_0002 +
          (uVar5 & 0xff) * (ushort)DAT_0001 +
          (ushort)(byte)(DAT_0004 * DAT_0003 +
                        DAT_0005 * DAT_0002 + DAT_0006 * DAT_0001 + DAT_0007 * DAT_0000) * 0x100;
  DAT_0000 = (char)((ushort)sVar2 >> 8);
  uVar3 = (uVar5 & 0xff) * (ushort)DAT_0002;
  uVar4 = uVar3 + sVar2 * 0x100;
  if (CARRY2(uVar3,sVar2 * 0x100)) {
    DAT_0000 = DAT_0000 + '\x01';
  }
  sVar2 = (ushort)DAT_0006 * (ushort)DAT_0003 + uVar4;
  DAT_0001 = (byte)((ushort)sVar2 >> 8);
  if (CARRY2((ushort)DAT_0006 * (ushort)DAT_0003,uVar4)) {
    DAT_0000 = DAT_0000 + '\x01';
  }
  sVar7 = CONCAT11(DAT_0000,DAT_0001);
  uVar5 = (uVar5 & 0xff) * (ushort)DAT_0003;
  sVar6 = uVar5 + sVar2 * 0x100;
  DAT_0002 = (byte)((ushort)sVar6 >> 8);
  DAT_0003 = (byte)sVar6;
  if (CARRY2(uVar5,sVar2 * 0x100)) {
    sVar7 = CONCAT11(DAT_0000,DAT_0001) + 1;
  }
  DAT_0000 = (char)((ushort)sVar7 >> 8);
  DAT_0001 = (byte)sVar7;
  return;
}

// FUNC 0x82dc  sub_82dc

void sub_82dc(void)

{
  sub_8d74();
  sub_82e4();
  return;
}

// FUNC 0x82e1  sub_82e1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_82e1(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  char cVar6;
  ushort uVar7;
  ushort uVar8;
  
  sub_8d81();
  uVar7 = _DAT_0002;
  if (_DAT_0000 != 0) {
    cVar6 = ' ';
    if (DAT_0000 == '\0') {
      _DAT_0000 = CONCAT31((int3)_DAT_0000,0xff);
      cVar6 = '\x18';
    }
    uVar7 = 0;
    uVar8 = 0;
    bVar5 = true;
    while( true ) {
      uVar4 = _DAT_0000;
      uVar2 = _DAT_0000 & 0x80;
      uVar3 = _DAT_0000 >> 8;
      DAT_0003 = DAT_0003 << 1 | bVar5;
      DAT_0002 = SUB41(uVar4,1);
      DAT_0002 = DAT_0002 << 1 | uVar2 != 0;
      DAT_0001 = SUB41(uVar4,2);
      DAT_0000 = SUB41(uVar4,3);
      DAT_0001 = DAT_0001 << 1 | (uVar3 & 0x80) != 0;
      DAT_0000 = DAT_0000 << 1 | (uVar4 >> 0x10 & 0x80) != 0;
      cVar6 = cVar6 + -1;
      if (cVar6 < '\0') break;
      uVar1 = uVar8 & 0x8000;
      uVar8 = uVar8 << 1 | (ushort)((uVar4 & 0x80000000) != 0);
      uVar7 = uVar7 << 1 | (ushort)(uVar1 != 0);
      bVar5 = uVar7 < _DAT_0004;
      if (uVar7 == _DAT_0004) {
        bVar5 = uVar8 < _DAT_0006;
      }
      if (!bVar5) {
        bVar5 = uVar8 < _DAT_0006;
        uVar8 = uVar8 - _DAT_0006;
        if (bVar5) {
          uVar7 = uVar7 - 1;
        }
        bVar5 = uVar7 < _DAT_0004;
        uVar7 = uVar7 - _DAT_0004;
      }
    }
    _DAT_0004 = uVar7;
    _DAT_0006 = uVar8;
    _DAT_0000 = CONCAT22(~_DAT_0000,~_DAT_0002);
    return;
  }
  if (_DAT_0004 == 0) {
    uVar7 = _DAT_0002 % _DAT_0006;
    _DAT_0000 = (uint)(_DAT_0002 / _DAT_0006);
    _DAT_0006 = uVar7;
    return;
  }
  _DAT_0004 = _DAT_0000;
  _DAT_0000 = 0;
  _DAT_0006 = uVar7;
  return;
}

// FUNC 0x82e4  sub_82e4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_82e4(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  char cVar6;
  ushort uVar7;
  ushort uVar8;
  
  uVar7 = _DAT_0002;
  if (_DAT_0000 != 0) {
    cVar6 = ' ';
    if (DAT_0000 == '\0') {
      _DAT_0000 = CONCAT31((int3)_DAT_0000,0xff);
      cVar6 = '\x18';
    }
    uVar7 = 0;
    uVar8 = 0;
    bVar5 = true;
    while( true ) {
      uVar4 = _DAT_0000;
      uVar2 = _DAT_0000 & 0x80;
      uVar3 = _DAT_0000 >> 8;
      DAT_0003 = DAT_0003 << 1 | bVar5;
      DAT_0002 = SUB41(uVar4,1);
      DAT_0002 = DAT_0002 << 1 | uVar2 != 0;
      DAT_0001 = SUB41(uVar4,2);
      DAT_0000 = SUB41(uVar4,3);
      DAT_0001 = DAT_0001 << 1 | (uVar3 & 0x80) != 0;
      DAT_0000 = DAT_0000 << 1 | (uVar4 >> 0x10 & 0x80) != 0;
      cVar6 = cVar6 + -1;
      if (cVar6 < '\0') break;
      uVar1 = uVar8 & 0x8000;
      uVar8 = uVar8 << 1 | (ushort)((uVar4 & 0x80000000) != 0);
      uVar7 = uVar7 << 1 | (ushort)(uVar1 != 0);
      bVar5 = uVar7 < _DAT_0004;
      if (uVar7 == _DAT_0004) {
        bVar5 = uVar8 < _DAT_0006;
      }
      if (!bVar5) {
        bVar5 = uVar8 < _DAT_0006;
        uVar8 = uVar8 - _DAT_0006;
        if (bVar5) {
          uVar7 = uVar7 - 1;
        }
        bVar5 = uVar7 < _DAT_0004;
        uVar7 = uVar7 - _DAT_0004;
      }
    }
    _DAT_0004 = uVar7;
    _DAT_0006 = uVar8;
    _DAT_0000 = CONCAT22(~_DAT_0000,~_DAT_0002);
    return;
  }
  if (_DAT_0004 == 0) {
    uVar7 = _DAT_0002 % _DAT_0006;
    _DAT_0000 = (uint)(_DAT_0002 / _DAT_0006);
    _DAT_0006 = uVar7;
    return;
  }
  _DAT_0004 = _DAT_0000;
  _DAT_0000 = 0;
  _DAT_0006 = uVar7;
  return;
}

// FUNC 0x8351  sub_8351

void sub_8351(char param_1)

{
  byte bVar1;
  byte bVar2;
  
  if (param_1 != '\0') {
    do {
      bVar1 = DAT_0003 & 0x80;
      DAT_0003 = DAT_0003 << 1;
      bVar2 = DAT_0002 & 0x80;
      DAT_0002 = DAT_0002 << 1 | bVar1 != 0;
      bVar1 = DAT_0001 & 0x80;
      DAT_0001 = DAT_0001 << 1 | bVar2 != 0;
      DAT_0000 = DAT_0000 << 1 | bVar1 != 0;
      param_1 = param_1 + -1;
    } while (param_1 != '\0');
  }
  return;
}

// FUNC 0x8362  sub_8362

void sub_8362(void)

{
  FUN_836c(0);
  return;
}

// FUNC 0x8367  sub_8367

void sub_8367(void)

{
  FUN_836c(8);
  return;
}

// FUNC 0x836c  FUN_836c

undefined2 FUN_836c(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x837f  sub_837f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 sub_837f(undefined2 param_1,undefined2 param_2)

{
  _DAT_0008 = param_2;
  return param_1;
}

// FUNC 0x838e  sub_838e

void sub_838e(void)

{
  FUN_83a2(0);
  return;
}

// FUNC 0x8393  sub_8393

void sub_8393(void)

{
  FUN_83a2(4);
  return;
}

// FUNC 0x8398  sub_8398

void sub_8398(void)

{
  FUN_83a2(8);
  return;
}

// FUNC 0x839d  sub_839d

void sub_839d(void)

{
  FUN_83a2(0xc);
  return;
}

// FUNC 0x83a2  FUN_83a2

undefined2 FUN_83a2(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x83bf  sub_83bf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_83bf(undefined2 param_1,undefined2 param_2)

{
  _DAT_0000 = param_1;
  _DAT_0002 = param_2;
  FUN_83eb();
  return;
}

// FUNC 0x83ca  sub_83ca

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_83ca(undefined2 param_1,undefined2 param_2)

{
  _DAT_0004 = param_1;
  _DAT_0006 = param_2;
  FUN_83eb();
  return;
}

// FUNC 0x83d5  sub_83d5

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_83d5(undefined2 param_1,undefined2 param_2)

{
  _DAT_0008 = param_1;
  _DAT_000a = param_2;
  FUN_83eb();
  return;
}

// FUNC 0x83e0  sub_83e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_83e0(undefined2 param_1,undefined2 param_2)

{
  _DAT_000c = param_1;
  _DAT_000e = param_2;
  FUN_83eb();
  return;
}

// FUNC 0x83eb  FUN_83eb

undefined2 FUN_83eb(void)

{
  undefined2 in_stack_00000001;
  
  return in_stack_00000001;
}

// FUNC 0x83f3  sub_83f3

void sub_83f3(void)

{
  sub_83e0();
  sub_83d5();
  return;
}

// FUNC 0x83f6  sub_83f6

void sub_83f6(void)

{
  sub_83d5();
  return;
}

// FUNC 0x83fa  sub_83fa

void sub_83fa(void)

{
  sub_837f();
  return;
}

// FUNC 0x83fe  sub_83fe

void sub_83fe(void)

{
  DAT_0000 = DAT_0008;
  DAT_0001 = DAT_0009;
  DAT_0002 = DAT_000a;
  DAT_0003 = DAT_000b;
  return;
}

// FUNC 0x840b  sub_840b

void sub_840b(void)

{
  DAT_0000 = DAT_000c;
  DAT_0001 = DAT_000d;
  DAT_0002 = DAT_000e;
  DAT_0003 = DAT_000f;
  return;
}

// FUNC 0x8418  sub_8418

void sub_8418(void)

{
  DAT_0004 = DAT_0008;
  DAT_0005 = DAT_0009;
  DAT_0006 = DAT_000a;
  DAT_0007 = DAT_000b;
  return;
}

// FUNC 0x8425  sub_8425

void sub_8425(void)

{
  DAT_0004 = DAT_000c;
  DAT_0005 = DAT_000d;
  DAT_0006 = DAT_000e;
  DAT_0007 = DAT_000f;
  return;
}

// FUNC 0x8432  sub_8432

void sub_8432(void)

{
  DAT_0008 = DAT_0000;
  DAT_0009 = DAT_0001;
  DAT_000a = DAT_0002;
  DAT_000b = DAT_0003;
  return;
}

// FUNC 0x843f  sub_843f

void sub_843f(void)

{
  DAT_000c = DAT_0000;
  DAT_000d = DAT_0001;
  DAT_000e = DAT_0002;
  DAT_000f = DAT_0003;
  return;
}

// FUNC 0x844c  display_frame_handler

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Display frame handler (ASR -> STM8, 115200 8N1).
   Validates 9-byte frame: [0]=0x5A, [8]=0xEE, len=9.
   Splits bytes 2-5 into 8 nibbles (abStack_8), then dispatches per channel.
   Nibble table: 0/2/4/6=off, 1=pin1, 3=pin3, 5=pin2, 7=pin1+pin2, 8-15=unchanged.
   Active-low: low=lit. See docs/panel_led_map.md. */

void display_frame_handler(void)

{
  byte bVar1;
  undefined1 uVar2;
  char *pcVar3;
  byte *pbVar4;
  byte abStack_8 [8];
  
  pcVar3 = (char *)sub_8398();
  uVar2 = DAT_000c;
  if (pcVar3[9] != '\t') {
    sub_8508();
    return;
  }
  if (*pcVar3 != 'Z') {
    sub_8508();
    return;
  }
  if (pcVar3[8] != -0x12) {
    sub_8508();
    return;
  }
  pbVar4 = (byte *)(pcVar3 + 2);
  _DAT_0000 = abStack_8;
  DAT_0002 = '\x04';
  do {
    DAT_0003 = *pbVar4;
    *_DAT_0000 = DAT_0003 >> 4;
    _DAT_0000[1] = DAT_0003 & 0xf;
    _DAT_0000 = _DAT_0000 + 2;
    pbVar4 = pbVar4 + 1;
    DAT_0002 = DAT_0002 + -1;
  } while (DAT_0002 != '\0');
  _DAT_000a = abStack_8;
  _DAT_0008 = 0x10;
  DAT_000c = '\b';
  do {
    bVar1 = *_DAT_000a;
    if (bVar1 == 0) {
LAB_84e1:
      pin1_set_high();
LAB_84e4:
      pin2_set_high();
LAB_84f2:
      get_pin3();
      pin_set();
    }
    else {
      if (bVar1 == 1) {
        pin1_set_low();
        goto LAB_84e4;
      }
      if (bVar1 == 2) goto LAB_84e1;
      if (bVar1 != 3) {
        if (bVar1 == 4) goto LAB_84e1;
        if (bVar1 == 5) {
          pin1_set_high();
        }
        else {
          if (bVar1 == 6) goto LAB_84e1;
          if (bVar1 != 7) goto LAB_84f8;
          pin1_set_low();
        }
        get_pin2();
        pin_clear();
        goto LAB_84f2;
      }
      pin1_set_high();
      pin2_set_high();
      get_pin3();
      pin_clear();
    }
LAB_84f8:
    _DAT_0008 = _DAT_0008 + 9;
    _DAT_000a = _DAT_000a + 1;
    DAT_000c = DAT_000c + -1;
    if (DAT_000c == '\0') {
      DAT_000c = uVar2;
      sub_83f6();
      return;
    }
  } while( true );
}

// FUNC 0x8508  sub_8508

void sub_8508(undefined1 param_1)

{
  DAT_000c = param_1;
  sub_83f6();
  return;
}

// FUNC 0x8510  gpio_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* GPIO_Init helper (SPL-style). Mode 0xF0 = push-pull output. */

void gpio_init(void)

{
  byte extraout_A;
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  _DAT_0008 = (byte *)sub_8398();
  DAT_000b = DAT_0000;
  DAT_000a = extraout_A;
  if (((((DAT_0000 != 0) && (DAT_0000 != 0x40)) && (DAT_0000 != 0x20)) &&
      ((((DAT_0000 != 0x60 && (DAT_0000 != 0xa0)) &&
        ((DAT_0000 != 0xe0 && ((DAT_0000 != 0x80 && (DAT_0000 != 0xc0)))))) && (DAT_0000 != 0xb0))))
     && (((DAT_0000 != 0xf0 && (DAT_0000 != 0x90)) && (DAT_0000 != 0xd0)))) {
    sub_8ebc(0x4d);
  }
  if (DAT_000a == 0) {
    sub_8ebc(0x4e);
  }
  DAT_0000 = ~DAT_000a;
  pbVar2 = _DAT_0008 + 4;
  *pbVar2 = *pbVar2 & DAT_0000;
  if ((DAT_000b & 0x80) == 0) {
    pbVar3 = _DAT_0008 + 2;
    bVar1 = *pbVar3 & DAT_0000;
  }
  else {
    if ((DAT_000b & 0x10) == 0) {
      bVar1 = *_DAT_0008 & DAT_0000;
    }
    else {
      bVar1 = *_DAT_0008 | DAT_000a;
    }
    *_DAT_0008 = bVar1;
    pbVar3 = _DAT_0008 + 2;
    bVar1 = *pbVar3 | DAT_000a;
  }
  *pbVar3 = bVar1;
  pbVar3 = _DAT_0008 + 3;
  if ((DAT_000b & 0x40) == 0) {
    bVar1 = *pbVar3 & DAT_0000;
  }
  else {
    bVar1 = *pbVar3 | DAT_000a;
  }
  *pbVar3 = bVar1;
  if ((DAT_000b & 0x20) == 0) {
    bVar1 = *pbVar2 & DAT_0000;
  }
  else {
    bVar1 = *pbVar2 | DAT_000a;
  }
  *pbVar2 = bVar1;
  sub_83f6();
  return;
}

// FUNC 0x85c1  sub_85c1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_85c1(void)

{
  undefined1 uVar1;
  char extraout_A;
  
  _DAT_0008 = (undefined *)sub_8367();
  uVar1 = DAT_000a;
  DAT_000a = extraout_A;
  if (((((_DAT_0008 != (undefined *)0x100) && (_DAT_0008 != &UNK_0277)) && (_DAT_0008 != &UNK_0266))
      && ((_DAT_0008 != &UNK_0205 && (_DAT_0008 != &UNK_0244)))) && (_DAT_0008 != &UNK_0346)) {
    sub_8edd(0xd8);
  }
  if ((DAT_000a != '\0') && (DAT_000a != '\x01')) {
    sub_8edd(0xd9);
  }
  sub_8f4a(DAT_0009);
  if (DAT_000a == '\0') {
    DAT_0000 = ~DAT_0000;
    if (DAT_0008 == '\x01') {
      UART1_CR1 = UART1_CR1 & DAT_0000;
    }
    else if (DAT_0008 == '\x02') {
      UART1_CR2 = UART1_CR2 & DAT_0000;
    }
    else {
      UART1_CR4 = UART1_CR4 & DAT_0000;
    }
  }
  else if (DAT_0008 == '\x01') {
    UART1_CR1 = UART1_CR1 | DAT_0000;
  }
  else if (DAT_0008 == '\x02') {
    UART1_CR2 = UART1_CR2 | DAT_0000;
  }
  else {
    UART1_CR4 = UART1_CR4 | DAT_0000;
  }
  DAT_000a = uVar1;
  sub_83fa();
  return;
}

// FUNC 0x8841  x_8841

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: RAM */

void x_8841(byte param_1)

{
  bool bVar1;
  byte *pbVar2;
  ushort in_Y;
  
  DAT_0053 = DAT_0053 << 1;
  bRAMffff = bRAMffff >> 1;
  DAT_004f = DAT_004f >> 1;
  pbVar2 = (byte *)(0xffff / in_Y + _DAT_7068);
  *pbVar2 = *pbVar2 << 1 | in_Y == 0;
  *_DAT_7665 = *_DAT_7665 << 1 | (param_1 & 1) != 0;
  bVar1 = SCARRY1(DAT_7372,'\x01');
  DAT_7372 = DAT_7372 + '\x01';
  DAT_0000 = (char)~((byte)~DAT_0000 >> 1) >> 2;
  DAT_0067 = DAT_0067 >> 1;
  if (bVar1) {
    DAT_005c = ~DAT_005c - 1;
    DAT_0000 = DAT_0000 >> 1;
    UNK_006e = 0;
    DAT_0001 = -DAT_0001;
    *(undefined1 *)(_DAT_6a65 + 1) = 0;
    UNK_0075 = ~UNK_0075;
    DAT_0001 = ~DAT_0001;
    UNK_0077 = UNK_0077 >> 1;
    UNK_0069 = UNK_0069 << 4 | UNK_0069 >> 4;
    DAT_0002 = DAT_0002 + -1;
    UNK_0071 = UNK_0071 << 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  bRAMffff = bRAMffff >> 1;
  DAT_004f = DAT_004f >> 1;
  pbVar2 = (byte *)(0xffff / (0xffffU % in_Y) + _DAT_7068);
  *pbVar2 = *pbVar2 << 1 | 0xffffU % in_Y == 0;
  *_DAT_7665 = *_DAT_7665 << 1 | (param_1 >> 1 & 1) != 0;
  DAT_7372 = DAT_7372 + '\x01';
  UNK_006c = ~UNK_006c;
  DAT_005c = DAT_003a;
  DAT_0000 = (byte)~DAT_0000 >> 2;
  UNK_006e = 0;
  DAT_0001 = -DAT_0001;
  *(undefined1 *)(_DAT_6a65 + 1) = 0;
  UNK_0075 = ~UNK_0075;
  DAT_0001 = ~DAT_0001;
  UNK_0077 = UNK_0077 >> 1;
  UNK_0069 = UNK_0069 << 4 | UNK_0069 >> 4;
  DAT_0002 = DAT_0002 + -1;
  UNK_0071 = UNK_0071 << 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x896d  panel_main_loop

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Panel main loop. Calls uart1_init_115200, led_gpio_init, sub_8a52 twice,
   enables interrupts, prints the DAT_005b buffer, then loops calling
   display_frame_handler (sub_844c) + sub_8e65. */

void panel_main_loop(void)

{
  byte extraout_CC;
  byte extraout_CC_00;
  
  sub_8398();
  sub_8cd6(0);
  DAT_0000 = 0x3f;
  sub_8cac();
  DAT_0000 = 0x7c;
  sub_8be4();
  sub_8dbd();
  DAT_0000 = 1;
  sub_8c1e();
  sub_8def();
  uart1_init_115200();
  sub_8e8c();
  led_gpio_init();
  DAT_0000 = 1;
  sub_8a52();
  DAT_0000 = 3;
  sub_8a52();
  __EnableInterrupt();
  if (DAT_005b != 0) {
    _DAT_000a = &DAT_0058;
    _DAT_0008 = (ushort)DAT_005b;
    do {
      sub_8f61(*_DAT_000a);
      do {
        sub_8f06();
      } while ((bool)(extraout_CC >> 1 & 1));
      sub_8ea6();
    } while (!(bool)(extraout_CC_00 >> 1 & 1));
  }
  do {
    if (DAT_0067 != '\0') {
      display_frame_handler(DAT_0067,0x5d);
      sub_8e65();
      DAT_0067 = '\0';
    }
    sub_8da3(0x68);
  } while( true );
}

// FUNC 0x89ef  sub_89ef

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_89ef(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
  _DAT_0008 = (undefined *)sub_8367();
  uVar2 = DAT_000a;
  DAT_000a = 0;
  if (((((_DAT_0008 != (undefined *)0x80) && (_DAT_0008 != (undefined *)0x40)) &&
       (_DAT_0008 != (undefined *)0x20)) &&
      ((_DAT_0008 != (undefined *)0x10 && (_DAT_0008 != (undefined *)0x8)))) &&
     ((_DAT_0008 != (undefined *)0x4 &&
      ((_DAT_0008 != (undefined *)0x2 && (_DAT_0008 != (undefined *)0x1)))))) {
    if (_DAT_0008 == &UNK_0101) {
      bVar1 = UART1_CR2 & 1;
      goto joined_r0x8a4b;
    }
    if (_DAT_0008 == &UNK_0210) {
      bVar1 = UART1_CR4 & 0x10;
      goto joined_r0x8a4b;
    }
    sub_8edd(&UNK_023d);
  }
  bVar1 = DAT_0009 & UART1_SR;
joined_r0x8a4b:
  if (bVar1 != 0) {
    DAT_000a = 1;
  }
  uVar3 = DAT_000a;
  DAT_000a = uVar2;
  sub_83fa(uVar3);
  return;
}

// FUNC 0x8a52  sub_8a52

void sub_8a52(void)

{
  byte bVar1;
  
  DAT_0009 = sub_8367();
  DAT_0008 = DAT_0000;
  if (0x18 < DAT_0009) {
    sub_8ec7(0xe2);
  }
  if ((((DAT_0008 != '\x02') && (DAT_0008 != '\x01')) && (DAT_0008 != '\0')) && (DAT_0008 != '\x03')
     ) {
    sub_8ec7(0xe3);
  }
  bVar1 = sub_8f6b();
  if ((bVar1 & 0x28) != 0x28) {
    sub_8ec7(0xe6);
  }
  if (((DAT_0009 == 0x11) || (DAT_0009 == 0x12)) || (DAT_0009 == 0x17)) {
    bVar1 = sub_8e56();
    DAT_7f75 = ~bVar1 & DAT_7f75;
    DAT_0000 = DAT_0001;
    bVar1 = sub_8ef3(DAT_0008);
    DAT_7f75 = bVar1 | DAT_7f75;
  }
  sub_83fa();
  return;
}

// FUNC 0x8ab4  led_pin_table_flash

/* WARNING: Control flow encountered bad instruction data */

void led_pin_table_flash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x8ac3  ret_8ac3

/* WARNING: Control flow encountered bad instruction data */

void ret_8ac3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x8af0  ret_8af0

undefined2 ret_8af0(byte param_1,short param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  byte in_stack_00000002;
  undefined1 uStack0004;
  undefined1 uStack0008;
  undefined1 uStack0010;
  
  uStack0004 = 0;
  uStack0008 = 0;
  uStack0010 = 0;
  sub_838e(*(undefined2 *)(((ushort)param_1 << 8 | param_2 - 1U >> 8) + 3));
  sub_8393();
  sub_8367();
  DAT_005c = 10;
  if ((UART1_SR & 8) != 0) {
    UART1_SR = UART1_SR & 0xf7;
    sub_8f5d();
  }
  DAT_0001 = DAT_0066;
  if (DAT_0066 < 9) {
    DAT_0066 = DAT_0066 + 1;
    DAT_0000 = 0;
    sub_8362();
    uVar1 = sub_8f5d();
    puVar2 = &stack0x0002;
    *(undefined1 *)(in_stack_00000002 + 0x5d) = uVar1;
    register0x0008 = (BADSPACEBASE *)&stack0x0002;
    if (DAT_0066 == 9) {
      DAT_0067 = 1;
      DAT_005c = 0;
      register0x0008 = (BADSPACEBASE *)puVar2;
    }
  }
  else {
    sub_8f5d();
  }
  *(undefined2 *)((short)register0x0008 + -1) = 0x8b5b;
  sub_837f();
  *(undefined2 *)((short)register0x0008 + -1) = 0x8b5e;
  sub_83ca();
  *(undefined2 *)((short)register0x0008 + -1) = 0x8b61;
  sub_83bf();
  return *(undefined2 *)((short)register0x0008 + 3);
}

// FUNC 0x8b0c  vec_8b0c

undefined2 vec_8b0c(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  short in_stack_00000001;
  
  sub_838e();
  sub_8393();
  sub_8367();
  DAT_005c = 10;
  if ((UART1_SR & 8) != 0) {
    UART1_SR = UART1_SR & 0xf7;
    sub_8f5d();
  }
  DAT_0001 = DAT_0066;
  if (DAT_0066 < 9) {
    DAT_0066 = DAT_0066 + 1;
    DAT_0000 = 0;
    sub_8362();
    uVar1 = sub_8f5d();
    puVar2 = &stack0x0002;
    *(undefined1 *)(in_stack_00000001 + 0x5d) = uVar1;
    register0x0008 = (BADSPACEBASE *)&stack0x0002;
    if (DAT_0066 == 9) {
      DAT_0067 = 1;
      DAT_005c = 0;
      register0x0008 = (BADSPACEBASE *)puVar2;
    }
  }
  else {
    sub_8f5d();
  }
  *(undefined2 *)((short)register0x0008 + -1) = 0x8b5b;
  sub_837f();
  *(undefined2 *)((short)register0x0008 + -1) = 0x8b5e;
  sub_83ca();
  *(undefined2 *)((short)register0x0008 + -1) = 0x8b61;
  sub_83bf();
  return *(undefined2 *)((short)register0x0008 + 3);
}

// FUNC 0x8b62  sub_8b62

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * sub_8b62(void)

{
  undefined2 *puVar1;
  byte *in_stack_00000001;
  
  puVar1 = (undefined2 *)(&stack0x0002 + *in_stack_00000001);
  _DAT_0000 = *puVar1;
  _DAT_0002 = puVar1[1];
  return puVar1;
}

// FUNC 0x8b72  sub_8b72

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * sub_8b72(undefined2 *param_1)

{
  _DAT_0000 = *param_1;
  _DAT_0002 = param_1[1];
  return param_1;
}

// FUNC 0x8b7e  sub_8b7e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * sub_8b7e(undefined2 *param_1)

{
  _DAT_0004 = *param_1;
  _DAT_0006 = param_1[1];
  return param_1;
}

// FUNC 0x8b8a  sub_8b8a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8b8a(void)

{
  byte bVar1;
  byte *in_stack_00000001;
  
  bVar1 = *in_stack_00000001;
  *(undefined2 *)(&stack0x0002 + bVar1) = _DAT_0000;
  *(undefined2 *)(&stack0x0004 + bVar1) = _DAT_0002;
  return;
}

// FUNC 0x8ba9  sub_8ba9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8ba9(void)

{
  if (CLK_CMSR == -0x1f) {
    _DAT_0006 = (ushort)(byte)FUN_8f50[(CLK_CKDIVR >> 3 & 0xff03) + 5];
    _DAT_0004 = 0;
    sub_82dc();
    return;
  }
  if (CLK_CMSR != -0x2e) {
    _DAT_0002 = 0x2400;
    _DAT_0000 = 0xf4;
    return;
  }
  _DAT_0002 = 0xf400;
  _DAT_0000 = 1;
  return;
}

// FUNC 0x8be4  sub_8be4

void sub_8be4(void)

{
  DAT_0008 = sub_8367();
  DAT_0009 = DAT_0000;
  if (((((DAT_0008 != '\0') && (DAT_0008 != '\x01')) && (DAT_0008 != '\x02')) &&
      ((DAT_0008 != '\x03' && (DAT_0008 != '\x04')))) &&
     ((DAT_0008 != '\x05' && ((DAT_0008 != '\x06' && (DAT_0008 != '\a')))))) {
    sub_8ed2(0x44);
  }
  TIM4_EGR = DAT_0008;
  TIM4_CNTR = DAT_0009;
  sub_83fa();
  return;
}

// FUNC 0x8c1e  sub_8c1e

void sub_8c1e(void)

{
  DAT_0009 = sub_8367();
  DAT_0008 = DAT_0000;
  if (DAT_0009 != 1) {
    sub_8ed2(0x6e);
  }
  if (DAT_0008 == '\0') {
    DAT_0009 = ~DAT_0009;
    TIM4_ETR = DAT_0009 & TIM4_ETR;
  }
  else {
    if (DAT_0008 != '\x01') {
      sub_8ed2(0x6f);
    }
    TIM4_ETR = TIM4_ETR | DAT_0009;
  }
  sub_83fa();
  return;
}

// FUNC 0x8c31  x_8c31

void x_8c31(void)

{
  byte in_CC;
  
  if ((bool)(in_CC >> 1 & 1)) {
    DAT_0009 = ~DAT_0009;
    TIM4_ETR = DAT_0009 & TIM4_ETR;
  }
  else {
    if (DAT_0008 != '\x01') {
      sub_8ed2(0x6f);
    }
    TIM4_ETR = TIM4_ETR | DAT_0009;
  }
  sub_83fa();
  return;
}

// FUNC 0x8c52  led_gpio_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* LED GPIO init. Iterates _DAT_0008=0x0010 with DAT_000a=0x18 (24 pins), calls sub_8510 with mode
   0xF0. */

void led_gpio_init(void)

{
  undefined1 uVar1;
  
  sub_8367();
  uVar1 = DAT_000a;
  _DAT_0008 = (undefined2 *)&led_pin_table;
  DAT_000a = '\x18';
  do {
    DAT_0000 = 0xf0;
    gpio_init(*(undefined1 *)(_DAT_0008 + 1),*_DAT_0008);
    _DAT_0008 = (undefined2 *)((short)_DAT_0008 + 3);
    DAT_000a = DAT_000a + -1;
  } while (DAT_000a != '\0');
  DAT_000a = uVar1;
  sub_83fa();
  return;
}

// FUNC 0x8c81  sub_8c81

undefined1 sub_8c81(void)

{
  UART1_BRR2 = 0;
  UART1_BRR1 = 0;
  UART1_CR1 = 0;
  UART1_CR2 = 0;
  UART1_CR3 = 0;
  UART1_CR4 = 0;
  UART1_CR5 = 0;
  UART1_GTR = 0;
  UART1_PSCR = 0;
  return UART1_DR;
}

// FUNC 0x8cac  sub_8cac

void sub_8cac(void)

{
  DAT_0008 = sub_8367();
  DAT_0009 = DAT_0000;
  if (0x7f < DAT_0000) {
    sub_8ee8(0x38);
  }
  WWDG_CR = DAT_0008 | 0xc0;
  WWDG_WR = DAT_0009 & 0x7f | 0x40;
  sub_83fa();
  return;
}

// FUNC 0x8cd6  sub_8cd6

void sub_8cd6(byte param_1)

{
  undefined1 uVar1;
  
  uVar1 = DAT_0008;
  DAT_0008 = param_1;
  if ((((param_1 != 0) && (param_1 != 8)) && (param_1 != 0x10)) && (param_1 != 0x18)) {
    sub_8eb1(&UNK_01a2);
  }
  sub_8f0f();
  CLK_CKDIVR = CLK_CKDIVR | DAT_0008;
  DAT_0008 = uVar1;
  return;
}

// FUNC 0x8d26  uart1_init_115200

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* UART1 init for 115200 (Roadstm8Panel). Sets DAT_0007=0x0C, DAT_0006=0x80,
   DAT_0002=0xC200 (115200), then calls the configure chain. Parallel to the
   base board uart1_init_2400 (0x9B17, DAT_0002=0x960). */

undefined1 uart1_init_115200(void)

{
  sub_8c81();
  DAT_0007 = 0xc;
  DAT_0006 = 0x80;
  DAT_0005 = 0;
  DAT_0004 = 0;
  _DAT_0002 = 0xc200;
  _DAT_0000 = 1;
  uart1_param_check(0);
  sub_85c1(1,&UNK_0205);
  return 1;
}

// FUNC 0x8d4d  vec_8d4d

undefined2 vec_8d4d(undefined2 param_1)

{
  sub_838e();
  sub_8393();
  if ((DAT_005c != '\0') && (DAT_005c = DAT_005c + -1, DAT_005c == '\0')) {
    DAT_0067 = 1;
  }
  sub_8dd6(1);
  sub_83ca();
  sub_83bf();
  return param_1;
}

// FUNC 0x8d74  sub_8d74

void sub_8d74(undefined2 param_1)

{
  sub_8b72(param_1);
  return;
}

// FUNC 0x8d81  sub_8d81

void sub_8d81(undefined2 param_1)

{
  sub_8b7e(param_1);
  return;
}

// FUNC 0x8d8e  sub_8d8e

undefined2 sub_8d8e(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8da3  sub_8da3

void sub_8da3(byte param_1)

{
  undefined1 uVar1;
  
  uVar1 = DAT_0008;
  DAT_0008 = param_1;
  if (0x7f < param_1) {
    sub_8ee8(0x48);
  }
  WWDG_CR = DAT_0008 & 0x7f;
  DAT_0008 = uVar1;
  return;
}

// FUNC 0x8dbd  sub_8dbd

void sub_8dbd(byte param_1)

{
  undefined1 uVar1;
  
  uVar1 = DAT_0008;
  DAT_0008 = param_1;
  if (param_1 != 1) {
    sub_8ed2(&UNK_015b);
  }
  DAT_0008 = ~DAT_0008;
  TIM4_IER = DAT_0008;
  DAT_0008 = uVar1;
  return;
}

// FUNC 0x8dd6  sub_8dd6

void sub_8dd6(byte param_1)

{
  undefined1 uVar1;
  
  uVar1 = DAT_0008;
  DAT_0008 = param_1;
  if (param_1 != 1) {
    sub_8ed2(&UNK_018a);
  }
  DAT_0008 = ~DAT_0008;
  TIM4_IER = DAT_0008;
  DAT_0008 = uVar1;
  return;
}

// FUNC 0x8def  sub_8def

void sub_8def(char param_1)

{
  if (param_1 != '\0') {
    if (param_1 != '\x01') {
      sub_8ed2(0x54);
    }
    TIM4_CR1 = TIM4_CR1 | 1;
    return;
  }
  TIM4_CR1 = TIM4_CR1 & 0xfe;
  return;
}

// FUNC 0x8e05  sub_8e05

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * sub_8e05(undefined1 *param_1)

{
  undefined1 in_YL;
  
  _DAT_0002 = param_1;
  for (; _DAT_0000 != 0; _DAT_0000 = _DAT_0000 + -1) {
    *param_1 = in_YL;
    param_1 = param_1 + 1;
  }
  return _DAT_0002;
}

// FUNC 0x8e1b  sub_8e1b

void sub_8e1b(void)

{
  code *pcVar1;
  
  for (pcVar1 = (code *)&DAT_8d99; pcVar1 != sub_8da3; pcVar1 = (code *)func_0x0000eb80(pcVar1 + 2))
  {
  }
  return;
}

// FUNC 0x8e2f  sub_8e2f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8e2f(void)

{
  undefined1 uStack_1;
  
  _DAT_0008 = sub_8367();
  do {
    sub_8f8e(1,&uStack_1);
  } while( true );
}

// FUNC 0x8e43  vec_8e43

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vec_8e43(void)

{
  short sVar1;
  
  _DAT_03fe = 0x8e4a;
  sVar1 = sub_8f71();
  if (sVar1 != 0) {
    _DAT_03fe = 0x8e50;
    sub_8e1b();
  }
  _DAT_03fe = 0x8e53;
  panel_main_loop();
  thunk_FUN_8f50();
  return;
}

// FUNC 0x8e56  sub_8e56

void sub_8e56(void)

{
  DAT_0000 = (DAT_0009 & 3) << 1;
  DAT_0001 = DAT_0000;
  sub_8ef3(3);
  return;
}

// FUNC 0x8e65  sub_8e65

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8e65(void)

{
  _DAT_0000 = 10;
  sub_8e05(0x5d);
  return;
}

// FUNC 0x8e72  get_pin3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 get_pin3(void)

{
  return *(undefined2 *)(_DAT_0008 + 6);
}

// FUNC 0x8e7f  get_pin2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 get_pin2(void)

{
  return *(undefined2 *)(_DAT_0008 + 3);
}

// FUNC 0x8e8c  sub_8e8c

void sub_8e8c(char param_1)

{
  if (param_1 != '\0') {
    UART1_CR1 = UART1_CR1 & 0xdf;
    return;
  }
  UART1_CR1 = UART1_CR1 | 0x20;
  return;
}

// FUNC 0x8e99  sub_8e99

void sub_8e99(char param_1)

{
  if (param_1 != '\0') {
    do {
      param_1 = param_1 + -1;
    } while (param_1 != '\0');
  }
  return;
}

// FUNC 0x8ea1  sub_8ea1

ushort sub_8ea1(ushort param_1)

{
  return param_1 >> 4;
}

// FUNC 0x8ea6  sub_8ea6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8ea6(void)

{
  _DAT_000a = _DAT_000a + 1;
  _DAT_0008 = _DAT_0008 + -1;
  return;
}

// FUNC 0x8eb1  sub_8eb1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8eb1(undefined2 param_1)

{
  _DAT_0000 = 0;
  _DAT_0002 = param_1;
  sub_8f7a(0x8867);
  return;
}

// FUNC 0x8ebc  sub_8ebc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8ebc(undefined2 param_1)

{
  _DAT_0000 = 0;
  _DAT_0002 = param_1;
  sub_8f7a(s_E__eaton_projects_guangzhou_weim_86db);
  return;
}

// FUNC 0x8ec7  sub_8ec7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8ec7(undefined2 param_1)

{
  _DAT_0000 = 0;
  _DAT_0002 = param_1;
  sub_8f7a(0x88ea);
  return;
}

// FUNC 0x8ed2  sub_8ed2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8ed2(undefined2 param_1)

{
  _DAT_0000 = 0;
  _DAT_0002 = param_1;
  sub_8f7a(s_E__eaton_projects_guangzhou_weim_875f);
  return;
}

// FUNC 0x8edd  sub_8edd

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8edd(undefined2 param_1)

{
  _DAT_0000 = 0;
  _DAT_0002 = param_1;
  sub_8f7a(s_E__eaton_projects_guangzhou_weim_8656);
  return;
}

// FUNC 0x8ee8  sub_8ee8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8ee8(undefined2 param_1)

{
  _DAT_0000 = 0;
  _DAT_0002 = param_1;
  sub_8f7a(0x87e3);
  return;
}

// FUNC 0x8ef3  sub_8ef3

void sub_8ef3(void)

{
  if (DAT_0000 != '\0') {
    do {
      DAT_0000 = DAT_0000 + -1;
    } while (DAT_0000 != '\0');
  }
  return;
}

// FUNC 0x8efd  get_pin1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 get_pin1(void)

{
  return *_DAT_0008;
}

// FUNC 0x8f06  sub_8f06

void sub_8f06(void)

{
  sub_89ef(0x80);
  return;
}

// FUNC 0x8f0f  sub_8f0f

void sub_8f0f(void)

{
  CLK_CKDIVR = CLK_CKDIVR & 0xe7;
  return;
}

// FUNC 0x8f18  sub_8f18

undefined1 sub_8f18(byte param_1)

{
  undefined1 uVar1;
  
  uVar1 = sub_8e99(param_1 & 0xf,1);
  return uVar1;
}

// FUNC 0x8f21  sub_8f21

void sub_8f21(void)

{
  mul_wide();
  return;
}

// FUNC 0x8f29  sub_8f29

void sub_8f29(void)

{
  sub_83fe();
  sub_8351(4);
  return;
}

// FUNC 0x8f31  sub_8f31

void sub_8f31(byte param_1,byte *param_2)

{
  DAT_0000 = param_1;
  *param_2 = *param_2 | param_1;
  return;
}

// FUNC 0x8f38  pin1_set_low

void pin1_set_low(void)

{
  get_pin1();
  pin_clear();
  return;
}

// FUNC 0x8f3e  pin2_set_high

void pin2_set_high(void)

{
  get_pin2();
  pin_set();
  return;
}

// FUNC 0x8f44  pin1_set_high

void pin1_set_high(void)

{
  get_pin1();
  pin_set();
  return;
}

// FUNC 0x8f4a  sub_8f4a

void sub_8f4a(void)

{
  DAT_0000 = sub_8f18();
  return;
}

// FUNC 0x8f50  FUN_8f50

void FUN_8f50(undefined2 param_1)

{
  byte extraout_A;
  byte *pbVar1;
  
  pbVar1 = (byte *)sub_8e2f(param_1);
  *pbVar1 = ~extraout_A & *pbVar1;
  return;
}

// FUNC 0x8f59  sub_8f59

void sub_8f59(byte param_1,byte *param_2)

{
  *param_2 = ~param_1 & *param_2;
  return;
}

// FUNC 0x8f5d  sub_8f5d

undefined1 sub_8f5d(void)

{
  return UART1_DR;
}

// FUNC 0x8f61  sub_8f61

void sub_8f61(undefined1 param_1)

{
  UART1_DR = param_1;
  return;
}

// FUNC 0x8f65  pin_clear

void pin_clear(byte param_1,byte *param_2)

{
  *param_2 = ~param_1 & *param_2;
  return;
}

// FUNC 0x8f68  pin_set

void pin_set(byte param_1,byte *param_2)

{
  DAT_0000 = param_1;
  *param_2 = *param_2 | param_1;
  return;
}

// FUNC 0x8f6b  sub_8f6b

undefined1 sub_8f6b(void)

{
  undefined1 in_CC;
  
  return in_CC;
}

// FUNC 0x8f6e  thunk_FUN_8f77

void thunk_FUN_8f77(void)

{
  do {
    __Nop();
  } while( true );
}

// FUNC 0x8f71  sub_8f71

undefined2 sub_8f71(void)

{
  return 1;
}

// FUNC 0x8f74  thunk_FUN_8f50

void thunk_FUN_8f50(undefined2 param_1)

{
  byte extraout_A;
  byte *pbVar1;
  
  pbVar1 = (byte *)sub_8e2f(param_1);
  *pbVar1 = ~extraout_A & *pbVar1;
  return;
}

// FUNC 0x8f77  FUN_8f77

void FUN_8f77(void)

{
  do {
    __Nop();
  } while( true );
}

// FUNC 0x8f7a  sub_8f7a

void sub_8f7a(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x8f7c  vec_8f7c

undefined2 vec_8f7c(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f7d  vec_8f7d

undefined2 vec_8f7d(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f7e  vec_8f7e

undefined2 vec_8f7e(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f7f  vec_8f7f

undefined2 vec_8f7f(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f80  vec_8f80

undefined2 vec_8f80(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f81  vec_8f81

undefined2 vec_8f81(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f82  vec_8f82

undefined2 vec_8f82(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f83  vec_8f83

undefined2 vec_8f83(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f84  vec_8f84

undefined2 vec_8f84(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f85  vec_8f85

undefined2 vec_8f85(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f86  vec_8f86

undefined2 vec_8f86(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f87  vec_8f87

undefined2 vec_8f87(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f88  vec_8f88

undefined2 vec_8f88(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f89  vec_8f89

undefined2 vec_8f89(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f8a  vec_8f8a

undefined2 vec_8f8a(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f8b  vec_8f8b

undefined2 vec_8f8b(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f8c  vec_8f8c

undefined2 vec_8f8c(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f8d  vec_8f8d

undefined2 vec_8f8d(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f8e  sub_8f8e

void sub_8f8e(void)

{
  return;
}

// FUNC 0x8f8f  gap_8f8f

/* WARNING: Control flow encountered bad instruction data */

void gap_8f8f(undefined2 *param_1)

{
  undefined2 in_Y;
  
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
                    /* WARNING: Bad instruction - Truncating control flow here */
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  halt_baddata();
}

// FUNC 0x8fa0  gap_8fa0

/* WARNING: Control flow encountered bad instruction data */

void gap_8fa0(undefined2 *param_1)

{
  undefined2 in_Y;
  
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
                    /* WARNING: Bad instruction - Truncating control flow here */
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  halt_baddata();
}

// FUNC 0x8fa9  uart1_configure

/* WARNING: Control flow encountered bad instruction data */
/* UART1 configuration routine.
     1. CR1: 8-bit word, WAKE cleared, mask OR'ed from RAM 0x0006
     2. CR3: STOP=00 (1 stop bit), bit2 set
     3. CR1/CR2/CR3/CR4 enable/interrupt bits set from mask
     4. BRR1/BRR2 programmed from a computed 16-bit divisor
   No direct CALL exists in the image; reached by fall-through or via an
   indirect function pointer, so the baud divisor is not yet recovered. */

void uart1_configure(undefined2 *param_1)

{
  undefined2 in_Y;
  
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
                    /* WARNING: Bad instruction - Truncating control flow here */
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  halt_baddata();
}

// FUNC 0x8fb5  x_8fb5

/* WARNING: Control flow encountered bad instruction data */

void x_8fb5(undefined2 *param_1)

{
  undefined2 in_Y;
  
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
                    /* WARNING: Bad instruction - Truncating control flow here */
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  halt_baddata();
}

// FUNC 0x8fba  gap_8fba

/* WARNING: Control flow encountered bad instruction data */

void gap_8fba(undefined2 *param_1)

{
  undefined2 in_Y;
  
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
                    /* WARNING: Bad instruction - Truncating control flow here */
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  halt_baddata();
}

// FUNC 0x8fcb  gap_8fcb

/* WARNING: Control flow encountered bad instruction data */

void gap_8fcb(undefined2 *param_1)

{
  undefined2 in_Y;
  
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
                    /* WARNING: Bad instruction - Truncating control flow here */
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  halt_baddata();
}

// FUNC 0x8fdc  gap_8fdc

/* WARNING: Control flow encountered bad instruction data */

void gap_8fdc(undefined2 *param_1)

{
  undefined2 in_Y;
  
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x8fed  gap_8fed

/* WARNING: Control flow encountered bad instruction data */

void gap_8fed(undefined2 *param_1)

{
  undefined2 in_Y;
  
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x8ffe  gap_8ffe

/* WARNING: Control flow encountered bad instruction data */

void gap_8ffe(undefined2 *param_1)

{
  undefined2 in_Y;
  
  *param_1 = in_Y;
  *param_1 = in_Y;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x908a  x_908a

/* WARNING: Control flow encountered bad instruction data */

void x_908a(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9510  x_9510

/* WARNING: Control flow encountered bad instruction data */

void x_9510(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x95de  x_95de

/* WARNING: Control flow encountered bad instruction data */

void x_95de(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9780  uart1_set_control_bits

/* WARNING: Control flow encountered bad instruction data */

void uart1_set_control_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x97d3  x_97d3

/* WARNING: Control flow encountered bad instruction data */

void x_97d3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9824  x_9824

/* WARNING: Control flow encountered bad instruction data */

void x_9824(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9bcf  x_9bcf

/* WARNING: Control flow encountered bad instruction data */

void x_9bcf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9c31  x_9c31

/* WARNING: Control flow encountered bad instruction data */

void x_9c31(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9c5b  x_9c5b

/* WARNING: Control flow encountered bad instruction data */

void x_9c5b(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9cd8  reset_startup

/* WARNING: Control flow encountered bad instruction data */
/* Reset entry: SP = 0x03FF, init calls, then jump to main. */

void reset_startup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

