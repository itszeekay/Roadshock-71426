// FUNC 0x10001abc  FUN_10001abc

void FUN_10001abc(void)

{
  int iVar1;
  
  iVar1 = DAT_10001ad0;
  *(undefined4 *)(DAT_10001ad0 + 0xc00) = DAT_10001ad4;
  *(undefined4 *)(iVar1 + 0xc) = 1;
  *(undefined4 *)(iVar1 + 0xc00) = DAT_10001ad8;
  return;
}


