// FUNC 0x1004d148  FUN_1004d148

undefined4 FUN_1004d148(byte *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (byte *)0x0) || (0xb < *param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    *DAT_1004d168 = 1 << (uint)*param_1 | *DAT_1004d168;
  }
  return uVar1;
}


