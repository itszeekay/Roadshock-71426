// FUNC 0x10000b0c  FUN_10000b0c

int FUN_10000b0c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = FUN_10000b24();
    iVar1 = iVar1 + 0x20;
  }
  else {
    iVar1 = FUN_10000b24(param_2);
  }
  return iVar1;
}


