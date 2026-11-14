// FUNC 0x100481e4  FUN_100481e4

void FUN_100481e4(int param_1,int param_2,int param_3,int param_4)

{
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != 0) {
      param_1 = -1;
      param_2 = param_1;
    }
                    /* WARNING: Could not recover jumptable at 0x10048204. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((int)&DAT_10048208 + DAT_10048208))(param_1,param_2);
    return;
  }
  FUN_10048290(param_1);
  return;
}


