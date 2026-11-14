// FUNC 0x1004b218  FUN_1004b218

void FUN_1004b218(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6,undefined1 param_7,undefined4 param_8,uint param_9,
                 undefined4 param_10,undefined4 param_11,undefined4 param_12,uint param_13)

{
  char cVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  char local_38 [36];
  
  lVar7 = CONCAT44(param_6,param_5);
  if (param_5 == 0 && param_6 == 0) {
    param_13 = param_13 & 0xffffffef;
  }
  if ((-1 < (int)(param_13 << 0x15)) || (iVar5 = 0, param_5 != 0 || param_6 != 0)) {
    cVar3 = 'a';
    if ((int)(param_13 << 0x1a) < 0) {
      cVar3 = 'A';
    }
    iVar6 = 0;
    do {
      uVar4 = (undefined4)((ulonglong)lVar7 >> 0x20);
      uVar2 = param_9;
      FUN_100481e4((int)lVar7,uVar4,param_9,param_10);
      cVar1 = (char)uVar2 + cVar3 + -10;
      iVar5 = iVar6 + 1;
      if ((uVar2 & 0xff) < 10) {
        cVar1 = (char)uVar2 + '0';
      }
      local_38[iVar6] = cVar1;
      lVar7 = FUN_100481e4((int)lVar7,uVar4,param_9,param_10);
    } while ((lVar7 != 0) && (iVar6 = iVar5, iVar5 != 0x20));
  }
  FUN_1004b098(param_1,param_2,param_3,param_4,local_38,iVar5,param_7,param_9,param_11,param_12,
               param_13);
  return;
}


