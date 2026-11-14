// FUNC 0x100536a8  FUN_100536a8

undefined4 FUN_100536a8(undefined1 param_1,undefined2 param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_100536d0,8,4,0x3a);
  puVar1[1] = param_1;
  *(undefined2 *)(puVar1 + 2) = param_2;
  *puVar1 = 0xa4;
  puVar1[4] = param_3;
  FUN_10056e78();
  return 0;
}


