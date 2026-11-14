// FUNC 0x10003e10  FUN_10003e10

void FUN_10003e10(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_10003bac();
  if (iVar1 == -1) {
    if (*(char *)(param_1 + 0x28) != '\0') {
      FUN_10003dc8(param_1);
      iVar1 = FUN_10003bac(param_1,param_2,param_3);
      if (iVar1 == -1) {
        *(char *)(param_1 + 0x28) = '\0';
      }
    }
  }
  return;
}


