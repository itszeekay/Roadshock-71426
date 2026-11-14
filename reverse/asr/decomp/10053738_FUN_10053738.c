// FUNC 0x10053738  FUN_10053738

undefined8 FUN_10053738(undefined4 param_1,undefined1 param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_3 == 0) || (param_4 != 0)) {
    uVar2 = param_1;
    puVar1 = (undefined1 *)
             FUN_10056e38(DAT_10053784,8,4,param_3 + 4U & 0xffff,param_1,param_1,param_3);
    puVar1[1] = param_2;
    *puVar1 = (char)uVar2;
    *(short *)(puVar1 + 2) = (short)param_3;
    if (param_4 != 0) {
      FUN_10056de8(puVar1 + 4,param_4,param_3);
    }
    FUN_10056e78(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x340;
  }
  return CONCAT44(param_1,uVar2);
}


