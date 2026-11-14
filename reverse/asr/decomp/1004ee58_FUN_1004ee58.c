// FUNC 0x1004ee58  FUN_1004ee58

void FUN_1004ee58(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  
  if (param_2 == 4) {
    if (*DAT_1004eea4 == '\0') {
      return;
    }
    sVar1 = *DAT_1004eea8 + 4;
  }
  else if (param_2 == 9) {
    if (*DAT_1004eeac == '\0') {
      return;
    }
    sVar1 = *DAT_1004eea8 + 9;
  }
  else {
    if (param_2 != 0xe) {
      return;
    }
    if (*DAT_1004eeb0 == '\0') {
      return;
    }
    sVar1 = *DAT_1004eea8 + 0xe;
  }
  FUN_100521b8(param_1,sVar1,param_4,param_3);
  return;
}


