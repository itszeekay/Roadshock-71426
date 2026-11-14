// FUNC 0x1004c918  pinmux_set

/* pinmux_set(pin, class); 4-bit field at 0x40110068..0x40110074 */

void pinmux_set(undefined4 *param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (uint *)((((uint)param_1 >> 3) + DAT_1004ca28) * 4);
  iVar2 = ((uint)param_1 & 7) << 2;
  if (param_2 < 0x19) {
    iVar2 = FUN_10056ee8(param_2);
    *param_1 = 0xd;
                    /* WARNING: Could not recover jumptable at 0x1004c948. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(iVar2 + -0x31);
    return;
  }
  *puVar1 = *puVar1 & ~(0xf << iVar2);
  *puVar1 = 0 << iVar2 | *puVar1;
  return;
}


