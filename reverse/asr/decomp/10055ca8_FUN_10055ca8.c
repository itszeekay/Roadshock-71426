// FUNC 0x10055ca8  FUN_10055ca8

int FUN_10055ca8(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 local_84 [8];
  undefined1 auStack_64 [32];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_1 == 0) {
    if (*(int *)(param_2 + 0x40) == 0) {
      uVar5 = 0;
      if (param_4 != 3) {
        uVar5 = 0xffffffff;
      }
      *(undefined4 *)(param_2 + 0x44) = uVar5;
    }
    puVar2 = DAT_10055ddc;
    puVar1 = DAT_10055dd8;
    *(undefined4 *)(param_2 + 0x48) = 0;
    *(undefined4 *)(param_2 + 0x60) = 0;
    uVar6 = *puVar1;
    *puVar2 = 0xfffffffe;
    local_84[0] = 0x1000;
    iVar3 = FUN_1004c7dc(5,0x1000,0x80);
    *puVar1 = uVar6 & 0xfffffffe;
    if (iVar3 == 0) {
      uVar6 = *puVar1;
      *puVar2 = 0xfffffffe;
      local_84[0] = 0x1000;
      iVar3 = FUN_1004c82c(5,local_84,param_2,0x80);
      *puVar1 = uVar6 & 0xfffffffe;
      iVar4 = FUN_1004c79c(param_3);
      uVar5 = *(undefined4 *)(iVar4 + 8);
      iVar4 = FUN_1004c79c(param_4);
      uVar7 = *(undefined4 *)(iVar4 + 8);
      iVar4 = FUN_1004c79c(param_4);
      FUN_1004bf28(DAT_10055de0,uVar5,uVar7,*(undefined4 *)(iVar4 + 0xc),
                   *(undefined4 *)(param_2 + 0x40),*(undefined4 *)(param_2 + 0x44),
                   *(undefined4 *)(param_2 + 0x4c));
    }
  }
  else {
    FUN_10056de8(local_84,param_2,0x20);
    FUN_10056de8(auStack_64,param_2 + 0x20);
    local_44 = 0;
    local_20 = *(undefined4 *)(param_2 + 0x60);
    local_1c = *(undefined4 *)(param_2 + 100);
    local_28 = *(undefined4 *)(param_2 + 0x58);
    local_24 = *(undefined4 *)(param_2 + 0x5c);
    local_30 = *(undefined4 *)(param_2 + 0x50);
    local_2c = *(undefined4 *)(param_2 + 0x54);
    if (*(int *)(param_2 + 0x40) == 0) {
      local_40 = 0;
      if (param_4 != 3) {
        local_40 = 1;
      }
    }
    else if (*(int *)(param_2 + 0x4c) == 0) {
      local_40 = 3;
    }
    else {
      local_40 = 2;
    }
    iVar3 = FUN_1004c79c(param_3);
    local_3c = *(undefined4 *)(iVar3 + 8);
    iVar3 = FUN_1004c79c(param_4);
    local_38 = *(undefined4 *)(iVar3 + 8);
    iVar3 = FUN_1004c79c(param_4);
    local_34 = *(undefined4 *)(iVar3 + 0xc);
    FUN_1004bf28(DAT_10055dd4,local_3c,local_38,local_34,local_40);
    iVar3 = FUN_10055e64(3,local_84,0x6c);
  }
  return iVar3;
}


