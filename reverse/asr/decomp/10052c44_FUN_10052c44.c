// FUNC 0x10052c44  FUN_10052c44

undefined4 FUN_10052c44(int param_1,undefined2 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_10052c68,param_1 << 8 | 9,4,10);
  *(undefined2 *)(puVar1 + 2) = param_2;
  *puVar1 = 1;
  FUN_10056e78();
  return 0;
}


