// FUNC 0x100556e8  FUN_100556e8

void FUN_100556e8(undefined4 *param_1)

{
  int iVar1;
  
  log_printf(PTR_s__OTAS_TRC_otas_task_init_1005570c);
  iVar1 = FUN_10054b70(0x50);
  *param_1 = PTR_DAT_10055710;
  *(undefined2 *)((int)param_1 + 10) = 6;
  param_1[1] = iVar1 + 8;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}


