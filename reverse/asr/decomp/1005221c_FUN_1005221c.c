// FUNC 0x1005221c  FUN_1005221c

undefined4 FUN_1005221c(int param_1,undefined2 param_2,undefined1 param_3,int param_4,int param_5)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  
  if ((param_4 == 0) || (param_5 != 0)) {
    puVar1 = (undefined2 *)
             FUN_10056e38(DAT_10052268,param_1 << 8 | 7,4,param_4 + 6U & 0xffff,param_4);
    *puVar1 = param_2;
    puVar1[1] = (short)param_4;
    *(undefined1 *)(puVar1 + 2) = param_3;
    if (param_5 != 0) {
      FUN_10056de8((int)puVar1 + 5,param_5,param_4);
    }
    FUN_10056e78(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x440;
  }
  return uVar2;
}


