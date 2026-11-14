// FUNC 0x1004cbe8  FUN_1004cbe8

undefined4 FUN_1004cbe8(byte *param_1)

{
  uint uVar1;
  int iVar2;
  int extraout_r1;
  uint uVar3;
  uint *puVar4;
  uint unaff_r6;
  
  if (param_1 != (byte *)0x0) {
    uVar3 = (uint)*param_1;
    if (uVar3 < 8) {
      uVar3 = uVar3 * 4;
      uVar3 = *(int *)(uVar3 + DAT_1004cdd4) << (uVar3 & 0xff) |
              *DAT_1004cdd0 & ~(0xf << (uVar3 & 0xff));
      puVar4 = DAT_1004cdd0;
    }
    else {
      if (uVar3 < 0x10) {
        iVar2 = uVar3 - 8;
        uVar1 = *DAT_1004cdd8;
        puVar4 = DAT_1004cdd8;
      }
      else if (uVar3 < 0x18) {
        iVar2 = uVar3 - 0x10;
        uVar1 = *DAT_1004cddc;
        puVar4 = DAT_1004cddc;
      }
      else {
        if (0x1e < uVar3) {
          return 0xffffffff;
        }
        iVar2 = uVar3 - 0x18;
        uVar1 = *DAT_1004cde0;
        puVar4 = DAT_1004cde0;
      }
      uVar3 = *(int *)(uVar3 * 4 + DAT_1004cdd4) << (iVar2 << 2 & 0xffU) |
              uVar1 & ~(0xf << (iVar2 << 2 & 0xffU));
    }
    *puVar4 = uVar3;
    uVar3 = (uint)*param_1;
    if (uVar3 < 0x10) {
      if (param_1[1] < 8) {
        FUN_10056ee8();
        uVar3 = 1 << (uVar3 & 0xff);
        if ((uVar3 & *(uint *)(DAT_1004cde4 + 0x10)) != 0) {
          *(uint *)(DAT_1004cde4 + 0x14) = uVar3;
        }
        *DAT_1004cde8 =
             *DAT_1004cde8 & ~(3 << ((uint)*param_1 << 1 & 0xff)) |
             1 << ((uint)*param_1 << 1 & 0xff);
        *DAT_1004cdec = 1 << *param_1 | *DAT_1004cdec;
        return 0;
      }
    }
    else if (param_1[1] < 8) {
      FUN_10056ee8();
      puVar4[0x11] = (uint)puVar4;
      *(int *)(extraout_r1 + 100) = extraout_r1;
      puVar4[0x1a] = unaff_r6;
      uVar3 = 1 << (uVar3 - 0x10 & 0xff);
      if ((uVar3 & *(uint *)(DAT_1004cdf0 + 0x10)) != 0) {
        *(uint *)(DAT_1004cdf0 + 0x14) = uVar3;
      }
      uVar3 = (*param_1 - 0x10) * 2;
      *DAT_1004cdf4 = 1 << (uVar3 & 0xff) | *DAT_1004cdf4 & ~(3 << (uVar3 & 0xff));
      *DAT_1004cdec = *DAT_1004cdec | 1 << *param_1;
      if (*param_1 < 0x1b) {
        return 0;
      }
      uVar3 = 1 << (uint)*param_1;
      *DAT_1004cdf8 = *DAT_1004cdf8 & ~uVar3 | uVar3;
      *DAT_1004cdfc = 1 << *param_1 | *DAT_1004cdfc & ~(1 << *param_1);
      return 0;
    }
  }
  return 0xffffffff;
}


