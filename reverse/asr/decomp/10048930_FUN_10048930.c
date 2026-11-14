// FUNC 0x10048930  FUN_10048930

uint FUN_10048930(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar4 = param_1 & 0x7fffff;
  uVar5 = (param_1 << 1) >> 0x18;
  if (uVar5 == 0) {
    if (uVar4 == 0) {
      uVar7 = 4;
    }
    else {
      iVar6 = FUN_10056d78(uVar4);
      uVar4 = uVar4 << (iVar6 - 5U & 0xff);
      uVar5 = -(iVar6 + 0x76);
      uVar7 = 0;
    }
  }
  else if (uVar5 == 0xff) {
    if (uVar4 == 0) {
      uVar7 = 8;
    }
    else {
      uVar7 = 0xc;
    }
  }
  else {
    uVar7 = 0;
    uVar4 = uVar4 << 3 | 0x4000000;
    uVar5 = uVar5 - 0x7f;
  }
  uVar3 = param_2 & 0x7fffff;
  uVar2 = (param_2 << 1) >> 0x18;
  if (uVar2 == 0) {
    uVar1 = 1;
    if (uVar3 != 0) {
      iVar6 = FUN_10056d78(uVar3);
      uVar3 = uVar3 << (iVar6 - 5U & 0xff);
      uVar2 = -(iVar6 + 0x76);
      uVar1 = 0;
    }
  }
  else if (uVar2 == 0xff) {
    uVar1 = 3 - (uVar3 == 0);
  }
  else {
    uVar1 = 0;
    uVar3 = uVar3 << 3 | 0x4000000;
    uVar2 = uVar2 - 0x7f;
  }
  if ((uVar7 | uVar1) < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x10048998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar5 = (**(code **)(DAT_10048b50 + (uVar7 | uVar1) * 4))();
    return uVar5;
  }
  uVar1 = (uVar4 >> 0x10) * (uVar3 & 0xffff);
  uVar7 = (uVar4 & 0xffff) * (uVar3 & 0xffff);
  iVar6 = (uVar3 >> 0x10) * (uVar4 >> 0x10);
  uVar4 = (uVar7 >> 0x10) + (uVar4 & 0xffff) * (uVar3 >> 0x10) + uVar1;
  if (uVar4 <= uVar1 && uVar1 - uVar4 != 0) {
    iVar6 = iVar6 + 0x10000;
  }
  uVar3 = uVar4 * 0x10000 + (uVar7 & 0xffff);
  uVar7 = (uint)((uVar3 & 0x3ffffff) != 0);
  uVar3 = uVar3 >> 0x1a;
  uVar4 = ((uVar4 >> 0x10) + iVar6) * 0x40 | uVar3 | uVar7;
  iVar6 = uVar5 + uVar2;
  if ((int)(uVar4 << 4) < 0) {
    uVar4 = uVar3 & 1 | uVar7 | uVar4 >> 1;
    iVar6 = uVar5 + uVar2 + 1;
  }
  uVar5 = iVar6 + 0x7f;
  if ((int)uVar5 < 1) {
    uVar5 = 1 - uVar5;
    if ((int)uVar5 < 0x1c) {
      uVar7 = uVar4 >> (uVar5 & 0xff);
      uVar5 = (uint)(uVar4 << (0x20 - uVar5 & 0xff) != 0);
      uVar4 = uVar7 | uVar5;
      if (((uVar7 & 7) != 0 || uVar5 != 0) && ((uVar7 & 0xf | uVar5) != 4)) {
        uVar4 = uVar4 + 4;
      }
      if ((int)(uVar4 << 5) < 0) {
        uVar5 = 1;
        uVar4 = 0;
      }
      else {
        uVar4 = (uVar4 << 6) >> 9;
        uVar5 = 0;
      }
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
    }
  }
  else {
    if (((uVar4 & 7) != 0) && ((uVar4 & 0xf) != 4)) {
      uVar4 = uVar4 + 4;
    }
    if ((int)(uVar4 << 4) < 0) {
      uVar5 = iVar6 + 0x80;
      uVar4 = uVar4 & DAT_10048b54;
    }
    if ((int)uVar5 < 0xff) {
      uVar4 = (uVar4 << 6) >> 9;
      uVar5 = uVar5 & 0xff;
    }
    else {
      uVar5 = 0xff;
      uVar4 = 0;
    }
  }
  return uVar4 | uVar5 << 0x17 | (param_2 ^ param_1) & 0x80000000;
}


