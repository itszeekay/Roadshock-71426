// FUNC 0x100516d8  led_frame_send

/* Builds 5A 00 <6 bytes> EE and sends it to UART3 */

void led_frame_send(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_1c [16];
  
  local_1c[0] = 0x5a;
  local_1c[2] = *param_1;
  iVar2 = 0;
  local_1c[3] = param_1[1];
  local_1c[4] = param_1[2];
  local_1c[1] = 0;
  local_1c[5] = param_1[3];
  local_1c[6] = param_1[4];
  local_1c[7] = param_1[5];
  local_1c[8] = 0xee;
  uart3_write(local_1c,9);
  log_printf(PTR_s_IND_DATA_SEND__10051728);
  do {
    puVar1 = local_1c + iVar2;
    iVar2 = iVar2 + 1;
    log_printf(PTR_s__02x_1005172c,*puVar1);
  } while (iVar2 != 9);
  log_printf(DAT_10051730);
  return;
}


