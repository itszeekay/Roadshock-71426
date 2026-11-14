// FUNC 0x100562ac  FUN_100562ac

void FUN_100562ac(int param_1)

{
  uint local_28;
  undefined1 auStack_24 [24];
  
  local_28 = 0;
  FUN_100561b6(param_1,auStack_24,1,&local_28,0,DAT_100562ec,0);
  if (local_28 < 2) {
    FUN_100561b6(param_1,auStack_24,0,param_1,0,DAT_100562f0,0);
  }
  *(undefined1 *)(param_1 + 0x28) = 0;
  return;
}


