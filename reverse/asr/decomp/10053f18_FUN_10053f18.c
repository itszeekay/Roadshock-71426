// FUNC 0x10053f18  FUN_10053f18

void FUN_10053f18(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  if (param_3 < 0x20) {
    uVar1 = (1 << (param_3 & 0xff)) - 1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  if ((((param_1 != 0xff) && (param_2 < 0x20)) && (param_3 < 0x21)) && (param_4 <= uVar1)) {
    FUN_10053f00(param_1,param_4 << (param_2 & 0xff) |
                         *(uint *)((param_1 + DAT_10053f54) * 4) & ~(uVar1 << (param_2 & 0xff)));
  }
  return;
}


