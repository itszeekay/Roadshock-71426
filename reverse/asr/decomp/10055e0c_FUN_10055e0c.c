// FUNC 0x10055e0c  FUN_10055e0c

int FUN_10055e0c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *DAT_10055e48 = param_1;
  *DAT_10055e4c = param_2;
  uVar1 = DAT_10055e50;
  if (param_1 != 0) {
    FUN_10056870(DAT_10055e50,2,PTR_LAB_10055de4_1_10055e54);
  }
  if (param_2 != 0) {
    FUN_10056870(uVar1,3,PTR_LAB_10055df8_1_10055e58);
  }
  iVar2 = FUN_100568a2(uVar1,PTR_s_SYS_ENV_10055e60,PTR_s_SYS_KV_10055e5c);
  return -(uint)(iVar2 != 0);
}


