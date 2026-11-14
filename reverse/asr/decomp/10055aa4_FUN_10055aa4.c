// FUNC 0x10055aa4  FUN_10055aa4

uint FUN_10055aa4(uint param_1,uint param_2)

{
  param_2 = param_2 | 0x100;
  do {
    param_2 = param_2 << 1;
    param_1 = param_1 * 2 + (uint)((param_2 & 0x100) != 0);
    if ((param_1 & 0x10000) != 0) {
      param_1 = param_1 ^ DAT_10055ad0;
    }
  } while ((param_2 & 0x10000) == 0);
  return param_1 & 0xffff;
}


