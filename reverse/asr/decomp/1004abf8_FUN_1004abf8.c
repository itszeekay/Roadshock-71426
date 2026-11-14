// FUNC 0x1004abf8  FUN_1004abf8

uint FUN_1004abf8(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = (param_2 << 1) >> 0x15;
  uVar3 = param_1 >> 0x1d | (param_2 << 0xc) >> 9;
  uVar6 = param_1 << 3;
  if ((uVar7 + 1 & 0x7ff) < 2) {
    if (uVar7 == 0) {
      uVar3 = uVar3 | uVar6;
      uVar5 = 0;
      if (uVar3 != 0) {
LAB_1004ac86:
        uVar5 = 0;
        uVar3 = 0;
        goto LAB_1004ac88;
      }
LAB_1004ac8e:
      uVar3 = uVar3 & 0x7fffff;
      uVar5 = uVar5 & 0xff;
      goto LAB_1004ac56;
    }
    if (uVar6 != 0 || uVar3 != 0) {
      uVar3 = uVar3 << 3 | 0x2000000;
      uVar5 = 0xff;
      goto LAB_1004ac2e;
    }
  }
  else {
    uVar5 = uVar7 + DAT_1004ad04;
    if ((int)uVar5 < 0xff) {
      if ((int)uVar5 < 1) {
        if ((int)(uVar5 + 0x17) < 0 != SCARRY4(uVar5,0x17)) goto LAB_1004ac86;
        uVar3 = uVar3 | 0x800000;
        uVar2 = 0x1e - uVar5;
        if ((int)uVar2 < 0x20) {
          uVar3 = uVar6 >> (uVar2 & 0xff) |
                  (uint)(uVar6 << (uVar7 + DAT_1004ad08 & 0xff) != 0) |
                  uVar3 << (uVar7 + DAT_1004ad08 & 0xff);
          uVar5 = 0;
        }
        else {
          iVar1 = -uVar5;
          if (uVar2 == 0x20) {
            iVar4 = 0;
          }
          else {
            iVar4 = uVar3 << (uVar7 + DAT_1004ad0c & 0xff);
          }
          uVar5 = 0;
          uVar3 = (uint)(uVar6 != 0 || iVar4 != 0) | uVar3 >> (iVar1 - 2U & 0xff);
        }
      }
      else {
        uVar3 = uVar6 >> 0x1d | (uint)((param_1 & 0x3ffffff) != 0) | uVar3 << 3;
      }
LAB_1004ac2e:
      if (((uVar3 & 7) != 0) && ((uVar3 & 0xf) != 4)) {
        uVar3 = uVar3 + 4;
      }
      if ((uVar3 & 0x4000000) == 0) {
LAB_1004ac88:
        uVar3 = uVar3 >> 3;
        if (uVar5 == 0xff) {
          uVar5 = 0xff;
          if (uVar3 == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = uVar3 & 0x7fffff | 0x400000;
          }
          goto LAB_1004ac56;
        }
        goto LAB_1004ac8e;
      }
      if (uVar5 + 1 != 0xff) {
        uVar3 = (uVar3 << 6) >> 9;
        uVar5 = uVar5 + 1 & 0xff;
        goto LAB_1004ac56;
      }
    }
  }
  uVar5 = 0xff;
  uVar3 = 0;
LAB_1004ac56:
  return uVar5 << 0x17 | uVar3 | param_2 & 0x80000000;
}


