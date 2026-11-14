// FUNC 0x10048224  FUN_10048224

int FUN_10048224(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_1004ad70(param_1,0x4f000000);
  if (iVar1 == 0) {
    iVar1 = FUN_10048e64(param_1);
  }
  else {
    FUN_10048b58(param_1,0x4f000000);
    iVar1 = FUN_10048e64();
    iVar1 = iVar1 + -0x80000000;
  }
  return iVar1;
}


