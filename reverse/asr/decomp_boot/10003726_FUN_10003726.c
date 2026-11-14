// FUNC 0x10003726  FUN_10003726

undefined4 FUN_10003726(undefined4 param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_4c [8];
  int local_44;
  uint local_40;
  undefined2 local_3c;
  undefined1 auStack_38 [36];
  
  FUN_1000421e(param_1,*(undefined4 *)(param_2 + 8),auStack_4c,0x14);
  uVar1 = FUN_10004318(auStack_4c,6);
  *(undefined1 *)param_2 = uVar1;
  if (local_40 < 0x81) {
    uVar3 = 0;
    iVar4 = 0;
    *(uint *)(param_2 + 4) = local_40;
    uVar2 = local_40 + 8;
    do {
      iVar5 = 0x20;
      if (uVar2 <= uVar3 + 0x20) {
        iVar5 = uVar2 - uVar3;
      }
      FUN_1000421e(param_1,*(int *)(param_2 + 8) + 0xc + uVar3,auStack_38,iVar5);
      iVar4 = FUN_100042c0(iVar4,auStack_38,iVar5);
      uVar3 = uVar3 + iVar5;
    } while (uVar3 < uVar2);
    if (local_44 == iVar4) {
      *(undefined1 *)((int)param_2 + 1) = 1;
      param_2[6] = local_3c;
      *(int *)(param_2 + 10) = *(int *)(param_2 + 8) + 0x14;
      return 0;
    }
    *(undefined1 *)((int)param_2 + 1) = 0;
  }
  else {
    *(undefined4 *)(param_2 + 4) = 0x80;
    *param_2 = 5;
  }
  return 2;
}


