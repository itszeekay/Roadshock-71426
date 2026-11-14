// FUNC 0x1004c120  FUN_1004c120

void FUN_1004c120(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_1004c134;
  uVar2 = 1 << (param_1 & 0xff);
  *DAT_1004c134 = *DAT_1004c134 | uVar2;
  *puVar1 = *puVar1 & ~uVar2;
  return;
}


