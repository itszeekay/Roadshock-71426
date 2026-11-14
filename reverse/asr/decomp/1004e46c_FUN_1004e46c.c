// FUNC 0x1004e46c  FUN_1004e46c

void FUN_1004e46c(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 local_3c [2];
  undefined2 local_3a;
  undefined1 local_21;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined1 local_16;
  
  uVar1 = DAT_1004e528;
  FUN_1004bf28(DAT_1004e528,DAT_1004e52c);
  FUN_10051b94(5);
  FUN_100533bc(DAT_1004e530);
  FUN_10051e64(DAT_1004e534);
  FUN_100533c8(DAT_1004e538);
  FUN_10053b6c(DAT_1004e53c);
  FUN_100533d4(DAT_1004e540);
  FUN_10055110(DAT_1004e544);
  uVar2 = DAT_1004e548;
  FUN_1004bf28(uVar1,DAT_1004e548);
  FUN_10056f28(local_3c,0,0x2a);
  local_3a = 0x96;
  local_21 = 3;
  local_1c = 0x80;
  local_1a = 0x2a0;
  local_18 = 0x2a0;
  local_16 = 10;
  local_3c[0] = 10;
  iVar3 = FUN_1005359c(local_3c);
  if (iVar3 != 0) {
    FUN_1004bf28(DAT_1004e54c,uVar2);
  }
  puVar4 = (undefined1 *)FUN_100539d4();
  FUN_1004bf28(DAT_1004e550,puVar4[5],puVar4[4],puVar4[3],puVar4[2],puVar4[1],*puVar4);
  FUN_1004bf28(DAT_1004e554);
  iVar3 = DAT_1004e558;
  FUN_10053958(DAT_1004e558);
  FUN_10053958(iVar3 + 8);
  FUN_10053958(iVar3 + 0x10);
  return;
}


