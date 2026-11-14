// FUNC 0x10051e70  FUN_10051e70

undefined8 FUN_10051e70(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 *puVar4;
  
  if ((param_4 == 0) || (param_5 != 0)) {
    uVar2 = param_1;
    puVar1 = (undefined2 *)FUN_10056e38(0xb00,6,4,(param_4 + 1) * 0x16,param_1,param_2,param_3);
    puVar1[1] = 4;
    *puVar1 = (short)param_1;
    *(char *)(puVar1 + 2) = (char)param_2;
    *(char *)((int)puVar1 + 5) = (char)param_4;
    param_1 = uVar2;
    if (param_3 != 0) {
      FUN_10056de8(puVar1 + 3,param_3,0x10);
      param_1 = uVar2;
    }
    iVar3 = param_5 + param_4 * 0x16;
    puVar4 = puVar1;
    for (; param_5 != iVar3; param_5 = param_5 + 0x16) {
      puVar4[0x13] = *(undefined2 *)(param_5 + 0x10);
      puVar4[0x14] = *(undefined2 *)(param_5 + 0x12);
      puVar4[0x15] = *(undefined2 *)(param_5 + 0x14);
      FUN_10056de8(puVar4 + 0xb,param_5,0x10);
      puVar4 = puVar4 + 0xb;
    }
    FUN_10056e78(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x440;
  }
  return CONCAT44(param_1,uVar2);
}


