// FUNC 0x1004b2d0  uart_putc_indexed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Writes one byte to UART0..3 selected by the first argument */

void uart_putc_indexed(int param_1)

{
  char cVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    cVar1 = *DAT_1004b328;
    if (cVar1 == '\0') {
      do {
      } while ((_DAT_40000018 & 0x20) != 0);
      piVar2 = (int *)&DAT_40000000;
    }
    else if (cVar1 == '\x01') {
      do {
        piVar2 = DAT_1004b32c;
      } while ((DAT_1004b32c[6] & 0x20U) != 0);
    }
    else if (cVar1 == '\x02') {
      do {
        piVar2 = DAT_1004b330;
      } while ((DAT_1004b330[6] & 0x20U) != 0);
    }
    else {
      if (cVar1 != '\x03') {
        return;
      }
      do {
        piVar2 = DAT_1004b334;
      } while ((DAT_1004b334[6] & 0x20U) != 0);
    }
    *piVar2 = param_1;
  }
  return;
}


