// FUNC 0x10055eb6  FUN_10055eb6

undefined4 FUN_10055eb6(undefined4 param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int local_58;
  undefined1 auStack_4c [8];
  int local_44;
  uint local_40;
  undefined2 local_3c;
  undefined1 auStack_38 [36];
  
  FUN_10056a4a(param_1,*(undefined4 *)(param_2 + 0x10),auStack_4c,0x14);
  uVar1 = FUN_10056936(auStack_4c,6);
  *param_2 = uVar1;
  if (local_40 < 0x81) {
    *(uint *)(param_2 + 8) = local_40;
    uVar3 = 0;
    uVar2 = local_40 + 8;
    local_58 = 0;
    do {
      iVar4 = 0x20;
      if (uVar2 <= uVar3 + 0x20) {
        iVar4 = uVar2 - uVar3;
      }
      FUN_10056a4a(param_1,*(int *)(param_2 + 0x10) + 0xc + uVar3,auStack_38,iVar4);
      local_58 = FUN_100568d8(local_58,auStack_38,iVar4);
      uVar3 = uVar3 + iVar4;
    } while (uVar3 < uVar2);
    if (local_58 == local_44) {
      param_2[1] = 1;
      *(undefined2 *)(param_2 + 0xc) = local_3c;
      *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x10) + 0x14;
      return 0;
    }
  }
  else {
    *(undefined4 *)(param_2 + 8) = 0x80;
    *param_2 = 5;
  }
  param_2[1] = 0;
  return 2;
}


