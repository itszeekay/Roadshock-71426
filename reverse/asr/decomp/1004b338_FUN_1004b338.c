// FUNC 0x1004b338  FUN_1004b338

void FUN_1004b338(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,uint param_7,uint param_8,uint param_9)

{
  int iVar1;
  int iVar2;
  char extraout_r1;
  char extraout_r1_00;
  undefined4 uVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  char *pcVar12;
  uint uVar13;
  uint local_58;
  char local_38 [36];
  
  uVar10 = CONCAT44(param_6,param_5);
  iVar1 = FUN_10048188(param_5,param_6);
  if (iVar1 == 0) {
    uVar13 = 3;
    pcVar12 = DAT_1004b610;
    goto LAB_1004b5f4;
  }
  iVar1 = FUN_10048194(param_5,param_6,0xffffffff,DAT_1004b614);
  if (iVar1 != 0) {
    uVar13 = 4;
    pcVar12 = DAT_1004b618;
    goto LAB_1004b5f4;
  }
  iVar1 = FUN_100481bc(param_5,param_6,0xffffffff,DAT_1004b61c);
  if (iVar1 != 0) {
    uVar13 = 4;
    pcVar12 = DAT_1004b620;
    if ((param_9 & 4) == 0) {
      uVar13 = 3;
      pcVar12 = DAT_1004b624;
    }
    goto LAB_1004b5f4;
  }
  iVar1 = FUN_100481bc(param_5,param_6,0,DAT_1004b628);
  if ((iVar1 != 0) || (iVar1 = FUN_10048194(param_5,param_6,0,DAT_1004b62c), iVar1 != 0)) {
    FUN_1004b638(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    return;
  }
  iVar1 = FUN_10048194(param_5,param_6,0,0);
  bVar9 = iVar1 != 0;
  if (bVar9) {
    uVar10 = FUN_1004a348(0,0,param_5,param_6);
  }
  param_6 = (undefined4)((ulonglong)uVar10 >> 0x20);
  param_5 = (undefined4)uVar10;
  if (-1 < (int)(param_9 << 0x15)) {
    param_7 = 6;
  }
  uVar8 = 0;
  do {
    if (param_7 < 10) break;
    local_38[uVar8] = '0';
    uVar8 = uVar8 + 1;
    param_7 = param_7 - 1;
  } while (uVar8 != 0x20);
  local_58 = FUN_1004a9f0(param_5,param_6);
  puVar5 = (undefined4 *)(DAT_1004b630 + param_7 * 8);
  uVar7 = puVar5[1];
  uVar6 = *puVar5;
  uVar10 = FUN_1004aa5c();
  uVar10 = FUN_1004a348(param_5,param_6,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
  uVar10 = FUN_10049e54((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar6,uVar7);
  iVar2 = FUN_10048254();
  uVar11 = FUN_1004aae0();
  uVar10 = FUN_1004a348((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                        (int)((ulonglong)uVar11 >> 0x20));
  uVar3 = (undefined4)((ulonglong)uVar10 >> 0x20);
  iVar1 = FUN_100481bc((int)uVar10,uVar3,0,DAT_1004b634);
  if (iVar1 == 0) {
    iVar1 = FUN_10048194((int)uVar10,uVar3,0,DAT_1004b634);
    if ((iVar1 == 0) && ((iVar2 == 0 || (iVar2 << 0x1f < 0)))) {
      iVar2 = iVar2 + 1;
    }
  }
  else {
    iVar2 = iVar2 + 1;
    uVar10 = FUN_1004aae0(iVar2);
    iVar1 = FUN_100481a8(uVar6,uVar7,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    if (iVar1 != 0) {
      iVar2 = 0;
      local_58 = local_58 + 1;
    }
  }
  if (param_7 == 0) {
    uVar10 = FUN_1004aa5c(local_58);
    uVar10 = FUN_1004a348(param_5,param_6,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    uVar3 = (undefined4)((ulonglong)uVar10 >> 0x20);
    iVar1 = FUN_10048194((int)uVar10,uVar3,0,DAT_1004b634);
    if ((iVar1 == 0) || (iVar1 = FUN_100481bc((int)uVar10,uVar3,0,DAT_1004b634), iVar1 != 0)) {
      local_58 = local_58 + (local_58 & 1);
    }
LAB_1004b584:
    do {
      if (uVar8 == 0x20) goto LAB_1004b588;
      uVar13 = uVar8 + 1;
      FUN_10056ed8(local_58,10);
      local_38[uVar8] = extraout_r1_00 + '0';
      local_58 = FUN_10056e98(local_58,10);
      uVar8 = uVar13;
    } while (local_58 != 0);
  }
  else {
    do {
      if (uVar8 == 0x20) goto LAB_1004b588;
      param_7 = param_7 - 1;
      uVar13 = uVar8 + 1;
      FUN_10056d68(iVar2,10);
      local_38[uVar8] = extraout_r1 + '0';
      iVar2 = FUN_10056d58(iVar2,10);
      uVar8 = uVar13;
    } while (iVar2 != 0);
    param_7 = param_7 + uVar13;
    for (; uVar13 != 0x20; uVar13 = uVar13 + 1) {
      if (param_7 == uVar13) {
        local_38[param_7] = '.';
        uVar8 = param_7 + 1;
        goto LAB_1004b584;
      }
      local_38[uVar13] = '0';
    }
LAB_1004b588:
    uVar13 = 0x20;
  }
  if (((param_9 & 3) == 1) && (param_8 != 0)) {
    if ((bVar9) || ((param_9 & 0xc) != 0)) {
      param_8 = param_8 - 1;
    }
    for (; uVar13 < param_8; uVar13 = uVar13 + 1) {
      if (uVar13 == 0x20) goto LAB_1004b5e6;
      local_38[uVar13] = '0';
    }
  }
  if (uVar13 < 0x20) {
    if (bVar9) {
      cVar4 = '-';
    }
    else if ((int)(param_9 << 0x1d) < 0) {
      cVar4 = '+';
    }
    else {
      if (-1 < (int)(param_9 << 0x1c)) goto LAB_1004b5e6;
      cVar4 = ' ';
    }
    local_38[uVar13] = cVar4;
    uVar13 = uVar13 + 1;
  }
LAB_1004b5e6:
  pcVar12 = local_38;
LAB_1004b5f4:
  FUN_1004b02e(param_1,param_2,param_3,param_4,pcVar12,uVar13,param_8,param_9);
  return;
}


