// FUNC 0x10000934  FUN_10000934

void FUN_10000934(int param_1,int param_2,int param_3,int param_4)

{
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != 0) {
      param_1 = -1;
      param_2 = param_1;
    }
                    /* WARNING: Could not recover jumptable at 0x10000954. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((int)&DAT_10000958 + DAT_10000958))(param_1,param_2);
    return;
  }
  FUN_10000974(param_1);
  return;
}


