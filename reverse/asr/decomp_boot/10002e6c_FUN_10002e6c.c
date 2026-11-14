// FUNC 0x10002e6c  FUN_10002e6c

bool FUN_10002e6c(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  piVar4 = (int *)(param_1 + 0x98);
  uVar1 = param_2[2] - param_2[1];
  uVar2 = *(int *)(param_1 + 0x9c) - *piVar4;
  if (uVar1 < uVar2) {
    uVar2 = uVar1;
  }
  FUN_100049ac(param_1 + 0xa0 + *piVar4,*param_2 + param_2[1],uVar2,*param_2,param_4);
  param_2[1] = param_2[1] + uVar2;
  iVar3 = uVar2 + *piVar4;
  *piVar4 = iVar3;
  bVar5 = iVar3 == *(int *)(param_1 + 0x9c);
  if (bVar5) {
    *piVar4 = 0;
  }
  return bVar5;
}


