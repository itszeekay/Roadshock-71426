// FUNC 0x100556b4  FUN_100556b4

void FUN_100556b4(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_100556d8;
  *DAT_100556dc = DAT_100556d8;
  puVar2 = DAT_100556e0;
  *DAT_100556e0 = 0;
  *(undefined2 *)(puVar2 + 2) = 0;
  *(undefined4 *)(puVar2 + 4) = 0;
  puVar2[1] = 0;
  uVar3 = (**(code **)(iVar1 + 0x14))();
  log_printf(DAT_100556e4,uVar3);
  return;
}


