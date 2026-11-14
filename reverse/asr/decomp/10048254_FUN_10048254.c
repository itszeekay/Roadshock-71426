// FUNC 0x10048254  FUN_10048254

int FUN_10048254(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_100481d0(param_1,param_2,0,DAT_1004828c);
  if (iVar1 == 0) {
    iVar1 = FUN_1004a9f0(param_1,param_2);
  }
  else {
    FUN_1004a348(param_1,param_2,0,DAT_1004828c);
    iVar1 = FUN_1004a9f0();
    iVar1 = iVar1 + -0x80000000;
  }
  return iVar1;
}


