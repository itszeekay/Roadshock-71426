// FUNC 0x10002234  FUN_10002234

undefined4 FUN_10002234(uint *param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  undefined1 uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  ushort *puVar13;
  uint uVar14;
  uint local_2c;
  
  if ((((param_1[8] < param_1[10]) && (param_1[0x19] != 0)) && (param_1[0x14] < param_1[9])) &&
     (param_1[0x14] < param_1[0xc])) {
    FUN_100021ea(param_1 + 6,param_1 + 0x19);
  }
  do {
    while( true ) {
      uVar5 = param_1[8];
      uVar10 = *param_1;
      if ((param_1[10] <= uVar5) || (uVar6 = param_1[4], param_1[5] < uVar6)) {
        if (0xffffff < uVar10) {
          return 1;
        }
        *param_1 = uVar10 << 8;
        uVar5 = param_1[4];
        param_1[4] = uVar5 + 1;
        param_1[1] = (uint)*(byte *)(param_1[3] + uVar5) + param_1[1] * 0x100;
        return 1;
      }
      uVar2 = param_1[0x1c] & uVar5;
      uVar3 = (uint)(byte)param_1[0x18];
      if (uVar10 < 0x1000000) {
        *param_1 = uVar10 << 8;
        param_1[4] = uVar6 + 1;
        param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + param_1[1] * 0x100;
      }
      iVar4 = uVar3 * 0x10 + uVar2;
      puVar13 = (ushort *)((int)param_1 + iVar4 * 2 + 0x74);
      uVar1 = *puVar13;
      uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
      uVar10 = param_1[1];
      if (uVar6 < uVar10 || uVar6 - uVar10 == 0) break;
      *param_1 = uVar6;
      *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
      iVar4 = uVar5 - 1;
      if (uVar5 == 0) {
        iVar4 = param_1[0xb] - 1;
      }
      uVar10 = param_1[6];
      local_2c = param_1[9];
      uVar6 = 0;
      if (local_2c != 0) {
        uVar6 = (uint)*(byte *)(uVar10 + iVar4);
      }
      iVar4 = (((param_1[0x1b] & uVar5) << (param_1[0x1a] & 0xff)) +
              (uVar6 >> (8 - param_1[0x1a] & 0xff))) * 0x600 + 0xee0;
      if (uVar3 < 7) {
        uVar2 = 1;
        do {
          puVar13 = (ushort *)((int)param_1 + uVar2 * 2 + iVar4);
          if (*param_1 < 0x1000000) {
            *param_1 = *param_1 << 8;
            uVar6 = param_1[4];
            param_1[4] = uVar6 + 1;
            param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + param_1[1] * 0x100;
          }
          uVar1 = *puVar13;
          uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
          uVar3 = param_1[1];
          uVar2 = uVar2 * 2;
          if (uVar6 < uVar3 || uVar6 - uVar3 == 0) {
            param_1[1] = uVar3 - uVar6;
            *param_1 = *param_1 - uVar6;
            uVar2 = uVar2 + 1;
            *puVar13 = uVar1 - (uVar1 >> 5);
          }
          else {
            *param_1 = uVar6;
            *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
          }
        } while (uVar2 < 0x100);
      }
      else {
        iVar11 = (uVar5 - 1) - param_1[0x14];
        if (uVar5 <= param_1[0x14]) {
          iVar11 = iVar11 + param_1[0xb];
        }
        if (local_2c != 0) {
          local_2c = (uint)*(byte *)(uVar10 + iVar11);
        }
        uVar2 = 1;
        uVar6 = 0x100;
        do {
          local_2c = local_2c << 1;
          uVar3 = uVar6 & local_2c;
          puVar13 = (ushort *)((int)param_1 + (uVar6 + uVar2 + uVar3) * 2 + iVar4);
          if (*param_1 < 0x1000000) {
            *param_1 = *param_1 << 8;
            uVar7 = param_1[4];
            param_1[4] = uVar7 + 1;
            param_1[1] = (uint)*(byte *)(param_1[3] + uVar7) + param_1[1] * 0x100;
          }
          uVar14 = param_1[1];
          uVar1 = *puVar13;
          uVar7 = (uint)uVar1 * (*param_1 >> 0xb);
          uVar2 = uVar2 * 2;
          if (uVar7 < uVar14 || uVar7 - uVar14 == 0) {
            uVar2 = uVar2 + 1;
            *param_1 = *param_1 - uVar7;
            param_1[1] = uVar14 - uVar7;
            *puVar13 = uVar1 - (uVar1 >> 5);
          }
          else {
            *param_1 = uVar7;
            *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
            uVar3 = uVar6 & ~uVar3;
          }
          uVar6 = uVar3;
        } while (uVar2 < 0x100);
      }
      param_1[8] = uVar5 + 1;
      *(char *)(uVar10 + uVar5) = (char)uVar2;
      if (param_1[9] < param_1[8]) {
        param_1[9] = param_1[8];
      }
      bVar8 = (byte)param_1[0x18];
      if (bVar8 < 4) {
        bVar8 = 0;
      }
      else if (bVar8 < 10) {
        bVar8 = bVar8 - 3;
      }
      else {
        bVar8 = bVar8 - 6;
      }
      *(byte *)(param_1 + 0x18) = bVar8;
    }
    uVar5 = *param_1 - uVar6;
    *param_1 = uVar5;
    param_1[1] = uVar10 - uVar6;
    *puVar13 = uVar1 - (uVar1 >> 5);
    if (uVar5 < 0x1000000) {
      *param_1 = uVar5 * 0x100;
      uVar5 = param_1[4];
      param_1[4] = uVar5 + 1;
      param_1[1] = (uint)*(byte *)(param_1[3] + uVar5) + (uVar10 - uVar6) * 0x100;
    }
    uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 500);
    uVar10 = (uint)uVar1 * (*param_1 >> 0xb);
    uVar5 = param_1[1];
    if (uVar10 < uVar5 || uVar10 - uVar5 == 0) {
      uVar6 = *param_1 - uVar10;
      *param_1 = uVar6;
      param_1[1] = uVar5 - uVar10;
      *(ushort *)((int)param_1 + uVar3 * 2 + 500) = uVar1 - (uVar1 >> 5);
      if (uVar6 < 0x1000000) {
        *param_1 = uVar6 * 0x100;
        uVar6 = param_1[4];
        param_1[4] = uVar6 + 1;
        param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + (uVar5 - uVar10) * 0x100;
      }
      uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 0x20c);
      uVar5 = (uint)uVar1 * (*param_1 >> 0xb);
      uVar10 = param_1[1];
      if (uVar5 < uVar10 || uVar5 - uVar10 == 0) {
        uVar6 = *param_1 - uVar5;
        *param_1 = uVar6;
        param_1[1] = uVar10 - uVar5;
        *(ushort *)((int)param_1 + uVar3 * 2 + 0x20c) = uVar1 - (uVar1 >> 5);
        if (uVar6 < 0x1000000) {
          uVar7 = param_1[4];
          param_1[4] = uVar7 + 1;
          *param_1 = uVar6 * 0x100;
          param_1[1] = (uint)*(byte *)(param_1[3] + uVar7) + (uVar10 - uVar5) * 0x100;
        }
        uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 0x224);
        uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
        uVar5 = param_1[1];
        uVar10 = param_1[0x15];
        if (uVar6 < uVar5 || uVar6 - uVar5 == 0) {
          uVar7 = *param_1 - uVar6;
          *param_1 = uVar7;
          param_1[1] = uVar5 - uVar6;
          *(ushort *)((int)param_1 + uVar3 * 2 + 0x224) = uVar1 - (uVar1 >> 5);
          if (uVar7 < 0x1000000) {
            *param_1 = uVar7 * 0x100;
            uVar7 = param_1[4];
            param_1[4] = uVar7 + 1;
            param_1[1] = (uint)*(byte *)(param_1[3] + uVar7) + (uVar5 - uVar6) * 0x100;
          }
          uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 0x23c);
          uVar6 = param_1[1];
          uVar5 = (uint)uVar1 * (*param_1 >> 0xb);
          uVar7 = param_1[0x16];
          if (uVar5 < uVar6 || uVar5 - uVar6 == 0) {
            param_1[1] = uVar6 - uVar5;
            *param_1 = *param_1 - uVar5;
            *(ushort *)((int)param_1 + uVar3 * 2 + 0x23c) = uVar1 - (uVar1 >> 5);
            uVar5 = param_1[0x17];
            param_1[0x17] = uVar7;
          }
          else {
            *param_1 = uVar5;
            *(ushort *)((int)param_1 + uVar3 * 2 + 0x23c) =
                 uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
            uVar5 = uVar7;
          }
          param_1[0x16] = uVar10;
        }
        else {
          *param_1 = uVar6;
          *(ushort *)((int)param_1 + uVar3 * 2 + 0x224) =
               uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
          uVar5 = uVar10;
        }
        uVar10 = param_1[0x14];
        param_1[0x14] = uVar5;
        param_1[0x15] = uVar10;
      }
      else {
        *param_1 = uVar5;
        *(ushort *)((int)param_1 + uVar3 * 2 + 0x20c) =
             uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
        if (uVar5 < 0x1000000) {
          uVar6 = param_1[4];
          *param_1 = uVar5 * 0x100;
          param_1[4] = uVar6 + 1;
          param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + uVar10 * 0x100;
        }
        uVar1 = *(ushort *)((int)param_1 + iVar4 * 2 + 0x254);
        uVar10 = (uint)uVar1 * (*param_1 >> 0xb);
        uVar5 = param_1[1];
        if (uVar5 <= uVar10 && uVar10 - uVar5 != 0) {
          *param_1 = uVar10;
          *(ushort *)((int)param_1 + iVar4 * 2 + 0x254) =
               uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
          uVar9 = 9;
          if (6 < uVar3) {
            uVar9 = 0xb;
          }
          *(undefined1 *)(param_1 + 0x18) = uVar9;
          param_1[0x19] = 1;
          goto LAB_1000253a;
        }
        param_1[1] = uVar5 - uVar10;
        *param_1 = *param_1 - uVar10;
        *(ushort *)((int)param_1 + iVar4 * 2 + 0x254) = uVar1 - (uVar1 >> 5);
      }
      uVar9 = 8;
      if (6 < uVar3) {
        uVar9 = 0xb;
      }
      *(undefined1 *)(param_1 + 0x18) = uVar9;
      FUN_100020c0(param_1,(int)param_1 + DAT_10002874,uVar2);
    }
    else {
      *param_1 = uVar10;
      *(ushort *)((int)param_1 + uVar3 * 2 + 500) = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5)
      ;
      uVar9 = 7;
      if (6 < uVar3) {
        uVar9 = 10;
      }
      *(undefined1 *)(param_1 + 0x18) = uVar9;
      param_1[0x17] = param_1[0x16];
      param_1[0x16] = param_1[0x15];
      param_1[0x15] = param_1[0x14];
      FUN_100020c0(param_1,param_1 + 0x1b6,uVar2);
      uVar5 = param_1[0x19];
      if (5 < uVar5) {
        uVar5 = 5;
      }
      uVar10 = 1;
      do {
        uVar10 = uVar10 * 2;
        puVar13 = (ushort *)((int)param_1 + uVar10 + uVar5 * 0x80 + 0x2d4);
        if (*param_1 < 0x1000000) {
          *param_1 = *param_1 << 8;
          uVar6 = param_1[4];
          param_1[4] = uVar6 + 1;
          param_1[1] = (uint)*(byte *)(param_1[3] + uVar6) + param_1[1] * 0x100;
        }
        uVar1 = *puVar13;
        uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
        uVar2 = param_1[1];
        if (uVar6 < uVar2 || uVar6 - uVar2 == 0) {
          param_1[1] = uVar2 - uVar6;
          *param_1 = *param_1 - uVar6;
          uVar10 = uVar10 + 1;
          *puVar13 = uVar1 - (uVar1 >> 5);
        }
        else {
          *param_1 = uVar6;
          *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
        }
        iVar4 = DAT_1000286c;
      } while (uVar10 < 0x40);
      uVar10 = uVar10 - 0x40;
      if (uVar10 < 4) {
        param_1[0x14] = uVar10;
      }
      else {
        uVar5 = (uVar10 & 1) + 2;
        if (uVar10 < 0xe) {
          uVar6 = (uVar10 >> 1) - 1;
          uVar5 = uVar5 << (uVar6 & 0xff);
          param_1[0x14] = uVar5;
          iVar11 = (uVar5 - uVar10) + DAT_10002870;
          uVar5 = 0;
          iVar12 = 1;
          do {
            puVar13 = (ushort *)((int)param_1 + (iVar11 + iVar12) * 2 + iVar4);
            if (*param_1 < 0x1000000) {
              *param_1 = *param_1 << 8;
              uVar10 = param_1[4];
              param_1[4] = uVar10 + 1;
              param_1[1] = (uint)*(byte *)(param_1[3] + uVar10) + param_1[1] * 0x100;
            }
            uVar1 = *puVar13;
            uVar10 = (uint)uVar1 * (*param_1 >> 0xb);
            uVar2 = param_1[1];
            iVar12 = iVar12 * 2;
            if (uVar10 < uVar2 || uVar10 - uVar2 == 0) {
              *param_1 = *param_1 - uVar10;
              uVar3 = param_1[0x14];
              param_1[1] = uVar2 - uVar10;
              *puVar13 = uVar1 - (uVar1 >> 5);
              iVar12 = iVar12 + 1;
              param_1[0x14] = (1 << (uVar5 & 0xff)) + uVar3;
            }
            else {
              *param_1 = uVar10;
              *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar6);
        }
        else {
          param_1[0x14] = uVar5;
          iVar4 = (uVar10 >> 1) - 5;
          do {
            if (*param_1 < 0x1000000) {
              *param_1 = *param_1 << 8;
              uVar5 = param_1[4];
              param_1[4] = uVar5 + 1;
              param_1[1] = (uint)*(byte *)(param_1[3] + uVar5) + param_1[1] * 0x100;
            }
            iVar4 = iVar4 + -1;
            uVar10 = *param_1 >> 1;
            *param_1 = uVar10;
            uVar5 = (int)(param_1[1] - uVar10) >> 0x1f;
            param_1[1] = (uVar10 & uVar5) + (param_1[1] - uVar10);
            uVar5 = param_1[0x14] * 2 + 1 + uVar5;
            param_1[0x14] = uVar5;
          } while (iVar4 != 0);
          param_1[0x14] = uVar5 * 0x10;
          iVar4 = 1;
          uVar5 = 0;
          do {
            puVar13 = (ushort *)((int)param_1 + iVar4 * 2 + 0x6b8);
            if (*param_1 < 0x1000000) {
              *param_1 = *param_1 << 8;
              uVar10 = param_1[4];
              param_1[4] = uVar10 + 1;
              param_1[1] = (uint)*(byte *)(param_1[3] + uVar10) + param_1[1] * 0x100;
            }
            uVar1 = *puVar13;
            uVar10 = (uint)uVar1 * (*param_1 >> 0xb);
            uVar6 = param_1[1];
            iVar4 = iVar4 * 2;
            if (uVar10 < uVar6 || uVar10 - uVar6 == 0) {
              uVar2 = param_1[0x14];
              *param_1 = *param_1 - uVar10;
              param_1[1] = uVar6 - uVar10;
              *puVar13 = uVar1 - (uVar1 >> 5);
              iVar4 = iVar4 + 1;
              param_1[0x14] = (1 << (uVar5 & 0xff)) + uVar2;
            }
            else {
              *param_1 = uVar10;
              *puVar13 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 != 4);
        }
      }
    }
LAB_1000253a:
    if (((param_1[9] <= param_1[0x14]) || (param_1[0xc] <= param_1[0x14])) ||
       (iVar4 = FUN_100021ea(param_1 + 6,param_1 + 0x19), iVar4 == 0)) {
      return 0;
    }
  } while( true );
}


