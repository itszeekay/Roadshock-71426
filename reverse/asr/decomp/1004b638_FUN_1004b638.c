// FUNC 0x1004b638  FUN_1004b638

int FUN_1004b638(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                uint param_6,int param_7,uint param_8,uint param_9)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  int local_4c;
  undefined4 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar1 = FUN_10048188(param_5,param_6,param_5,param_6);
  if (((iVar1 == 0) || (iVar1 = FUN_100481bc(param_5,param_6,0xffffffff,DAT_1004b978), iVar1 != 0))
     || (iVar1 = FUN_10048194(param_5,param_6,0xffffffff,DAT_1004b97c), iVar1 != 0)) {
    iVar1 = FUN_1004b338(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  else {
    iVar1 = FUN_10048194(param_5,param_6,0,0);
    uVar7 = param_6;
    if (iVar1 != 0) {
      uVar7 = param_6 + 0x80000000;
    }
    uVar13 = CONCAT44(uVar7,param_5);
    if ((param_9 & 0x400) == 0) {
      param_7 = 6;
    }
    uVar10 = FUN_1004aa5c(((uVar7 << 1) >> 0x15) + DAT_1004b980);
    uVar10 = FUN_10049e54((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_1004b984,DAT_1004b988);
    uVar10 = FUN_10048fb4((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_1004b98c,DAT_1004b990);
    uVar11 = FUN_1004a348(param_5,DAT_1004b994 | uVar7 & 0xfffff,0,DAT_1004b998);
    uVar11 = FUN_10049e54((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_1004b99c,DAT_1004b9a0);
    FUN_10048fb4((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                 (int)((ulonglong)uVar11 >> 0x20));
    uVar2 = FUN_1004a9f0();
    uVar10 = FUN_1004aa5c();
    uVar4 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar11 = FUN_10049e54((int)uVar10,uVar4,DAT_1004b9a4,DAT_1004b9a8);
    FUN_10048fb4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_1004b9ac);
    iVar1 = FUN_1004a9f0();
    uVar10 = FUN_10049e54((int)uVar10,uVar4,DAT_1004b9b0,DAT_1004b9b4);
    uVar11 = FUN_1004aa5c(iVar1);
    uVar11 = FUN_10049e54((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_1004b9b8,DAT_1004b9bc);
    uVar10 = FUN_1004a348((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                          (int)((ulonglong)uVar11 >> 0x20));
    uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar4 = (undefined4)uVar10;
    uVar10 = FUN_10049e54(uVar4,uVar5,uVar4,uVar5);
    uVar6 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar3 = (undefined4)uVar10;
    uVar10 = FUN_10048fb4(uVar4,uVar5);
    uVar11 = FUN_1004960c(uVar3,uVar6,0,DAT_1004b9c0);
    uVar11 = FUN_10048fb4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_1004b9c4);
    uVar11 = FUN_1004960c(uVar3,uVar6,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
    uVar11 = FUN_10048fb4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_1004b9c8);
    uVar11 = FUN_1004960c(uVar3,uVar6,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
    uVar12 = FUN_1004a348(0,0x40000000,uVar4,uVar5);
    uVar11 = FUN_10048fb4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                          (int)((ulonglong)uVar12 >> 0x20));
    uVar10 = FUN_1004960c((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                          (int)((ulonglong)uVar11 >> 0x20));
    uVar10 = FUN_10048fb4((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,DAT_1004b994);
    uVar10 = FUN_10049e54((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,
                          (iVar1 + DAT_1004b9cc) * 0x100000);
    uVar4 = (undefined4)((ulonglong)uVar10 >> 0x20);
    iVar1 = FUN_10048194(param_5,uVar7,(int)uVar10,uVar4);
    if (iVar1 != 0) {
      uVar10 = FUN_1004960c((int)uVar10,uVar4,0,DAT_1004b9c4);
      uVar2 = uVar2 - 1;
    }
    local_2c = (undefined4)((ulonglong)uVar10 >> 0x20);
    local_30 = (undefined4)uVar10;
    uVar8 = 5 - (uVar2 + 99 < 199);
    if ((int)(param_9 << 0x14) < 0) {
      iVar1 = FUN_100481d0(param_5,uVar7,DAT_1004b9d0,DAT_1004b9d4);
      if ((iVar1 == 0) || (iVar1 = FUN_10048194(param_5,uVar7,0,DAT_1004b9d8), iVar1 == 0)) {
        if (param_7 != 0) {
          param_7 = param_7 - (uint)((param_9 & 0x400) != 0);
        }
      }
      else {
        if ((int)uVar2 < param_7) {
          param_7 = (param_7 - uVar2) + -1;
        }
        else {
          param_7 = 0;
        }
        uVar8 = 0;
        param_9 = param_9 | 0x400;
        uVar2 = 0;
      }
    }
    uVar9 = 0;
    if (uVar8 < param_8) {
      uVar9 = param_8 - uVar8;
    }
    if ((param_9 & 2) != 0) {
      uVar9 = uVar9 & -(uint)(uVar8 == 0);
    }
    if (uVar2 != 0) {
      uVar13 = FUN_1004960c(param_5,uVar7,local_30,local_2c);
    }
    local_4c = (int)((ulonglong)uVar13 >> 0x20);
    local_40 = (undefined4)uVar13;
    iVar1 = FUN_10048194(param_5,param_6,0,0);
    if (iVar1 != 0) {
      local_4c = local_4c + -0x80000000;
    }
    iVar1 = FUN_1004b338(param_1,param_2,param_3,param_4,local_40,local_4c,param_7,uVar9,
                         DAT_1004b9dc & param_9);
    if (uVar8 != 0) {
      uVar4 = 0x45;
      if (-1 < (int)(param_9 << 0x1a)) {
        uVar4 = 0x65;
      }
      (*param_1)(uVar4,param_2,iVar1,param_4);
      iVar1 = FUN_1004b184(param_1,param_2,iVar1 + 1,param_4,
                           uVar2 + ((int)uVar2 >> 0x1f) ^ (int)uVar2 >> 0x1f,uVar2 >> 0x1f,10,0,
                           uVar8 - 1,5);
      if ((param_9 & 2) != 0) {
        for (; (uint)(iVar1 - param_3) < param_8; iVar1 = iVar1 + 1) {
          (*param_1)(0x20,param_2,iVar1,param_4);
        }
      }
    }
  }
  return iVar1;
}


