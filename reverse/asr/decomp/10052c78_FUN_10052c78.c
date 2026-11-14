// FUNC 0x10052c78  FUN_10052c78

undefined4
FUN_10052c78(int param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,undefined2 param_5
            )

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_10052ca8,param_1 << 8 | 9,4,10,param_4);
  *(undefined2 *)(puVar1 + 2) = param_2;
  *(undefined2 *)(puVar1 + 4) = param_3;
  *(short *)(puVar1 + 6) = (short)param_4;
  *puVar1 = 2;
  *(undefined2 *)(puVar1 + 8) = param_5;
  FUN_10056e78();
  return 0;
}


