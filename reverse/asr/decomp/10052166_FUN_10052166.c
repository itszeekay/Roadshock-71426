// FUNC 0x10052166  FUN_10052166

undefined4 FUN_10052166(int param_1,undefined2 param_2,undefined2 param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_4 == 0) || (param_5 != 0)) {
    puVar1 = (undefined1 *)FUN_10056e38(0xc10,param_1 << 8 | 7,4,param_4 + 8U & 0xffff,param_4);
    *puVar1 = 0x12;
    *(short *)(puVar1 + 6) = (short)param_4;
    *(undefined2 *)(puVar1 + 2) = param_2;
    *(undefined2 *)(puVar1 + 4) = param_3;
    if (param_5 != 0) {
      FUN_10056de8(puVar1 + 8,param_5,param_4);
    }
    FUN_10056e78(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x440;
  }
  return uVar2;
}


