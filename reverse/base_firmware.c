/*
 * Roadshock 8-Gang switch panel - base board firmware
 * STM8S003F3P6, 8 KB flash @ 0x8000, 1 KB RAM
 *
 * Reconstructed from the dumped flash image with Ghidra 12.2
 * (language STM8:BE:16, base 0x8000).
 *
 * This is decompiler output, not original source. Types are
 * approximate; function names are either recovered from call
 * sites or assigned by the analysis (vec*, sub_*, gap_*).
 * Regions marked with WARNING comments contain data bytes that
 * the disassembler could not separate from code.
 */

/* ---- function index ----------------------------------------
 * 8000  VEC00_RESET
 * 8080  x_8080
 * 8112  sub_8112
 * 8118  sub_8118
 * 811E  sub_811e
 * 8146  sub_8146
 * 816D  x_816d
 * 81CD  sub_81cd
 * 828D  sub_828d
 * 828E  sub_828e
 * 82A8  sub_82a8
 * 82AA  sub_82aa
 * 82B3  sub_82b3
 * 833B  x_833b
 * 845D  sub_845d
 * 845E  sub_845e
 * 8480  x_833b
 * 8485  sub_8485
 * 848B  sub_848b
 * 8490  sub_8490
 * 8495  sub_8495
 * 84A5  sub_84a5
 * 84B3  sub_84b3
 * 84B9  sub_84b9
 * 84C5  thunk_EXT_FUN_a501
 * 84CC  sub_84cc
 * 84D5  sub_84d5
 * 84E4  sub_84e4
 * 8504  sub_8504
 * 851A  sub_851a
 * 85E6  sub_86a6
 * 860C  sub_860c
 * 8640  sub_8640
 * 8689  sub_8689
 * 86A6  sub_86a6
 * 86AB  sub_86ab
 * 86C2  sub_86c2
 * 86C8  sub_86c8
 * 86CB  sub_86cb
 * 86D1  sub_86d1
 * 86D3  sub_86d3
 * 86D8  sub_86d8
 * 86DF  sub_86df
 * 86E8  sub_86e8
 * 8700  gap_8700
 * 8811  sub_8811
 * 8814  sub_8814
 * 881C  sub_881c
 * 8828  sub_8828
 * 8841  x_8841
 * 8A15  sub_8a15
 * 8A46  sub_8a46
 * 8B5D  sub_8b5d
 * 8B6E  sub_8b6e
 * 8B71  sub_8b71
 * 8B79  sub_8b79
 * 8B8A  sub_8b8a
 * 8B8E  sub_8b8e
 * 8B96  sub_8b96
 * 8C31  x_8c31
 * 8D00  sub_8d00
 * 8D03  sub_8d03
 * 8D16  sub_8d16
 * 8D31  sub_8d31
 * 8DBB  sub_8dbb
 * 8DC0  sub_8dc0
 * 8DC3  sub_8dc3
 * 8E30  sub_8e30
 * 8E40  sub_8e40
 * 8E51  sub_8e51
 * 8E5C  sub_8e5c
 * 8EE6  sub_8ee6
 * 8F7E  x_8f7e
 * 8FB5  x_8fb5
 * 908A  x_908a
 * 908F  sub_908f
 * 9094  sub_9094
 * 9099  FUN_9099
 * 90AC  sub_90ac
 * 90B3  thunk_FUN_9127
 * 90BA  FUN_90ba
 * 90C2  sub_90c2
 * 90C7  sub_90c7
 * 90CC  sub_90cc
 * 90D1  sub_90d1
 * 90D6  FUN_90d6
 * 90F3  sub_90f3
 * 90FE  FUN_90fe
 * 9109  sub_9109
 * 9114  sub_9114
 * 911F  FUN_911f
 * 9127  FUN_9127
 * 912A  thunk_FUN_914d
 * 912E  sub_912e
 * 9135  thunk_FUN_914d
 * 9139  sub_9139
 * 9140  sub_9140
 * 9147  sub_9147
 * 9154  sub_9154
 * 9161  FUN_9161
 * 916E  sub_916e
 * 917B  sub_917b
 * 9223  vec_9223
 * 92C2  gap_92c2
 * 935E  ret_935e
 * 93E5  sub_93e5
 * 9464  clk_set_divider
 * 94D6  sub_94d6
 * 9541  sub_9541
 * 95A5  sub_95a5
 * 95B5  sub_95b5
 * 95C1  sub_95c1
 * 95CD  sub_95cd
 * 95DE  x_95de
 * 95EC  sub_95ec
 * 95FA  sub_95fa
 * 9608  vec_9608
 * 966A  sub_966a
 * 96CB  itc_set_priority
 * 9728  sub_9728
 * 9780  uart1_set_control_bits
 * 97D3  vec_97d3
 * 9823  sub_9823
 * 9872  sub_9872
 * 98B6  sub_98b6
 * 98F1  clk_gate_enable_1
 * 9927  sub_9927
 * 995A  sub_995a
 * 998A  gap_998a
 * 99B6  sub_99b6
 * 99D4  sub_99d4
 * 99DC  sub_99dc
 * 99E1  vec_99e1
 * 9A0B  sub_9a0b
 * 9A34  ret_9a34
 * 9A5C  ret_9a5c
 * 9A84  sub_9a84
 * 9AAA  sub_9aaa
 * 9AB7  sub_9ab7
 * 9AC4  sub_9ac4
 * 9ACF  FUN_9acf
 * 9AF3  sub_9af3
 * 9B17  sub_9b17
 * 9B3A  sub_9b3a
 * 9B72  sub_9b72
 * 9B92  sub_9b92
 * 9BCF  x_9bcf
 * 9BEB  sub_9beb
 * 9C03  sub_9c03
 * 9C1B  sub_9c1b
 * 9C31  x_9c31
 * 9C47  sub_9c47
 * 9C5B  x_9c5b
 * 9C6F  sub_9c6f
 * 9C76  flash_write_key_ae
 * 9C82  flash_write_key_56
 * 9C95  sub_9c95
 * 9CA7  sub_9ca7
 * 9CB8  sub_9cb8
 * 9CC8  sub_9cc8
 * 9CD2  sub_9cd2
 * 9CD8  reset_startup
 * 9CE7  sub_9ce7
 * 9CF6  sub_9cf6
 * 9D05  sub_9d05
 * 9D14  sub_9d14
 * 9D23  sub_9d23
 * 9D32  sub_9d32
 * 9D40  sub_9d40
 * 9D4E  sub_9d4e
 * 9D5C  sub_9d5c
 * 9D69  sub_9d69
 * 9D76  sub_9d76
 * 9D83  sub_9d83
 * 9D90  sub_9d90
 * 9D9D  sub_9d9d
 * 9DAA  clk_gate_enable_2
 * 9DB7  sub_9db7
 * 9DC3  sub_9dc3
 * 9DCF  sub_9dcf
 * 9DDA  sub_9dda
 * 9DE5  sub_9de5
 * 9DEF  tim4_init
 * 9DF9  sub_9df9
 * 9E03  sub_9e03
 * 9E05  sub_9e05
 * 9E0D  sub_9e0d
 * 9E17  sub_9e17
 * 9E21  sub_9e21
 * 9E2B  gap_9e2b
 * 9E34  sub_9e34
 * 9E3D  sub_9e3d
 * 9E40  sub_9e40
 * 9E46  sub_9e46
 * 9E4F  sub_9e4f
 * 9E58  sub_9e58
 * 9E61  sub_9e61
 * 9E6A  sub_9e6a
 * 9E73  sub_9e73
 * 9E7C  sub_9e7c
 * 9E85  gap_9e85
 * 9E8D  sub_9af3
 * 9E95  sub_9e95
 * 9E9D  sub_9e9d
 * 9EA5  sub_9ea5
 * 9EAC  clk_gate_enable_3
 * 9EB3  sub_9eb3
 * 9EBA  sub_9eba
 * 9EC1  tim2_set_ccr1l
 * 9EC8  sub_9ec8
 * 9ECF  tim4_clear_egr
 * 9ED6  sub_9ed6
 * 9EDC  sub_9edc
 * 9EE1  sub_9ee1
 * 9EE6  sub_9ee6
 * 9EEB  sub_9eeb
 * 9EF0  sub_9ef0
 * 9EF5  sub_9ef5
 * 9EFE  sub_9efe
 * 9F02  sub_9f02
 * 9F06  sub_9f06
 * 9F0A  sub_9f0a
 * 9F0E  sub_9f0e
 * 9F12  sub_9f12
 * 9F16  sub_9f16
 * 9F1A  sub_9f1a
 * 9F1E  sub_9f1e
 * 9F22  sub_9f22
 * 9F26  sub_9f26
 * 9F2A  sub_9f2a
 * 9F2D  sub_9f2d
 * 9F30  vec_9f30
 * 9F33  sub_9f33
 * 9F36  iwdg_reload
 * 9F39  FUN_9f39
 * 9F3C  vec_9f3c
 * 9F3D  iwdg_start
 * 9F3E  vec_9f3e
 * 9F3F  vec_9f3f
 * 9F40  vec_9f40
 * 9F41  vec_9f41
 * 9F42  vec_9f42
 * 9F43  vec_9f43
 * 9F44  vec_9f44
 * 9F45  vec_9f45
 * 9F46  vec_9f46
 * 9F47  vec_9f47
 * 9F48  vec_9f48
 * 9F49  vec_9f49
 * 9F4A  vec_9f4a
 * 9F4B  sub_9f4b
 * 9F4C  gap_9f4c
 * 9F5D  gap_9f5d
 * 9F6E  ret_9f6e
 * 9F7F  gap_9f7f
 * 9F90  gap_9f90
 * ----------------------------------------------------------- */

/* ===== 0x8000  VEC00_RESET ===== */

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
  sVar1 = sub_9f33();
  if (sVar1 != 0) {
    _DAT_03fe = 0x9c8f;
    sub_9c47();
  }
  _DAT_03fe = 0x9c92;
  sub_8e5c();
  iwdg_reload();
  return;
}



/* ===== 0x8080  x_8080 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x_8080(void)

{
  undefined1 uVar1;
  byte extraout_CC;
  undefined1 extraout_A;
  undefined1 extraout_A_00;
  undefined1 uVar2;
  undefined1 *puVar3;
  
  sub_908f();
  DAT_0004 = sub_9094();
  uVar1 = DAT_000a._0_1_;
  DAT_0002._1_1_ = DAT_0000;
  DAT_0005 = DAT_0001;
  DAT_000a._0_1_ = DAT_0002._0_1_;
  _DAT_0006 = CONCAT11(DAT_0006,DAT_02ce);
  do {
    if (9 < DAT_0007) break;
    _DAT_0006 = _DAT_0006 & 0xff;
    sub_86cb();
    puVar3 = (undefined1 *)flash_write_key_ae(_DAT_0006);
    if ((bool)(extraout_CC >> 1 & 1)) {
      *puVar3 = 1;
      _DAT_0000 = (undefined2 *)(puVar3 + 1);
      *_DAT_0000 = 0;
      puVar3 = (undefined1 *)sub_8118(DAT_0005);
      *puVar3 = extraout_A;
      DAT_000c = sub_8112();
      puVar3 = (undefined1 *)sub_9e3d(DAT_0004);
      *puVar3 = extraout_A_00;
      clk_gate_enable_3((undefined1)DAT_0002);
      _DAT_0000 = (undefined2 *)(ushort)DAT_000a._0_1_;
      sub_9efe();
      uVar2 = sub_9cb8(DAT_000a._0_1_ + 3,DAT_000c);
      _DAT_0000 = (undefined2 *)CONCAT11(uVar2,DAT_0001);
      *(undefined1 *)((ushort)DAT_000a._0_1_ + DAT_0008 + 7) = uVar2;
      sub_9ea5(DAT_000a._0_1_ + 4);
      break;
    }
    DAT_0007 = DAT_0007 + 1;
    if (9 < DAT_0007) {
      DAT_0007 = 0;
    }
  } while (DAT_02ce != DAT_0007);
  DAT_000a._0_1_ = uVar1;
  sub_90b3();
  sub_9135();
  return;
}



/* ===== 0x8112  sub_8112 ===== */

short sub_8112(void)

{
  return DAT_0008 + 4;
}



/* ===== 0x8118  sub_8118 ===== */

short sub_8118(void)

{
  return DAT_0008 + 3;
}



/* ===== 0x811E  sub_811e ===== */

char sub_811e(char param_1)

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
      sub_8490();
    }
  }
  return DAT_0000;
}



/* ===== 0x8146  sub_8146 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8146(void)

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
  
  sub_90cc();
  sub_9094();
  uVar1 = DAT_000e;
  DAT_0001 = 0xc;
  DAT_0000 = '\0';
  sStack_2 = in_Y;
  sub_9b92(acStack_e);
  DAT_000e = 0;
  pcVar2 = acStack_e;
  sub_8495();
  sub_82a8();
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
      pcVar2 = (char *)sub_8490();
    }
    *pcVar2 = DAT_0000;
  }
  if (acStack_e[0] == '\0') {
    sub_84b3();
    if (!(bool)(extraout_CC_00 >> 1 & 1)) {
      sub_828e();
      return;
    }
    sVar3 = sub_8485();
    *(undefined1 *)(sVar3 + sStack_2) = 0;
    sub_828e();
    return;
  }
  if (acStack_e[0] == '\x01') {
    sVar3 = sub_84b9();
    pbVar4 = (byte *)sub_848b(sVar3 + sStack_2);
    if ((bool)(extraout_CC_01 >> 1 & 1)) {
      sub_828d(0x10);
      return;
    }
    sub_828d(*pbVar4 | 1);
    return;
  }
  if (acStack_e[0] == '\x02') {
    sVar3 = sub_84c5();
    pbVar4 = (byte *)sub_848b(sVar3 + sStack_2);
    if ((bool)(extraout_CC_02 >> 1 & 1)) {
      sub_828d(0x20);
      return;
    }
    sub_828d(*pbVar4 | 2);
    return;
  }
  if (acStack_e[0] == '\x03') {
    sVar3 = sub_84b9();
    pbVar4 = (byte *)sub_848b(sVar3 + sStack_2);
    if ((bool)(extraout_CC_03 >> 1 & 1)) {
      sub_828d(0x30);
      return;
    }
    sub_828d(*pbVar4 | 3);
    return;
  }
  if (acStack_e[0] == '\x04') {
    sVar3 = sub_84c5();
    pbVar4 = (byte *)sub_848b(sVar3 + sStack_2);
    if ((bool)(extraout_CC_04 >> 1 & 1)) {
      sub_828d(0x40);
      return;
    }
    sub_828d(*pbVar4 | 4);
    return;
  }
  if (acStack_e[0] == '\x05') {
    *DAT_000c = 0;
    if (*DAT_0008 == '\0') {
      sub_84e4();
    }
    sVar3 = sub_8485();
    pbVar4 = (byte *)sub_848b(sVar3 + sStack_2);
    if ((bool)(extraout_CC_05 >> 1 & 1)) {
      sub_828d(0x50);
      return;
    }
    sub_828d(*pbVar4 | 5);
    return;
  }
  if (acStack_e[0] == '\x06') {
    sVar3 = sub_84c5();
    pbVar4 = (byte *)sub_848b(sVar3 + sStack_2);
    if ((bool)(extraout_CC_06 >> 1 & 1)) {
      sub_828d(0x60);
      return;
    }
    sub_828d(*pbVar4 | 6);
    return;
  }
  if (acStack_e[0] == '\a') {
    sVar3 = sub_84a5();
    pbVar4 = (byte *)sub_848b(sVar3 + sStack_2);
    if ((bool)(extraout_CC_07 >> 1 & 1)) {
      sub_828d(0x70);
      return;
    }
    sub_828d(*pbVar4 | 7);
    return;
  }
  if (acStack_e[0] == '\b') {
    sVar3 = sub_8485();
    pbVar4 = (byte *)sub_848b(sVar3 + sStack_2);
    if ((bool)(extraout_CC_08 >> 1 & 1)) {
      sub_828d(0x80);
      return;
    }
    *pbVar4 = *pbVar4 | 8;
  }
  sub_8504();
  if (DAT_000e < 0xc) {
    x_816d();
    return;
  }
  DAT_000e = uVar1;
  sub_912e(0);
  return;
}



/* ===== 0x816D  x_816d ===== */

void x_816d(short param_1,undefined1 param_2)

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
  
  sub_82a8();
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
      pcVar2 = (char *)sub_8490();
    }
    *pcVar2 = DAT_0000;
  }
  cVar1 = *in_stack_00000001;
  if (cVar1 == '\0') {
    sub_84b3();
    if (!(bool)(extraout_CC_00 >> 1 & 1)) {
      sub_828e();
      return;
    }
    sVar3 = sub_8485();
    *(undefined1 *)(sVar3 + param_1) = 0;
    sub_828e();
    return;
  }
  if (cVar1 == '\x01') {
    sVar3 = sub_84b9();
    pbVar4 = (byte *)sub_848b(sVar3 + param_1);
    if ((bool)(extraout_CC_01 >> 1 & 1)) {
      sub_828d(0x10);
      return;
    }
    sub_828d(*pbVar4 | 1);
    return;
  }
  if (cVar1 == '\x02') {
    sVar3 = sub_84c5();
    pbVar4 = (byte *)sub_848b(sVar3 + param_1);
    if ((bool)(extraout_CC_02 >> 1 & 1)) {
      sub_828d(0x20);
      return;
    }
    sub_828d(*pbVar4 | 2);
    return;
  }
  if (cVar1 == '\x03') {
    sVar3 = sub_84b9();
    pbVar4 = (byte *)sub_848b(sVar3 + param_1);
    if ((bool)(extraout_CC_03 >> 1 & 1)) {
      sub_828d(0x30);
      return;
    }
    sub_828d(*pbVar4 | 3);
    return;
  }
  if (cVar1 == '\x04') {
    sVar3 = sub_84c5();
    pbVar4 = (byte *)sub_848b(sVar3 + param_1);
    if ((bool)(extraout_CC_04 >> 1 & 1)) {
      sub_828d(0x40);
      return;
    }
    sub_828d(*pbVar4 | 4);
    return;
  }
  if (cVar1 == '\x05') {
    *DAT_000c = 0;
    if (*DAT_0008 == '\0') {
      sub_84e4();
    }
    sVar3 = sub_8485();
    pbVar4 = (byte *)sub_848b(sVar3 + param_1);
    if ((bool)(extraout_CC_05 >> 1 & 1)) {
      sub_828d(0x50);
      return;
    }
    sub_828d(*pbVar4 | 5);
    return;
  }
  if (cVar1 == '\x06') {
    sVar3 = sub_84c5();
    pbVar4 = (byte *)sub_848b(sVar3 + param_1);
    if ((bool)(extraout_CC_06 >> 1 & 1)) {
      sub_828d(0x60);
      return;
    }
    sub_828d(*pbVar4 | 6);
    return;
  }
  if (cVar1 == '\a') {
    sVar3 = sub_84a5();
    pbVar4 = (byte *)sub_848b(sVar3 + param_1);
    if ((bool)(extraout_CC_07 >> 1 & 1)) {
      sub_828d(0x70);
      return;
    }
    sub_828d(*pbVar4 | 7);
    return;
  }
  if (cVar1 == '\b') {
    sVar3 = sub_8485();
    pbVar4 = (byte *)sub_848b(sVar3 + param_1);
    if ((bool)(extraout_CC_08 >> 1 & 1)) {
      sub_828d(0x80);
      return;
    }
    *pbVar4 = *pbVar4 | 8;
  }
  sub_8504();
  if (DAT_000e < 0xc) {
    x_816d();
    return;
  }
  DAT_000e = param_2;
  sub_912e(0);
  return;
}



/* ===== 0x81CD  sub_81cd ===== */

void sub_81cd(void)

{
  sub_828d(0x10);
  return;
}



/* ===== 0x828D  sub_828d ===== */

void sub_828d(undefined1 param_1,undefined1 *param_2,undefined1 param_3)

{
  *param_2 = param_1;
  sub_8504();
  if (DAT_000e < 0xc) {
    x_816d();
    return;
  }
  DAT_000e = param_3;
  sub_912e(0);
  return;
}



/* ===== 0x828E  sub_828e ===== */

void sub_828e(undefined1 param_1)

{
  sub_8504();
  if (DAT_000e < 0xc) {
    x_816d();
    return;
  }
  DAT_000e = param_1;
  sub_912e(0);
  return;
}



/* ===== 0x82A8  sub_82a8 ===== */

void sub_82a8(void)

{
  tim2_set_ccr1l(&PD_ODR);
  return;
}



/* ===== 0x82AA  sub_82aa ===== */

void sub_82aa(void)

{
  tim2_set_ccr1l(&PD_ODR);
  return;
}



/* ===== 0x82B3  sub_82b3 ===== */

void sub_82b3(void)

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
  
  sub_90cc();
  DAT_000c = (byte *)sub_9094();
  uVar2 = DAT_000e;
  iVar9 = (uint3)in_Y << 8;
  puVar4 = (undefined1 *)sub_8490(in_Y);
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
      sub_82a8();
      if (((bool)(extraout_CC >> 1 & 1)) || ((DAT_000e != 0 && (DAT_000e != 2)))) {
        *DAT_000a = *DAT_0008;
      }
    }
    if (DAT_0008[1] != 8) {
      DAT_000a[1] = DAT_0008[1];
    }
    DAT_000e = DAT_000e + 1;
    DAT_000a = DAT_000a + 2;
    DAT_0008 = (byte *)sub_8480();
    iVar3 = iVar9;
    local_2 = (short)((uint3)iVar9 >> 8);
  } while (DAT_000e < 6);
  DAT_000e = 0;
  pbVar8 = &DAT_01fa;
  pbVar6 = abStack_e;
  sub_8495();
  sub_82a8();
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
      sub_8490();
    }
    *pbVar6 = DAT_0000;
  }
  bVar1 = *pbVar6;
  if (bVar1 == 0) {
    sub_84b3();
    if (!(bool)(extraout_CC_01 >> 1 & 1)) {
      sub_845e();
      return;
    }
    sVar5 = sub_8485();
    *(undefined1 *)(sVar5 + local_2) = 0;
    sub_845e();
    return;
  }
  if (bVar1 == 1) {
    sVar5 = sub_84b9();
    pbVar6 = (byte *)sub_848b(sVar5 + local_2);
    if ((bool)(extraout_CC_02 >> 1 & 1)) {
      sub_845d(0x10);
      return;
    }
    sub_845d(*pbVar6 | 1);
    return;
  }
  if (bVar1 == 2) {
    sVar5 = sub_84c5();
    pbVar6 = (byte *)sub_848b(sVar5 + local_2);
    if ((bool)(extraout_CC_03 >> 1 & 1)) {
      sub_845d(0x20);
      return;
    }
    sub_845d(*pbVar6 | 2);
    return;
  }
  if (bVar1 == 3) {
    sVar5 = sub_84b9();
    pbVar6 = (byte *)sub_848b(sVar5 + local_2);
    if ((bool)(extraout_CC_04 >> 1 & 1)) {
      sub_845d(0x30);
      return;
    }
    sub_845d(*pbVar6 | 3);
    return;
  }
  if (bVar1 == 4) {
    sVar5 = sub_84c5();
    pbVar6 = (byte *)sub_848b(sVar5 + local_2);
    if ((bool)(extraout_CC_05 >> 1 & 1)) {
      sub_845d(0x40);
      return;
    }
    sub_845d(*pbVar6 | 4);
    return;
  }
  if (bVar1 == 5) {
    *DAT_000c = 0;
    if (*DAT_0008 == 0) {
      sub_84e4();
    }
    sVar5 = sub_8485();
    pbVar6 = (byte *)sub_848b(sVar5 + local_2);
    if ((bool)(extraout_CC_06 >> 1 & 1)) {
      sub_845d(0x50);
      return;
    }
    sub_845d(*pbVar6 | 5);
    return;
  }
  if (bVar1 == 6) {
    sVar5 = sub_84c5();
    pbVar6 = (byte *)sub_848b(sVar5 + local_2);
    if ((bool)(extraout_CC_07 >> 1 & 1)) {
      sub_845d(0x60);
      return;
    }
    sub_845d(*pbVar6 | 6);
    return;
  }
  if (bVar1 == 7) {
    sVar5 = sub_84a5();
    pbVar6 = (byte *)sub_848b(sVar5 + local_2);
    if ((bool)(extraout_CC_08 >> 1 & 1)) {
      sub_845d(0x70);
      return;
    }
    sub_845d(*pbVar6 | 7);
    return;
  }
  if (bVar1 == 8) {
    sVar5 = sub_8485();
    pbVar7 = (byte *)sub_848b(sVar5 + local_2);
    if ((bool)(extraout_CC_09 >> 1 & 1)) {
      sub_845d(0x80);
      return;
    }
    *pbVar7 = *pbVar7 | 8;
  }
  sub_8504();
  if (DAT_000e < 0xc) {
    x_833b();
    return;
  }
  sub_86e8(pbVar6 + 1,pbVar8 + 1);
  DAT_000e = uVar2;
  sub_912e(0);
  return;
}



/* ===== 0x833B  x_833b ===== */

void x_833b(char *param_1,short param_2,undefined1 param_3)

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
  
  sub_82a8();
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
      sub_8490();
    }
    *in_stack_00000001 = DAT_0000;
  }
  cVar1 = *in_stack_00000001;
  if (cVar1 == '\0') {
    sub_84b3();
    if (!(bool)(extraout_CC_00 >> 1 & 1)) {
      sub_845e();
      return;
    }
    sVar2 = sub_8485();
    *(undefined1 *)(sVar2 + param_2) = 0;
    sub_845e();
    return;
  }
  if (cVar1 == '\x01') {
    sVar2 = sub_84b9();
    pbVar3 = (byte *)sub_848b(sVar2 + param_2);
    if ((bool)(extraout_CC_01 >> 1 & 1)) {
      sub_845d(0x10);
      return;
    }
    sub_845d(*pbVar3 | 1);
    return;
  }
  if (cVar1 == '\x02') {
    sVar2 = sub_84c5();
    pbVar3 = (byte *)sub_848b(sVar2 + param_2);
    if ((bool)(extraout_CC_02 >> 1 & 1)) {
      sub_845d(0x20);
      return;
    }
    sub_845d(*pbVar3 | 2);
    return;
  }
  if (cVar1 == '\x03') {
    sVar2 = sub_84b9();
    pbVar3 = (byte *)sub_848b(sVar2 + param_2);
    if ((bool)(extraout_CC_03 >> 1 & 1)) {
      sub_845d(0x30);
      return;
    }
    sub_845d(*pbVar3 | 3);
    return;
  }
  if (cVar1 == '\x04') {
    sVar2 = sub_84c5();
    pbVar3 = (byte *)sub_848b(sVar2 + param_2);
    if ((bool)(extraout_CC_04 >> 1 & 1)) {
      sub_845d(0x40);
      return;
    }
    sub_845d(*pbVar3 | 4);
    return;
  }
  if (cVar1 == '\x05') {
    *DAT_000c = 0;
    if (*DAT_0008 == '\0') {
      sub_84e4();
    }
    sVar2 = sub_8485();
    pbVar3 = (byte *)sub_848b(sVar2 + param_2);
    if ((bool)(extraout_CC_05 >> 1 & 1)) {
      sub_845d(0x50);
      return;
    }
    sub_845d(*pbVar3 | 5);
    return;
  }
  if (cVar1 == '\x06') {
    sVar2 = sub_84c5();
    pbVar3 = (byte *)sub_848b(sVar2 + param_2);
    if ((bool)(extraout_CC_06 >> 1 & 1)) {
      sub_845d(0x60);
      return;
    }
    sub_845d(*pbVar3 | 6);
    return;
  }
  if (cVar1 == '\a') {
    sVar2 = sub_84a5();
    pbVar3 = (byte *)sub_848b(sVar2 + param_2);
    if ((bool)(extraout_CC_07 >> 1 & 1)) {
      sub_845d(0x70);
      return;
    }
    sub_845d(*pbVar3 | 7);
    return;
  }
  if (cVar1 == '\b') {
    sVar2 = sub_8485();
    pbVar3 = (byte *)sub_848b(sVar2 + param_2);
    if ((bool)(extraout_CC_08 >> 1 & 1)) {
      sub_845d(0x80);
      return;
    }
    *pbVar3 = *pbVar3 | 8;
  }
  sub_8504();
  if (DAT_000e < 0xc) {
    x_833b();
    return;
  }
  sub_86e8();
  DAT_000e = param_3;
  sub_912e(0);
  return;
}



/* ===== 0x845D  sub_845d ===== */

void sub_845d(undefined1 param_1,undefined1 *param_2,undefined1 param_3)

{
  *param_2 = param_1;
  sub_8504();
  if (DAT_000e < 0xc) {
    x_833b();
    return;
  }
  sub_86e8();
  DAT_000e = param_3;
  sub_912e(0);
  return;
}



/* ===== 0x845E  sub_845e ===== */

void sub_845e(undefined1 param_1)

{
  sub_8504();
  if (DAT_000e < 0xc) {
    x_833b();
    return;
  }
  sub_86e8();
  DAT_000e = param_1;
  sub_912e(0);
  return;
}



/* ===== 0x8480  x_833b ===== */

short sub_8480(void)

{
  return DAT_0008 + 2;
}



/* ===== 0x8485  sub_8485 ===== */

byte sub_8485(void)

{
  return DAT_000e >> 1;
}



/* ===== 0x848B  sub_848b ===== */

undefined1 sub_848b(void)

{
  return DAT_000e;
}



/* ===== 0x8490  sub_8490 ===== */

void sub_8490(void)

{
  DAT_0000 = 6;
  return;
}



/* ===== 0x8495  sub_8495 ===== */

void sub_8495(void)

{
  DAT_000c = &DAT_02b8;
  DAT_000a = &DAT_02df;
  DAT_0008 = &DAT_0182;
  return;
}



/* ===== 0x84A5  sub_84a5 ===== */

byte sub_84a5(void)

{
  *DAT_000c = 1;
  *DAT_0008 = 0;
  return DAT_000e >> 1;
}



/* ===== 0x84B3  sub_84b3 ===== */

void sub_84b3(void)

{
  sub_84cc();
  return;
}



/* ===== 0x84B9  sub_84b9 ===== */

byte sub_84b9(void)

{
  sub_84d5();
  thunk_FUN_9eba();
  return DAT_000e >> 1;
}



/* ===== 0x84C5  thunk_EXT_FUN_a501 ===== */

byte sub_84c5(void)

{
  byte bVar1;
  
  bVar1 = sub_84cc();
  return bVar1 >> 1;
}



/* ===== 0x84CC  sub_84cc ===== */

undefined1 sub_84cc(void)

{
  sub_84d5();
  thunk_FUN_9f12();
  return DAT_000e;
}



/* ===== 0x84D5  sub_84d5 ===== */

undefined2 sub_84d5(void)

{
  *DAT_000c = 0;
  *DAT_0008 = 0;
  return *DAT_000a;
}



/* ===== 0x84E4  sub_84e4 ===== */

void sub_84e4(void)

{
  undefined1 *puVar1;
  
  *DAT_0008 = 1;
  DAT_0008[4] = 0x19;
  DAT_0008[3] = 4;
  puVar1 = (undefined1 *)sub_8480();
  *puVar1 = 5;
  DAT_0008[1] = 5;
  return;
}



/* ===== 0x8504  sub_8504 ===== */

void sub_8504(void)

{
  DAT_000e = DAT_000e + '\x01';
  DAT_0008 = DAT_0008 + 5;
  DAT_000a = DAT_000a + 3;
  DAT_000c = DAT_000c + 1;
  return;
}



/* ===== 0x851A  sub_851a ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_851a(void)

{
  char *pcVar1;
  byte *pbVar2;
  undefined1 local_13;
  char local_12;
  byte abStack_b [11];
  
  clk_gate_enable_2(8);
  _DAT_0000 = (byte *)CONCAT11(DAT_0000,DAT_023d);
  if (DAT_023d < 2) {
    sub_86c8(&local_13);
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
    sub_86c8();
    return;
  }
  if (DAT_021e != '\0') {
    sub_86ab(DAT_021e);
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
    local_13 = sub_8146(abStack_b);
    DAT_0002._0_1_ = 8;
    _DAT_0000 = (byte *)0x1700;
                    /* WARNING: Subroutine does not return */
    x_8080(DAT_021d,&local_13);
  }
  if (DAT_021f == '\b') {
    DAT_01f9 = 0;
    local_13 = sub_82b3(&DAT_0220);
    DAT_0002._0_1_ = 7;
    _DAT_0000 = (byte *)0x1800;
    sub_86c2(&local_13);
    return;
  }
  if (DAT_021f == '\v') {
    sub_8640();
    return;
  }
  if (DAT_021f == '\r') {
    sub_8689();
    return;
  }
  if (DAT_021f == '\x19') {
    sub_860c();
    return;
  }
  sub_86c8();
  return;
}



/* ===== 0x85E6  sub_86a6 ===== */

void sub_86a6(void)

{
  sub_86e8();
  sub_86c8();
  return;
}



/* ===== 0x860C  sub_860c ===== */

void sub_860c(void)

{
  byte extraout_CC;
  char *pcVar1;
  
  DAT_0002 = 0;
  while( true ) {
    DAT_0002 = DAT_0002 & 0xff;
    sub_86cb();
    pcVar1 = (char *)sub_86d8(DAT_0002);
    if (((*pcVar1 != '\0') && (pcVar1[6] == '\t')) && (DAT_021d == pcVar1[4])) break;
    sub_86d1();
    if (!(bool)(extraout_CC & 1)) {
      sub_86c8();
      return;
    }
  }
  *pcVar1 = '\0';
  sub_86c8();
  return;
}



/* ===== 0x8640  sub_8640 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8640(void)

{
  _DAT_0000 = CONCAT11(DAT_0220,DAT_0001);
  if (((DAT_0220 != 0) && (DAT_0220 < 0x65)) && (DAT_0206 != DAT_0220)) {
    DAT_0206 = DAT_0220;
    DAT_0002 = (ushort)DAT_0220;
    _DAT_0000 = 0;
    sub_9927(&DAT_01be);
    sub_86e8();
    sub_9f02();
    DAT_0002 = CONCAT11(1,(undefined1)DAT_0002);
    _DAT_0000 = 0x1b02;
                    /* WARNING: Subroutine does not return */
    x_8080((undefined1)DAT_0002,&stack0x0001);
  }
  return;
}



/* ===== 0x8689  sub_8689 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8689(void)

{
  DAT_0000 = DAT_0220;
  if (DAT_0220 == '\0') {
    _DAT_02cb = 10000;
    sub_86c8();
    return;
  }
  if (DAT_0220 == '\x01') {
    sub_86df();
    DAT_0206 = 10;
    sub_86e8();
    sub_86c8();
    return;
  }
  return;
}



/* ===== 0x86A6  sub_86a6 ===== */

void sub_86a6(void)

{
  sub_86e8();
  sub_86c8();
  return;
}



/* ===== 0x86AB  sub_86ab ===== */

void sub_86ab(char param_1)

{
  if ((param_1 == -1) && (DAT_0000 = DAT_021f, DAT_021f != '\f')) {
    DAT_0002._0_1_ = DAT_0001 + -4;
    DAT_0001 = 0;
                    /* WARNING: Subroutine does not return */
    x_8080(DAT_021d,&DAT_0220);
  }
  return;
}



/* ===== 0x86C2  sub_86c2 ===== */

void sub_86c2(void)

{
                    /* WARNING: Subroutine does not return */
  x_8080(DAT_021d);
}



/* ===== 0x86C8  sub_86c8 ===== */

void sub_86c8(void)

{
  return;
}



/* ===== 0x86CB  sub_86cb ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_86cb(void)

{
  _DAT_0000 = 0x25;
  return;
}



/* ===== 0x86D1  sub_86d1 ===== */

char sub_86d1(void)

{
  DAT_0002._1_1_ = (char)DAT_0002 + '\x01';
  return (char)DAT_0002;
}



/* ===== 0x86D3  sub_86d3 ===== */

undefined1 sub_86d3(void)

{
  return (undefined1)DAT_0002;
}



/* ===== 0x86D8  sub_86d8 ===== */

short sub_86d8(void)

{
  short sVar1;
  
  sVar1 = sub_99b6();
  return sVar1 + 0x10;
}



/* ===== 0x86DF  sub_86df ===== */

void sub_86df(void)

{
  DAT_0207 = 0;
  DAT_021c = 0;
  return;
}



/* ===== 0x86E8  sub_86e8 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_86e8(void)

{
  sub_9af3(&UNK_01df);
  DAT_0002 = &UNK_03e8;
  _DAT_0000 = 0;
  sub_9927(&UNK_01df);
  return;
}



/* ===== 0x8700  gap_8700 ===== */

char ret_8700(void)

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
    bVar1 = sub_82aa(8);
    if ((bool)(extraout_CC >> 1 & 1)) {
      bVar1 = pin_state_d3;
      if (pin_state_d3 != 0) {
        local_18 = 2;
        uStack_1a = (code *)0x8724;
        sub_82a8();
        local_17 = !(bool)(extraout_CC_00 >> 1 & 1);
        local_16 = 1;
        local_15 = DAT_01fa;
        local_14 = DAT_01fe;
        uStack_1a = (code *)0x873e;
        sub_8814();
        uStack_1a = (code *)0x8742;
        bVar1 = sub_881c((short)&uStack_1a + 1);
        pin_state_d3 = 0;
      }
    }
    else {
      pin_state_d3 = 1;
    }
  }
  uStack_1a = (code *)0x874f;
  sub_82a8(bVar1);
  if ((bool)(extraout_CC_01 >> 1 & 1)) {
    if (pin_state_d4 == '\0') {
      cVar2 = sub_8811(0);
      return cVar2;
    }
    uStack_1a = (code *)0x875e;
    sub_82aa(8);
    local_18 = !(bool)(extraout_CC_02 >> 1 & 1);
    uStack_1a = (code *)0x876a;
    sub_82a8();
    local_17 = !(bool)(extraout_CC_03 >> 1 & 1);
    local_16 = 1;
    local_15 = DAT_01fa;
    local_14 = DAT_01fe;
    uStack_1a = (code *)0x8784;
    sub_8814();
    uStack_1a = (code *)0x8788;
    sub_881c((short)&uStack_1a + 1);
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
    sub_82aa(8);
    local_18 = !(bool)(extraout_CC_04 >> 1 & 1);
    uStack_1a = (code *)0x87c0;
    sub_82a8();
    local_17 = !(bool)(extraout_CC_05 >> 1 & 1);
    local_16 = 1;
    uStack_1a = (code *)0x87d3;
    local_15 = sub_811e(DAT_01fa);
    uStack_1a = (code *)0x87db;
    local_14 = sub_811e(DAT_01fe);
    uStack_1a = (code *)0x87e0;
    sub_8814();
    uStack_1a = (code *)0x87e4;
    sub_881c((short)&uStack_1a + 1);
    puVar3 = local_13;
    DAT_0000 = '\f';
    do {
      *puVar3 = 8;
      puVar3 = puVar3 + 1;
      DAT_0000 = DAT_0000 + -1;
    } while (DAT_0000 != '\0');
    uStack_1a = (code *)0x87fa;
    local_13[0] = sub_811e(DAT_01fa);
    uStack_1a = (code *)0x8802;
    local_f = sub_811e(DAT_01fe);
  }
  uStack_1a = sub_8811;
  cVar2 = sub_8146(local_13);
  return cVar2;
}



/* ===== 0x8811  sub_8811 ===== */

void sub_8811(void)

{
  return;
}



/* ===== 0x8814  sub_8814 ===== */

void sub_8814(void)

{
  sub_9e0d();
  DAT_0002._0_1_ = 5;
  return;
}



/* ===== 0x881C  sub_881c ===== */

void sub_881c(short param_1)

{
  DAT_0001 = 0;
  DAT_0000 = 9;
                    /* WARNING: Subroutine does not return */
  x_8080((undefined1)DAT_0002,param_1 + 1);
}



/* ===== 0x8828  sub_8828 ===== */

void sub_8828(void)

{
  sub_90cc();
  sub_9094();
  DAT_000a._0_1_ = 0xff;
  DAT_000e = 0;
  x_8841();
  return;
}



/* ===== 0x8841  x_8841 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x_8841(void)

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
      sub_8b8a();
      return;
    }
    DAT_0008 = &UNK_0280 + DAT_000e;
    if (*DAT_0008 == 'Z') {
      DAT_0001 = '\0';
      sub_8490();
      do {
        sub_9e46();
      } while (!(bool)(extraout_CC >> 1 & 1));
      if (DAT_0008[6] == DAT_0001) {
        sub_9dc3();
        sVar2 = sub_995a();
        if (sVar2 == 0) {
          sub_8b79();
          return;
        }
        sub_9dc3();
        sub_9b92();
        pbVar3 = (byte *)sub_8480();
        uVar4 = (ushort)*pbVar3 << 8;
        pbVar3 = (byte *)sub_8118(0);
        DAT_0001 = *pbVar3;
        uVar4 = uVar4 & 0xff00 | (ushort)(byte)((byte)uVar4 | DAT_0001);
        pcVar5 = (char *)sub_9e40(DAT_0001);
        DAT_000a._1_1_ = *pcVar5;
        pcVar5 = (char *)sub_8112();
        cVar1 = *pcVar5;
        if (cVar1 == '\0') {
          sub_9eb3();
          if (!(bool)(extraout_CC_03 >> 1 & 1)) {
            DAT_000a._0_1_ = 3;
            sub_8b71();
            return;
          }
          sub_8b71();
          return;
        }
        if (cVar1 == '\x01') {
          sub_9eb3();
          if (!(bool)(extraout_CC_02 >> 1 & 1)) {
            DAT_000a._0_1_ = 2;
            sub_8b71();
            return;
          }
          sub_8b71();
          return;
        }
        if (cVar1 == '\x04') {
          sub_9eb3();
          if (!(bool)(extraout_CC_04 >> 1 & 1)) {
            DAT_000a._0_1_ = 4;
            sub_8b71();
            return;
          }
          sub_8b71();
          return;
        }
        if (cVar1 == '\a') {
          sub_9eb3();
          if (!(bool)(extraout_CC_05 >> 1 & 1)) {
            DAT_000a._0_1_ = 5;
            sub_8b71();
            return;
          }
          sub_8b71();
          return;
        }
        if (cVar1 == '\n') {
          sub_9eb3();
          if (!(bool)(extraout_CC_06 >> 1 & 1)) {
            DAT_000a._0_1_ = 6;
            sub_8b71();
            return;
          }
          sub_8b71();
          return;
        }
        if (cVar1 == '\x11') {
          sub_9eb3();
          if (!(bool)(extraout_CC_01 >> 1 & 1)) {
            DAT_000a._0_1_ = 1;
            sub_8b71();
            return;
          }
          sub_8b71();
          return;
        }
        if (cVar1 == '\x12') {
          sub_9eb3();
          if (!(bool)(extraout_CC_07 >> 1 & 1)) {
            DAT_000a._0_1_ = 7;
            sub_8b71();
            return;
          }
          sub_8b71();
          return;
        }
        if (cVar1 == '\x15') {
          sub_9eb3();
          if (!(bool)(extraout_CC_00 >> 1 & 1)) {
            DAT_000a._0_1_ = 0;
            sub_8b71();
            return;
          }
          sub_8b71();
          return;
        }
        if (cVar1 != '.') {
          sub_8b71();
          return;
        }
        if ((char)DAT_000a == '\x01') {
          sub_8b8e();
          return;
        }
        if (_DAT_02cb == 0) {
          sub_8a46();
          return;
        }
        DAT_0001 = DAT_021c;
        if (9 < DAT_021c) {
          sub_8a15();
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
  sVar2 = sub_9e8d(sVar2);
  if ((bool)(extraout_CC_08 >> 1 & 1)) goto LAB_897e;
  DAT_0000 = DAT_0000 + 1;
  goto LAB_8964;
code_r0x896a:
  if (DAT_0001 == DAT_0000) {
    *(ushort *)(&UNK_0208 + (ushort)DAT_0001 * 2) = uVar4;
    DAT_021c = DAT_021c + 1;
    sub_86e8();
  }
LAB_897e:
  sub_9ce7();
  do {
    sub_86d3();
    if (!(bool)(extraout_CC_09 & 1)) break;
    sub_9c6f();
    if ((bool)(extraout_CC_10 >> 1 & 1)) {
      sub_9d5c();
      sub_9d14();
      sub_9ea5();
      break;
    }
    sub_86d1();
    if (!(bool)(extraout_CC_11 & 1)) {
      DAT_0002._1_1_ = 0;
    }
    sub_9ed6();
  } while (!(bool)(extraout_CC_12 >> 1 & 1));
  pcVar5 = &DAT_01fa;
  sub_9e17(&stack0x0000);
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
    sub_9cf6();
  } while (!(bool)(extraout_CC_13 >> 1 & 1));
  DAT_01f9 = 1;
  sub_8146(&stack0x0010);
  sub_9dcf();
  do {
    sub_86d3();
    if (!(bool)(extraout_CC_14 & 1)) break;
    sub_9c6f();
    if ((bool)(extraout_CC_15 >> 1 & 1)) {
      sub_9d40();
      sub_9d05();
      sub_9ea5();
      break;
    }
    sub_86d1();
    if (!(bool)(extraout_CC_16 & 1)) {
      DAT_0002._1_1_ = 0;
    }
    sub_9ed6();
  } while (!(bool)(extraout_CC_17 >> 1 & 1));
  _DAT_02cb = 0;
  sub_8b71();
  return;
}



/* ===== 0x8A15  sub_8a15 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8a15(void)

{
  byte extraout_CC;
  byte extraout_CC_00;
  byte extraout_CC_01;
  byte extraout_CC_02;
  
  sub_9ce7();
  do {
    sub_86d3();
    if (!(bool)(extraout_CC & 1)) break;
    sub_9c6f();
    if ((bool)(extraout_CC_00 >> 1 & 1)) {
      sub_9d5c();
      sub_9d14();
      sub_9ea5();
      break;
    }
    sub_86d1();
    if (!(bool)(extraout_CC_01 & 1)) {
      DAT_0002._1_1_ = 0;
    }
    sub_9ed6();
  } while (!(bool)(extraout_CC_02 >> 1 & 1));
  _DAT_02cb = 0;
  sub_8b71();
  return;
}



/* ===== 0x8A46  sub_8a46 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8a46(void)

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
    sub_8b71();
    return;
  }
  DAT_0000 = 0;
  DAT_0001 = DAT_021c;
  while( true ) {
    if (DAT_0001 <= DAT_0000) {
      sub_8b71();
      return;
    }
    sub_9e8d();
    if ((bool)(extraout_CC >> 1 & 1)) break;
    DAT_0000 = DAT_0000 + 1;
  }
  if (DAT_01f9 == '\0') {
    pcVar3 = &DAT_01fa;
    sub_9e17(0,&stack0x0000);
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
      sub_9cf6();
    } while (!(bool)(extraout_CC_00 >> 1 & 1));
    DAT_01f9 = 1;
    sub_8146(&stack0x0010);
    sub_9dcf();
    while( true ) {
      sub_86d3();
      if (!(bool)(extraout_CC_01 & 1)) {
        sub_8b6e();
        return;
      }
      sub_9c6f();
      if ((bool)(extraout_CC_02 >> 1 & 1)) break;
      sub_86d1();
      if (!(bool)(extraout_CC_03 & 1)) {
        DAT_0002._1_1_ = 0;
      }
      sub_9ed6();
      if ((bool)(extraout_CC_04 >> 1 & 1)) {
        sub_8b6e();
        return;
      }
    }
    sub_9d40();
    sub_9d05();
    sub_8b5d();
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
  sub_82b3(&stack0x0009);
  sub_9ce7();
  do {
    sub_86d3();
    if (!(bool)(extraout_CC_05 & 1)) break;
    sub_9c6f();
    if ((bool)(extraout_CC_06 >> 1 & 1)) {
      sub_9e21();
      puVar1 = (undefined1 *)sub_8118();
      *puVar1 = 0;
      DAT_000c = sub_8112();
      puVar1 = (undefined1 *)sub_9e3d(DAT_0002._0_1_);
      *puVar1 = extraout_A;
      clk_gate_enable_3(0x18);
      _DAT_0000 = (char *)0x7;
      sub_9efe();
      sVar2 = sub_9e95(10);
      *(undefined1 *)(sVar2 + 0xe) = extraout_A_00;
      sub_9ea5(0xb);
      sub_8b6e();
      return;
    }
    sub_86d1();
    if (!(bool)(extraout_CC_07 & 1)) {
      DAT_0002._1_1_ = 0;
    }
    sub_9ed6();
  } while (!(bool)(extraout_CC_08 >> 1 & 1));
  sub_86e8();
  _DAT_0000 = (char *)CONCAT11((undefined1)DAT_000a,DAT_0001);
  sub_8b96(DAT_000a._0_1_);
  DAT_000e = DAT_000e + '\a';
  DAT_02d6 = DAT_02d6 + -7;
  x_8841();
  return;
}



/* ===== 0x8B5D  sub_8b5d ===== */

void sub_8b5d(void)

{
  sub_9ea5();
  sub_8b6e();
  return;
}



/* ===== 0x8B6E  sub_8b6e ===== */

void sub_8b6e(void)

{
  sub_86e8();
  DAT_0000 = (undefined1)DAT_000a;
  sub_8b96(DAT_000a._0_1_);
  DAT_000e = DAT_000e + '\a';
  DAT_02d6 = DAT_02d6 + -7;
  x_8841();
  return;
}



/* ===== 0x8B71  sub_8b71 ===== */

void sub_8b71(void)

{
  DAT_0000 = (undefined1)DAT_000a;
  sub_8b96(DAT_000a._0_1_);
  DAT_000e = DAT_000e + '\a';
  DAT_02d6 = DAT_02d6 + -7;
  x_8841();
  return;
}



/* ===== 0x8B79  sub_8b79 ===== */

void sub_8b79(void)

{
  DAT_000e = DAT_000e + '\a';
  DAT_02d6 = DAT_02d6 + -7;
  x_8841();
  return;
}



/* ===== 0x8B8A  sub_8b8a ===== */

void sub_8b8a(undefined1 param_1)

{
  DAT_02d6 = 0;
  DAT_000e = param_1;
  sub_912e();
  return;
}



/* ===== 0x8B8E  sub_8b8e ===== */

void sub_8b8e(undefined1 param_1)

{
  DAT_000e = param_1;
  sub_912e();
  return;
}



/* ===== 0x8B96  sub_8b96 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8b96(byte param_1)

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
    sub_8d00();
    return;
  }
  local_e = 0xc;
  DAT_0002._0_1_ = DAT_01f9;
  if (DAT_01f9 != '\x01') {
    x_8c31();
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
    pbVar4 = (byte *)sub_9d32((short)&uStack_10 + 1);
    if ((bool)(extraout_CC >> 1 & 1)) {
      DAT_0001 = DAT_0004 & 0xf;
      *pbVar4 = DAT_0001;
      cVar1 = (char)DAT_0002;
      if (DAT_0000 != '\x01') goto LAB_8cc9;
      uStack_10 = (code *)0x8c89;
      pbVar4 = (byte *)sub_811e((char)DAT_0002);
      cVar1 = extraout_A_00;
      goto LAB_8cd3;
    }
    DAT_0001 = DAT_0004 & 0xf0;
    *pbVar4 = DAT_0001;
    cVar1 = (char)DAT_0002;
    if (DAT_0000 == '\x01') {
      uStack_10 = (code *)0x8c72;
      pbVar4 = (byte *)sub_811e((char)DAT_0002);
      bVar2 = extraout_A;
      goto LAB_8cd6;
    }
LAB_8caf:
    uStack_10 = (code *)0x8cb2;
    cVar1 = sub_811e(cVar1);
  }
  else {
    if (DAT_0000 == '\x01') {
      return;
    }
    DAT_0005 = param_1 >> 1;
    DAT_0004 = 0;
    uStack_10 = (code *)0x8c9f;
    pbVar4 = (byte *)sub_9d32((short)&uStack_10 + 1);
    if ((bool)(extraout_CC_00 >> 1 & 1)) {
      DAT_0001 = DAT_0004 & 0xf;
      *pbVar4 = DAT_0001;
      cVar1 = (char)DAT_0002;
      if (DAT_0002._0_1_ == '\x01') {
        cVar1 = *pcVar3;
LAB_8cc9:
        uStack_10 = (code *)0x8ccc;
        cVar1 = sub_811e(cVar1);
      }
      uStack_10 = (code *)0x8cd3;
      pbVar4 = (byte *)sub_9823(cVar1);
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
  pbVar4 = (byte *)sub_9823(cVar1);
  bVar2 = extraout_A_01;
LAB_8cd6:
  *pbVar4 = bVar2 | DAT_0001;
  DAT_01f9 = 0;
  uStack_10 = (code *)0x8ce8;
  sub_82b3(&local_e);
  auStack_7[0] = 0;
  uStack_10 = (code *)0x8ced;
  sub_9f02();
  DAT_0002._0_1_ = 7;
  DAT_0001 = 0;
  DAT_0000 = 0x18;
                    /* WARNING: Subroutine does not return */
  uStack_10 = sub_8d00;
  x_8080((char)DAT_0002,auStack_7);
}



/* ===== 0x8C31  x_8c31 ===== */

void x_8c31(short param_1,undefined1 param_2)

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
    pbVar5 = (byte *)sub_9d32();
    if ((bool)(extraout_CC >> 1 & 1)) {
      DAT_0001 = DAT_0004 & 0xf;
      *pbVar5 = DAT_0001;
      cVar1 = (char)DAT_0002;
      if (DAT_0000 != '\x01') goto LAB_8cc9;
      pbVar5 = (byte *)sub_811e((char)DAT_0002);
      cVar1 = extraout_A_00;
      goto LAB_8cd3;
    }
    DAT_0001 = DAT_0004 & 0xf0;
    *pbVar5 = DAT_0001;
    cVar1 = (char)DAT_0002;
    if (DAT_0000 == '\x01') {
      pbVar5 = (byte *)sub_811e((char)DAT_0002);
      bVar2 = extraout_A;
      goto LAB_8cd6;
    }
LAB_8caf:
    cVar1 = sub_811e(cVar1);
  }
  else {
    if (DAT_0000 == '\x01') {
      return;
    }
    DAT_0005 = DAT_0001 >> 1;
    DAT_0004 = 0;
    pbVar5 = (byte *)sub_9d32();
    if ((bool)(extraout_CC_00 >> 1 & 1)) {
      DAT_0001 = DAT_0004 & 0xf;
      *pbVar5 = DAT_0001;
      cVar1 = (char)DAT_0002;
      if (DAT_0002._0_1_ == '\x01') {
        cVar1 = *pcVar4;
LAB_8cc9:
        cVar1 = sub_811e(cVar1);
      }
      pbVar5 = (byte *)sub_9823(cVar1);
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
  pbVar5 = (byte *)sub_9823(cVar1);
  bVar2 = extraout_A_01;
LAB_8cd6:
  *pbVar5 = bVar2 | DAT_0001;
  DAT_01f9 = 0;
  sub_82b3(&stack0x0001);
  param_2 = 0;
  sub_9f02();
  DAT_0002._0_1_ = 7;
  DAT_0001 = 0;
  DAT_0000 = 0x18;
                    /* WARNING: Subroutine does not return */
  x_8080((char)DAT_0002,&param_2);
}



/* ===== 0x8D00  sub_8d00 ===== */

void sub_8d00(void)

{
  return;
}



/* ===== 0x8D03  sub_8d03 ===== */

void sub_8d03(void)

{
  DAT_0002._1_1_ = (char)DAT_0002 + '\x01';
  if ((((char)DAT_0002 == '\0') &&
      (DAT_0002._0_1_ = DAT_0002._0_1_ + '\x01', DAT_0002._0_1_ == '\0')) &&
     (DAT_0001 = DAT_0001 + '\x01', DAT_0001 == '\0')) {
    DAT_0000 = DAT_0000 + '\x01';
  }
  return;
}



/* ===== 0x8D16  sub_8d16 ===== */

void sub_8d16(void)

{
  DAT_0002._1_1_ = (char)DAT_0002 - DAT_0007;
  DAT_0002._0_1_ = (DAT_0002._0_1_ - DAT_0006) - (DAT_0002._0_1_ < DAT_0006);
  DAT_0001 = (DAT_0001 - DAT_0005) - (DAT_0001 < DAT_0005);
  DAT_0000 = (DAT_0000 - DAT_0004) - (DAT_0000 < DAT_0004);
  return;
}



/* ===== 0x8D31  sub_8d31 ===== */

void sub_8d31(void)

{
  ushort *puVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  short sVar7;
  
  puVar1 = (ushort *)sub_9ac4();
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



/* ===== 0x8DBB  sub_8dbb ===== */

void sub_8dbb(void)

{
  sub_9aaa();
  sub_8dc3();
  return;
}



/* ===== 0x8DC0  sub_8dc0 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8dc0(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  char cVar6;
  ushort uVar7;
  ushort uVar8;
  
  sub_9ab7();
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



/* ===== 0x8DC3  sub_8dc3 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8dc3(void)

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



/* ===== 0x8E30  sub_8e30 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8e30(void)

{
  return;
}



/* ===== 0x8E40  sub_8e40 ===== */

void sub_8e40(char param_1)

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



/* ===== 0x8E51  sub_8e51 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8e51(short param_1)

{
  DAT_0002 = param_1;
  _DAT_0000 = 0;
  if (param_1 < 0) {
    _DAT_0000 = 0xffff;
  }
  return;
}



/* ===== 0x8E5C  sub_8e5c ===== */

void sub_8e5c(void)

{
  char cVar1;
  
  sub_908f();
  sub_9094();
  clk_gate_enable_1();
  sub_9d4e(0);
  DAT_0002._0_1_ = 0;
  DAT_0001 = 0;
  DAT_0000 = 0xe1;
  sub_93e5();
  sub_9c95();
  sub_9edc();
  DAT_0000 = 0x7c;
  sub_9e73();
  sub_9eeb();
  DAT_0000 = 1;
  sub_9c03();
  sub_9d90();
  sub_9b17();
  sub_9d9d();
  sub_94d6();
  clk_set_divider();
  DAT_0000 = 1;
  uart1_set_control_bits();
  DAT_0000 = 0;
  uart1_set_control_bits();
  DAT_0000 = 0;
  uart1_set_control_bits();
  DAT_025f = 0;
  sub_9b72();
  __EnableInterrupt();
  sub_917b();
  cVar1 = DAT_02cf;
  DAT_0002._1_1_ = DAT_02cf;
  DAT_02cf = DAT_02cf + '\x01';
  DAT_0002._0_1_ = 1;
  DAT_0001 = 2;
  DAT_0000 = 0x1b;
                    /* WARNING: Subroutine does not return */
  x_8080(cVar1,&DAT_0206);
}



/* ===== 0x8EE6  sub_8ee6 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_8ee6(void)

{
  byte extraout_CC;
  char cVar1;
  char extraout_A;
  short sVar2;
  
  do {
    if (uart_flag_c != '\0') {
      DAT_0008 = (undefined *)CONCAT11(rx_frame_len,DAT_0008._1_1_);
      _DAT_0000 = (ushort)rx_frame_len;
      sub_9b92(uart_flag_c,&DAT_021d);
      DAT_023d = DAT_0008._0_1_;
      rx_frame_len = 0;
      uart_flag_c = '\0';
      sub_851a();
      DAT_023d = 0;
    }
    cVar1 = DAT_02d5;
    if (DAT_02d5 != '\0') {
      _DAT_0000 = (ushort)DAT_025f;
      sub_9b92(&UNK_0280);
      DAT_02d6 = DAT_025f;
      DAT_025f = 0;
      sub_8828();
      DAT_02d5 = '\0';
      cVar1 = sub_9b72();
    }
    DAT_0008 = &UNK_01bf;
    DAT_000a._0_1_ = '\x05';
    do {
      if (DAT_0008[-1] != '\0') {
        DAT_000c = DAT_0008 + 4;
        sub_95b5(cVar1);
        sVar2 = sub_8e30(DAT_0008);
        cVar1 = extraout_A;
        if (!(bool)(extraout_CC & 1)) {
          if (*(short *)(sVar2 + 8) != 0) {
            func_0x0000eb80();
          }
          DAT_0002 = 0;
          _DAT_0000 = 0;
          cVar1 = x_95de(DAT_000c);
        }
      }
      DAT_0008 = DAT_0008 + 0xb;
      DAT_000a._0_1_ = DAT_000a._0_1_ + -1;
    } while (DAT_000a._0_1_ != '\0');
    sub_9edc();
  } while( true );
}



/* ===== 0x8F7E  x_8f7e ===== */

void x_8f7e(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte extraout_A;
  byte extraout_A_00;
  ushort uVar4;
  byte extraout_XL;
  undefined2 uStack_3;
  
  sub_90cc();
  bVar3 = sub_90d1();
  bVar2 = DAT_0007;
  bVar1 = DAT_0006;
  UART1_CR1 = UART1_CR1 & 0xef;
  UART1_CR3 = UART1_CR3 & 0xcf | DAT_0004;
  UART1_CR1 = (UART1_CR1 | bVar3) & 0xf9 | DAT_0005;
  UART1_BRR1 = 0;
  UART1_BRR2 = 0;
  DAT_0006 = bVar3;
  sub_8e40();
  sub_9161();
  sub_98b6();
  sub_9154();
  sub_8dc3();
  uVar4 = sub_95cd();
  sub_98b6((char)uVar4,(ushort)extraout_A << 8 | uVar4 >> 8);
  sub_916e();
  uVar4 = sub_95a5();
  sub_9e9d((char)uVar4,(ushort)extraout_A_00 << 8 | uVar4 >> 8);
  sub_90c2();
  sub_9147();
  sub_9e9d();
  sub_9154();
  sub_8dc3();
  sub_90fe();
  sub_8d16();
  sub_8e40();
  sub_8dc0();
  UART1_BRR2 = (byte)DAT_0002 & 0xf | UART1_BRR2;
  sub_99dc(uStack_3);
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
  sub_9127();
  return;
}



/* ===== 0x8FB5  x_8fb5 ===== */

void x_8fb5(byte param_1,undefined2 param_2,byte param_3,byte param_4)

{
  byte extraout_A;
  byte extraout_A_00;
  ushort uVar1;
  byte extraout_XL;
  
  UART1_CR1 = param_1 | DAT_0005;
  UART1_BRR1 = 0;
  UART1_BRR2 = 0;
  sub_8e40();
  sub_9161();
  sub_98b6();
  sub_9154();
  sub_8dc3();
  uVar1 = sub_95cd();
  sub_98b6((char)uVar1,(ushort)extraout_A << 8 | uVar1 >> 8);
  sub_916e();
  uVar1 = sub_95a5();
  sub_9e9d((char)uVar1,(ushort)extraout_A_00 << 8 | uVar1 >> 8);
  sub_90c2();
  sub_9147();
  sub_9e9d();
  sub_9154();
  sub_8dc3();
  sub_90fe();
  sub_8d16();
  sub_8e40();
  sub_8dc0();
  UART1_BRR2 = (byte)DAT_0002 & 0xf | UART1_BRR2;
  sub_99dc(param_2);
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
  sub_9127();
  return;
}



/* ===== 0x908A  x_908a ===== */

void x_908a(void)

{
  FUN_9099(0);
  return;
}



/* ===== 0x908F  sub_908f ===== */

void sub_908f(void)

{
  FUN_9099(8);
  return;
}



/* ===== 0x9094  sub_9094 ===== */

void sub_9094(void)

{
  FUN_9099(0xc);
  return;
}



/* ===== 0x9099  FUN_9099 ===== */

undefined2 FUN_9099(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x90AC  sub_90ac ===== */

void sub_90ac(undefined2 param_1)

{
  DAT_0008 = param_1;
  FUN_90ba();
  return;
}



/* ===== 0x90B3  thunk_FUN_9127 ===== */

void sub_90b3(undefined2 param_1)

{
  DAT_000c = param_1;
  FUN_90ba();
  return;
}



/* ===== 0x90BA  FUN_90ba ===== */

undefined2 FUN_90ba(void)

{
  undefined2 in_stack_00000001;
  
  return in_stack_00000001;
}



/* ===== 0x90C2  sub_90c2 ===== */

void sub_90c2(void)

{
  FUN_90d6(0);
  return;
}



/* ===== 0x90C7  sub_90c7 ===== */

void sub_90c7(void)

{
  FUN_90d6(4);
  return;
}



/* ===== 0x90CC  sub_90cc ===== */

void sub_90cc(void)

{
  FUN_90d6(8);
  return;
}



/* ===== 0x90D1  sub_90d1 ===== */

void sub_90d1(void)

{
  FUN_90d6(0xc);
  return;
}



/* ===== 0x90D6  FUN_90d6 ===== */

undefined2 FUN_90d6(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x90F3  sub_90f3 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_90f3(undefined2 param_1,undefined2 param_2)

{
  _DAT_0000 = param_1;
  DAT_0002 = param_2;
  FUN_911f();
  return;
}



/* ===== 0x90FE  FUN_90fe ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_90fe(undefined2 param_1,undefined2 param_2)

{
  _DAT_0004 = param_1;
  _DAT_0006 = param_2;
  FUN_911f();
  return;
}



/* ===== 0x9109  sub_9109 ===== */

void sub_9109(undefined2 param_1,undefined2 param_2)

{
  DAT_0008 = param_1;
  DAT_000a = param_2;
  FUN_911f();
  return;
}



/* ===== 0x9114  sub_9114 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_9114(undefined2 param_1,undefined2 param_2)

{
  DAT_000c = param_1;
  _DAT_000e = param_2;
  FUN_911f();
  return;
}



/* ===== 0x911F  FUN_911f ===== */

undefined2 FUN_911f(void)

{
  undefined2 in_stack_00000001;
  
  return in_stack_00000001;
}



/* ===== 0x9127  FUN_9127 ===== */

void sub_9127(void)

{
  sub_9114();
  sub_9109();
  return;
}



/* ===== 0x912A  thunk_FUN_914d ===== */

void sub_912a(void)

{
  sub_9109();
  return;
}



/* ===== 0x912E  sub_912e ===== */

void sub_912e(void)

{
  sub_90b3();
  sub_9109();
  return;
}



/* ===== 0x9135  thunk_FUN_914d ===== */

void sub_9135(void)

{
  sub_90ac();
  return;
}



/* ===== 0x9139  sub_9139 ===== */

void sub_9139(void)

{
  DAT_0004 = DAT_0002._0_1_;
  DAT_0005 = (undefined1)DAT_0002;
  return;
}



/* ===== 0x9140  sub_9140 ===== */

void sub_9140(void)

{
  DAT_000a._0_1_ = DAT_0008._0_1_;
  DAT_000a._1_1_ = (undefined1)DAT_0008;
  return;
}



/* ===== 0x9147  sub_9147 ===== */

void sub_9147(void)

{
  DAT_0000 = DAT_000c._0_1_;
  DAT_0001 = (undefined1)DAT_000c;
  DAT_0002._0_1_ = DAT_000e;
  DAT_0002._1_1_ = DAT_000f;
  return;
}



/* ===== 0x9154  sub_9154 ===== */

void sub_9154(void)

{
  DAT_0004 = DAT_0008._0_1_;
  DAT_0005 = (undefined1)DAT_0008;
  DAT_0006 = DAT_000a._0_1_;
  DAT_0007 = (undefined1)DAT_000a;
  return;
}



/* ===== 0x9161  FUN_9161 ===== */

void sub_9161(void)

{
  DAT_0008._0_1_ = DAT_0000;
  DAT_0008._1_1_ = DAT_0001;
  DAT_000a._0_1_ = DAT_0002._0_1_;
  DAT_000a._1_1_ = (undefined1)DAT_0002;
  return;
}



/* ===== 0x916E  sub_916e ===== */

void sub_916e(void)

{
  DAT_000c._0_1_ = DAT_0000;
  DAT_000c._1_1_ = DAT_0001;
  DAT_000e = DAT_0002._0_1_;
  DAT_000f = (undefined1)DAT_0002;
  return;
}



/* ===== 0x917B  sub_917b ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_917b(void)

{
  char cVar1;
  short sVar2;
  
  _DAT_0000 = &UNK_01bf;
  cVar1 = '\x05';
  do {
    _DAT_0000[-1] = 0;
    _DAT_0006 = 0;
    _DAT_0004 = 0;
    sVar2 = sub_95ec(cVar1,_DAT_0000);
    cVar1 = sub_95ec(sVar2 + 4);
    *(undefined2 *)(_DAT_0000 + 8) = 0;
    _DAT_0000 = _DAT_0000 + 0xb;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  DAT_01d4 = 1;
  _DAT_01d5 = 0;
  _DAT_01d7 = 0x4b;
  _DAT_01d9 = 0;
  _DAT_01db = 0;
  _DAT_01dd = ret_935e;
  DAT_01c9 = 1;
  _DAT_01ca = 0;
  _DAT_01cc = 0x32;
  _DAT_01ce = 0;
  _DAT_01d0 = 0;
  _DAT_01d2 = ret_8700;
  DAT_0002 = (ushort)DAT_0206;
  _DAT_0000 = (undefined *)0x0;
  DAT_01be = DAT_0206 != 0;
  x_95de(&UNK_01bf);
  _DAT_01c3 = 0;
  _DAT_01c5 = 0;
  _DAT_01c7 = gap_92c2;
  DAT_01ea = 1;
  _DAT_01eb = 0;
  _DAT_01ed = 10;
  _DAT_01ef = 0;
  _DAT_01f1 = 0;
  _DAT_01f3 = gap_998a;
  return;
}



/* ===== 0x9223  vec_9223 ===== */

undefined2 vec_9223(undefined2 param_1)

{
  undefined1 uVar1;
  byte extraout_XL;
  
  sub_90c2();
  sub_90c7();
  uVar1 = DAT_0008._0_1_;
  DAT_0008._0_1_ = 1;
  if (DAT_02d4 == '\0') {
    DAT_02db = 8;
    if (DAT_02d9 < 8) {
      if ((PA_IDR & 2) != 0) {
        sub_99d4(1);
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
          sub_9b72();
        }
        DAT_02da = 0;
        sub_9f06();
        sub_9d90(1);
      }
    }
  }
  else {
    sub_9a0b(0x60e);
    DAT_02d9 = 0;
    DAT_02da = 0;
    DAT_02d4 = '\0';
    DAT_02db = 8;
  }
  sub_9ee6(1);
  DAT_0008._0_1_ = uVar1;
  sub_90fe();
  sub_90f3();
  return param_1;
}



/* ===== 0x92C2  gap_92c2 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_92c2(void)

{
  undefined1 uVar1;
  char *pcVar2;
  char *in_Y;
  
  sub_90cc();
  sub_9094();
  uVar1 = DAT_000e;
  DAT_000c = &DAT_02df;
  DAT_0008 = &DAT_0182;
  DAT_000e = '\f';
  do {
    if (*DAT_0008 != '\0') {
      sub_9140();
      pcVar2 = DAT_000a + 1;
      DAT_000a = pcVar2;
      if (*pcVar2 == '\x05') {
        sub_9e34();
        pcVar2 = (char *)thunk_FUN_9eba();
      }
      if (*DAT_000a == '\0') {
        pcVar2 = (char *)sub_8480();
        if (*pcVar2 == '\x05') {
          sub_9e34();
          pcVar2 = (char *)thunk_FUN_9f12();
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
      in_Y = (char *)sub_8480(in_Y);
      if (*in_Y == '\0') {
        _DAT_0000 = (char *)sub_8118(pcVar2);
        if (*_DAT_0000 == '\0') {
          pcVar2 = (char *)sub_8112();
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
    DAT_0008 = (char *)sub_9e40();
    DAT_000c = DAT_000c + 3;
    DAT_000e = DAT_000e + -1;
    if (DAT_000e == '\0') {
      DAT_000e = uVar1;
      sub_912e();
      return;
    }
  } while( true );
}



/* ===== 0x935E  ret_935e ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ret_935e(void)

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
    sub_86cb(bVar2);
    pcVar3 = (char *)sub_86d8(uVar4);
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
    _DAT_0000 = (char *)sub_86d8(DAT_02ce);
    if ((*_DAT_0000 != '\0') && (*(short *)(_DAT_0000 + 1) == 0)) break;
    sub_9df9();
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
  sub_9728();
  sub_9df9();
  if ((bool)(extraout_CC & 1)) {
    return;
  }
  DAT_02ce = 0;
  return;
}



/* ===== 0x93E5  sub_93e5 ===== */

undefined1 sub_93e5(char param_1)

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



/* ===== 0x9464  clk_set_divider ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void clk_set_divider(void)

{
  char cVar1;
  undefined1 *puVar2;
  
  _DAT_0000 = &UNK_0172;
  x_9c31(0x10);
  _DAT_0000 = (undefined *)0x21;
  x_9c31(&DAT_021d);
  sub_9b3a();
  sub_95b5(&DAT_01f5);
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
    sub_86df();
    sub_9acf();
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



/* ===== 0x94D6  sub_94d6 ===== */

void sub_94d6(void)

{
  undefined1 uVar1;
  
  sub_90cc();
  uVar1 = DAT_000c._0_1_;
  DAT_0000 = 0x40;
  sub_9541(&PD_ODR);
  DAT_0000 = 0x40;
  sub_9541(0x10,&PD_ODR);
  pin_state_d3 = tim2_set_ccr1l(8,&PD_ODR);
  pin_state_d4 = tim2_set_ccr1l(0x10,&PD_ODR);
  DAT_0008 = (undefined2 *)&DAT_02df;
  DAT_000c._0_1_ = '\f';
  do {
    sub_9140();
    DAT_000a = DAT_000a + 2;
    DAT_0000 = 0xc0;
    sub_9541(*DAT_000a,*DAT_0008);
    FUN_9f12(*DAT_000a,*DAT_0008);
    DAT_0008 = (undefined2 *)((short)DAT_0008 + 3);
    DAT_000c._0_1_ = DAT_000c._0_1_ + -1;
  } while (DAT_000c._0_1_ != '\0');
  DAT_000c._0_1_ = uVar1;
  sub_912a();
  return;
}



/* ===== 0x9541  sub_9541 ===== */

void sub_9541(byte param_1,byte *param_2)

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



/* ===== 0x95A5  sub_95a5 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * sub_95a5(void)

{
  undefined2 *puVar1;
  byte *in_stack_00000001;
  
  puVar1 = (undefined2 *)(&stack0x0002 + *in_stack_00000001);
  _DAT_0000 = *puVar1;
  DAT_0002 = puVar1[1];
  return puVar1;
}



/* ===== 0x95B5  sub_95b5 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * sub_95b5(undefined2 *param_1)

{
  _DAT_0000 = *param_1;
  DAT_0002 = param_1[1];
  return param_1;
}



/* ===== 0x95C1  sub_95c1 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * sub_95c1(undefined2 *param_1)

{
  _DAT_0004 = *param_1;
  _DAT_0006 = param_1[1];
  return param_1;
}



/* ===== 0x95CD  sub_95cd ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_95cd(void)

{
  byte bVar1;
  byte *in_stack_00000001;
  
  bVar1 = *in_stack_00000001;
  *(undefined2 *)(&stack0x0002 + bVar1) = _DAT_0000;
  *(undefined2 *)(&stack0x0004 + bVar1) = DAT_0002;
  return;
}



/* ===== 0x95DE  x_95de ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void x_95de(undefined2 *param_1)

{
  *param_1 = _DAT_0000;
  param_1[1] = DAT_0002;
  return;
}



/* ===== 0x95EC  sub_95ec ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_95ec(undefined2 *param_1)

{
  *param_1 = _DAT_0004;
  param_1[1] = _DAT_0006;
  return;
}



/* ===== 0x95FA  sub_95fa ===== */

void sub_95fa(undefined2 *param_1)

{
  *param_1 = DAT_0008;
  param_1[1] = DAT_000a;
  return;
}



/* ===== 0x9608  vec_9608 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 vec_9608(undefined2 param_1)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  
  sub_9ec8();
  sub_90c2();
  sub_90c7();
  puVar3 = &DAT_01c3;
  cVar2 = '\x05';
  do {
    if (puVar3[-5] != '\0') {
      sub_95b5(puVar3);
      sub_8d03();
      cVar2 = x_95de(puVar3);
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
    sub_9f06(cVar1);
  }
  if (_DAT_02cb != 0) {
    _DAT_02cb = _DAT_02cb + -1;
  }
  sub_9ef0(1);
  sub_90fe();
  sub_90f3();
  return param_1;
}



/* ===== 0x966A  sub_966a ===== */

void sub_966a(char param_1)

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
      bVar1 = sub_9cd2(DAT_0000);
    }
    ITC_SPR1 = bVar1 | ITC_SPR1;
  }
  return;
}



/* ===== 0x96CB  itc_set_priority ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Interrupt priority setup via ITC_SPR1/SPR2 (0x50A0/0x50A1). */

undefined2 itc_set_priority(undefined2 param_1)

{
  ushort uVar1;
  short sVar2;
  
  sub_9ec8();
  sub_90c2();
  sub_90c7();
  uVar1 = (ushort)DAT_02d1;
  DAT_02d1 = DAT_02d1 + 1;
  sVar2 = uVar1 + 0x14;
  DAT_0002 = (ushort)uart_state_a;
  _DAT_0000 = 0x25;
  _DAT_0000 = sub_99b6(DAT_0002);
  sub_9f26(*(undefined1 *)(sVar2 + _DAT_0000));
  _DAT_0000 = 0x25;
  sVar2 = sub_99b6(uart_state_a);
  if (*(char *)(sVar2 + 0x34) == DAT_02d1) {
    sub_9728(0,&UNK_0277);
  }
  sub_90fe();
  sub_90f3();
  return param_1;
}



/* ===== 0x9728  sub_9728 ===== */

void sub_9728(char param_1,undefined2 param_2)

{
  DAT_0000 = (char)((ushort)param_2 >> 8);
  DAT_0001 = param_1;
  DAT_0002._0_1_ = sub_9e7c((char)param_2);
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



/* ===== 0x9780  uart1_set_control_bits ===== */

void uart1_set_control_bits(char param_1)

{
  byte bVar1;
  
  DAT_0002._1_1_ = DAT_0000;
  DAT_0002._0_1_ = param_1;
  bVar1 = sub_9d69();
  DAT_0004 = ~bVar1;
  DAT_0000 = DAT_0001;
  DAT_0000 = sub_9cc8((undefined1)DAT_0002);
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



/* ===== 0x97D3  vec_97d3 ===== */

undefined2 vec_97d3(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  short in_stack_00000001;
  
  sub_9ec8();
  sub_90c2();
  sub_90c7();
  sub_908f();
  uart_flag_b = 10;
  if ((UART1_SR & 8) != 0) {
    UART1_SR = UART1_SR & 0xf7;
  }
  DAT_0001 = rx_frame_len;
  if (rx_frame_len < 0x20) {
    rx_frame_len = rx_frame_len + 1;
    DAT_0000 = 0;
    x_908a();
    uVar1 = sub_9f22();
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
    sub_9f22();
  }
  *(undefined2 *)((short)register0x0008 + -1) = 0x981c;
  sub_90ac();
  *(undefined2 *)((short)register0x0008 + -1) = 0x981f;
  sub_90fe();
  *(undefined2 *)((short)register0x0008 + -1) = 0x9822;
  sub_90f3();
  return *(undefined2 *)((short)register0x0008 + 3);
}



/* ===== 0x9823  sub_9823 ===== */

char sub_9823(char param_1)

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
      sub_8490();
    }
    else if (param_1 == '\x06') {
      DAT_0000 = '\a';
    }
  }
  return DAT_0000;
}



/* ===== 0x9872  sub_9872 ===== */

void sub_9872(void)

{
  undefined1 *puVar1;
  
  sub_90cc();
  DAT_000c._0_1_ = sub_9094();
  DAT_000a = &DAT_02b8;
  DAT_0008 = (undefined2 *)&DAT_02df;
  DAT_000c._1_1_ = '\f';
  do {
    if (*DAT_000a != '\0') {
      puVar1 = (undefined1 *)sub_8480();
      if (DAT_000c._0_1_ == '\x01') {
        thunk_FUN_9eba(*puVar1,*DAT_0008);
      }
      else {
        thunk_FUN_9f12(*puVar1,*DAT_0008);
      }
    }
    DAT_0008 = (undefined2 *)sub_8118();
    DAT_000a = DAT_000a + 1;
    DAT_000c._1_1_ = (char)DAT_000c + -1;
  } while ((char)DAT_000c != '\0');
  sub_912e();
  return;
}



/* ===== 0x98B6  sub_98b6 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_98b6(void)

{
  if (CLK_CMSR == -0x1f) {
    _DAT_0006 = (ushort)(byte)sub_9ef5[(CLK_CKDIVR >> 3 & 0xff03) + 5];
    _DAT_0004 = 0;
    sub_8dbb();
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



/* ===== 0x98F1  clk_gate_enable_1 ===== */

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



/* ===== 0x9927  sub_9927 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_9927(void)

{
  undefined2 in_Y;
  
  _DAT_0004 = (undefined1 *)sub_90cc();
  *_DAT_0004 = 1;
  if (_DAT_0000 == (undefined1 *)0x0 && DAT_0002 == 0) {
    *_DAT_0004 = 0;
  }
  x_95de(_DAT_0004 + 1);
  _DAT_0000 = _DAT_0004 + 5;
  DAT_000a = 0;
  DAT_0008 = 0;
  sub_95fa(_DAT_0000);
  *(undefined2 *)(_DAT_0004 + 9) = in_Y;
  sub_912a();
  return;
}



/* ===== 0x995A  sub_995a ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 sub_995a(byte *param_1)

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



/* ===== 0x998A  gap_998a ===== */

char gap_998a(void)

{
  char cVar1;
  
  cVar1 = DAT_02dc;
  if (DAT_02dc == '\0') {
    DAT_02de = DAT_02de + -1;
    if (DAT_02de == '\0') {
      cVar1 = sub_9872(1);
      DAT_02dc = '\x01';
      DAT_02dd = '\x1e';
    }
  }
  else {
    DAT_02dd = DAT_02dd + -1;
    if (DAT_02dd == '\0') {
      cVar1 = sub_9872(0);
      DAT_02dc = 0;
      DAT_02de = 0x46;
      return cVar1;
    }
  }
  return cVar1;
}



/* ===== 0x99B6  sub_99b6 ===== */

short sub_99b6(ushort param_1)

{
  return (param_1 & 0xff) * (ushort)DAT_0001 +
         ((param_1 & 0xff) * (ushort)DAT_0000 + (param_1 >> 8) * (ushort)DAT_0001) * 0x100;
}



/* ===== 0x99D4  sub_99d4 ===== */

void sub_99d4(char param_1)

{
  if (param_1 != '\0') {
    do {
      param_1 = param_1 + -1;
    } while (param_1 != '\0');
  }
  return;
}



/* ===== 0x99DC  sub_99dc ===== */

ushort sub_99dc(ushort param_1)

{
  return param_1 >> 4;
}



/* ===== 0x99E1  vec_99e1 ===== */

undefined2 vec_99e1(undefined2 param_1)

{
  sub_9ec8();
  sub_90c2();
  sub_90c7();
  if ((PA_IDR & 2) == 0) {
    sub_9a0b(&UNK_01f4);
    reset_startup();
    DAT_02d4 = 1;
    DAT_02db = 8;
    sub_9d90(0);
  }
  sub_90fe();
  sub_90f3();
  return param_1;
}



/* ===== 0x9A0B  sub_9a0b ===== */

void sub_9a0b(void)

{
  tim4_clear_egr(0);
  sub_9e6a(0);
  DAT_0000 = 1;
  sub_9beb(1);
  sub_9d83(1);
  sub_9ee6(1);
  sub_9d76(1);
  DAT_0000 = 3;
  uart1_set_control_bits(0xd);
  return;
}



/* ===== 0x9A34  ret_9a34 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ret_9a34(short *param_1)

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



/* ===== 0x9A5C  ret_9a5c ===== */

/* WARNING: Control flow encountered bad instruction data */

void ret_9a5c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ===== 0x9A84  sub_9a84 ===== */

undefined1 sub_9a84(void)

{
  byte extraout_CC;
  
  DAT_0001 = 0;
  if (DAT_0207 != '\0') {
    DAT_0002._0_1_ = DAT_021c;
    for (DAT_0000 = 0; DAT_0000 < DAT_0002._0_1_; DAT_0000 = DAT_0000 + 1) {
      sub_9e8d();
      if ((bool)(extraout_CC >> 1 & 1)) {
        DAT_0001 = 1;
        return 1;
      }
    }
  }
  return DAT_0001;
}



/* ===== 0x9AAA  sub_9aaa ===== */

void sub_9aaa(undefined2 param_1)

{
  sub_95b5(param_1);
  return;
}



/* ===== 0x9AB7  sub_9ab7 ===== */

void sub_9ab7(undefined2 param_1)

{
  sub_95c1(param_1);
  return;
}



/* ===== 0x9AC4  sub_9ac4 ===== */

undefined2 sub_9ac4(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9ACF  FUN_9acf ===== */

void sub_9acf(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte extraout_CC;
  
  sub_908f();
  uVar2 = DAT_000a._0_1_;
  sub_9ca7();
  do {
    uVar1 = *DAT_0008;
    sub_9de5();
    sub_9f0a(uVar1);
    sub_9db7();
  } while ((bool)(extraout_CC & 1));
  sub_9dda(0xf7);
  DAT_000a._0_1_ = uVar2;
  sub_9135();
  return;
}



/* ===== 0x9AF3  sub_9af3 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_9af3(undefined1 *param_1)

{
  _DAT_0000 = param_1;
  *param_1 = 0;
  _DAT_0006 = 0;
  _DAT_0004 = 0;
  sub_95ec(_DAT_0000 + 1);
  sub_95ec(_DAT_0000 + 5);
  *(undefined2 *)(_DAT_0000 + 9) = 0;
  return;
}



/* ===== 0x9B17  sub_9b17 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 sub_9b17(void)

{
  DAT_0007 = 0xc;
  DAT_0006 = 0x80;
  DAT_0005 = 0;
  DAT_0004 = 0;
  DAT_0002 = 0x960;
  _DAT_0000 = 0;
  x_8f7e(0);
  sub_9728(1,&UNK_0205);
  return 1;
}



/* ===== 0x9B3A  sub_9b3a ===== */

void sub_9b3a(void)

{
  undefined1 uVar1;
  byte extraout_CC;
  undefined1 uVar2;
  
  sub_908f();
  uVar1 = DAT_000a._0_1_;
  sub_9ca7();
  do {
    sub_9de5();
    uVar2 = sub_9f0e();
    *DAT_0008 = uVar2;
    sub_9db7();
  } while ((bool)(extraout_CC & 1));
  sub_9dda(0xf7);
  DAT_000a._0_1_ = uVar1;
  sub_9135();
  return;
}



/* ===== 0x9B72  sub_9b72 ===== */

void sub_9b72(void)

{
  sub_9e58();
  DAT_0000 = 0x60;
  sub_9541(&PA_ODR);
  DAT_0000 = 2;
  sub_966a(0);
  DAT_0000 = 3;
  uart1_set_control_bits(6);
  return;
}



/* ===== 0x9B92  sub_9b92 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 sub_9b92(undefined2 param_1)

{
  undefined1 *in_Y;
  
  DAT_0002 = param_1;
  sub_9139();
  for (; _DAT_0000 != 0; _DAT_0000 = _DAT_0000 + -1) {
    *_DAT_0004 = *in_Y;
    _DAT_0004 = _DAT_0004 + 1;
    in_Y = in_Y + 1;
  }
  return DAT_0002;
}



/* ===== 0x9BCF  x_9bcf ===== */

void x_9bcf(void)

{
  sub_9e21();
  *(undefined1 *)(DAT_0008 + 3) = 0;
  DAT_000c = (undefined1 *)(DAT_0008 + 4);
  *DAT_000c = DAT_0002._0_1_;
  *(undefined1 *)(DAT_0008 + 5) = 0xff;
  return;
}



/* ===== 0x9BEB  sub_9beb ===== */

void sub_9beb(byte param_1)

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



/* ===== 0x9C03  sub_9c03 ===== */

void sub_9c03(byte param_1)

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



/* ===== 0x9C1B  sub_9c1b ===== */

void sub_9c1b(char param_1)

{
  if (param_1 == -3) {
    FLASH_KEYREG_A = 0xae;
    return;
  }
  FLASH_KEYREG_B = 0x56;
  return;
}



/* ===== 0x9C31  x_9c31 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * x_9c31(undefined1 *param_1)

{
  undefined1 in_YL;
  
  DAT_0002 = param_1;
  for (; _DAT_0000 != 0; _DAT_0000 = _DAT_0000 + -1) {
    *param_1 = in_YL;
    param_1 = param_1 + 1;
  }
  return DAT_0002;
}



/* ===== 0x9C47  sub_9c47 ===== */

void sub_9c47(void)

{
  code *pcVar1;
  
  for (pcVar1 = (code *)&DAT_9b5c; pcVar1 != sub_9b72; pcVar1 = (code *)func_0x0000eb80(pcVar1 + 2))
  {
  }
  return;
}



/* ===== 0x9C5B  x_9c5b ===== */

void x_9c5b(void)

{
  undefined1 uStack_1;
  
  DAT_0008 = sub_908f();
  do {
    sub_9f4b(1,&uStack_1);
  } while( true );
}



/* ===== 0x9C6F  sub_9c6f ===== */

void sub_9c6f(byte param_1)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = (ushort)param_1;
  sub_86cb(0);
  sVar1 = sub_99b6(uVar2);
  DAT_0008 = sVar1 + 0x10;
  return;
}



/* ===== 0x9C76  flash_write_key_ae ===== */

/* FLASH key 0xAE -> FLASH_KEYREG_A (0x5062), STM8 mass-key idiom. */

void flash_write_key_ae(void)

{
  short sVar1;
  
  sVar1 = sub_99b6();
  DAT_0008 = sVar1 + 0x10;
  return;
}



/* ===== 0x9C82  flash_write_key_56 ===== */

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* FLASH key 0x56 -> FLASH_KEYREG_B (0x5064), STM8 mass-key idiom. */

void flash_write_key_56(void)

{
  short sVar1;
  
  _DAT_03fe = 0x9c89;
  sVar1 = sub_9f33();
  if (sVar1 != 0) {
    _DAT_03fe = 0x9c8f;
    sub_9c47();
  }
  _DAT_03fe = 0x9c92;
  sub_8e5c();
  iwdg_reload();
  return;
}



/* ===== 0x9C95  sub_9c95 ===== */

void sub_9c95(void)

{
  sub_9ee1();
  sub_9f16(0x55);
  sub_9f1a(6);
  sub_9f1e(0xfa);
  return;
}



/* ===== 0x9CA7  sub_9ca7 ===== */

void sub_9ca7(void)

{
  sub_9d23(0);
  sub_9c1b();
  DAT_000a._0_1_ = 0;
  DAT_0008 = &DAT_01f5;
  return;
}



/* ===== 0x9CB8  sub_9cb8 ===== */

undefined1 sub_9cb8(char param_1)

{
  byte extraout_CC;
  
  DAT_0001 = 0;
  DAT_0000 = param_1;
  if (param_1 != '\0') {
    do {
      sub_9e46();
    } while (!(bool)(extraout_CC >> 1 & 1));
  }
  return DAT_0001;
}



/* ===== 0x9CC8  sub_9cc8 ===== */

void sub_9cc8(void)

{
  if (DAT_0000 != '\0') {
    do {
      DAT_0000 = DAT_0000 + -1;
    } while (DAT_0000 != '\0');
  }
  return;
}



/* ===== 0x9CD2  sub_9cd2 ===== */

char sub_9cd2(char param_1)

{
  return param_1 << 6;
}



/* ===== 0x9CD8  reset_startup ===== */

/* Reset entry: SP = 0x03FF, init calls, then jump to main. */

void reset_startup(void)

{
  sub_9e58();
  DAT_0000 = 0x40;
  sub_9541(&PA_ODR);
  return;
}



/* ===== 0x9CE7  sub_9ce7 ===== */

void sub_9ce7(void)

{
  DAT_0002._0_1_ = DAT_02cf;
  DAT_02cf = DAT_02cf + '\x01';
  DAT_0002._1_1_ = DAT_02ce;
  return;
}



/* ===== 0x9CF6  sub_9cf6 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_9cf6(void)

{
  *_DAT_0000 = DAT_0002._0_1_;
  _DAT_0000 = _DAT_0000 + 1;
  DAT_0002._1_1_ = (char)DAT_0002 + -1;
  return;
}



/* ===== 0x9D05  sub_9d05 ===== */

undefined1 sub_9d05(void)

{
  undefined1 extraout_A;
  short sVar1;
  
  sub_9e03();
  sVar1 = sub_9e95(0xb);
  *(undefined1 *)(sVar1 + 0xf) = extraout_A;
  return 0xc;
}



/* ===== 0x9D14  sub_9d14 ===== */

undefined1 sub_9d14(void)

{
  undefined1 extraout_A;
  short sVar1;
  
  sub_9e03();
  sVar1 = sub_9e95(4);
  *(undefined1 *)(sVar1 + 8) = extraout_A;
  return 5;
}



/* ===== 0x9D23  sub_9d23 ===== */

void sub_9d23(byte param_1)

{
  DAT_0000 = param_1;
  DAT_505a = DAT_505a & 0xfe;
  DAT_505a = DAT_505a | param_1;
  return;
}



/* ===== 0x9D32  sub_9d32 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 sub_9d32(short param_1)

{
  _DAT_0004 = CONCAT11(*(undefined1 *)(param_1 + _DAT_0004 + 2),DAT_0005);
  return DAT_0001;
}



/* ===== 0x9D40  sub_9d40 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_9d40(void)

{
  x_9bcf();
  clk_gate_enable_3();
  _DAT_0000 = 8;
  return;
}



/* ===== 0x9D4E  sub_9d4e ===== */

void sub_9d4e(byte param_1)

{
  DAT_0000 = param_1;
  sub_9e4f();
  CLK_CKDIVR = CLK_CKDIVR | DAT_0000;
  return;
}



/* ===== 0x9D5C  sub_9d5c ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_9d5c(void)

{
  x_9bcf();
  clk_gate_enable_3();
  _DAT_0000 = 1;
  return;
}



/* ===== 0x9D69  sub_9d69 ===== */

void sub_9d69(byte param_1)

{
  DAT_0000 = (param_1 & 3) << 1;
  DAT_0001 = DAT_0000;
  sub_9cc8(3);
  return;
}



/* ===== 0x9D76  sub_9d76 ===== */

void sub_9d76(char param_1)

{
  if (param_1 != '\0') {
    TIM2_CR1 = TIM2_CR1 | 1;
    return;
  }
  TIM2_CR1 = TIM2_CR1 & 0xfe;
  return;
}



/* ===== 0x9D83  sub_9d83 ===== */

void sub_9d83(char param_1)

{
  if (param_1 != '\0') {
    TIM2_CR1 = TIM2_CR1 | 0x80;
    return;
  }
  TIM2_CR1 = TIM2_CR1 & 0x7f;
  return;
}



/* ===== 0x9D90  sub_9d90 ===== */

void sub_9d90(char param_1)

{
  if (param_1 != '\0') {
    TIM4_CR1 = TIM4_CR1 | 1;
    return;
  }
  TIM4_CR1 = TIM4_CR1 & 0xfe;
  return;
}



/* ===== 0x9D9D  sub_9d9d ===== */

void sub_9d9d(char param_1)

{
  if (param_1 != '\0') {
    UART1_CR1 = UART1_CR1 & 0xdf;
    return;
  }
  UART1_CR1 = UART1_CR1 | 0x20;
  return;
}



/* ===== 0x9DAA  clk_gate_enable_2 ===== */

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



/* ===== 0x9DB7  sub_9db7 ===== */

char sub_9db7(void)

{
  DAT_000a._0_1_ = DAT_000a._0_1_ + '\x01';
  DAT_0008 = DAT_0008 + 1;
  return DAT_000a._0_1_;
}



/* ===== 0x9DC3  sub_9dc3 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * sub_9dc3(void)

{
  _DAT_0000 = 7;
  return &UNK_02c4;
}



/* ===== 0x9DCF  sub_9dcf ===== */

void sub_9dcf(void)

{
  DAT_0002._0_1_ = DAT_02cf;
  DAT_0002._1_1_ = DAT_02ce;
  return;
}



/* ===== 0x9DDA  sub_9dda ===== */

void sub_9dda(byte param_1)

{
  DAT_0000 = param_1;
  DAT_505f = DAT_505f & param_1;
  return;
}



/* ===== 0x9DE5  sub_9de5 ===== */

void sub_9de5(void)

{
  sub_8e51(&UNK_4008 + DAT_000a._0_1_);
  return;
}



/* ===== 0x9DEF  tim4_init ===== */

undefined * tim4_init(void)

{
  DAT_02d1 = 0;
  return &UNK_0277;
}



/* ===== 0x9DF9  sub_9df9 ===== */

char sub_9df9(void)

{
  DAT_02ce = DAT_02ce + '\x01';
  return DAT_02ce;
}



/* ===== 0x9E03  sub_9e03 ===== */

void sub_9e03(void)

{
  sub_9b92(DAT_0008 + 7);
  return;
}



/* ===== 0x9E05  sub_9e05 ===== */

void sub_9e05(void)

{
  sub_9b92(DAT_0008 + 7);
  return;
}



/* ===== 0x9E0D  sub_9e0d ===== */

void sub_9e0d(void)

{
  DAT_0002._1_1_ = DAT_02cf;
  DAT_02cf = DAT_02cf + '\x01';
  return;
}



/* ===== 0x9E17  sub_9e17 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_9e17(short param_1)

{
  _DAT_0000 = param_1 + 0x10;
  DAT_0002._1_1_ = 0xc;
  return;
}



/* ===== 0x9E21  sub_9e21 ===== */

void sub_9e21(undefined1 *param_1)

{
  *param_1 = 1;
  *(undefined2 *)(DAT_0008 + 1) = 0;
  return;
}



/* ===== 0x9E2B  gap_9e2b ===== */

void gap_9e2b(void)

{
  sub_9acf();
  sub_9af3(&UNK_01df);
  return;
}



/* ===== 0x9E34  sub_9e34 ===== */

undefined2 sub_9e34(void)

{
  return *DAT_000c;
}



/* ===== 0x9E3D  sub_9e3d ===== */

short sub_9e3d(undefined1 param_1,undefined1 *param_2)

{
  *param_2 = param_1;
  return DAT_0008 + 5;
}



/* ===== 0x9E40  sub_9e40 ===== */

short sub_9e40(void)

{
  return DAT_0008 + 5;
}



/* ===== 0x9E46  sub_9e46 ===== */

char * sub_9e46(char *param_1)

{
  DAT_0001 = *param_1 + DAT_0001;
  DAT_0000 = DAT_0000 + -1;
  return param_1 + 1;
}



/* ===== 0x9E4F  sub_9e4f ===== */

void sub_9e4f(void)

{
  CLK_CKDIVR = CLK_CKDIVR & 0xe7;
  return;
}



/* ===== 0x9E58  sub_9e58 ===== */

void sub_9e58(void)

{
  ITC_SPR1 = 0;
  ITC_SPR2 = 0;
  return;
}



/* ===== 0x9E61  sub_9e61 ===== */

void sub_9e61(void)

{
  undefined1 in_XH;
  undefined1 in_XL;
  
  TIM2_CCR1H = in_XH;
  TIM2_CCR1L = in_XL;
  return;
}



/* ===== 0x9E6A  sub_9e6a ===== */

void sub_9e6a(void)

{
  undefined1 in_XH;
  undefined1 in_XL;
  
  TIM2_PSCR = in_XH;
  TIM2_ARRH = in_XL;
  return;
}



/* ===== 0x9E73  sub_9e73 ===== */

void sub_9e73(undefined1 param_1)

{
  TIM4_EGR = param_1;
  TIM4_CNTR = DAT_0000;
  return;
}



/* ===== 0x9E7C  sub_9e7c ===== */

undefined1 sub_9e7c(byte param_1)

{
  undefined1 uVar1;
  
  uVar1 = sub_99d4(param_1 & 0xf,1);
  return uVar1;
}



/* ===== 0x9E85  gap_9e85 ===== */

void gap_9e85(void)

{
  return;
}



/* ===== 0x9E8D  sub_9af3 ===== */

void sub_9e8d(void)

{
  return;
}



/* ===== 0x9E95  sub_9e95 ===== */

undefined2 sub_9e95(void)

{
  sub_9cb8(DAT_000c);
  return DAT_0008;
}



/* ===== 0x9E9D  sub_9e9d ===== */

void sub_9e9d(void)

{
  sub_8d31();
  return;
}



/* ===== 0x9EA5  sub_9ea5 ===== */

void sub_9ea5(undefined1 param_1)

{
  *(undefined1 *)(DAT_0008 + 0x24) = param_1;
  return;
}



/* ===== 0x9EAC  clk_gate_enable_3 ===== */

void clk_gate_enable_3(undefined1 param_1)

{
  *(undefined1 *)(DAT_0008 + 6) = param_1;
  return;
}



/* ===== 0x9EB3  sub_9eb3 ===== */

void sub_9eb3(void)

{
  sub_9a84();
  return;
}



/* ===== 0x9EBA  sub_9eba ===== */

void FUN_9eba(byte param_1,byte *param_2)

{
  DAT_0000 = param_1;
  *param_2 = *param_2 | param_1;
  return;
}



/* ===== 0x9EC1  tim2_set_ccr1l ===== */

/* Write TIM2 CCR1 low byte (PWM duty helper). */

byte tim2_set_ccr1l(byte param_1,short param_2)

{
  DAT_0000 = param_1;
  return *(byte *)(param_2 + 1) & param_1;
}



/* ===== 0x9EC8  sub_9ec8 ===== */

void sub_9ec8(void)

{
  return;
}



/* ===== 0x9ECF  tim4_clear_egr ===== */

void tim4_clear_egr(undefined1 param_1)

{
  TIM2_ARRL = param_1;
  sub_9e61();
  return;
}



/* ===== 0x9ED6  sub_9ed6 ===== */

undefined1 sub_9ed6(void)

{
  return DAT_02ce;
}



/* ===== 0x9EDC  sub_9edc ===== */

void sub_9edc(void)

{
  IWDG_KR = 0xaa;
  return;
}



/* ===== 0x9EE1  sub_9ee1 ===== */

void sub_9ee1(void)

{
  IWDG_KR = 0xcc;
  return;
}



/* ===== 0x9EE6  sub_9ee6 ===== */

void sub_9ee6(byte param_1)

{
  TIM2_SR1 = ~param_1;
  return;
}



/* ===== 0x9EEB  sub_9eeb ===== */

void sub_9eeb(byte param_1)

{
  TIM4_IER = ~param_1;
  return;
}



/* ===== 0x9EF0  sub_9ef0 ===== */

void sub_9ef0(byte param_1)

{
  TIM4_IER = ~param_1;
  return;
}



/* ===== 0x9EF5  sub_9ef5 ===== */

void sub_9ef5(undefined2 param_1)

{
  undefined1 extraout_A;
  undefined2 uVar1;
  
  uVar1 = x_9c5b(param_1);
  sub_9e05(extraout_A,uVar1);
  return;
}



/* ===== 0x9EFE  sub_9efe ===== */

void sub_9efe(void)

{
  sub_9e05();
  return;
}



/* ===== 0x9F02  sub_9f02 ===== */

void sub_9f02(void)

{
  sub_9e0d();
  return;
}



/* ===== 0x9F06  sub_9f06 ===== */

void sub_9f06(void)

{
  sub_9d76(0);
  return;
}



/* ===== 0x9F0A  sub_9f0a ===== */

void sub_9f0a(undefined1 param_1)

{
  *DAT_0002 = param_1;
  return;
}



/* ===== 0x9F0E  sub_9f0e ===== */

undefined1 sub_9f0e(void)

{
  return *DAT_0002;
}



/* ===== 0x9F12  sub_9f12 ===== */

void FUN_9f12(byte param_1,byte *param_2)

{
  *param_2 = ~param_1 & *param_2;
  return;
}



/* ===== 0x9F16  sub_9f16 ===== */

void sub_9f16(undefined1 param_1)

{
  IWDG_KR = param_1;
  return;
}



/* ===== 0x9F1A  sub_9f1a ===== */

void sub_9f1a(undefined1 param_1)

{
  IWDG_PR = param_1;
  return;
}



/* ===== 0x9F1E  sub_9f1e ===== */

void sub_9f1e(undefined1 param_1)

{
  IWDG_RLR = param_1;
  return;
}



/* ===== 0x9F22  sub_9f22 ===== */

undefined1 sub_9f22(void)

{
  return UART1_DR;
}



/* ===== 0x9F26  sub_9f26 ===== */

void sub_9f26(undefined1 param_1)

{
  UART1_DR = param_1;
  return;
}



/* ===== 0x9F2A  sub_9f2a ===== */

void thunk_FUN_9f12(byte param_1,byte *param_2)

{
  *param_2 = ~param_1 & *param_2;
  return;
}



/* ===== 0x9F2D  sub_9f2d ===== */

void thunk_FUN_9eba(byte param_1,byte *param_2)

{
  DAT_0000 = param_1;
  *param_2 = *param_2 | param_1;
  return;
}



/* ===== 0x9F30  vec_9f30 ===== */

void thunk_FUN_9f39(void)

{
  do {
    __Nop();
  } while( true );
}



/* ===== 0x9F33  sub_9f33 ===== */

undefined2 sub_9f33(void)

{
  return 1;
}



/* ===== 0x9F36  iwdg_reload ===== */

/* IWDG reload/refresh (writes IWDG_KR). */

void iwdg_reload(undefined2 param_1)

{
  undefined1 extraout_A;
  undefined2 uVar1;
  
  uVar1 = x_9c5b(param_1);
  sub_9e05(extraout_A,uVar1);
  return;
}



/* ===== 0x9F39  FUN_9f39 ===== */

void FUN_9f39(void)

{
  do {
    __Nop();
  } while( true );
}



/* ===== 0x9F3C  vec_9f3c ===== */

undefined2 vec_9f3c(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F3D  iwdg_start ===== */

/* IWDG start: IWDG_KR = 0xCC. */

undefined2 iwdg_start(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F3E  vec_9f3e ===== */

undefined2 vec_9f3e(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F3F  vec_9f3f ===== */

undefined2 vec_9f3f(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F40  vec_9f40 ===== */

undefined2 vec_9f40(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F41  vec_9f41 ===== */

undefined2 vec_9f41(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F42  vec_9f42 ===== */

undefined2 vec_9f42(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F43  vec_9f43 ===== */

undefined2 vec_9f43(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F44  vec_9f44 ===== */

undefined2 vec_9f44(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F45  vec_9f45 ===== */

undefined2 vec_9f45(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F46  vec_9f46 ===== */

undefined2 vec_9f46(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F47  vec_9f47 ===== */

undefined2 vec_9f47(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F48  vec_9f48 ===== */

undefined2 vec_9f48(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F49  vec_9f49 ===== */

undefined2 vec_9f49(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F4A  vec_9f4a ===== */

undefined2 vec_9f4a(undefined2 param_1)

{
  return param_1;
}



/* ===== 0x9F4B  sub_9f4b ===== */

void sub_9f4b(void)

{
  return;
}



/* ===== 0x9F4C  gap_9f4c ===== */

/* WARNING: Control flow encountered bad instruction data */

void gap_9f4c(undefined2 *param_1)

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



/* ===== 0x9F5D  gap_9f5d ===== */

/* WARNING: Control flow encountered bad instruction data */

void gap_9f5d(undefined2 *param_1)

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



/* ===== 0x9F6E  ret_9f6e ===== */

/* WARNING: Control flow encountered bad instruction data */

void gap_9f6e(undefined2 *param_1)

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



/* ===== 0x9F7F  gap_9f7f ===== */

/* WARNING: Control flow encountered bad instruction data */

void gap_9f7f(undefined2 *param_1)

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



/* ===== 0x9F90  gap_9f90 ===== */

/* WARNING: Control flow encountered bad instruction data */

void gap_9f90(undefined2 *param_1)

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



