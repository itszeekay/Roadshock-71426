// FUNC 0x100521b8  FUN_100521b8

undefined8 FUN_100521b8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  short sVar2;
  
  sVar2 = *(short *)(DAT_100521d4 + 4) + 1;
  *(short *)(DAT_100521d4 + 4) = sVar2;
  uVar1 = FUN_10052166(param_1,sVar2,param_2,param_3,param_4,param_2);
  return CONCAT44(param_4,(uint)uVar1);
}


