// FUNC 0x1004cb54  FUN_1004cb54

uint FUN_1004cb54(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (((param_1 == 0xff) || (0x1f < param_2)) || (0x20 < param_3)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = ((1 << (param_3 & 0xff)) + -1 << (param_2 & 0xff) &
            *(uint *)(param_1 * 4 + DAT_1004cb7c)) >> (param_2 & 0xff);
  }
  return uVar1;
}


