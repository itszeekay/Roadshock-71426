// FUNC 0x10000c8c  FUN_10000c8c

void FUN_10000c8c(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_c;
  
  iVar1 = FUN_10000804(*DAT_10000cdc,DAT_10000ce0);
  uVar2 = FUN_10000804(iVar1 * param_1,0x11);
  if (uVar2 < 0xc) {
    uVar2 = 0xc;
  }
  for (local_c = uVar2 - 0xc; local_c != 0; local_c = local_c + -1) {
  }
  return;
}


