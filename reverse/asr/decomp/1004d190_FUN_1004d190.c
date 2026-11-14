// FUNC 0x1004d190  FUN_1004d190

undefined4 FUN_1004d190(byte *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (byte *)0x0) || (0xb < *param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = FUN_1004d16c();
  }
  return uVar1;
}


