// FUNC 0x10000c6c  FUN_10000c6c

uint FUN_10000c6c(int param_1)

{
  uint uVar1;
  
  uVar1 = *DAT_10000c84;
  if (DAT_10000c88 < uVar1 + param_1) {
    uVar1 = 0xffffffff;
  }
  else {
    *DAT_10000c84 = uVar1 + param_1;
  }
  return uVar1;
}


