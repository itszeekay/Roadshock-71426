// FUNC 0x10052a0c  FUN_10052a0c

undefined4 FUN_10052a0c(int param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(0xe10,param_1 << 8 | 9,4,6);
  *(undefined2 *)(puVar1 + 4) = param_4;
  *(undefined2 *)(puVar1 + 2) = param_3;
  *puVar1 = param_2;
  FUN_10056e78();
  return 0;
}


