// FUNC 0x1004c630  FUN_1004c630

undefined4 FUN_1004c630(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  bVar1 = *param_1;
  if (bVar1 == 0) {
    iVar6 = 0x40000000;
  }
  else {
    iVar6 = DAT_1004c74c;
    if (((bVar1 != 1) && (iVar6 = DAT_1004c750, bVar1 != 2)) && (iVar6 = DAT_1004c748, bVar1 != 3))
    {
      return 0xffffffff;
    }
  }
  do {
  } while ((*(uint *)(iVar6 + 0x18) & 8) != 0);
  *(undefined4 *)(iVar6 + 0x38) = 0;
  *(undefined4 *)(iVar6 + 0x30) = 0;
  *(undefined4 *)(iVar6 + 0x2c) = 0;
  uVar2 = *(undefined4 *)(param_1 + 4);
  *(uint *)(iVar6 + 0x48) = *(uint *)(iVar6 + 0x48) & 0xfffffffc;
  uVar3 = FUN_1004c55c(uVar2);
  *(uint *)(iVar6 + 0x24) = uVar3 >> 0x10;
  *(uint *)(iVar6 + 0x28) = uVar3 & 0x3f;
  *(uint *)(iVar6 + 0x2c) = (uint)param_1[8] << 5 | (uint)param_1[10] << 3 | *(uint *)(iVar6 + 0x2c)
  ;
  bVar1 = param_1[9];
  if (bVar1 == 1) {
    *(uint *)(iVar6 + 0x2c) = *(uint *)(iVar6 + 0x2c) & 0xfffffff9;
    uVar3 = *(uint *)(iVar6 + 0x2c);
    uVar5 = 2;
LAB_1004c6ac:
    uVar3 = uVar3 | uVar5;
  }
  else {
    if (bVar1 != 0) {
      if (bVar1 != 2) goto LAB_1004c6bc;
      uVar5 = 6;
      uVar3 = *(uint *)(iVar6 + 0x2c);
      goto LAB_1004c6ac;
    }
    uVar3 = *(uint *)(iVar6 + 0x2c) & 0xfffffffd;
  }
  *(uint *)(iVar6 + 0x2c) = uVar3;
LAB_1004c6bc:
  if (param_1[0xc] == 0) {
    param_1[0xc] = 3;
  }
  *(uint *)(iVar6 + 0x30) = DAT_1004c754 & *(uint *)(iVar6 + 0x30);
  uVar2 = 0x10;
  *(uint *)(iVar6 + 0x30) =
       (uint)param_1[0xb] << 0xe | (uint)param_1[0xc] << 8 | *(uint *)(iVar6 + 0x30);
  *(uint *)(iVar6 + 0x2c) = *(uint *)(iVar6 + 0x2c) | 0x10;
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) & 0xfffffff8;
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) | 2;
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) & 0xffffffc7;
  iVar4 = *(int *)(param_1 + 0x10);
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) | 0x10;
  if (iVar4 != 0) {
    *(uint *)(iVar6 + 0x38) = *(uint *)(iVar6 + 0x38) | 0x50;
    if (iVar6 == 0x40000000) {
      uVar2 = 8;
    }
    else if (iVar6 == DAT_1004c74c) {
      uVar2 = 4;
    }
    else if (iVar6 != DAT_1004c750) {
      uVar2 = 0x20;
    }
    *DAT_1004c758 = uVar2;
    *(int *)((uint)*param_1 * 4 + DAT_1004c75c) = iVar4;
  }
  *(uint *)(iVar6 + 0x30) = *(uint *)(iVar6 + 0x30) | 1;
  return 0;
}


