// FUNC 0x10004bf4  FUN_10004bf4

undefined4 FUN_10004bf4(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  FUN_10004bb0();
  iVar2 = DAT_10004c80;
  uVar4 = *(uint *)(*(int *)(DAT_10004c80 + 8) + 4) & 0xfffffffc;
  iVar3 = ((uVar4 - param_2) + DAT_10004c84 >> 0xc) - 1;
  if ((DAT_10004c84 + 0x11 <= iVar3 * 0x1000) &&
     (iVar1 = FUN_10004bd0(param_1,0), iVar1 == *(int *)(iVar2 + 8) + uVar4)) {
    iVar1 = FUN_10004bd0(param_1,iVar3 * -0x1000);
    if (iVar1 != -1) {
      *(uint *)(*(int *)(iVar2 + 8) + 4) = uVar4 + iVar3 * -0x1000 | 1;
      *DAT_10004c88 = *DAT_10004c88 + iVar3 * -0x1000;
      FUN_10004bc0(param_1);
      return 1;
    }
    iVar3 = FUN_10004bd0(param_1,0);
    iVar2 = *(int *)(iVar2 + 8);
    uVar4 = iVar3 - iVar2;
    if (0xf < (int)uVar4) {
      *DAT_10004c88 = iVar3 - *DAT_10004c8c;
      *(uint *)(iVar2 + 4) = uVar4 | 1;
    }
  }
  FUN_10004bc0(param_1);
  return 0;
}


