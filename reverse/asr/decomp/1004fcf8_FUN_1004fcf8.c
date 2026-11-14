// FUNC 0x1004fcf8  FUN_1004fcf8

void FUN_1004fcf8(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined4 param_5,byte param_6)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = DAT_1004fd74;
  uVar5 = (uint)param_6;
  uVar4 = (uint)*DAT_1004fd70;
  while( true ) {
    if (0x13 < uVar4) {
      return;
    }
    iVar2 = uVar4 * 0x26;
    if (*(char *)(iVar2 + DAT_1004fd74) == '\0') break;
    uVar4 = uVar4 + 1 & 0xff;
    if (uVar4 == 0x14) {
      uVar4 = 0;
    }
    if (uVar4 == *DAT_1004fd70) {
      return;
    }
  }
  *(undefined1 *)(DAT_1004fd74 + iVar2) = 1;
  iVar3 = iVar3 + iVar2;
  *(undefined2 *)(iVar3 + 2) = 0;
  *(undefined1 *)(iVar3 + 6) = param_2;
  *(undefined1 *)(iVar3 + 4) = param_4;
  *(undefined1 *)(iVar3 + 5) = param_1;
  *(undefined1 *)(iVar3 + 7) = param_3;
  FUN_10056de8(iVar3 + 8,param_5,uVar5);
  uVar1 = FUN_1004f814(iVar3 + 5,uVar5 + 3 & 0xff);
  *(undefined1 *)(iVar3 + uVar5 + 8) = uVar1;
  *(byte *)(iVar3 + 0x25) = param_6 + 4;
  return;
}


