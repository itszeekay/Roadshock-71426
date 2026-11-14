// FUNC 0x1004ffe0  FUN_1004ffe0

void FUN_1004ffe0(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte local_24;
  byte local_20 [4];
  undefined1 local_1c;
  undefined1 local_1b;
  
  FUN_10056de8(local_20,DAT_10050158,6);
  iVar3 = DAT_1005015c;
  uVar5 = param_1 - 1U & 0xff;
  *(undefined1 *)(DAT_1005015c + 0x5d) = 0;
  uVar6 = uVar5 >> 1;
  if ((int)(uVar5 << 0x1f) < 0) {
    bVar1 = *(byte *)(iVar3 + uVar6 + 0x57);
    uVar5 = bVar1 & 0xf;
    if (1 < uVar5 - 2) {
      FUN_10056de8(local_20,iVar3 + 0x57,6);
    }
    if (param_2 == 1) {
      bVar2 = 1;
      if (((bVar1 & 0xf) != 0) && (bVar2 = 0, uVar5 != 1)) {
        local_24 = (byte)(uVar5 - 2);
        bVar2 = 3;
        if ((((1 < local_24) && ((bVar2 = 5, uVar5 != 4 && (bVar2 = 4, uVar5 != 5)))) &&
            (bVar2 = 7, uVar5 != 6)) && (bVar2 = 6, uVar5 != 7)) {
          bVar2 = 8;
        }
      }
      local_20[uVar6] = bVar2 | local_20[uVar6] & 0xf0;
    }
    else {
      if (param_2 != 3) {
        return;
      }
      if (1 < (*(byte *)(DAT_1005015c + uVar6 + 0x57) & 0xf) - 2) {
        return;
      }
      local_20[uVar6] = local_20[uVar6] & 0xf0 | 2;
    }
    uVar5 = local_20[uVar6] & 0xf;
  }
  else {
    uVar4 = (uint)(*(byte *)(iVar3 + uVar6 + 0x57) >> 4);
    if (1 < uVar4 - 2) {
      FUN_10056de8(local_20,iVar3 + 0x57,6);
    }
    if (param_2 == 1) {
      iVar3 = 1;
      if ((uVar4 != 0) && (iVar3 = 0, uVar4 != 1)) {
        local_24 = (byte)(uVar4 - 2);
        iVar3 = 3;
        if ((1 < local_24) &&
           ((((iVar3 = 5, uVar4 != 4 && (iVar3 = 4, uVar4 != 5)) && (iVar3 = 7, uVar4 != 6)) &&
            (iVar3 = 6, uVar4 != 7)))) {
          iVar3 = 8;
        }
      }
      local_20[uVar6] = (byte)(iVar3 << 4) | local_20[uVar6] & 0xf;
    }
    else {
      if (param_2 != 3) {
        return;
      }
      uVar6 = uVar5 >> 1;
      if (1 < (*(byte *)(DAT_1005015c + uVar6 + 0x57) >> 4) - 2) {
        return;
      }
      local_20[uVar6] = local_20[uVar6] & 0xf | 0x20;
    }
    uVar5 = (uint)(local_20[uVar5 >> 1] >> 4);
  }
  if (uVar5 - 2 < 2) {
    FUN_100519ec(param_1,uVar5,local_20);
  }
  else {
    FUN_1005189c(param_1,uVar5,local_20);
  }
  FUN_1004fd78(local_20[0],local_20[1],local_20[2],local_20[3],local_1c,local_1b);
  return;
}


