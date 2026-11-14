// FUNC 0x10051754  FUN_10051754

undefined8 FUN_10051754(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  undefined1 local_19;
  undefined4 uStack_18;
  
  uStack_18 = param_3;
  FUN_1005152c();
  piVar1 = DAT_10051850;
  FUN_100539c0(0x96,&local_19,DAT_10051850);
  if (*piVar1 != DAT_10051854) {
    FUN_10051674();
  }
  *DAT_10051858 = *(undefined2 *)((int)piVar1 + 0xe);
  *DAT_1005185c = (char)piVar1[4];
  if (*(char *)((int)piVar1 + 0x11) != '\0') {
    *(undefined1 *)((int)piVar1 + 0x11) = 0;
  }
  *(undefined1 *)((int)piVar1 + 0x5d) = 1;
  bVar2 = *DAT_10051860;
  iVar3 = FUN_10051734(bVar2 >> 4);
  bVar2 = FUN_10051734(bVar2 & 0xf);
  *DAT_10051860 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *DAT_10051864;
  iVar3 = FUN_10051734(bVar2 >> 4);
  bVar2 = FUN_10051734(bVar2 & 0xf);
  *DAT_10051864 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *DAT_10051868;
  iVar3 = FUN_10051734(bVar2 >> 4);
  bVar2 = FUN_10051734(bVar2 & 0xf);
  *DAT_10051868 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *DAT_1005186c;
  iVar3 = FUN_10051734(bVar2 >> 4);
  bVar2 = FUN_10051734(bVar2 & 0xf);
  *DAT_1005186c = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *DAT_10051870;
  iVar3 = FUN_10051734(bVar2 >> 4);
  bVar2 = FUN_10051734(bVar2 & 0xf);
  *DAT_10051870 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *DAT_10051874;
  iVar3 = FUN_10051734(bVar2 >> 4);
  bVar2 = FUN_10051734(bVar2 & 0xf);
  *DAT_10051874 = bVar2 | (byte)(iVar3 << 4);
  return CONCAT44(param_1,(uint)(*piVar1 + DAT_10051878 == 0));
}


