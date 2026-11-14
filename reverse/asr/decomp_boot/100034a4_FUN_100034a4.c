// FUNC 0x100034a4  FUN_100034a4

int FUN_100034a4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_100043bc(0x4a8);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x1d) = (char)param_1;
    iVar2 = FUN_10002cf8(param_1,param_2);
    *(int *)(iVar1 + 0x4a0) = iVar2;
    if (iVar2 == 0) {
      FUN_100043d0();
      iVar1 = 0;
    }
    else {
      FUN_10002eb2(iVar1);
    }
  }
  return iVar1;
}


