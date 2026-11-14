// FUNC 0x1004dc24  FUN_1004dc24

void FUN_1004dc24(int param_1)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_1004dc40 | 0x800;
  }
  else {
    uVar1 = DAT_1004dc44 & *DAT_1004dc40;
  }
  *DAT_1004dc40 = uVar1;
  return;
}


