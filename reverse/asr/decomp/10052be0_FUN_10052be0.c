// FUNC 0x10052be0  FUN_10052be0

undefined4 FUN_10052be0(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_2 == 0) || (param_3 != 0)) {
    puVar1 = (undefined1 *)FUN_10056e38(DAT_10052c28,param_1 << 8 | 9,4,param_2 + 10U & 0xffff);
    *puVar1 = 0;
    *(short *)(puVar1 + 2) = (short)param_2;
    if (param_3 != 0) {
      FUN_10056de8(puVar1 + 4,param_3,param_2);
    }
    FUN_10056e78(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x340;
  }
  return uVar2;
}


