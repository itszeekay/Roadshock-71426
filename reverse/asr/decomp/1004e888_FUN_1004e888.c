// FUNC 0x1004e888  FUN_1004e888

void FUN_1004e888(undefined1 *param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = param_1 + param_2;
  for (; param_1 != puVar1; param_1 = param_1 + 1) {
    FUN_1004c5ac(DAT_1004e8a0,*param_1);
  }
  return;
}


