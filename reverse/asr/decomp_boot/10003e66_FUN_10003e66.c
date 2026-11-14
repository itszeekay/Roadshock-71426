// FUNC 0x10003e66  FUN_10003e66

uint FUN_10003e66(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_30 [8];
  uint local_28;
  undefined4 local_1c;
  
  uVar2 = (uint)*(byte *)(param_1 + 0x10);
  if (uVar2 != 0) {
    if (*(code **)(param_1 + 0x14) != (code *)0x0) {
      (**(code **)(param_1 + 0x14))();
    }
    iVar3 = *param_3;
    uVar2 = param_3[1];
    iVar1 = FUN_10003a1c(param_1,param_2,auStack_30);
    if (iVar1 == 0) {
      param_3[4] = 0;
      uVar2 = 0;
    }
    else {
      param_3[4] = local_28;
      if (local_28 < uVar2) {
        uVar2 = local_28;
      }
      if (iVar3 != 0) {
        FUN_1000421e(param_1,local_1c,iVar3,uVar2);
      }
    }
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return uVar2;
}


