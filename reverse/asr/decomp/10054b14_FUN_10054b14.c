// FUNC 0x10054b14  FUN_10054b14

void FUN_10054b14(undefined4 param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)(DAT_10054b3c + 0xda);
  puVar2 = (undefined2 *)(DAT_10054b3c + 0x12);
  do {
    iVar1 = FUN_100549f0(*puVar2);
    if (iVar1 != 0) {
      (**(code **)(iVar1 + 8))(puVar2 + -9,param_1);
    }
    puVar2 = puVar2 + 10;
  } while (puVar2 != puVar3);
  return;
}


