// FUNC 0x1005152c  FUN_1005152c

undefined8 FUN_1005152c(undefined4 param_1,undefined3 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  piVar1 = DAT_1005155c;
  uStack_14 = CONCAT13(8,param_2);
  uStack_10 = param_3;
  FUN_100539c0(0x97,(int)&uStack_14 + 3,DAT_1005155c);
  if (*piVar1 != DAT_10051560) {
    *piVar1 = DAT_10051560;
    piVar1[1] = 0;
    FUN_100539ae(0x97,8,piVar1);
  }
  return CONCAT44(uStack_14,param_1);
}


