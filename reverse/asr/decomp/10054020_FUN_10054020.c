// FUNC 0x10054020  FUN_10054020

undefined8 FUN_10054020(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  FUN_10056e58(0x2d,0,1,0,param_1,param_2,param_3);
  FUN_10056e58(0x2d,0,1);
  FUN_10056e48(0x32);
  uVar2 = *DAT_1005414c;
  uVar3 = *DAT_1005414c;
  uVar5 = *DAT_1005414c;
  uVar7 = *DAT_1005414c;
  *DAT_1005414c = DAT_10054150;
  FUN_10056e48(10);
  if (param_1 == 1) {
    FUN_10053f18(0,4,3,1);
    uVar4 = 3;
    uVar1 = 0x17;
LAB_10054088:
    FUN_10056e58(0x33,uVar1,4,uVar4);
  }
  else if (param_1 == 2) {
    FUN_10053f18(0,4,3);
    uVar4 = 7;
    uVar1 = 0x1b;
    goto LAB_10054088;
  }
  FUN_10056e58(0x2f,0x17,1,0);
  FUN_10056e58(0x2f,0x17,1);
  FUN_10056e48(DAT_10054154);
  FUN_10056e58(0x2f,0x17,1,0);
  uVar6 = *DAT_10054158;
  if (param_1 == 1) {
    uVar1 = FUN_10056d58(64000,uVar6 >> 10);
    FUN_10053f18(6,0x10,8,uVar1);
    FUN_10053f18(6,0x18,5,10);
    FUN_10053f18(6,0,8,uVar7 & 0xff);
    uVar5 = (uVar5 << 0x13) >> 0x1b;
  }
  else {
    if (param_1 != 2) goto LAB_1005413c;
    FUN_10053f18(6,0x10,8,uVar3 >> 0x10 & 0xff);
    FUN_10053f18(6,0x18,5,(uVar2 << 3) >> 0x1b);
    uVar1 = FUN_10056d58(0x1f400,uVar6 >> 10);
    FUN_10053f18(6,0,8,uVar1);
    uVar5 = 10;
  }
  FUN_10053f18(6,8,5,uVar5);
LAB_1005413c:
  FUN_10053f18(0,4,3);
  return CONCAT44(uVar2,uVar3);
}


