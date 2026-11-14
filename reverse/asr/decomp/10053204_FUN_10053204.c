// FUNC 0x10053204  FUN_10053204

undefined4
FUN_10053204(undefined1 param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)FUN_10056e38(0xda0,8,4,(byte)param_2[0x27] + 0x2c,param_4);
  *puVar2 = 0xa0;
  puVar1 = DAT_100532b0;
  puVar2[1] = param_1;
  *puVar1 = 0xff;
  puVar2[4] = *param_2;
  puVar2[5] = param_2[1];
  *(undefined2 *)(puVar2 + 6) = *(undefined2 *)(param_2 + 2);
  puVar2[8] = param_2[4];
  puVar2[9] = param_2[5];
  FUN_10056de8(puVar2 + 10,param_2 + 6,6);
  puVar2[0x10] = param_2[0xc];
  *(undefined4 *)(puVar2 + 0x14) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(puVar2 + 0x18) = *(undefined4 *)(param_2 + 0x14);
  puVar2[0x1c] = param_2[0x18];
  puVar2[0x1d] = param_2[0x19];
  puVar2[0x20] = param_2[0x1c];
  puVar2[0x21] = param_2[0x1d];
  puVar2[0x22] = param_2[0x1e];
  *(undefined2 *)(puVar2 + 0x24) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(puVar2 + 0x26) = *(undefined2 *)(param_2 + 0x14);
  puVar2[0x28] = param_2[0x24];
  puVar2[0x29] = param_2[0x25];
  puVar2[0x2a] = param_2[0x26];
  puVar2[0x2b] = param_2[0x27];
  FUN_10056de8(puVar2 + 0x2c,param_2 + 0x28,param_2[0x27]);
  FUN_10056e78(puVar2);
  return 0;
}


