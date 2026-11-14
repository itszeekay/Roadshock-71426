// FUNC 0x100562f4  FUN_100562f4

void FUN_100562f4(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  while( true ) {
    iVar2 = FUN_1005621c(param_1,param_2,param_3);
    if (iVar2 != -1) {
      return;
    }
    if (*(char *)(param_1 + 0x28) == '\0') break;
    if (bVar1) goto LAB_10056328;
    FUN_100562ac(param_1);
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
LAB_10056328:
  *(char *)(param_1 + 0x28) = '\0';
  return;
}


