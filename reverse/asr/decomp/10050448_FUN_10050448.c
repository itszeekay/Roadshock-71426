// FUNC 0x10050448  FUN_10050448

undefined8 FUN_10050448(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  
  FUN_1004eb00();
  puVar3 = DAT_10050480;
  iVar2 = DAT_1005047c;
  *(undefined1 *)(DAT_1005047c + 0x11) = 0;
  *puVar3 = 0;
  FUN_10053930(0x2f);
  FUN_10053930(0x2e);
  bVar1 = *(byte *)(iVar2 + 0xc);
  FUN_10050354(*(undefined1 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 9),*(undefined1 *)(iVar2 + 10),
               *(undefined1 *)(iVar2 + 0xb));
  log_printf(DAT_10050484);
  return CONCAT44(param_2,(uint)bVar1);
}


