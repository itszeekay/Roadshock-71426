// FUNC 0x100522f4  FUN_100522f4

undefined4 FUN_100522f4(int param_1,undefined2 param_2,undefined2 param_3,undefined1 param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_10056e38(DAT_1005231c,param_1 << 8 | 7,4,6);
  *puVar1 = param_2;
  puVar1[1] = param_3;
  *(undefined1 *)(puVar1 + 2) = param_4;
  FUN_10056e78();
  return 0;
}


