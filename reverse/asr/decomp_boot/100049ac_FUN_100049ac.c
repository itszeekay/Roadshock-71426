// FUNC 0x100049ac  FUN_100049ac

void FUN_100049ac(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  bool bVar8;
  
  uVar4 = param_3;
  if (0xf < param_3) {
    uVar6 = ((uint)param_2 | (uint)param_1) & 3;
    if ((((uint)param_2 | (uint)param_1) & 3) != 0) {
      iVar5 = param_3 - 1;
      goto LAB_10004a26;
    }
    uVar4 = param_3 - 0x10 >> 4;
    puVar1 = param_1;
    puVar3 = param_2;
    do {
      uVar7 = puVar3[1];
      *puVar1 = *puVar3;
      puVar1[1] = uVar7;
      uVar7 = puVar3[3];
      puVar1[2] = puVar3[2];
      puVar1[3] = uVar7;
      puVar3 = puVar3 + 4;
      bVar8 = puVar1 != param_1 + uVar4 * 4;
      puVar1 = puVar1 + 4;
    } while (bVar8);
    iVar5 = uVar4 + 1;
    param_2 = param_2 + iVar5 * 4;
    uVar4 = param_3 & 0xf;
    param_1 = param_1 + iVar5 * 4;
    if ((param_3 & 0xc) != 0) {
      do {
        *(undefined4 *)((int)param_1 + uVar6) = *(undefined4 *)((int)param_2 + uVar6);
        uVar6 = uVar6 + 4;
      } while (3 < uVar4 - uVar6);
      iVar5 = (uVar4 - 4 >> 2) + 1;
      param_1 = param_1 + iVar5;
      param_2 = param_2 + iVar5;
      uVar4 = param_3 & 3;
    }
  }
  iVar5 = uVar4 - 1;
  if (uVar4 == 0) {
    return;
  }
LAB_10004a26:
  iVar2 = 0;
  do {
    *(undefined1 *)((int)param_1 + iVar2) = *(undefined1 *)((int)param_2 + iVar2);
    bVar8 = iVar5 != iVar2;
    iVar2 = iVar2 + 1;
  } while (bVar8);
  return;
}


