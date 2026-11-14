// FUNC 0x100528ec  FUN_100528ec

undefined4
FUN_100528ec(int param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5
            ,undefined2 param_6,undefined2 param_7,undefined2 param_8)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_1005294c,param_1 << 8 | 9,4,0xe);
  *puVar1 = 9;
  *(undefined2 *)(puVar1 + 6) = param_5;
  puVar1[1] = param_2;
  *(undefined2 *)(puVar1 + 8) = param_6;
  *(undefined2 *)(puVar1 + 2) = param_3;
  *(undefined2 *)(puVar1 + 10) = param_7;
  *(undefined2 *)(puVar1 + 4) = param_4;
  *(undefined2 *)(puVar1 + 0xc) = param_8;
  FUN_10056e78();
  return 0;
}


