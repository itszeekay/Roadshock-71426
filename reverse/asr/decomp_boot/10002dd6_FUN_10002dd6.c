// FUNC 0x10002dd6  FUN_10002dd6

undefined8 FUN_10002dd6(int param_1,int param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  while( true ) {
    uVar3 = *param_3;
    if (param_4 <= uVar3) {
      uVar2 = 0;
      goto LAB_10002e2c;
    }
    iVar4 = *(int *)(param_1 + 4);
    bVar1 = *(byte *)(param_2 + uVar3);
    *param_3 = uVar3 + 1;
    uVar5 = FUN_1000091c(bVar1 & 0x7f,0,iVar4);
    *(uint *)(param_1 + 8) = (uint)uVar5 | *(uint *)(param_1 + 8);
    *(uint *)(param_1 + 0xc) = (uint)((ulonglong)uVar5 >> 0x20) | *(uint *)(param_1 + 0xc);
    if (-1 < (char)bVar1) break;
    *(int *)(param_1 + 4) = iVar4 + 7;
    if (iVar4 + 7 == 0x3f) {
LAB_10002e2a:
      uVar2 = 7;
LAB_10002e2c:
      return CONCAT44(param_2,uVar2);
    }
  }
  if ((bVar1 != 0) || (iVar4 == 0)) {
    uVar2 = 1;
    *(undefined4 *)(param_1 + 4) = 0;
    goto LAB_10002e2c;
  }
  goto LAB_10002e2a;
}


