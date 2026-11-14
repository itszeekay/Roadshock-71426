// FUNC 0x1005661c  FUN_1005661c

int FUN_1005661c(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined2 local_44;
  char local_2d;
  undefined1 auStack_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  undefined2 local_1c;
  
  iVar5 = 8;
  if (*(char *)(param_1 + 0x10) != '\0') {
    if (*(code **)(param_1 + 0x14) != (code *)0x0) {
      (**(code **)(param_1 + 0x14))();
    }
    iVar2 = *param_3;
    uVar6 = param_3[1];
    if (iVar2 == 0) {
      iVar5 = FUN_100563fc(param_1,param_2,0,1);
    }
    else {
      iVar3 = param_1 + 0x44;
      iVar1 = FUN_100562f4(param_1,iVar3,uVar6 + 0x14);
      iVar5 = 7;
      if (iVar1 != -1) {
        iVar4 = param_1 + 0x2c;
        iVar1 = FUN_100563d0(param_1,param_2,iVar4);
        if ((iVar1 == 0) || (iVar5 = FUN_100563fc(param_1,param_2,iVar4,0), iVar5 == 0)) {
          local_2d = '\0';
          iVar7 = *(int *)(param_1 + 0x54);
          FUN_10056f28(auStack_2c,0xff,0x14);
          local_28 = DAT_100567a0;
          local_44 = (undefined2)param_2;
          local_1c = local_44;
          local_20 = uVar6;
          if (((*(int *)(param_1 + 8) - 8U < uVar6) || (0x80 < uVar6)) ||
             ((iVar7 == -1 && (iVar7 = FUN_100562f4(param_1,iVar3,0x94), iVar7 == -1)))) {
            iVar5 = 7;
          }
          else {
            iVar5 = FUN_1005615e(param_1,iVar3,&local_2d);
            if (iVar5 == 0) {
              local_24 = FUN_100568d8(0,&local_20,8);
              local_24 = FUN_100568d8(local_24,iVar2,local_20);
              iVar5 = FUN_10056960(param_1,iVar7,auStack_2c,6,1,0);
              if ((((iVar5 == 0) &&
                   (iVar5 = FUN_10056a6e(param_1,iVar7 + 4,&local_28,0x10,0), iVar5 == 0)) &&
                  (iVar5 = FUN_10056a6e(param_1,iVar7 + 0x14,iVar2,local_20,0), iVar5 == 0)) &&
                 ((iVar5 = FUN_10056960(param_1,iVar7,auStack_2c,6,2,1), iVar5 == 0 &&
                  (local_2d != '\0')))) {
                *(undefined1 *)(param_1 + 0x28) = 1;
              }
            }
          }
          if ((iVar1 != 0) && (iVar5 == 0)) {
            iVar5 = FUN_100563fc(param_1,param_2,iVar4,1);
          }
        }
        if (*(char *)(param_1 + 0x28) != '\0') {
          FUN_100562ac(param_1);
        }
      }
    }
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return iVar5;
}


