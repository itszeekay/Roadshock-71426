// FUNC 0x10049e54  FUN_10049e54

undefined8 FUN_10049e54(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined8 uVar16;
  int local_34;
  
  uVar7 = param_2 & 0xfffff;
  uVar12 = (param_2 << 1) >> 0x15;
  if (uVar12 == 0) {
    if (uVar7 == 0 && param_1 == 0) {
      uVar7 = 0;
      param_1 = 0;
      uVar13 = 4;
    }
    else {
      if (uVar7 == 0) {
        iVar2 = FUN_10056d78();
        iVar2 = iVar2 + 0x20;
      }
      else {
        iVar2 = FUN_10056d78(uVar7);
      }
      if (iVar2 + -0xb < 0x1d) {
        uVar12 = param_1 >> (0x1dU - (iVar2 + -0xb) & 0xff);
        param_1 = param_1 << (iVar2 - 8U & 0xff);
        uVar7 = uVar12 | uVar7 << (iVar2 - 8U & 0xff);
      }
      else {
        uVar7 = param_1 << (iVar2 - 0x28U & 0xff);
        param_1 = 0;
      }
      uVar13 = 0;
      uVar12 = -(iVar2 + DAT_1004a040);
    }
  }
  else if (uVar12 == DAT_1004a030) {
    if (param_1 == 0 && uVar7 == 0) {
      uVar7 = 0;
      param_1 = 0;
      uVar13 = 8;
    }
    else {
      uVar13 = 0xc;
    }
  }
  else {
    uVar7 = param_1 >> 0x1d | 0x800000 | uVar7 << 3;
    param_1 = param_1 << 3;
    uVar13 = 0;
    uVar12 = uVar12 + DAT_1004a034;
  }
  uVar10 = param_4 & 0xfffff;
  uVar1 = (param_4 << 1) >> 0x15;
  if (uVar1 == 0) {
    if (param_3 == 0 && uVar10 == 0) {
      uVar10 = 0;
      param_3 = 0;
      uVar3 = 1;
    }
    else {
      if (uVar10 == 0) {
        iVar2 = FUN_10056d78(param_3);
        iVar2 = iVar2 + 0x20;
      }
      else {
        iVar2 = FUN_10056d78(uVar10);
      }
      if (iVar2 + -0xb < 0x1d) {
        uVar1 = param_3 >> (0x1dU - (iVar2 + -0xb) & 0xff);
        param_3 = param_3 << (iVar2 - 8U & 0xff);
        uVar10 = uVar10 << (iVar2 - 8U & 0xff) | uVar1;
      }
      else {
        uVar10 = param_3 << (iVar2 - 0x28U & 0xff);
        param_3 = 0;
      }
      uVar1 = -(iVar2 + DAT_1004a040);
      uVar3 = 0;
    }
  }
  else if (uVar1 == DAT_1004a030) {
    if (param_3 == 0 && uVar10 == 0) {
      uVar10 = 0;
      param_3 = 0;
      uVar3 = 2;
    }
    else {
      uVar3 = 3;
    }
  }
  else {
    uVar10 = uVar10 << 3 | param_3 >> 0x1d | 0x800000;
    uVar3 = 0;
    param_3 = param_3 << 3;
    uVar1 = uVar1 + DAT_1004a034;
  }
  if ((uVar13 | uVar3) < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x10049eea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar16 = (**(code **)(DAT_1004a038 + (uVar13 | uVar3) * 4))();
    return uVar16;
  }
  uVar13 = param_1 >> 0x10;
  uVar3 = param_3 >> 0x10;
  param_3 = param_3 & 0xffff;
  uVar4 = param_3 * uVar13;
  local_34 = uVar3 * uVar13;
  param_1 = param_1 & 0xffff;
  uVar5 = param_1 * uVar3 + uVar4 + (param_1 * param_3 >> 0x10);
  if (uVar5 <= uVar4 && uVar4 - uVar5 != 0) {
    local_34 = local_34 + 0x10000;
  }
  uVar6 = uVar10 >> 0x10;
  uVar10 = uVar10 & 0xffff;
  uVar4 = uVar10 * uVar13;
  iVar2 = uVar6 * uVar13;
  uVar13 = uVar6 * param_1 + uVar4 + (param_1 * uVar10 >> 0x10);
  if (uVar13 <= uVar4 && uVar4 - uVar13 != 0) {
    iVar2 = iVar2 + 0x10000;
  }
  uVar4 = (uVar13 >> 0x10) + iVar2;
  uVar14 = uVar13 * 0x10000 + (param_1 * uVar10 & 0xffff);
  uVar13 = uVar7 >> 0x10;
  uVar7 = uVar7 & 0xffff;
  uVar8 = uVar13 * param_3;
  iVar2 = uVar13 * uVar3;
  uVar3 = uVar7 * uVar3 + uVar8 + (param_3 * uVar7 >> 0x10);
  if (uVar3 <= uVar8 && uVar8 - uVar3 != 0) {
    iVar2 = iVar2 + 0x10000;
  }
  uVar9 = uVar3 * 0x10000 + (param_3 * uVar7 & 0xffff);
  uVar8 = uVar10 * uVar13;
  iVar11 = uVar6 * uVar13;
  uVar13 = uVar7 * uVar6 + uVar8 + (uVar10 * uVar7 >> 0x10);
  uVar3 = (uVar3 >> 0x10) + iVar2;
  if (uVar13 <= uVar8 && uVar8 - uVar13 != 0) {
    iVar11 = iVar11 + 0x10000;
  }
  uVar15 = local_34 + (uVar5 >> 0x10) + uVar14;
  uVar6 = (uint)(uVar15 < uVar14);
  uVar10 = (uVar10 * uVar7 & 0xffff) + uVar13 * 0x10000 + uVar4;
  uVar15 = uVar15 + uVar9;
  uVar7 = (uint)(uVar15 < uVar9);
  uVar9 = uVar10 + uVar6;
  uVar14 = uVar3 + uVar9;
  uVar8 = uVar7 + uVar14;
  uVar10 = ((uint)(uVar10 < uVar4 || uVar9 < uVar6) + (uVar13 >> 0x10) +
            (uint)(uVar14 < uVar3 || uVar8 < uVar7) + iVar11) * 0x200 | uVar8 >> 0x17;
  uVar7 = (uint)((uVar15 & 0x7fffff) != 0 || uVar5 * 0x10000 + (param_1 * param_3 & 0xffff) != 0);
  uVar13 = uVar8 * 0x200 | uVar7 | uVar15 >> 0x17;
  iVar2 = uVar12 + uVar1;
  if ((int)(uVar10 << 7) < 0) {
    uVar13 = uVar7 | uVar15 >> 0x17 & 1 | uVar13 >> 1 | (uVar8 >> 0x17) << 0x1f;
    uVar10 = uVar10 >> 1;
    iVar2 = uVar12 + uVar1 + 1;
  }
  uVar12 = iVar2 + DAT_1004a338;
  if (0 < (int)uVar12) {
    uVar7 = uVar13;
    if (((uVar13 & 7) != 0) && ((uVar13 & 0xf) != 4)) {
      uVar7 = uVar13 + 4;
      uVar10 = uVar10 + (uVar7 < uVar13);
    }
    if ((int)(uVar10 << 7) < 0) {
      uVar10 = uVar10 & DAT_1004a33c;
      uVar12 = iVar2 + 0x400;
    }
    if (DAT_1004a340 < (int)uVar12) {
      uVar7 = 0;
      uVar13 = 0;
      uVar12 = DAT_1004a030;
    }
    else {
      uVar7 = uVar10 << 0x1d | uVar7 >> 3;
      uVar13 = (uVar10 << 9) >> 0xc;
      uVar12 = uVar12 & 0x7ff;
    }
    goto LAB_10049f20;
  }
  uVar7 = 1 - uVar12;
  if (0x38 < (int)uVar7) {
    uVar12 = 0;
    uVar13 = 0;
    uVar7 = 0;
    goto LAB_10049f20;
  }
  if ((int)uVar7 < 0x20) {
    uVar1 = uVar10 << (0x20 - uVar7 & 0xff) | uVar13 >> (uVar7 & 0xff);
    uVar12 = (uint)(uVar13 << (0x20 - uVar7 & 0xff) != 0);
    uVar3 = uVar1 | uVar12;
    uVar10 = uVar10 >> (uVar7 & 0xff);
    if (((uVar1 & 7) != 0 || uVar12 != 0) && ((uVar1 & 0xf | uVar12) != 4)) {
LAB_1004a2ba:
      uVar10 = uVar10 + (uVar3 + 4 < uVar3);
      uVar3 = uVar3 + 4;
    }
    if ((int)(uVar10 << 8) < 0) {
      uVar12 = 1;
      uVar13 = 0;
      uVar7 = 0;
      goto LAB_10049f20;
    }
LAB_1004a308:
    uVar7 = uVar10 << 0x1d;
    uVar13 = (uVar10 << 9) >> 0xc;
  }
  else {
    uVar12 = uVar10 >> (-uVar12 - 0x1f & 0xff);
    if (uVar7 == 0x20) {
      iVar2 = 0;
    }
    else {
      iVar2 = uVar10 << (0x40 - uVar7 & 0xff);
    }
    uVar1 = (uint)(uVar13 != 0 || iVar2 != 0);
    uVar3 = uVar1 | uVar12;
    uVar7 = uVar1 | uVar12 & 7;
    uVar13 = 0;
    if (uVar7 != 0) {
      uVar10 = 0;
      if ((uVar1 | uVar12 & 0xf) != 4) goto LAB_1004a2ba;
      goto LAB_1004a308;
    }
  }
  uVar7 = uVar3 >> 3 | uVar7;
  uVar12 = 0;
LAB_10049f20:
  return CONCAT44(uVar13 & DAT_1004a03c | (uVar12 & 0x7ff) << 0x14 |
                  (param_4 ^ param_2) & 0x80000000,uVar7);
}


