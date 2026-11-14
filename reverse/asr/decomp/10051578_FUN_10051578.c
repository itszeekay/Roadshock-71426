// FUNC 0x10051578  FUN_10051578

uint FUN_10051578(uint param_1)

{
  return (param_1 >> 4) * 10 + (param_1 & 0xf) & 0xff;
}


