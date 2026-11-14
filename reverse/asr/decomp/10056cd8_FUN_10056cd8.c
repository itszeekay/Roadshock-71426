// FUNC 0x10056cd8  FUN_10056cd8

void FUN_10056cd8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*DAT_10056cfc + 0x34);
  if (iVar1 == 0) {
    iVar1 = DAT_10056d00;
  }
  FUN_10056b8c(*DAT_10056cfc,param_1,param_2,param_3,iVar1);
  return;
}


