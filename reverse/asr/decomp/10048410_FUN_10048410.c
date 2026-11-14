// FUNC 0x10048410  FUN_10048410

uint FUN_10048410(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar6 = -((int)param_1 >> 0x1f);
  uVar5 = (param_1 << 1) >> 0x18;
  uVar4 = (param_1 << 9) >> 6;
  uVar7 = (param_2 << 1) >> 0x18;
  iVar2 = -((int)param_2 >> 0x1f);
  uVar3 = (param_2 << 9) >> 6;
  uVar8 = uVar4;
  if (iVar6 == iVar2) {
    uVar1 = uVar5 - uVar7;
    if ((int)uVar1 < 1) {
      if (uVar1 != 0) {
        if (uVar5 == 0) {
          uVar8 = uVar3;
          uVar5 = uVar7;
          if (uVar4 == 0) goto LAB_1004843e;
          uVar1 = ~uVar1;
          if (uVar1 == 0) goto LAB_10048640;
          if (uVar7 != 0xff) goto LAB_1004862c;
        }
        else if (uVar7 != 0xff) {
          uVar1 = -uVar1;
          uVar4 = uVar4 | 0x4000000;
LAB_1004862c:
          if ((int)uVar1 < 0x1c) {
            uVar4 = (uint)(uVar4 << (0x20 - uVar1 & 0xff) != 0) | uVar4 >> (uVar1 & 0xff);
          }
          else {
            uVar4 = 1;
          }
LAB_10048640:
          uVar8 = uVar4 + uVar3;
          goto LAB_1004850c;
        }
LAB_100486ce:
        uVar8 = uVar3;
        uVar5 = 0xff;
        goto LAB_1004843e;
      }
      uVar7 = uVar5 + 1;
      if ((uVar7 & 0xff) < 2) {
        if (uVar5 == 0) {
          uVar8 = uVar3;
          if ((uVar4 != 0) && (uVar8 = uVar4, uVar3 != 0)) {
            uVar8 = uVar4 + uVar3;
            if (-1 < (int)(uVar8 * 0x20)) goto LAB_100484be;
            uVar8 = uVar8 & DAT_100486f8;
            uVar5 = uVar7;
          }
        }
        else {
          if (uVar4 == 0) goto LAB_100486ce;
          uVar5 = 0xff;
          if (uVar3 != 0) {
            uVar8 = param_1 & 0x7fffff;
            if (((param_1 & 0x400000) != 0) && ((param_2 & 0x400000) == 0)) {
              uVar8 = param_2 & 0x7fffff;
            }
            goto LAB_100486a0;
          }
        }
        goto LAB_1004843e;
      }
      if (uVar7 != 0xff) {
        uVar8 = uVar4 + uVar3 >> 1;
        uVar5 = uVar7;
        goto LAB_1004843e;
      }
    }
    else {
      if (uVar7 == 0) {
        if (uVar3 != 0) {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0) goto LAB_1004850a;
          if (uVar5 != 0xff) goto LAB_100484f4;
        }
      }
      else if (uVar5 != 0xff) {
        uVar3 = uVar3 | 0x4000000;
LAB_100484f4:
        if ((int)uVar1 < 0x1c) {
          uVar3 = (uint)(uVar3 << (0x20 - uVar1 & 0xff) != 0) | uVar3 >> (uVar1 & 0xff);
        }
        else {
          uVar3 = 1;
        }
LAB_1004850a:
        uVar8 = uVar4 + uVar3;
        uVar7 = uVar5;
LAB_1004850c:
        uVar5 = uVar7;
        if (-1 < (int)(uVar8 << 5)) goto LAB_100484be;
        if (uVar7 + 1 == 0xff) goto LAB_100485e0;
        uVar8 = uVar8 >> 1 & DAT_100486f4 | uVar8 & 1;
        uVar5 = uVar7 + 1;
      }
LAB_1004843e:
      if ((uVar8 & 7) != 0) {
LAB_10048442:
        if ((uVar8 & 0xf) != 4) {
          uVar8 = uVar8 + 4;
        }
      }
      if ((int)(uVar8 << 5) < 0) {
        if (uVar5 + 1 == 0xff) {
          uVar8 = 0;
          uVar5 = 0xff;
        }
        else {
          uVar8 = (uVar8 << 6) >> 9;
          uVar5 = uVar5 + 1 & 0xff;
        }
        goto LAB_10048460;
      }
LAB_100484c2:
      uVar8 = uVar8 >> 3;
      if (uVar5 != 0xff) goto LAB_1004852a;
      if (uVar8 != 0) {
LAB_100484d0:
        uVar8 = uVar8 & 0x7fffff | 0x400000;
        uVar5 = 0xff;
        goto LAB_10048460;
      }
    }
LAB_100485e0:
    uVar5 = 0xff;
    uVar8 = 0;
  }
  else {
    uVar1 = uVar5 - uVar7;
    if (0 < (int)uVar1) {
      if (uVar7 == 0) {
        if (uVar3 != 0) {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0) goto LAB_1004848e;
          if (uVar5 != 0xff) goto LAB_10048478;
        }
      }
      else if (uVar5 != 0xff) {
        uVar3 = uVar3 | 0x4000000;
LAB_10048478:
        if ((int)uVar1 < 0x1c) {
          uVar3 = (uint)(uVar3 << (0x20 - uVar1 & 0xff) != 0) | uVar3 >> (uVar1 & 0xff);
        }
        else {
          uVar3 = 1;
        }
LAB_1004848e:
        uVar8 = uVar4 - uVar3;
        goto LAB_10048490;
      }
      goto LAB_1004843e;
    }
    if (uVar1 != 0) {
      if (uVar5 == 0) {
        uVar8 = uVar3;
        uVar5 = uVar7;
        iVar6 = iVar2;
        if (uVar4 == 0) goto LAB_1004843e;
        uVar1 = ~uVar1;
        if (uVar1 != 0) {
          if (uVar7 == 0xff) goto LAB_100486a6;
          goto LAB_100485a8;
        }
      }
      else {
        if (uVar7 == 0xff) {
LAB_100486a6:
          uVar8 = uVar3;
          uVar5 = 0xff;
          iVar6 = iVar2;
          goto LAB_1004843e;
        }
        uVar1 = -uVar1;
        uVar4 = uVar4 | 0x4000000;
LAB_100485a8:
        if ((int)uVar1 < 0x1c) {
          uVar4 = (uint)(uVar4 << (0x20 - uVar1 & 0xff) != 0) | uVar4 >> (uVar1 & 0xff);
        }
        else {
          uVar4 = 1;
        }
      }
      uVar8 = uVar3 - uVar4;
      uVar5 = uVar7;
      iVar6 = iVar2;
LAB_10048490:
      if ((int)(uVar8 << 5) < 0) {
        uVar8 = uVar8 & 0x3ffffff;
        goto LAB_10048498;
      }
LAB_100484be:
      if ((uVar8 & 7) != 0) goto LAB_10048442;
      goto LAB_100484c2;
    }
    if (1 < (uVar5 + 1 & 0xff)) {
      uVar8 = uVar4 - uVar3;
      if ((uVar8 & 0x4000000) == 0) {
        if (uVar8 == 0) {
          iVar6 = 0;
          uVar5 = 0;
          uVar8 = 0;
          goto LAB_1004852a;
        }
      }
      else {
        uVar8 = uVar3 - uVar4;
        iVar6 = iVar2;
      }
LAB_10048498:
      iVar2 = FUN_10056d78(uVar8);
      uVar7 = iVar2 - 5;
      uVar8 = uVar8 << (uVar7 & 0xff);
      if ((int)uVar7 < (int)uVar5) {
        uVar8 = DAT_100486f8 & uVar8;
        uVar5 = uVar5 - uVar7;
      }
      else {
        uVar5 = (uVar7 - uVar5) + 1;
        uVar8 = uVar8 >> (uVar5 & 0xff) | (uint)(uVar8 << (0x20 - uVar5 & 0xff) != 0);
        uVar5 = 0;
      }
      goto LAB_1004843e;
    }
    if (uVar5 != 0) {
      if (uVar4 != 0) {
        uVar5 = 0xff;
        if (uVar3 != 0) {
          uVar8 = param_1 & 0x7fffff;
          if (((param_1 & 0x400000) != 0) && ((param_2 & 0x400000) == 0)) {
            uVar8 = param_2 & 0x7fffff;
            iVar6 = iVar2;
          }
LAB_100486a0:
          uVar8 = uVar8 << 3;
          uVar5 = 0xff;
        }
        goto LAB_1004843e;
      }
      if (uVar3 != 0) {
        uVar8 = uVar3;
        uVar5 = 0xff;
        iVar6 = iVar2;
        goto LAB_1004843e;
      }
      iVar6 = 0;
      uVar8 = 0x400000;
      goto LAB_100484d0;
    }
    if (uVar4 != 0) {
      if (uVar3 != 0) {
        uVar8 = uVar4 - uVar3;
        if ((uVar8 & 0x4000000) == 0) {
          if (uVar8 != 0) goto LAB_100484be;
          iVar6 = 0;
          uVar8 = 0;
          goto LAB_1004852a;
        }
        uVar8 = uVar3 - uVar4;
        iVar6 = iVar2;
      }
      goto LAB_1004843e;
    }
    uVar8 = uVar3;
    iVar6 = iVar2;
    if (uVar3 != 0) goto LAB_1004843e;
    uVar8 = 0;
    iVar6 = 0;
LAB_1004852a:
    uVar8 = uVar8 & 0x7fffff;
    uVar5 = uVar5 & 0xff;
  }
LAB_10048460:
  return iVar6 << 0x1f | uVar8 | uVar5 << 0x17;
}


