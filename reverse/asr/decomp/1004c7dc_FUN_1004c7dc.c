// FUNC 0x1004c7dc  FUN_1004c7dc

int FUN_1004c7dc(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_1004c824 + param_1 * 0x14;
  if (*(uint *)(iVar1 + 0xc) < (uint)(param_3 + param_2)) {
    iVar1 = -1;
  }
  else {
    uVar2 = param_2 + *(int *)(iVar1 + 8);
    for (uVar3 = uVar2 & 0xfffff000; uVar3 <= ((param_3 + uVar2) - 1 & 0xfffff000);
        uVar3 = uVar3 + 0x1000) {
      iVar1 = FUN_10056d98(DAT_1004c828,uVar3);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


