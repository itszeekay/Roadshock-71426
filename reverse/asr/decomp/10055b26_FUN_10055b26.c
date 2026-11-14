// FUNC 0x10055b26  FUN_10055b26

void FUN_10055b26(undefined2 *param_1,undefined1 *param_2,int param_3)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  
  puVar2 = param_2 + param_3;
  for (; param_2 < puVar2; param_2 = param_2 + 1) {
    uVar1 = FUN_10055aa4(*param_1,*param_2);
    *param_1 = uVar1;
  }
  return;
}


