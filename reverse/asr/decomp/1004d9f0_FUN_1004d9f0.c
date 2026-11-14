// FUNC 0x1004d9f0  FUN_1004d9f0

void FUN_1004d9f0(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  pinmux_set(param_1,3);
  puVar1 = DAT_1004da44;
  if (param_1 < 0x10) {
    uVar2 = 1 << (param_1 & 0xff);
    *(uint *)(DAT_1004da48 + 0x14) = uVar2;
    *puVar1 = *puVar1 & ~uVar2;
    *DAT_1004da4c = 3 << ((param_1 & 0x7f) << 1) | *DAT_1004da4c;
  }
  else {
    *(int *)(DAT_1004da50 + 0x14) = 1 << (param_1 - 0x10 & 0xff);
    *puVar1 = 1 << (param_1 & 0xff) | *puVar1;
    *DAT_1004da54 = 3 << ((param_1 - 0x10) * 2 & 0xff) | *DAT_1004da54;
  }
  return;
}


