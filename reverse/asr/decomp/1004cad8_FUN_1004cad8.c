// FUNC 0x1004cad8  FUN_1004cad8

void FUN_1004cad8(int param_1,uint param_2,int param_3)

{
  undefined1 uVar1;
  uint uVar2;
  
  FUN_1004ca50(0);
  for (uVar2 = 0; (uVar2 & 0xffff) < param_2; uVar2 = uVar2 + 1) {
    uVar1 = FUN_1004ca94(param_1 + uVar2 & 0xff);
    *(undefined1 *)(param_3 + uVar2) = uVar1;
  }
  return;
}


