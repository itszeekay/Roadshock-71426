// FUNC 0x100037b0  FUN_100037b0

void FUN_100037b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int extraout_r1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 local_14;
  
  uStack_18 = param_3;
  local_14 = param_4;
  FUN_10004b08(&uStack_18,0,8,param_4,param_1,param_2);
  uVar2 = *(undefined4 *)(param_1 + 8);
  FUN_10000910(param_2,uVar2);
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = FUN_10004230(param_1,param_2,uVar2);
  if (iVar1 == 0) {
    FUN_10004b08(&uStack_18,0xff,8);
    FUN_100042f4(&uStack_18,4,1);
    FUN_100042f4((int)&uStack_18 + 1,4,1);
    local_14 = DAT_10003818;
    FUN_10004242(param_1,param_2,&uStack_18,8,1);
  }
  return;
}


