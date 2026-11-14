// FUNC 0x100522a0  FUN_100522a0

undefined4 FUN_100522a0(int param_1,undefined2 param_2,undefined1 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_10056e38(DAT_100522c4,param_1 << 8 | 7,4);
  *puVar1 = param_2;
  *(undefined1 *)(puVar1 + 1) = param_3;
  FUN_10056e78();
  return 0;
}


