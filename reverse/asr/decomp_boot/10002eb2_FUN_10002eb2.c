// FUNC 0x10002eb2  FUN_10002eb2

void FUN_10002eb2(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[0x1e] = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_10004b08(param_1 + 0x38,0,0x30);
  FUN_10004b08(param_1 + 0x68,0,0x30);
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0xc;
  return;
}


