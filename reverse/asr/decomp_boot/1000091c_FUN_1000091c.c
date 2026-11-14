// FUNC 0x1000091c  FUN_1000091c

undefined8 FUN_1000091c(uint param_1,int param_2,uint param_3)

{
  return CONCAT44(param_2 << (param_3 & 0xff) | param_1 << (param_3 - 0x20 & 0xff) |
                  param_1 >> (-(param_3 - 0x20) & 0xff),param_1 << (param_3 & 0xff));
}


