// FUNC 0x1004ea30  FUN_1004ea30

void FUN_1004ea30(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_1004ea64;
  *DAT_1004ea64 = 5;
  uVar2 = FUN_10048ea8();
  uVar3 = FUN_100486fc(uVar2,DAT_1004ea68);
  uVar2 = DAT_1004ea6c;
  *(undefined4 *)(puVar1 + 4) = uVar3;
  *(undefined4 *)(puVar1 + 8) = uVar2;
  if (param_1 == 0) {
    FUN_1004d190(puVar1);
  }
  else {
    FUN_1004d0ec();
    FUN_1004d148(puVar1);
  }
  return;
}


