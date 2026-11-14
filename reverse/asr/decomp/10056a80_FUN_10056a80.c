// FUNC 0x10056a80  FUN_10056a80

undefined4 FUN_10056a80(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int extraout_r1;
  int iVar3;
  
  iVar1 = DAT_10056ae8;
  if (param_1 == (int *)0x0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((char)param_1[4] == '\0') {
    *param_1 = param_2;
    param_1[7] = iVar1;
    param_1[8] = DAT_10056aec;
    param_1[9] = DAT_10056af0;
    iVar1 = FUN_1004c7ac(param_3);
    *(char *)(param_1 + 1) = (char)iVar1;
    if (iVar1 == -1) {
      return 4;
    }
    param_1[2] = 0x1000;
    iVar1 = FUN_1004c79c();
    iVar3 = *(int *)(iVar1 + 0xc);
    param_1[3] = iVar3;
    iVar1 = param_1[2];
    FUN_10056d68(iVar3,iVar1);
    if (extraout_r1 != 0) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uVar2 = FUN_10056d58(iVar3,iVar1);
    if (uVar2 < 2) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  return 0;
}


