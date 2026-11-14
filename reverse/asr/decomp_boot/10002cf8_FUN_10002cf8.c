// FUNC 0x10002cf8  FUN_10002cf8

int FUN_10002cf8(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_100043bc(DAT_10002d38);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x3c) = (char)param_1;
    *(undefined4 *)(iVar1 + 0x34) = param_2;
    if (param_1 == 1) {
      iVar2 = FUN_100043bc(param_2);
      *(int *)(iVar1 + 0x18) = iVar2;
      if (iVar2 == 0) {
        FUN_100043d0(iVar1);
        iVar1 = 0;
      }
    }
    else if (param_1 == 2) {
      *(undefined4 *)(iVar1 + 0x18) = 0;
      *(undefined4 *)(iVar1 + 0x38) = 0;
    }
  }
  return iVar1;
}


