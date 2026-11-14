// FUNC 0x10051b04  FUN_10051b04

undefined8 FUN_10051b04(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20 [3];
  
  bVar1 = *DAT_10051b74;
  iVar3 = DAT_10051b78 + 0x57;
  *DAT_10051b74 = bVar1 ^ 1;
  local_20[0] = param_1;
  local_20[1] = param_2;
  local_20[2] = param_3;
  FUN_10056de8(local_20,iVar3,6);
  if ((bVar1 ^ 1) == 0) {
    iVar3 = 0;
    do {
      bVar1 = *(byte *)((int)local_20 + iVar3);
      iVar2 = FUN_10051734(bVar1 >> 4);
      bVar1 = FUN_10051734(bVar1 & 0xf);
      *(byte *)((int)local_20 + iVar3) = bVar1 | (byte)(iVar2 << 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 != 6);
  }
  else {
    iVar3 = 0;
    do {
      bVar1 = *(byte *)((int)local_20 + iVar3);
      iVar2 = FUN_1005187c(bVar1 >> 4);
      bVar1 = FUN_1005187c(bVar1 & 0xf);
      *(byte *)((int)local_20 + iVar3) = bVar1 | (byte)(iVar2 << 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 != 6);
  }
  FUN_100516d8(local_20);
  return CONCAT44(local_20[1],local_20[0]);
}


