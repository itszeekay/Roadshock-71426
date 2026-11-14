// FUNC 0x1004d6e0  FUN_1004d6e0

void FUN_1004d6e0(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_2 < 2) {
    if (0xf < param_1) {
      return;
    }
    FUN_1004cb20(0x15,0xe,1);
    FUN_1004cb20(0x15,0x10,1);
    FUN_1004cb20(0x15,0xf,1);
    FUN_1004afa2(1);
    FUN_1004cb20(0x15,0xd,1,0);
    FUN_1004cb20(0x15,0xe,1,0);
    FUN_1004cb20(0x15,0x10,1,0);
    FUN_1004cb20(0x15,0xf,1,0);
    FUN_1004cb20(0x23,0xf,2,3);
    FUN_1004cb20(2,0xc,1);
    if (param_2 == 0) {
      FUN_1004cb20(0x23,0x1c,1,0);
      FUN_1004cb20(0x23,0x15,4,param_1);
      if (param_1 != 0xf) {
        FUN_1004d1e0();
        return;
      }
      iVar1 = FUN_1004cb54(3,0x1c,1);
      if (iVar1 != 1) {
        FUN_1004d1e0();
        FUN_1004cb20(0x23,0,1);
        uVar5 = 1;
        uVar3 = 0xc;
        uVar4 = 1;
        uVar2 = 2;
        goto LAB_1004d9d8;
      }
      FUN_1004cb20(2,0xc,1,0);
      FUN_1004cb20(0x15,0xd,4,0);
      FUN_1004cb20(0x23,0x1c,1,0);
      FUN_1004cb20(0x23,0x19,3,1);
      FUN_1004cb20(0x23,0x15,4,0xf);
      FUN_1004cb20(0x23,10,1,0);
      FUN_1004cb20(0x23,0,1,1);
      FUN_1004cb20(0x23,0x1d,1,1);
      FUN_1004cb20(0x32,0xd,4);
      uVar3 = 9;
      uVar4 = 1;
      uVar5 = 1;
    }
    else {
      FUN_1004cb20(0x23,0x1c,1);
      uVar5 = 3;
      uVar4 = 2;
      uVar3 = 0xf;
    }
    uVar2 = 0x23;
  }
  else {
    mic_pins_config(4);
    FUN_1004cb20(0x17,0xb,1);
    FUN_1004cb20(0x17,0x16,1,0);
    if (param_2 == 2) {
      FUN_1004d376();
      FUN_1004cb20(0x15,0x19,1,0);
      FUN_1004cb20(0x15,0x17,1,0);
      FUN_1004cb20(0x15,0x11,2,0);
      FUN_1004cb20(0x15,0x14,1,0);
      FUN_1004cb20(0x15,0x15,1,0);
      FUN_1004cb20(0x15,0x18,1,0);
      FUN_1004cb20(0x15,9,1);
      FUN_1004cb20(0x15,9,1,0);
      FUN_1004cb00(0x20,DAT_1004d9e0);
      FUN_1004cb00(0x21,DAT_1004d9e4);
      FUN_1004cb20(0x21,4,3,5);
      FUN_1004cb20(0x20,0x12,2,1);
      FUN_1004afa2(600);
    }
    else {
      if (param_2 != 3) {
        return;
      }
      FUN_1004cb20(0x15,0xd,1,0);
      FUN_1004cb20(0x20,0x1c,4,0xb);
      FUN_1004cb20(0x15,0x19,7,0);
      FUN_1004cb20(0x15,0x17,1,0);
      FUN_1004cb20(0x15,0xb,2,3);
      FUN_1004cb20(0x15,0xb,1,0);
      FUN_1004cb20(0x15,0xc,1,0);
      FUN_1004afa2(DAT_1004d9e8);
      FUN_1004cb20(0x15,0x11,2,0);
      FUN_1004cb20(0x15,0x14,1,0);
      FUN_1004cb20(0x15,0x15,2,0);
      FUN_1004cb20(0x15,0x18,1,0);
      FUN_1004cb20(0x15,9,1);
      FUN_1004cb20(0x15,9,1,0);
      FUN_1004cb00(0x20,DAT_1004d9e0);
      FUN_1004cb00(0x21,DAT_1004d9ec);
      FUN_1004cb20(0x21,4,3,5);
      FUN_1004cb20(0x20,0x12,2,1);
      FUN_1004afa2(600);
    }
    uVar5 = 3;
    uVar4 = 2;
    uVar3 = 0x12;
    uVar2 = 0x20;
  }
LAB_1004d9d8:
  FUN_1004cb20(uVar2,uVar3,uVar4,uVar5);
  return;
}


