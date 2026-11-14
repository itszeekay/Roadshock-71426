// FUNC 0x10000eee  FUN_10000eee

/* WARNING: Removing unreachable block (ram,0x10000f74) */

void FUN_10000eee(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6,undefined1 param_7,undefined4 param_8,uint param_9,
                 undefined4 param_10,undefined4 param_11,undefined4 param_12,uint param_13)

{
  ulonglong uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  int local_5c;
  char acStack_38 [36];
  
  if (param_5 == 0 && param_6 == 0) {
    param_13 = param_13 & 0xffffffef;
  }
  if ((-1 < (int)(param_13 << 0x15)) || (iVar5 = 0, param_5 != 0 || param_6 != 0)) {
    cVar3 = 'a';
    if ((int)(param_13 << 0x1a) < 0) {
      cVar3 = 'A';
    }
    local_5c = 0;
    uVar1 = CONCAT44(param_6,param_5);
    do {
      uVar2 = param_9;
      uVar6 = FUN_10000934((int)uVar1,(int)(uVar1 >> 0x20),param_9,param_10);
      cVar4 = (char)uVar2 + cVar3 + -10;
      if ((uVar2 & 0xff) < 10) {
        cVar4 = (char)uVar2 + '0';
      }
      iVar5 = local_5c + 1;
      acStack_38[local_5c] = cVar4;
    } while ((CONCAT44(param_10,param_9) <= uVar1) &&
            (local_5c = iVar5, uVar1 = uVar6, iVar5 != 0x20));
  }
  FUN_10000cf0(param_1,param_2,param_3,param_4,acStack_38,iVar5,param_7,param_9,param_11,param_12,
               param_13);
  return;
}


