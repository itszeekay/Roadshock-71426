// FUNC 0x1004d16c  FUN_1004d16c

undefined4 FUN_1004d16c(byte *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (byte *)0x0) || (0xb < *param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    *DAT_1004d18c = *DAT_1004d18c & ~(1 << (uint)*param_1);
  }
  return uVar1;
}


