// FUNC 0x100538e8  FUN_100538e8

undefined4 FUN_100538e8(undefined1 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_10053910,4,4,8);
  uVar2 = DAT_10053914;
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = param_1;
    *(undefined4 *)(puVar1 + 4) = param_2;
    FUN_10056e78();
    uVar2 = 0;
  }
  return uVar2;
}


