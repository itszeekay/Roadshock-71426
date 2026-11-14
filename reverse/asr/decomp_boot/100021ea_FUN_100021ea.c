// FUNC 0x100021ea  FUN_100021ea

undefined4 FUN_100021ea(int *param_1,uint *param_2,uint param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = *param_2;
  uVar6 = param_1[2];
  uVar5 = param_1[4] - uVar6;
  if (uVar3 < param_1[4] - uVar6) {
    uVar5 = uVar3;
  }
  *param_2 = uVar3 - uVar5;
  iVar4 = ~param_3 + uVar6;
  if (uVar6 <= param_3) {
    iVar4 = iVar4 + param_1[5];
  }
  do {
    iVar2 = param_1[2];
    param_1[2] = iVar2 + 1;
    puVar1 = (undefined1 *)(*param_1 + iVar4);
    iVar4 = iVar4 + 1;
    *(undefined1 *)(*param_1 + iVar2) = *puVar1;
    if (iVar4 == param_1[5]) {
      iVar4 = 0;
    }
    uVar5 = uVar5 - 1;
  } while (uVar5 != 0);
  if ((uint)param_1[3] < (uint)param_1[2]) {
    param_1[3] = param_1[2];
  }
  return 1;
}


