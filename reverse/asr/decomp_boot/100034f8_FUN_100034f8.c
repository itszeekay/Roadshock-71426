// FUNC 0x100034f8  FUN_100034f8

/* WARNING: Function: __gnu_thumb1_case_uqi replaced with injection: switch8_r0 */
/* WARNING (jumptable): Removing unreachable block (ram,0x100035c0) */
/* WARNING: Removing unreachable block (ram,0x100035c0) */

undefined4 FUN_100034f8(code *param_1,code *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  
  FUN_1000205c();
  iVar1 = FUN_100034a4(2,0x4000);
  if (iVar1 == 0) {
switchD_100035c0_caseD_3:
    uVar4 = DAT_10003618;
  }
  else {
    local_30 = FUN_100043bc(0x1000);
    local_2c = 0;
    local_28 = 0;
    local_24 = FUN_100043bc(0x1000);
    local_20 = 0;
    local_1c = 0x1000;
    do {
      if (local_2c == local_28) {
        local_28 = (*param_1)(local_30,1,0x1000,0);
        local_2c = 0;
      }
      iVar2 = FUN_10002ee8(iVar1,&local_30);
      if (local_20 == 0x1000) {
        iVar3 = (*param_2)(local_24,1,0x1000,0);
        uVar4 = DAT_100035fc;
        if (iVar3 != local_20) goto LAB_1000357a;
        local_20 = 0;
      }
    } while (iVar2 == 0);
    iVar3 = (*param_2)(local_24,1,local_20,0);
    uVar4 = DAT_100035fc;
    if (iVar3 != local_20) goto LAB_1000357a;
    switch(iVar2) {
    case 1:
      FUN_100034de(iVar1);
      FUN_100043d0(local_30);
      FUN_100043d0(local_24);
      return 0;
    default:
      uVar4 = DAT_10003614;
      break;
    case 3:
      goto switchD_100035c0_caseD_3;
    case 4:
      uVar4 = DAT_10003604;
      break;
    case 5:
      uVar4 = DAT_10003608;
      break;
    case 6:
      uVar4 = DAT_1000360c;
      break;
    case 7:
    case 8:
      uVar4 = DAT_10003610;
    }
  }
LAB_1000357a:
  FUN_100034de(iVar1);
  if (local_30 != 0) {
    FUN_100043d0();
  }
  if (local_24 != 0) {
    FUN_100043d0();
  }
  FUN_100014a0(DAT_10003600,uVar4);
  return 1;
}


