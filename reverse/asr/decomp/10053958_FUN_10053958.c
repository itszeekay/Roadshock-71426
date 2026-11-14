// FUNC 0x10053958  FUN_10053958

undefined4 FUN_10053958(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_10053974;
  iVar3 = *DAT_10053974;
  uVar2 = DAT_10053978;
  if (iVar3 < 0x20) {
    DAT_10053974[iVar3 + 1] = param_1;
    *piVar1 = iVar3 + 1;
    uVar2 = 0;
  }
  return uVar2;
}


