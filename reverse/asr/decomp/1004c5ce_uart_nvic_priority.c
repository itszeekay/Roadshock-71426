// FUNC 0x1004c5ce  uart_nvic_priority

undefined4 uart_nvic_priority(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xffffffc7;
  *(uint *)(param_1 + 0x34) = param_2 << 3 | *(uint *)(param_1 + 0x34);
  return 0;
}


