// FUNC 0x1005659e  FUN_1005659e

undefined4 FUN_1005659e(char *param_1,undefined4 param_2)

{
  undefined1 auStack_2c [4];
  byte local_28;
  char local_27;
  int local_18 [2];
  
  if ((*param_1 != '\0') && ((byte)param_1[2] - 2 < 2)) {
    FUN_10056960(param_2,*(int *)(param_1 + 4) + 1,auStack_2c,4,3,1);
    local_18[0] = *(int *)(param_1 + 4) + 8;
    do {
      FUN_10055eb6(param_2,&local_28);
      if ((local_27 != '\0') && (local_28 - 2 < 2)) {
        FUN_10056486(param_2,&local_28);
      }
      if (param_1[1] == '\x01') {
        local_18[0] = -1;
      }
      else {
        local_18[0] = FUN_10056000(param_2,param_1,local_18);
      }
    } while (local_18[0] != -1);
    FUN_10055f3c(param_2,*(undefined4 *)(param_1 + 4));
  }
  return 0;
}


