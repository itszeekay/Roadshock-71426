// FUNC 0x10002094  FUN_10002094

uint FUN_10002094(byte *param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  
  param_3 = ~param_3;
  pbVar1 = param_1 + param_2;
  for (; param_1 != pbVar1; param_1 = param_1 + 1) {
    param_3 = param_3 >> 8 ^ *(uint *)(((uint)*param_1 ^ param_3 & 0xff) * 4 + DAT_100020bc);
  }
  return ~param_3;
}


