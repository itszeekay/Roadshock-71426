// FUNC 0x10002e40  FUN_10002e40

void FUN_10002e40(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = param_2[1] - *(int *)(param_1 + 0x10);
  uVar1 = *(uint *)(param_1 + 0x70);
  iVar2 = *param_2;
  *(uint *)(param_1 + 0x70) = uVar4 + uVar1;
  *(uint *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + (uint)CARRY4(uVar4,uVar1);
  uVar3 = FUN_10002094(iVar2 + *(int *)(param_1 + 0x10),uVar4,*(undefined4 *)(param_1 + 0x18),
                       param_2,param_4);
  *(undefined4 *)(param_1 + 0x18) = uVar3;
  return;
}


