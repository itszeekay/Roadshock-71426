// FUNC 0x1004cf6c  FUN_1004cf6c

void FUN_1004cf6c(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  
  iVar2 = FUN_10056d58(*DAT_1004d0dc,*(undefined4 *)(param_1 + 8),param_3,DAT_1004d0dc,param_4);
  uVar3 = FUN_10048b58(0x3f800000,*(undefined4 *)(param_1 + 4));
  uVar4 = FUN_10048f38(iVar2);
  FUN_10048930(uVar3,uVar4);
  uVar8 = FUN_1004ab50();
  uVar8 = FUN_10048fb4((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,DAT_1004d0e0);
  FUN_1004a348((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,DAT_1004d0e4);
  uVar1 = FUN_10048254();
  iVar7 = DAT_1004d0e8;
  uVar6 = (uint)uVar1;
  if (*param_1 < 0xc) {
    *(undefined4 *)(DAT_1004d0e8 + 0x34) = *(undefined4 *)(DAT_1004d0e8 + 0x34);
    iVar5 = FUN_10056ee8();
    param_1 = param_1 + iVar5;
    param_1[0] = 0x1d;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    *(uint *)(iVar7 + 0x38) = iVar2 - 0x33U | *(uint *)(iVar7 + 0x38) & 0xffff0000;
    *(uint *)(iVar7 + 0x50) = *(uint *)(iVar7 + 0x50) & 0xffff0000 | uVar6;
    *(undefined4 *)(iVar7 + 0x68) = 0;
  }
  return;
}


