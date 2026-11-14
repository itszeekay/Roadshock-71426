// FUNC 0x10055a18  FUN_10055a18

undefined4 FUN_10055a18(void)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  
  log_printf(DAT_10055a7c);
  piVar1 = DAT_10055a80;
  FUN_10055b42(DAT_10055a80 + 4,DAT_10055a80 + 4);
  puVar3 = DAT_10055a84;
  if (*piVar1 == piVar1[2] + 0x80) {
    if (piVar1[2] != *(int *)(DAT_10055a88 + 0x50)) {
      log_printf(PTR_s_image_length_compare_fail____d____10055a8c,*(int *)(DAT_10055a88 + 0x50));
      return 0xffffffff;
    }
    puVar3 = PTR_s_image_crc_compare_fail_10055a90;
    if ((*(uint *)(DAT_10055a88 + 0x54) == (uint)*(ushort *)(piVar1 + 4)) &&
       (iVar2 = FUN_10055ca8(*DAT_10055a9c,DAT_10055a88,(int)*DAT_10055a98,(int)*DAT_10055a94),
       puVar3 = DAT_10055aa0, iVar2 == 0)) {
      return 0;
    }
  }
  log_printf(puVar3);
  return 0xffffffff;
}


