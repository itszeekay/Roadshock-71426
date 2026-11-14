// FUNC 0x100020c0  FUN_100020c0

undefined8 FUN_100020c0(uint *param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  
  if (*param_1 < 0x1000000) {
    *param_1 = *param_1 << 8;
    uVar4 = param_1[4];
    param_1[4] = uVar4 + 1;
    param_1[1] = (uint)*(byte *)(param_1[3] + uVar4) + param_1[1] * 0x100;
  }
  uVar1 = *param_2;
  uVar4 = (uint)uVar1 * (*param_1 >> 0xb);
  uVar6 = param_1[1];
  if (uVar4 < uVar6 || uVar4 - uVar6 == 0) {
    uVar3 = *param_1 - uVar4;
    *param_1 = uVar3;
    param_1[1] = uVar6 - uVar4;
    *param_2 = uVar1 - (uVar1 >> 5);
    if (uVar3 < 0x1000000) {
      *param_1 = uVar3 * 0x100;
      uVar3 = param_1[4];
      param_1[4] = uVar3 + 1;
      param_1[1] = (uint)*(byte *)(param_1[3] + uVar3) + (uVar6 - uVar4) * 0x100;
    }
    uVar1 = param_2[1];
    uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
    uVar4 = param_1[1];
    if (uVar6 < uVar4 || uVar6 - uVar4 == 0) {
      *param_1 = *param_1 - uVar6;
      param_1[1] = uVar4 - uVar6;
      param_2[1] = uVar1 - (uVar1 >> 5);
      iVar2 = 0x204;
      param_1[0x19] = 0x12;
      uVar4 = 0x100;
      goto LAB_1000210a;
    }
    iVar2 = param_3 * 0x10 + 0x104;
    *param_1 = uVar6;
    param_2[1] = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
    uVar6 = 10;
  }
  else {
    uVar6 = 2;
    iVar2 = param_3 * 0x10 + 4;
    *param_1 = uVar4;
    *param_2 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
  }
  uVar4 = 8;
  param_1[0x19] = uVar6;
LAB_1000210a:
  uVar6 = 1;
  do {
    puVar5 = (ushort *)((int)param_2 + uVar6 * 2 + iVar2);
    if (*param_1 < 0x1000000) {
      *param_1 = *param_1 << 8;
      uVar3 = param_1[4];
      param_1[4] = uVar3 + 1;
      param_1[1] = (uint)*(byte *)(param_1[3] + uVar3) + param_1[1] * 0x100;
    }
    uVar7 = param_1[1];
    uVar1 = *puVar5;
    uVar3 = (uint)uVar1 * (*param_1 >> 0xb);
    uVar6 = uVar6 * 2;
    if (uVar3 < uVar7 || uVar3 - uVar7 == 0) {
      *param_1 = *param_1 - uVar3;
      uVar6 = uVar6 + 1;
      param_1[1] = uVar7 - uVar3;
      *puVar5 = uVar1 - (uVar1 >> 5);
    }
    else {
      *param_1 = uVar3;
      *puVar5 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
    }
  } while (uVar6 < uVar4);
  param_1[0x19] = (param_1[0x19] - uVar4) + uVar6;
  return CONCAT44(uVar7,param_1);
}


