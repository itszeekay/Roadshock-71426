// FUNC 0x1004d4b4  FUN_1004d4b4

void FUN_1004d4b4(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int unaff_r5;
  
  if (param_1 < 0xe) {
    FUN_10056ee8();
    *(ushort *)(param_4 + unaff_r5) = (ushort)param_4 | 0x24;
    FUN_1004cb20(0x22,0x11,1);
    FUN_1004cb20(0x22,0xb,3,0);
    FUN_1004cb20(0x20,0x1a,1,0);
  }
  return;
}


