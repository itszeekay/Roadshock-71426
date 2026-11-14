// FUNC 0x10056b8c  FUN_10056b8c

uint FUN_10056b8c(undefined4 *param_1,byte *param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int extraout_r1;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  pbVar9 = param_2;
  do {
    pbVar10 = pbVar9;
    uVar8 = (uint)*pbVar10;
    iVar2 = FUN_10056d04(param_5);
    pbVar9 = pbVar10 + 1;
  } while ((*(byte *)(iVar2 + uVar8 + 1) & 8) != 0);
  if (uVar8 == 0x2d) {
    bVar1 = true;
    pbVar9 = pbVar10 + 2;
    uVar8 = (uint)pbVar10[1];
  }
  else {
    bVar1 = false;
    if (uVar8 == 0x2b) {
      pbVar9 = pbVar10 + 2;
      uVar8 = (uint)pbVar10[1];
    }
  }
  if (param_4 == 0) {
    if (uVar8 != 0x30) {
      iVar2 = 10;
      param_4 = 10;
      goto LAB_10056bd8;
    }
    if ((*pbVar9 & 0xdf) != 0x58) {
      iVar2 = 8;
      param_4 = 8;
      goto LAB_10056bd8;
    }
  }
  else {
    iVar2 = param_4;
    if (param_4 != 0x10) goto LAB_10056bd8;
    if ((uVar8 != 0x30) || ((*pbVar9 & 0xdf) != 0x58)) {
      iVar2 = 0x10;
      goto LAB_10056bd8;
    }
  }
  uVar8 = (uint)pbVar9[1];
  iVar2 = 0x10;
  pbVar9 = pbVar9 + 2;
  param_4 = 0x10;
LAB_10056bd8:
  FUN_10056d68(-0x80000000 - (uint)!bVar1,iVar2);
  uVar3 = FUN_10056d58(-0x80000000 - (uint)!bVar1,iVar2);
  iVar5 = 0;
  uVar4 = 0;
  do {
    uVar7 = uVar8 - 0x30;
    if (9 < uVar7) {
      if (uVar8 - 0x41 < 0x1a) {
        uVar7 = uVar8 - 0x37;
      }
      else {
        if (0x19 < uVar8 - 0x61) break;
        uVar7 = uVar8 - 0x57;
      }
    }
    if (param_4 <= (int)uVar7) break;
    uVar6 = uVar4;
    if (iVar5 != -1) {
      if ((uVar3 < uVar4) || ((uVar3 == uVar4 && (uVar6 = uVar3, extraout_r1 < (int)uVar7)))) {
        iVar5 = -1;
      }
      else {
        iVar5 = 1;
        uVar6 = uVar7 + iVar2 * uVar4;
      }
    }
    uVar8 = (uint)*pbVar9;
    pbVar9 = pbVar9 + 1;
    uVar4 = uVar6;
  } while( true );
  if (iVar5 == -1) {
    uVar4 = 0x80000000 - !bVar1;
    *param_1 = 0x22;
    if (param_3 == (undefined4 *)0x0) {
      return uVar4;
    }
  }
  else {
    if (bVar1) {
      uVar4 = -uVar4;
    }
    if (param_3 == (undefined4 *)0x0) {
      return uVar4;
    }
    if (iVar5 == 0) goto LAB_10056c46;
  }
  param_2 = pbVar9 + -1;
LAB_10056c46:
  *param_3 = param_2;
  return uVar4;
}


