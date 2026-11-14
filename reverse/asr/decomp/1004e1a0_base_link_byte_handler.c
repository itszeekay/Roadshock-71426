// FUNC 0x1004e1a0  base_link_byte_handler

undefined4 base_link_byte_handler(int param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte *pbVar4;
  byte *pbVar5;
  ushort *puVar6;
  undefined4 uVar7;
  uint uVar8;
  
  if (param_1 == 0x28) {
    log_printf(DAT_1004e2ac);
    pbVar5 = DAT_1004e2b4;
    pbVar4 = DAT_1004e2b0;
    bVar1 = *DAT_1004e2b0;
    bVar2 = *DAT_1004e2b4;
    uVar8 = (uint)bVar2;
    *(byte *)(DAT_1004e2b8 + uVar8) = bVar1;
    *pbVar4 = 0;
    puVar6 = DAT_1004e2bc;
    *DAT_1004e2bc = (ushort)bVar1;
    *(uint *)(puVar6 + 2) = uVar8 * 0x20 + DAT_1004e2c0;
    *(undefined4 *)(puVar6 + 4) = DAT_1004e2c4;
    if (uVar8 == 1) {
      *pbVar5 = 0;
    }
    else {
      *pbVar5 = bVar2 + 1;
    }
    FUN_100538e8(0xb);
    return 0;
  }
  if (param_1 == 0x29) {
    FUN_1004f7e0(0);
    uVar7 = 0x4b;
  }
  else if (param_1 == 0x2d) {
    FUN_1005147c(0);
    if (*DAT_1004e2c8 == '\0') {
      return 0;
    }
    uVar7 = 100;
  }
  else if (param_1 == 0x30) {
    FUN_100512ec(0);
    uVar7 = 0x28;
  }
  else {
    if (param_1 == 0x2a) {
      FUN_10051b7c(0);
      return 0;
    }
    if (param_1 == 0x2f) {
      FUN_10050488(0);
      uVar7 = 0x21;
      cVar3 = *DAT_1004e2cc;
    }
    else {
      if (param_1 == 0x2e) {
        FUN_10050448(0);
        return 0;
      }
      if (param_1 != 0x2b) {
        if (param_1 == 0x31) {
          FUN_10051654(0);
          return 0;
        }
        if (param_1 == 0x32) {
          FUN_1005032c(0);
          return 0;
        }
        if (param_1 == 0x33) {
          FUN_100502ec();
          return 0;
        }
        if (param_1 == 0x34) {
          FUN_1004fe88();
          return 0;
        }
        if (param_1 == 0x35) {
          FUN_1004fe40();
          return 0;
        }
        if (param_1 == 0x36) {
          FUN_1004fdf8();
          return 0;
        }
        if (param_1 != 0x37) {
          return 0;
        }
        FUN_1004f7bc();
        return 0;
      }
      FUN_10051b04(0);
      uVar7 = 200;
      cVar3 = *DAT_1004e2d0;
    }
    if (cVar3 == '\0') {
      return 0;
    }
  }
  FUN_10053918(param_1,uVar7);
  return 0;
}


