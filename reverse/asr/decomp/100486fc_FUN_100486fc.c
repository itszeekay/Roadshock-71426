// FUNC 0x100486fc  FUN_100486fc

void FUN_100486fc(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 & 0x7fffff;
  uVar3 = (param_1 << 1) >> 0x18;
  if (uVar3 == 0) {
    if (uVar2 == 0) {
      uVar2 = 4;
    }
    else {
      FUN_10056d78(uVar2);
      uVar2 = 0;
    }
  }
  else if (uVar3 == 0xff) {
    if (uVar2 == 0) {
      uVar2 = 8;
    }
    else {
      uVar2 = 0xc;
    }
  }
  else {
    uVar2 = 0;
  }
  uVar1 = param_2 & 0x7fffff;
  uVar3 = (param_2 << 1) >> 0x18;
  if (uVar3 == 0) {
    if (uVar1 == 0) {
      uVar3 = 1;
LAB_100487b2:
                    /* WARNING: Could not recover jumptable at 0x100487c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(PTR_PTR_LAB_10048928 + (uVar2 | uVar3) * 4))();
      return;
    }
    FUN_10056d78(uVar1);
    uVar3 = 0;
  }
  else if (uVar3 == 0xff) {
    if (uVar1 == 0) {
      uVar3 = 2;
      goto LAB_100487b2;
    }
    uVar3 = 3;
  }
  else {
    uVar3 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x10048762. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_PTR_LAB_10048924 + (uVar2 | uVar3) * 4))();
  return;
}


