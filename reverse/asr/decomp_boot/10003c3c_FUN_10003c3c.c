// FUNC 0x10003c3c  FUN_10003c3c

undefined4 FUN_10003c3c(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_5c;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [20];
  undefined1 auStack_38 [36];
  
  if (*param_2 == '\x02') {
    FUN_10003a48(param_1,0,param_2);
  }
  iVar1 = FUN_10003bac(param_1,auStack_4c,0x94);
  local_5c = 7;
  if (iVar1 != -1) {
    if ((*(char *)(param_1 + 0x29) == '\0') ||
       (iVar2 = FUN_10003a1c(param_1,*(undefined2 *)(param_2 + 0xc),auStack_38), iVar2 == 0)) {
      iVar2 = *(int *)(param_2 + 8);
      FUN_10003af4(param_1,auStack_4c,0);
      FUN_10004346(param_1,iVar1,auStack_50,6,1,0);
      uVar3 = iVar2 + 0x10;
      local_5c = 0;
      for (uVar4 = 0; uVar4 < uVar3; uVar4 = uVar4 + iVar2) {
        iVar2 = 0x20;
        if (uVar3 <= uVar4 + 0x20) {
          iVar2 = uVar3 - uVar4;
        }
        FUN_1000421e(param_1,*(int *)(param_2 + 0x10) + 4 + uVar4,auStack_38,iVar2);
        local_5c = FUN_10004242(param_1,iVar1 + 4 + uVar4,auStack_38,iVar2,1);
      }
      FUN_10004346(param_1,iVar1,auStack_50,6,2,1);
    }
    else {
      local_5c = 0;
    }
    FUN_10003a48(param_1,0,param_2,1);
  }
  return local_5c;
}


