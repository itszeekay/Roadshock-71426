// FUNC 0x10048b58  FUN_10048b58

uint FUN_10048b58(uint param_1,uint param_2)

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
  
  uVar6 = (param_1 << 1) >> 0x18;
  uVar7 = -((int)param_1 >> 0x1f);
  uVar5 = (param_1 << 9) >> 6;
  uVar8 = (param_2 << 1) >> 0x18;
  uVar3 = param_2 >> 0x1f;
  uVar4 = (param_2 << 9) >> 6;
  if ((uVar8 != 0xff) || (uVar4 == 0)) {
    uVar3 = uVar3 ^ 1;
  }
  uVar1 = uVar6 - uVar8;
  uVar9 = uVar5;
  if (uVar3 == uVar7) {
    if ((int)uVar1 < 1) {
      if (uVar1 != 0) {
        if (uVar6 == 0) {
          uVar9 = uVar4;
          uVar6 = uVar8;
          if (uVar5 == 0) goto LAB_10048b8e;
          uVar1 = ~uVar1;
          if (uVar1 == 0) goto LAB_10048daa;
          if (uVar8 != 0xff) goto LAB_10048d96;
        }
        else if (uVar8 != 0xff) {
          uVar1 = -uVar1;
          uVar5 = uVar5 | 0x4000000;
LAB_10048d96:
          if ((int)uVar1 < 0x1c) {
            uVar5 = (uint)(uVar5 << (0x20 - uVar1 & 0xff) != 0) | uVar5 >> (uVar1 & 0xff);
          }
          else {
            uVar5 = 1;
          }
LAB_10048daa:
          uVar9 = uVar5 + uVar4;
          goto LAB_10048c62;
        }
LAB_10048e36:
        uVar9 = uVar4;
        uVar6 = 0xff;
        goto LAB_10048b8e;
      }
      uVar1 = uVar6 + 1;
      if ((uVar1 & 0xff) < 2) {
        if (uVar6 == 0) {
          uVar9 = uVar4;
          if ((uVar5 != 0) && (uVar9 = uVar5, uVar4 != 0)) {
            uVar9 = uVar5 + uVar4;
            uVar8 = uVar6;
            uVar3 = uVar7;
            if (-1 < (int)(uVar9 * 0x20)) goto LAB_10048c14;
            uVar9 = uVar9 & DAT_10048e60;
            uVar6 = uVar1;
          }
        }
        else {
          if (uVar5 == 0) goto LAB_10048e36;
          uVar6 = 0xff;
          if (uVar4 != 0) {
            uVar6 = param_1 & 0x7fffff;
            if (((param_1 & 0x400000) != 0) && ((param_2 & 0x400000) == 0)) {
              uVar6 = param_2 & 0x7fffff;
            }
            uVar9 = uVar6 << 3;
            uVar6 = 0xff;
            uVar7 = uVar3;
          }
        }
        goto LAB_10048b8e;
      }
      if (uVar1 != 0xff) {
        uVar9 = uVar5 + uVar4 >> 1;
        uVar6 = uVar1;
        goto LAB_10048b8e;
      }
    }
    else {
      if (uVar8 == 0) {
        if (uVar4 != 0) {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0) goto LAB_10048c60;
          if (uVar6 != 0xff) goto LAB_10048c4a;
        }
      }
      else if (uVar6 != 0xff) {
        uVar4 = uVar4 | 0x4000000;
LAB_10048c4a:
        if ((int)uVar1 < 0x1c) {
          uVar4 = (uint)(uVar4 << (0x20 - uVar1 & 0xff) != 0) | uVar4 >> (uVar1 & 0xff);
        }
        else {
          uVar4 = 1;
        }
LAB_10048c60:
        uVar9 = uVar5 + uVar4;
        uVar8 = uVar6;
LAB_10048c62:
        if (-1 < (int)(uVar9 << 5)) goto LAB_10048c14;
        if (uVar8 + 1 == 0xff) goto LAB_10048d4a;
        uVar9 = uVar9 >> 1 & DAT_10048e5c | uVar9 & 1;
        uVar6 = uVar8 + 1;
        uVar7 = uVar3;
      }
LAB_10048b8e:
      uVar8 = uVar6;
      uVar3 = uVar7;
      if ((uVar9 & 7) != 0) {
LAB_10048b92:
        if ((uVar9 & 0xf) != 4) {
          uVar9 = uVar9 + 4;
        }
      }
      uVar6 = uVar8;
      if ((int)(uVar9 << 5) < 0) {
        if (uVar8 + 1 == 0xff) {
          uVar9 = 0;
          uVar6 = 0xff;
        }
        else {
          uVar9 = (uVar9 << 6) >> 9;
          uVar6 = uVar8 + 1 & 0xff;
        }
        goto LAB_10048bb2;
      }
LAB_10048c18:
      uVar9 = uVar9 >> 3;
      if (uVar6 != 0xff) goto LAB_10048c8a;
      if (uVar9 != 0) {
LAB_10048c28:
        uVar9 = uVar9 & 0x7fffff | 0x400000;
        uVar6 = 0xff;
        goto LAB_10048bb2;
      }
    }
LAB_10048d4a:
    uVar6 = 0xff;
    uVar9 = 0;
  }
  else {
    if (0 < (int)uVar1) {
      if (uVar8 == 0) {
        if (uVar4 != 0) {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0) goto LAB_10048be2;
          if (uVar6 != 0xff) goto LAB_10048bcc;
        }
      }
      else if (uVar6 != 0xff) {
        uVar4 = uVar4 | 0x4000000;
LAB_10048bcc:
        if ((int)uVar1 < 0x1c) {
          uVar4 = (uint)(uVar4 << (0x20 - uVar1 & 0xff) != 0) | uVar4 >> (uVar1 & 0xff);
        }
        else {
          uVar4 = 1;
        }
LAB_10048be2:
        uVar9 = uVar5 - uVar4;
        goto LAB_10048be4;
      }
      goto LAB_10048b8e;
    }
    if (uVar1 != 0) {
      if (uVar6 == 0) {
        uVar9 = uVar4;
        uVar6 = uVar8;
        uVar7 = uVar3;
        if (uVar5 == 0) goto LAB_10048b8e;
        uVar1 = ~uVar1;
        if (uVar1 != 0) {
          if (uVar8 == 0xff) goto LAB_10048d40;
          goto LAB_10048d08;
        }
      }
      else {
        if (uVar8 == 0xff) {
LAB_10048d40:
          uVar9 = uVar4;
          uVar6 = 0xff;
          uVar7 = uVar3;
          goto LAB_10048b8e;
        }
        uVar1 = -uVar1;
        uVar5 = uVar5 | 0x4000000;
LAB_10048d08:
        if ((int)uVar1 < 0x1c) {
          uVar5 = (uint)(uVar5 << (0x20 - uVar1 & 0xff) != 0) | uVar5 >> (uVar1 & 0xff);
        }
        else {
          uVar5 = 1;
        }
      }
      uVar9 = uVar4 - uVar5;
      uVar6 = uVar8;
      uVar7 = uVar3;
LAB_10048be4:
      uVar8 = uVar6;
      uVar3 = uVar7;
      if ((int)(uVar9 << 5) < 0) {
        uVar9 = uVar9 & 0x3ffffff;
        goto LAB_10048bec;
      }
LAB_10048c14:
      uVar6 = uVar8;
      if ((uVar9 & 7) != 0) goto LAB_10048b92;
      goto LAB_10048c18;
    }
    if (1 < (uVar6 + 1 & 0xff)) {
      uVar9 = uVar5 - uVar4;
      if ((uVar9 & 0x4000000) == 0) {
        if (uVar9 == 0) {
          uVar3 = 0;
          uVar6 = 0;
          uVar9 = 0;
          goto LAB_10048c8a;
        }
      }
      else {
        uVar9 = uVar4 - uVar5;
        uVar7 = uVar3;
      }
LAB_10048bec:
      iVar2 = FUN_10056d78(uVar9);
      uVar8 = iVar2 - 5;
      uVar9 = uVar9 << (uVar8 & 0xff);
      if ((int)uVar8 < (int)uVar6) {
        uVar9 = DAT_10048e60 & uVar9;
        uVar6 = uVar6 - uVar8;
      }
      else {
        uVar6 = (uVar8 - uVar6) + 1;
        uVar9 = uVar9 >> (uVar6 & 0xff) | (uint)(uVar9 << (0x20 - uVar6 & 0xff) != 0);
        uVar6 = 0;
      }
      goto LAB_10048b8e;
    }
    if (uVar6 != 0) {
      if (uVar5 != 0) {
        uVar6 = 0xff;
        if (uVar4 != 0) {
          uVar6 = param_1 & 0x7fffff;
          if (((param_1 & 0x400000) != 0) && ((param_2 & 0x400000) == 0)) {
            uVar6 = param_2 & 0x7fffff;
            uVar7 = uVar3;
          }
          uVar9 = uVar6 << 3;
          uVar6 = 0xff;
        }
        goto LAB_10048b8e;
      }
      if (uVar4 != 0) {
        uVar9 = uVar4;
        uVar6 = 0xff;
        uVar7 = uVar3;
        goto LAB_10048b8e;
      }
      uVar3 = 0;
      uVar9 = 0x400000;
      goto LAB_10048c28;
    }
    if (uVar5 != 0) {
      if (uVar4 != 0) {
        uVar9 = uVar5 - uVar4;
        if ((uVar9 & 0x4000000) == 0) {
          uVar8 = uVar6;
          uVar3 = uVar7;
          if (uVar9 != 0) goto LAB_10048c14;
          uVar3 = 0;
          uVar9 = 0;
          goto LAB_10048c8a;
        }
        uVar9 = uVar4 - uVar5;
        uVar7 = uVar3;
      }
      goto LAB_10048b8e;
    }
    uVar9 = uVar4;
    uVar7 = uVar3;
    if (uVar4 != 0) goto LAB_10048b8e;
    uVar9 = 0;
    uVar3 = 0;
LAB_10048c8a:
    uVar9 = uVar9 & 0x7fffff;
    uVar6 = uVar6 & 0xff;
  }
LAB_10048bb2:
  return uVar9 | uVar6 << 0x17 | uVar3 << 0x1f;
}


