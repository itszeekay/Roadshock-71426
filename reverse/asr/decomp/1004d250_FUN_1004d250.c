// FUNC 0x1004d250  FUN_1004d250

void FUN_1004d250(int param_1,uint param_2)

{
  if (param_1 == 2) {
    if (7 < param_2) {
      return;
    }
    if (param_2 - 1 < 7) {
      FUN_10056ee8();
    }
    FUN_1004cb20(0x21,8,1,0);
    FUN_1004cb20(0x21,0x13,1,0);
  }
  else {
    if (param_1 != 3) {
      return;
    }
    if (param_2 < 8) {
      return;
    }
    if (7 < param_2 - 8) {
      return;
    }
    FUN_10056ee8(param_2 - 8,8,1,0);
    FUN_1004cb20(0x21);
    FUN_1004cb20(0x21,0x13,1);
  }
  FUN_1004cb20(0x21,9,2,0);
  return;
}


