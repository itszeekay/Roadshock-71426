// FUNC 0x1004d0ec  FUN_1004d0ec

undefined4 FUN_1004d0ec(byte *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_1004d134;
  if ((param_1 == (byte *)0x0) || (0xb < *param_1)) {
    uVar2 = 0xffffffff;
  }
  else {
    *DAT_1004d130 = DAT_1004d12c;
    *DAT_1004d13c = DAT_1004d138;
    *DAT_1004d140 = DAT_1004d144 & *DAT_1004d140;
    *puVar1 = *puVar1 & ~(1 << (uint)*param_1);
    FUN_1004cf6c();
    uVar2 = 0;
    puVar1[1] = 0;
  }
  return uVar2;
}


