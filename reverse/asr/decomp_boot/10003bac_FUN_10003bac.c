// FUNC 0x10003bac  FUN_10003bac

int FUN_10003bac(int param_1,undefined4 param_2,undefined4 param_3)

{
  int local_28;
  uint local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int *local_14;
  
  local_28 = -1;
  local_14 = &local_28;
  local_24 = 0;
  local_20 = 0;
  local_1c = param_1;
  local_18 = param_3;
  FUN_10003b4c(param_1,param_2,0,&local_24,&local_20,DAT_10003c34,0);
  if (local_20 != 0) {
    FUN_10003b4c(param_1,param_2,2,&local_1c,0,DAT_10003c38,1);
  }
  if ((local_24 != 0) && (local_28 == -1)) {
    if ((local_24 < 2) && (*(char *)(param_1 + 0x28) == '\0')) {
      *(char *)(param_1 + 0x28) = '\x01';
    }
    else {
      FUN_10003b4c(param_1,param_2,1,&local_1c,0,DAT_10003c38,1);
    }
  }
  return local_28;
}


