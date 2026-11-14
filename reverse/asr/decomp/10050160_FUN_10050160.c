// FUNC 0x10050160  FUN_10050160

void FUN_10050160(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  if (param_2 == 0) {
    pbVar3 = (byte *)(DAT_100501f8 + (param_1 >> 1) + 0x57);
    if ((param_1 & 1) != 0) {
      bVar2 = *pbVar3 & 0xf0 | 1;
      goto LAB_100501f4;
    }
    bVar2 = *pbVar3 & 0xf;
    bVar1 = 0x10;
  }
  else if (param_2 == 1) {
    pbVar3 = (byte *)(DAT_100501f8 + (param_1 >> 1) + 0x57);
    if ((param_1 & 1) == 0) {
      bVar2 = *pbVar3 & 0xf;
      bVar1 = 0x20;
    }
    else {
      bVar2 = *pbVar3 & 0xf0;
      bVar1 = 2;
    }
  }
  else if (param_2 == 2) {
    pbVar3 = (byte *)(DAT_100501f8 + (param_1 >> 1) + 0x57);
    if ((int)(param_1 << 0x1f) < 0) {
      bVar2 = *pbVar3 & 0xf0;
      bVar1 = 5;
    }
    else {
      bVar2 = *pbVar3 & 0xf;
      bVar1 = 0x50;
    }
  }
  else {
    if (param_2 != 3) {
      return;
    }
    pbVar3 = (byte *)(DAT_100501f8 + (param_1 >> 1) + 0x57);
    if ((int)(param_1 << 0x1f) < 0) {
      bVar2 = *pbVar3 & 0xf0;
      bVar1 = 7;
    }
    else {
      bVar2 = *pbVar3 & 0xf;
      bVar1 = 0x70;
    }
  }
  bVar2 = bVar2 | bVar1;
LAB_100501f4:
  *pbVar3 = bVar2;
  return;
}


