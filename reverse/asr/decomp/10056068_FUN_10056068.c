// FUNC 0x10056068  FUN_10056068

undefined4 FUN_10056068(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int extraout_r1;
  undefined1 uStack_38;
  undefined1 auStack_37 [3];
  int local_34;
  byte local_30;
  char local_2f;
  int local_20 [3];
  
  FUN_10056f28(&uStack_38,0,8);
  FUN_10056d68(param_2,*(undefined4 *)(param_1 + 8));
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_3 != (undefined1 *)0x0) {
    FUN_10056a4a(param_1,param_2,&uStack_38,8);
    iVar1 = DAT_10056140;
    *(undefined4 *)(param_3 + 4) = param_2;
    *(int *)(param_3 + 8) = local_34;
    if (local_34 == iVar1) {
      *param_3 = 1;
      uVar2 = FUN_10056936(&uStack_38,4);
      param_3[1] = uVar2;
      uVar2 = FUN_10056936(auStack_37,4);
      param_3[2] = uVar2;
      if (param_4 != 0) {
        local_20[0] = *(int *)(param_3 + 4) + 8;
        *(undefined4 *)(param_3 + 0xc) = 0;
        *(int *)(param_3 + 0x10) = local_20[0];
        if (param_3[1] == '\x01') {
          *(int *)(param_3 + 0xc) = *(int *)(param_1 + 8) + -8;
        }
        else if (param_3[1] == '\x02') {
          *(int *)(param_3 + 0xc) = *(int *)(param_1 + 8) + -8;
          do {
            FUN_10055eb6(param_1,&local_30);
            if ((local_2f == '\0') && ((local_30 & 0xfb) != 1)) {
              *(undefined4 *)(param_3 + 0xc) = 0;
              return 2;
            }
            *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 0x94;
            *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + -0x94;
            if (param_3[1] == '\x01') {
              local_20[0] = -1;
            }
            else {
              local_20[0] = FUN_10056000(param_1,param_3,local_20);
            }
          } while (local_20[0] != -1);
        }
      }
      uVar3 = 0;
    }
    else {
      *param_3 = 0;
      uVar3 = 8;
    }
    return uVar3;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


