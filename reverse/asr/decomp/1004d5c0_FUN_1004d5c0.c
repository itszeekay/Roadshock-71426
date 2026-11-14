// FUNC 0x1004d5c0  FUN_1004d5c0

ulonglong FUN_1004d5c0(int param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint local_20;
  
  iVar1 = DAT_1004d674;
  if (0x10 < param_2) {
    param_2 = 0;
  }
  *(uint *)(DAT_1004d674 + 8) = param_2;
  local_20 = 0;
  uVar4 = 0;
  while ((uVar4 & 0xff) < param_2) {
    FUN_1004c918(*(undefined1 *)(param_1 + uVar4),3);
    puVar2 = DAT_1004d678;
    uVar3 = (uint)*(byte *)(param_1 + uVar4);
    if (uVar3 < 0x10) {
      *(int *)(DAT_1004d67c + 0x14) = 1 << uVar3;
      *puVar2 = *puVar2 & ~(1 << *(sbyte *)(param_1 + uVar4));
      *DAT_1004d680 = 3 << ((*(byte *)(param_1 + uVar4) & 0x7f) << 1) | *DAT_1004d680;
    }
    else {
      *(int *)(DAT_1004d684 + 0x14) = 1 << (uVar3 - 0x10 & 0xff);
      *puVar2 = *puVar2 | 1 << *(sbyte *)(param_1 + uVar4);
      *DAT_1004d688 = 3 << ((*(byte *)(param_1 + uVar4) - 0x10) * 2 & 0xff) | *DAT_1004d688;
    }
    if (*(byte *)(param_1 + uVar4) < 0xe) {
      local_20 = (uint)(byte)(*(byte *)(param_1 + uVar4) - 6);
    }
    uVar3 = uVar4 + 1;
    if ((uVar4 & 0xff) < 7) {
      *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | local_20 << (uVar3 * 4 & 0xff);
      uVar4 = uVar3;
    }
    else {
      *(uint *)(iVar1 + 0xc) =
           *(uint *)(iVar1 + 0xc) | local_20 << ((uVar4 + DAT_1004d68c) * 4 & 0xff);
      uVar4 = uVar3;
    }
  }
  return CONCAT44(uVar4,local_20) & 0xffffffffff;
}


