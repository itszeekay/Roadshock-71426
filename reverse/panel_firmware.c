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
 *  816D  uart_config_tail
 *  8237  arith_sub
 *  8252  mul_wide
 *  82DC  div_panel
 *  82E1  div_panel_2
 *  82E4  div_helper
 *  8351  reg_write_a
 *  8362  bank_0
 *  8367  bank_8
 *  836C  identity_fn_2
 *  837F  save_ptr
 *  838E  bank_0b
 *  8393  bank_4
 *  8398  bank_8b
 *  839D  bank_c
 *  83A2  identity_fn
 *  83BF  save_ptr_0
 *  83CA  save_ptr_1
 *  83D5  save_ptr_2
 *  83E0  save_ptr_3
 *  83EB  stack_ret
 *  83F3  save_chain_c
 *  83F6  save_chain_a
 *  83FA  save_chain_b
 *  83FE  save_regs_0
 *  840B  save_regs_1
 *  8418  save_regs_2
 *  8425  save_regs_3
 *  8432  save_regs_4
 *  843F  save_regs_5
 *  844C  display_frame_handler
 *  8508  frame_fail
 *  8510  gpio_init
 *  85C1  uart1_cr_bits_checked
 *  8841  desync_8841
 *  896D  panel_main_loop
 *  89EF  led_state_read
 *  8A52  led_selftest
 *  8AB4  led_pin_table_flash
 *  8AC3  desync_8ac3
 *  8AF0  led_nibble_dispatch
 *  8B0C  vec_8b0c_isr
 *  8B62  load_pair_0
 *  8B72  load_pair_1
 *  8B7E  load_pair_2
 *  8B8A  display_step
 *  8BA9  baud_lookup
 *  8BE4  pin_ctrl_a
 *  8C1E  pin_init
 *  8C31  display_wait
 *  8C52  led_gpio_init
 *  8C81  uart_brr_clear
 *  8CAC  pin_ctrl_b
 *  8CD6  pin_ctrl_c
 *  8D26  uart1_init_115200
 *  8D4D  vec_8d4d_isr
 *  8D74  pin_set_call
 *  8D81  pin_set_call_2
 *  8D8E  identity_2
 *  8DA3  pin_ctrl
 *  8DBD  pin_ctrl_2
 *  8DD6  pin_ctrl_3
 *  8DEF  uart_cr_a
 *  8E05  addr_lookup
 *  8E1B  init_walker
 *  8E2F  reg_read_a
 *  8E43  reset_chain
 *  8E56  led_shift
 *  8E65  display_kick
 *  8E72  get_pin3
 *  8E7F  get_pin2
 *  8E8C  uart_clear_20
 *  8E99  shift_loop
 *  8EA1  shr_4
 *  8EA6  step_pair
 *  8EB1  trap_setup_a
 *  8EBC  trap_setup_b
 *  8EC7  trap_setup_c
 *  8ED2  trap_setup_d
 *  8EDD  trap_setup_e
 *  8EE8  trap_setup_f
 *  8EF3  shift_loop_2
 *  8EFD  get_pin1
 *  8F06  led_off
 *  8F0F  clk_trim_clear
 *  8F18  nibble_map
 *  8F21  mul_wide_call
 *  8F29  uart_prelude
 *  8F31  pin_or_low
 *  8F38  pin1_set_low
 *  8F3E  pin2_set_high
 *  8F44  pin1_set_high
 *  8F4A  nibble_get
 *  8F50  bank_helper
 *  8F59  pin_and_low
 *  8F5D  uart1_read_dr
 *  8F61  uart1_write_dr
 *  8F65  pin_clear
 *  8F68  pin_set
 *  8F6B  cc_ret
 *  8F6E  nop_spin_2
 *  8F71  ret_one
 *  8F74  bank_helper_2
 *  8F77  nop_spin
 *  8F7A  spin_wdt
 *  8F7C  unused_vec_8f7c
 *  8F7D  unused_vec_8f7d
 *  8F7E  unused_vec_8f7e
 *  8F7F  unused_vec_8f7f
 *  8F80  unused_vec_8f80
 *  8F81  unused_vec_8f81
 *  8F82  unused_vec_8f82
 *  8F83  unused_vec_8f83
 *  8F84  unused_vec_8f84
 *  8F85  unused_vec_8f85
 *  8F86  unused_vec_8f86
 *  8F87  unused_vec_8f87
 *  8F88  unused_vec_8f88
 *  8F89  unused_vec_8f89
 *  8F8A  unused_vec_8f8a
 *  8F8B  unused_vec_8f8b
 *  8F8C  unused_vec_8f8c
 *  8F8D  unused_vec_8f8d
 *  8F8E  noop
 *  8F8F  irq_fill_8f8f
 *  8FA0  irq_fill_8fa0
 *  8FA9  uart1_configure
 *  8FB5  irq_fill_8fb5
 *  8FBA  irq_fill_8fba
 *  8FCB  irq_fill_8fcb
 *  8FDC  irq_fill_8fdc
 *  8FED  irq_fill_8fed
 *  8FFE  irq_fill_8ffe
 *  908A  desync_908a
 *  9510  desync_9510
 *  95DE  desync_95de
 *  9780  uart1_set_control_bits
 *  97D3  desync_97d3
 *  9824  desync_9824
 *  9BCF  desync_9bcf
 *  9C31  desync_9c31
 *  9C5B  desync_9c5b
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
  sVar1 = ret_one();
  if (sVar1 != 0) {
    _DAT_03fe = 0x8e50;
    init_walker();
  }
  _DAT_03fe = 0x8e53;
  panel_main_loop();
  bank_helper_2();
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
  
  bank_8b();
  bank_c();
  bVar2 = DAT_0007;
  bVar1 = DAT_0006;
  DAT_000e = save_regs_4();
  DAT_000c = DAT_0004;
  DAT_000d = DAT_0005;
  bVar3 = _DAT_0008 < 9;
  if (_DAT_0008 == 9) {
    bVar3 = _DAT_000a < 0x8969;
  }
  if (!bVar3) {
    trap_setup_e(0x61);
  }
  if ((DAT_000e != 0) && (DAT_000e != 0x10)) {
    trap_setup_e(0x62);
  }
  if ((((DAT_000c != 0) && (DAT_000c != 0x10)) && (DAT_000c != 0x20)) && (DAT_000c != 0x30)) {
    trap_setup_e(99);
  }
  if (((DAT_000d != 0) && (DAT_000d != 4)) && (DAT_000d != 6)) {
    trap_setup_e(100);
  }
  if (((bVar2 != 8) && (bVar2 != 0x40)) &&
     (((bVar2 != 4 && (((bVar2 != 0x80 && (bVar2 != 0xc)) && (bVar2 != 0x44)))) &&
      ((bVar2 != 0xc0 && (bVar2 != 0x88)))))) {
    trap_setup_e(0x65);
  }
  if ((((bVar1 & 0x88) == 0x88) || ((bVar1 & 0x44) == 0x44)) ||
     (((bVar1 & 0x22) == 0x22 || ((bVar1 & 0x11) == 0x11)))) {
    trap_setup_e(0x66);
  }
  UART1_CR1 = UART1_CR1 & 0xef;
  UART1_CR3 = UART1_CR3 & 0xcf | DAT_000c;
  UART1_CR1 = (UART1_CR1 | DAT_000e) & 0xf9 | DAT_000d;
  UART1_BRR1 = 0;
  UART1_BRR2 = 0;
  uart_prelude();
  save_regs_5();
  baud_lookup();
  save_regs_3();
  div_helper();
  uVar4 = display_step();
  baud_lookup((char)uVar4,(ushort)extraout_A << 8 | uVar4 >> 8);
  save_regs_5();
  uVar4 = load_pair_0();
  mul_wide_call((char)uVar4,(ushort)extraout_A_00 << 8 | uVar4 >> 8);
  bank_0b();
  uart_prelude();
  save_regs_4();
  save_regs_1();
  mul_wide_call();
  save_regs_2();
  div_helper();
  save_ptr_1();
  arith_sub();
  reg_write_a(4);
  div_panel_2();
  UART1_BRR2 = DAT_0003 & 0xf | UART1_BRR2;
  shr_4(uStack_3);
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
  save_chain_c();
  return;
}

// FUNC 0x816d  uart_config_tail

/* Ghidra split artifact: starts mid-UART-config (BRR writes). Real entry is uart1_param_check. */

void uart_config_tail(undefined2 param_1,byte param_2,byte param_3)

{
  byte extraout_A;
  byte extraout_A_00;
  ushort uVar1;
  byte extraout_XL;
  
  UART1_BRR2 = 0;
  uart_prelude();
  save_regs_5();
  baud_lookup();
  save_regs_3();
  div_helper();
  uVar1 = display_step();
  baud_lookup((char)uVar1,(ushort)extraout_A << 8 | uVar1 >> 8);
  save_regs_5();
  uVar1 = load_pair_0();
  mul_wide_call((char)uVar1,(ushort)extraout_A_00 << 8 | uVar1 >> 8);
  bank_0b();
  uart_prelude();
  save_regs_4();
  save_regs_1();
  mul_wide_call();
  save_regs_2();
  div_helper();
  save_ptr_1();
  arith_sub();
  reg_write_a();
  div_panel_2();
  UART1_BRR2 = DAT_0003 & 0xf | UART1_BRR2;
  shr_4(param_1);
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
  save_chain_c();
  return;
}

// FUNC 0x8237  arith_sub

void arith_sub(void)

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
  
  puVar1 = (ushort *)identity_2();
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

// FUNC 0x82dc  div_panel

void div_panel(void)

{
  pin_set_call();
  div_helper();
  return;
}

// FUNC 0x82e1  div_panel_2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void div_panel_2(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  char cVar6;
  ushort uVar7;
  ushort uVar8;
  
  pin_set_call_2();
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

// FUNC 0x82e4  div_helper

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void div_helper(void)

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

// FUNC 0x8351  reg_write_a

void reg_write_a(char param_1)

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

// FUNC 0x8362  bank_0

void bank_0(void)

{
  identity_fn_2(0);
  return;
}

// FUNC 0x8367  bank_8

void bank_8(void)

{
  identity_fn_2(8);
  return;
}

// FUNC 0x836c  identity_fn_2

undefined2 identity_fn_2(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x837f  save_ptr

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 save_ptr(undefined2 param_1,undefined2 param_2)

{
  _DAT_0008 = param_2;
  return param_1;
}

// FUNC 0x838e  bank_0b

void bank_0b(void)

{
  identity_fn(0);
  return;
}

// FUNC 0x8393  bank_4

void bank_4(void)

{
  identity_fn(4);
  return;
}

// FUNC 0x8398  bank_8b

void bank_8b(void)

{
  identity_fn(8);
  return;
}

// FUNC 0x839d  bank_c

void bank_c(void)

{
  identity_fn(0xc);
  return;
}

// FUNC 0x83a2  identity_fn

undefined2 identity_fn(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x83bf  save_ptr_0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void save_ptr_0(undefined2 param_1,undefined2 param_2)

{
  _DAT_0000 = param_1;
  _DAT_0002 = param_2;
  stack_ret();
  return;
}

// FUNC 0x83ca  save_ptr_1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void save_ptr_1(undefined2 param_1,undefined2 param_2)

{
  _DAT_0004 = param_1;
  _DAT_0006 = param_2;
  stack_ret();
  return;
}

// FUNC 0x83d5  save_ptr_2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void save_ptr_2(undefined2 param_1,undefined2 param_2)

{
  _DAT_0008 = param_1;
  _DAT_000a = param_2;
  stack_ret();
  return;
}

// FUNC 0x83e0  save_ptr_3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void save_ptr_3(undefined2 param_1,undefined2 param_2)

{
  _DAT_000c = param_1;
  _DAT_000e = param_2;
  stack_ret();
  return;
}

// FUNC 0x83eb  stack_ret

undefined2 stack_ret(void)

{
  undefined2 in_stack_00000001;
  
  return in_stack_00000001;
}

// FUNC 0x83f3  save_chain_c

void save_chain_c(void)

{
  save_ptr_3();
  save_ptr_2();
  return;
}

// FUNC 0x83f6  save_chain_a

void save_chain_a(void)

{
  save_ptr_2();
  return;
}

// FUNC 0x83fa  save_chain_b

void save_chain_b(void)

{
  save_ptr();
  return;
}

// FUNC 0x83fe  save_regs_0

void save_regs_0(void)

{
  DAT_0000 = DAT_0008;
  DAT_0001 = DAT_0009;
  DAT_0002 = DAT_000a;
  DAT_0003 = DAT_000b;
  return;
}

// FUNC 0x840b  save_regs_1

void save_regs_1(void)

{
  DAT_0000 = DAT_000c;
  DAT_0001 = DAT_000d;
  DAT_0002 = DAT_000e;
  DAT_0003 = DAT_000f;
  return;
}

// FUNC 0x8418  save_regs_2

void save_regs_2(void)

{
  DAT_0004 = DAT_0008;
  DAT_0005 = DAT_0009;
  DAT_0006 = DAT_000a;
  DAT_0007 = DAT_000b;
  return;
}

// FUNC 0x8425  save_regs_3

void save_regs_3(void)

{
  DAT_0004 = DAT_000c;
  DAT_0005 = DAT_000d;
  DAT_0006 = DAT_000e;
  DAT_0007 = DAT_000f;
  return;
}

// FUNC 0x8432  save_regs_4

void save_regs_4(void)

{
  DAT_0008 = DAT_0000;
  DAT_0009 = DAT_0001;
  DAT_000a = DAT_0002;
  DAT_000b = DAT_0003;
  return;
}

// FUNC 0x843f  save_regs_5

void save_regs_5(void)

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
  
  pcVar3 = (char *)bank_8b();
  uVar2 = DAT_000c;
  if (pcVar3[9] != '\t') {
    frame_fail();
    return;
  }
  if (*pcVar3 != 'Z') {
    frame_fail();
    return;
  }
  if (pcVar3[8] != -0x12) {
    frame_fail();
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
      save_chain_a();
      return;
    }
  } while( true );
}

// FUNC 0x8508  frame_fail

void frame_fail(undefined1 param_1)

{
  DAT_000c = param_1;
  save_chain_a();
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
  
  _DAT_0008 = (byte *)bank_8b();
  DAT_000b = DAT_0000;
  DAT_000a = extraout_A;
  if (((((DAT_0000 != 0) && (DAT_0000 != 0x40)) && (DAT_0000 != 0x20)) &&
      ((((DAT_0000 != 0x60 && (DAT_0000 != 0xa0)) &&
        ((DAT_0000 != 0xe0 && ((DAT_0000 != 0x80 && (DAT_0000 != 0xc0)))))) && (DAT_0000 != 0xb0))))
     && (((DAT_0000 != 0xf0 && (DAT_0000 != 0x90)) && (DAT_0000 != 0xd0)))) {
    trap_setup_b(0x4d);
  }
  if (DAT_000a == 0) {
    trap_setup_b(0x4e);
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
  save_chain_a();
  return;
}

// FUNC 0x85c1  uart1_cr_bits_checked

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void uart1_cr_bits_checked(void)

{
  undefined1 uVar1;
  char extraout_A;
  
  _DAT_0008 = (undefined *)bank_8();
  uVar1 = DAT_000a;
  DAT_000a = extraout_A;
  if (((((_DAT_0008 != (undefined *)0x100) && (_DAT_0008 != &UNK_0277)) && (_DAT_0008 != &UNK_0266))
      && ((_DAT_0008 != &UNK_0205 && (_DAT_0008 != &UNK_0244)))) && (_DAT_0008 != &UNK_0346)) {
    trap_setup_e(0xd8);
  }
  if ((DAT_000a != '\0') && (DAT_000a != '\x01')) {
    trap_setup_e(0xd9);
  }
  nibble_get(DAT_0009);
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
  save_chain_b();
  return;
}

// FUNC 0x8841  desync_8841

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: RAM */
/* Decompiler desync artifact (SP-relative heap arithmetic). Not a real entry point. */

void desync_8841(byte param_1)

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
  
  bank_8b();
  pin_ctrl_c(0);
  DAT_0000 = 0x3f;
  pin_ctrl_b();
  DAT_0000 = 0x7c;
  pin_ctrl_a();
  pin_ctrl_2();
  DAT_0000 = 1;
  pin_init();
  uart_cr_a();
  uart1_init_115200();
  uart_clear_20();
  led_gpio_init();
  DAT_0000 = 1;
  led_selftest();
  DAT_0000 = 3;
  led_selftest();
  __EnableInterrupt();
  if (DAT_005b != 0) {
    _DAT_000a = &DAT_0058;
    _DAT_0008 = (ushort)DAT_005b;
    do {
      uart1_write_dr(*_DAT_000a);
      do {
        led_off();
      } while ((bool)(extraout_CC >> 1 & 1));
      step_pair();
    } while (!(bool)(extraout_CC_00 >> 1 & 1));
  }
  do {
    if (DAT_0067 != '\0') {
      display_frame_handler(DAT_0067,0x5d);
      display_kick();
      DAT_0067 = '\0';
    }
    pin_ctrl(0x68);
  } while( true );
}

// FUNC 0x89ef  led_state_read

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void led_state_read(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
  _DAT_0008 = (undefined *)bank_8();
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
    trap_setup_e(&UNK_023d);
  }
  bVar1 = DAT_0009 & UART1_SR;
joined_r0x8a4b:
  if (bVar1 != 0) {
    DAT_000a = 1;
  }
  uVar3 = DAT_000a;
  DAT_000a = uVar2;
  save_chain_b(uVar3);
  return;
}

// FUNC 0x8a52  led_selftest

void led_selftest(void)

{
  byte bVar1;
  
  DAT_0009 = bank_8();
  DAT_0008 = DAT_0000;
  if (0x18 < DAT_0009) {
    trap_setup_c(0xe2);
  }
  if ((((DAT_0008 != '\x02') && (DAT_0008 != '\x01')) && (DAT_0008 != '\0')) && (DAT_0008 != '\x03')
     ) {
    trap_setup_c(0xe3);
  }
  bVar1 = cc_ret();
  if ((bVar1 & 0x28) != 0x28) {
    trap_setup_c(0xe6);
  }
  if (((DAT_0009 == 0x11) || (DAT_0009 == 0x12)) || (DAT_0009 == 0x17)) {
    bVar1 = led_shift();
    DAT_7f75 = ~bVar1 & DAT_7f75;
    DAT_0000 = DAT_0001;
    bVar1 = shift_loop_2(DAT_0008);
    DAT_7f75 = bVar1 | DAT_7f75;
  }
  save_chain_b();
  return;
}

// FUNC 0x8ab4  led_pin_table_flash

/* WARNING: Control flow encountered bad instruction data */

void led_pin_table_flash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x8ac3  desync_8ac3

/* WARNING: Control flow encountered bad instruction data */

void desync_8ac3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x8af0  led_nibble_dispatch

undefined2 led_nibble_dispatch(byte param_1,short param_2)

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
  bank_0b(*(undefined2 *)(((ushort)param_1 << 8 | param_2 - 1U >> 8) + 3));
  bank_4();
  bank_8();
  DAT_005c = 10;
  if ((UART1_SR & 8) != 0) {
    UART1_SR = UART1_SR & 0xf7;
    uart1_read_dr();
  }
  DAT_0001 = DAT_0066;
  if (DAT_0066 < 9) {
    DAT_0066 = DAT_0066 + 1;
    DAT_0000 = 0;
    bank_0();
    uVar1 = uart1_read_dr();
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
    uart1_read_dr();
  }
  *(undefined2 *)((short)register0x0008 + -1) = 0x8b5b;
  save_ptr();
  *(undefined2 *)((short)register0x0008 + -1) = 0x8b5e;
  save_ptr_1();
  *(undefined2 *)((short)register0x0008 + -1) = 0x8b61;
  save_ptr_0();
  return *(undefined2 *)((short)register0x0008 + 3);
}

// FUNC 0x8b0c  vec_8b0c_isr

undefined2 vec_8b0c_isr(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  short in_stack_00000001;
  
  bank_0b();
  bank_4();
  bank_8();
  DAT_005c = 10;
  if ((UART1_SR & 8) != 0) {
    UART1_SR = UART1_SR & 0xf7;
    uart1_read_dr();
  }
  DAT_0001 = DAT_0066;
  if (DAT_0066 < 9) {
    DAT_0066 = DAT_0066 + 1;
    DAT_0000 = 0;
    bank_0();
    uVar1 = uart1_read_dr();
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
    uart1_read_dr();
  }
  *(undefined2 *)((short)register0x0008 + -1) = 0x8b5b;
  save_ptr();
  *(undefined2 *)((short)register0x0008 + -1) = 0x8b5e;
  save_ptr_1();
  *(undefined2 *)((short)register0x0008 + -1) = 0x8b61;
  save_ptr_0();
  return *(undefined2 *)((short)register0x0008 + 3);
}

// FUNC 0x8b62  load_pair_0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * load_pair_0(void)

{
  undefined2 *puVar1;
  byte *in_stack_00000001;
  
  puVar1 = (undefined2 *)(&stack0x0002 + *in_stack_00000001);
  _DAT_0000 = *puVar1;
  _DAT_0002 = puVar1[1];
  return puVar1;
}

// FUNC 0x8b72  load_pair_1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * load_pair_1(undefined2 *param_1)

{
  _DAT_0000 = *param_1;
  _DAT_0002 = param_1[1];
  return param_1;
}

// FUNC 0x8b7e  load_pair_2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * load_pair_2(undefined2 *param_1)

{
  _DAT_0004 = *param_1;
  _DAT_0006 = param_1[1];
  return param_1;
}

// FUNC 0x8b8a  display_step

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void display_step(void)

{
  byte bVar1;
  byte *in_stack_00000001;
  
  bVar1 = *in_stack_00000001;
  *(undefined2 *)(&stack0x0002 + bVar1) = _DAT_0000;
  *(undefined2 *)(&stack0x0004 + bVar1) = _DAT_0002;
  return;
}

// FUNC 0x8ba9  baud_lookup

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void baud_lookup(void)

{
  if (CLK_CMSR == -0x1f) {
    _DAT_0006 = (ushort)(byte)bank_helper[(CLK_CKDIVR >> 3 & 0xff03) + 5];
    _DAT_0004 = 0;
    div_panel();
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

// FUNC 0x8be4  pin_ctrl_a

void pin_ctrl_a(void)

{
  DAT_0008 = bank_8();
  DAT_0009 = DAT_0000;
  if (((((DAT_0008 != '\0') && (DAT_0008 != '\x01')) && (DAT_0008 != '\x02')) &&
      ((DAT_0008 != '\x03' && (DAT_0008 != '\x04')))) &&
     ((DAT_0008 != '\x05' && ((DAT_0008 != '\x06' && (DAT_0008 != '\a')))))) {
    trap_setup_d(0x44);
  }
  TIM4_EGR = DAT_0008;
  TIM4_CNTR = DAT_0009;
  save_chain_b();
  return;
}

// FUNC 0x8c1e  pin_init

void pin_init(void)

{
  DAT_0009 = bank_8();
  DAT_0008 = DAT_0000;
  if (DAT_0009 != 1) {
    trap_setup_d(0x6e);
  }
  if (DAT_0008 == '\0') {
    DAT_0009 = ~DAT_0009;
    TIM4_ETR = DAT_0009 & TIM4_ETR;
  }
  else {
    if (DAT_0008 != '\x01') {
      trap_setup_d(0x6f);
    }
    TIM4_ETR = TIM4_ETR | DAT_0009;
  }
  save_chain_b();
  return;
}

// FUNC 0x8c31  display_wait

void display_wait(void)

{
  byte in_CC;
  
  if ((bool)(in_CC >> 1 & 1)) {
    DAT_0009 = ~DAT_0009;
    TIM4_ETR = DAT_0009 & TIM4_ETR;
  }
  else {
    if (DAT_0008 != '\x01') {
      trap_setup_d(0x6f);
    }
    TIM4_ETR = TIM4_ETR | DAT_0009;
  }
  save_chain_b();
  return;
}

// FUNC 0x8c52  led_gpio_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* LED GPIO init. Iterates _DAT_0008=0x0010 with DAT_000a=0x18 (24 pins), calls sub_8510 with mode
   0xF0. */

void led_gpio_init(void)

{
  undefined1 uVar1;
  
  bank_8();
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
  save_chain_b();
  return;
}

// FUNC 0x8c81  uart_brr_clear

undefined1 uart_brr_clear(void)

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

// FUNC 0x8cac  pin_ctrl_b

void pin_ctrl_b(void)

{
  DAT_0008 = bank_8();
  DAT_0009 = DAT_0000;
  if (0x7f < DAT_0000) {
    trap_setup_f(0x38);
  }
  WWDG_CR = DAT_0008 | 0xc0;
  WWDG_WR = DAT_0009 & 0x7f | 0x40;
  save_chain_b();
  return;
}

// FUNC 0x8cd6  pin_ctrl_c

void pin_ctrl_c(byte param_1)

{
  undefined1 uVar1;
  
  uVar1 = DAT_0008;
  DAT_0008 = param_1;
  if ((((param_1 != 0) && (param_1 != 8)) && (param_1 != 0x10)) && (param_1 != 0x18)) {
    trap_setup_a(&UNK_01a2);
  }
  clk_trim_clear();
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
  uart_brr_clear();
  DAT_0007 = 0xc;
  DAT_0006 = 0x80;
  DAT_0005 = 0;
  DAT_0004 = 0;
  _DAT_0002 = 0xc200;
  _DAT_0000 = 1;
  uart1_param_check(0);
  uart1_cr_bits_checked(1,&UNK_0205);
  return 1;
}

// FUNC 0x8d4d  vec_8d4d_isr

undefined2 vec_8d4d_isr(undefined2 param_1)

{
  bank_0b();
  bank_4();
  if ((DAT_005c != '\0') && (DAT_005c = DAT_005c + -1, DAT_005c == '\0')) {
    DAT_0067 = 1;
  }
  pin_ctrl_3(1);
  save_ptr_1();
  save_ptr_0();
  return param_1;
}

// FUNC 0x8d74  pin_set_call

void pin_set_call(undefined2 param_1)

{
  load_pair_1(param_1);
  return;
}

// FUNC 0x8d81  pin_set_call_2

void pin_set_call_2(undefined2 param_1)

{
  load_pair_2(param_1);
  return;
}

// FUNC 0x8d8e  identity_2

undefined2 identity_2(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8da3  pin_ctrl

void pin_ctrl(byte param_1)

{
  undefined1 uVar1;
  
  uVar1 = DAT_0008;
  DAT_0008 = param_1;
  if (0x7f < param_1) {
    trap_setup_f(0x48);
  }
  WWDG_CR = DAT_0008 & 0x7f;
  DAT_0008 = uVar1;
  return;
}

// FUNC 0x8dbd  pin_ctrl_2

void pin_ctrl_2(byte param_1)

{
  undefined1 uVar1;
  
  uVar1 = DAT_0008;
  DAT_0008 = param_1;
  if (param_1 != 1) {
    trap_setup_d(&UNK_015b);
  }
  DAT_0008 = ~DAT_0008;
  TIM4_IER = DAT_0008;
  DAT_0008 = uVar1;
  return;
}

// FUNC 0x8dd6  pin_ctrl_3

void pin_ctrl_3(byte param_1)

{
  undefined1 uVar1;
  
  uVar1 = DAT_0008;
  DAT_0008 = param_1;
  if (param_1 != 1) {
    trap_setup_d(&UNK_018a);
  }
  DAT_0008 = ~DAT_0008;
  TIM4_IER = DAT_0008;
  DAT_0008 = uVar1;
  return;
}

// FUNC 0x8def  uart_cr_a

void uart_cr_a(char param_1)

{
  if (param_1 != '\0') {
    if (param_1 != '\x01') {
      trap_setup_d(0x54);
    }
    TIM4_CR1 = TIM4_CR1 | 1;
    return;
  }
  TIM4_CR1 = TIM4_CR1 & 0xfe;
  return;
}

// FUNC 0x8e05  addr_lookup

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * addr_lookup(undefined1 *param_1)

{
  undefined1 in_YL;
  
  _DAT_0002 = param_1;
  for (; _DAT_0000 != 0; _DAT_0000 = _DAT_0000 + -1) {
    *param_1 = in_YL;
    param_1 = param_1 + 1;
  }
  return _DAT_0002;
}

// FUNC 0x8e1b  init_walker

void init_walker(void)

{
  code *pcVar1;
  
  for (pcVar1 = (code *)&DAT_8d99; pcVar1 != pin_ctrl; pcVar1 = (code *)func_0x0000eb80(pcVar1 + 2))
  {
  }
  return;
}

// FUNC 0x8e2f  reg_read_a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void reg_read_a(void)

{
  undefined1 uStack_1;
  
  _DAT_0008 = bank_8();
  do {
    noop(1,&uStack_1);
  } while( true );
}

// FUNC 0x8e43  reset_chain

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void reset_chain(void)

{
  short sVar1;
  
  _DAT_03fe = 0x8e4a;
  sVar1 = ret_one();
  if (sVar1 != 0) {
    _DAT_03fe = 0x8e50;
    init_walker();
  }
  _DAT_03fe = 0x8e53;
  panel_main_loop();
  bank_helper_2();
  return;
}

// FUNC 0x8e56  led_shift

void led_shift(void)

{
  DAT_0000 = (DAT_0009 & 3) << 1;
  DAT_0001 = DAT_0000;
  shift_loop_2(3);
  return;
}

// FUNC 0x8e65  display_kick

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void display_kick(void)

{
  _DAT_0000 = 10;
  addr_lookup(0x5d);
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

// FUNC 0x8e8c  uart_clear_20

void uart_clear_20(char param_1)

{
  if (param_1 != '\0') {
    UART1_CR1 = UART1_CR1 & 0xdf;
    return;
  }
  UART1_CR1 = UART1_CR1 | 0x20;
  return;
}

// FUNC 0x8e99  shift_loop

void shift_loop(char param_1)

{
  if (param_1 != '\0') {
    do {
      param_1 = param_1 + -1;
    } while (param_1 != '\0');
  }
  return;
}

// FUNC 0x8ea1  shr_4

ushort shr_4(ushort param_1)

{
  return param_1 >> 4;
}

// FUNC 0x8ea6  step_pair

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void step_pair(void)

{
  _DAT_000a = _DAT_000a + 1;
  _DAT_0008 = _DAT_0008 + -1;
  return;
}

// FUNC 0x8eb1  trap_setup_a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void trap_setup_a(undefined2 param_1)

{
  _DAT_0000 = 0;
  _DAT_0002 = param_1;
  spin_wdt(0x8867);
  return;
}

// FUNC 0x8ebc  trap_setup_b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void trap_setup_b(undefined2 param_1)

{
  _DAT_0000 = 0;
  _DAT_0002 = param_1;
  spin_wdt(s_E__eaton_projects_guangzhou_weim_86db);
  return;
}

// FUNC 0x8ec7  trap_setup_c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void trap_setup_c(undefined2 param_1)

{
  _DAT_0000 = 0;
  _DAT_0002 = param_1;
  spin_wdt(0x88ea);
  return;
}

// FUNC 0x8ed2  trap_setup_d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void trap_setup_d(undefined2 param_1)

{
  _DAT_0000 = 0;
  _DAT_0002 = param_1;
  spin_wdt(s_E__eaton_projects_guangzhou_weim_875f);
  return;
}

// FUNC 0x8edd  trap_setup_e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void trap_setup_e(undefined2 param_1)

{
  _DAT_0000 = 0;
  _DAT_0002 = param_1;
  spin_wdt(s_E__eaton_projects_guangzhou_weim_8656);
  return;
}

// FUNC 0x8ee8  trap_setup_f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void trap_setup_f(undefined2 param_1)

{
  _DAT_0000 = 0;
  _DAT_0002 = param_1;
  spin_wdt(0x87e3);
  return;
}

// FUNC 0x8ef3  shift_loop_2

void shift_loop_2(void)

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

// FUNC 0x8f06  led_off

void led_off(void)

{
  led_state_read(0x80);
  return;
}

// FUNC 0x8f0f  clk_trim_clear

void clk_trim_clear(void)

{
  CLK_CKDIVR = CLK_CKDIVR & 0xe7;
  return;
}

// FUNC 0x8f18  nibble_map

undefined1 nibble_map(byte param_1)

{
  undefined1 uVar1;
  
  uVar1 = shift_loop(param_1 & 0xf,1);
  return uVar1;
}

// FUNC 0x8f21  mul_wide_call

void mul_wide_call(void)

{
  mul_wide();
  return;
}

// FUNC 0x8f29  uart_prelude

void uart_prelude(void)

{
  save_regs_0();
  reg_write_a(4);
  return;
}

// FUNC 0x8f31  pin_or_low

void pin_or_low(byte param_1,byte *param_2)

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

// FUNC 0x8f4a  nibble_get

void nibble_get(void)

{
  DAT_0000 = nibble_map();
  return;
}

// FUNC 0x8f50  bank_helper

void bank_helper(undefined2 param_1)

{
  byte extraout_A;
  byte *pbVar1;
  
  pbVar1 = (byte *)reg_read_a(param_1);
  *pbVar1 = ~extraout_A & *pbVar1;
  return;
}

// FUNC 0x8f59  pin_and_low

void pin_and_low(byte param_1,byte *param_2)

{
  *param_2 = ~param_1 & *param_2;
  return;
}

// FUNC 0x8f5d  uart1_read_dr

undefined1 uart1_read_dr(void)

{
  return UART1_DR;
}

// FUNC 0x8f61  uart1_write_dr

void uart1_write_dr(undefined1 param_1)

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

// FUNC 0x8f6b  cc_ret

undefined1 cc_ret(void)

{
  undefined1 in_CC;
  
  return in_CC;
}

// FUNC 0x8f6e  nop_spin_2

void nop_spin_2(void)

{
  do {
    __Nop();
  } while( true );
}

// FUNC 0x8f71  ret_one

undefined2 ret_one(void)

{
  return 1;
}

// FUNC 0x8f74  bank_helper_2

void bank_helper_2(undefined2 param_1)

{
  byte extraout_A;
  byte *pbVar1;
  
  pbVar1 = (byte *)reg_read_a(param_1);
  *pbVar1 = ~extraout_A & *pbVar1;
  return;
}

// FUNC 0x8f77  nop_spin

void nop_spin(void)

{
  do {
    __Nop();
  } while( true );
}

// FUNC 0x8f7a  spin_wdt

void spin_wdt(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x8f7c  unused_vec_8f7c

undefined2 unused_vec_8f7c(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f7d  unused_vec_8f7d

undefined2 unused_vec_8f7d(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f7e  unused_vec_8f7e

undefined2 unused_vec_8f7e(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f7f  unused_vec_8f7f

undefined2 unused_vec_8f7f(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f80  unused_vec_8f80

undefined2 unused_vec_8f80(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f81  unused_vec_8f81

undefined2 unused_vec_8f81(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f82  unused_vec_8f82

undefined2 unused_vec_8f82(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f83  unused_vec_8f83

undefined2 unused_vec_8f83(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f84  unused_vec_8f84

undefined2 unused_vec_8f84(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f85  unused_vec_8f85

undefined2 unused_vec_8f85(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f86  unused_vec_8f86

undefined2 unused_vec_8f86(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f87  unused_vec_8f87

undefined2 unused_vec_8f87(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f88  unused_vec_8f88

undefined2 unused_vec_8f88(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f89  unused_vec_8f89

undefined2 unused_vec_8f89(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f8a  unused_vec_8f8a

undefined2 unused_vec_8f8a(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f8b  unused_vec_8f8b

undefined2 unused_vec_8f8b(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f8c  unused_vec_8f8c

undefined2 unused_vec_8f8c(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f8d  unused_vec_8f8d

undefined2 unused_vec_8f8d(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x8f8e  noop

void noop(void)

{
  return;
}

// FUNC 0x8f8f  irq_fill_8f8f

/* WARNING: Control flow encountered bad instruction data */

void irq_fill_8f8f(undefined2 *param_1)

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

// FUNC 0x8fa0  irq_fill_8fa0

/* WARNING: Control flow encountered bad instruction data */

void irq_fill_8fa0(undefined2 *param_1)

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

// FUNC 0x8fb5  irq_fill_8fb5

/* WARNING: Control flow encountered bad instruction data */

void irq_fill_8fb5(undefined2 *param_1)

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

// FUNC 0x8fba  irq_fill_8fba

/* WARNING: Control flow encountered bad instruction data */

void irq_fill_8fba(undefined2 *param_1)

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

// FUNC 0x8fcb  irq_fill_8fcb

/* WARNING: Control flow encountered bad instruction data */

void irq_fill_8fcb(undefined2 *param_1)

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

// FUNC 0x8fdc  irq_fill_8fdc

/* WARNING: Control flow encountered bad instruction data */

void irq_fill_8fdc(undefined2 *param_1)

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

// FUNC 0x8fed  irq_fill_8fed

/* WARNING: Control flow encountered bad instruction data */

void irq_fill_8fed(undefined2 *param_1)

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

// FUNC 0x8ffe  irq_fill_8ffe

/* WARNING: Control flow encountered bad instruction data */

void irq_fill_8ffe(undefined2 *param_1)

{
  undefined2 in_Y;
  
  *param_1 = in_Y;
  *param_1 = in_Y;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x908a  desync_908a

/* WARNING: Control flow encountered bad instruction data */
/* Decompiler desync artifact (bad instruction / 0xFF filler). */

void desync_908a(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9510  desync_9510

/* WARNING: Control flow encountered bad instruction data */
/* Decompiler desync artifact (bad instruction / 0xFF filler). */

void desync_9510(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x95de  desync_95de

/* WARNING: Control flow encountered bad instruction data */

void desync_95de(void)

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

// FUNC 0x97d3  desync_97d3

/* WARNING: Control flow encountered bad instruction data */

void desync_97d3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9824  desync_9824

/* WARNING: Control flow encountered bad instruction data */

void desync_9824(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9bcf  desync_9bcf

/* WARNING: Control flow encountered bad instruction data */

void desync_9bcf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9c31  desync_9c31

/* WARNING: Control flow encountered bad instruction data */

void desync_9c31(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9c5b  desync_9c5b

/* WARNING: Control flow encountered bad instruction data */

void desync_9c5b(void)

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

