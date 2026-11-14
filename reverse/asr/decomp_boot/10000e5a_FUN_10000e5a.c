// FUNC 0x10000e5a  FUN_10000e5a

void FUN_10000e5a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5,undefined1 param_6,uint param_7,undefined4 param_8,undefined4 param_9,
                 uint param_10)

{
  char cVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  char local_38 [36];
  
  if (param_5 == 0) {
    param_10 = param_10 & 0xffffffef;
  }
  if ((-1 < (int)(param_10 << 0x15)) || (param_5 != 0)) {
    cVar3 = 'a';
    if ((int)(param_10 << 0x1a) < 0) {
      cVar3 = 'A';
    }
    uVar4 = param_5;
    param_5 = 0;
    do {
      uVar5 = FUN_10000910(uVar4,param_7);
      cVar2 = (char)(uVar5 >> 0x20);
      cVar1 = cVar2 + cVar3 + -10;
      if (uVar5 < 0xa00000000) {
        cVar1 = cVar2 + '0';
      }
      local_38[param_5] = cVar1;
      param_5 = param_5 + 1;
    } while ((param_7 <= uVar4) && (uVar4 = (uint)uVar5, param_5 != 0x20));
  }
  FUN_10000cf0(param_1,param_2,param_3,param_4,local_38,param_5,param_6,param_7,param_8,param_9,
               param_10);
  return;
}


