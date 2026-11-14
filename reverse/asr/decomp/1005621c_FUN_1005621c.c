// FUNC 0x1005621c  FUN_1005621c

int FUN_1005621c(int param_1,undefined4 param_2,undefined4 param_3)

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
  FUN_100561b6(param_1,param_2,0,&local_24,&local_20,DAT_100562a4,0);
  if (local_20 != 0) {
    FUN_100561b6(param_1,param_2,2,&local_1c,0,DAT_100562a8,1);
  }
  if ((local_24 != 0) && (local_28 == -1)) {
    if ((local_24 < 2) && (*(char *)(param_1 + 0x28) == '\0')) {
      *(char *)(param_1 + 0x28) = '\x01';
    }
    else {
      FUN_100561b6(param_1,param_2,1,&local_1c,0,DAT_100562a8,1);
    }
  }
  return local_28;
}


