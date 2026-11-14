// FUNC 0x10004230  FUN_10004230

undefined4 FUN_10004230(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x24))(param_1);
  }
  return uVar1;
}


