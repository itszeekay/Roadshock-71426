// FUNC 0x10004bd0  FUN_10004bd0

void FUN_10004bd0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_10004bf0;
  *DAT_10004bf0 = 0;
  iVar2 = FUN_10000c6c(param_2);
  if ((iVar2 == -1) && (*piVar1 != 0)) {
    *param_1 = *piVar1;
  }
  return;
}


