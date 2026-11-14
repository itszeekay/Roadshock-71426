// FUNC 0x1004960c  FUN_1004960c

undefined8 FUN_1004960c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  int local_3c;
  uint local_38;
  uint local_34;
  
  uVar12 = param_2 & 0xfffff;
  uVar10 = (param_2 << 1) >> 0x15;
  if (uVar10 == 0) {
    if (uVar12 == 0 && param_1 == 0) {
      uVar5 = 0;
      uVar13 = 4;
      uVar12 = 0;
    }
    else {
      if (uVar12 == 0) {
        iVar4 = FUN_10056d78();
        iVar4 = iVar4 + 0x20;
      }
      else {
        iVar4 = FUN_10056d78(uVar12);
      }
      if (iVar4 + -0xb < 0x1d) {
        uVar5 = param_1 << (iVar4 - 8U & 0xff);
        uVar12 = uVar12 << (iVar4 - 8U & 0xff) | param_1 >> (0x1dU - (iVar4 + -0xb) & 0xff);
      }
      else {
        uVar12 = param_1 << (iVar4 - 0x28U & 0xff);
        uVar5 = 0;
      }
      uVar13 = 0;
      uVar10 = -(iVar4 + DAT_100497f8);
    }
  }
  else if (uVar10 == DAT_100497e8) {
    if (param_1 == 0 && uVar12 == 0) {
      uVar5 = 0;
      uVar13 = 8;
      uVar12 = 0;
    }
    else {
      uVar13 = 0xc;
      uVar5 = param_1;
    }
  }
  else {
    uVar12 = uVar12 << 3 | param_1 >> 0x1d | 0x800000;
    uVar13 = 0;
    uVar10 = uVar10 + DAT_100497ec;
    uVar5 = param_1 << 3;
  }
  uVar6 = param_4 & 0xfffff;
  uVar1 = (param_4 << 1) >> 0x15;
  if (uVar1 == 0) {
    if (uVar6 == 0 && param_3 == 0) {
      uVar6 = 0;
      param_3 = 0;
      uVar7 = 1;
    }
    else {
      if (uVar6 == 0) {
        iVar4 = FUN_10056d78(param_3);
        iVar4 = iVar4 + 0x20;
      }
      else {
        iVar4 = FUN_10056d78(uVar6);
      }
      if (iVar4 + -0xb < 0x1d) {
        uVar6 = param_3 >> (0x1dU - (iVar4 + -0xb) & 0xff) | uVar6 << (iVar4 - 8U & 0xff);
        param_3 = param_3 << (iVar4 - 8U & 0xff);
      }
      else {
        uVar6 = param_3 << (iVar4 - 0x28U & 0xff);
        param_3 = 0;
      }
      uVar1 = -(iVar4 + DAT_100497f8);
      uVar7 = 0;
    }
  }
  else if (uVar1 == DAT_100497e8) {
    if (param_3 == 0 && uVar6 == 0) {
      param_3 = 0;
      uVar6 = 0;
      uVar7 = 2;
    }
    else {
      uVar7 = 3;
    }
  }
  else {
    uVar6 = param_3 >> 0x1d | 0x800000 | uVar6 << 3;
    param_3 = param_3 << 3;
    uVar7 = 0;
    uVar1 = uVar1 + DAT_100497ec;
  }
  local_3c = uVar10 - uVar1;
  if ((uVar13 | uVar7) < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x100496a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar14 = (**(code **)(DAT_100497f0 + (uVar13 | uVar7) * 4))();
    return uVar14;
  }
  if ((uVar6 < uVar12) || ((uVar12 == uVar6 && (param_3 <= uVar5)))) {
    uVar10 = uVar12 << 0x1f;
    local_38 = uVar5 << 0x1f;
    uVar12 = uVar12 >> 1;
    uVar5 = uVar10 | uVar5 >> 1;
  }
  else {
    local_3c = local_3c + -1;
    local_38 = 0;
  }
  uVar6 = uVar6 << 8;
  uVar7 = uVar6 | param_3 >> 0x18;
  uVar10 = param_3 * 0x100;
  uVar13 = uVar6 >> 0x10;
  uVar6 = uVar6 & 0xffff | param_3 >> 0x18;
  iVar2 = FUN_10056d58(uVar12,uVar13);
  uVar1 = iVar2 * uVar6;
  FUN_10056d68(uVar12,uVar13);
  uVar12 = uVar5 >> 0x10 | extraout_r1 << 0x10;
  iVar4 = iVar2;
  if (uVar12 <= uVar1 && uVar1 - uVar12 != 0) {
    uVar12 = uVar12 + uVar7;
    iVar4 = iVar2 + -1;
    if ((uVar7 <= uVar12) && (uVar12 <= uVar1 && uVar1 - uVar12 != 0)) {
      iVar4 = iVar2 + -2;
      uVar12 = uVar12 + uVar7;
    }
  }
  uVar3 = FUN_10056d58(uVar12 - uVar1,uVar13);
  uVar8 = uVar6 * uVar3;
  FUN_10056d68(uVar12 - uVar1,uVar13);
  uVar5 = uVar5 & 0xffff | extraout_r1_00 << 0x10;
  uVar12 = uVar3;
  if (uVar5 <= uVar8 && uVar8 - uVar5 != 0) {
    uVar5 = uVar5 + uVar7;
    uVar12 = uVar3 - 1;
    if ((uVar7 <= uVar5) && (uVar5 <= uVar8 && uVar8 - uVar5 != 0)) {
      uVar5 = uVar5 + uVar7;
      uVar12 = uVar3 - 2;
    }
  }
  uVar5 = uVar5 - uVar8;
  uVar1 = uVar12 | iVar4 << 0x10;
  uVar9 = uVar10 >> 0x10;
  uVar3 = uVar10 & 0xffff;
  uVar11 = (uVar1 >> 0x10) * uVar3;
  uVar8 = (uVar12 & 0xffff) * uVar3;
  iVar4 = uVar9 * (uVar1 >> 0x10);
  uVar12 = (uVar8 >> 0x10) + uVar9 * (uVar12 & 0xffff) + uVar11;
  if (uVar12 <= uVar11 && uVar11 - uVar12 != 0) {
    iVar4 = iVar4 + 0x10000;
  }
  uVar11 = (uVar12 >> 0x10) + iVar4;
  uVar12 = uVar12 * 0x10000 + (uVar8 & 0xffff);
  if (uVar5 < uVar11) {
LAB_10049ab6:
    local_38 = local_38 + uVar10;
    uVar5 = (local_38 < uVar10) + uVar7 + uVar5;
    uVar8 = uVar1 - 1;
    if (uVar7 < uVar5) {
LAB_10049ad4:
      if (uVar11 <= uVar5) {
        if (uVar11 != uVar5) goto LAB_10049adc;
        if (uVar12 <= local_38) {
          iVar4 = 0;
          uVar1 = uVar8;
          goto LAB_100498fe;
        }
      }
      uVar1 = uVar1 - 2;
      local_38 = local_38 + uVar10;
      uVar5 = (local_38 < uVar10) + uVar7 + uVar5;
LAB_100498fc:
      iVar4 = uVar5 - uVar11;
    }
    else {
      if (uVar7 == uVar5) {
        if (local_38 < uVar10) {
          iVar4 = uVar7 - uVar11;
          uVar1 = uVar8;
          goto LAB_100498fe;
        }
        goto LAB_10049ad4;
      }
LAB_10049adc:
      iVar4 = uVar5 - uVar11;
      uVar1 = uVar8;
    }
  }
  else {
    if (uVar5 != uVar11) goto LAB_100498fc;
    iVar4 = 0;
    if (local_38 < uVar12) goto LAB_10049ab6;
  }
LAB_100498fe:
  uVar12 = local_38 - uVar12;
  uVar5 = iVar4 - (uint)(local_38 < uVar12);
  if (uVar7 == uVar5) {
    uVar13 = 0xffffffff;
  }
  else {
    iVar2 = FUN_10056d58(uVar5,uVar13);
    uVar8 = iVar2 * uVar6;
    FUN_10056d68(uVar5,uVar13);
    uVar5 = uVar12 >> 0x10 | extraout_r1_01 << 0x10;
    iVar4 = iVar2;
    if (uVar5 <= uVar8 && uVar8 - uVar5 != 0) {
      uVar5 = uVar5 + uVar7;
      iVar4 = iVar2 + -1;
      if ((uVar7 <= uVar5) && (uVar5 <= uVar8 && uVar8 - uVar5 != 0)) {
        iVar4 = iVar2 + -2;
        uVar5 = uVar5 + uVar7;
      }
    }
    uVar11 = FUN_10056d58(uVar5 - uVar8,uVar13);
    uVar6 = uVar11 * uVar6;
    FUN_10056d68(uVar5 - uVar8,uVar13);
    uVar5 = uVar12 & 0xffff | extraout_r1_02 << 0x10;
    uVar12 = uVar11;
    if (uVar5 <= uVar6 && uVar6 - uVar5 != 0) {
      uVar5 = uVar5 + uVar7;
      uVar12 = uVar11 - 1;
      if ((uVar7 <= uVar5) && (uVar5 <= uVar6 && uVar6 - uVar5 != 0)) {
        uVar12 = uVar11 - 2;
        uVar5 = uVar5 + uVar7;
      }
    }
    uVar8 = iVar4 << 0x10 | uVar12;
    uVar5 = uVar5 - uVar6;
    uVar13 = (uVar12 & 0xffff) * uVar3;
    uVar3 = (uVar8 >> 0x10) * uVar3;
    iVar4 = uVar9 * (uVar8 >> 0x10);
    uVar12 = (uVar13 >> 0x10) + uVar9 * (uVar12 & 0xffff) + uVar3;
    if (uVar12 <= uVar3 && uVar3 - uVar12 != 0) {
      iVar4 = iVar4 + 0x10000;
    }
    uVar6 = (uVar12 >> 0x10) + iVar4;
    uVar12 = uVar12 * 0x10000 + (uVar13 & 0xffff);
    if (uVar5 < uVar6) {
LAB_10049a68:
      uVar5 = uVar7 + uVar5;
      uVar13 = uVar8 - 1;
      local_34 = uVar10;
      if (uVar5 < uVar7) {
LAB_10049a70:
        if (uVar5 != uVar6) goto LAB_100499c8;
      }
      else {
        if (uVar5 < uVar6) {
LAB_10049b98:
          uVar13 = uVar8 - 2;
          local_34 = param_3 << 9;
          uVar5 = uVar5 + (local_34 < uVar10) + uVar7;
          goto LAB_10049a70;
        }
        if (uVar6 != uVar5) goto LAB_100499c8;
        if (uVar10 < uVar12) goto LAB_10049b98;
      }
      if (local_34 == uVar12) goto LAB_100499cc;
    }
    else {
      uVar13 = uVar8;
      if (uVar5 == uVar6) {
        if (uVar12 == 0) goto LAB_100499cc;
        goto LAB_10049a68;
      }
    }
LAB_100499c8:
    uVar13 = uVar13 | 1;
  }
LAB_100499cc:
  uVar10 = local_3c + DAT_10049c28;
  if (0 < (int)uVar10) {
    uVar12 = uVar13;
    if (((uVar13 & 7) != 0) && ((uVar13 & 0xf) != 4)) {
      uVar12 = uVar13 + 4;
      uVar1 = uVar1 + (uVar12 < uVar13);
    }
    if ((int)(uVar1 << 7) < 0) {
      uVar1 = uVar1 & DAT_10049c2c;
      uVar10 = local_3c + 0x400;
    }
    if (DAT_10049c30 < (int)uVar10) {
      uVar5 = 0;
      uVar12 = 0;
      uVar10 = DAT_100497e8;
    }
    else {
      uVar12 = uVar1 << 0x1d | uVar12 >> 3;
      uVar5 = (uVar1 << 9) >> 0xc;
      uVar10 = uVar10 & 0x7ff;
    }
    goto LAB_100496d8;
  }
  uVar12 = 1 - uVar10;
  if (0x38 < (int)uVar12) {
    uVar5 = 0;
    uVar12 = 0;
    uVar10 = 0;
    goto LAB_100496d8;
  }
  if ((int)uVar12 < 0x20) {
    uVar5 = uVar13 >> (uVar12 & 0xff) | uVar1 << (0x20 - uVar12 & 0xff);
    uVar10 = (uint)(uVar13 << (0x20 - uVar12 & 0xff) != 0);
    uVar6 = uVar10 | uVar5;
    uVar1 = uVar1 >> (uVar12 & 0xff);
    if ((uVar10 != 0 || (uVar5 & 7) != 0) && (uVar12 = uVar6, (uVar10 | uVar5 & 0xf) != 4)) {
LAB_10049b5a:
      uVar6 = uVar12 + 4;
      uVar1 = uVar1 + (uVar6 < uVar12);
    }
    if ((int)(uVar1 << 8) < 0) {
      uVar12 = 0;
      uVar5 = 0;
      uVar10 = 1;
      goto LAB_100496d8;
    }
LAB_10049be2:
    uVar12 = uVar1 << 0x1d;
    uVar5 = (uVar1 << 9) >> 0xc;
  }
  else {
    uVar10 = uVar1 >> (-uVar10 - 0x1f & 0xff);
    if (uVar12 == 0x20) {
      iVar4 = 0;
    }
    else {
      iVar4 = uVar1 << (0x40 - uVar12 & 0xff);
    }
    uVar13 = (uint)(uVar13 != 0 || iVar4 != 0);
    uVar6 = uVar10 | uVar13;
    uVar12 = uVar10 & 7 | uVar13;
    uVar5 = 0;
    if (uVar12 != 0) {
      uVar1 = 0;
      uVar12 = uVar6;
      if ((uVar10 & 0xf | uVar13) != 4) goto LAB_10049b5a;
      goto LAB_10049be2;
    }
  }
  uVar12 = uVar6 >> 3 | uVar12;
  uVar10 = 0;
LAB_100496d8:
  return CONCAT44(uVar5 & DAT_100497f4 | (uVar10 & 0x7ff) << 0x14 | (param_2 ^ param_4) & 0x80000000
                  ,uVar12);
}


