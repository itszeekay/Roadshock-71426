// FUNC 0x100567a4  FUN_100567a4

int FUN_100567a4(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(code **)(param_1 + 0x14) != (code *)0x0) {
    (**(code **)(param_1 + 0x14))();
  }
  for (uVar2 = 0; uVar2 < *(uint *)(param_1 + 0xc); uVar2 = uVar2 + *(int *)(param_1 + 8)) {
    iVar1 = FUN_10055f3c(param_1,uVar2);
    if (iVar1 != 0) goto LAB_100567cc;
  }
  iVar1 = 0;
LAB_100567cc:
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  return iVar1;
}


