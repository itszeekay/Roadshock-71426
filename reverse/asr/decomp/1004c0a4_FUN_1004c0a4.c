// FUNC 0x1004c0a4  FUN_1004c0a4

void FUN_1004c0a4(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)getMainStackPointer();
  log_printf(DAT_1004c0fc);
  log_printf(DAT_1004c100,*puVar1);
  log_printf(DAT_1004c104,puVar1[1]);
  log_printf(DAT_1004c108,puVar1[2]);
  log_printf(DAT_1004c10c,puVar1[3]);
  log_printf(DAT_1004c110,puVar1[4]);
  log_printf(DAT_1004c114,puVar1[5]);
  log_printf(DAT_1004c118,puVar1[6]);
  log_printf(DAT_1004c11c,puVar1[7]);
  software_bkpt(1);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


