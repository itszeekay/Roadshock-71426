// FUNC 0x10053f64  FUN_10053f64

void FUN_10053f64(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((code *)*DAT_10054014 != (code *)0x0) {
    (*(code *)*DAT_10054014)();
    return;
  }
  FUN_10056e58(0x17,0x12,1,0);
  FUN_10056e58(0x1e,0x11,4,7);
  FUN_10056e58(0x15,0x1a,3,0);
  FUN_10056e58(0x15,10,1);
  uVar3 = *DAT_10054018;
  if ((uVar3 & 9) != 0) goto LAB_10053ff8;
  if ((uVar3 & 2) == 0) {
    if ((int)(uVar3 << 0x1d) < 0) {
LAB_10053fee:
      uVar5 = 0;
      uVar2 = 1;
    }
    else {
      if ((uVar3 & 0x20) == 0) {
        if (-1 < (int)(uVar3 << 0x1b)) goto LAB_10053ff8;
        FUN_10056e58(0x1d,0xb,1);
        goto LAB_10053fee;
      }
      uVar5 = 1;
      uVar2 = 0xb;
    }
    uVar4 = 1;
    uVar1 = 0x1d;
  }
  else {
    FUN_10056e58(0x1e,1,1);
    uVar5 = 1;
    uVar4 = 2;
    uVar2 = 0x1a;
    uVar1 = 0x1f;
  }
  FUN_10056e58(uVar1,uVar2,uVar4,uVar5);
LAB_10053ff8:
  FUN_10056e48(100);
  FUN_10056e58(0x15,10,1,0);
  do {
  } while (-1 < *DAT_1005401c);
  return;
}


