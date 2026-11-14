// FUNC 0x10056a5c  FUN_10056a5c

undefined4 FUN_10056a5c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x24))();
  }
  return uVar1;
}


