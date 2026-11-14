// FUNC 0x100534a4  FUN_100534a4

undefined2
FUN_100534a4(undefined4 param_1,undefined4 param_2,int param_3,int param_4,ushort param_5,
            short param_6,undefined2 param_7,undefined2 param_8)

{
  undefined2 uVar1;
  
  if ((((DAT_10053500 < (param_4 - 6U & 0xffff)) || (DAT_10053500 < (param_3 - 6U & 0xffff))) ||
      (DAT_10053504 < (ushort)(param_6 - 10))) || (499 < param_5)) {
    uVar1 = 0x340;
  }
  else {
    uVar1 = FUN_100528ec(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  return uVar1;
}


