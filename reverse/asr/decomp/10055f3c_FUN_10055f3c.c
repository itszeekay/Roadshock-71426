// FUNC 0x10055f3c  FUN_10055f3c

void FUN_10055f3c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int extraout_r1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 local_14;
  
  uStack_18 = param_3;
  local_14 = param_4;
  FUN_10056f28(&uStack_18,0,8,param_4,param_1,param_2);
  uVar2 = *(undefined4 *)(param_1 + 8);
  FUN_10056d68(param_2,uVar2);
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = FUN_10056a5c(param_1,param_2,uVar2);
  if (iVar1 == 0) {
    FUN_10056f28(&uStack_18,0xff,8);
    FUN_10056910(&uStack_18,4,1);
    FUN_10056910((int)&uStack_18 + 1,4,1);
    local_14 = DAT_10055fa4;
    FUN_10056a6e(param_1,param_2,&uStack_18,8,1);
  }
  return;
}


