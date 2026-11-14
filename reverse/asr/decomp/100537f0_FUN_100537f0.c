// FUNC 0x100537f0  FUN_100537f0

undefined8
FUN_100537f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_4 == 0) || (param_5 != 0)) {
    uVar2 = param_1;
    puVar1 = (undefined1 *)
             FUN_10056e38(DAT_10053848,8,4,param_4 + 8U & 0xffff,param_1,param_2,param_3);
    *(undefined2 *)(puVar1 + 4) = 4;
    *puVar1 = 0x1b;
    puVar1[1] = (char)param_2;
    *(short *)(puVar1 + 2) = (short)param_1;
    *(short *)(puVar1 + 6) = (short)param_3;
    param_1 = uVar2;
    if (param_5 != 0) {
      FUN_10056de8(puVar1 + 8,param_5,param_4);
      param_1 = uVar2;
    }
    FUN_10056e78(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x340;
  }
  return CONCAT44(param_1,uVar2);
}


