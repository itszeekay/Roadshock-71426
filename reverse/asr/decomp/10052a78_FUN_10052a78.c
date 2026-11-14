// FUNC 0x10052a78  FUN_10052a78

undefined4 FUN_10052a78(int param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_10052a9c,param_1 << 8 | 9,4,2);
  *puVar1 = param_2;
  puVar1[1] = param_3;
  FUN_10056e78();
  return 0;
}


