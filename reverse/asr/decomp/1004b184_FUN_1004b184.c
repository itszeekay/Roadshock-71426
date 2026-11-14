// FUNC 0x1004b184  FUN_1004b184

void FUN_1004b184(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined1 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,uint param_10)

{
  char cVar1;
  byte extraout_r1;
  char cVar2;
  int iVar3;
  int iVar4;
  char local_38 [36];
  
  if (param_5 == 0) {
    param_10 = param_10 & 0xffffffef;
  }
  if ((-1 < (int)(param_10 << 0x15)) || (iVar3 = 0, param_5 != 0)) {
    cVar2 = 'a';
    if ((int)(param_10 << 0x1a) < 0) {
      cVar2 = 'A';
    }
    iVar4 = 0;
    do {
      FUN_10056d68(param_5,param_7);
      iVar3 = iVar4 + 1;
      cVar1 = cVar2 + -10;
      if (extraout_r1 < 10) {
        cVar1 = '0';
      }
      local_38[iVar4] = extraout_r1 + cVar1;
      param_5 = FUN_10056d58(param_5,param_7);
    } while ((param_5 != 0) && (iVar4 = iVar3, iVar3 != 0x20));
  }
  FUN_1004b098(param_1,param_2,param_3,param_4,local_38,iVar3,param_6,param_7,param_8,param_9,
               param_10);
  return;
}


