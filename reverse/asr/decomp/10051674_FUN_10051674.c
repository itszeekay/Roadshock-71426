// FUNC 0x10051674  FUN_10051674

void FUN_10051674(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = DAT_100516d0;
  *(undefined1 *)((int)DAT_100516d0 + 9) = 0xff;
  *(undefined1 *)(puVar1 + 3) = 0xff;
  uVar2 = DAT_100516d4;
  *(undefined2 *)((int)puVar1 + 0xe) = 0x78;
  *(undefined1 *)((int)puVar1 + 0x12) = 1;
  *puVar1 = uVar2;
  *(undefined1 *)((int)puVar1 + 0x5d) = 0;
  puVar1[1] = 0;
  *(undefined1 *)((int)puVar1 + 10) = 0;
  *(undefined1 *)(puVar1 + 2) = 0;
  *(undefined1 *)((int)puVar1 + 0xb) = 0;
  *(undefined1 *)(puVar1 + 4) = 0;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  iVar4 = 0;
  do {
    iVar3 = iVar4 + 1;
    *(undefined1 *)((int)puVar1 + iVar4 + 0x13) = 0;
    iVar4 = iVar3;
  } while (iVar3 != 0xc);
  FUN_10056f28((int)puVar1 + 0x1f,0,0x38);
  iVar4 = 0;
  do {
    iVar3 = iVar4 + 1;
    *(undefined1 *)((int)puVar1 + iVar4 + 0x57) = 0;
    *(undefined1 *)((int)puVar1 + iVar4 + 0x5e) = 0;
    iVar4 = iVar3;
  } while (iVar3 != 6);
  return;
}


