/*
 * Roadshock 8-Gang switch panel - base board firmware
 * STM8S003F3P6, 8 KB flash @ 0x8000, 1 KB RAM
 *
 * Reconstructed from the corrected dump (sha256
 * a730e8b0bd32861a02fdfd75ada5a78f632b85e54de8cb0b6a3d2d85f1dcef62)
 * with Ghidra 11.3.1 + STM8 SLEIGH (STM8:BE:16, base 0x8000),
 * project Roadstm8true. 256/256 functions decompiled.
 *
 * This is decompiler output, not original source. Types are
 * approximate. Reading order: the function index first, then each
 * function in address order. Names marked here (uart1_configure,
 * uart1_init_2400, mode_handler, frame_handler, cmd_0b_handler,
 * cmd_0d_handler, cmd_19_handler, config_mode_handler, etc.) were
 * assigned from call sites and confirmed against assembly; see
 * tools/ghidra/build_project.py and docs/mode_timing.md,
 * docs/hidden_commands.md. Generic names
 * (sub_*, FUN_*, gap_*, vec_*) are Ghidra defaults for code that has
 * not been given a role yet.
 *
 * Data consumed directly from the driver regions is in flash at
 * 0x9E85 (nibble table), 0x9AA8 (pin descriptor table), and the
 * panel pin table at 0x8AB4. Ghidra 11.3.1 decompilation is the source
 * of truth; cross-check against asm/base.lst and captures/.
 */

/* ---- function index -------------------------------
 *  addr  name
 *  8000  VEC00_RESET
 *  8080  message_post_loop
 *  8112  channel_ptr_4
 *  8118  channel_ptr_3
 *  811E  mode_convert
 *  8146  config_mode_handler
 *  816D  mode_handler
 *  81CD  mode_dispatch_tail
 *  828D  channel_state_write
 *  828E  channel_step_b
 *  82A8  tim2_path_set
 *  82AA  tim2_path_set_b
 *  82B3  button_bitmask_handler
 *  833B  mode_apply_block
 *  845D  channel_state_write_b
 *  845E  channel_step
 *  8480  channel_ptr_2
 *  8485  channel_pair_get
 *  848B  channel_index_get
 *  8490  set_6
 *  8495  pin_table_ptrs
 *  84A5  flag_init_pair
 *  84B3  mode_off_entry
 *  84B9  toggle_head
 *  84C5  mode_head
 *  84CC  mode_off_prelude
 *  84D5  flag_clear_pair
 *  84E4  flag_set_1
 *  8504  channel_advance
 *  851A  frame_handler
 *  85E6  eeprom_flush
 *  860C  cmd_19_handler
 *  8640  cmd_0b_handler
 *  8689  cmd_0d_handler
 *  86A6  eeprom_flush
 *  86AB  post_if_ff
 *  86C2  post_dispatch
 *  86C8  noop_c
 *  86CB  msg_post
 *  86D1  msg_next
 *  86D3  dat_0002_ret
 *  86D8  msg_peek
 *  86DF  reset_state
 *  86E8  eeprom_sequencer
 *  8700  mode_tick
 *  8811  noop_2
 *  8814  tick_b
 *  881C  tick_c
 *  8828  bank_prelude
 *  8841  state_dispatch
 *  8A15  msg_alloc_loop
 *  8A46  param_block_apply
 *  8B5D  state_step
 *  8B6E  msg_step
 *  8B71  to_button_frame
 *  8B79  index_add_7
 *  8B8A  index_set
 *  8B8E  channel_index_set
 *  8B96  button_frame_builder
 *  8C31  idle_reply_builder
 *  8D00  noop_d
 *  8D03  counter_inc
 *  8D16  arith_sub
 *  8D31  mul_wide
 *  8DBB  div_path
 *  8DC0  div_small
 *  8DC3  div_helper
 *  8E30  noop
 *  8E40  reg_snapshot
 *  8E51  init_pair
 *  8E5C  system_init
 *  8EE6  link_service_loop
 *  8F7E  uart1_configure
 *  8FB5  uart1_configure_ex
 *  908A  bank_0_call
 *  908F  bank_post_8
 *  9094  bank_post_c
 *  9099  bank_fn_9099
 *  90AC  frame_push_0
 *  90B3  frame_push_1
 *  90BA  stack_ret
 *  90C2  bank_set_0
 *  90C7  bank_set_4
 *  90CC  bank_set_8
 *  90D1  bank_set_c
 *  90D6  identity_fn
 *  90F3  save_pair_0
 *  90FE  save_pair_1
 *  9109  save_pair_2
 *  9114  save_pair_3
 *  911F  stack_ret_2
 *  9127  save_regs_2
 *  912A  save_pair_2w
 *  912E  save_regs_chain
 *  9135  frame_push_call
 *  9139  save_regs_0
 *  9140  save_regs_1
 *  9147  save_ptr_0
 *  9154  save_ptr_1
 *  9161  save_ptr_2
 *  916E  save_ptr_3
 *  917B  state_table_init
 *  9223  acc_sense_sample
 *  92C2  channels_apply
 *  935E  tx_queue_drain
 *  93E5  clk_switch
 *  9464  clk_set_divider
 *  94D6  outputs_init
 *  9541  gpio_init
 *  95A5  get_arg_ptr
 *  95B5  load_pair_0
 *  95C1  load_pair_1
 *  95CD  get_arg_ptr_2
 *  95DE  store_pair_0
 *  95EC  store_pair_1
 *  95FA  store_pair_2
 *  9608  tim4_isr
 *  966A  itc_spr_write
 *  96CB  itc_set_priority
 *  9728  uart1_cr_write
 *  9780  uart1_set_control_bits
 *  97D3  uart1_rx_isr
 *  9823  mode_remap
 *  9872  pin_table_apply
 *  98B6  baud_lookup
 *  98F1  clk_gate_enable_1
 *  9927  eeprom_write
 *  995A  mem_compare
 *  998A  tx_index
 *  99B6  mul_small
 *  99D4  shift_loop
 *  99DC  shr_4
 *  99E1  ext0_pa1_isr
 *  9A0B  tim4_reset
 *  9A34  block_move
 *  9A5C  bad_code_9a5c
 *  9A84  queue_scan
 *  9AAA  load_a
 *  9AB7  load_b
 *  9AC4  identity_2
 *  9ACF  eeprom_rd_a
 *  9AF3  state_clear
 *  9B17  uart1_init_2400
 *  9B3A  boot_chain
 *  9B72  pa_outputs_init
 *  9B92  block_copy
 *  9BCF  reg_clear_a
 *  9BEB  tim2_ier_write
 *  9C03  tim4_etr_write
 *  9C1B  flash_key_dispatch
 *  9C31  memset_like
 *  9C47  init_walker
 *  9C5B  frame_get
 *  9C6F  msg_alloc
 *  9C76  flash_write_key_ae
 *  9C82  flash_write_key_56
 *  9C95  iwdg_setup
 *  9CA7  flash_unlock
 *  9CB8  poll_busy
 *  9CC8  shl_loop
 *  9CD2  shl_6
 *  9CD8  reset_startup
 *  9CE7  seq_alloc_3
 *  9CF6  byte_store_inc
 *  9D05  bit_scan_a
 *  9D14  bit_scan_b
 *  9D23  flash_and_505a
 *  9D32  pack_pair
 *  9D40  clk_enable_b
 *  9D4E  clk_reg_a
 *  9D5C  clk_enable_a
 *  9D69  clk_shift
 *  9D76  tim2_enable
 *  9D83  tim2_cr1_or_80
 *  9D90  tim4_enable
 *  9D9D  uart1_clear_20
 *  9DAA  clk_gate_enable_2
 *  9DB7  inc_pair
 *  9DC3  ptr_02c4
 *  9DCF  seq_save
 *  9DDA  flash_and_505f
 *  9DE5  eeprom_ofs
 *  9DEF  tim4_init
 *  9DF9  seq_inc
 *  9E03  block_copy_7
 *  9E05  block_copy_7b
 *  9E0D  seq_alloc
 *  9E17  addr_plus_10
 *  9E21  flag1_clear2
 *  9E2B  eeprom_init_a
 *  9E34  load_000c
 *  9E3D  channel_ptr_5_store
 *  9E40  channel_ptr_5
 *  9E46  sum_add
 *  9E4F  clk_trim_clear
 *  9E58  itc_clear
 *  9E61  pin_bit_a
 *  9E6A  pin_bit_b
 *  9E73  tim4_egr_set
 *  9E7C  nibble_map
 *  9E85  noop_e
 *  9E8D  noop_3
 *  9E95  poll_and_load
 *  9E9D  mul_wide_call
 *  9EA5  byte_store_off24
 *  9EAC  clk_gate_enable_3
 *  9EB3  poll_call
 *  9EBA  pin_or
 *  9EC1  tim2_set_ccr1l
 *  9EC8  noop_4
 *  9ECF  tim4_clear_egr
 *  9ED6  tx_index_ret
 *  9EDC  iwdg_refresh
 *  9EE1  iwdg_kick_cc
 *  9EE6  tim2_sr1_clear
 *  9EEB  tim4_ier_set
 *  9EF0  tim4_ier_set_2
 *  9EF5  table_lookup
 *  9EFE  block_copy_call
 *  9F02  seq_alloc_2
 *  9F06  tim2_off
 *  9F0A  store_0002
 *  9F0E  load_0002
 *  9F12  pin_and
 *  9F16  iwdg_kr_write
 *  9F1A  iwdg_pr_write
 *  9F1E  iwdg_rlr_write
 *  9F22  uart1_dr_read
 *  9F26  uart1_dr_write
 *  9F2A  pin_and
 *  9F2D  pin_or
 *  9F30  nop_spin_a
 *  9F33  ret_one
 *  9F36  iwdg_reload
 *  9F39  nop_spin
 *  9F3C  unused_vec_9f3c
 *  9F3D  iwdg_start
 *  9F3E  unused_vec_9f3e
 *  9F3F  unused_vec_9f3f
 *  9F40  unused_vec_9f40
 *  9F41  unused_vec_9f41
 *  9F42  unused_vec_9f42
 *  9F43  unused_vec_9f43
 *  9F44  unused_vec_9f44
 *  9F45  unused_vec_9f45
 *  9F46  unused_vec_9f46
 *  9F47  unused_vec_9f47
 *  9F48  unused_vec_9f48
 *  9F49  unused_vec_9f49
 *  9F4A  unused_vec_9f4a
 *  9F4B  noop_f
 *  9F4C  unused_irq_vec_9f4c
 *  9F5D  unused_irq_vec_9f5d
 *  9F6E  unused_irq_vec_9f6e
 *  9F7F  unused_irq_vec_9f7f
 *  9F90  unused_irq_vec_9f90
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
  
  _DAT_03fe = 0x9c89;
  sVar1 = ret_one();
  if (sVar1 != 0) {
    _DAT_03fe = 0x9c8f;
    init_walker();
  }
  _DAT_03fe = 0x9c92;
  system_init();
  iwdg_reload();
  return;
}

// FUNC 0x8080  message_post_loop

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void message_post_loop(void)

{
  undefined1 uVar1;
  byte extraout_CC;
  undefined1 extraout_A;
  undefined1 extraout_A_00;
  undefined1 uVar2;
  undefined1 *puVar3;
  
  bank_post_8();
  DAT_0004 = bank_post_c();
  uVar1 = DAT_000a._0_1_;
  DAT_0002._1_1_ = DAT_0000;
  DAT_0005 = DAT_0001;
  DAT_000a._0_1_ = DAT_0002._0_1_;
  _DAT_0006 = CONCAT11(DAT_0006,DAT_02ce);
  do {
    if (9 < DAT_0007) break;
    _DAT_0006 = _DAT_0006 & 0xff;
    msg_post();
    puVar3 = (undefined1 *)flash_write_key_ae(_DAT_0006);
    if ((bool)(extraout_CC >> 1 & 1)) {
      *puVar3 = 1;
      _DAT_0000 = (undefined2 *)(puVar3 + 1);
      *_DAT_0000 = 0;
      puVar3 = (undefined1 *)channel_ptr_3(DAT_0005);
      *puVar3 = extraout_A;
      DAT_000c = channel_ptr_4();
      puVar3 = (undefined1 *)channel_ptr_5_store(DAT_0004);
      *puVar3 = extraout_A_00;
      clk_gate_enable_3((undefined1)DAT_0002);
      _DAT_0000 = (undefined2 *)(ushort)DAT_000a._0_1_;
      block_copy_call();
      uVar2 = poll_busy(DAT_000a._0_1_ + 3,DAT_000c);
      _DAT_0000 = (undefined2 *)CONCAT11(uVar2,DAT_0001);
      *(undefined1 *)((ushort)DAT_000a._0_1_ + DAT_0008 + 7) = uVar2;
      byte_store_off24(DAT_000a._0_1_ + 4);
      break;
    }
    DAT_0007 = DAT_0007 + 1;
    if (9 < DAT_0007) {
      DAT_0007 = 0;
    }
  } while (DAT_02ce != DAT_0007);
  DAT_000a._0_1_ = uVar1;
  frame_push_1();
  frame_push_call();
  return;
}

// FUNC 0x8112  channel_ptr_4

short channel_ptr_4(void)

{
  return DAT_0008 + 4;
}

// FUNC 0x8118  channel_ptr_3

short channel_ptr_3(void)

{
  return DAT_0008 + 3;
}

// FUNC 0x811e  mode_convert

char mode_convert(char param_1)

{
  if (param_1 == '\x01') {
    DAT_0000 = '\0';
  }
  else if (param_1 == '\x03') {
    DAT_0000 = '\x02';
  }
  else if (param_1 == '\x05') {
    DAT_0000 = '\x04';
  }
  else {
    DAT_0000 = param_1;
    if (param_1 == '\a') {
      set_6();
    }
  }
  return DAT_0000;
}

// FUNC 0x8146  config_mode_handler

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Type-7 config mode handler (Roadstm8true, 2026-11-09).
   Called from frame_handler with 12 nibbles (abStack_b) expanded from the 6-byte payload.
   Copies the block via sub_9b92, then loops calling mode_handler logic per channel.
   See docs/hidden_commands.md. */

void config_mode_handler(void)

{
  undefined1 uVar1;
  byte extraout_CC;
  byte extraout_CC_00;
  byte extraout_CC_01;
  byte extraout_CC_02;
  byte extraout_CC_03;
  byte extraout_CC_04;
  byte extraout_CC_05;
  byte extraout_CC_06;
  byte extraout_CC_07;
  byte extraout_CC_08;
  char *pcVar2;
  short sVar3;
  byte *pbVar4;
  short in_Y;
  char acStack_e [12];
  short sStack_2;
  
  bank_set_8();
  bank_post_c();
  uVar1 = DAT_000e;
  DAT_0001 = 0xc;
  DAT_0000 = '\0';
  sStack_2 = in_Y;
  block_copy(acStack_e);
  DAT_000e = 0;
  pcVar2 = acStack_e;
  pin_table_ptrs();
  tim2_path_set();
  if ((!(bool)(extraout_CC >> 1 & 1)) && ((DAT_000e == 0 || (DAT_000e == 4)))) {
    DAT_0000 = acStack_e[0];
    if (acStack_e[0] == '\x01') {
      DAT_0000 = '\0';
    }
    else if (acStack_e[0] == '\x03') {
      DAT_0000 = '\x02';
    }
    else if (acStack_e[0] == '\x05') {
      DAT_0000 = '\x04';
    }
    else if (acStack_e[0] == '\a') {
      pcVar2 = (char *)set_6();
    }
    *pcVar2 = DAT_0000;
  }
  if (acStack_e[0] == '\0') {
    mode_off_entry();
    if (!(bool)(extraout_CC_00 >> 1 & 1)) {
      channel_step_b();
      return;
    }
    sVar3 = channel_pair_get();
    *(undefined1 *)(sVar3 + sStack_2) = 0;
    channel_step_b();
    return;
  }
  if (acStack_e[0] == '\x01') {
    sVar3 = toggle_head();
    pbVar4 = (byte *)channel_index_get(sVar3 + sStack_2);
    if ((bool)(extraout_CC_01 >> 1 & 1)) {
      channel_state_write(0x10);
      return;
    }
    channel_state_write(*pbVar4 | 1);
    return;
  }
  if (acStack_e[0] == '\x02') {
    sVar3 = mode_head();
    pbVar4 = (byte *)channel_index_get(sVar3 + sStack_2);
    if ((bool)(extraout_CC_02 >> 1 & 1)) {
      channel_state_write(0x20);
      return;
    }
    channel_state_write(*pbVar4 | 2);
    return;
  }
  if (acStack_e[0] == '\x03') {
    sVar3 = toggle_head();
    pbVar4 = (byte *)channel_index_get(sVar3 + sStack_2);
    if ((bool)(extraout_CC_03 >> 1 & 1)) {
      channel_state_write(0x30);
      return;
    }
    channel_state_write(*pbVar4 | 3);
    return;
  }
  if (acStack_e[0] == '\x04') {
    sVar3 = mode_head();
    pbVar4 = (byte *)channel_index_get(sVar3 + sStack_2);
    if ((bool)(extraout_CC_04 >> 1 & 1)) {
      channel_state_write(0x40);
      return;
    }
    channel_state_write(*pbVar4 | 4);
    return;
  }
  if (acStack_e[0] == '\x05') {
    *DAT_000c = 0;
    if (*DAT_0008 == '\0') {
      flag_set_1();
    }
    sVar3 = channel_pair_get();
    pbVar4 = (byte *)channel_index_get(sVar3 + sStack_2);
    if ((bool)(extraout_CC_05 >> 1 & 1)) {
      channel_state_write(0x50);
      return;
    }
    channel_state_write(*pbVar4 | 5);
    return;
  }
  if (acStack_e[0] == '\x06') {
    sVar3 = mode_head();
    pbVar4 = (byte *)channel_index_get(sVar3 + sStack_2);
    if ((bool)(extraout_CC_06 >> 1 & 1)) {
      channel_state_write(0x60);
      return;
    }
    channel_state_write(*pbVar4 | 6);
    return;
  }
  if (acStack_e[0] == '\a') {
    sVar3 = flag_init_pair();
    pbVar4 = (byte *)channel_index_get(sVar3 + sStack_2);
    if ((bool)(extraout_CC_07 >> 1 & 1)) {
      channel_state_write(0x70);
      return;
    }
    channel_state_write(*pbVar4 | 7);
    return;
  }
  if (acStack_e[0] == '\b') {
    sVar3 = channel_pair_get();
    pbVar4 = (byte *)channel_index_get(sVar3 + sStack_2);
    if ((bool)(extraout_CC_08 >> 1 & 1)) {
      channel_state_write(0x80);
      return;
    }
    *pbVar4 = *pbVar4 | 8;
  }
  channel_advance();
  if (DAT_000e < 0xc) {
    mode_handler();
    return;
  }
  DAT_000e = uVar1;
  save_regs_chain(0);
  return;
}

// FUNC 0x816d  mode_handler

/* Mode handler (Roadstm8true, 2026-11-09).
   Converts incoming mode byte 1/3/5/7 -> internal 0/2/4/8 (off/toggle/momentary/pulse).
   Dispatches on internal mode to sub_84b3/sub_84b9/sub_84c5/sub_8485 + sub_848b + sub_828d.
   See docs/mode_timing.md. Timing constants still need bench measurement. */

void mode_handler(short param_1,undefined1 param_2)

{
  char cVar1;
  byte extraout_CC;
  byte extraout_CC_00;
  byte extraout_CC_01;
  byte extraout_CC_02;
  byte extraout_CC_03;
  byte extraout_CC_04;
  byte extraout_CC_05;
  byte extraout_CC_06;
  byte extraout_CC_07;
  byte extraout_CC_08;
  char *pcVar2;
  short sVar3;
  byte *pbVar4;
  char *in_stack_00000001;
  
  tim2_path_set();
  if ((!(bool)(extraout_CC >> 1 & 1)) && ((DAT_000e == 0 || (DAT_000e == 4)))) {
    DAT_0000 = *in_stack_00000001;
    pcVar2 = in_stack_00000001;
    if (DAT_0000 == '\x01') {
      DAT_0000 = '\0';
    }
    else if (DAT_0000 == '\x03') {
      DAT_0000 = '\x02';
    }
    else if (DAT_0000 == '\x05') {
      DAT_0000 = '\x04';
    }
    else if (DAT_0000 == '\a') {
      pcVar2 = (char *)set_6();
    }
    *pcVar2 = DAT_0000;
  }
  cVar1 = *in_stack_00000001;
  if (cVar1 == '\0') {
    mode_off_entry();
    if (!(bool)(extraout_CC_00 >> 1 & 1)) {
      channel_step_b();
      return;
    }
    sVar3 = channel_pair_get();
    *(undefined1 *)(sVar3 + param_1) = 0;
    channel_step_b();
    return;
  }
  if (cVar1 == '\x01') {
    sVar3 = toggle_head();
    pbVar4 = (byte *)channel_index_get(sVar3 + param_1);
    if ((bool)(extraout_CC_01 >> 1 & 1)) {
      channel_state_write(0x10);
      return;
    }
    channel_state_write(*pbVar4 | 1);
    return;
  }
  if (cVar1 == '\x02') {
    sVar3 = mode_head();
    pbVar4 = (byte *)channel_index_get(sVar3 + param_1);
    if ((bool)(extraout_CC_02 >> 1 & 1)) {
      channel_state_write(0x20);
      return;
    }
    channel_state_write(*pbVar4 | 2);
    return;
  }
  if (cVar1 == '\x03') {
    sVar3 = toggle_head();
    pbVar4 = (byte *)channel_index_get(sVar3 + param_1);
    if ((bool)(extraout_CC_03 >> 1 & 1)) {
      channel_state_write(0x30);
      return;
    }
    channel_state_write(*pbVar4 | 3);
    return;
  }
  if (cVar1 == '\x04') {
    sVar3 = mode_head();
    pbVar4 = (byte *)channel_index_get(sVar3 + param_1);
    if ((bool)(extraout_CC_04 >> 1 & 1)) {
      channel_state_write(0x40);
      return;
    }
    channel_state_write(*pbVar4 | 4);
    return;
  }
  if (cVar1 == '\x05') {
    *DAT_000c = 0;
    if (*DAT_0008 == '\0') {
      flag_set_1();
    }
    sVar3 = channel_pair_get();
    pbVar4 = (byte *)channel_index_get(sVar3 + param_1);
    if ((bool)(extraout_CC_05 >> 1 & 1)) {
      channel_state_write(0x50);
      return;
    }
    channel_state_write(*pbVar4 | 5);
    return;
  }
  if (cVar1 == '\x06') {
    sVar3 = mode_head();
    pbVar4 = (byte *)channel_index_get(sVar3 + param_1);
    if ((bool)(extraout_CC_06 >> 1 & 1)) {
      channel_state_write(0x60);
      return;
    }
    channel_state_write(*pbVar4 | 6);
    return;
  }
  if (cVar1 == '\a') {
    sVar3 = flag_init_pair();
    pbVar4 = (byte *)channel_index_get(sVar3 + param_1);
    if ((bool)(extraout_CC_07 >> 1 & 1)) {
      channel_state_write(0x70);
      return;
    }
    channel_state_write(*pbVar4 | 7);
    return;
  }
  if (cVar1 == '\b') {
    sVar3 = channel_pair_get();
    pbVar4 = (byte *)channel_index_get(sVar3 + param_1);
    if ((bool)(extraout_CC_08 >> 1 & 1)) {
      channel_state_write(0x80);
      return;
    }
    *pbVar4 = *pbVar4 | 8;
  }
  channel_advance();
  if (DAT_000e < 0xc) {
    mode_handler();
    return;
  }
  DAT_000e = param_2;
  save_regs_chain(0);
  return;
}

// FUNC 0x81cd  mode_dispatch_tail

void mode_dispatch_tail(void)

{
  channel_state_write(0x10);
  return;
}

// FUNC 0x828d  channel_state_write

void channel_state_write(undefined1 param_1,undefined1 *param_2,undefined1 param_3)

{
  *param_2 = param_1;
  channel_advance();
  if (DAT_000e < 0xc) {
    mode_handler();
    return;
  }
  DAT_000e = param_3;
  save_regs_chain(0);
  return;
}

// FUNC 0x828e  channel_step_b

void channel_step_b(undefined1 param_1)

{
  channel_advance();
  if (DAT_000e < 0xc) {
    mode_handler();
    return;
  }
  DAT_000e = param_1;
  save_regs_chain(0);
  return;
}

// FUNC 0x82a8  tim2_path_set

void tim2_path_set(void)

{
  tim2_set_ccr1l(&PD_ODR);
  return;
}

// FUNC 0x82aa  tim2_path_set_b

void tim2_path_set_b(void)

{
  tim2_set_ccr1l(&PD_ODR);
  return;
}

// FUNC 0x82b3  button_bitmask_handler

void button_bitmask_handler(void)

{
  byte bVar1;
  undefined1 uVar2;
  int3 iVar3;
  byte extraout_CC;
  byte extraout_CC_00;
  byte extraout_CC_01;
  byte extraout_CC_02;
  byte extraout_CC_03;
  byte extraout_CC_04;
  byte extraout_CC_05;
  byte extraout_CC_06;
  byte extraout_CC_07;
  byte extraout_CC_08;
  byte extraout_CC_09;
  undefined1 *puVar4;
  short sVar5;
  byte *pbVar6;
  byte *pbVar7;
  ushort in_Y;
  byte *pbVar8;
  byte abStack_e [12];
  short local_2;
  int3 iVar9;
  
  bank_set_8();
  DAT_000c = (byte *)bank_post_c();
  uVar2 = DAT_000e;
  iVar9 = (uint3)in_Y << 8;
  puVar4 = (undefined1 *)set_6(in_Y);
  do {
    *puVar4 = 0x88;
    puVar4 = puVar4 + 1;
    DAT_0000 = DAT_0000 + -1;
  } while (DAT_0000 != '\0');
  DAT_000e = 0;
  DAT_0008 = abStack_e;
  DAT_000a = &DAT_01fa;
  iVar3 = iVar9;
  do {
    iVar9 = iVar3;
    DAT_000c = DAT_000c + 1;
    DAT_0000 = *DAT_000c >> 4;
    *DAT_0008 = DAT_0000;
    DAT_0008[1] = *DAT_000c & 0xf;
    if (DAT_0000 != 8) {
      tim2_path_set();
      if (((bool)(extraout_CC >> 1 & 1)) || ((DAT_000e != 0 && (DAT_000e != 2)))) {
        *DAT_000a = *DAT_0008;
      }
    }
    if (DAT_0008[1] != 8) {
      DAT_000a[1] = DAT_0008[1];
    }
    DAT_000e = DAT_000e + 1;
    DAT_000a = DAT_000a + 2;
    DAT_0008 = (byte *)channel_ptr_2();
    iVar3 = iVar9;
    local_2 = (short)((uint3)iVar9 >> 8);
  } while (DAT_000e < 6);
  DAT_000e = 0;
  pbVar8 = &DAT_01fa;
  pbVar6 = abStack_e;
  pin_table_ptrs();
  tim2_path_set();
  if ((!(bool)(extraout_CC_00 >> 1 & 1)) && ((DAT_000e == 0 || (DAT_000e == 4)))) {
    DAT_0000 = *pbVar8;
    if (DAT_0000 == 1) {
      DAT_0000 = 0;
    }
    else if (DAT_0000 == 3) {
      DAT_0000 = 2;
    }
    else if (DAT_0000 == 5) {
      DAT_0000 = 4;
    }
    else if (DAT_0000 == 7) {
      set_6();
    }
    *pbVar6 = DAT_0000;
  }
  bVar1 = *pbVar6;
  if (bVar1 == 0) {
    mode_off_entry();
    if (!(bool)(extraout_CC_01 >> 1 & 1)) {
      channel_step();
      return;
    }
    sVar5 = channel_pair_get();
    *(undefined1 *)(sVar5 + local_2) = 0;
    channel_step();
    return;
  }
  if (bVar1 == 1) {
    sVar5 = toggle_head();
    pbVar6 = (byte *)channel_index_get(sVar5 + local_2);
    if ((bool)(extraout_CC_02 >> 1 & 1)) {
      channel_state_write_b(0x10);
      return;
    }
    channel_state_write_b(*pbVar6 | 1);
    return;
  }
  if (bVar1 == 2) {
    sVar5 = mode_head();
    pbVar6 = (byte *)channel_index_get(sVar5 + local_2);
    if ((bool)(extraout_CC_03 >> 1 & 1)) {
      channel_state_write_b(0x20);
      return;
    }
    channel_state_write_b(*pbVar6 | 2);
    return;
  }
  if (bVar1 == 3) {
    sVar5 = toggle_head();
    pbVar6 = (byte *)channel_index_get(sVar5 + local_2);
    if ((bool)(extraout_CC_04 >> 1 & 1)) {
      channel_state_write_b(0x30);
      return;
    }
    channel_state_write_b(*pbVar6 | 3);
    return;
  }
  if (bVar1 == 4) {
    sVar5 = mode_head();
    pbVar6 = (byte *)channel_index_get(sVar5 + local_2);
    if ((bool)(extraout_CC_05 >> 1 & 1)) {
      channel_state_write_b(0x40);
      return;
    }
    channel_state_write_b(*pbVar6 | 4);
    return;
  }
  if (bVar1 == 5) {
    *DAT_000c = 0;
    if (*DAT_0008 == 0) {
      flag_set_1();
    }
    sVar5 = channel_pair_get();
    pbVar6 = (byte *)channel_index_get(sVar5 + local_2);
    if ((bool)(extraout_CC_06 >> 1 & 1)) {
      channel_state_write_b(0x50);
      return;
    }
    channel_state_write_b(*pbVar6 | 5);
    return;
  }
  if (bVar1 == 6) {
    sVar5 = mode_head();
    pbVar6 = (byte *)channel_index_get(sVar5 + local_2);
    if ((bool)(extraout_CC_07 >> 1 & 1)) {
      channel_state_write_b(0x60);
      return;
    }
    channel_state_write_b(*pbVar6 | 6);
    return;
  }
  if (bVar1 == 7) {
    sVar5 = flag_init_pair();
    pbVar6 = (byte *)channel_index_get(sVar5 + local_2);
    if ((bool)(extraout_CC_08 >> 1 & 1)) {
      channel_state_write_b(0x70);
      return;
    }
    channel_state_write_b(*pbVar6 | 7);
    return;
  }
  if (bVar1 == 8) {
    sVar5 = channel_pair_get();
    pbVar7 = (byte *)channel_index_get(sVar5 + local_2);
    if ((bool)(extraout_CC_09 >> 1 & 1)) {
      channel_state_write_b(0x80);
      return;
    }
    *pbVar7 = *pbVar7 | 8;
  }
  channel_advance();
  if (DAT_000e < 0xc) {
    mode_apply_block();
    return;
  }
  eeprom_sequencer(pbVar6 + 1,pbVar8 + 1);
  DAT_000e = uVar2;
  save_regs_chain(0);
  return;
}

// FUNC 0x833b  mode_apply_block

void mode_apply_block(char *param_1,short param_2,undefined1 param_3)

{
  char cVar1;
  byte extraout_CC;
  byte extraout_CC_00;
  byte extraout_CC_01;
  byte extraout_CC_02;
  byte extraout_CC_03;
  byte extraout_CC_04;
  byte extraout_CC_05;
  byte extraout_CC_06;
  byte extraout_CC_07;
  byte extraout_CC_08;
  short sVar2;
  byte *pbVar3;
  char *in_stack_00000001;
  
  tim2_path_set();
  if ((!(bool)(extraout_CC >> 1 & 1)) && ((DAT_000e == 0 || (DAT_000e == 4)))) {
    DAT_0000 = *param_1;
    if (DAT_0000 == '\x01') {
      DAT_0000 = '\0';
    }
    else if (DAT_0000 == '\x03') {
      DAT_0000 = '\x02';
    }
    else if (DAT_0000 == '\x05') {
      DAT_0000 = '\x04';
    }
    else if (DAT_0000 == '\a') {
      set_6();
    }
    *in_stack_00000001 = DAT_0000;
  }
  cVar1 = *in_stack_00000001;
  if (cVar1 == '\0') {
    mode_off_entry();
    if (!(bool)(extraout_CC_00 >> 1 & 1)) {
      channel_step();
      return;
    }
    sVar2 = channel_pair_get();
    *(undefined1 *)(sVar2 + param_2) = 0;
    channel_step();
    return;
  }
  if (cVar1 == '\x01') {
    sVar2 = toggle_head();
    pbVar3 = (byte *)channel_index_get(sVar2 + param_2);
    if ((bool)(extraout_CC_01 >> 1 & 1)) {
      channel_state_write_b(0x10);
      return;
    }
    channel_state_write_b(*pbVar3 | 1);
    return;
  }
  if (cVar1 == '\x02') {
    sVar2 = mode_head();
    pbVar3 = (byte *)channel_index_get(sVar2 + param_2);
    if ((bool)(extraout_CC_02 >> 1 & 1)) {
      channel_state_write_b(0x20);
      return;
    }
    channel_state_write_b(*pbVar3 | 2);
    return;
  }
  if (cVar1 == '\x03') {
    sVar2 = toggle_head();
    pbVar3 = (byte *)channel_index_get(sVar2 + param_2);
    if ((bool)(extraout_CC_03 >> 1 & 1)) {
      channel_state_write_b(0x30);
      return;
    }
    channel_state_write_b(*pbVar3 | 3);
    return;
  }
  if (cVar1 == '\x04') {
    sVar2 = mode_head();
    pbVar3 = (byte *)channel_index_get(sVar2 + param_2);
    if ((bool)(extraout_CC_04 >> 1 & 1)) {
      channel_state_write_b(0x40);
      return;
    }
    channel_state_write_b(*pbVar3 | 4);
    return;
  }
  if (cVar1 == '\x05') {
    *DAT_000c = 0;
    if (*DAT_0008 == '\0') {
      flag_set_1();
    }
    sVar2 = channel_pair_get();
    pbVar3 = (byte *)channel_index_get(sVar2 + param_2);
    if ((bool)(extraout_CC_05 >> 1 & 1)) {
      channel_state_write_b(0x50);
      return;
    }
    channel_state_write_b(*pbVar3 | 5);
    return;
  }
  if (cVar1 == '\x06') {
    sVar2 = mode_head();
    pbVar3 = (byte *)channel_index_get(sVar2 + param_2);
    if ((bool)(extraout_CC_06 >> 1 & 1)) {
      channel_state_write_b(0x60);
      return;
    }
    channel_state_write_b(*pbVar3 | 6);
    return;
  }
  if (cVar1 == '\a') {
    sVar2 = flag_init_pair();
    pbVar3 = (byte *)channel_index_get(sVar2 + param_2);
    if ((bool)(extraout_CC_07 >> 1 & 1)) {
      channel_state_write_b(0x70);
      return;
    }
    channel_state_write_b(*pbVar3 | 7);
    return;
  }
  if (cVar1 == '\b') {
    sVar2 = channel_pair_get();
    pbVar3 = (byte *)channel_index_get(sVar2 + param_2);
    if ((bool)(extraout_CC_08 >> 1 & 1)) {
      channel_state_write_b(0x80);
      return;
    }
    *pbVar3 = *pbVar3 | 8;
  }
  channel_advance();
  if (DAT_000e < 0xc) {
    mode_apply_block();
    return;
  }
  eeprom_sequencer();
  DAT_000e = param_3;
  save_regs_chain(0);
  return;
}

// FUNC 0x845d  channel_state_write_b

void channel_state_write_b(undefined1 param_1,undefined1 *param_2,undefined1 param_3)

{
  *param_2 = param_1;
  channel_advance();
  if (DAT_000e < 0xc) {
    mode_apply_block();
    return;
  }
  eeprom_sequencer();
  DAT_000e = param_3;
  save_regs_chain(0);
  return;
}

// FUNC 0x845e  channel_step

void channel_step(undefined1 param_1)

{
  channel_advance();
  if (DAT_000e < 0xc) {
    mode_apply_block();
    return;
  }
  eeprom_sequencer();
  DAT_000e = param_1;
  save_regs_chain(0);
  return;
}

// FUNC 0x8480  channel_ptr_2

short channel_ptr_2(void)

{
  return DAT_0008 + 2;
}

// FUNC 0x8485  channel_pair_get

byte channel_pair_get(void)

{
  return DAT_000e >> 1;
}

// FUNC 0x848b  channel_index_get

undefined1 channel_index_get(void)

{
  return DAT_000e;
}

// FUNC 0x8490  set_6

void set_6(void)

{
  DAT_0000 = 6;
  return;
}

// FUNC 0x8495  pin_table_ptrs

void pin_table_ptrs(void)

{
  DAT_000c = &DAT_02b8;
  DAT_000a = &DAT_02df;
  DAT_0008 = &DAT_0182;
  return;
}

// FUNC 0x84a5  flag_init_pair

byte flag_init_pair(void)

{
  *DAT_000c = 1;
  *DAT_0008 = 0;
  return DAT_000e >> 1;
}

// FUNC 0x84b3  mode_off_entry

void mode_off_entry(void)

{
  mode_off_prelude();
  return;
}

// FUNC 0x84b9  toggle_head

byte toggle_head(void)

{
  flag_clear_pair();
  pin_or();
  return DAT_000e >> 1;
}

// FUNC 0x84c5  mode_head

byte mode_head(void)

{
  byte bVar1;
  
  bVar1 = mode_off_prelude();
  return bVar1 >> 1;
}

// FUNC 0x84cc  mode_off_prelude

undefined1 mode_off_prelude(void)

{
  flag_clear_pair();
  pin_and();
  return DAT_000e;
}

// FUNC 0x84d5  flag_clear_pair

undefined2 flag_clear_pair(void)

{
  *DAT_000c = 0;
  *DAT_0008 = 0;
  return *DAT_000a;
}

// FUNC 0x84e4  flag_set_1

void flag_set_1(void)

{
  undefined1 *puVar1;
  
  *DAT_0008 = 1;
  DAT_0008[4] = 0x19;
  DAT_0008[3] = 4;
  puVar1 = (undefined1 *)channel_ptr_2();
  *puVar1 = 5;
  DAT_0008[1] = 5;
  return;
}

// FUNC 0x8504  channel_advance

void channel_advance(void)

{
  DAT_000e = DAT_000e + '\x01';
  DAT_0008 = DAT_0008 + 5;
  DAT_000a = DAT_000a + 3;
  DAT_000c = DAT_000c + 1;
  return;
}

// FUNC 0x851a  frame_handler

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Frame handler. Validates 11-byte checksum, dispatches on DAT_021f (type).
   Type 7: master power/parameter (6 bytes -> 12 nibbles at 0x9E85, post 0x1700).
   Type 8: button bitmask (sub_82b3, post 0x1800).
   Type 0x0B: cmd_0b_handler (sub_8640). Type 0x0D: cmd_0d_handler (sub_8689).
   Type 0x19: cmd_19_handler (sub_860c). See docs/hidden_commands.md. */

void frame_handler(void)

{
  char *pcVar1;
  byte *pbVar2;
  undefined1 local_13;
  char local_12;
  byte abStack_b [11];
  
  clk_gate_enable_2(8);
  _DAT_0000 = (byte *)CONCAT11(DAT_0000,DAT_023d);
  if (DAT_023d < 2) {
    noop_c(&local_13);
    return;
  }
  DAT_0000 = DAT_023d - 1;
  DAT_0001 = DAT_023d;
  DAT_0002._0_1_ = '\0';
  if (DAT_0000 != '\0') {
    pcVar1 = &DAT_021d;
    do {
      DAT_0002._0_1_ = *pcVar1 + DAT_0002._0_1_;
      pcVar1 = pcVar1 + 1;
      DAT_0000 = DAT_0000 + -1;
    } while (DAT_0000 != '\0');
  }
  if ((&DAT_021c)[DAT_023d] != DAT_0002._0_1_) {
    noop_c();
    return;
  }
  if (DAT_021e != '\0') {
    post_if_ff(DAT_021e);
    return;
  }
  if (DAT_021f == '\a') {
    local_12 = DAT_0220;
    DAT_01f9 = DAT_0220 == '\0';
    _DAT_0000 = &UNK_0221;
    pbVar2 = abStack_b;
    DAT_0002._0_1_ = '\x06';
    do {
      DAT_0002._1_1_ = *_DAT_0000;
      *pbVar2 = (byte)DAT_0002 >> 4;
      pbVar2[1] = (byte)DAT_0002 & 0xf;
      pbVar2 = pbVar2 + 2;
      _DAT_0000 = _DAT_0000 + 1;
      DAT_0002._0_1_ = DAT_0002._0_1_ + -1;
    } while (DAT_0002._0_1_ != '\0');
    local_13 = config_mode_handler(abStack_b);
    DAT_0002._0_1_ = 8;
    _DAT_0000 = (byte *)0x1700;
                    /* WARNING: Subroutine does not return */
    message_post_loop(DAT_021d,&local_13);
  }
  if (DAT_021f == '\b') {
    DAT_01f9 = 0;
    local_13 = button_bitmask_handler(&DAT_0220);
    DAT_0002._0_1_ = 7;
    _DAT_0000 = (byte *)0x1800;
    post_dispatch(&local_13);
    return;
  }
  if (DAT_021f == '\v') {
    cmd_0b_handler();
    return;
  }
  if (DAT_021f == '\r') {
    cmd_0d_handler();
    return;
  }
  if (DAT_021f == '\x19') {
    cmd_19_handler();
    return;
  }
  noop_c();
  return;
}

// FUNC 0x85e6  eeprom_flush

void eeprom_flush(void)

{
  eeprom_sequencer();
  noop_c();
  return;
}

// FUNC 0x860c  cmd_19_handler

/* Hidden command 0x19 handler. Searches message queue for matching seq, clears it. */

void cmd_19_handler(void)

{
  byte extraout_CC;
  char *pcVar1;
  
  DAT_0002 = 0;
  while( true ) {
    DAT_0002 = DAT_0002 & 0xff;
    msg_post();
    pcVar1 = (char *)msg_peek(DAT_0002);
    if (((*pcVar1 != '\0') && (pcVar1[6] == '\t')) && (DAT_021d == pcVar1[4])) break;
    msg_next();
    if (!(bool)(extraout_CC & 1)) {
      noop_c();
      return;
    }
  }
  *pcVar1 = '\0';
  noop_c();
  return;
}

// FUNC 0x8640  cmd_0b_handler

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Hidden command 0x0B handler. Updates DAT_0206, writes EEPROM via sub_9927, posts 0x1B. */

void cmd_0b_handler(void)

{
  _DAT_0000 = CONCAT11(DAT_0220,DAT_0001);
  if (((DAT_0220 != 0) && (DAT_0220 < 0x65)) && (DAT_0206 != DAT_0220)) {
    DAT_0206 = DAT_0220;
    DAT_0002 = (ushort)DAT_0220;
    _DAT_0000 = 0;
    eeprom_write(&DAT_01be);
    eeprom_sequencer();
    seq_alloc_2();
    DAT_0002 = CONCAT11(1,(undefined1)DAT_0002);
    _DAT_0000 = 0x1b02;
                    /* WARNING: Subroutine does not return */
    message_post_loop((undefined1)DAT_0002,&stack0x0001);
  }
  return;
}

// FUNC 0x8689  cmd_0d_handler

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Hidden command 0x0D handler. Type 0 -> _DAT_02cb=10000; Type 1 -> reset state, DAT_0206=10. */

void cmd_0d_handler(void)

{
  DAT_0000 = DAT_0220;
  if (DAT_0220 == '\0') {
    _DAT_02cb = 10000;
    noop_c();
    return;
  }
  if (DAT_0220 == '\x01') {
    reset_state();
    DAT_0206 = 10;
    eeprom_sequencer();
    noop_c();
    return;
  }
  return;
}

// FUNC 0x86a6  eeprom_flush

void eeprom_flush(void)

{
  eeprom_sequencer();
  noop_c();
  return;
}

// FUNC 0x86ab  post_if_ff

void post_if_ff(char param_1)

{
  if ((param_1 == -1) && (DAT_0000 = DAT_021f, DAT_021f != '\f')) {
    DAT_0002._0_1_ = DAT_0001 + -4;
    DAT_0001 = 0;
                    /* WARNING: Subroutine does not return */
    message_post_loop(DAT_021d,&DAT_0220);
  }
  return;
}

// FUNC 0x86c2  post_dispatch

void post_dispatch(void)

{
                    /* WARNING: Subroutine does not return */
  message_post_loop(DAT_021d);
}

// FUNC 0x86c8  noop_c

void noop_c(void)

{
  return;
}

// FUNC 0x86cb  msg_post

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msg_post(void)

{
  _DAT_0000 = 0x25;
  return;
}

// FUNC 0x86d1  msg_next

char msg_next(void)

{
  DAT_0002._1_1_ = (char)DAT_0002 + '\x01';
  return (char)DAT_0002;
}

// FUNC 0x86d3  dat_0002_ret

undefined1 dat_0002_ret(void)

{
  return (undefined1)DAT_0002;
}

// FUNC 0x86d8  msg_peek

short msg_peek(void)

{
  short sVar1;
  
  sVar1 = mul_small();
  return sVar1 + 0x10;
}

// FUNC 0x86df  reset_state

void reset_state(void)

{
  DAT_0207 = 0;
  DAT_021c = 0;
  return;
}

// FUNC 0x86e8  eeprom_sequencer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void eeprom_sequencer(void)

{
  state_clear(&UNK_01df);
  DAT_0002 = &UNK_03e8;
  _DAT_0000 = 0;
  eeprom_write(&UNK_01df);
  return;
}

// FUNC 0x8700  mode_tick

/* Mode tick. DAT_02d7 divider (every 3rd pass), toggles pin_state_d3/d4 via
   sub_8811/8814/881c. Blink/pulse state advance. */

char mode_tick(void)

{
  byte extraout_CC;
  byte extraout_CC_00;
  byte extraout_CC_01;
  byte extraout_CC_02;
  byte extraout_CC_03;
  byte extraout_CC_04;
  byte extraout_CC_05;
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined2 uStack_1a;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13 [4];
  undefined1 local_f;
  
  DAT_02d7 = DAT_02d7 + 1;
  bVar1 = DAT_02d7;
  if (2 < DAT_02d7) {
    DAT_02d7 = 0;
    uStack_1a = (code *)0x8716;
    bVar1 = tim2_path_set_b(8);
    if ((bool)(extraout_CC >> 1 & 1)) {
      bVar1 = pin_state_d3;
      if (pin_state_d3 != 0) {
        local_18 = 2;
        uStack_1a = (code *)0x8724;
        tim2_path_set();
        local_17 = !(bool)(extraout_CC_00 >> 1 & 1);
        local_16 = 1;
        local_15 = DAT_01fa;
        local_14 = DAT_01fe;
        uStack_1a = (code *)0x873e;
        tick_b();
        uStack_1a = (code *)0x8742;
        bVar1 = tick_c((short)&uStack_1a + 1);
        pin_state_d3 = 0;
      }
    }
    else {
      pin_state_d3 = 1;
    }
  }
  uStack_1a = (code *)0x874f;
  tim2_path_set(bVar1);
  if ((bool)(extraout_CC_01 >> 1 & 1)) {
    if (pin_state_d4 == '\0') {
      cVar2 = noop_2(0);
      return cVar2;
    }
    uStack_1a = (code *)0x875e;
    tim2_path_set_b(8);
    local_18 = !(bool)(extraout_CC_02 >> 1 & 1);
    uStack_1a = (code *)0x876a;
    tim2_path_set();
    local_17 = !(bool)(extraout_CC_03 >> 1 & 1);
    local_16 = 1;
    local_15 = DAT_01fa;
    local_14 = DAT_01fe;
    uStack_1a = (code *)0x8784;
    tick_b();
    uStack_1a = (code *)0x8788;
    tick_c((short)&uStack_1a + 1);
    pin_state_d4 = 0;
    puVar3 = local_13;
    DAT_0000 = '\f';
    do {
      *puVar3 = 8;
      puVar3 = puVar3 + 1;
      DAT_0000 = DAT_0000 + -1;
    } while (DAT_0000 != '\0');
    local_13[0] = DAT_01fa;
    local_f = DAT_01fe;
  }
  else {
    if (pin_state_d4 != '\0') {
      return pin_state_d4;
    }
    pin_state_d4 = 1;
    uStack_1a = (code *)0x87b4;
    tim2_path_set_b(8);
    local_18 = !(bool)(extraout_CC_04 >> 1 & 1);
    uStack_1a = (code *)0x87c0;
    tim2_path_set();
    local_17 = !(bool)(extraout_CC_05 >> 1 & 1);
    local_16 = 1;
    uStack_1a = (code *)0x87d3;
    local_15 = mode_convert(DAT_01fa);
    uStack_1a = (code *)0x87db;
    local_14 = mode_convert(DAT_01fe);
    uStack_1a = (code *)0x87e0;
    tick_b();
    uStack_1a = (code *)0x87e4;
    tick_c((short)&uStack_1a + 1);
    puVar3 = local_13;
    DAT_0000 = '\f';
    do {
      *puVar3 = 8;
      puVar3 = puVar3 + 1;
      DAT_0000 = DAT_0000 + -1;
    } while (DAT_0000 != '\0');
    uStack_1a = (code *)0x87fa;
    local_13[0] = mode_convert(DAT_01fa);
    uStack_1a = (code *)0x8802;
    local_f = mode_convert(DAT_01fe);
  }
  uStack_1a = noop_2;
  cVar2 = config_mode_handler(local_13);
  return cVar2;
}

// FUNC 0x8811  noop_2

void noop_2(void)

{
  return;
}

// FUNC 0x8814  tick_b

void tick_b(void)

{
  seq_alloc();
  DAT_0002._0_1_ = 5;
  return;
}

// FUNC 0x881c  tick_c

void tick_c(short param_1)

{
  DAT_0001 = 0;
  DAT_0000 = 9;
                    /* WARNING: Subroutine does not return */
  message_post_loop((undefined1)DAT_0002,param_1 + 1);
}

// FUNC 0x8828  bank_prelude

void bank_prelude(void)

{
  bank_set_8();
  bank_post_c();
  DAT_000a._0_1_ = 0xff;
  DAT_000e = 0;
  state_dispatch();
  return;
}

// FUNC 0x8841  state_dispatch

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_dispatch(void)

{
  char cVar1;
  byte extraout_CC;
  byte extraout_CC_00;
  byte extraout_CC_01;
  byte extraout_CC_02;
  byte extraout_CC_03;
  byte extraout_CC_04;
  byte extraout_CC_05;
  byte extraout_CC_06;
  byte extraout_CC_07;
  byte extraout_CC_08;
  byte extraout_CC_09;
  byte extraout_CC_10;
  byte extraout_CC_11;
  byte extraout_CC_12;
  byte extraout_CC_13;
  byte extraout_CC_14;
  byte extraout_CC_15;
  byte extraout_CC_16;
  byte extraout_CC_17;
  short sVar2;
  byte *pbVar3;
  ushort uVar4;
  char *pcVar5;
  
  do {
    if (DAT_02d6 < 7) {
      index_set();
      return;
    }
    DAT_0008 = &UNK_0280 + DAT_000e;
    if (*DAT_0008 == 'Z') {
      DAT_0001 = '\0';
      set_6();
      do {
        sum_add();
      } while (!(bool)(extraout_CC >> 1 & 1));
      if (DAT_0008[6] == DAT_0001) {
        ptr_02c4();
        sVar2 = mem_compare();
        if (sVar2 == 0) {
          index_add_7();
          return;
        }
        ptr_02c4();
        block_copy();
        pbVar3 = (byte *)channel_ptr_2();
        uVar4 = (ushort)*pbVar3 << 8;
        pbVar3 = (byte *)channel_ptr_3(0);
        DAT_0001 = *pbVar3;
        uVar4 = uVar4 & 0xff00 | (ushort)(byte)((byte)uVar4 | DAT_0001);
        pcVar5 = (char *)channel_ptr_5(DAT_0001);
        DAT_000a._1_1_ = *pcVar5;
        pcVar5 = (char *)channel_ptr_4();
        cVar1 = *pcVar5;
        if (cVar1 == '\0') {
          poll_call();
          if (!(bool)(extraout_CC_03 >> 1 & 1)) {
            DAT_000a._0_1_ = 3;
            to_button_frame();
            return;
          }
          to_button_frame();
          return;
        }
        if (cVar1 == '\x01') {
          poll_call();
          if (!(bool)(extraout_CC_02 >> 1 & 1)) {
            DAT_000a._0_1_ = 2;
            to_button_frame();
            return;
          }
          to_button_frame();
          return;
        }
        if (cVar1 == '\x04') {
          poll_call();
          if (!(bool)(extraout_CC_04 >> 1 & 1)) {
            DAT_000a._0_1_ = 4;
            to_button_frame();
            return;
          }
          to_button_frame();
          return;
        }
        if (cVar1 == '\a') {
          poll_call();
          if (!(bool)(extraout_CC_05 >> 1 & 1)) {
            DAT_000a._0_1_ = 5;
            to_button_frame();
            return;
          }
          to_button_frame();
          return;
        }
        if (cVar1 == '\n') {
          poll_call();
          if (!(bool)(extraout_CC_06 >> 1 & 1)) {
            DAT_000a._0_1_ = 6;
            to_button_frame();
            return;
          }
          to_button_frame();
          return;
        }
        if (cVar1 == '\x11') {
          poll_call();
          if (!(bool)(extraout_CC_01 >> 1 & 1)) {
            DAT_000a._0_1_ = 1;
            to_button_frame();
            return;
          }
          to_button_frame();
          return;
        }
        if (cVar1 == '\x12') {
          poll_call();
          if (!(bool)(extraout_CC_07 >> 1 & 1)) {
            DAT_000a._0_1_ = 7;
            to_button_frame();
            return;
          }
          to_button_frame();
          return;
        }
        if (cVar1 == '\x15') {
          poll_call();
          if (!(bool)(extraout_CC_00 >> 1 & 1)) {
            DAT_000a._0_1_ = 0;
            to_button_frame();
            return;
          }
          to_button_frame();
          return;
        }
        if (cVar1 != '.') {
          to_button_frame();
          return;
        }
        if ((char)DAT_000a == '\x01') {
          channel_index_set();
          return;
        }
        if (_DAT_02cb == 0) {
          param_block_apply();
          return;
        }
        DAT_0001 = DAT_021c;
        if (9 < DAT_021c) {
          msg_alloc_loop();
          return;
        }
        DAT_0207 = 1;
        DAT_0000 = 0;
        sVar2 = _DAT_02cb;
        break;
      }
    }
    DAT_000e = DAT_000e + 1;
    DAT_02d6 = DAT_02d6 - 1;
  } while( true );
LAB_8964:
  if (DAT_0001 <= DAT_0000) goto code_r0x896a;
  sVar2 = noop_3(sVar2);
  if ((bool)(extraout_CC_08 >> 1 & 1)) goto LAB_897e;
  DAT_0000 = DAT_0000 + 1;
  goto LAB_8964;
code_r0x896a:
  if (DAT_0001 == DAT_0000) {
    *(ushort *)(&UNK_0208 + (ushort)DAT_0001 * 2) = uVar4;
    DAT_021c = DAT_021c + 1;
    eeprom_sequencer();
  }
LAB_897e:
  seq_alloc_3();
  do {
    dat_0002_ret();
    if (!(bool)(extraout_CC_09 & 1)) break;
    msg_alloc();
    if ((bool)(extraout_CC_10 >> 1 & 1)) {
      clk_enable_a();
      bit_scan_b();
      byte_store_off24();
      break;
    }
    msg_next();
    if (!(bool)(extraout_CC_11 & 1)) {
      DAT_0002._1_1_ = 0;
    }
    tx_index_ret();
  } while (!(bool)(extraout_CC_12 >> 1 & 1));
  pcVar5 = &DAT_01fa;
  addr_plus_10(&stack0x0000);
  do {
    DAT_0002._0_1_ = *pcVar5;
    if (DAT_0002._0_1_ == '\x01') {
      DAT_0002._0_1_ = '\0';
    }
    else if (DAT_0002._0_1_ == '\x03') {
      DAT_0002._0_1_ = '\x02';
    }
    else if (DAT_0002._0_1_ == '\x05') {
      DAT_0002._0_1_ = '\x04';
    }
    else if (DAT_0002._0_1_ == '\a') {
      DAT_0002._0_1_ = '\x06';
    }
    byte_store_inc();
  } while (!(bool)(extraout_CC_13 >> 1 & 1));
  DAT_01f9 = 1;
  config_mode_handler(&stack0x0010);
  seq_save();
  do {
    dat_0002_ret();
    if (!(bool)(extraout_CC_14 & 1)) break;
    msg_alloc();
    if ((bool)(extraout_CC_15 >> 1 & 1)) {
      clk_enable_b();
      bit_scan_a();
      byte_store_off24();
      break;
    }
    msg_next();
    if (!(bool)(extraout_CC_16 & 1)) {
      DAT_0002._1_1_ = 0;
    }
    tx_index_ret();
  } while (!(bool)(extraout_CC_17 >> 1 & 1));
  _DAT_02cb = 0;
  to_button_frame();
  return;
}

// FUNC 0x8a15  msg_alloc_loop

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msg_alloc_loop(void)

{
  byte extraout_CC;
  byte extraout_CC_00;
  byte extraout_CC_01;
  byte extraout_CC_02;
  
  seq_alloc_3();
  do {
    dat_0002_ret();
    if (!(bool)(extraout_CC & 1)) break;
    msg_alloc();
    if ((bool)(extraout_CC_00 >> 1 & 1)) {
      clk_enable_a();
      bit_scan_b();
      byte_store_off24();
      break;
    }
    msg_next();
    if (!(bool)(extraout_CC_01 & 1)) {
      DAT_0002._1_1_ = 0;
    }
    tx_index_ret();
  } while (!(bool)(extraout_CC_02 >> 1 & 1));
  _DAT_02cb = 0;
  to_button_frame();
  return;
}

// FUNC 0x8a46  param_block_apply

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void param_block_apply(void)

{
  byte extraout_CC;
  byte extraout_CC_00;
  byte extraout_CC_01;
  byte extraout_CC_02;
  byte extraout_CC_03;
  byte extraout_CC_04;
  byte extraout_CC_05;
  byte extraout_CC_06;
  byte extraout_CC_07;
  byte extraout_CC_08;
  undefined1 extraout_A;
  undefined1 extraout_A_00;
  undefined1 *puVar1;
  short sVar2;
  char *pcVar3;
  byte *pbVar4;
  
  if (DAT_0207 == '\0') {
    to_button_frame();
    return;
  }
  DAT_0000 = 0;
  DAT_0001 = DAT_021c;
  while( true ) {
    if (DAT_0001 <= DAT_0000) {
      to_button_frame();
      return;
    }
    noop_3();
    if ((bool)(extraout_CC >> 1 & 1)) break;
    DAT_0000 = DAT_0000 + 1;
  }
  if (DAT_01f9 == '\0') {
    pcVar3 = &DAT_01fa;
    addr_plus_10(0,&stack0x0000);
    do {
      DAT_0002._0_1_ = *pcVar3;
      if (DAT_0002._0_1_ == '\x01') {
        DAT_0002._0_1_ = '\0';
      }
      else if (DAT_0002._0_1_ == '\x03') {
        DAT_0002._0_1_ = '\x02';
      }
      else if (DAT_0002._0_1_ == '\x05') {
        DAT_0002._0_1_ = '\x04';
      }
      else if (DAT_0002._0_1_ == '\a') {
        DAT_0002._0_1_ = '\x06';
      }
      byte_store_inc();
    } while (!(bool)(extraout_CC_00 >> 1 & 1));
    DAT_01f9 = 1;
    config_mode_handler(&stack0x0010);
    seq_save();
    while( true ) {
      dat_0002_ret();
      if (!(bool)(extraout_CC_01 & 1)) {
        msg_step();
        return;
      }
      msg_alloc();
      if ((bool)(extraout_CC_02 >> 1 & 1)) break;
      msg_next();
      if (!(bool)(extraout_CC_03 & 1)) {
        DAT_0002._1_1_ = 0;
      }
      tx_index_ret();
      if ((bool)(extraout_CC_04 >> 1 & 1)) {
        msg_step();
        return;
      }
    }
    clk_enable_b();
    bit_scan_a();
    state_step();
    return;
  }
  pbVar4 = &stack0x000a;
  _DAT_0000 = &DAT_01fa;
  DAT_0002._0_1_ = '\x06';
  do {
    DAT_0004 = *_DAT_0000 << 4;
    *pbVar4 = _DAT_0000[1] & 0xfU | DAT_0004;
    _DAT_0000 = _DAT_0000 + 2;
    pbVar4 = pbVar4 + 1;
    DAT_0002._0_1_ = DAT_0002._0_1_ + -1;
  } while (DAT_0002._0_1_ != '\0');
  DAT_01f9 = 0;
  button_bitmask_handler(&stack0x0009);
  seq_alloc_3();
  do {
    dat_0002_ret();
    if (!(bool)(extraout_CC_05 & 1)) break;
    msg_alloc();
    if ((bool)(extraout_CC_06 >> 1 & 1)) {
      flag1_clear2();
      puVar1 = (undefined1 *)channel_ptr_3();
      *puVar1 = 0;
      DAT_000c = channel_ptr_4();
      puVar1 = (undefined1 *)channel_ptr_5_store(DAT_0002._0_1_);
      *puVar1 = extraout_A;
      clk_gate_enable_3(0x18);
      _DAT_0000 = (char *)0x7;
      block_copy_call();
      sVar2 = poll_and_load(10);
      *(undefined1 *)(sVar2 + 0xe) = extraout_A_00;
      byte_store_off24(0xb);
      msg_step();
      return;
    }
    msg_next();
    if (!(bool)(extraout_CC_07 & 1)) {
      DAT_0002._1_1_ = 0;
    }
    tx_index_ret();
  } while (!(bool)(extraout_CC_08 >> 1 & 1));
  eeprom_sequencer();
  _DAT_0000 = (char *)CONCAT11((undefined1)DAT_000a,DAT_0001);
  button_frame_builder(DAT_000a._0_1_);
  DAT_000e = DAT_000e + '\a';
  DAT_02d6 = DAT_02d6 + -7;
  state_dispatch();
  return;
}

// FUNC 0x8b5d  state_step

void state_step(void)

{
  byte_store_off24();
  msg_step();
  return;
}

// FUNC 0x8b6e  msg_step

void msg_step(void)

{
  eeprom_sequencer();
  DAT_0000 = (undefined1)DAT_000a;
  button_frame_builder(DAT_000a._0_1_);
  DAT_000e = DAT_000e + '\a';
  DAT_02d6 = DAT_02d6 + -7;
  state_dispatch();
  return;
}

// FUNC 0x8b71  to_button_frame

void to_button_frame(void)

{
  DAT_0000 = (undefined1)DAT_000a;
  button_frame_builder(DAT_000a._0_1_);
  DAT_000e = DAT_000e + '\a';
  DAT_02d6 = DAT_02d6 + -7;
  state_dispatch();
  return;
}

// FUNC 0x8b79  index_add_7

void index_add_7(void)

{
  DAT_000e = DAT_000e + '\a';
  DAT_02d6 = DAT_02d6 + -7;
  state_dispatch();
  return;
}

// FUNC 0x8b8a  index_set

void index_set(undefined1 param_1)

{
  DAT_02d6 = 0;
  DAT_000e = param_1;
  save_regs_chain();
  return;
}

// FUNC 0x8b8e  channel_index_set

void channel_index_set(undefined1 param_1)

{
  DAT_000e = param_1;
  save_regs_chain();
  return;
}

// FUNC 0x8b96  button_frame_builder

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void button_frame_builder(byte param_1)

{
  byte extraout_CC;
  byte extraout_CC_00;
  byte extraout_A;
  char extraout_A_00;
  char cVar1;
  byte extraout_A_01;
  char extraout_A_02;
  byte bVar2;
  char *pcVar3;
  byte *pbVar4;
  undefined2 uStack_10;
  undefined1 local_e;
  byte abStack_d [6];
  undefined1 auStack_7 [7];
  
  DAT_0001 = param_1;
  if (0xb < param_1) {
    noop_d();
    return;
  }
  local_e = 0xc;
  DAT_0002._0_1_ = DAT_01f9;
  if (DAT_01f9 != '\x01') {
    idle_reply_builder();
    return;
  }
  pbVar4 = abStack_d;
  _DAT_0004 = &DAT_01fa;
  DAT_0002._1_1_ = '\x06';
  do {
    DAT_0006 = *_DAT_0004;
    if (DAT_0006 == '\x01') {
      DAT_0006 = '\0';
    }
    else if (DAT_0006 == '\x03') {
      DAT_0006 = '\x02';
    }
    else if (DAT_0006 == '\x05') {
      DAT_0006 = '\x04';
    }
    else if (DAT_0006 == '\a') {
      DAT_0006 = '\x06';
    }
    DAT_0007 = _DAT_0004[1];
    if (DAT_0007 == 1) {
      DAT_0007 = 0;
    }
    else if (DAT_0007 == 3) {
      DAT_0007 = 2;
    }
    else if (DAT_0007 == 5) {
      DAT_0007 = 4;
    }
    else if (DAT_0007 == 7) {
      DAT_0007 = 6;
    }
    DAT_0006 = DAT_0006 << 4;
    *pbVar4 = DAT_0007 & 0xf | DAT_0006;
    _DAT_0004 = _DAT_0004 + 2;
    pbVar4 = pbVar4 + 1;
    DAT_0002._1_1_ = (char)DAT_0002 + -1;
  } while ((char)DAT_0002 != '\0');
  pcVar3 = &DAT_01fa + param_1;
  DAT_0002._1_1_ = *pcVar3;
  if (((char)DAT_0002 == '\x03') || ((char)DAT_0002 == '\x02')) {
    DAT_0005 = param_1 >> 1;
    DAT_0004 = 0;
    uStack_10 = (code *)0x8c5f;
    pbVar4 = (byte *)pack_pair((short)&uStack_10 + 1);
    if ((bool)(extraout_CC >> 1 & 1)) {
      DAT_0001 = DAT_0004 & 0xf;
      *pbVar4 = DAT_0001;
      cVar1 = (char)DAT_0002;
      if (DAT_0000 != '\x01') goto LAB_8cc9;
      uStack_10 = (code *)0x8c89;
      pbVar4 = (byte *)mode_convert((char)DAT_0002);
      cVar1 = extraout_A_00;
      goto LAB_8cd3;
    }
    DAT_0001 = DAT_0004 & 0xf0;
    *pbVar4 = DAT_0001;
    cVar1 = (char)DAT_0002;
    if (DAT_0000 == '\x01') {
      uStack_10 = (code *)0x8c72;
      pbVar4 = (byte *)mode_convert((char)DAT_0002);
      bVar2 = extraout_A;
      goto LAB_8cd6;
    }
LAB_8caf:
    uStack_10 = (code *)0x8cb2;
    cVar1 = mode_convert(cVar1);
  }
  else {
    if (DAT_0000 == '\x01') {
      return;
    }
    DAT_0005 = param_1 >> 1;
    DAT_0004 = 0;
    uStack_10 = (code *)0x8c9f;
    pbVar4 = (byte *)pack_pair((short)&uStack_10 + 1);
    if ((bool)(extraout_CC_00 >> 1 & 1)) {
      DAT_0001 = DAT_0004 & 0xf;
      *pbVar4 = DAT_0001;
      cVar1 = (char)DAT_0002;
      if (DAT_0002._0_1_ == '\x01') {
        cVar1 = *pcVar3;
LAB_8cc9:
        uStack_10 = (code *)0x8ccc;
        cVar1 = mode_convert(cVar1);
      }
      uStack_10 = (code *)0x8cd3;
      pbVar4 = (byte *)mode_remap(cVar1);
      cVar1 = extraout_A_02;
LAB_8cd3:
      bVar2 = cVar1 << 4;
      goto LAB_8cd6;
    }
    DAT_0001 = DAT_0004 & 0xf0;
    *pbVar4 = DAT_0001;
    cVar1 = (char)DAT_0002;
    if (DAT_0002._0_1_ == '\x01') {
      cVar1 = *pcVar3;
      goto LAB_8caf;
    }
  }
  uStack_10 = (code *)0x8cb9;
  pbVar4 = (byte *)mode_remap(cVar1);
  bVar2 = extraout_A_01;
LAB_8cd6:
  *pbVar4 = bVar2 | DAT_0001;
  DAT_01f9 = 0;
  uStack_10 = (code *)0x8ce8;
  button_bitmask_handler(&local_e);
  auStack_7[0] = 0;
  uStack_10 = (code *)0x8ced;
  seq_alloc_2();
  DAT_0002._0_1_ = 7;
  DAT_0001 = 0;
  DAT_0000 = 0x18;
                    /* WARNING: Subroutine does not return */
  uStack_10 = noop_d;
  message_post_loop((char)DAT_0002,auStack_7);
}

// FUNC 0x8c31  idle_reply_builder

void idle_reply_builder(short param_1,undefined1 param_2)

{
  byte extraout_CC;
  byte extraout_CC_00;
  byte extraout_A;
  char extraout_A_00;
  char cVar1;
  byte extraout_A_01;
  char extraout_A_02;
  byte bVar2;
  undefined1 *puVar3;
  char *pcVar4;
  byte *pbVar5;
  
  puVar3 = (undefined1 *)(param_1 + 2);
  DAT_0002._1_1_ = '\x06';
  do {
    *puVar3 = 0x88;
    puVar3 = puVar3 + 1;
    DAT_0002._1_1_ = (char)DAT_0002 + -1;
  } while ((char)DAT_0002 != '\0');
  pcVar4 = &DAT_01fa + DAT_0001;
  DAT_0002._1_1_ = *pcVar4;
  if (((char)DAT_0002 == '\x03') || ((char)DAT_0002 == '\x02')) {
    DAT_0005 = DAT_0001 >> 1;
    DAT_0004 = 0;
    pbVar5 = (byte *)pack_pair();
    if ((bool)(extraout_CC >> 1 & 1)) {
      DAT_0001 = DAT_0004 & 0xf;
      *pbVar5 = DAT_0001;
      cVar1 = (char)DAT_0002;
      if (DAT_0000 != '\x01') goto LAB_8cc9;
      pbVar5 = (byte *)mode_convert((char)DAT_0002);
      cVar1 = extraout_A_00;
      goto LAB_8cd3;
    }
    DAT_0001 = DAT_0004 & 0xf0;
    *pbVar5 = DAT_0001;
    cVar1 = (char)DAT_0002;
    if (DAT_0000 == '\x01') {
      pbVar5 = (byte *)mode_convert((char)DAT_0002);
      bVar2 = extraout_A;
      goto LAB_8cd6;
    }
LAB_8caf:
    cVar1 = mode_convert(cVar1);
  }
  else {
    if (DAT_0000 == '\x01') {
      return;
    }
    DAT_0005 = DAT_0001 >> 1;
    DAT_0004 = 0;
    pbVar5 = (byte *)pack_pair();
    if ((bool)(extraout_CC_00 >> 1 & 1)) {
      DAT_0001 = DAT_0004 & 0xf;
      *pbVar5 = DAT_0001;
      cVar1 = (char)DAT_0002;
      if (DAT_0002._0_1_ == '\x01') {
        cVar1 = *pcVar4;
LAB_8cc9:
        cVar1 = mode_convert(cVar1);
      }
      pbVar5 = (byte *)mode_remap(cVar1);
      cVar1 = extraout_A_02;
LAB_8cd3:
      bVar2 = cVar1 << 4;
      goto LAB_8cd6;
    }
    DAT_0001 = DAT_0004 & 0xf0;
    *pbVar5 = DAT_0001;
    cVar1 = (char)DAT_0002;
    if (DAT_0002._0_1_ == '\x01') {
      cVar1 = *pcVar4;
      goto LAB_8caf;
    }
  }
  pbVar5 = (byte *)mode_remap(cVar1);
  bVar2 = extraout_A_01;
LAB_8cd6:
  *pbVar5 = bVar2 | DAT_0001;
  DAT_01f9 = 0;
  button_bitmask_handler(&stack0x0001);
  param_2 = 0;
  seq_alloc_2();
  DAT_0002._0_1_ = 7;
  DAT_0001 = 0;
  DAT_0000 = 0x18;
                    /* WARNING: Subroutine does not return */
  message_post_loop((char)DAT_0002,&param_2);
}

// FUNC 0x8d00  noop_d

void noop_d(void)

{
  return;
}

// FUNC 0x8d03  counter_inc

void counter_inc(void)

{
  DAT_0002._1_1_ = (char)DAT_0002 + '\x01';
  if ((((char)DAT_0002 == '\0') &&
      (DAT_0002._0_1_ = DAT_0002._0_1_ + '\x01', DAT_0002._0_1_ == '\0')) &&
     (DAT_0001 = DAT_0001 + '\x01', DAT_0001 == '\0')) {
    DAT_0000 = DAT_0000 + '\x01';
  }
  return;
}

// FUNC 0x8d16  arith_sub

void arith_sub(void)

{
  DAT_0002._1_1_ = (char)DAT_0002 - DAT_0007;
  DAT_0002._0_1_ = (DAT_0002._0_1_ - DAT_0006) - (DAT_0002._0_1_ < DAT_0006);
  DAT_0001 = (DAT_0001 - DAT_0005) - (DAT_0001 < DAT_0005);
  DAT_0000 = (DAT_0000 - DAT_0004) - (DAT_0000 < DAT_0004);
  return;
}

// FUNC 0x8d31  mul_wide

/* Wide multiply helper (MUL with carry). */

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
  sVar2 = (uVar3 & 0xff) * (ushort)(byte)DAT_0002 +
          (ushort)DAT_0006 * (ushort)DAT_0002._0_1_ +
          (uVar5 & 0xff) * (ushort)DAT_0001 +
          (ushort)(byte)(DAT_0004 * (byte)DAT_0002 +
                        DAT_0005 * DAT_0002._0_1_ + DAT_0006 * DAT_0001 + DAT_0007 * DAT_0000) *
          0x100;
  DAT_0000 = (char)((ushort)sVar2 >> 8);
  uVar3 = (uVar5 & 0xff) * (ushort)DAT_0002._0_1_;
  uVar4 = uVar3 + sVar2 * 0x100;
  if (CARRY2(uVar3,sVar2 * 0x100)) {
    DAT_0000 = DAT_0000 + '\x01';
  }
  sVar2 = (ushort)DAT_0006 * (ushort)(byte)DAT_0002 + uVar4;
  DAT_0001 = (byte)((ushort)sVar2 >> 8);
  if (CARRY2((ushort)DAT_0006 * (ushort)(byte)DAT_0002,uVar4)) {
    DAT_0000 = DAT_0000 + '\x01';
  }
  sVar7 = CONCAT11(DAT_0000,DAT_0001);
  uVar5 = (uVar5 & 0xff) * (ushort)(byte)DAT_0002;
  sVar6 = uVar5 + sVar2 * 0x100;
  DAT_0002._0_1_ = (byte)((ushort)sVar6 >> 8);
  DAT_0002._1_1_ = (byte)sVar6;
  if (CARRY2(uVar5,sVar2 * 0x100)) {
    sVar7 = CONCAT11(DAT_0000,DAT_0001) + 1;
  }
  DAT_0000 = (char)((ushort)sVar7 >> 8);
  DAT_0001 = (byte)sVar7;
  return;
}

// FUNC 0x8dbb  div_path

void div_path(void)

{
  load_a();
  div_helper();
  return;
}

// FUNC 0x8dc0  div_small

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void div_small(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  char cVar6;
  ushort uVar7;
  ushort uVar8;
  
  load_b();
  uVar7 = DAT_0002;
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
      DAT_0002._1_1_ = (byte)DAT_0002 << 1 | bVar5;
      DAT_0002._0_1_ = SUB41(uVar4,1);
      DAT_0002._0_1_ = DAT_0002._0_1_ << 1 | uVar2 != 0;
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
    _DAT_0000 = CONCAT22(~_DAT_0000,~DAT_0002);
    return;
  }
  if (_DAT_0004 == 0) {
    uVar7 = DAT_0002 % _DAT_0006;
    _DAT_0000 = (uint)(DAT_0002 / _DAT_0006);
    _DAT_0006 = uVar7;
    return;
  }
  _DAT_0004 = _DAT_0000;
  _DAT_0000 = 0;
  _DAT_0006 = uVar7;
  return;
}

// FUNC 0x8dc3  div_helper

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* 32-bit division/modulo helper (compiler library). */

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
  
  uVar7 = DAT_0002;
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
      DAT_0002._1_1_ = (byte)DAT_0002 << 1 | bVar5;
      DAT_0002._0_1_ = SUB41(uVar4,1);
      DAT_0002._0_1_ = DAT_0002._0_1_ << 1 | uVar2 != 0;
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
    _DAT_0000 = CONCAT22(~_DAT_0000,~DAT_0002);
    return;
  }
  if (_DAT_0004 == 0) {
    uVar7 = DAT_0002 % _DAT_0006;
    _DAT_0000 = (uint)(DAT_0002 / _DAT_0006);
    _DAT_0006 = uVar7;
    return;
  }
  _DAT_0004 = _DAT_0000;
  _DAT_0000 = 0;
  _DAT_0006 = uVar7;
  return;
}

// FUNC 0x8e30  noop

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void noop(void)

{
  return;
}

// FUNC 0x8e40  reg_snapshot

void reg_snapshot(char param_1)

{
  byte bVar1;
  byte bVar2;
  
  if (param_1 != '\0') {
    do {
      bVar1 = (byte)DAT_0002 & 0x80;
      DAT_0002._1_1_ = (byte)DAT_0002 << 1;
      bVar2 = DAT_0002._0_1_ & 0x80;
      DAT_0002._0_1_ = DAT_0002._0_1_ << 1 | bVar1 != 0;
      bVar1 = DAT_0001 & 0x80;
      DAT_0001 = DAT_0001 << 1 | bVar2 != 0;
      DAT_0000 = DAT_0000 << 1 | bVar1 != 0;
      param_1 = param_1 + -1;
    } while (param_1 != '\0');
  }
  return;
}

// FUNC 0x8e51  init_pair

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void init_pair(short param_1)

{
  DAT_0002 = param_1;
  _DAT_0000 = 0;
  if (param_1 < 0) {
    _DAT_0000 = 0xffff;
  }
  return;
}

// FUNC 0x8e5c  system_init

/* System init. Calls uart1_init_2400, clk_set_divider, uart1_set_control_bits,
   sub_9b72 (output init), enables interrupts, posts message 0x1B. */

void system_init(void)

{
  char cVar1;
  
  bank_post_8();
  bank_post_c();
  clk_gate_enable_1();
  clk_reg_a(0);
  DAT_0002._0_1_ = 0;
  DAT_0001 = 0;
  DAT_0000 = 0xe1;
  clk_switch();
  iwdg_setup();
  iwdg_refresh();
  DAT_0000 = 0x7c;
  tim4_egr_set();
  tim4_ier_set();
  DAT_0000 = 1;
  tim4_etr_write();
  tim4_enable();
  uart1_init_2400();
  uart1_clear_20();
  outputs_init();
  clk_set_divider();
  DAT_0000 = 1;
  uart1_set_control_bits();
  DAT_0000 = 0;
  uart1_set_control_bits();
  DAT_0000 = 0;
  uart1_set_control_bits();
  DAT_025f = 0;
  pa_outputs_init();
  __EnableInterrupt();
  state_table_init();
  cVar1 = DAT_02cf;
  DAT_0002._1_1_ = DAT_02cf;
  DAT_02cf = DAT_02cf + '\x01';
  DAT_0002._0_1_ = 1;
  DAT_0001 = 2;
  DAT_0000 = 0x1b;
                    /* WARNING: Subroutine does not return */
  message_post_loop(cVar1,&DAT_0206);
}

// FUNC 0x8ee6  link_service_loop

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Link service loop. When uart_flag_c is set, copies the RX frame and calls frame_handler.
   Also services DAT_02d5/DAT_025f and the pin-table block at UNK_01bf. */

void link_service_loop(void)

{
  byte extraout_CC;
  char cVar1;
  char extraout_A;
  short sVar2;
  
  do {
    if (uart_flag_c != '\0') {
      DAT_0008 = (undefined *)CONCAT11(rx_frame_len,DAT_0008._1_1_);
      _DAT_0000 = (ushort)rx_frame_len;
      block_copy(uart_flag_c,&DAT_021d);
      DAT_023d = DAT_0008._0_1_;
      rx_frame_len = 0;
      uart_flag_c = '\0';
      frame_handler();
      DAT_023d = 0;
    }
    cVar1 = DAT_02d5;
    if (DAT_02d5 != '\0') {
      _DAT_0000 = (ushort)DAT_025f;
      block_copy(&UNK_0280);
      DAT_02d6 = DAT_025f;
      DAT_025f = 0;
      bank_prelude();
      DAT_02d5 = '\0';
      cVar1 = pa_outputs_init();
    }
    DAT_0008 = &UNK_01bf;
    DAT_000a._0_1_ = '\x05';
    do {
      if (DAT_0008[-1] != '\0') {
        DAT_000c = DAT_0008 + 4;
        load_pair_0(cVar1);
        sVar2 = noop(DAT_0008);
        cVar1 = extraout_A;
        if (!(bool)(extraout_CC & 1)) {
          if (*(short *)(sVar2 + 8) != 0) {
            func_0x0000eb80();
          }
          DAT_0002 = 0;
          _DAT_0000 = 0;
          cVar1 = store_pair_0(DAT_000c);
        }
      }
      DAT_0008 = DAT_0008 + 0xb;
      DAT_000a._0_1_ = DAT_000a._0_1_ + -1;
    } while (DAT_000a._0_1_ != '\0');
    iwdg_refresh();
  } while( true );
}

// FUNC 0x8f7e  uart1_configure

/* UART1 configure (Roadstm8true, 2026-11-09). Caller is uart1_init_2400 at 0x9B17.
   Caller sets DAT_0007=0x0C, DAT_0006=0x80, DAT_0005=0, DAT_0004=0, DAT_0002=0x960 (2400)
   then CALLs this function. BRR1/BRR2 split via sub_99dc (>>4). Live value: 2400 baud
   (BRR1=0xA0, BRR2=0x1A, divider 6666). See docs/mode_timing.md. */

void uart1_configure(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte extraout_A;
  byte extraout_A_00;
  ushort uVar4;
  byte extraout_XL;
  undefined2 uStack_3;
  
  bank_set_8();
  bVar3 = bank_set_c();
  bVar2 = DAT_0007;
  bVar1 = DAT_0006;
  UART1_CR1 = UART1_CR1 & 0xef;
  UART1_CR3 = UART1_CR3 & 0xcf | DAT_0004;
  UART1_CR1 = (UART1_CR1 | bVar3) & 0xf9 | DAT_0005;
  UART1_BRR1 = 0;
  UART1_BRR2 = 0;
  DAT_0006 = bVar3;
  reg_snapshot();
  save_ptr_2();
  baud_lookup();
  save_ptr_1();
  div_helper();
  uVar4 = get_arg_ptr_2();
  baud_lookup((char)uVar4,(ushort)extraout_A << 8 | uVar4 >> 8);
  save_ptr_3();
  uVar4 = get_arg_ptr();
  mul_wide_call((char)uVar4,(ushort)extraout_A_00 << 8 | uVar4 >> 8);
  bank_set_0();
  save_ptr_0();
  mul_wide_call();
  save_ptr_1();
  div_helper();
  save_pair_1();
  arith_sub();
  reg_snapshot();
  div_small();
  UART1_BRR2 = (byte)DAT_0002 & 0xf | UART1_BRR2;
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
  save_regs_2();
  return;
}

// FUNC 0x8fb5  uart1_configure_ex

/* UART1 configure with explicit params (CR1/BRR/CR2/CR3 from args). */

void uart1_configure_ex(byte param_1,undefined2 param_2,byte param_3,byte param_4)

{
  byte extraout_A;
  byte extraout_A_00;
  ushort uVar1;
  byte extraout_XL;
  
  UART1_CR1 = param_1 | DAT_0005;
  UART1_BRR1 = 0;
  UART1_BRR2 = 0;
  reg_snapshot();
  save_ptr_2();
  baud_lookup();
  save_ptr_1();
  div_helper();
  uVar1 = get_arg_ptr_2();
  baud_lookup((char)uVar1,(ushort)extraout_A << 8 | uVar1 >> 8);
  save_ptr_3();
  uVar1 = get_arg_ptr();
  mul_wide_call((char)uVar1,(ushort)extraout_A_00 << 8 | uVar1 >> 8);
  bank_set_0();
  save_ptr_0();
  mul_wide_call();
  save_ptr_1();
  div_helper();
  save_pair_1();
  arith_sub();
  reg_snapshot();
  div_small();
  UART1_BRR2 = (byte)DAT_0002 & 0xf | UART1_BRR2;
  shr_4(param_2);
  UART1_BRR2 = extraout_XL & 0xf0 | UART1_BRR2;
  UART1_BRR1 = (byte)param_2 | UART1_BRR1;
  UART1_CR2 = UART1_CR2 & 0xf3;
  if ((param_3 & 4) != 0) {
    UART1_CR2 = UART1_CR2 | 8;
  }
  if ((param_3 & 8) != 0) {
    UART1_CR2 = UART1_CR2 | 4;
  }
  if ((param_4 & 0x80) == 0) {
    UART1_CR3 = param_4 & 8 | param_4 & 7 | UART1_CR3 & 0xf8;
  }
  else {
    UART1_CR3 = param_4 & 7 | UART1_CR3 & 0xf0;
  }
  save_regs_2();
  return;
}

// FUNC 0x908a  bank_0_call

void bank_0_call(void)

{
  bank_fn_9099(0);
  return;
}

// FUNC 0x908f  bank_post_8

void bank_post_8(void)

{
  bank_fn_9099(8);
  return;
}

// FUNC 0x9094  bank_post_c

void bank_post_c(void)

{
  bank_fn_9099(0xc);
  return;
}

// FUNC 0x9099  bank_fn_9099

undefined2 bank_fn_9099(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x90ac  frame_push_0

void frame_push_0(undefined2 param_1)

{
  DAT_0008 = param_1;
  stack_ret();
  return;
}

// FUNC 0x90b3  frame_push_1

void frame_push_1(undefined2 param_1)

{
  DAT_000c = param_1;
  stack_ret();
  return;
}

// FUNC 0x90ba  stack_ret

undefined2 stack_ret(void)

{
  undefined2 in_stack_00000001;
  
  return in_stack_00000001;
}

// FUNC 0x90c2  bank_set_0

void bank_set_0(void)

{
  identity_fn(0);
  return;
}

// FUNC 0x90c7  bank_set_4

void bank_set_4(void)

{
  identity_fn(4);
  return;
}

// FUNC 0x90cc  bank_set_8

void bank_set_8(void)

{
  identity_fn(8);
  return;
}

// FUNC 0x90d1  bank_set_c

void bank_set_c(void)

{
  identity_fn(0xc);
  return;
}

// FUNC 0x90d6  identity_fn

undefined2 identity_fn(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x90f3  save_pair_0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void save_pair_0(undefined2 param_1,undefined2 param_2)

{
  _DAT_0000 = param_1;
  DAT_0002 = param_2;
  stack_ret_2();
  return;
}

// FUNC 0x90fe  save_pair_1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void save_pair_1(undefined2 param_1,undefined2 param_2)

{
  _DAT_0004 = param_1;
  _DAT_0006 = param_2;
  stack_ret_2();
  return;
}

// FUNC 0x9109  save_pair_2

void save_pair_2(undefined2 param_1,undefined2 param_2)

{
  DAT_0008 = param_1;
  DAT_000a = param_2;
  stack_ret_2();
  return;
}

// FUNC 0x9114  save_pair_3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void save_pair_3(undefined2 param_1,undefined2 param_2)

{
  DAT_000c = param_1;
  _DAT_000e = param_2;
  stack_ret_2();
  return;
}

// FUNC 0x911f  stack_ret_2

undefined2 stack_ret_2(void)

{
  undefined2 in_stack_00000001;
  
  return in_stack_00000001;
}

// FUNC 0x9127  save_regs_2

void save_regs_2(void)

{
  save_pair_3();
  save_pair_2();
  return;
}

// FUNC 0x912a  save_pair_2w

void save_pair_2w(void)

{
  save_pair_2();
  return;
}

// FUNC 0x912e  save_regs_chain

void save_regs_chain(void)

{
  frame_push_1();
  save_pair_2();
  return;
}

// FUNC 0x9135  frame_push_call

void frame_push_call(void)

{
  frame_push_0();
  return;
}

// FUNC 0x9139  save_regs_0

void save_regs_0(void)

{
  DAT_0004 = DAT_0002._0_1_;
  DAT_0005 = (undefined1)DAT_0002;
  return;
}

// FUNC 0x9140  save_regs_1

void save_regs_1(void)

{
  DAT_000a._0_1_ = DAT_0008._0_1_;
  DAT_000a._1_1_ = (undefined1)DAT_0008;
  return;
}

// FUNC 0x9147  save_ptr_0

void save_ptr_0(void)

{
  DAT_0000 = DAT_000c._0_1_;
  DAT_0001 = (undefined1)DAT_000c;
  DAT_0002._0_1_ = DAT_000e;
  DAT_0002._1_1_ = DAT_000f;
  return;
}

// FUNC 0x9154  save_ptr_1

void save_ptr_1(void)

{
  DAT_0004 = DAT_0008._0_1_;
  DAT_0005 = (undefined1)DAT_0008;
  DAT_0006 = DAT_000a._0_1_;
  DAT_0007 = (undefined1)DAT_000a;
  return;
}

// FUNC 0x9161  save_ptr_2

void save_ptr_2(void)

{
  DAT_0008._0_1_ = DAT_0000;
  DAT_0008._1_1_ = DAT_0001;
  DAT_000a._0_1_ = DAT_0002._0_1_;
  DAT_000a._1_1_ = (undefined1)DAT_0002;
  return;
}

// FUNC 0x916e  save_ptr_3

void save_ptr_3(void)

{
  DAT_000c._0_1_ = DAT_0000;
  DAT_000c._1_1_ = DAT_0001;
  DAT_000e = DAT_0002._0_1_;
  DAT_000f = (undefined1)DAT_0002;
  return;
}

// FUNC 0x917b  state_table_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void state_table_init(void)

{
  char cVar1;
  short sVar2;
  
  _DAT_0000 = &UNK_01bf;
  cVar1 = '\x05';
  do {
    _DAT_0000[-1] = 0;
    _DAT_0006 = 0;
    _DAT_0004 = 0;
    sVar2 = store_pair_1(cVar1,_DAT_0000);
    cVar1 = store_pair_1(sVar2 + 4);
    *(undefined2 *)(_DAT_0000 + 8) = 0;
    _DAT_0000 = _DAT_0000 + 0xb;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  DAT_01d4 = 1;
  _DAT_01d5 = 0;
  _DAT_01d7 = 0x4b;
  _DAT_01d9 = 0;
  _DAT_01db = 0;
  _DAT_01dd = tx_queue_drain;
  DAT_01c9 = 1;
  _DAT_01ca = 0;
  _DAT_01cc = 0x32;
  _DAT_01ce = 0;
  _DAT_01d0 = 0;
  _DAT_01d2 = mode_tick;
  DAT_0002 = (ushort)DAT_0206;
  _DAT_0000 = (undefined *)0x0;
  DAT_01be = DAT_0206 != 0;
  store_pair_0(&UNK_01bf);
  _DAT_01c3 = 0;
  _DAT_01c5 = 0;
  _DAT_01c7 = channels_apply;
  DAT_01ea = 1;
  _DAT_01eb = 0;
  _DAT_01ed = 10;
  _DAT_01ef = 0;
  _DAT_01f1 = 0;
  _DAT_01f3 = tx_index;
  return;
}

// FUNC 0x9223  acc_sense_sample

/* ACC sense sample. Reads PA_IDR bit1 (PA1), debounce 8 samples into DAT_02da,
   stores to DAT_0260. DT/DAT_02d4 selects the sample vs reset path. */

undefined2 acc_sense_sample(undefined2 param_1)

{
  undefined1 uVar1;
  byte extraout_XL;
  
  bank_set_0();
  bank_set_4();
  uVar1 = DAT_0008._0_1_;
  DAT_0008._0_1_ = 1;
  if (DAT_02d4 == '\0') {
    DAT_02db = 8;
    if (DAT_02d9 < 8) {
      if ((PA_IDR & 2) != 0) {
        shift_loop(1);
        DAT_02da = extraout_XL | DAT_02da;
      }
      DAT_02d9 = DAT_02d9 + 1;
      if (DAT_02d9 == 8) {
        DAT_02d9 = 0;
        (&DAT_0260)[DAT_025f] = DAT_02da;
        DAT_025f = DAT_025f + 1;
        if (DAT_025f == 0x20) {
          DAT_02db = 0;
          DAT_02d5 = 1;
        }
        else {
          pa_outputs_init();
        }
        DAT_02da = 0;
        tim2_off();
        tim4_enable(1);
      }
    }
  }
  else {
    tim4_reset(0x60e);
    DAT_02d9 = 0;
    DAT_02da = 0;
    DAT_02d4 = '\0';
    DAT_02db = 8;
  }
  tim2_sr1_clear(1);
  DAT_0008._0_1_ = uVar1;
  save_pair_1();
  save_pair_0();
  return param_1;
}

// FUNC 0x92c2  channels_apply

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void channels_apply(void)

{
  undefined1 uVar1;
  char *pcVar2;
  char *in_Y;
  
  bank_set_8();
  bank_post_c();
  uVar1 = DAT_000e;
  DAT_000c = &DAT_02df;
  DAT_0008 = &DAT_0182;
  DAT_000e = '\f';
  do {
    if (*DAT_0008 != '\0') {
      save_regs_1();
      pcVar2 = DAT_000a + 1;
      DAT_000a = pcVar2;
      if (*pcVar2 == '\x05') {
        load_000c();
        pcVar2 = (char *)pin_or();
      }
      if (*DAT_000a == '\0') {
        pcVar2 = (char *)channel_ptr_2();
        if (*pcVar2 == '\x05') {
          load_000c();
          pcVar2 = (char *)pin_and();
          goto LAB_9304;
        }
      }
      else {
LAB_9304:
        if (*DAT_000a != '\0') {
          *DAT_000a = *DAT_000a + -1;
          goto LAB_9348;
        }
      }
      in_Y = (char *)channel_ptr_2(in_Y);
      if (*in_Y == '\0') {
        _DAT_0000 = (char *)channel_ptr_3(pcVar2);
        if (*_DAT_0000 == '\0') {
          pcVar2 = (char *)channel_ptr_4();
          if (*pcVar2 == '\0') {
            *DAT_000a = '\x05';
            *in_Y = '\x05';
            *_DAT_0000 = '\x04';
            *pcVar2 = '\x19';
          }
          else {
            *pcVar2 = *pcVar2 + -1;
          }
        }
        else {
          *_DAT_0000 = *_DAT_0000 + -1;
          *DAT_000a = '\x05';
          *in_Y = '\x05';
        }
      }
      else {
        *in_Y = *in_Y + -1;
      }
    }
LAB_9348:
    DAT_0008 = (char *)channel_ptr_5();
    DAT_000c = DAT_000c + 3;
    DAT_000e = DAT_000e + -1;
    if (DAT_000e == '\0') {
      DAT_000e = uVar1;
      save_regs_chain();
      return;
    }
  } while( true );
}

// FUNC 0x935e  tx_queue_drain

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* TX queue drain. Loops msg_post/msg_peek over 0..9, decrements counts,
   then scans DAT_02ce queue for zero-count messages. */

void tx_queue_drain(void)

{
  short sVar1;
  byte extraout_CC;
  byte extraout_CC_00;
  byte bVar2;
  char extraout_A;
  char *pcVar3;
  ushort uVar4;
  
  bVar2 = 0;
  do {
    uVar4 = (ushort)bVar2;
    msg_post(bVar2);
    pcVar3 = (char *)msg_peek(uVar4);
    if (*pcVar3 != '\0') {
      sVar1 = *(short *)(pcVar3 + 1);
      if (sVar1 != 0) {
        *(short *)(pcVar3 + 1) = sVar1 + -1;
      }
    }
    bVar2 = extraout_A + 1;
  } while (bVar2 < 10);
  DAT_02cd = DAT_02ce;
  while( true ) {
    if (9 < DAT_02ce) {
      return;
    }
    _DAT_0000 = (char *)0x25;
    _DAT_0000 = (char *)msg_peek(DAT_02ce);
    if ((*_DAT_0000 != '\0') && (*(short *)(_DAT_0000 + 1) == 0)) break;
    seq_inc();
    if (!(bool)(extraout_CC_00 & 1)) {
      DAT_02ce = 0;
    }
    if (DAT_02ce == DAT_02cd) {
      return;
    }
  }
  DAT_0002 = _DAT_0000 + 3;
  if (*DAT_0002 == '\0') {
    *_DAT_0000 = '\0';
  }
  else {
    *(short *)(_DAT_0000 + 1) = 3;
    *DAT_0002 = *DAT_0002 + -1;
  }
  uart_state_a = DAT_02ce;
  tim4_init();
  uart1_cr_write();
  seq_inc();
  if ((bool)(extraout_CC & 1)) {
    return;
  }
  DAT_02ce = 0;
  return;
}

// FUNC 0x93e5  clk_switch

undefined1 clk_switch(char param_1)

{
  short sVar1;
  
  sVar1 = -1;
  DAT_0004 = CLK_CMSR;
  if (param_1 == '\x01') {
    if (DAT_0001 == '\0') {
      CLK_SWCR = CLK_SWCR & 0xfb | 2;
    }
    else {
      CLK_SWCR = CLK_SWCR | 6;
    }
    while ((CLK_SWCR & 1) != 0) {
      if (sVar1 == 0) {
        DAT_0002._1_1_ = 0;
        CLK_SWR = DAT_0000;
        return 0;
      }
      sVar1 = sVar1 + -1;
    }
    if (sVar1 == 0) {
      DAT_0002._1_1_ = 0;
      CLK_SWR = DAT_0000;
      return 0;
    }
  }
  else {
    if (DAT_0001 == '\0') {
      CLK_SWCR = CLK_SWCR & 0xfb;
    }
    else {
      CLK_SWCR = CLK_SWCR | 4;
    }
    while ((CLK_SWCR & 8) != 0) {
      if (sVar1 == 0) {
        DAT_0002._1_1_ = 0;
        CLK_SWR = DAT_0000;
        return 0;
      }
      sVar1 = sVar1 + -1;
    }
    if (sVar1 == 0) {
      DAT_0002._1_1_ = 0;
      CLK_SWR = DAT_0000;
      return 0;
    }
    CLK_SWCR = CLK_SWCR | 2;
  }
  DAT_0002._1_1_ = 1;
  if (DAT_0002._0_1_ == '\0') {
    if (CLK_CMSR == -0x1f) {
      CLK_ICKR = CLK_ICKR & 0xfe;
    }
    else if (CLK_CMSR == -0x2e) {
      CLK_ICKR = CLK_ICKR & 0xf7;
    }
    else if (CLK_CMSR == -0x4c) {
      CLK_ECKR = CLK_ECKR & 0xfe;
    }
  }
  CLK_SWR = DAT_0000;
  return 1;
}

// FUNC 0x9464  clk_set_divider

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void clk_set_divider(void)

{
  char cVar1;
  undefined1 *puVar2;
  
  _DAT_0000 = &UNK_0172;
  memset_like(0x10);
  _DAT_0000 = (undefined *)0x21;
  memset_like(&DAT_021d);
  boot_chain();
  load_pair_0(&DAT_01f5);
  if (_DAT_0000 != &UNK_0134 || DAT_0002 != -0x4bdf) {
    _DAT_01f5 = &UNK_0134;
    _DAT_01f7 = 0xb421;
    DAT_0206 = 10;
    DAT_01f9 = 1;
    puVar2 = &DAT_01fa;
    cVar1 = '\f';
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
      cVar1 = cVar1 + -1;
    } while (cVar1 != '\0');
    reset_state();
    eeprom_rd_a();
  }
  puVar2 = &DAT_02a0;
  cVar1 = '\f';
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 2;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  DAT_01f9 = 1;
  if ((DAT_0206 == 0) || (100 < DAT_0206)) {
    DAT_0206 = 10;
  }
  return;
}

// FUNC 0x94d6  outputs_init

/* Outputs init. GPIO_Init on PD (0x40), tim2_set_ccr1l twice, then iterates the
   12-entry pin table at DAT_02df calling sub_9541 + FUN_9f12 per channel. */

void outputs_init(void)

{
  undefined1 uVar1;
  
  bank_set_8();
  uVar1 = DAT_000c._0_1_;
  DAT_0000 = 0x40;
  gpio_init(&PD_ODR);
  DAT_0000 = 0x40;
  gpio_init(0x10,&PD_ODR);
  pin_state_d3 = tim2_set_ccr1l(8,&PD_ODR);
  pin_state_d4 = tim2_set_ccr1l(0x10,&PD_ODR);
  DAT_0008 = (undefined2 *)&DAT_02df;
  DAT_000c._0_1_ = '\f';
  do {
    save_regs_1();
    DAT_000a = DAT_000a + 2;
    DAT_0000 = 0xc0;
    gpio_init(*DAT_000a,*DAT_0008);
    pin_and(*DAT_000a,*DAT_0008);
    DAT_0008 = (undefined2 *)((short)DAT_0008 + 3);
    DAT_000c._0_1_ = DAT_000c._0_1_ + -1;
  } while (DAT_000c._0_1_ != '\0');
  DAT_000c._0_1_ = uVar1;
  save_pair_2w();
  return;
}

// FUNC 0x9541  gpio_init

/* GPIO_Init helper (SPL-style). Mode bits 0x80/0x10 in DAT_0000 select
   ODR/DDR/CR1/CR2 read-modify-write via the port pointer. */

void gpio_init(byte param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  DAT_0001 = ~param_1;
  pbVar2 = param_2 + 4;
  DAT_0002 = param_2;
  DAT_0004 = param_1;
  *pbVar2 = *pbVar2 & DAT_0001;
  if ((DAT_0000 & 0x80) == 0) {
    pbVar3 = DAT_0002 + 2;
    bVar1 = *pbVar3 & DAT_0001;
  }
  else {
    if ((DAT_0000 & 0x10) == 0) {
      bVar1 = *DAT_0002 & DAT_0001;
    }
    else {
      bVar1 = *DAT_0002 | DAT_0004;
    }
    *DAT_0002 = bVar1;
    pbVar3 = DAT_0002 + 2;
    bVar1 = *pbVar3 | DAT_0004;
  }
  *pbVar3 = bVar1;
  pbVar3 = DAT_0002 + 3;
  if ((DAT_0000 & 0x40) == 0) {
    bVar1 = *pbVar3 & DAT_0001;
  }
  else {
    bVar1 = *pbVar3 | DAT_0004;
  }
  *pbVar3 = bVar1;
  if ((DAT_0000 & 0x20) == 0) {
    bVar1 = *pbVar2 & DAT_0001;
  }
  else {
    bVar1 = *pbVar2 | DAT_0004;
  }
  *pbVar2 = bVar1;
  return;
}

// FUNC 0x95a5  get_arg_ptr

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * get_arg_ptr(void)

{
  undefined2 *puVar1;
  byte *in_stack_00000001;
  
  puVar1 = (undefined2 *)(&stack0x0002 + *in_stack_00000001);
  _DAT_0000 = *puVar1;
  DAT_0002 = puVar1[1];
  return puVar1;
}

// FUNC 0x95b5  load_pair_0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * load_pair_0(undefined2 *param_1)

{
  _DAT_0000 = *param_1;
  DAT_0002 = param_1[1];
  return param_1;
}

// FUNC 0x95c1  load_pair_1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * load_pair_1(undefined2 *param_1)

{
  _DAT_0004 = *param_1;
  _DAT_0006 = param_1[1];
  return param_1;
}

// FUNC 0x95cd  get_arg_ptr_2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void get_arg_ptr_2(void)

{
  byte bVar1;
  byte *in_stack_00000001;
  
  bVar1 = *in_stack_00000001;
  *(undefined2 *)(&stack0x0002 + bVar1) = _DAT_0000;
  *(undefined2 *)(&stack0x0004 + bVar1) = DAT_0002;
  return;
}

// FUNC 0x95de  store_pair_0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void store_pair_0(undefined2 *param_1)

{
  *param_1 = _DAT_0000;
  param_1[1] = DAT_0002;
  return;
}

// FUNC 0x95ec  store_pair_1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void store_pair_1(undefined2 *param_1)

{
  *param_1 = _DAT_0004;
  param_1[1] = _DAT_0006;
  return;
}

// FUNC 0x95fa  store_pair_2

void store_pair_2(undefined2 *param_1)

{
  *param_1 = DAT_0008;
  param_1[1] = DAT_000a;
  return;
}

// FUNC 0x9608  tim4_isr

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 tim4_isr(undefined2 param_1)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  
  noop_4();
  bank_set_0();
  bank_set_4();
  puVar3 = &DAT_01c3;
  cVar2 = '\x05';
  do {
    if (puVar3[-5] != '\0') {
      load_pair_0(puVar3);
      counter_inc();
      cVar2 = store_pair_0(puVar3);
    }
    cVar1 = DAT_02db;
    puVar3 = puVar3 + 0xb;
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  if ((uart_flag_b != '\0') && (uart_flag_b = uart_flag_b + -1, uart_flag_b == '\0')) {
    uart_flag_c = 1;
  }
  if ((DAT_02db != '\0') && (DAT_02db = DAT_02db + -1, DAT_02db == '\0')) {
    DAT_02da = 0;
    DAT_02d5 = 1;
    tim2_off(cVar1);
  }
  if (_DAT_02cb != 0) {
    _DAT_02cb = _DAT_02cb + -1;
  }
  tim4_ier_set_2(1);
  save_pair_1();
  save_pair_0();
  return param_1;
}

// FUNC 0x966a  itc_spr_write

void itc_spr_write(char param_1)

{
  byte bVar1;
  
  if (param_1 == '\0') {
    ITC_SPR1 = ITC_SPR1 & 0xfc | DAT_0000;
  }
  else {
    if (param_1 == '\x01') {
      ITC_SPR1 = ITC_SPR1 & 0xf3;
      bVar1 = DAT_0000 << 2;
    }
    else if (param_1 == '\x02') {
      ITC_SPR1 = ITC_SPR1 & 0xcf;
      bVar1 = DAT_0000 << 4;
    }
    else {
      if (param_1 != '\x03') {
        if (param_1 != '\x04') {
          return;
        }
        ITC_SPR2 = ITC_SPR2 & 0xfc | DAT_0000;
        return;
      }
      ITC_SPR1 = ITC_SPR1 & 0x3f;
      bVar1 = shl_6(DAT_0000);
    }
    ITC_SPR1 = bVar1 | ITC_SPR1;
  }
  return;
}

// FUNC 0x96cb  itc_set_priority

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Interrupt priority setup via ITC_SPR1/SPR2 (0x50A0/0x50A1). */

undefined2 itc_set_priority(undefined2 param_1)

{
  ushort uVar1;
  short sVar2;
  
  noop_4();
  bank_set_0();
  bank_set_4();
  uVar1 = (ushort)DAT_02d1;
  DAT_02d1 = DAT_02d1 + 1;
  sVar2 = uVar1 + 0x14;
  DAT_0002 = (ushort)uart_state_a;
  _DAT_0000 = 0x25;
  _DAT_0000 = mul_small(DAT_0002);
  uart1_dr_write(*(undefined1 *)(sVar2 + _DAT_0000));
  _DAT_0000 = 0x25;
  sVar2 = mul_small(uart_state_a);
  if (*(char *)(sVar2 + 0x34) == DAT_02d1) {
    uart1_cr_write(0,&UNK_0277);
  }
  save_pair_1();
  save_pair_0();
  return param_1;
}

// FUNC 0x9728  uart1_cr_write

void uart1_cr_write(char param_1,undefined2 param_2)

{
  DAT_0000 = (char)((ushort)param_2 >> 8);
  DAT_0001 = param_1;
  DAT_0002._0_1_ = nibble_map((char)param_2);
  if (DAT_0001 == '\0') {
    DAT_0002._0_1_ = ~DAT_0002._0_1_;
    if (DAT_0000 != '\x01') {
      if (DAT_0000 == '\x02') {
        UART1_CR2 = UART1_CR2 & DAT_0002._0_1_;
        return;
      }
      UART1_CR4 = UART1_CR4 & DAT_0002._0_1_;
      return;
    }
    UART1_CR1 = UART1_CR1 & DAT_0002._0_1_;
  }
  else {
    if (DAT_0000 != '\x01') {
      if (DAT_0000 == '\x02') {
        UART1_CR2 = UART1_CR2 | DAT_0002._0_1_;
        return;
      }
      UART1_CR4 = UART1_CR4 | DAT_0002._0_1_;
      return;
    }
    UART1_CR1 = UART1_CR1 | DAT_0002._0_1_;
  }
  return;
}

// FUNC 0x9780  uart1_set_control_bits

void uart1_set_control_bits(char param_1)

{
  byte bVar1;
  
  DAT_0002._1_1_ = DAT_0000;
  DAT_0002._0_1_ = param_1;
  bVar1 = clk_shift();
  DAT_0004 = ~bVar1;
  DAT_0000 = DAT_0001;
  DAT_0000 = shl_loop((undefined1)DAT_0002);
  if ((((DAT_0002._0_1_ != '\f') && (DAT_0002._0_1_ != '\r')) && (DAT_0002._0_1_ != '\x0e')) &&
     (DAT_0002._0_1_ != '\x0f')) {
    if (((DAT_0002._0_1_ != '\x11') && (DAT_0002._0_1_ != '\x12')) && (DAT_0002._0_1_ != '\x17')) {
      return;
    }
    DAT_7f75 = DAT_7f75 & DAT_0004 | DAT_0000;
    return;
  }
  DAT_7f73 = DAT_7f73 & DAT_0004 | DAT_0000;
  return;
}

// FUNC 0x97d3  uart1_rx_isr

undefined2 uart1_rx_isr(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  short in_stack_00000001;
  
  noop_4();
  bank_set_0();
  bank_set_4();
  bank_post_8();
  uart_flag_b = 10;
  if ((UART1_SR & 8) != 0) {
    UART1_SR = UART1_SR & 0xf7;
  }
  DAT_0001 = rx_frame_len;
  if (rx_frame_len < 0x20) {
    rx_frame_len = rx_frame_len + 1;
    DAT_0000 = 0;
    bank_0_call();
    uVar1 = uart1_dr_read();
    puVar2 = &stack0x0002;
    (&rx_frame_data)[in_stack_00000001] = uVar1;
    register0x0008 = (BADSPACEBASE *)&stack0x0002;
    if (0x1f < rx_frame_len) {
      uart_flag_c = 1;
      uart_flag_b = 0;
      register0x0008 = (BADSPACEBASE *)puVar2;
    }
  }
  else {
    uart1_dr_read();
  }
  *(undefined2 *)((short)register0x0008 + -1) = 0x981c;
  frame_push_0();
  *(undefined2 *)((short)register0x0008 + -1) = 0x981f;
  save_pair_1();
  *(undefined2 *)((short)register0x0008 + -1) = 0x9822;
  save_pair_0();
  return *(undefined2 *)((short)register0x0008 + 3);
}

// FUNC 0x9823  mode_remap

char mode_remap(char param_1)

{
  if (param_1 == '\x01') {
    DAT_0000 = '\0';
  }
  else if (param_1 == '\0') {
    DAT_0000 = '\x01';
  }
  else if (param_1 == '\x03') {
    DAT_0000 = '\x02';
  }
  else if (param_1 == '\x02') {
    DAT_0000 = '\x03';
  }
  else if (param_1 == '\x05') {
    DAT_0000 = '\x04';
  }
  else if (param_1 == '\x04') {
    DAT_0000 = '\x05';
  }
  else {
    DAT_0000 = param_1;
    if (param_1 == '\a') {
      set_6();
    }
    else if (param_1 == '\x06') {
      DAT_0000 = '\a';
    }
  }
  return DAT_0000;
}

// FUNC 0x9872  pin_table_apply

void pin_table_apply(void)

{
  undefined1 *puVar1;
  
  bank_set_8();
  DAT_000c._0_1_ = bank_post_c();
  DAT_000a = &DAT_02b8;
  DAT_0008 = (undefined2 *)&DAT_02df;
  DAT_000c._1_1_ = '\f';
  do {
    if (*DAT_000a != '\0') {
      puVar1 = (undefined1 *)channel_ptr_2();
      if (DAT_000c._0_1_ == '\x01') {
        pin_or(*puVar1,*DAT_0008);
      }
      else {
        pin_and(*puVar1,*DAT_0008);
      }
    }
    DAT_0008 = (undefined2 *)channel_ptr_3();
    DAT_000a = DAT_000a + 1;
    DAT_000c._1_1_ = (char)DAT_000c + -1;
  } while ((char)DAT_000c != '\0');
  save_regs_chain();
  return;
}

// FUNC 0x98b6  baud_lookup

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Clock/baud lookup. Reads CLK_CMSR, looks up sub_9ef5 table by CKDIVR.
   Returns DAT_0002=0x2400 (2400 baud) for the default clock, 0xF400 otherwise. */

void baud_lookup(void)

{
  if (CLK_CMSR == -0x1f) {
    _DAT_0006 = (ushort)(byte)table_lookup[(CLK_CKDIVR >> 3 & 0xff03) + 5];
    _DAT_0004 = 0;
    div_path();
    return;
  }
  if (CLK_CMSR != -0x2e) {
    DAT_0002 = 0x2400;
    _DAT_0000 = 0xf4;
    return;
  }
  DAT_0002 = 0xf400;
  _DAT_0000 = 1;
  return;
}

// FUNC 0x98f1  clk_gate_enable_1

void clk_gate_enable_1(void)

{
  CLK_ICKR = 1;
  CLK_ECKR = 0;
  CLK_SWR = 0xe1;
  CLK_SWCR = 0;
  CLK_CKDIVR = 0x18;
  CLK_PCKENR1 = 0xff;
  CLK_PCKENR2 = 0xff;
  CLK_CSSR = 0;
  CLK_CCOR = 0;
  DAT_50cc = 0;
  DAT_50cd = 0;
  return;
}

// FUNC 0x9927  eeprom_write

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* EEPROM write helper. Called from sub_86e8 and cmd_0b_handler. */

void eeprom_write(void)

{
  undefined2 in_Y;
  
  _DAT_0004 = (undefined1 *)bank_set_8();
  *_DAT_0004 = 1;
  if (_DAT_0000 == (undefined1 *)0x0 && DAT_0002 == 0) {
    *_DAT_0004 = 0;
  }
  store_pair_0(_DAT_0004 + 1);
  _DAT_0000 = _DAT_0004 + 5;
  DAT_000a = 0;
  DAT_0008 = 0;
  store_pair_2(_DAT_0000);
  *(undefined2 *)(_DAT_0004 + 9) = in_Y;
  save_pair_2w();
  return;
}

// FUNC 0x995a  mem_compare

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Memory compare (returns 0/-1/1). */

undefined2 mem_compare(byte *param_1)

{
  byte *in_Y;
  
  DAT_0002 = param_1;
  while( true ) {
    if (_DAT_0000 == 0) {
      return 0;
    }
    DAT_0005 = *in_Y;
    DAT_0004 = *DAT_0002;
    if (DAT_0005 != DAT_0004) break;
    DAT_0002 = DAT_0002 + 1;
    in_Y = in_Y + 1;
    _DAT_0000 = _DAT_0000 + -1;
  }
  if (DAT_0004 < DAT_0005) {
    return 0xffff;
  }
  return 1;
}

// FUNC 0x998a  tx_index

char tx_index(void)

{
  char cVar1;
  
  cVar1 = DAT_02dc;
  if (DAT_02dc == '\0') {
    DAT_02de = DAT_02de + -1;
    if (DAT_02de == '\0') {
      cVar1 = pin_table_apply(1);
      DAT_02dc = '\x01';
      DAT_02dd = '\x1e';
    }
  }
  else {
    DAT_02dd = DAT_02dd + -1;
    if (DAT_02dd == '\0') {
      cVar1 = pin_table_apply(0);
      DAT_02dc = 0;
      DAT_02de = 0x46;
      return cVar1;
    }
  }
  return cVar1;
}

// FUNC 0x99b6  mul_small

/* Small multiply helper (MUL X,A). */

short mul_small(ushort param_1)

{
  return (param_1 & 0xff) * (ushort)DAT_0001 +
         ((param_1 & 0xff) * (ushort)DAT_0000 + (param_1 >> 8) * (ushort)DAT_0001) * 0x100;
}

// FUNC 0x99d4  shift_loop

void shift_loop(char param_1)

{
  if (param_1 != '\0') {
    do {
      param_1 = param_1 + -1;
    } while (param_1 != '\0');
  }
  return;
}

// FUNC 0x99dc  shr_4

ushort shr_4(ushort param_1)

{
  return param_1 >> 4;
}

// FUNC 0x99e1  ext0_pa1_isr

undefined2 ext0_pa1_isr(undefined2 param_1)

{
  noop_4();
  bank_set_0();
  bank_set_4();
  if ((PA_IDR & 2) == 0) {
    tim4_reset(&UNK_01f4);
    reset_startup();
    DAT_02d4 = 1;
    DAT_02db = 8;
    tim4_enable(0);
  }
  save_pair_1();
  save_pair_0();
  return param_1;
}

// FUNC 0x9a0b  tim4_reset

void tim4_reset(void)

{
  tim4_clear_egr(0);
  pin_bit_b(0);
  DAT_0000 = 1;
  tim2_ier_write(1);
  tim2_cr1_or_80(1);
  tim2_sr1_clear(1);
  tim2_enable(1);
  DAT_0000 = 3;
  uart1_set_control_bits(0xd);
  return;
}

// FUNC 0x9a34  block_move

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Block move (backward copy). */

void block_move(short *param_1)

{
  short sVar1;
  
  while( true ) {
    sVar1 = *param_1;
    if (sVar1 == 0) break;
    _DAT_0000 = param_1[1];
    DAT_0002 = param_1[2];
    param_1 = param_1 + 3;
    sVar1 = sVar1 + -1;
    do {
      *(undefined1 *)(sVar1 + DAT_0002) = *(undefined1 *)(sVar1 + _DAT_0000);
      sVar1 = sVar1 + -1;
    } while (-1 < sVar1);
  }
  return;
}

// FUNC 0x9a5c  bad_code_9a5c

/* WARNING: Control flow encountered bad instruction data */

void bad_code_9a5c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// FUNC 0x9a84  queue_scan

undefined1 queue_scan(void)

{
  byte extraout_CC;
  
  DAT_0001 = 0;
  if (DAT_0207 != '\0') {
    DAT_0002._0_1_ = DAT_021c;
    for (DAT_0000 = 0; DAT_0000 < DAT_0002._0_1_; DAT_0000 = DAT_0000 + 1) {
      noop_3();
      if ((bool)(extraout_CC >> 1 & 1)) {
        DAT_0001 = 1;
        return 1;
      }
    }
  }
  return DAT_0001;
}

// FUNC 0x9aaa  load_a

void load_a(undefined2 param_1)

{
  load_pair_0(param_1);
  return;
}

// FUNC 0x9ab7  load_b

void load_b(undefined2 param_1)

{
  load_pair_1(param_1);
  return;
}

// FUNC 0x9ac4  identity_2

undefined2 identity_2(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9acf  eeprom_rd_a

void eeprom_rd_a(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte extraout_CC;
  
  bank_post_8();
  uVar2 = DAT_000a._0_1_;
  flash_unlock();
  do {
    uVar1 = *DAT_0008;
    eeprom_ofs();
    store_0002(uVar1);
    inc_pair();
  } while ((bool)(extraout_CC & 1));
  flash_and_505f(0xf7);
  DAT_000a._0_1_ = uVar2;
  frame_push_call();
  return;
}

// FUNC 0x9af3  state_clear

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* State clear helper. Clears the per-channel state at param_1. */

void state_clear(undefined1 *param_1)

{
  _DAT_0000 = param_1;
  *param_1 = 0;
  _DAT_0006 = 0;
  _DAT_0004 = 0;
  store_pair_1(_DAT_0000 + 1);
  store_pair_1(_DAT_0000 + 5);
  *(undefined2 *)(_DAT_0000 + 9) = 0;
  return;
}

// FUNC 0x9b17  uart1_init_2400

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* UART init for 2400 baud (Roadstm8true, 2026-11-09).
   Sets the UART control masks and DAT_0002=0x960, then CALLs uart1_configure (0x8F7E).
   Called from 0x8E9B. This resolves the formerly open static-caller question. */

undefined1 uart1_init_2400(void)

{
  DAT_0007 = 0xc;
  DAT_0006 = 0x80;
  DAT_0005 = 0;
  DAT_0004 = 0;
  DAT_0002 = 0x960;
  _DAT_0000 = 0;
  uart1_configure(0);
  uart1_cr_write(1,&UNK_0205);
  return 1;
}

// FUNC 0x9b3a  boot_chain

void boot_chain(void)

{
  undefined1 uVar1;
  byte extraout_CC;
  undefined1 uVar2;
  
  bank_post_8();
  uVar1 = DAT_000a._0_1_;
  flash_unlock();
  do {
    eeprom_ofs();
    uVar2 = load_0002();
    *DAT_0008 = uVar2;
    inc_pair();
  } while ((bool)(extraout_CC & 1));
  flash_and_505f(0xf7);
  DAT_000a._0_1_ = uVar1;
  frame_push_call();
  return;
}

// FUNC 0x9b72  pa_outputs_init

void pa_outputs_init(void)

{
  itc_clear();
  DAT_0000 = 0x60;
  gpio_init(&PA_ODR);
  DAT_0000 = 2;
  itc_spr_write(0);
  DAT_0000 = 3;
  uart1_set_control_bits(6);
  return;
}

// FUNC 0x9b92  block_copy

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 block_copy(undefined2 param_1)

{
  undefined1 *in_Y;
  
  DAT_0002 = param_1;
  save_regs_0();
  for (; _DAT_0000 != 0; _DAT_0000 = _DAT_0000 + -1) {
    *_DAT_0004 = *in_Y;
    _DAT_0004 = _DAT_0004 + 1;
    in_Y = in_Y + 1;
  }
  return DAT_0002;
}

// FUNC 0x9bcf  reg_clear_a

void reg_clear_a(void)

{
  flag1_clear2();
  *(undefined1 *)(DAT_0008 + 3) = 0;
  DAT_000c = (undefined1 *)(DAT_0008 + 4);
  *DAT_000c = DAT_0002._0_1_;
  *(undefined1 *)(DAT_0008 + 5) = 0xff;
  return;
}

// FUNC 0x9beb  tim2_ier_write

void tim2_ier_write(byte param_1)

{
  if (DAT_0000 == '\0') {
    DAT_0001 = ~param_1;
    TIM2_IER = DAT_0001 & TIM2_IER;
  }
  else {
    TIM2_IER = TIM2_IER | param_1;
    DAT_0001 = param_1;
  }
  return;
}

// FUNC 0x9c03  tim4_etr_write

void tim4_etr_write(byte param_1)

{
  if (DAT_0000 == '\0') {
    DAT_0001 = ~param_1;
    TIM4_ETR = DAT_0001 & TIM4_ETR;
  }
  else {
    TIM4_ETR = TIM4_ETR | param_1;
    DAT_0001 = param_1;
  }
  return;
}

// FUNC 0x9c1b  flash_key_dispatch

/* Flash key dispatch (Roadstm8true, 2026-11-09).
   If A==0xFD, FLASH_KEYREG_A (0x5062) unlock sequence (0x56 then 0xAE).
   Otherwise FLASH_KEYREG_B (0x5064) unlock sequence (0xAE then 0x56).
   Confirms 0x5062/0x5064 are the flash unlock registers for this part. */

void flash_key_dispatch(char param_1)

{
  if (param_1 == -3) {
    FLASH_KEYREG_A = 0xae;
    return;
  }
  FLASH_KEYREG_B = 0x56;
  return;
}

// FUNC 0x9c31  memset_like

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * memset_like(undefined1 *param_1)

{
  undefined1 in_YL;
  
  DAT_0002 = param_1;
  for (; _DAT_0000 != 0; _DAT_0000 = _DAT_0000 + -1) {
    *param_1 = in_YL;
    param_1 = param_1 + 1;
  }
  return DAT_0002;
}

// FUNC 0x9c47  init_walker

void init_walker(void)

{
  code *pcVar1;
  
  for (pcVar1 = (code *)&DAT_9b5c; pcVar1 != pa_outputs_init;
      pcVar1 = (code *)func_0x0000eb80(pcVar1 + 2)) {
  }
  return;
}

// FUNC 0x9c5b  frame_get

void frame_get(void)

{
  undefined1 uStack_1;
  
  DAT_0008 = bank_post_8();
  do {
    noop_f(1,&uStack_1);
  } while( true );
}

// FUNC 0x9c6f  msg_alloc

void msg_alloc(byte param_1)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = (ushort)param_1;
  msg_post(0);
  sVar1 = mul_small(uVar2);
  DAT_0008 = sVar1 + 0x10;
  return;
}

// FUNC 0x9c76  flash_write_key_ae

/* FLASH key 0xAE -> FLASH_KEYREG_A (0x5062), STM8 mass-key idiom. */

void flash_write_key_ae(void)

{
  short sVar1;
  
  sVar1 = mul_small();
  DAT_0008 = sVar1 + 0x10;
  return;
}

// FUNC 0x9c82  flash_write_key_56

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* FLASH key 0x56 -> FLASH_KEYREG_B (0x5064), STM8 mass-key idiom. */

void flash_write_key_56(void)

{
  short sVar1;
  
  _DAT_03fe = 0x9c89;
  sVar1 = ret_one();
  if (sVar1 != 0) {
    _DAT_03fe = 0x9c8f;
    init_walker();
  }
  _DAT_03fe = 0x9c92;
  system_init();
  iwdg_reload();
  return;
}

// FUNC 0x9c95  iwdg_setup

void iwdg_setup(void)

{
  iwdg_kick_cc();
  iwdg_kr_write(0x55);
  iwdg_pr_write(6);
  iwdg_rlr_write(0xfa);
  return;
}

// FUNC 0x9ca7  flash_unlock

void flash_unlock(void)

{
  flash_and_505a(0);
  flash_key_dispatch();
  DAT_000a._0_1_ = 0;
  DAT_0008 = &DAT_01f5;
  return;
}

// FUNC 0x9cb8  poll_busy

undefined1 poll_busy(char param_1)

{
  byte extraout_CC;
  
  DAT_0001 = 0;
  DAT_0000 = param_1;
  if (param_1 != '\0') {
    do {
      sum_add();
    } while (!(bool)(extraout_CC >> 1 & 1));
  }
  return DAT_0001;
}

// FUNC 0x9cc8  shl_loop

void shl_loop(void)

{
  if (DAT_0000 != '\0') {
    do {
      DAT_0000 = DAT_0000 + -1;
    } while (DAT_0000 != '\0');
  }
  return;
}

// FUNC 0x9cd2  shl_6

char shl_6(char param_1)

{
  return param_1 << 6;
}

// FUNC 0x9cd8  reset_startup

/* Reset entry: SP = 0x03FF, init calls, then jump to main. */

void reset_startup(void)

{
  itc_clear();
  DAT_0000 = 0x40;
  gpio_init(&PA_ODR);
  return;
}

// FUNC 0x9ce7  seq_alloc_3

void seq_alloc_3(void)

{
  DAT_0002._0_1_ = DAT_02cf;
  DAT_02cf = DAT_02cf + '\x01';
  DAT_0002._1_1_ = DAT_02ce;
  return;
}

// FUNC 0x9cf6  byte_store_inc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void byte_store_inc(void)

{
  *_DAT_0000 = DAT_0002._0_1_;
  _DAT_0000 = _DAT_0000 + 1;
  DAT_0002._1_1_ = (char)DAT_0002 + -1;
  return;
}

// FUNC 0x9d05  bit_scan_a

undefined1 bit_scan_a(void)

{
  undefined1 extraout_A;
  short sVar1;
  
  block_copy_7();
  sVar1 = poll_and_load(0xb);
  *(undefined1 *)(sVar1 + 0xf) = extraout_A;
  return 0xc;
}

// FUNC 0x9d14  bit_scan_b

undefined1 bit_scan_b(void)

{
  undefined1 extraout_A;
  short sVar1;
  
  block_copy_7();
  sVar1 = poll_and_load(4);
  *(undefined1 *)(sVar1 + 8) = extraout_A;
  return 5;
}

// FUNC 0x9d23  flash_and_505a

void flash_and_505a(byte param_1)

{
  DAT_0000 = param_1;
  DAT_505a = DAT_505a & 0xfe;
  DAT_505a = DAT_505a | param_1;
  return;
}

// FUNC 0x9d32  pack_pair

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 pack_pair(short param_1)

{
  _DAT_0004 = CONCAT11(*(undefined1 *)(param_1 + _DAT_0004 + 2),DAT_0005);
  return DAT_0001;
}

// FUNC 0x9d40  clk_enable_b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void clk_enable_b(void)

{
  reg_clear_a();
  clk_gate_enable_3();
  _DAT_0000 = 8;
  return;
}

// FUNC 0x9d4e  clk_reg_a

void clk_reg_a(byte param_1)

{
  DAT_0000 = param_1;
  clk_trim_clear();
  CLK_CKDIVR = CLK_CKDIVR | DAT_0000;
  return;
}

// FUNC 0x9d5c  clk_enable_a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void clk_enable_a(void)

{
  reg_clear_a();
  clk_gate_enable_3();
  _DAT_0000 = 1;
  return;
}

// FUNC 0x9d69  clk_shift

void clk_shift(byte param_1)

{
  DAT_0000 = (param_1 & 3) << 1;
  DAT_0001 = DAT_0000;
  shl_loop(3);
  return;
}

// FUNC 0x9d76  tim2_enable

void tim2_enable(char param_1)

{
  if (param_1 != '\0') {
    TIM2_CR1 = TIM2_CR1 | 1;
    return;
  }
  TIM2_CR1 = TIM2_CR1 & 0xfe;
  return;
}

// FUNC 0x9d83  tim2_cr1_or_80

void tim2_cr1_or_80(char param_1)

{
  if (param_1 != '\0') {
    TIM2_CR1 = TIM2_CR1 | 0x80;
    return;
  }
  TIM2_CR1 = TIM2_CR1 & 0x7f;
  return;
}

// FUNC 0x9d90  tim4_enable

void tim4_enable(char param_1)

{
  if (param_1 != '\0') {
    TIM4_CR1 = TIM4_CR1 | 1;
    return;
  }
  TIM4_CR1 = TIM4_CR1 & 0xfe;
  return;
}

// FUNC 0x9d9d  uart1_clear_20

void uart1_clear_20(char param_1)

{
  if (param_1 != '\0') {
    UART1_CR1 = UART1_CR1 & 0xdf;
    return;
  }
  UART1_CR1 = UART1_CR1 | 0x20;
  return;
}

// FUNC 0x9daa  clk_gate_enable_2

undefined1 clk_gate_enable_2(char param_1,undefined1 *param_2)

{
  undefined1 *in_Y;
  
  do {
    *param_2 = *in_Y;
    param_2 = param_2 + 1;
    in_Y = in_Y + 1;
    param_1 = param_1 + -1;
  } while (param_1 != '\0');
  return 0;
}

// FUNC 0x9db7  inc_pair

char inc_pair(void)

{
  DAT_000a._0_1_ = DAT_000a._0_1_ + '\x01';
  DAT_0008 = DAT_0008 + 1;
  return DAT_000a._0_1_;
}

// FUNC 0x9dc3  ptr_02c4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * ptr_02c4(void)

{
  _DAT_0000 = 7;
  return &UNK_02c4;
}

// FUNC 0x9dcf  seq_save

void seq_save(void)

{
  DAT_0002._0_1_ = DAT_02cf;
  DAT_0002._1_1_ = DAT_02ce;
  return;
}

// FUNC 0x9dda  flash_and_505f

void flash_and_505f(byte param_1)

{
  DAT_0000 = param_1;
  DAT_505f = DAT_505f & param_1;
  return;
}

// FUNC 0x9de5  eeprom_ofs

void eeprom_ofs(void)

{
  init_pair(&UNK_4008 + DAT_000a._0_1_);
  return;
}

// FUNC 0x9def  tim4_init

undefined * tim4_init(void)

{
  DAT_02d1 = 0;
  return &UNK_0277;
}

// FUNC 0x9df9  seq_inc

char seq_inc(void)

{
  DAT_02ce = DAT_02ce + '\x01';
  return DAT_02ce;
}

// FUNC 0x9e03  block_copy_7

void block_copy_7(void)

{
  block_copy(DAT_0008 + 7);
  return;
}

// FUNC 0x9e05  block_copy_7b

void block_copy_7b(void)

{
  block_copy(DAT_0008 + 7);
  return;
}

// FUNC 0x9e0d  seq_alloc

void seq_alloc(void)

{
  DAT_0002._1_1_ = DAT_02cf;
  DAT_02cf = DAT_02cf + '\x01';
  return;
}

// FUNC 0x9e17  addr_plus_10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void addr_plus_10(short param_1)

{
  _DAT_0000 = param_1 + 0x10;
  DAT_0002._1_1_ = 0xc;
  return;
}

// FUNC 0x9e21  flag1_clear2

void flag1_clear2(undefined1 *param_1)

{
  *param_1 = 1;
  *(undefined2 *)(DAT_0008 + 1) = 0;
  return;
}

// FUNC 0x9e2b  eeprom_init_a

void eeprom_init_a(void)

{
  eeprom_rd_a();
  state_clear(&UNK_01df);
  return;
}

// FUNC 0x9e34  load_000c

undefined2 load_000c(void)

{
  return *DAT_000c;
}

// FUNC 0x9e3d  channel_ptr_5_store

short channel_ptr_5_store(undefined1 param_1,undefined1 *param_2)

{
  *param_2 = param_1;
  return DAT_0008 + 5;
}

// FUNC 0x9e40  channel_ptr_5

short channel_ptr_5(void)

{
  return DAT_0008 + 5;
}

// FUNC 0x9e46  sum_add

char * sum_add(char *param_1)

{
  DAT_0001 = *param_1 + DAT_0001;
  DAT_0000 = DAT_0000 + -1;
  return param_1 + 1;
}

// FUNC 0x9e4f  clk_trim_clear

void clk_trim_clear(void)

{
  CLK_CKDIVR = CLK_CKDIVR & 0xe7;
  return;
}

// FUNC 0x9e58  itc_clear

void itc_clear(void)

{
  ITC_SPR1 = 0;
  ITC_SPR2 = 0;
  return;
}

// FUNC 0x9e61  pin_bit_a

void pin_bit_a(void)

{
  undefined1 in_XH;
  undefined1 in_XL;
  
  TIM2_CCR1H = in_XH;
  TIM2_CCR1L = in_XL;
  return;
}

// FUNC 0x9e6a  pin_bit_b

void pin_bit_b(void)

{
  undefined1 in_XH;
  undefined1 in_XL;
  
  TIM2_PSCR = in_XH;
  TIM2_ARRH = in_XL;
  return;
}

// FUNC 0x9e73  tim4_egr_set

void tim4_egr_set(undefined1 param_1)

{
  TIM4_EGR = param_1;
  TIM4_CNTR = DAT_0000;
  return;
}

// FUNC 0x9e7c  nibble_map

undefined1 nibble_map(byte param_1)

{
  undefined1 uVar1;
  
  uVar1 = shift_loop(param_1 & 0xf,1);
  return uVar1;
}

// FUNC 0x9e85  noop_e

void noop_e(void)

{
  return;
}

// FUNC 0x9e8d  noop_3

void noop_3(void)

{
  return;
}

// FUNC 0x9e95  poll_and_load

undefined2 poll_and_load(void)

{
  poll_busy(DAT_000c);
  return DAT_0008;
}

// FUNC 0x9e9d  mul_wide_call

void mul_wide_call(void)

{
  mul_wide();
  return;
}

// FUNC 0x9ea5  byte_store_off24

void byte_store_off24(undefined1 param_1)

{
  *(undefined1 *)(DAT_0008 + 0x24) = param_1;
  return;
}

// FUNC 0x9eac  clk_gate_enable_3

void clk_gate_enable_3(undefined1 param_1)

{
  *(undefined1 *)(DAT_0008 + 6) = param_1;
  return;
}

// FUNC 0x9eb3  poll_call

void poll_call(void)

{
  queue_scan();
  return;
}

// FUNC 0x9eba  pin_or

void pin_or(byte param_1,byte *param_2)

{
  DAT_0000 = param_1;
  *param_2 = *param_2 | param_1;
  return;
}

// FUNC 0x9ec1  tim2_set_ccr1l

/* Write TIM2 CCR1 low byte (PWM duty helper). */

byte tim2_set_ccr1l(byte param_1,short param_2)

{
  DAT_0000 = param_1;
  return *(byte *)(param_2 + 1) & param_1;
}

// FUNC 0x9ec8  noop_4

void noop_4(void)

{
  return;
}

// FUNC 0x9ecf  tim4_clear_egr

void tim4_clear_egr(undefined1 param_1)

{
  TIM2_ARRL = param_1;
  pin_bit_a();
  return;
}

// FUNC 0x9ed6  tx_index_ret

undefined1 tx_index_ret(void)

{
  return DAT_02ce;
}

// FUNC 0x9edc  iwdg_refresh

void iwdg_refresh(void)

{
  IWDG_KR = 0xaa;
  return;
}

// FUNC 0x9ee1  iwdg_kick_cc

void iwdg_kick_cc(void)

{
  IWDG_KR = 0xcc;
  return;
}

// FUNC 0x9ee6  tim2_sr1_clear

void tim2_sr1_clear(byte param_1)

{
  TIM2_SR1 = ~param_1;
  return;
}

// FUNC 0x9eeb  tim4_ier_set

void tim4_ier_set(byte param_1)

{
  TIM4_IER = ~param_1;
  return;
}

// FUNC 0x9ef0  tim4_ier_set_2

void tim4_ier_set_2(byte param_1)

{
  TIM4_IER = ~param_1;
  return;
}

// FUNC 0x9ef5  table_lookup

void table_lookup(undefined2 param_1)

{
  undefined1 extraout_A;
  undefined2 uVar1;
  
  uVar1 = frame_get(param_1);
  block_copy_7b(extraout_A,uVar1);
  return;
}

// FUNC 0x9efe  block_copy_call

void block_copy_call(void)

{
  block_copy_7b();
  return;
}

// FUNC 0x9f02  seq_alloc_2

void seq_alloc_2(void)

{
  seq_alloc();
  return;
}

// FUNC 0x9f06  tim2_off

void tim2_off(void)

{
  tim2_enable(0);
  return;
}

// FUNC 0x9f0a  store_0002

void store_0002(undefined1 param_1)

{
  *DAT_0002 = param_1;
  return;
}

// FUNC 0x9f0e  load_0002

undefined1 load_0002(void)

{
  return *DAT_0002;
}

// FUNC 0x9f12  pin_and

void pin_and(byte param_1,byte *param_2)

{
  *param_2 = ~param_1 & *param_2;
  return;
}

// FUNC 0x9f16  iwdg_kr_write

void iwdg_kr_write(undefined1 param_1)

{
  IWDG_KR = param_1;
  return;
}

// FUNC 0x9f1a  iwdg_pr_write

void iwdg_pr_write(undefined1 param_1)

{
  IWDG_PR = param_1;
  return;
}

// FUNC 0x9f1e  iwdg_rlr_write

void iwdg_rlr_write(undefined1 param_1)

{
  IWDG_RLR = param_1;
  return;
}

// FUNC 0x9f22  uart1_dr_read

undefined1 uart1_dr_read(void)

{
  return UART1_DR;
}

// FUNC 0x9f26  uart1_dr_write

void uart1_dr_write(undefined1 param_1)

{
  UART1_DR = param_1;
  return;
}

// FUNC 0x9f2a  pin_and

void pin_and(byte param_1,byte *param_2)

{
  *param_2 = ~param_1 & *param_2;
  return;
}

// FUNC 0x9f2d  pin_or

void pin_or(byte param_1,byte *param_2)

{
  DAT_0000 = param_1;
  *param_2 = *param_2 | param_1;
  return;
}

// FUNC 0x9f30  nop_spin_a

void nop_spin_a(void)

{
  do {
    __Nop();
  } while( true );
}

// FUNC 0x9f33  ret_one

undefined2 ret_one(void)

{
  return 1;
}

// FUNC 0x9f36  iwdg_reload

/* IWDG reload/refresh (writes IWDG_KR). */

void iwdg_reload(undefined2 param_1)

{
  undefined1 extraout_A;
  undefined2 uVar1;
  
  uVar1 = frame_get(param_1);
  block_copy_7b(extraout_A,uVar1);
  return;
}

// FUNC 0x9f39  nop_spin

void nop_spin(void)

{
  do {
    __Nop();
  } while( true );
}

// FUNC 0x9f3c  unused_vec_9f3c

undefined2 unused_vec_9f3c(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f3d  iwdg_start

/* IWDG start: IWDG_KR = 0xCC. */

undefined2 iwdg_start(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f3e  unused_vec_9f3e

undefined2 unused_vec_9f3e(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f3f  unused_vec_9f3f

undefined2 unused_vec_9f3f(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f40  unused_vec_9f40

undefined2 unused_vec_9f40(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f41  unused_vec_9f41

undefined2 unused_vec_9f41(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f42  unused_vec_9f42

undefined2 unused_vec_9f42(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f43  unused_vec_9f43

undefined2 unused_vec_9f43(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f44  unused_vec_9f44

undefined2 unused_vec_9f44(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f45  unused_vec_9f45

undefined2 unused_vec_9f45(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f46  unused_vec_9f46

undefined2 unused_vec_9f46(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f47  unused_vec_9f47

undefined2 unused_vec_9f47(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f48  unused_vec_9f48

undefined2 unused_vec_9f48(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f49  unused_vec_9f49

undefined2 unused_vec_9f49(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f4a  unused_vec_9f4a

undefined2 unused_vec_9f4a(undefined2 param_1)

{
  return param_1;
}

// FUNC 0x9f4b  noop_f

void noop_f(void)

{
  return;
}

// FUNC 0x9f4c  unused_irq_vec_9f4c

/* WARNING: Control flow encountered bad instruction data */

void unused_irq_vec_9f4c(undefined2 *param_1)

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
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
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

// FUNC 0x9f5d  unused_irq_vec_9f5d

/* WARNING: Control flow encountered bad instruction data */

void unused_irq_vec_9f5d(undefined2 *param_1)

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
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
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

// FUNC 0x9f6e  unused_irq_vec_9f6e

/* WARNING: Control flow encountered bad instruction data */

void unused_irq_vec_9f6e(undefined2 *param_1)

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
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
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

// FUNC 0x9f7f  unused_irq_vec_9f7f

/* WARNING: Control flow encountered bad instruction data */

void unused_irq_vec_9f7f(undefined2 *param_1)

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
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
  *param_1 = in_Y;
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

// FUNC 0x9f90  unused_irq_vec_9f90

/* WARNING: Control flow encountered bad instruction data */

void unused_irq_vec_9f90(undefined2 *param_1)

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
  halt_baddata();
}

