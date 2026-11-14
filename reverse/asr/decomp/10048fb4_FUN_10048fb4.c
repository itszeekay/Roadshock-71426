// FUNC 0x10048fb4  FUN_10048fb4

undefined8 FUN_10048fb4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  iVar9 = -((int)param_2 >> 0x1f);
  uVar10 = param_1 >> 0x1d;
  uVar13 = (param_4 << 1) >> 0x15;
  uVar3 = (param_2 << 0xc) >> 9 | uVar10;
  uVar11 = param_1 * 8;
  uVar14 = param_3 >> 0x1d;
  uVar8 = (param_2 << 1) >> 0x15;
  iVar6 = -((int)param_4 >> 0x1f);
  uVar1 = (param_4 << 0xc) >> 9 | uVar14;
  uVar5 = param_3 * 8;
  uVar4 = uVar3;
  uVar12 = uVar11;
  if (iVar9 == iVar6) {
    uVar7 = uVar8 - uVar13;
    if (0 < (int)uVar7) {
      if (uVar13 == 0) {
        if (uVar1 != 0 || uVar5 != 0) {
          uVar7 = uVar7 - 1;
          if (uVar7 == 0) {
            uVar10 = uVar11 + uVar5;
            uVar4 = (uint)(uVar10 < uVar11) + uVar3 + uVar1;
            goto LAB_10049184;
          }
          if (uVar8 != DAT_10049604) goto LAB_10049164;
        }
      }
      else if (uVar8 != DAT_10049350) {
        uVar1 = uVar1 | 0x800000;
LAB_10049164:
        if ((int)uVar7 < 0x39) {
          if ((int)uVar7 < 0x20) {
            uVar10 = (uint)(uVar5 << (0x20 - uVar7 & 0xff) != 0) |
                     uVar1 << (0x20 - uVar7 & 0xff) | uVar5 >> (uVar7 & 0xff);
            uVar1 = uVar1 >> (uVar7 & 0xff);
          }
          else {
            if (uVar7 == 0x20) {
              iVar6 = 0;
            }
            else {
              iVar6 = uVar1 << (0x40 - uVar7 & 0xff);
            }
            uVar10 = uVar1 >> (uVar7 - 0x20 & 0xff) | (uint)(uVar5 != 0 || iVar6 != 0);
            uVar1 = 0;
          }
        }
        else {
          uVar10 = (uint)(uVar5 != 0 || uVar1 != 0);
          uVar1 = 0;
        }
        uVar10 = uVar10 + uVar11;
        uVar4 = (uint)(uVar10 < uVar11) + uVar1 + uVar3;
LAB_10049184:
        if (-1 < (int)(uVar4 << 8)) goto LAB_10049124;
        uVar13 = uVar8 + 1;
        if (uVar13 == DAT_10049350) goto LAB_1004940e;
        uVar11 = DAT_10049354 & uVar4;
        uVar4 = uVar11 >> 1;
        uVar8 = uVar13;
        uVar12 = uVar11 << 0x1f | uVar10 & 1 | uVar10 >> 1;
      }
LAB_10049006:
      uVar10 = uVar12;
      if ((uVar12 & 7) != 0) {
LAB_1004900a:
        uVar10 = uVar12;
        if ((uVar12 & 0xf) != 4) {
          uVar10 = uVar12 + 4;
          uVar4 = uVar4 + (uVar10 < uVar12);
        }
      }
      if ((int)(uVar4 << 8) < 0) {
        uVar8 = uVar8 + 1;
        if (uVar8 == DAT_10049350) {
          uVar11 = 0;
          uVar12 = 0;
        }
        else {
          uVar12 = uVar10 >> 3 | (uVar4 & DAT_10049354) << 0x1d;
          uVar11 = ((uVar4 & DAT_10049354) << 9) >> 0xc;
          uVar8 = uVar8 & 0x7ff;
        }
        goto LAB_10049044;
      }
      goto LAB_1004912a;
    }
    if (uVar7 != 0) {
      if (uVar8 == 0) {
        uVar4 = uVar1;
        uVar8 = uVar13;
        uVar12 = uVar5;
        if (uVar3 != 0 || uVar11 != 0) {
          uVar7 = ~uVar7;
          if (uVar7 == 0) goto LAB_1004949c;
          if (uVar13 != DAT_10049604) goto LAB_1004946c;
        }
      }
      else {
        uVar4 = uVar1;
        uVar8 = uVar13;
        uVar12 = uVar5;
        if (uVar13 != DAT_10049604) {
          uVar7 = -uVar7;
          uVar3 = uVar3 | 0x800000;
LAB_1004946c:
          if ((int)uVar7 < 0x39) {
            if ((int)uVar7 < 0x20) {
              uVar12 = uVar3 << (0x20 - uVar7 & 0xff);
              uVar3 = uVar3 >> (uVar7 & 0xff);
              uVar11 = (uint)(uVar11 << (0x20 - uVar7 & 0xff) != 0) |
                       uVar12 | uVar11 >> (uVar7 & 0xff);
            }
            else {
              uVar12 = uVar3 >> (uVar7 - 0x20 & 0xff);
              if (uVar7 == 0x20) {
                iVar6 = 0;
              }
              else {
                iVar6 = uVar3 << (0x40 - uVar7 & 0xff);
              }
              uVar3 = 0;
              uVar11 = (uVar11 != 0 || iVar6 != 0) | uVar12;
            }
          }
          else {
            uVar11 = (uint)(uVar11 != 0 || uVar3 != 0);
            uVar3 = 0;
          }
LAB_1004949c:
          uVar10 = uVar11 + uVar5;
          uVar4 = (uint)(uVar10 < uVar5) + uVar3 + uVar1;
          uVar8 = uVar13;
          goto LAB_10049184;
        }
      }
      goto LAB_10049006;
    }
    uVar13 = uVar8 + 1;
    if ((uVar13 & 0x7ff) < 2) {
      if (uVar8 == 0) {
        uVar4 = uVar1;
        uVar12 = uVar5;
        if ((uVar3 != 0 || uVar11 != 0) &&
           (uVar4 = uVar3, uVar12 = uVar11, uVar1 != 0 || uVar5 != 0)) {
          uVar10 = uVar11 + uVar5;
          uVar4 = (uint)(uVar10 < uVar11) + uVar3 + uVar1;
          if (-1 < (int)(uVar4 * 0x100)) goto LAB_10049124;
          uVar4 = uVar4 & DAT_10049608;
          uVar8 = uVar13;
          uVar12 = uVar10;
        }
      }
      else {
        uVar4 = uVar1;
        uVar8 = DAT_10049604;
        uVar12 = uVar5;
        if ((uVar3 != 0 || uVar11 != 0) &&
           (uVar4 = uVar3, uVar12 = uVar11, uVar1 != 0 || uVar5 != 0)) {
          uVar12 = uVar10 << 0x1d | param_1 & 0x1fffffff;
          uVar11 = param_2 & 0xfffff;
          if (((param_2 & 0x80000) != 0) && ((param_4 & 0x80000) == 0)) {
            uVar12 = uVar14 << 0x1d | param_3 & 0x1fffffff;
            uVar11 = param_4 & 0xfffff;
          }
          uVar4 = uVar11 << 3 | uVar12 >> 0x1d;
          uVar12 = uVar12 << 3;
        }
      }
      goto LAB_10049006;
    }
    if (uVar13 != DAT_10049350) {
      uVar12 = (uint)(uVar11 + uVar5 < uVar11) + uVar3 + uVar1;
      uVar4 = uVar12 >> 1;
      uVar8 = uVar13;
      uVar12 = uVar12 * -0x80000000 | uVar11 + uVar5 >> 1;
      goto LAB_10049006;
    }
LAB_1004940e:
    uVar11 = 0;
    uVar12 = 0;
    uVar8 = uVar13;
  }
  else {
    uVar7 = uVar8 - uVar13;
    if ((int)uVar7 < 1) {
      if (uVar7 == 0) {
        if ((uVar8 + 1 & 0x7ff) < 2) {
          if (uVar8 == 0) {
            if (uVar3 == 0 && uVar11 == 0) {
              uVar4 = uVar1;
              uVar12 = uVar5;
              iVar9 = iVar6;
              if (uVar1 == 0 && uVar5 == 0) {
LAB_1004958a:
                uVar11 = 0;
                iVar9 = 0;
                uVar12 = 0;
                goto LAB_10049134;
              }
            }
            else if (uVar1 != 0 || uVar5 != 0) {
              uVar10 = uVar11 + param_3 * -8;
              uVar4 = (uVar3 - uVar1) - (uint)(uVar11 < uVar10);
              if (-1 < (int)(uVar4 * 0x100)) {
                if (uVar10 != 0 || uVar4 != 0) goto LAB_10049124;
                goto LAB_1004958a;
              }
              uVar12 = uVar5 + param_1 * -8;
              uVar4 = (uVar1 - uVar3) - (uint)(uVar5 < uVar12);
              iVar9 = iVar6;
            }
          }
          else if (uVar3 == 0 && uVar11 == 0) {
            uVar4 = uVar1;
            uVar8 = DAT_10049604;
            uVar12 = uVar5;
            iVar9 = iVar6;
            if (uVar1 == 0 && uVar5 == 0) {
              iVar9 = 0;
              uVar11 = 0x80000;
              uVar12 = 0;
              goto LAB_10049134;
            }
          }
          else {
            uVar8 = DAT_10049604;
            if (uVar1 != 0 || uVar5 != 0) {
              uVar12 = uVar10 << 0x1d | param_1 & 0x1fffffff;
              uVar11 = param_2 & 0xfffff;
              if (((param_2 & 0x80000) != 0) && ((param_4 & 0x80000) == 0)) {
                uVar12 = uVar14 << 0x1d | param_3 & 0x1fffffff;
                uVar11 = param_4 & 0xfffff;
                iVar9 = iVar6;
              }
              uVar4 = uVar11 << 3 | uVar12 >> 0x1d;
              uVar12 = uVar12 << 3;
            }
          }
        }
        else {
          uVar10 = uVar11 + param_3 * -8;
          uVar4 = (uVar3 - uVar1) - (uint)(uVar11 < uVar10);
          if ((int)(uVar4 * 0x100) < 0) {
            uVar10 = uVar5 + param_1 * -8;
            uVar4 = (uVar1 - uVar3) - (uint)(uVar5 < uVar10);
            iVar9 = iVar6;
          }
          else if (uVar10 == 0 && uVar4 == 0) {
            iVar9 = 0;
            uVar8 = 0;
            uVar12 = 0;
            uVar11 = 0;
            goto LAB_10049134;
          }
LAB_100490c4:
          if (uVar4 == 0) {
            iVar2 = FUN_10056d78(uVar10);
            iVar6 = iVar2 + 0x20;
            uVar11 = iVar2 + 0x18;
            if ((int)uVar11 < 0x20) goto LAB_100490da;
LAB_10049246:
            uVar10 = uVar10 << (iVar6 - 0x28U & 0xff);
            uVar12 = 0;
          }
          else {
            iVar6 = FUN_10056d78(uVar4);
            uVar11 = iVar6 - 8;
            if (0x1f < (int)uVar11) goto LAB_10049246;
LAB_100490da:
            uVar12 = uVar10 << (uVar11 & 0xff);
            uVar10 = uVar10 >> (0x20 - uVar11 & 0xff) | uVar4 << (uVar11 & 0xff);
          }
          if ((int)uVar11 < (int)uVar8) {
            uVar4 = DAT_10049354 & uVar10;
            uVar8 = uVar8 - uVar11;
          }
          else {
            uVar1 = (uVar11 - uVar8) + 1;
            if (0x1f < (int)uVar1) {
              if (uVar1 == 0x20) {
                iVar6 = 0;
              }
              else {
                iVar6 = uVar10 << (0x40 - uVar1 & 0xff);
              }
              uVar4 = 0;
              uVar10 = (uint)(uVar12 != 0 || iVar6 != 0) |
                       uVar10 >> ((uVar11 - uVar8) - 0x1f & 0xff);
              uVar8 = 0;
              goto LAB_10049124;
            }
            uVar4 = uVar10 >> (uVar1 & 0xff);
            uVar8 = 0;
            uVar12 = (uint)(uVar12 << (0x20 - uVar1 & 0xff) != 0) |
                     uVar10 << (0x20 - uVar1 & 0xff) | uVar12 >> (uVar1 & 0xff);
          }
        }
      }
      else if (uVar8 == 0) {
        uVar4 = uVar1;
        uVar8 = uVar13;
        uVar12 = uVar5;
        iVar9 = iVar6;
        if (uVar3 != 0 || uVar11 != 0) {
          uVar7 = ~uVar7;
          if (uVar7 == 0) {
            uVar10 = uVar5 + param_1 * -8;
            uVar4 = (uVar1 - uVar3) - (uint)(uVar5 < uVar10);
            goto LAB_100490bc;
          }
          if (uVar13 != DAT_10049604) goto LAB_100492fc;
        }
      }
      else {
        uVar4 = uVar1;
        uVar8 = uVar13;
        uVar12 = uVar5;
        iVar9 = iVar6;
        if (uVar13 != DAT_10049350) {
          uVar7 = -uVar7;
          uVar3 = uVar3 | 0x800000;
LAB_100492fc:
          if ((int)uVar7 < 0x39) {
            if ((int)uVar7 < 0x20) {
              uVar12 = uVar3 >> (uVar7 & 0xff);
              uVar10 = uVar11 >> (uVar7 & 0xff) | uVar3 << (0x20 - uVar7 & 0xff) |
                       (uint)(uVar11 << (0x20 - uVar7 & 0xff) != 0);
            }
            else {
              if (uVar7 == 0x20) {
                iVar9 = 0;
              }
              else {
                iVar9 = uVar3 << (0x40 - uVar7 & 0xff);
              }
              uVar12 = 0;
              uVar10 = uVar3 >> (uVar7 - 0x20 & 0xff) | (uint)(uVar11 != 0 || iVar9 != 0);
            }
          }
          else {
            uVar10 = (uint)(uVar11 != 0 || uVar3 != 0);
            uVar12 = 0;
          }
          uVar10 = uVar5 - uVar10;
          uVar4 = (uVar1 - uVar12) - (uint)(uVar5 < uVar10);
          uVar8 = uVar13;
          iVar9 = iVar6;
          goto LAB_100490bc;
        }
      }
      goto LAB_10049006;
    }
    if (uVar13 == 0) {
      if (uVar1 != 0 || uVar5 != 0) {
        uVar7 = uVar7 - 1;
        if (uVar7 == 0) {
          uVar10 = uVar11 + param_3 * -8;
          uVar4 = (uVar3 - uVar1) - (uint)(uVar11 < uVar10);
          goto LAB_100490bc;
        }
        if (uVar8 != DAT_10049350) goto LAB_1004907e;
      }
      goto LAB_10049006;
    }
    if (uVar8 == DAT_10049350) goto LAB_10049006;
    uVar1 = uVar1 | 0x800000;
LAB_1004907e:
    if ((int)uVar7 < 0x39) {
      if ((int)uVar7 < 0x20) {
        uVar10 = uVar5 >> (uVar7 & 0xff) | uVar1 << (0x20 - uVar7 & 0xff) |
                 (uint)(uVar5 << (0x20 - uVar7 & 0xff) != 0);
        uVar1 = uVar1 >> (uVar7 & 0xff);
      }
      else {
        if (uVar7 == 0x20) {
          iVar6 = 0;
        }
        else {
          iVar6 = uVar1 << (0x40 - uVar7 & 0xff);
        }
        uVar10 = uVar1 >> (uVar7 - 0x20 & 0xff) | (uint)(uVar5 != 0 || iVar6 != 0);
        uVar1 = 0;
      }
    }
    else {
      uVar10 = (uint)(uVar5 != 0 || uVar1 != 0);
      uVar1 = 0;
    }
    uVar10 = uVar11 - uVar10;
    uVar4 = (uVar3 - uVar1) - (uint)(uVar11 < uVar10);
LAB_100490bc:
    if ((int)(uVar4 << 8) < 0) {
      uVar4 = uVar4 & 0x7fffff;
      goto LAB_100490c4;
    }
LAB_10049124:
    uVar12 = uVar10;
    if ((uVar10 & 7) != 0) goto LAB_1004900a;
LAB_1004912a:
    uVar11 = uVar4 >> 3;
    uVar12 = uVar10 >> 3 | uVar4 << 0x1d;
  }
LAB_10049134:
  if (uVar8 == DAT_10049350) {
    if (uVar12 == 0 && uVar11 == 0) {
      uVar11 = 0;
      uVar12 = 0;
    }
    else {
      uVar11 = uVar11 & 0xfffff | 0x80000;
    }
  }
  else {
    uVar11 = uVar11 & 0xfffff;
    uVar8 = uVar8 & 0x7ff;
  }
LAB_10049044:
  return CONCAT44(DAT_10049358 & uVar11 | (uVar8 << 0x15) >> 1 | iVar9 << 0x1f,uVar12);
}


