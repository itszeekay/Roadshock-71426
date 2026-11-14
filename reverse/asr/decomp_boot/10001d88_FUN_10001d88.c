// FUNC 0x10001d88  FUN_10001d88

void FUN_10001d88(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int local_120;
  int local_11c;
  undefined1 auStack_118 [260];
  
  uVar2 = DAT_10001ec4;
  if (*(int *)(param_1 + 0x40) == 1) {
LAB_10001ebc:
    FUN_100014a0(uVar2);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x44);
    if (uVar4 - 2 < 2) {
      FUN_100014a0(DAT_10001ec8);
      uVar2 = DAT_10001ecc;
      if (*(int *)(param_1 + 0x44) == 3) {
        FUN_10001bb4(DAT_10001ed0,*(undefined4 *)(param_1 + 0x5c));
        FUN_100014a0(uVar2);
        FUN_100014a0(DAT_10001ed4);
        iVar1 = FUN_10002030(*(undefined4 *)(param_1 + 0x48),DAT_10001ed0,
                             *(undefined4 *)(param_1 + 0x5c));
        if (iVar1 != 0) {
          FUN_100014a0(DAT_10001ed8);
          DataSynchronizationBarrier(0xf);
          *(undefined4 *)(DAT_10001edc + 0xc) = DAT_10001ee0;
          DataSynchronizationBarrier(0xf);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
      }
      else {
        FUN_10001bb4(DAT_10001ed0,*(undefined4 *)(param_1 + 0x5c));
        FUN_100014a0(uVar2);
        FUN_100014a0(DAT_10001ee4);
        local_120 = *(int *)(param_1 + 0x48);
        uVar4 = *(uint *)(param_1 + 0x5c);
        local_11c = DAT_10001ed0;
        for (; uVar4 != 0; uVar4 = uVar4 - uVar3) {
          uVar3 = 0x100;
          if (uVar4 < 0x100) {
            uVar3 = uVar4;
          }
          FUN_100049ac(auStack_118,local_120,uVar3);
          FUN_10001c70(local_11c,auStack_118,uVar3);
          local_120 = local_120 + uVar3;
          local_11c = local_11c + uVar3;
        }
      }
      uVar4 = FUN_10001b54(DAT_10001ed0,*(undefined4 *)(param_1 + 0x5c));
      if ((*(uint *)(param_1 + 0x60) & 0xffff) != uVar4) {
        FUN_100014a0(DAT_10001ef0);
        DataSynchronizationBarrier(0xf);
        *(undefined4 *)(DAT_10001edc + 0xc) = DAT_10001ee0;
        DataSynchronizationBarrier(0xf);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      FUN_100014a0(DAT_10001ee8);
      uVar4 = 0;
      uVar3 = *(uint *)(param_1 + 0x48);
      *param_2 = 0;
      param_2[2] = uVar3;
      param_2[3] = *(uint *)(param_1 + 0x5c);
LAB_10001e28:
      param_2[1] = uVar4;
    }
    else {
      uVar2 = DAT_10001efc;
      if (1 < uVar4) goto LAB_10001ebc;
      *param_2 = uVar4;
      param_2[2] = *(uint *)(param_1 + 0x48);
      param_2[3] = *(uint *)(param_1 + 0x5c);
      param_2[1] = 0;
      param_2[4] = 0;
      if (*(int *)(param_1 + 0x68) == DAT_10001ef4) {
        FUN_100014a0(DAT_10001ef8);
        uVar4 = *(uint *)(param_1 + 0x68);
        goto LAB_10001e28;
      }
    }
    uVar3 = *(uint *)(param_1 + 100);
    uVar4 = *(uint *)(param_1 + 0x4c);
    param_2[4] = uVar3;
    param_2[5] = uVar4;
    param_2[6] = *(uint *)(param_1 + 0x50);
    FUN_100014a0(DAT_10001eec,*param_2,param_2[2],param_2[3],param_2[1],uVar3);
    FUN_10001b94(param_2);
  }
  return;
}


