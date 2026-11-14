/*
 * ASR5601S application - reconstructed from the SWD dump.
 * Image base 0x10048000, Ghidra 11.3.1, language ARM:LE:32:Cortex.
 * 496 functions, address order.
 *
 * Decompiler output, not original source. Types are approximate.
 * The per-function files and the Ghidra project are kept outside the
 * public repository; this file and the index are the tracked output.
 */

// FUNC 0x10000120  flash_begin

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Re-enables the flash controller after a direct access */

void flash_begin(void)

{
  if ((*_DAT_10000130 & 2) == 0) {
    *_DAT_10000130 = 2;
  }
  return;
}

// FUNC 0x10000134  flash_end

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Releases the flash controller and clears its state */

void flash_end(void)

{
  int *piVar1;
  
  piVar1 = _DAT_10000148;
  if (*_DAT_10000148 << 0x1e < 0) {
    *_DAT_10000148 = 3;
    *piVar1 = 0;
  }
  return;
}

// FUNC 0x1000014c  flash_status

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Returns the flash busy/ready flag */

uint flash_status(void)

{
  return ~(*_DAT_10000158 >> 1) & 1;
}

// FUNC 0x1000015c  flash_exit_powerdown

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Leaves flash deep power-down */

void flash_exit_powerdown(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = _DAT_10000174;
  uVar2 = *_DAT_10000174;
  if ((uVar2 & 2) == 0) {
    *_DAT_10000174 = 2;
    *puVar1 = 3;
    *puVar1 = uVar2 & 2;
  }
  return;
}

// FUNC 0x10000178  delay_loop

/* Short calibrated busy loop */

void delay_loop(char param_1)

{
  do {
    param_1 = param_1 + -1;
  } while (param_1 != -1);
  return;
}

// FUNC 0x10000186  flash_wait_ready

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Waits for the flash controller bit 0x20 */

uint flash_wait_ready(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(_DAT_100001a8 + 8);
  iVar1 = _DAT_100001ac;
  do {
    if ((uVar2 & 0x20) == 0) {
      return uVar2 & 0x20;
    }
    iVar1 = iVar1 + -1;
    uVar2 = *(uint *)(_DAT_100001a8 + 8);
  } while (iVar1 != 0);
  return 1;
}

// FUNC 0x100001b0  flash_wait_ready_long

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Waits for the flash controller bit 0x40 with a longer timeout */

uint flash_wait_ready_long(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0xc9;
  uVar2 = *(uint *)(_DAT_100001d0 + 8);
  do {
    if ((uVar2 & 0x40) == 0) {
      return uVar2 & 0x40;
    }
    iVar1 = iVar1 + -1;
    uVar2 = *(uint *)(_DAT_100001d0 + 8);
  } while (iVar1 != 0);
  return 1;
}

// FUNC 0x100001d4  flash_run_command

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Strobes the flash command register */

void flash_run_command(void)

{
  int iVar1;
  
  iVar1 = _DAT_100001e0;
  *(undefined4 *)(_DAT_100001e0 + 0xc) = _DAT_100001e4;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  return;
}

// FUNC 0x100001e8  flash_arm_command

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Arms the flash controller for a command */

undefined4 flash_arm_command(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = _DAT_100001fc;
  uVar2 = *_DAT_100001fc;
  *_DAT_100001fc = (uVar2 & 0xfffffffd) + 2;
  *puVar1 = uVar2 & 0xfffffffd;
  return 0;
}

// FUNC 0x10000200  flash_set_read_mode

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configures the flash controller for reads */

undefined4 flash_set_read_mode(void)

{
  uint *puVar1;
  
  puVar1 = _DAT_10000234;
  _DAT_10000234[5] = _DAT_10000238;
  *puVar1 = *puVar1 | 0x400000;
  puVar1[4] = 0;
  puVar1[9] = 1;
  puVar1[10] = 0;
  puVar1[0x24] = 1;
  delay_loop(10);
  flash_wait_ready();
  flash_run_command();
  return 0;
}

// FUNC 0x1000023c  flash_set_write_mode

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configures the flash controller for writes */

undefined4 flash_set_write_mode(void)

{
  uint *puVar1;
  
  puVar1 = _DAT_10000270;
  _DAT_10000270[5] = _DAT_10000274;
  *puVar1 = *puVar1 | 0x400000;
  puVar1[4] = 0;
  puVar1[9] = 2;
  puVar1[10] = 2;
  puVar1[0x24] = 1;
  delay_loop(10);
  flash_wait_ready();
  flash_run_command();
  return 0;
}

// FUNC 0x1000035c  flash_set_window

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Programs the flash address window and timing */

void flash_set_window(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  flash_arm_command();
  flash_wait_ready_long();
  iVar2 = _DAT_100003ac;
  piVar1 = _DAT_100003a8;
  iVar3 = *_DAT_100003a0;
  if (*_DAT_100003a0 == 0) {
    iVar3 = _DAT_100003a4;
  }
  *_DAT_100003a8 = iVar3;
  piVar1[1] = 0x140000;
  piVar1[3] = 0;
  piVar1[4] = 0;
  piVar1[5] = iVar2;
  piVar1[6] = 0;
  piVar1[7] = 0;
  piVar1[8] = 0;
  piVar1[9] = 0;
  piVar1[10] = 0;
  piVar1[0xb] = 0;
  piVar1[0xc] = _DAT_100003b0;
  *_DAT_100003b4 = 0x200;
  return;
}

// FUNC 0x100003b8  flash_controller_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Initializes the flash controller after reset */

undefined4 flash_controller_init(void)

{
  *_DAT_100003d4 = 0;
  delay_loop(0x20);
  flash_set_window();
  flash_exit_powerdown();
  return 0;
}

// FUNC 0x100003d8  flash_erase_sector

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Erases one flash sector through the controller */

longlong flash_erase_sector(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  delay_loop(0x20);
  flash_arm_command();
  flash_wait_ready_long();
  puVar2 = _DAT_1000044c;
  iVar1 = _DAT_10000448;
  *(undefined4 *)(_DAT_10000448 + 0x14) = 0x106;
  flash_run_command();
  *puVar2 = 1;
  delay_loop(10);
  flash_wait_ready();
  flash_set_write_mode();
  *(uint *)(iVar1 + 0x14) = param_1;
  if (param_1 != 0x160) {
    *(undefined4 *)(iVar1 + 0x18) = param_2;
  }
  flash_run_command();
  *puVar2 = 1;
  delay_loop(10);
  flash_wait_ready();
  flash_run_command();
  flash_set_read_mode();
  delay_loop(10);
  flash_run_command();
  flash_set_window();
  flash_exit_powerdown();
  return (ulonglong)param_1 << 0x20;
}

// FUNC 0x10000450  flash_program_page

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Programs one flash page, handling unaligned sources */

undefined4 flash_program_page(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 auStack_118 [65];
  
  rom_memset(auStack_118,0,0x100);
  uVar4 = 1;
  if ((param_2 != 0) && (param_3 != (undefined4 *)0x0)) {
    if ((param_3 + -0x4000000 < (undefined4 *)0x8000000) || (((uint)param_3 & 3) != 0)) {
      rom_memcpy(auStack_118,param_3,param_2);
      param_3 = auStack_118;
    }
    uVar6 = param_2 + 3U & 0xfffffffc;
    delay_loop(0x20);
    flash_arm_command();
    flash_wait_ready_long();
    iVar2 = _DAT_1000053c;
    *(undefined4 *)(_DAT_1000053c + 0x14) = 0x106;
    flash_run_command();
    puVar3 = _DAT_10000540;
    *_DAT_10000540 = 1;
    delay_loop(10);
    flash_wait_ready();
    flash_set_write_mode();
    uVar5 = uVar6 - 0x20;
    *(undefined4 *)(iVar2 + 0x14) = _DAT_10000544;
    *(int *)(iVar2 + 0x10) = param_2 + -1;
    *(undefined4 *)(iVar2 + 0x18) = param_1;
    while ((uVar6 != 0 && (uVar5 != uVar6))) {
      if ((*(int *)(iVar2 + 8) >> 8 & 0x38U) == 0) {
        uVar4 = *param_3;
        param_3 = param_3 + 1;
        uVar6 = uVar6 - 4;
        *(undefined4 *)(iVar2 + 0x20) = uVar4;
      }
    }
    delay_loop(10);
    flash_wait_ready();
    *puVar3 = 1;
    delay_loop(10);
    uVar5 = uVar6;
    while (uVar5 != 0) {
      if ((*(int *)(iVar2 + 8) >> 8 & 0x38U) == 0) {
        iVar1 = uVar6 - uVar5;
        uVar5 = uVar5 - 4;
        *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)((int)param_3 + iVar1);
      }
    }
    delay_loop(10);
    flash_wait_ready();
    flash_set_read_mode();
    flash_set_window();
    flash_exit_powerdown();
    uVar4 = 0;
  }
  return uVar4;
}

// FUNC 0x10000720  rom_memcpy

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer into the ROM copy routine */

void rom_memcpy(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10000728. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1000072c)(param_1);
  return;
}

// FUNC 0x10000730  rom_memset

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer into the ROM fill routine */

void rom_memset(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10000738. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_1000073c)(param_1);
  return;
}

// FUNC 0x10000740  strcmp

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Word-optimized string compare with a byte tail */

int strcmp(uint *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    do {
      uVar2 = *param_1;
      param_1 = param_1 + 1;
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      uVar4 = uVar2 - _DAT_100007c4 & ~uVar2 & _DAT_100007c4 << 7;
      if (uVar4 != 0) {
        iVar1 = (uVar2 & 0xff) - (uVar3 & 0xff);
        if ((((uVar4 & 0xff) == 0 && iVar1 == 0) &&
            (iVar1 = (uVar2 & 0xffff) - (uVar3 & 0xffff), (uVar4 & 0xffff) == 0 && iVar1 == 0)) &&
           (iVar1 = (uVar2 & 0xffffff) - (uVar3 & 0xffffff), (uVar4 & 0xffffff) == 0 && iVar1 == 0))
        {
          iVar1 = (uVar2 >> 0x18) - (uVar3 >> 0x18);
        }
        return iVar1;
      }
    } while (uVar2 == uVar3);
    if ((uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18)
        < (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18
          )) {
      return 1;
    }
    return -1;
  }
  while( true ) {
    uVar2 = (uint)(byte)*param_1;
    uVar3 = (uint)(byte)*param_2;
    if ((uVar2 == 0) || (uVar2 != uVar3)) break;
    uVar2 = (uint)*(byte *)((int)param_1 + 1);
    uVar3 = (uint)*(byte *)((int)param_2 + 1);
    param_1 = (uint *)((int)param_1 + 2);
    param_2 = (uint *)((int)param_2 + 2);
    if ((uVar2 == 0) || (uVar2 != uVar3)) break;
  }
  return uVar2 - uVar3;
}

// FUNC 0x100007c8  FUN_100007c8

void FUN_100007c8(void)

{
  return;
}

// FUNC 0x100007dc  FUN_100007dc

undefined8 FUN_100007dc(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}

// FUNC 0x100007f0  FUN_100007f0

undefined8 FUN_100007f0(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}

// FUNC 0x10000804  aeabi_uidivmod

/* Unsigned 32-bit divide and remainder */

undefined8 aeabi_uidivmod(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  iVar5 = 0;
  if (param_2 <= param_1 >> 1) {
    if (param_2 <= param_1 >> 4) {
      if (param_2 <= param_1 >> 8) {
        if (param_1 >> 0xc < param_2) goto LAB_10000870;
        if (param_2 <= param_1 >> 0x10) {
          iVar5 = -0x1000000;
          uVar1 = param_2 << 8;
          if (param_2 << 8 <= param_1 >> 0x10) {
            iVar5 = -0x10000;
            uVar1 = param_2 << 0x10;
            if (param_2 << 0x10 == 0) {
              uVar4 = aeabi_idiv0(0);
              return CONCAT44(param_1,uVar4);
            }
          }
          param_2 = uVar1;
          if (param_1 >> 0xc < param_2) goto LAB_10000870;
        }
        while( true ) {
          bVar6 = param_2 <= param_1 >> 0xf;
          uVar1 = param_1;
          if (bVar6) {
            uVar1 = param_1 + param_2 * -0x8000;
          }
          bVar10 = param_2 * 0x8000 <= param_1;
          bVar7 = param_2 <= uVar1 >> 0xe;
          uVar2 = uVar1;
          if (bVar7) {
            uVar2 = uVar1 + param_2 * -0x4000;
          }
          bVar8 = param_2 <= uVar2 >> 0xd;
          uVar3 = uVar2;
          if (bVar8) {
            uVar3 = uVar2 + param_2 * -0x2000;
          }
          bVar9 = param_2 <= uVar3 >> 0xc;
          param_1 = uVar3;
          if (bVar9) {
            param_1 = uVar3 + param_2 * -0x1000;
          }
          iVar5 = (((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 +
                   (uint)(bVar7 && param_2 * 0x4000 <= uVar1)) * 2 +
                  (uint)(bVar8 && param_2 * 0x2000 <= uVar2)) * 2 +
                  (uint)(bVar9 && param_2 * 0x1000 <= uVar3);
LAB_10000870:
          bVar6 = param_2 <= param_1 >> 0xb;
          uVar1 = param_1;
          if (bVar6) {
            uVar1 = param_1 + param_2 * -0x800;
          }
          bVar10 = param_2 <= uVar1 >> 10;
          uVar2 = uVar1;
          if (bVar10) {
            uVar2 = uVar1 + param_2 * -0x400;
          }
          bVar7 = param_2 <= uVar2 >> 9;
          uVar3 = uVar2;
          if (bVar7) {
            uVar3 = uVar2 + param_2 * -0x200;
          }
          uVar1 = ((iVar5 * 2 + (uint)(bVar6 && param_2 * 0x800 <= param_1)) * 2 +
                  (uint)(bVar10 && param_2 * 0x400 <= uVar1)) * 2 +
                  (uint)(bVar7 && param_2 * 0x200 <= uVar2);
          bVar6 = param_2 <= uVar3 >> 8;
          param_1 = uVar3;
          if (bVar6) {
            param_1 = uVar3 + param_2 * -0x100;
          }
          bVar6 = bVar6 && param_2 * 0x100 <= uVar3;
          iVar5 = uVar1 * 2 + (uint)bVar6;
          if (!CARRY4(uVar1,uVar1) && !CARRY4(uVar1 * 2,(uint)bVar6)) break;
          param_2 = param_2 >> 8;
        }
      }
      bVar6 = param_2 <= param_1 >> 7;
      uVar1 = param_1;
      if (bVar6) {
        uVar1 = param_1 + param_2 * -0x80;
      }
      bVar10 = param_2 * 0x80 <= param_1;
      bVar7 = param_2 <= uVar1 >> 6;
      uVar2 = uVar1;
      if (bVar7) {
        uVar2 = uVar1 + param_2 * -0x40;
      }
      bVar8 = param_2 <= uVar2 >> 5;
      uVar3 = uVar2;
      if (bVar8) {
        uVar3 = uVar2 + param_2 * -0x20;
      }
      bVar9 = param_2 <= uVar3 >> 4;
      param_1 = uVar3;
      if (bVar9) {
        param_1 = uVar3 + param_2 * -0x10;
      }
      iVar5 = (((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 + (uint)(bVar7 && param_2 * 0x40 <= uVar1)
               ) * 2 + (uint)(bVar8 && param_2 * 0x20 <= uVar2)) * 2 +
              (uint)(bVar9 && param_2 * 0x10 <= uVar3);
    }
    bVar6 = param_2 <= param_1 >> 3;
    uVar1 = param_1;
    if (bVar6) {
      uVar1 = param_1 + param_2 * -8;
    }
    bVar10 = param_2 * 8 <= param_1;
    bVar7 = param_2 <= uVar1 >> 2;
    uVar2 = uVar1;
    if (bVar7) {
      uVar2 = uVar1 + param_2 * -4;
    }
    bVar8 = param_2 <= uVar2 >> 1;
    param_1 = uVar2;
    if (bVar8) {
      param_1 = uVar2 + param_2 * -2;
    }
    iVar5 = ((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 + (uint)(bVar7 && param_2 * 4 <= uVar1)) * 2
            + (uint)(bVar8 && param_2 * 2 <= uVar2);
  }
  uVar1 = param_1 - param_2;
  if (param_2 > param_1) {
    uVar1 = param_1;
  }
  return CONCAT44(uVar1,iVar5 * 2 + (uint)(param_2 <= param_1));
}

// FUNC 0x10000910  aeabi_uidiv

/* Unsigned 32-bit divide */

undefined8 aeabi_uidiv(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  if (param_2 != 0) {
    iVar5 = 0;
    if (param_2 <= param_1 >> 1) {
      if (param_2 <= param_1 >> 4) {
        if (param_2 <= param_1 >> 8) {
          if (param_1 >> 0xc < param_2) goto LAB_10000870;
          if (param_2 <= param_1 >> 0x10) {
            iVar5 = -0x1000000;
            uVar1 = param_2 << 8;
            if (param_2 << 8 <= param_1 >> 0x10) {
              iVar5 = -0x10000;
              uVar1 = param_2 << 0x10;
              if (param_2 << 0x10 == 0) goto LAB_10000904;
            }
            param_2 = uVar1;
            if (param_1 >> 0xc < param_2) goto LAB_10000870;
          }
          while( true ) {
            bVar6 = param_2 <= param_1 >> 0xf;
            uVar1 = param_1;
            if (bVar6) {
              uVar1 = param_1 + param_2 * -0x8000;
            }
            bVar10 = param_2 * 0x8000 <= param_1;
            bVar7 = param_2 <= uVar1 >> 0xe;
            uVar2 = uVar1;
            if (bVar7) {
              uVar2 = uVar1 + param_2 * -0x4000;
            }
            bVar8 = param_2 <= uVar2 >> 0xd;
            uVar3 = uVar2;
            if (bVar8) {
              uVar3 = uVar2 + param_2 * -0x2000;
            }
            bVar9 = param_2 <= uVar3 >> 0xc;
            param_1 = uVar3;
            if (bVar9) {
              param_1 = uVar3 + param_2 * -0x1000;
            }
            iVar5 = (((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 +
                     (uint)(bVar7 && param_2 * 0x4000 <= uVar1)) * 2 +
                    (uint)(bVar8 && param_2 * 0x2000 <= uVar2)) * 2 +
                    (uint)(bVar9 && param_2 * 0x1000 <= uVar3);
LAB_10000870:
            bVar6 = param_2 <= param_1 >> 0xb;
            uVar1 = param_1;
            if (bVar6) {
              uVar1 = param_1 + param_2 * -0x800;
            }
            bVar10 = param_2 <= uVar1 >> 10;
            uVar2 = uVar1;
            if (bVar10) {
              uVar2 = uVar1 + param_2 * -0x400;
            }
            bVar7 = param_2 <= uVar2 >> 9;
            uVar3 = uVar2;
            if (bVar7) {
              uVar3 = uVar2 + param_2 * -0x200;
            }
            uVar1 = ((iVar5 * 2 + (uint)(bVar6 && param_2 * 0x800 <= param_1)) * 2 +
                    (uint)(bVar10 && param_2 * 0x400 <= uVar1)) * 2 +
                    (uint)(bVar7 && param_2 * 0x200 <= uVar2);
            bVar6 = param_2 <= uVar3 >> 8;
            param_1 = uVar3;
            if (bVar6) {
              param_1 = uVar3 + param_2 * -0x100;
            }
            bVar6 = bVar6 && param_2 * 0x100 <= uVar3;
            iVar5 = uVar1 * 2 + (uint)bVar6;
            if (!CARRY4(uVar1,uVar1) && !CARRY4(uVar1 * 2,(uint)bVar6)) break;
            param_2 = param_2 >> 8;
          }
        }
        bVar6 = param_2 <= param_1 >> 7;
        uVar1 = param_1;
        if (bVar6) {
          uVar1 = param_1 + param_2 * -0x80;
        }
        bVar10 = param_2 * 0x80 <= param_1;
        bVar7 = param_2 <= uVar1 >> 6;
        uVar2 = uVar1;
        if (bVar7) {
          uVar2 = uVar1 + param_2 * -0x40;
        }
        bVar8 = param_2 <= uVar2 >> 5;
        uVar3 = uVar2;
        if (bVar8) {
          uVar3 = uVar2 + param_2 * -0x20;
        }
        bVar9 = param_2 <= uVar3 >> 4;
        param_1 = uVar3;
        if (bVar9) {
          param_1 = uVar3 + param_2 * -0x10;
        }
        iVar5 = (((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 +
                 (uint)(bVar7 && param_2 * 0x40 <= uVar1)) * 2 +
                (uint)(bVar8 && param_2 * 0x20 <= uVar2)) * 2 +
                (uint)(bVar9 && param_2 * 0x10 <= uVar3);
      }
      bVar6 = param_2 <= param_1 >> 3;
      uVar1 = param_1;
      if (bVar6) {
        uVar1 = param_1 + param_2 * -8;
      }
      bVar10 = param_2 * 8 <= param_1;
      bVar7 = param_2 <= uVar1 >> 2;
      uVar2 = uVar1;
      if (bVar7) {
        uVar2 = uVar1 + param_2 * -4;
      }
      bVar8 = param_2 <= uVar2 >> 1;
      param_1 = uVar2;
      if (bVar8) {
        param_1 = uVar2 + param_2 * -2;
      }
      iVar5 = ((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 + (uint)(bVar7 && param_2 * 4 <= uVar1)) *
              2 + (uint)(bVar8 && param_2 * 2 <= uVar2);
    }
    uVar1 = param_1 - param_2;
    if (param_2 > param_1) {
      uVar1 = param_1;
    }
    return CONCAT44(uVar1,iVar5 * 2 + (uint)(param_2 <= param_1));
  }
LAB_10000904:
  uVar4 = aeabi_idiv0(0);
  return CONCAT44(param_1,uVar4);
}

// FUNC 0x10000918  aeabi_idiv0

/* Divide-by-zero helper, returns zero */

void aeabi_idiv0(void)

{
  return;
}

// FUNC 0x1000091c  aeabi_llsl

/* 64-bit shift left */

undefined8 aeabi_llsl(uint param_1,int param_2,uint param_3)

{
  return CONCAT44(param_2 << (param_3 & 0xff) | param_1 << (param_3 - 0x20 & 0xff) |
                  param_1 >> (-(param_3 - 0x20) & 0xff),param_1 << (param_3 & 0xff));
}

// FUNC 0x10000934  aeabi_uldivmod

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unsigned 64-bit divide and remainder */

undefined8 aeabi_uldivmod(int param_1,int param_2,int param_3,int param_4)

{
  undefined8 uVar1;
  
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != 0) {
      param_1 = -1;
      param_2 = param_1;
    }
    return CONCAT44(param_2,param_1);
  }
  uVar1 = udivmoddi4(param_1);
  return uVar1;
}

// FUNC 0x10000974  udivmoddi4

/* Core of the 64-bit divide */

undefined8 udivmoddi4(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  uint uStack_30;
  uint uStack_2c;
  
  if ((param_2 <= param_4 && param_4 != param_2) || ((param_4 == param_2 && (param_1 < param_3)))) {
    uStack_30 = 0;
    uStack_2c = 0;
    goto LAB_100009f8;
  }
  iVar1 = clzdi2(param_3,param_4);
  iVar2 = clzdi2(param_1,param_2);
  uVar4 = iVar1 - iVar2;
  uVar5 = uVar4 - 0x20;
  if ((int)uVar5 < 0) {
    uVar6 = param_4 << (uVar4 & 0xff) | param_3 >> (0x20 - uVar4 & 0xff);
    param_3 = param_3 << (uVar4 & 0xff);
    if (uVar6 <= param_2) goto LAB_100009c0;
LAB_10000a36:
    uStack_30 = 0;
    uStack_2c = 0;
  }
  else {
    uVar6 = param_3 << (uVar5 & 0xff);
    param_3 = param_3 << (uVar4 & 0xff);
    if (param_2 < uVar6) goto LAB_10000a36;
LAB_100009c0:
    if ((uVar6 == param_2) && (param_1 < param_3)) goto LAB_10000a36;
    bVar9 = param_1 < param_3;
    param_1 = param_1 - param_3;
    param_2 = (param_2 - uVar6) - (uint)bVar9;
    if ((int)uVar5 < 0) {
      uStack_2c = 1 >> (0x20 - uVar4 & 0xff);
    }
    else {
      uStack_2c = 1 << (uVar5 & 0xff);
    }
    uStack_30 = 1 << (uVar4 & 0xff);
  }
  if (uVar4 == 0) goto LAB_100009f8;
  uVar3 = param_3 >> 1 | uVar6 << 0x1f;
  uVar6 = uVar6 >> 1;
  uVar8 = uVar4;
  do {
    while ((uVar6 <= param_2 && ((uVar6 != param_2 || (uVar3 <= param_1))))) {
      bVar9 = param_1 < uVar3;
      uVar7 = param_1 - uVar3;
      uVar8 = uVar8 - 1;
      param_1 = uVar7 * 2 + 1;
      param_2 = ((param_2 - uVar6) - (uint)bVar9) * 2 + (uint)CARRY4(uVar7,uVar7) +
                (uint)(0xfffffffe < uVar7 * 2);
      if (uVar8 == 0) goto LAB_10000a7c;
    }
    uVar8 = uVar8 - 1;
    bVar9 = CARRY4(param_1,param_1);
    param_1 = param_1 * 2;
    param_2 = param_2 * 2 + (uint)bVar9;
  } while (uVar8 != 0);
LAB_10000a7c:
  bVar9 = CARRY4(uStack_30,param_1);
  uVar6 = uStack_30 + param_1;
  iVar1 = uStack_2c + param_2;
  if ((int)uVar5 < 0) {
    param_1 = param_1 >> (uVar4 & 0xff) | param_2 << (0x20 - uVar4 & 0xff);
    param_2 = param_2 >> (uVar4 & 0xff);
    if (-1 < (int)uVar5) goto LAB_10000aa0;
LAB_10000af6:
    uVar5 = param_2 << (uVar4 & 0xff) | param_1 >> (0x20 - uVar4 & 0xff);
  }
  else {
    param_1 = param_2 >> (uVar5 & 0xff);
    param_2 = param_2 >> (uVar4 & 0xff);
    if ((int)uVar5 < 0) goto LAB_10000af6;
LAB_10000aa0:
    uVar5 = param_1 << (uVar5 & 0xff);
  }
  uVar4 = param_1 << (uVar4 & 0xff);
  uStack_30 = uVar6 - uVar4;
  uStack_2c = ((iVar1 + (uint)bVar9) - uVar5) - (uint)(uVar6 < uVar4);
LAB_100009f8:
  if (param_5 != (uint *)0x0) {
    *param_5 = param_1;
    param_5[1] = param_2;
  }
  return CONCAT44(uStack_2c,uStack_30);
}

// FUNC 0x10000b0c  clzdi2

/* Count leading zeros in a 64-bit value */

int clzdi2(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = clzsi2();
    iVar1 = iVar1 + 0x20;
  }
  else {
    iVar1 = clzsi2(param_2);
  }
  return iVar1;
}

// FUNC 0x10000b24  clzsi2

/* Count leading zeros in a 32-bit value */

int clzsi2(uint param_1)

{
  int iVar1;
  
  iVar1 = 0x1c;
  if (0xffff < param_1) {
    param_1 = param_1 >> 0x10;
    iVar1 = 0xc;
  }
  if (0xff < param_1) {
    param_1 = param_1 >> 8;
    iVar1 = iVar1 + -8;
  }
  if (0xf < param_1) {
    param_1 = param_1 >> 4;
    iVar1 = iVar1 + -4;
  }
  return (uint)*(byte *)(param_1 + 0x10000b50) + iVar1;
}

// FUNC 0x10000b60  hardfault_handler

void hardfault_handler(void)

{
  boot_printf(uRam10000b6c);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x10000b70  boot_jump_to_app

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Sets VTOR and calls the app reset vector */

void boot_jump_to_app(undefined4 param_1)

{
  *(undefined4 *)(_DAT_10000b84 + 0x7c) = 0xffffffff;
  *(undefined4 *)(_DAT_10000b88 + 8) = param_1;
  call_app_reset_vector();
  return;
}

// FUNC 0x10000b8c  bootloader_boot_app

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reads OTA info from the KV store, applies it if valid, then hands control to the app */

void bootloader_boot_app(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = _DAT_10000bb8;
  iVar3 = kv_read(3,_DAT_10000bb8,0x6c);
  uVar2 = _DAT_10000bbc;
  if (iVar3 == 0) {
    ota_image_verify(uVar1,_DAT_10000bbc);
  }
  boot_printf(_DAT_10000bc0);
  boot_app_select(uVar2);
  return;
}

// FUNC 0x10000bc4  bootloader_main

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Prints the banner and boot reason, reads the boot info, then boots or updates the app */

void bootloader_main(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  boot_clock_init();
  uart_init(_DAT_10000c44,0x1c200);
  uart_pinmux_select();
  puVar1 = _DAT_10000c48;
  memset(_DAT_10000c48,0,0x1c);
  iVar2 = kv_store_init(0);
  if (iVar2 == 0) {
    kv_read(2,puVar1,0x1c);
  }
  image_header_build(*puVar1,puVar1[2],puVar1[3]);
  boot_printf(_DAT_10000c50,_DAT_10000c4c);
  iVar2 = boot_reason_get();
  uVar3 = _DAT_10000c54;
  if ((((iVar2 != 2) && (uVar3 = _DAT_10000c5c, iVar2 != 3)) && (uVar3 = _DAT_10000c60, iVar2 != 1))
     && (uVar3 = _DAT_10000c68, iVar2 == 0)) {
    uVar3 = _DAT_10000c64;
  }
  boot_printf(uVar3);
  boot_printf(_DAT_10000c58);
  bootloader_boot_app();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x10000c6c  heap_alloc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Bump allocator over the heap area */

uint heap_alloc(int param_1)

{
  uint uVar1;
  
  uVar1 = *_DAT_10000c84;
  if (_DAT_10000c88 < uVar1 + param_1) {
    uVar1 = 0xffffffff;
  }
  else {
    *_DAT_10000c84 = uVar1 + param_1;
  }
  return uVar1;
}

// FUNC 0x10000c8c  boot_delay_us

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calibrated busy-wait delay */

void boot_delay_us(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uStack_c;
  
  iVar1 = aeabi_uidivmod(*_DAT_10000cdc,_DAT_10000ce0);
  uVar2 = aeabi_uidivmod(iVar1 * param_1,0x11);
  if (uVar2 < 0xc) {
    uVar2 = 0xc;
  }
  for (uStack_c = uVar2 - 0xc; uStack_c != 0; uStack_c = uStack_c + -1) {
  }
  return;
}

// FUNC 0x10000ce4  call_app_reset_vector

/* Calls the word at app_base + 4 */

void call_app_reset_vector(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10000cea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 4))();
  return;
}

// FUNC 0x10000cf0  format_padded

/* Formats a number with padding and prefixes into the output buffer */

int format_padded(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 uint param_6,char param_7,int param_8,uint param_9,uint param_10,uint param_11)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if ((param_11 & 2) == 0) {
    if (((param_10 != 0) && ((param_11 & 1) != 0)) && ((param_7 != '\0' || ((param_11 & 0xc) != 0)))
       ) {
      param_10 = param_10 - 1;
    }
    for (; (param_6 < param_9 && (param_6 != 0x20)); param_6 = param_6 + 1) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
    }
    for (; (((param_11 & 1) != 0 && (param_6 < param_10)) && (param_6 != 0x20));
        param_6 = param_6 + 1) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
    }
  }
  if ((int)(param_11 << 0x1b) < 0) {
    uVar1 = param_6;
    if (((((int)(param_11 << 0x15) < 0) || (param_6 == 0)) ||
        ((param_6 != param_9 && (param_6 != param_10)))) || (uVar1 = param_6 - 1, param_6 == 1)) {
      uVar4 = uVar1;
      if (param_8 == 0x10) goto LAB_10000d86;
      if (param_8 == 2) {
        if (0x1f < uVar1) goto LAB_10000d90;
        goto LAB_10000dd8;
      }
    }
    else {
      uVar4 = param_6 - 2;
      if (param_8 == 0x10) {
LAB_10000d86:
        if ((int)(param_11 << 0x1a) < 0) {
          uVar2 = 0x58;
        }
        else {
          uVar2 = 0x78;
        }
        uVar1 = uVar4;
        if (0x1f < uVar4) goto LAB_10000d90;
      }
      else {
        if (param_8 != 2) goto LAB_10000de8;
LAB_10000dd8:
        uVar2 = 0x62;
        uVar4 = uVar1;
      }
      *(undefined1 *)(param_5 + uVar4) = uVar2;
      uVar1 = uVar4 + 1;
    }
LAB_10000de8:
    if (0x1f < uVar1) goto LAB_10000d90;
    *(undefined1 *)(param_5 + uVar1) = 0x30;
    param_6 = uVar1 + 1;
  }
  uVar1 = param_6;
  if (param_6 != 0x20) {
    uVar2 = 0x2d;
    if (param_7 == '\0') {
      if ((int)(param_11 << 0x1d) < 0) {
        uVar2 = 0x2b;
      }
      else {
        if (-1 < (int)(param_11 << 0x1c)) goto LAB_10000d90;
        uVar2 = 0x20;
      }
    }
    *(undefined1 *)(param_5 + param_6) = uVar2;
    uVar1 = param_6 + 1;
  }
LAB_10000d90:
  uVar4 = uVar1;
  uVar6 = uVar1;
  iVar3 = param_3;
  if ((param_11 & 3) == 0) {
    for (; uVar4 < param_10; uVar4 = uVar4 + 1) {
      (*param_1)(0x20,param_2,(param_3 - uVar1) + uVar4,param_4);
    }
    iVar3 = 0;
    if (uVar1 <= param_10) {
      iVar3 = param_10 - uVar1;
    }
    iVar3 = iVar3 + param_3;
  }
  while( true ) {
    iVar5 = uVar1 + iVar3;
    if (uVar6 == 0) break;
    (*param_1)(*(undefined1 *)(param_5 + (uVar6 - 1)),param_2,iVar5 - uVar6,param_4);
    uVar6 = uVar6 - 1;
  }
  if ((param_11 & 2) != 0) {
    for (uVar1 = iVar5 - param_3; uVar1 < param_10; uVar1 = uVar1 + 1) {
      (*param_1)(0x20,param_2,uVar1 + param_3,param_4);
    }
    iVar3 = 0;
    if ((uint)(iVar5 - param_3) <= param_10) {
      iVar3 = (param_10 + param_3) - iVar5;
    }
    iVar5 = iVar5 + iVar3;
  }
  return iVar5;
}

// FUNC 0x10000e5a  utoa

/* Unsigned int to string for the boot printf */

void utoa(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
         undefined1 param_6,uint param_7,undefined4 param_8,undefined4 param_9,uint param_10)

{
  char cVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  char acStack_38 [36];
  
  if (param_5 == 0) {
    param_10 = param_10 & 0xffffffef;
  }
  if ((-1 < (int)(param_10 << 0x15)) || (param_5 != 0)) {
    cVar3 = 'a';
    if ((int)(param_10 << 0x1a) < 0) {
      cVar3 = 'A';
    }
    uVar4 = param_5;
    param_5 = 0;
    do {
      uVar5 = aeabi_uidiv(uVar4,param_7);
      cVar2 = (char)(uVar5 >> 0x20);
      cVar1 = cVar2 + cVar3 + -10;
      if (uVar5 < 0xa00000000) {
        cVar1 = cVar2 + '0';
      }
      acStack_38[param_5] = cVar1;
      param_5 = param_5 + 1;
    } while ((param_7 <= uVar4) && (uVar4 = (uint)uVar5, param_5 != 0x20));
  }
  format_padded(param_1,param_2,param_3,param_4,acStack_38,param_5,param_6,param_7,param_8,param_9,
                param_10);
  return;
}

// FUNC 0x10000eee  ulltoa

/* WARNING: Removing unreachable block (ram,0x10000f74) */
/* Unsigned long long to string for the boot printf */

void ulltoa(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
           int param_6,undefined1 param_7,undefined4 param_8,uint param_9,undefined4 param_10,
           undefined4 param_11,undefined4 param_12,uint param_13)

{
  ulonglong uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  int iStack_5c;
  char acStack_38 [36];
  
  if (param_5 == 0 && param_6 == 0) {
    param_13 = param_13 & 0xffffffef;
  }
  if ((-1 < (int)(param_13 << 0x15)) || (iVar5 = 0, param_5 != 0 || param_6 != 0)) {
    cVar3 = 'a';
    if ((int)(param_13 << 0x1a) < 0) {
      cVar3 = 'A';
    }
    iStack_5c = 0;
    uVar1 = CONCAT44(param_6,param_5);
    do {
      uVar2 = param_9;
      uVar6 = aeabi_uldivmod((int)uVar1,(int)(uVar1 >> 0x20),param_9,param_10);
      cVar4 = (char)uVar2 + cVar3 + -10;
      if ((uVar2 & 0xff) < 10) {
        cVar4 = (char)uVar2 + '0';
      }
      iVar5 = iStack_5c + 1;
      acStack_38[iStack_5c] = cVar4;
    } while ((CONCAT44(param_10,param_9) <= uVar1) &&
            (iStack_5c = iVar5, uVar1 = uVar6, iVar5 != 0x20));
  }
  format_padded(param_1,param_2,param_3,param_4,acStack_38,iVar5,param_7,param_9,param_11,param_12,
                param_13);
  return;
}

// FUNC 0x10000fc0  vprintf_core

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Format engine behind boot_printf */

uint vprintf_core(code *param_1,int param_2,uint param_3,byte *param_4,uint *param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_54;
  byte *pbStack_50;
  uint uStack_4c;
  code *pcStack_48;
  
  pcStack_48 = param_1;
  if (param_2 == 0) {
    pcStack_48 = _DAT_1000128c;
  }
  uVar3 = 0;
  pbStack_50 = param_4;
LAB_10000ff2:
  do {
    while( true ) {
      bVar1 = *pbStack_50;
      if (bVar1 == 0) {
        uVar5 = uVar3;
        if (param_3 <= uVar3) {
          uVar5 = param_3 - 1;
        }
        (*pcStack_48)(0,param_2,uVar5,param_3);
        return uVar3;
      }
      pbStack_50 = pbStack_50 + 1;
      if (bVar1 == 0x25) break;
      (*pcStack_48)(bVar1,param_2,uVar3,param_3);
      uVar3 = uVar3 + 1;
    }
    uVar5 = 0;
LAB_10001026:
    while( true ) {
      uVar6 = (uint)*pbStack_50;
      pbVar4 = pbStack_50 + 1;
      if (uVar6 != 0x2b) break;
      uVar6 = 4;
LAB_1000104e:
      uVar5 = uVar5 | uVar6;
      pbStack_50 = pbVar4;
    }
    if (0x2b < uVar6) {
      if (uVar6 == 0x2d) {
        uVar6 = 2;
        goto LAB_1000104e;
      }
      if (uVar6 != 0x30) goto LAB_1000103c;
      uVar5 = uVar5 | 1;
      pbStack_50 = pbVar4;
      goto LAB_10001026;
    }
    if (uVar6 == 0x20) {
      uVar5 = uVar5 | 8;
      pbStack_50 = pbVar4;
      goto LAB_10001026;
    }
    if (uVar6 == 0x23) {
      uVar6 = 0x10;
      goto LAB_1000104e;
    }
LAB_1000103c:
    if (uVar6 - 0x30 < 10) {
      uStack_54 = 0;
      while( true ) {
        if (9 < *pbStack_50 - 0x30) break;
        uStack_54 = (uint)*pbStack_50 + uStack_54 * 10 + -0x30;
        pbStack_50 = pbStack_50 + 1;
      }
    }
    else {
      uStack_54 = 0;
      if (uVar6 == 0x2a) {
        uStack_54 = *param_5;
        param_5 = param_5 + 1;
        pbStack_50 = pbVar4;
        if ((int)uStack_54 < 0) {
          uVar5 = uVar5 | 2;
          uStack_54 = -uStack_54;
        }
      }
    }
    uStack_4c = 0;
    pbVar4 = pbStack_50;
    if (*pbStack_50 == 0x2e) {
      uVar5 = uVar5 | 0x400;
      pbVar4 = pbStack_50 + 1;
      if (pbStack_50[1] - 0x30 < 10) {
        while( true ) {
          if (9 < *pbVar4 - 0x30) break;
          uStack_4c = (uint)*pbVar4 + uStack_4c * 10 + -0x30;
          pbVar4 = pbVar4 + 1;
        }
      }
      else if (pbStack_50[1] == 0x2a) {
        uStack_4c = *param_5;
        param_5 = param_5 + 1;
        uStack_4c = uStack_4c & (int)~uStack_4c >> 0x1f;
        pbVar4 = pbStack_50 + 2;
      }
    }
    pbStack_50 = pbVar4;
    bVar1 = *pbStack_50;
    if (bVar1 == 0x6c) {
      if (pbStack_50[1] != 0x6c) {
LAB_10001134:
        uVar6 = 0x100;
        goto LAB_10001158;
      }
      uVar6 = 0x300;
LAB_10001146:
      uVar5 = uVar5 | uVar6;
      pbStack_50 = pbStack_50 + 2;
    }
    else if (bVar1 < 0x6d) {
      if (bVar1 == 0x68) {
        if (pbStack_50[1] == 0x68) {
          uVar6 = 0xc0;
          goto LAB_10001146;
        }
        uVar6 = 0x80;
      }
      else {
        if (bVar1 != 0x6a) goto LAB_100010f0;
        uVar6 = 0x200;
      }
LAB_10001158:
      uVar5 = uVar5 | uVar6;
      pbStack_50 = pbStack_50 + 1;
    }
    else if ((bVar1 == 0x74) || (bVar1 == 0x7a)) goto LAB_10001134;
LAB_100010f0:
    uVar6 = (uint)*pbStack_50;
    pbStack_50 = pbStack_50 + 1;
    if (uVar6 < 0x79) {
      if (uVar6 < 0x62) {
        if ((uVar6 != 0x25) && (uVar6 == 0x58)) {
          uVar5 = uVar5 | 0x20;
          uVar7 = 0x10;
          goto LAB_100011c0;
        }
      }
      else if (uVar6 - 0x62 < 0x17) {
        iVar2 = FUN_100007f0();
        param_5 = (uint *)(uVar3 << 5);
        uVar3 = iVar2 << 6;
        if (uVar6 == 0x78) {
          uVar7 = 0x10;
LAB_100011c0:
          uVar5 = uVar5 & 0xfffffff3;
        }
        else {
          if (uVar6 == 0x6f) {
            uVar7 = 8;
            goto LAB_100011c0;
          }
          if (uVar6 == 0x62) {
            uVar7 = 2;
            goto LAB_100011c0;
          }
          uVar5 = uVar5 & 0xffffffef;
          uVar7 = 10;
          if ((uVar6 != 0x69) && (uVar6 != 100)) goto LAB_100011c0;
        }
        if ((int)(uVar5 << 0x15) < 0) {
          uVar5 = uVar5 & 0xfffffffe;
        }
        if ((uVar6 == 0x69) || (uVar6 == 100)) {
          if ((uVar5 & 0x200) == 0) {
            if ((int)(uVar5 << 0x17) < 0) {
              uVar6 = *param_5;
            }
            else {
              uVar6 = *param_5;
              if ((int)(uVar5 << 0x19) < 0) {
                uVar6 = uVar6 & 0xff;
              }
              else if ((int)(uVar5 << 0x18) < 0) {
                uVar6 = (uint)(short)uVar6;
              }
            }
            uVar8 = uVar6 >> 0x1f;
            uVar6 = uVar6 + ((int)uVar6 >> 0x1f) ^ (int)uVar6 >> 0x1f;
            goto LAB_100012a8;
          }
          param_5 = (uint *)((int)param_5 + 7U & 0xfffffff8);
          uVar5 = param_5[1];
          uVar8 = uVar5 >> 0x1f;
          uVar9 = (int)uVar5 >> 0x1f;
          uVar6 = (uVar9 ^ *param_5) - uVar9;
          uVar5 = ((uVar9 ^ uVar5) - uVar9) - (uint)((uVar9 ^ *param_5) < uVar9);
        }
        else {
          if ((uVar5 & 0x200) == 0) {
            if ((int)(uVar5 << 0x17) < 0) {
              uVar6 = *param_5;
              uVar8 = 0;
            }
            else {
              uVar6 = *param_5;
              if ((int)(uVar5 << 0x19) < 0) {
                uVar6 = uVar6 & 0xff;
              }
              else if ((int)(uVar5 << 0x18) < 0) {
                uVar6 = uVar6 & 0xffff;
              }
              uVar8 = 0;
            }
LAB_100012a8:
            param_5 = param_5 + 1;
            uVar3 = utoa(pcStack_48,param_2,uVar3,param_3,uVar6,uVar8,uVar7,uStack_4c,uStack_54,
                         uVar5);
            goto LAB_10000ff2;
          }
          param_5 = (uint *)((int)param_5 + 7U & 0xfffffff8);
          uVar8 = 0;
          uVar6 = *param_5;
          uVar5 = param_5[1];
        }
        param_5 = param_5 + 2;
        uVar3 = ulltoa(pcStack_48,param_2,uVar3,param_3,uVar6,uVar5,uVar8);
        goto LAB_10000ff2;
      }
    }
    (*pcStack_48)(uVar6,param_2,uVar3,param_3);
    uVar3 = uVar3 + 1;
  } while( true );
}

// FUNC 0x100014a0  boot_printf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Variadic printf over UART1 at 115200 */

void boot_printf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStack_20;
  undefined4 *puStack_1c;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puStack_1c = &uStack_c;
  uStack_20 = param_3;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  vprintf_core(_DAT_100014c0,&uStack_20,0xffffffff,param_1,puStack_1c,param_2);
                    /* WARNING: Could not recover jumptable at 0x100014be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

// FUNC 0x100014c4  reset_handler

/* Vector table reset entry: calls startup_init, then bootloader_main */

void reset_handler(void)

{
  startup_init();
  bootloader_main();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x100014ce  default_handler

/* Infinite loop for unused vectors */

void default_handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x100014d0  startup_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calls the early image check, copies .data, zeroes .bss, calls flash_driver_init and
   bootloader_main */

void startup_init(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  boot_early_image_check();
  for (iVar1 = 0; (uint)(_DAT_10001538 + iVar1) < _DAT_1000153c; iVar1 = iVar1 + 4) {
    *(undefined4 *)(_DAT_10001538 + iVar1) = *(undefined4 *)(_DAT_10001534 + iVar1);
  }
  for (iVar1 = 0; puVar2 = _DAT_1000154c, (uint)(_DAT_10001544 + iVar1) < _DAT_10001548;
      iVar1 = iVar1 + 4) {
    *(undefined4 *)(_DAT_10001544 + iVar1) = *(undefined4 *)(_DAT_10001540 + iVar1);
  }
  for (; puVar2 < _DAT_10001550; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  *_DAT_10001528 = 1;
  *_DAT_1000152c = 2;
  *_DAT_10001530 = 2;
  flash_driver_init();
  return;
}

// FUNC 0x10001554  crc32

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Bitwise CRC-32 over a buffer, polynomial 0x4C11DB7 */

uint crc32(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  char cVar5;
  
  uVar3 = 0xffffffff;
  pbVar4 = _DAT_10001588;
  do {
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    cVar5 = '\b';
    uVar2 = uVar3 ^ (uint)bVar1 << 0x18;
    do {
      uVar3 = uVar2 << 1;
      if ((int)uVar2 < 0) {
        uVar3 = uVar3 ^ _DAT_1000158c;
      }
      cVar5 = cVar5 + -1;
      uVar2 = uVar3;
    } while (cVar5 != '\0');
  } while (pbVar4 != _DAT_10001590);
  return ~uVar3;
}

// FUNC 0x10001594  boot_clock_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configures the clock and power block at 0x40160024 */

void boot_clock_init(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = _DAT_10001604;
  uVar2 = *_DAT_10001600 >> 0x18 & 1;
  if (*_DAT_10001604 == 1) {
    if (uVar2 == 0) {
      *_DAT_10001600 = *_DAT_10001600 | 0x1000000;
      piVar1[1] = 1;
      piVar1[2] = 1;
      return;
    }
    iVar3 = 2;
  }
  else if (*_DAT_10001604 == 2) {
    if (uVar2 == 0) {
LAB_100015da:
      *_DAT_10001600 = *_DAT_10001600 | 0x1000000;
      *piVar1 = 1;
      piVar1[1] = 0;
      piVar1[2] = 0;
      return;
    }
    iVar3 = 3;
    *_DAT_10001604 = 1;
  }
  else {
    if (uVar2 == 0) goto LAB_100015da;
    *_DAT_10001600 = *_DAT_10001600 | 0x1000000;
    iVar3 = 0xff;
    *piVar1 = 1;
  }
  piVar1[1] = iVar3;
  piVar1[2] = iVar3;
  return;
}

// FUNC 0x10001608  boot_reason_get

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Returns the boot reason word at 0x20030004 */

undefined4 boot_reason_get(void)

{
  return *(undefined4 *)(_DAT_10001610 + 4);
}

// FUNC 0x10001614  image_header_build

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Stores base, size and CRC-32 in the image header descriptor */

void image_header_build(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _DAT_10001628;
  *(undefined4 *)(_DAT_10001628 + 0x10) = param_1;
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  *(undefined4 *)(iVar1 + 0x18) = param_3;
  uVar2 = crc32();
  *(undefined4 *)(iVar1 + 0x1c) = uVar2;
  return;
}

// FUNC 0x1000162c  boot_early_image_check

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reads the boot mode strap and a RAM image header; maps and jumps to the app when the CRC matches
    */

void boot_early_image_check(void)

{
  int iVar1;
  
  if (((((*_DAT_10001678 << 8) >> 0x1e != 0) || ((*_DAT_1000167c & 0xf) == 0)) &&
      ((*_DAT_10001678 >> 0x16 & 3) != 1)) && ((*_DAT_10001678 >> 0x16 & 3) != 2)) {
    return;
  }
  iVar1 = crc32();
  if (iVar1 == *(int *)(_uart_pins_config_alt + 0x1c)) {
    if (*(int *)(_uart_pins_config_alt + 0x10) == 1) {
      boot_map_exec_region
                (*(undefined4 *)(_uart_pins_config_alt + 0x14),
                 *(undefined4 *)(_uart_pins_config_alt + 0x18));
    }
    boot_jump_to_app(uRam10001684);
  }
  return;
}

// FUNC 0x10001680  uart_pins_config_alt

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Alternate UART pin setup; not referenced by the boot path */

void uart_pins_config_alt(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  byte abStack_70 [64];
  undefined1 auStack_30 [40];
  undefined4 uStack_8;
  
  uRam00000003 = 3;
  uStack_8 = 0;
  disableIRQinterrupts();
  iVar1 = reg_read_indexed(1);
  uVar3 = _DAT_10001734;
  if (iVar1 << 1 < 0) {
    uVar3 = _DAT_1000172c;
  }
  reg_write_indexed(1,uVar3);
  uVar2 = reg_read_indexed(1);
  reg_write_indexed(1,_DAT_10001730 & uVar2);
  uVar2 = reg_read_indexed(7);
  reg_write_indexed(7,uVar2 | 0x800000);
  iVar1 = 0;
  uVar2 = 0;
  while( true ) {
    auStack_30[uVar2] = (char)iVar1;
    uVar4 = uVar2 + 1;
    if (uVar4 == 0x25) break;
    iVar1 = (uVar4 & 1) << 4;
    uVar2 = uVar4;
  }
  iVar1 = 0;
  pbVar5 = abStack_70 + uVar2;
  do {
    if (iVar1 < 0x10) {
      pbVar5[0x1c] = pbVar5[0x1c] | 5;
      pbVar5[0x1d] = pbVar5[0x1d] | 5;
    }
    else {
      *pbVar5 = *pbVar5 | 10;
      pbVar5[1] = pbVar5[1] | 10;
    }
    iVar1 = iVar1 + 1;
    pbVar5 = pbVar5 + 2;
  } while (iVar1 != 0x20);
  iVar1 = 0;
  do {
    reg_write_indexed(0x14,auStack_30[iVar1]);
    iVar1 = iVar1 + 1;
    boot_delay_us(10);
  } while (iVar1 != 0x25);
  return;
}

// FUNC 0x10001688  uart_pins_config

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Builds the pin bitmap and programs the UART pin mux */

void uart_pins_config(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  byte abStack_70 [64];
  undefined1 auStack_30 [40];
  
  disableIRQinterrupts();
  iVar1 = reg_read_indexed(1);
  uVar3 = _DAT_10001734;
  if (iVar1 << 1 < 0) {
    uVar3 = _DAT_1000172c;
  }
  reg_write_indexed(1,uVar3);
  uVar2 = reg_read_indexed(1);
  reg_write_indexed(1,_DAT_10001730 & uVar2);
  uVar2 = reg_read_indexed(7);
  reg_write_indexed(7,uVar2 | 0x800000);
  iVar1 = 0;
  uVar2 = 0;
  while( true ) {
    auStack_30[uVar2] = (char)iVar1;
    uVar4 = uVar2 + 1;
    if (uVar4 == 0x25) break;
    iVar1 = (uVar4 & 1) << 4;
    uVar2 = uVar4;
  }
  iVar1 = 0;
  pbVar5 = abStack_70 + uVar2;
  do {
    if (iVar1 < 0x10) {
      pbVar5[0x1c] = pbVar5[0x1c] | 5;
      pbVar5[0x1d] = pbVar5[0x1d] | 5;
    }
    else {
      *pbVar5 = *pbVar5 | 10;
      pbVar5[1] = pbVar5[1] | 10;
    }
    iVar1 = iVar1 + 1;
    pbVar5 = pbVar5 + 2;
  } while (iVar1 != 0x20);
  iVar1 = 0;
  do {
    reg_write_indexed(0x14,auStack_30[iVar1]);
    iVar1 = iVar1 + 1;
    boot_delay_us(10);
  } while (iVar1 != 0x25);
  return;
}

// FUNC 0x10001738  uart_pinmux_select

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Selects the UART pin group from the boot reason and applies it */

void uart_pinmux_select(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = boot_reason_get();
  iVar1 = _DAT_10001784;
  if ((1 < uVar2) && (uVar2 != 0xff)) {
    return;
  }
  iVar3 = *(int *)(_DAT_10001784 + 0xc);
  if (iVar3 == _DAT_10001788) {
    uVar4 = 0;
  }
  else {
    if (iVar3 == _DAT_1000178c) goto LAB_10001766;
    if (iVar3 != _DAT_10001790) {
      if (uVar2 == 0) {
        *(int *)(_DAT_10001784 + 0xc) = _DAT_10001788;
      }
      else if (uVar2 == 1) {
        *(int *)(_DAT_10001784 + 0xc) = _DAT_1000178c;
      }
      else {
        *(int *)(_DAT_10001784 + 0xc) = _DAT_10001790;
      }
      uart_pins_config();
      return;
    }
    uVar4 = 0xff;
  }
  *(undefined4 *)(_DAT_10001784 + 4) = uVar4;
LAB_10001766:
  *(undefined4 *)(iVar1 + 0xc) = 0;
  return;
}

// FUNC 0x10001794  uart_baud_divider

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Converts a baud rate to the divisor written to the UART */

uint uart_baud_divider(uint param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (param_1 != 0) {
    if (*_DAT_100017c8 < param_1 << 4) {
      param_1 = 0;
    }
    else {
      uVar2 = aeabi_uidiv();
      uVar1 = aeabi_uidivmod((int)((ulonglong)uVar2 >> 0x20) << 3,param_1);
      param_1 = (uVar1 >> 1) + (uVar1 & 1) & 0xffff | (int)uVar2 << 0x10;
    }
  }
  return param_1;
}

// FUNC 0x100017cc  uart_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configures the bootloader console UART at 115200 */

void uart_init(int param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = _DAT_1000188c;
  if (param_1 == 0x40000000) {
    uVar2 = _DAT_10001890 & *_DAT_1000188c;
    uVar3 = 0x1100;
  }
  else if (param_1 == _DAT_10001898) {
    uVar2 = _DAT_1000189c & *_DAT_1000188c;
    uVar3 = 0x110000;
  }
  else {
    if (param_1 != _DAT_100018a0) goto LAB_100017ec;
    uVar2 = *_DAT_100018a4 & 0xffffff00;
    uVar3 = 0x11;
    puVar1 = _DAT_100018a4;
  }
  *puVar1 = uVar3 | uVar2;
LAB_100017ec:
  do {
  } while ((*(uint *)(param_1 + 0x18) & 8) != 0);
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffe;
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffffef;
  uVar2 = uart_baud_divider(param_2);
  *(uint *)(param_1 + 0x24) = uVar2 >> 0x10;
  *(uint *)(param_1 + 0x28) = uVar2 & 0x3f;
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x70;
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffff3;
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x300;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x50;
  if (param_1 == 0x40000000) {
    *_DAT_10001894 = 8;
  }
  else if (param_1 == _DAT_10001898) {
    *_DAT_10001894 = 4;
  }
  else if (param_1 == _DAT_100018a0) {
    *_DAT_10001894 = 0x10;
  }
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 1;
  return;
}

// FUNC 0x100018a8  reg_write_wait

/* Waits for status bit 0x20, then writes the register */

void reg_write_wait(undefined4 *param_1,undefined4 param_2)

{
  do {
  } while ((param_1[6] & 0x20) != 0);
  *param_1 = param_2;
  return;
}

// FUNC 0x100018b4  reg_write_indexed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Writes a 32-bit register selected by index */

void reg_write_indexed(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 * 4 + _DAT_100018c0) = param_2;
  return;
}

// FUNC 0x100018c4  reg_read_indexed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reads a 32-bit register selected by index */

undefined4 reg_read_indexed(int param_1)

{
  return *(undefined4 *)(param_1 * 4 + _DAT_100018d0);
}

// FUNC 0x1000193c  flash_driver_init

/* Calls the flash controller init in the RAM blob */

void flash_driver_init(void)

{
  flash_controller_init_veneer();
  return;
}

// FUNC 0x10001944  flash_region_get

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Returns the 0x14-byte region descriptor for an index */

int flash_region_get(int param_1)

{
  return param_1 * 0x14 + _DAT_10001950;
}

// FUNC 0x10001954  flash_region_find

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Finds a region index by name, 16 entries maximum */

int flash_region_find(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = _DAT_1000197c;
  do {
    iVar1 = strcmp(param_1,*(undefined4 *)(iVar3 + 4));
    if (iVar1 == 0) {
      return (int)(char)iVar2;
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x14;
  } while (iVar2 != 0x10);
  return -1;
}

// FUNC 0x10001980  flash_region_erase

int flash_region_erase(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = iRam100019c8 + param_1 * 0x14;
  if (*(uint *)(iVar1 + 0xc) < (uint)(param_3 + param_2)) {
    iVar1 = -1;
  }
  else {
    uVar2 = param_2 + *(int *)(iVar1 + 8);
    for (uVar3 = uVar2 & 0xfffff000; uVar3 <= (param_3 + -1 + uVar2 & 0xfffff000);
        uVar3 = uVar3 + 0x1000) {
      iVar1 = flash_erase_sector_veneer(uRam100019cc,uVar3);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

// FUNC 0x100019d0  flash_region_write

undefined4 flash_region_write(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = flash_status_veneer();
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    iVar3 = iRam10001a68 + param_1 * 0x14;
    if ((uint)(*param_2 + param_4) <= *(uint *)(iVar3 + 0xc)) {
      uVar2 = *param_2 + *(int *)(iVar3 + 8);
      uVar4 = param_4 + uVar2;
      if (iVar1 != 0) {
        flash_end_veneer();
      }
      for (iVar3 = param_4; iVar3 != 0; iVar3 = iVar3 - iVar5) {
        iVar5 = iVar3;
        if (uVar2 >> 8 < uVar4 >> 8) {
          iVar5 = 0x100 - (uVar2 & 0xff);
        }
        flash_program_page_veneer(uVar2,iVar5,param_3);
        param_3 = param_3 + iVar5;
        uVar2 = uVar2 + iVar5;
      }
      if (iVar1 != 0) {
        flash_begin_veneer();
      }
      *param_2 = param_4 + *param_2;
      return 0;
    }
  }
  return 0xffffffff;
}

// FUNC 0x10001a6c  flash_region_read

undefined4 flash_region_read(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    iVar1 = iRam10001ab8 + param_1 * 0x14;
    if (((uint)(*param_2 + param_4) <= *(uint *)(iVar1 + 0xc)) &&
       (0x7ffffff < param_3 + 0xf0000000U)) {
      iVar1 = *(int *)(iVar1 + 8);
      memcpy(param_3,*param_2 + iVar1,param_4,iVar1,param_4);
      *param_2 = *param_2 + param_4;
      return 0;
    }
  }
  return 0xffffffff;
}

// FUNC 0x10001abc  watchdog_config

void watchdog_config(void)

{
  int iVar1;
  
  iVar1 = iRam10001ad0;
  *(undefined4 *)(iRam10001ad0 + 0xc00) = uRam10001ad4;
  *(undefined4 *)(iVar1 + 0xc) = 1;
  *(undefined4 *)(iVar1 + 0xc00) = uRam10001ad8;
  return;
}

// FUNC 0x10001b54  crc16_ccitt

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CRC-16 CCITT over a buffer, polynomial 0x1021 */

uint crc16_ccitt(byte *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  pbVar1 = param_1 + param_2;
  for (; pbVar1 != param_1; param_1 = param_1 + 1) {
    iVar2 = 8;
    uVar4 = uVar4 ^ (uint)*param_1 << 8;
    do {
      uVar3 = uVar4 << 1;
      if ((short)uVar4 < 0) {
        uVar3 = uVar3 ^ _DAT_10001b8c;
      }
      uVar4 = uVar3 & 0xffff;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  boot_printf(_DAT_10001b90,uVar4);
  return uVar4;
}

// FUNC 0x10001b94  boot_info_save

/* Writes the boot info record to the KV store and updates the header */

void boot_info_save(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = kv_write(2,param_1,0x1c);
  if (iVar1 == 0) {
    image_header_build(*param_1,param_1[2],param_1[3]);
  }
  return;
}

// FUNC 0x10001bb4  flash_erase_range

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Erases a range using the largest aligned block size */

void flash_erase_range(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = param_1 & 0xfffff000;
  uVar5 = (param_1 + param_2) - uVar3;
  while( true ) {
    if (uVar5 == 0) {
      return;
    }
    if (((uVar3 & 0xffff) == 0) && (0xf000 < (int)uVar5)) {
      uVar4 = 0x10000;
      uVar2 = _DAT_10001c24;
    }
    else if (((uVar3 & 0x7fff) == 0) && (0x7000 < (int)uVar5)) {
      uVar4 = 0x8000;
      uVar2 = _DAT_10001c28;
    }
    else {
      uVar4 = 0x1000;
      uVar2 = _DAT_10001c20;
    }
    iVar6 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar6 = isIRQinterruptsEnabled();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts(1);
    }
    flash_erase_sector_veneer(uVar2,uVar3,param_3,1,param_4);
    if (iVar6 == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(0);
      }
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(1);
      }
    }
    uVar3 = uVar3 + uVar4;
    if (uVar5 <= uVar4) break;
    uVar5 = uVar5 - uVar4;
  }
  return;
}

// FUNC 0x10001c2c  ota_region_clear

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Erases the OTA staging region and clears its flag */

undefined4 ota_region_clear(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((*(uint *)(param_1 + 4) & 0xffffff00) != _DAT_10001c68) && (*(int *)(param_1 + 0x10) == 0)) {
    boot_printf(_DAT_10001c6c,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18));
    flash_erase_range(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
    boot_info_save(param_1);
    uVar1 = 1;
  }
  return uVar1;
}

// FUNC 0x10001c70  flash_program_bytes

/* Programs a byte range with interrupts disabled */

undefined4 flash_program_bytes(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uStack_24;
  
  iVar2 = flash_status_veneer();
  uVar3 = param_3 + param_1;
  if (iVar2 != 0) {
    flash_end_veneer();
  }
  uStack_24 = param_2;
  for (; param_3 != 0; param_3 = param_3 - iVar4) {
    iVar4 = param_3;
    if (param_1 >> 8 < uVar3 >> 8) {
      iVar4 = 0x100 - (param_1 & 0xff);
    }
    iVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar5 = isIRQinterruptsEnabled();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts(1);
    }
    flash_program_page_veneer(param_1,iVar4,uStack_24,1);
    if (iVar5 == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(0);
      }
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts(1);
      }
    }
    param_1 = param_1 + iVar4;
    uStack_24 = uStack_24 + iVar4;
  }
  if (iVar2 != 0) {
    flash_begin_veneer();
  }
  return 0;
}

// FUNC 0x10001ce6  image_copy

/* Copies the staged image into the app region */

undefined4 image_copy(undefined4 param_1,undefined4 param_2)

{
  memcpy(param_2,param_1);
  return 0;
}

// FUNC 0x10001cf8  boot_map_exec_region

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Programs the IOMUX exec window for the app base and length */

void boot_map_exec_region(uint param_1,int param_2)

{
  *_DAT_10001d1c = _DAT_10001d20;
  *_DAT_10001d24 = param_1 & 0xfffffc00;
  *_DAT_10001d30 = param_2 + _DAT_10001d28 & _DAT_10001d2c | 0x1000000;
  return;
}

// FUNC 0x10001d34  boot_rollback_update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Increments the rollback counter, then falls back to the previous image */

void boot_rollback_update(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = _DAT_10001d80;
  uVar2 = param_1[1];
  if (((uVar2 & 0xffffff00) == _DAT_10001d7c) && ((uVar2 & 0xff) != 0)) {
    if ((uVar2 & 0xff) < 3) {
      param_1[1] = uVar2 + 1;
      boot_printf(_DAT_10001d84);
    }
    else {
      iVar3 = *param_1 + -1;
      *param_1 = (iVar3 - (*param_1 + -2)) - (uint)(iVar3 == 0);
      param_1[1] = 0;
      boot_printf(uVar1);
    }
    boot_info_save(param_1);
  }
  return;
}

// FUNC 0x10001d88  ota_image_handler

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Copies or decompresses the staged image and verifies its CRC16 */

void ota_image_handler(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iStack_120;
  int iStack_11c;
  undefined1 auStack_118 [260];
  
  uVar2 = _DAT_10001ec4;
  if (*(int *)(param_1 + 0x40) == 1) {
LAB_10001ebc:
    boot_printf(uVar2);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x44);
    if (uVar4 - 2 < 2) {
      boot_printf(_DAT_10001ec8);
      uVar2 = _DAT_10001ecc;
      if (*(int *)(param_1 + 0x44) == 3) {
        flash_erase_range(_DAT_10001ed0,*(undefined4 *)(param_1 + 0x5c));
        boot_printf(uVar2);
        boot_printf(_DAT_10001ed4);
        iVar1 = xz_decompress_mem(*(undefined4 *)(param_1 + 0x48),_DAT_10001ed0,
                                  *(undefined4 *)(param_1 + 0x5c));
        if (iVar1 != 0) {
          boot_printf(_DAT_10001ed8);
          DataSynchronizationBarrier(0xf);
          *(undefined4 *)(_DAT_10001edc + 0xc) = _DAT_10001ee0;
          DataSynchronizationBarrier(0xf);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
      }
      else {
        flash_erase_range(_DAT_10001ed0,*(undefined4 *)(param_1 + 0x5c));
        boot_printf(uVar2);
        boot_printf(_DAT_10001ee4);
        iStack_120 = *(int *)(param_1 + 0x48);
        uVar4 = *(uint *)(param_1 + 0x5c);
        iStack_11c = _DAT_10001ed0;
        for (; uVar4 != 0; uVar4 = uVar4 - uVar3) {
          uVar3 = 0x100;
          if (uVar4 < 0x100) {
            uVar3 = uVar4;
          }
          memcpy(auStack_118,iStack_120,uVar3);
          flash_program_bytes(iStack_11c,auStack_118,uVar3);
          iStack_120 = iStack_120 + uVar3;
          iStack_11c = iStack_11c + uVar3;
        }
      }
      uVar4 = crc16_ccitt(_DAT_10001ed0,*(undefined4 *)(param_1 + 0x5c));
      if ((*(uint *)(param_1 + 0x60) & 0xffff) != uVar4) {
        boot_printf(_DAT_10001ef0);
        DataSynchronizationBarrier(0xf);
        *(undefined4 *)(_DAT_10001edc + 0xc) = _DAT_10001ee0;
        DataSynchronizationBarrier(0xf);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      boot_printf(_DAT_10001ee8);
      uVar4 = 0;
      uVar3 = *(uint *)(param_1 + 0x48);
      *param_2 = 0;
      param_2[2] = uVar3;
      param_2[3] = *(uint *)(param_1 + 0x5c);
LAB_10001e28:
      param_2[1] = uVar4;
    }
    else {
      uVar2 = _DAT_10001efc;
      if (1 < uVar4) goto LAB_10001ebc;
      *param_2 = uVar4;
      param_2[2] = *(uint *)(param_1 + 0x48);
      param_2[3] = *(uint *)(param_1 + 0x5c);
      param_2[1] = 0;
      param_2[4] = 0;
      if (*(int *)(param_1 + 0x68) == _DAT_10001ef4) {
        boot_printf(_DAT_10001ef8);
        uVar4 = *(uint *)(param_1 + 0x68);
        goto LAB_10001e28;
      }
    }
    uVar3 = *(uint *)(param_1 + 100);
    uVar4 = *(uint *)(param_1 + 0x4c);
    param_2[4] = uVar3;
    param_2[5] = uVar4;
    param_2[6] = *(uint *)(param_1 + 0x50);
    boot_printf(_DAT_10001eec,*param_2,param_2[2],param_2[3],param_2[1],uVar3);
    boot_info_save(param_2);
  }
  return;
}

// FUNC 0x10001f00  boot_app_select

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Applies the rollback policy, maps the exec region and jumps to the app */

void boot_app_select(int *param_1)

{
  boot_rollback_update();
  if (*param_1 == 1) {
    boot_map_exec_region(param_1[2],param_1[3]);
    flash_exit_powerdown_veneer();
  }
  boot_jump_to_app(_DAT_10001f24);
  return;
}

// FUNC 0x10001f28  ota_image_verify

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Checks the OTA tag and CRC16, applies the image, then clears the staging area */

void ota_image_verify(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = strcmp(param_1,_DAT_10001fc4);
  if (iVar1 == 0) {
    boot_printf(_DAT_10001fcc,param_1,param_1 + 0x20,*(undefined4 *)(param_1 + 0x40),
                *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
                *(undefined4 *)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x58),
                *(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x60),
                *(undefined4 *)(param_1 + 0x68));
    if (*(int *)(param_1 + 0x40) == -1) {
      boot_printf(_DAT_10001fd0);
    }
    else {
      uVar3 = crc16_ccitt(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x54));
      if ((*(uint *)(param_1 + 0x58) & 0xffff) != uVar3) {
        kv_delete(3);
        uVar2 = _DAT_10001fd8;
        goto LAB_10001f42;
      }
      boot_printf(_DAT_10001fd4);
      ota_image_handler(param_1,param_2);
      *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
      kv_write(3,param_1,0x6c);
    }
    ota_region_clear(param_2);
  }
  else {
    kv_delete(3);
    uVar2 = _DAT_10001fc8;
LAB_10001f42:
    boot_printf(uVar2);
  }
  return;
}

// FUNC 0x10002030  xz_decompress_mem

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Decompresses an XZ stream from one buffer to another */

void xz_decompress_mem(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *_DAT_10002048 = param_1;
  uVar1 = _DAT_10002050;
  *_DAT_1000204c = param_2;
  uVar2 = _DAT_10002058;
  *_DAT_10002054 = param_3;
  xz_decompress_buffer(uVar1,uVar2);
  return;
}

// FUNC 0x1000205c  crc32_table_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Builds the 256-entry CRC-32 table */

void crc32_table_init(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = _DAT_10002090;
  uVar1 = _DAT_1000208c;
  uVar4 = 0;
  do {
    iVar3 = 8;
    uVar5 = uVar4;
    do {
      iVar3 = iVar3 + -1;
      uVar5 = -(uVar5 & 1) & uVar1 ^ uVar5 >> 1;
    } while (iVar3 != 0);
    iVar3 = uVar4 * 4;
    uVar4 = uVar4 + 1;
    *(uint *)(iVar2 + iVar3) = uVar5;
  } while (uVar4 != 0x100);
  return;
}

// FUNC 0x10002094  crc32_update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Table-driven CRC-32 update */

uint crc32_update(byte *param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  
  param_3 = ~param_3;
  pbVar1 = param_1 + param_2;
  for (; param_1 != pbVar1; param_1 = param_1 + 1) {
    param_3 = param_3 >> 8 ^ *(uint *)(((uint)*param_1 ^ param_3 & 0xff) * 4 + _DAT_100020bc);
  }
  return ~param_3;
}

// FUNC 0x100020c0  lzma_len

/* LZMA length bittree decode */

undefined8 lzma_len(uint *param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  
  if (*param_1 < 0x1000000) {
    *param_1 = *param_1 << 8;
    uVar4 = param_1[4];
    param_1[4] = uVar4 + 1;
    param_1[1] = (uint)*(byte *)(param_1[3] + uVar4) + param_1[1] * 0x100;
  }
  uVar1 = *param_2;
  uVar4 = (uint)uVar1 * (*param_1 >> 0xb);
  uVar6 = param_1[1];
  if (uVar4 < uVar6 || uVar4 - uVar6 == 0) {
    uVar3 = *param_1 - uVar4;
    *param_1 = uVar3;
    param_1[1] = uVar6 - uVar4;
    *param_2 = uVar1 - (uVar1 >> 5);
    if (uVar3 < 0x1000000) {
      *param_1 = uVar3 * 0x100;
      uVar3 = param_1[4];
      param_1[4] = uVar3 + 1;
      param_1[1] = (uint)*(byte *)(param_1[3] + uVar3) + (uVar6 - uVar4) * 0x100;
    }
    uVar1 = param_2[1];
    uVar6 = (uint)uVar1 * (*param_1 >> 0xb);
    uVar4 = param_1[1];
    if (uVar6 < uVar4 || uVar6 - uVar4 == 0) {
      *param_1 = *param_1 - uVar6;
      param_1[1] = uVar4 - uVar6;
      param_2[1] = uVar1 - (uVar1 >> 5);
      iVar2 = 0x204;
      param_1[0x19] = 0x12;
      uVar4 = 0x100;
      goto LAB_1000210a;
    }
    iVar2 = param_3 * 0x10 + 0x104;
    *param_1 = uVar6;
    param_2[1] = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
    uVar6 = 10;
  }
  else {
    uVar6 = 2;
    iVar2 = param_3 * 0x10 + 4;
    *param_1 = uVar4;
    *param_2 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
  }
  uVar4 = 8;
  param_1[0x19] = uVar6;
LAB_1000210a:
  uVar6 = 1;
  do {
    puVar5 = (ushort *)((int)param_2 + uVar6 * 2 + iVar2);
    if (*param_1 < 0x1000000) {
      *param_1 = *param_1 << 8;
      uVar3 = param_1[4];
      param_1[4] = uVar3 + 1;
      param_1[1] = (uint)*(byte *)(param_1[3] + uVar3) + param_1[1] * 0x100;
    }
    uVar7 = param_1[1];
    uVar1 = *puVar5;
    uVar3 = (uint)uVar1 * (*param_1 >> 0xb);
    uVar6 = uVar6 * 2;
    if (uVar3 < uVar7 || uVar3 - uVar7 == 0) {
      *param_1 = *param_1 - uVar3;
      uVar6 = uVar6 + 1;
      param_1[1] = uVar7 - uVar3;
      *puVar5 = uVar1 - (uVar1 >> 5);
    }
    else {
      *param_1 = uVar3;
      *puVar5 = uVar1 + (short)((int)(0x800 - (uint)uVar1) >> 5);
    }
  } while (uVar6 < uVar4);
  param_1[0x19] = (param_1[0x19] - uVar4) + uVar6;
  return CONCAT44(uVar7,param_1);
}

// FUNC 0x100021ea  dict_repeat

/* Repeats bytes from the LZMA dictionary */

undefined4 dict_repeat(int *param_1,uint *param_2,uint param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = *param_2;
  uVar6 = param_1[2];
  uVar5 = param_1[4] - uVar6;
  if (uVar3 < param_1[4] - uVar6) {
    uVar5 = uVar3;
  }
  *param_2 = uVar3 - uVar5;
  iVar4 = ~param_3 + uVar6;
  if (uVar6 <= param_3) {
    iVar4 = iVar4 + param_1[5];
  }
  do {
    iVar2 = param_1[2];
    param_1[2] = iVar2 + 1;
    puVar1 = (undefined1 *)(*param_1 + iVar4);
    iVar4 = iVar4 + 1;
    *(undefined1 *)(*param_1 + iVar2) = *puVar1;
    if (iVar4 == param_1[5]) {
      iVar4 = 0;
    }
    uVar5 = uVar5 - 1;
  } while (uVar5 != 0);
  if ((uint)param_1[3] < (uint)param_1[2]) {
    param_1[3] = param_1[2];
  }
  return 1;
}

// FUNC 0x10002234  lzma_main

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* LZMA symbol decode loop */

undefined4 lzma_main(uint *param_1)

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
  uint uStack_2c;
  
  if ((((param_1[8] < param_1[10]) && (param_1[0x19] != 0)) && (param_1[0x14] < param_1[9])) &&
     (param_1[0x14] < param_1[0xc])) {
    dict_repeat(param_1 + 6,param_1 + 0x19);
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
      uStack_2c = param_1[9];
      uVar6 = 0;
      if (uStack_2c != 0) {
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
        if (uStack_2c != 0) {
          uStack_2c = (uint)*(byte *)(uVar10 + iVar11);
        }
        uVar2 = 1;
        uVar6 = 0x100;
        do {
          uStack_2c = uStack_2c << 1;
          uVar3 = uVar6 & uStack_2c;
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
      lzma_len(param_1,(int)param_1 + _DAT_10002874,uVar2);
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
      lzma_len(param_1,param_1 + 0x1b6,uVar2);
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
        iVar4 = _DAT_1000286c;
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
          iVar11 = (uVar5 - uVar10) + _DAT_10002870;
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
       (iVar4 = dict_repeat(param_1 + 6,param_1 + 0x19), iVar4 == 0)) {
      return 0;
    }
  } while( true );
}

// FUNC 0x10002878  xz_dec_lzma2_run

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* LZMA2 chunk state machine */

undefined8 xz_dec_lzma2_run(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int extraout_r1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  undefined8 unaff_d11;
  undefined8 in_d30;
  undefined4 *puVar13;
  
  puVar13 = param_1;
  piVar9 = param_2;
LAB_1000287e:
  do {
    iVar3 = _DAT_10002bb4;
    pbVar7 = (byte *)(param_1 + 0x10);
    uVar12 = param_2[2];
    do {
      if (uVar12 <= (uint)param_2[1]) {
        if (*pbVar7 == 7) {
          uVar11 = param_2[5] - param_2[4];
          if ((uint)param_1[0x11] < (uint)(param_2[5] - param_2[4])) {
            uVar11 = param_1[0x11];
          }
          iVar4 = param_1[0xb];
          if (uVar11 < (uint)(iVar4 - param_1[8])) {
            iVar4 = uVar11 + param_1[8];
          }
          param_1[10] = iVar4;
          iVar3 = *(int *)((int)param_1 + iVar3);
          if ((iVar3 == 0) && (param_1[0x12] != 0)) {
LAB_10002bce:
            iVar3 = param_2[1];
            uVar12 = param_2[2] - iVar3;
            if (0x14 < uVar12) {
              iVar4 = param_2[2] + -0x15;
              param_1[3] = *param_2;
              param_1[4] = iVar3;
              if (param_1[0x12] + 0x15 <= uVar12) {
                iVar4 = iVar3 + param_1[0x12];
              }
              param_1[5] = iVar4;
              iVar3 = lzma_main(param_1);
              if (iVar3 == 0) goto LAB_10002a3a;
              iVar3 = param_1[4];
              if ((uint)param_1[0x12] < (uint)(iVar3 - param_2[1])) goto LAB_10002a3a;
              param_1[0x12] = (param_2[1] - iVar3) + param_1[0x12];
              param_2[1] = iVar3;
            }
            uVar11 = param_2[2] - param_2[1];
            if (uVar11 < 0x15) {
              uVar12 = param_1[0x12];
              if (uVar11 < (uint)param_1[0x12]) {
                uVar12 = uVar11;
              }
              memcpy((int)param_1 + _DAT_10002cf4,*param_2 + param_2[1],uVar12,_DAT_10002cf4,puVar13
                     ,piVar9,param_3);
              *(uint *)((int)param_1 + _DAT_10002cf0) = uVar12;
LAB_10002ba6:
              param_2[1] = param_2[1] + uVar12;
            }
          }
          else {
            uVar11 = param_1[0x12] - iVar3;
            if (0x2aU - iVar3 < uVar11) {
              uVar11 = 0x2aU - iVar3;
            }
            uVar12 = uVar12 - param_2[1];
            if (uVar11 < uVar12) {
              uVar12 = uVar11;
            }
            iVar4 = (int)param_1 + _DAT_10002bb8;
            memcpy(iVar4 + iVar3,*param_2 + param_2[1],uVar12,*param_2,puVar13,piVar9,param_3);
            piVar9 = *(int **)((int)param_1 + _DAT_10002bb4);
            uVar11 = uVar12 + (int)piVar9;
            if (uVar11 != param_1[0x12]) {
              if (0x14 < uVar11) {
                param_1[5] = uVar11 - 0x15;
                goto LAB_1000290c;
              }
              *(uint *)((int)param_1 + _DAT_10002bb4) = uVar11;
              goto LAB_10002ba6;
            }
            memset(iVar4 + uVar11,0,0x3f - uVar11,param_1[0x12],puVar13,piVar9);
            piVar9 = *(int **)((int)param_1 + _DAT_10002bb4);
            param_1[5] = (int)piVar9 + uVar12;
LAB_1000290c:
            param_1[3] = iVar4;
            param_1[4] = 0;
            iVar3 = lzma_main(param_1);
            if (iVar3 == 0) goto LAB_10002a3a;
            uVar11 = param_1[4];
            uVar5 = *(uint *)((int)param_1 + _DAT_10002bb4);
            if (uVar12 + uVar5 < uVar11) goto LAB_10002a3a;
            param_1[0x12] = param_1[0x12] - uVar11;
            iVar3 = _DAT_10002cf0;
            if (uVar5 <= uVar11) {
              param_2[1] = (param_2[1] - uVar5) + uVar11;
              *(undefined4 *)((int)param_1 + iVar3) = 0;
              goto LAB_10002bce;
            }
            *(uint *)((int)param_1 + _DAT_10002bb4) = uVar5 - uVar11;
            memmove(iVar4,iVar4 + uVar11);
          }
          iVar4 = param_1[8];
          iVar3 = param_1[7];
          piVar9 = (int *)(iVar4 - iVar3);
          if (*(char *)(param_1 + 0xf) != '\0') {
            if (iVar4 == param_1[0xb]) {
              param_1[8] = 0;
            }
            memcpy(param_2[3] + param_2[4],param_1[6] + iVar3,iVar4 - iVar3,param_1[6],puVar13,
                   piVar9,param_3);
          }
          iVar6 = param_2[4];
          param_1[7] = param_1[8];
          iVar6 = (iVar4 - iVar3) + iVar6;
          iVar4 = (iVar3 + param_1[0x11]) - iVar4;
          param_2[4] = iVar6;
          param_1[0x11] = iVar4;
          if (iVar4 == 0) {
            if (((param_1[0x12] != 0) || (param_1[0x19] != 0)) || (param_1[1] != 0))
            goto LAB_10002a3a;
            *param_1 = 0xffffffff;
            param_1[2] = 5;
            *(undefined1 *)(param_1 + 0x10) = 0;
            goto LAB_1000287e;
          }
          if ((param_2[5] != iVar6) &&
             ((param_2[1] != param_2[2] ||
              ((uint)param_1[0x12] <= *(uint *)((int)param_1 + _DAT_10002cf0))))) goto LAB_1000287e;
        }
        uVar1 = 0;
        goto LAB_10002a3c;
      }
    } while (8 < *pbVar7);
    FUN_100007dc();
    param_1 = (undefined4 *)(extraout_r1 * 8);
    VectorRoundHalvingAdd(in_d30,unaff_d11,4,1);
    param_2[1] = (int)param_2 * 2 + 1;
    uVar12 = (uint)*(byte *)(*param_2 + (int)param_2 * 2);
    if (uVar12 == 0) {
      uVar1 = 1;
      goto LAB_10002a3c;
    }
    pcVar2 = (char *)(param_1 + 0x13);
    if ((uVar12 < 0xe0) && (uVar12 != 1)) {
      if (*pcVar2 == '\0') goto LAB_10002a0c;
LAB_10002a3a:
      uVar1 = 7;
LAB_10002a3c:
      return CONCAT44(puVar13,uVar1);
    }
    pcVar2[0] = '\0';
    pcVar2[1] = '\x01';
    if (*(char *)(param_1 + 0xf) == '\0') {
      iVar3 = param_2[4];
      param_1[6] = param_2[3] + iVar3;
      param_1[0xb] = param_2[5] - iVar3;
    }
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[10] = 0;
    param_1[9] = 0;
LAB_10002a0c:
    if (uVar12 < 0x80) {
      if (2 < uVar12) goto LAB_10002a3a;
      *(short *)(param_1 + 0x10) = (short)_DAT_10002bbc;
    }
    else {
      param_1[0x11] = (uVar12 & 0x1f) << 0x10;
      *pbVar7 = 1;
      if (uVar12 < 0xc0) {
        if (*(char *)((int)param_1 + 0x4d) != '\0') goto LAB_10002a3a;
        *(undefined1 *)((int)param_1 + 0x41) = 6;
        if (0x9f < uVar12) {
          *(undefined1 *)(param_1 + 0x18) = 0;
          param_1[0x14] = 0;
          param_1[0x15] = 0;
          param_1[0x16] = 0;
          param_1[0x17] = 0;
          puVar10 = param_1 + 0x1d;
          puVar8 = (undefined4 *)((int)param_1 + _DAT_10002bb4);
          do {
            *(undefined2 *)puVar10 = 0x400;
            puVar10 = (undefined4 *)((int)puVar10 + 2);
          } while (puVar8 != puVar10);
          *param_1 = 0xffffffff;
          param_1[1] = 0;
          param_1[2] = 5;
        }
      }
      else {
        *(char *)((int)param_1 + 0x4d) = '\0';
        *(undefined1 *)((int)param_1 + 0x41) = 5;
      }
    }
  } while( true );
}

// FUNC 0x10002cf8  lzma2_create

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Allocates the LZMA2 dictionary state */

int lzma2_create(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_100043bc(_DAT_10002d38);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x3c) = (char)param_1;
    *(undefined4 *)(iVar1 + 0x34) = param_2;
    if (param_1 == 1) {
      iVar2 = FUN_100043bc(param_2);
      *(int *)(iVar1 + 0x18) = iVar2;
      if (iVar2 == 0) {
        FUN_100043d0(iVar1);
        iVar1 = 0;
      }
    }
    else if (param_1 == 2) {
      *(undefined4 *)(iVar1 + 0x18) = 0;
      *(undefined4 *)(iVar1 + 0x38) = 0;
    }
  }
  return iVar1;
}

// FUNC 0x10002d3c  lzma2_reset

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Resets the dictionary and LZMA properties */

undefined4 lzma2_reset(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = 6;
  if (param_2 < 0x28) {
    uVar3 = (param_2 & 1) + 2 << ((param_2 >> 1) + 0xb & 0xff);
    *(uint *)(param_1 + 0x30) = uVar3;
    if (*(char *)(param_1 + 0x3c) != '\0') {
      if (*(uint *)(param_1 + 0x34) < uVar3) {
        return 4;
      }
      *(uint *)(param_1 + 0x2c) = uVar3;
      if ((*(char *)(param_1 + 0x3c) == '\x02') && (*(uint *)(param_1 + 0x38) < uVar3)) {
        FUN_100043d0(*(undefined4 *)(param_1 + 0x18));
        iVar2 = FUN_100043bc(*(undefined4 *)(param_1 + 0x30));
        *(int *)(param_1 + 0x18) = iVar2;
        if (iVar2 == 0) {
          *(undefined4 *)(param_1 + 0x38) = 0;
          return 3;
        }
      }
    }
    uVar1 = 0;
    *(undefined4 *)(param_1 + 100) = 0;
    *(undefined1 *)(param_1 + 0x40) = 0;
    *(undefined1 *)(param_1 + 0x4c) = 1;
    *(undefined4 *)(param_1 + _DAT_10002da0) = 0;
  }
  return uVar1;
}

// FUNC 0x10002da4  lzma2_end

/* Frees the LZMA2 dictionary state */

void lzma2_end(int param_1)

{
  if (*(char *)(param_1 + 0x3c) != '\0') {
    FUN_100043d0(*(undefined4 *)(param_1 + 0x18));
  }
  FUN_100043d0(param_1);
  return;
}

// FUNC 0x10002dc0  lzma2_get_value

/* Returns the first field of the LZMA2 state */

undefined4 lzma2_get_value(undefined4 *param_1)

{
  return *param_1;
}

// FUNC 0x10002dd6  lzma_props

/* Parses the five LZMA property bytes */

undefined8 lzma_props(int param_1,int param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  while( true ) {
    uVar3 = *param_3;
    if (param_4 <= uVar3) {
      uVar2 = 0;
      goto LAB_10002e2c;
    }
    iVar4 = *(int *)(param_1 + 4);
    bVar1 = *(byte *)(param_2 + uVar3);
    *param_3 = uVar3 + 1;
    uVar5 = aeabi_llsl(bVar1 & 0x7f,0,iVar4);
    *(uint *)(param_1 + 8) = (uint)uVar5 | *(uint *)(param_1 + 8);
    *(uint *)(param_1 + 0xc) = (uint)((ulonglong)uVar5 >> 0x20) | *(uint *)(param_1 + 0xc);
    if (-1 < (char)bVar1) break;
    *(int *)(param_1 + 4) = iVar4 + 7;
    if (iVar4 + 7 == 0x3f) {
LAB_10002e2a:
      uVar2 = 7;
LAB_10002e2c:
      return CONCAT44(param_2,uVar2);
    }
  }
  if ((bVar1 != 0) || (iVar4 == 0)) {
    uVar2 = 1;
    *(undefined4 *)(param_1 + 4) = 0;
    goto LAB_10002e2c;
  }
  goto LAB_10002e2a;
}

// FUNC 0x10002e40  xz_dec_crc_update

void xz_dec_crc_update(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = param_2[1] - *(int *)(param_1 + 0x10);
  uVar1 = *(uint *)(param_1 + 0x70);
  iVar2 = *param_2;
  *(uint *)(param_1 + 0x70) = uVar4 + uVar1;
  *(uint *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + (uint)CARRY4(uVar4,uVar1);
  uVar3 = crc32_update(iVar2 + *(int *)(param_1 + 0x10),uVar4,*(undefined4 *)(param_1 + 0x18),
                       param_2,param_4);
  *(undefined4 *)(param_1 + 0x18) = uVar3;
  return;
}

// FUNC 0x10002e6c  bcj_fill_temp

/* Fills the branch-converter temporary buffer */

bool bcj_fill_temp(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  piVar4 = (int *)(param_1 + 0x98);
  uVar1 = param_2[2] - param_2[1];
  uVar2 = *(int *)(param_1 + 0x9c) - *piVar4;
  if (uVar1 < uVar2) {
    uVar2 = uVar1;
  }
  memcpy(param_1 + 0xa0 + *piVar4,*param_2 + param_2[1],uVar2,*param_2,param_4);
  param_2[1] = param_2[1] + uVar2;
  iVar3 = uVar2 + *piVar4;
  *piVar4 = iVar3;
  bVar5 = iVar3 == *(int *)(param_1 + 0x9c);
  if (bVar5) {
    *piVar4 = 0;
  }
  return bVar5;
}

// FUNC 0x10002eb2  bcj_reset

/* Resets the branch-converter state */

void bcj_reset(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[0x1e] = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  memset(param_1 + 0x38,0,0x30);
  memset(param_1 + 0x68,0,0x30);
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0xc;
  return;
}

// FUNC 0x10002ee8  xz_dec_run

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* XZ container state machine: headers, blocks and checks */

int xz_dec_run(byte *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int extraout_r1;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  int *piVar12;
  byte *pbVar13;
  byte *pbVar14;
  int iVar15;
  uint *puVar16;
  uint uVar17;
  
  if (param_1[0x1d] == 0) {
    bcj_reset();
  }
  iVar8 = *(int *)(param_2 + 4);
  iVar9 = *(int *)(param_2 + 0x10);
  *(int *)(param_1 + 0x10) = iVar8;
  while( true ) {
    do {
    } while (9 < *param_1);
    FUN_100007f0();
    piVar12 = (int *)(extraout_r1 * 0x2000);
    iVar1 = bcj_fill_temp(param_1,piVar12,extraout_r1 << 7,extraout_r1 << 0x10);
    uVar4 = _DAT_10003280;
    if (iVar1 == 0) goto LAB_10002f30;
    *param_1 = 1;
    iVar1 = memcmp(param_1 + 0xa0,uVar4,6);
    if (iVar1 != 0) {
      iVar1 = 5;
      goto LAB_10002f66;
    }
    iVar1 = crc32_update(param_1 + 0xa6,2);
    iVar2 = lzma2_get_value(param_1 + 0xa8);
    if (iVar1 != iVar2) goto LAB_10002f64;
    if ((param_1[0xa6] != 0) || (param_1[0x1c] = param_1[0xa7], 1 < param_1[0xa7]))
    goto LAB_10002f90;
    iVar1 = piVar12[1];
    if (iVar1 == piVar12[2]) goto LAB_10002f30;
    if (*(byte *)(*piVar12 + iVar1) != 0) break;
    piVar12[1] = iVar1 + 1;
    bVar7 = 6;
    *(int *)(param_1 + 0x10) = iVar1;
LAB_10002fb8:
    *param_1 = bVar7;
  }
  iVar1 = (*(byte *)(*piVar12 + iVar1) + 1) * 4;
  *(int *)(param_1 + 0x30) = iVar1;
  *(int *)(param_1 + 0x9c) = iVar1;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  *param_1 = 2;
  iVar1 = bcj_fill_temp(param_1,piVar12);
  if (iVar1 == 0) {
LAB_10002f30:
    iVar1 = 0;
LAB_10002f66:
    if (param_1[0x1d] == 0) {
      if (iVar1 == 0) {
        iVar1 = 8 - (uint)(piVar12[1] == piVar12[2]);
      }
      else if (iVar1 == 1) {
        return 1;
      }
      piVar12[1] = iVar8;
      piVar12[4] = iVar9;
    }
    else {
      if (((iVar1 == 0) && (piVar12[1] == iVar8)) && (piVar12[4] == iVar9)) {
        if (param_1[0x1e] != 0) {
          iVar1 = 8;
        }
        bVar7 = 1;
      }
      else {
        bVar7 = 0;
      }
      param_1[0x1e] = bVar7;
    }
    return iVar1;
  }
  pbVar14 = param_1 + 0x9c;
  iVar1 = *(int *)pbVar14;
  pbVar13 = param_1 + 0xa0;
  *(int *)pbVar14 = iVar1 + -4;
  iVar1 = crc32_update(pbVar13,iVar1 + -4,0);
  iVar15 = *(int *)pbVar14;
  iVar2 = lzma2_get_value(pbVar13 + iVar15);
  if (iVar1 == iVar2) {
    pbVar14 = param_1 + 0x98;
    pbVar14[0] = 2;
    pbVar14[1] = 0;
    pbVar14[2] = 0;
    pbVar14[3] = 0;
    if ((param_1[0xa1] & 0x3f) == 0) {
      if ((int)((uint)param_1[0xa1] << 0x19) < 0) {
        iVar1 = lzma_props(param_1,pbVar13,pbVar14,iVar15);
        if (iVar1 != 1) goto LAB_10002f64;
        uVar4 = *(undefined4 *)(param_1 + 8);
        uVar11 = *(undefined4 *)(param_1 + 0xc);
      }
      else {
        uVar4 = 0xffffffff;
        uVar11 = 0xffffffff;
      }
      *(undefined4 *)(param_1 + 0x20) = uVar4;
      *(undefined4 *)(param_1 + 0x24) = uVar11;
      if (param_1[0xa1] < 0x80) {
        uVar4 = 0xffffffff;
        uVar11 = 0xffffffff;
      }
      else {
        iVar1 = lzma_props(param_1,pbVar13,param_1 + 0x98,*(undefined4 *)(param_1 + 0x9c));
        if (iVar1 != 1) goto LAB_10002f64;
        uVar4 = *(undefined4 *)(param_1 + 8);
        uVar11 = *(undefined4 *)(param_1 + 0xc);
      }
      *(undefined4 *)(param_1 + 0x28) = uVar4;
      *(undefined4 *)(param_1 + 0x2c) = uVar11;
      puVar16 = (uint *)(param_1 + 0x98);
      uVar3 = *(uint *)(param_1 + 0x9c);
      uVar5 = *puVar16;
      if (uVar3 - uVar5 < 2) goto LAB_10002f64;
      *puVar16 = uVar5 + 1;
      if (param_1[uVar5 + 0xa0] == 0x21) {
        *puVar16 = uVar5 + 2;
        if (param_1[uVar5 + 0xa1] == 1) {
          if (uVar3 == uVar5 + 2) goto LAB_10002f64;
          *puVar16 = uVar5 + 3;
          iVar1 = lzma2_reset(*(undefined4 *)(param_1 + 0x4a0),param_1[uVar5 + 0xa2]);
          if (iVar1 != 0) goto LAB_10002f66;
          while (uVar3 = *puVar16, uVar3 < *(uint *)(param_1 + 0x9c)) {
            *puVar16 = uVar3 + 1;
            if (param_1[uVar3 + 0xa0] != 0) goto LAB_10002f90;
          }
          *puVar16 = 0;
          param_1[0x38] = 0;
          param_1[0x39] = 0;
          param_1[0x3a] = 0;
          param_1[0x3b] = 0;
          param_1[0x3c] = 0;
          param_1[0x3d] = 0;
          param_1[0x3e] = 0;
          param_1[0x3f] = 0;
          param_1[0x40] = 0;
          param_1[0x41] = 0;
          param_1[0x42] = 0;
          param_1[0x43] = 0;
          param_1[0x44] = 0;
          param_1[0x45] = 0;
          param_1[0x46] = 0;
          param_1[0x47] = 0;
          *param_1 = 3;
          *(int *)(param_1 + 0x10) = piVar12[1];
          *(int *)(param_1 + 0x14) = piVar12[4];
          iVar1 = xz_dec_lzma2_run(*(undefined4 *)(param_1 + 0x4a0),piVar12);
          uVar3 = (piVar12[1] - *(int *)(param_1 + 0x10)) + *(uint *)(param_1 + 0x38);
          uVar5 = *(int *)(param_1 + 0x3c) +
                  (uint)CARRY4(piVar12[1] - *(int *)(param_1 + 0x10),*(uint *)(param_1 + 0x38));
          *(uint *)(param_1 + 0x38) = uVar3;
          *(uint *)(param_1 + 0x3c) = uVar5;
          uVar17 = piVar12[4] - *(int *)(param_1 + 0x14);
          uVar6 = uVar17 + *(uint *)(param_1 + 0x40);
          uVar10 = *(int *)(param_1 + 0x44) + (uint)CARRY4(uVar17,*(uint *)(param_1 + 0x40));
          *(uint *)(param_1 + 0x40) = uVar6;
          *(uint *)(param_1 + 0x44) = uVar10;
          if (((uVar5 <= *(uint *)(param_1 + 0x24)) &&
              (((*(uint *)(param_1 + 0x24) != uVar5 || (uVar3 <= *(uint *)(param_1 + 0x20))) &&
               (uVar10 <= *(uint *)(param_1 + 0x2c))))) &&
             ((*(uint *)(param_1 + 0x2c) != uVar10 || (uVar6 <= *(uint *)(param_1 + 0x28))))) {
            if (param_1[0x1c] == 1) {
              uVar4 = crc32_update(*(int *)(param_1 + 0x14) + piVar12[3],uVar17,
                                   *(undefined4 *)(param_1 + 0x18));
              *(undefined4 *)(param_1 + 0x18) = uVar4;
            }
            if (iVar1 != 1) goto LAB_10002f66;
            if (((*(int *)(param_1 + 0x20) == -1) && (*(int *)(param_1 + 0x24) == -1)) ||
               ((*(int *)(param_1 + 0x38) == *(int *)(param_1 + 0x20) &&
                (*(int *)(param_1 + 0x3c) == *(int *)(param_1 + 0x24))))) {
              uVar3 = *(uint *)(param_1 + 0x40);
              if (((*(uint *)(param_1 + 0x28) == 0xffffffff) && (*(int *)(param_1 + 0x2c) == -1)) ||
                 ((uVar3 == *(uint *)(param_1 + 0x28) &&
                  (*(int *)(param_1 + 0x44) == *(int *)(param_1 + 0x2c))))) {
                uVar5 = *(uint *)(param_1 + 0x50) + *(uint *)(param_1 + 0x38);
                uVar6 = uVar5 + *(uint *)(param_1 + 0x30);
                iVar1 = *(int *)(param_1 + 0x54) + *(int *)(param_1 + 0x3c) +
                        (uint)CARRY4(*(uint *)(param_1 + 0x50),*(uint *)(param_1 + 0x38)) +
                        (uint)CARRY4(uVar5,*(uint *)(param_1 + 0x30));
                *(uint *)(param_1 + 0x50) = uVar6;
                *(int *)(param_1 + 0x54) = iVar1;
                if (param_1[0x1c] == 1) {
                  *(uint *)(param_1 + 0x50) = uVar6 + 4;
                  *(uint *)(param_1 + 0x54) = iVar1 + (uint)(0xfffffffb < uVar6);
                }
                uVar5 = *(uint *)(param_1 + 0x58);
                *(uint *)(param_1 + 0x58) = uVar3 + uVar5;
                *(uint *)(param_1 + 0x5c) =
                     *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x5c) + (uint)CARRY4(uVar3,uVar5)
                ;
                uVar4 = crc32_update(param_1 + 0x50,0x18,*(undefined4 *)(param_1 + 0x60));
                uVar3 = *(uint *)(param_1 + 0x48);
                *(undefined4 *)(param_1 + 0x60) = uVar4;
                *(uint *)(param_1 + 0x48) = uVar3 + 1;
                *(uint *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + (uint)(0xfffffffe < uVar3);
                *param_1 = 4;
                while( true ) {
                  uVar3 = *(uint *)(param_1 + 0x38);
                  iVar1 = *(int *)(param_1 + 0x3c);
                  if ((uVar3 & 3) == 0) break;
                  iVar2 = piVar12[1];
                  if (iVar2 == piVar12[2]) goto LAB_10002f30;
                  piVar12[1] = iVar2 + 1;
                  if (*(char *)(*piVar12 + iVar2) != '\0') goto LAB_10002f64;
                  *(uint *)(param_1 + 0x38) = uVar3 + 1;
                  *(uint *)(param_1 + 0x3c) = iVar1 + (uint)(0xfffffffe < uVar3);
                }
                *param_1 = 5;
                if (param_1[0x1c] == 1) {
                  iVar1 = piVar12[2];
                  do {
                    iVar2 = piVar12[1];
                    if (iVar2 == iVar1) goto LAB_10002f30;
                    uVar5 = *(uint *)(param_1 + 4);
                    uVar3 = *(uint *)(param_1 + 0x18);
                    piVar12[1] = iVar2 + 1;
                    if ((uVar3 >> (uVar5 & 0xff) & 0xff) != (uint)*(byte *)(*piVar12 + iVar2))
                    goto LAB_10002f64;
                    uVar5 = uVar5 + 8;
                    *(uint *)(param_1 + 4) = uVar5;
                  } while (uVar5 < 0x20);
                  param_1[0x18] = 0;
                  param_1[0x19] = 0;
                  param_1[0x1a] = 0;
                  param_1[0x1b] = 0;
                  param_1[4] = 0;
                  param_1[5] = 0;
                  param_1[6] = 0;
                  param_1[7] = 0;
                }
                bVar7 = 1;
                goto LAB_10002fb8;
              }
            }
          }
          goto LAB_10002f64;
        }
      }
    }
LAB_10002f90:
    iVar1 = 6;
    goto LAB_10002f66;
  }
LAB_10002f64:
  iVar1 = 7;
  goto LAB_10002f66;
}

// FUNC 0x100034a4  xz_dec_lzma2_create

/* Allocates the XZ decoder state */

int xz_dec_lzma2_create(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_100043bc(0x4a8);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x1d) = (char)param_1;
    iVar2 = lzma2_create(param_1,param_2);
    *(int *)(iVar1 + 0x4a0) = iVar2;
    if (iVar2 == 0) {
      FUN_100043d0();
      iVar1 = 0;
    }
    else {
      bcj_reset(iVar1);
    }
  }
  return iVar1;
}

// FUNC 0x100034de  xz_dec_lzma2_end

/* Frees the XZ decoder state */

void xz_dec_lzma2_end(int param_1)

{
  if (param_1 != 0) {
    lzma2_end(*(undefined4 *)(param_1 + 0x4a0));
    FUN_100043d0(param_1);
  }
  return;
}

// FUNC 0x100034f8  xz_decompress_buffer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Allocates I/O buffers and drives the XZ decoder */

undefined4 xz_decompress_buffer(code *param_1,code *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  
  crc32_table_init();
  iVar1 = xz_dec_lzma2_create(2,0x4000);
  uVar4 = _DAT_10003618;
  if (iVar1 != 0) {
    iStack_30 = FUN_100043bc(0x1000);
    iStack_2c = 0;
    iStack_28 = 0;
    iStack_24 = FUN_100043bc(0x1000);
    iStack_20 = 0;
    uStack_1c = 0x1000;
    do {
      if (iStack_2c == iStack_28) {
        iStack_28 = (*param_1)(iStack_30,1,0x1000,0);
        iStack_2c = 0;
      }
      iVar2 = xz_dec_run(iVar1,&iStack_30);
      if (iStack_20 == 0x1000) {
        iVar3 = (*param_2)(iStack_24,1,0x1000,0);
        uVar4 = _DAT_100035fc;
        if (iVar3 != iStack_20) goto LAB_1000357a;
        iStack_20 = 0;
      }
    } while (iVar2 == 0);
    iVar3 = (*param_2)(iStack_24,1,iStack_20,0);
    uVar4 = _DAT_100035fc;
    if ((iVar3 == iStack_20) && (uVar4 = _DAT_10003614, iVar2 - 1U < 8)) {
      FUN_100007c8();
      uVar4 = _DAT_10003604;
    }
  }
LAB_1000357a:
  xz_dec_lzma2_end(iVar1);
  if (iStack_30 != 0) {
    FUN_100043d0();
  }
  if (iStack_24 != 0) {
    FUN_100043d0();
  }
  boot_printf(_DAT_10003600,uVar4);
  return 1;
}

// FUNC 0x10003644  kv_store_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Registers the SYS ENV and SYS KV callbacks and mounts the store */

int kv_store_init(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *_DAT_10003680 = param_1;
  uVar1 = _DAT_10003688;
  *_DAT_10003684 = param_2;
  if (param_1 != 0) {
    kv_set_callback(uVar1,2,_DAT_1000368c);
  }
  if (param_2 != 0) {
    kv_set_callback(uVar1,3,_DAT_10003690);
  }
  iVar2 = kv_mount(uVar1,_DAT_10003698,_DAT_10003694);
  return -(uint)(iVar2 != 0);
}

// FUNC 0x1000369c  kv_read

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reads a KV record by id into a caller buffer */

int kv_read(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1c [16];
  int iStack_c;
  
  uVar1 = FUN_1000439c(auStack_1c);
  xz_decode_finish(_DAT_100036c0,param_1,uVar1);
  return -(uint)(iStack_c == 0);
}

// FUNC 0x100036c4  kv_write

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Writes a KV record by id, magic KV10 */

void kv_write(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1c [20];
  
  uVar1 = FUN_1000439c(auStack_1c);
  FUN_10003ef4(_DAT_100036e0,param_1,uVar1);
  return;
}

// FUNC 0x100036e4  kv_delete

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Deletes a KV record by id */

void kv_delete(undefined4 param_1)

{
  kv_erase_entry(_DAT_100036f0,param_1);
  return;
}

// FUNC 0x10003726  xz_block_decode

/* Decodes one XZ block header and its compressed data */

undefined4 xz_block_decode(undefined4 param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_4c [8];
  int iStack_44;
  uint uStack_40;
  undefined2 uStack_3c;
  undefined1 auStack_38 [36];
  
  xz_hdr_validate(param_1,*(undefined4 *)(param_2 + 8),auStack_4c,0x14);
  uVar1 = xz_block_data_done(auStack_4c,6);
  *(undefined1 *)param_2 = uVar1;
  if (uStack_40 < 0x81) {
    uVar3 = 0;
    iVar4 = 0;
    *(uint *)(param_2 + 4) = uStack_40;
    uVar2 = uStack_40 + 8;
    do {
      iVar5 = 0x20;
      if (uVar2 <= uVar3 + 0x20) {
        iVar5 = uVar2 - uVar3;
      }
      xz_hdr_validate(param_1,*(int *)(param_2 + 8) + 0xc + uVar3,auStack_38,iVar5);
      iVar4 = xz_crc32_ccitt_update(iVar4,auStack_38,iVar5);
      uVar3 = uVar3 + iVar5;
    } while (uVar3 < uVar2);
    if (iStack_44 == iVar4) {
      *(undefined1 *)((int)param_2 + 1) = 1;
      param_2[6] = uStack_3c;
      *(int *)(param_2 + 10) = *(int *)(param_2 + 8) + 0x14;
      return 0;
    }
    *(undefined1 *)((int)param_2 + 1) = 0;
  }
  else {
    *(undefined4 *)(param_2 + 4) = 0x80;
    *param_2 = 5;
  }
  return 2;
}

// FUNC 0x100037b0  FUN_100037b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100037b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int extraout_r1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = param_3;
  uStack_14 = param_4;
  memset(&uStack_18,0,8,param_4,param_1,param_2);
  uVar2 = *(undefined4 *)(param_1 + 8);
  aeabi_uidiv(param_2,uVar2);
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = xz_hdr_crc_update(param_1,param_2,uVar2);
  if (iVar1 == 0) {
    memset(&uStack_18,0xff,8);
    xz_crc32_ccitt_init(&uStack_18,4,1);
    xz_crc32_ccitt_init((int)&uStack_18 + 1,4,1);
    uStack_14 = _DAT_10003818;
    xz_block_len_update(param_1,param_2,&uStack_18,8,1);
  }
  return;
}

// FUNC 0x10003874  xz_block_decode_hdr

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Parses the XZ block header fields */

uint xz_block_decode_hdr(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_2c [4];
  int iStack_28;
  
  if (*(char *)(param_2 + 1) != '\x01') {
    uVar1 = *param_3;
    if (uVar1 == 0xffffffff) {
      return *(int *)(param_2 + 4) + 8;
    }
    uVar3 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
    if (uVar1 <= uVar3) {
      uVar3 = uVar3 - 8;
      uVar1 = uVar1 + 0x94;
      do {
        uVar2 = uVar1;
        if ((uVar3 <= uVar2) || (uVar3 <= uVar2 + 0x94)) {
          uVar2 = 0xffffffff;
          break;
        }
        xz_hdr_validate(param_1,uVar2,auStack_2c,0x14);
        uVar1 = uVar2 + 0x94;
      } while (iStack_28 != _DAT_100038dc);
      if (uVar2 <= (uint)(*(int *)(param_2 + 4) + *(int *)(param_1 + 8))) {
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}

// FUNC 0x100038e0  FUN_100038e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_100038e0(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  int extraout_r1;
  undefined1 uStack_38;
  undefined1 auStack_37 [3];
  int iStack_34;
  byte bStack_30;
  char cStack_2f;
  int aiStack_20 [3];
  
  memset(&uStack_38,0,8);
  aeabi_uidiv(param_2,*(undefined4 *)(param_1 + 8));
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  xz_hdr_validate(param_1,param_2,&uStack_38,8);
  iVar1 = _DAT_100039a8;
  *(undefined4 *)(param_3 + 4) = param_2;
  *(int *)(param_3 + 8) = iStack_34;
  if (iStack_34 == iVar1) {
    *param_3 = 1;
    uVar2 = xz_block_data_done(&uStack_38,4);
    param_3[1] = uVar2;
    uVar2 = xz_block_data_done(auStack_37,4);
    param_3[2] = uVar2;
    if (param_4 != 0) {
      aiStack_20[0] = *(int *)(param_3 + 4) + 8;
      *(undefined4 *)(param_3 + 0xc) = 0;
      *(int *)(param_3 + 0x10) = aiStack_20[0];
      if (param_3[1] == '\x01') {
        *(int *)(param_3 + 0xc) = *(int *)(param_1 + 8) + -8;
      }
      else if (param_3[1] == '\x02') {
        *(int *)(param_3 + 0xc) = *(int *)(param_1 + 8) + -8;
        do {
          xz_block_decode(param_1,&bStack_30);
          if ((cStack_2f == '\0') && ((bStack_30 & 0xfb) != 1)) {
            *(undefined4 *)(param_3 + 0xc) = 0;
            return 2;
          }
          *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 0x94;
          *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + -0x94;
          aiStack_20[0] = xz_block_decode_hdr(param_1,param_3,aiStack_20);
        } while (aiStack_20[0] != -1);
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 8;
    *param_3 = 0;
  }
  return uVar2;
}

// FUNC 0x100039ac  xz_block_decode_loop

/* Main decode loop for XZ compressed data */

void xz_block_decode_loop
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 uStack_2c;
  byte bStack_2b;
  int iStack_28;
  
  do {
    uVar2 = 0;
    while( true ) {
      iVar1 = FUN_100038e0(param_1,uVar2,&uStack_2c,0);
      if ((iVar1 == 0) && (bStack_2b - 2 < 2)) {
        *(int *)(param_2 + 0x10) = iStack_28 + 8;
        do {
          xz_block_decode(param_1,param_2);
          iVar1 = (*param_5)(param_2,param_3,param_4);
          if (iVar1 != 0) {
            return;
          }
          iVar1 = xz_block_decode_hdr(param_1,&uStack_2c,param_2 + 0x10);
          *(int *)(param_2 + 0x10) = iVar1;
        } while (iVar1 != -1);
      }
      if (iStack_28 == -1) break;
      uVar2 = iStack_28 + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar2) || (uVar2 == 0xffffffff)) {
        return;
      }
    }
  } while( true );
}

// FUNC 0x10003a1c  FUN_10003a1c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_10003a1c(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  undefined2 auStack_12 [4];
  undefined1 uStack_9;
  
  uStack_9 = 0;
  auStack_12[0] = param_2;
  xz_block_decode_loop(param_1,param_3,auStack_12,&uStack_9,_DAT_10003a44);
  return uStack_9;
}

// FUNC 0x10003a48  FUN_10003a48

int FUN_10003a48(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [28];
  
  if (param_3 == (undefined1 *)0x0) {
    iVar1 = FUN_10003a1c(param_1,param_2,auStack_30);
    if (iVar1 == 0) {
      return 5;
    }
    param_3 = auStack_30;
  }
  if (param_4 != 0) {
    iVar1 = xz_stream_done(param_1,*(undefined4 *)(param_3 + 0x10),auStack_34,6,4,1);
  }
  else {
    iVar1 = xz_stream_done(param_1,*(undefined4 *)(param_3 + 0x10),auStack_34,6,3,0);
  }
  *(bool *)(param_1 + 0x58) = param_4 == 0;
  if (iVar1 == 0) {
    iVar3 = (*(uint *)(param_3 + 0x10) & -*(int *)(param_1 + 8)) + 1;
    iVar2 = FUN_10004380(param_1,iVar3,auStack_34,4);
    if (iVar2 == 1) {
      iVar1 = xz_stream_done(param_1,iVar3,auStack_34,4,2,1);
    }
  }
  return iVar1;
}

// FUNC 0x10003af4  FUN_10003af4

undefined4 FUN_10003af4(undefined4 param_1,int param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  undefined1 auStack_14 [8];
  
  if (*(char *)(param_2 + 1) == '\x01') {
    uVar1 = xz_stream_done(param_1,*(undefined4 *)(param_2 + 4),auStack_14,4,2,1);
  }
  else {
    uVar1 = 0;
    if (*(char *)(param_2 + 1) == '\x02') {
      if (*(uint *)(param_2 + 0xc) < 0x128) {
        uVar1 = xz_stream_done(param_1,*(undefined4 *)(param_2 + 4),auStack_14,4,3,1);
        if (param_3 != (undefined1 *)0x0) {
          *param_3 = 1;
        }
      }
      else if (param_3 != (undefined1 *)0x0) {
        *param_3 = 0;
      }
    }
  }
  return uVar1;
}

// FUNC 0x10003b4c  xz_container_decode

/* Decodes the XZ container format: stream headers and blocks */

undefined8
xz_container_decode(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                   code *param_6,byte param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (uint)param_7;
  uVar4 = param_3;
  do {
    uVar3 = 0;
    while( true ) {
      FUN_100038e0(param_1,uVar3,param_2,0,param_4,uVar2,uVar4);
      if ((param_3 == 0) || (*(byte *)(param_2 + 1) == param_3)) {
        if (uVar2 != 0) {
          FUN_100038e0(param_1,uVar3,param_2,1,param_4,uVar2,uVar4);
        }
        iVar1 = (*param_6)(param_2,param_4,param_5);
        if (iVar1 != 0) goto LAB_10003ba8;
      }
      if (*(int *)(param_2 + 4) == -1) break;
      uVar3 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar3) || (uVar3 == 0xffffffff)) {
LAB_10003ba8:
        return CONCAT44(uVar2,param_4);
      }
    }
  } while( true );
}

// FUNC 0x10003bac  FUN_10003bac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_10003bac(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iStack_28;
  uint uStack_24;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  int *piStack_14;
  
  iStack_28 = -1;
  piStack_14 = &iStack_28;
  uStack_24 = 0;
  iStack_20 = 0;
  iStack_1c = param_1;
  uStack_18 = param_3;
  xz_container_decode(param_1,param_2,0,&uStack_24,&iStack_20,_DAT_10003c34,0);
  if (iStack_20 != 0) {
    xz_container_decode(param_1,param_2,2,&iStack_1c,0,_DAT_10003c38,1);
  }
  if ((uStack_24 != 0) && (iStack_28 == -1)) {
    if ((uStack_24 < 2) && (*(char *)(param_1 + 0x28) == '\0')) {
      *(char *)(param_1 + 0x28) = '\x01';
    }
    else {
      xz_container_decode(param_1,param_2,1,&iStack_1c,0,_DAT_10003c38,1);
    }
  }
  return iStack_28;
}

// FUNC 0x10003c3c  xz_container_dispatch

undefined4 xz_container_dispatch(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_5c;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [20];
  undefined1 auStack_38 [36];
  
  if (*param_2 == '\x02') {
    FUN_10003a48(param_1,0,param_2);
  }
  iVar1 = FUN_10003bac(param_1,auStack_4c,0x94);
  uStack_5c = 7;
  if (iVar1 != -1) {
    if ((*(char *)(param_1 + 0x29) == '\0') ||
       (iVar2 = FUN_10003a1c(param_1,*(undefined2 *)(param_2 + 0xc),auStack_38), iVar2 == 0)) {
      iVar2 = *(int *)(param_2 + 8);
      FUN_10003af4(param_1,auStack_4c,0);
      xz_stream_done(param_1,iVar1,auStack_50,6,1,0);
      uVar3 = iVar2 + 0x10;
      uStack_5c = 0;
      for (uVar4 = 0; uVar4 < uVar3; uVar4 = uVar4 + iVar2) {
        iVar2 = 0x20;
        if (uVar3 <= uVar4 + 0x20) {
          iVar2 = uVar3 - uVar4;
        }
        xz_hdr_validate(param_1,*(int *)(param_2 + 0x10) + 4 + uVar4,auStack_38,iVar2);
        uStack_5c = xz_block_len_update(param_1,iVar1 + 4 + uVar4,auStack_38,iVar2,1);
      }
      xz_stream_done(param_1,iVar1,auStack_50,6,2,1);
    }
    else {
      uStack_5c = 0;
    }
    FUN_10003a48(param_1,0,param_2,1);
  }
  return uStack_5c;
}

// FUNC 0x10003dc8  xz_block_decode_done

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Finalizes an XZ block after decoding */

void xz_block_decode_done(int param_1)

{
  uint uStack_28;
  undefined1 auStack_24 [24];
  
  uStack_28 = 0;
  xz_container_decode(param_1,auStack_24,1,&uStack_28,0,_DAT_10003e08,0);
  if (uStack_28 < 2) {
    xz_container_decode(param_1,auStack_24,0,param_1,0,_DAT_10003e0c,0);
  }
  *(undefined1 *)(param_1 + 0x28) = 0;
  return;
}

// FUNC 0x10003e10  xz_stream_decode_done

/* Finalizes an XZ stream after all blocks */

void xz_stream_decode_done(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_10003bac();
  if (iVar1 == -1) {
    if (*(char *)(param_1 + 0x28) != '\0') {
      xz_block_decode_done(param_1);
      iVar1 = FUN_10003bac(param_1,param_2,param_3);
      if (iVar1 == -1) {
        *(char *)(param_1 + 0x28) = '\0';
      }
    }
  }
  return;
}

// FUNC 0x10003e66  xz_decode_finish

/* Checks completion and returns the result code */

uint xz_decode_finish(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_30 [8];
  uint uStack_28;
  undefined4 uStack_1c;
  
  uVar2 = (uint)*(byte *)(param_1 + 0x10);
  if (uVar2 != 0) {
    if (*(code **)(param_1 + 0x14) != (code *)0x0) {
      (**(code **)(param_1 + 0x14))();
    }
    iVar3 = *param_3;
    uVar2 = param_3[1];
    iVar1 = FUN_10003a1c(param_1,param_2,auStack_30);
    if (iVar1 == 0) {
      param_3[4] = 0;
      uVar2 = 0;
    }
    else {
      param_3[4] = uStack_28;
      if (uStack_28 < uVar2) {
        uVar2 = uStack_28;
      }
      if (iVar3 != 0) {
        xz_hdr_validate(param_1,uStack_1c,iVar3,uVar2);
      }
    }
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return uVar2;
}

// FUNC 0x10003ec0  kv_erase_entry

/* Erases one KV entry */

undefined4 kv_erase_entry(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 8;
  if (*(char *)(param_1 + 0x10) != '\0') {
    if (*(code **)(param_1 + 0x14) != (code *)0x0) {
      (**(code **)(param_1 + 0x14))();
    }
    uVar1 = FUN_10003a48(param_1,param_2,0,1);
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return uVar1;
}

// FUNC 0x10003ef4  FUN_10003ef4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_10003ef4(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char cStack_2d;
  undefined1 auStack_2c [4];
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  undefined2 uStack_1c;
  
  iVar6 = 8;
  if (*(char *)(param_1 + 0x10) != '\0') {
    if (*(code **)(param_1 + 0x14) != (code *)0x0) {
      (**(code **)(param_1 + 0x14))();
    }
    iVar2 = *param_3;
    if (iVar2 == 0) {
      iVar6 = FUN_10003a48(param_1,param_2,0,1);
    }
    else {
      uVar3 = param_3[1];
      iVar4 = param_1 + 0x44;
      iVar1 = xz_stream_decode_done(param_1,iVar4,uVar3 + 0x14);
      iVar6 = 7;
      if (iVar1 != -1) {
        iVar5 = param_1 + 0x2c;
        iVar1 = FUN_10003a1c(param_1,param_2,iVar5);
        if ((iVar1 == 0) || (iVar6 = FUN_10003a48(param_1,param_2,iVar5,0), iVar6 == 0)) {
          cStack_2d = '\0';
          iVar7 = *(int *)(param_1 + 0x54);
          memset(auStack_2c,0xff,0x14);
          uStack_28 = _DAT_10004074;
          uStack_1c = (undefined2)param_2;
          uStack_20 = uVar3;
          if (((*(int *)(param_1 + 8) - 8U < uVar3) || (0x80 < uVar3)) ||
             ((iVar7 == -1 && (iVar7 = xz_stream_decode_done(param_1,iVar4,0x94), iVar7 == -1)))) {
            iVar6 = 7;
          }
          else {
            iVar6 = FUN_10003af4(param_1,iVar4,&cStack_2d);
            if (iVar6 == 0) {
              uStack_24 = xz_crc32_ccitt_update(0,&uStack_20,8);
              uStack_24 = xz_crc32_ccitt_update(uStack_24,iVar2,uStack_20);
              iVar6 = xz_stream_done(param_1,iVar7,auStack_2c,6,1,0);
              if (iVar6 == 0) {
                iVar6 = xz_block_len_update(param_1,iVar7 + 4,&uStack_28,0x10,0);
                if (iVar6 == 0) {
                  iVar6 = xz_block_len_update(param_1,iVar7 + 0x14,iVar2,uStack_20,0);
                  if (iVar6 == 0) {
                    iVar6 = xz_stream_done(param_1,iVar7,auStack_2c,6,2,1);
                    if (iVar6 == 0) {
                      if (cStack_2d != '\0') {
                        *(undefined1 *)(param_1 + 0x28) = 1;
                      }
                      if (iVar1 != 0) {
                        iVar6 = FUN_10003a48(param_1,param_2,iVar5,1);
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if (*(char *)(param_1 + 0x28) != '\0') {
          xz_block_decode_done(param_1);
        }
      }
    }
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  return iVar6;
}

// FUNC 0x10004078  kv_scan_entries

/* Scans all KV sectors for valid entries */

int kv_scan_entries(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(code **)(param_1 + 0x14) != (code *)0x0) {
    (**(code **)(param_1 + 0x14))();
  }
  for (uVar2 = 0; uVar2 < *(uint *)(param_1 + 0xc); uVar2 = uVar2 + *(int *)(param_1 + 8)) {
    iVar1 = FUN_100037b0(param_1,uVar2);
    if (iVar1 != 0) goto LAB_1000408e;
  }
  iVar1 = 0;
LAB_1000408e:
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  return iVar1;
}

// FUNC 0x100040b0  kv_recover

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Rebuilds the KV index from the sector contents */

undefined4 kv_recover(int param_1)

{
  int iVar1;
  int iStack_40;
  undefined1 auStack_3c [20];
  undefined1 auStack_28 [28];
  
  *(undefined1 *)(param_1 + 0x29) = 1;
  iStack_40 = 0;
  xz_container_decode(param_1,auStack_3c,0,&iStack_40,param_1,_DAT_10004138,0);
  iVar1 = aeabi_uidivmod(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
  if (iVar1 == iStack_40) {
    kv_scan_entries(param_1);
  }
  if (*(code **)(param_1 + 0x14) != (code *)0x0) {
    (**(code **)(param_1 + 0x14))(param_1);
  }
  xz_container_decode(param_1,auStack_3c,0,param_1,0,_DAT_1000413c,0);
  while( true ) {
    xz_block_decode_loop(param_1,auStack_28,param_1,0,_DAT_10004140);
    if (*(char *)(param_1 + 0x28) == '\0') break;
    xz_block_decode_done(param_1);
  }
  *(undefined1 *)(param_1 + 0x29) = 0;
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  return 0;
}

// FUNC 0x10004144  kv_set_callback

/* Stores or returns the read, write and erase callbacks */

void kv_set_callback(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 < 4) {
    uVar1 = FUN_100007c8(param_2);
    if (*(char *)(param_1 + 0x10) != '\0') {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(uVar1 >> 4);
  }
  return;
}

// FUNC 0x10004178  kv_mount

/* Mounts the KV store, recovering it when needed */

int kv_mount(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = xz_header_parse();
  if (iVar1 == 0) {
    *(undefined2 *)(param_1 + 0x28) = 0;
    uVar2 = aeabi_uidivmod(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
    if (uVar2 < 2) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar1 = kv_recover(param_1);
  }
  kv_mark_ready(param_1,iVar1);
  return iVar1;
}

// FUNC 0x1000421e  xz_hdr_validate

/* Validates an XZ header CRC */

undefined4 xz_hdr_validate(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x1c))(param_1);
  }
  return uVar1;
}

// FUNC 0x10004230  xz_hdr_crc_update

/* Updates the header CRC over parsed bytes */

undefined4 xz_hdr_crc_update(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x24))(param_1);
  }
  return uVar1;
}

// FUNC 0x10004242  xz_block_len_update

/* Updates the block length CRC */

undefined4 xz_block_len_update(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 3;
  if (*(code **)(param_1 + 0x20) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x20))(param_1);
  }
  return uVar1;
}

// FUNC 0x10004254  xz_header_parse

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Parses the XZ stream header: magic, blocks, streams */

undefined4 xz_header_parse(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = _DAT_100042b4;
  if (param_1 == (int *)0x0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((char)param_1[4] == '\0') {
    *param_1 = param_2;
    param_1[7] = iVar1;
    param_1[8] = _DAT_100042b8;
    param_1[9] = _DAT_100042bc;
    iVar1 = flash_region_find(param_3);
    *(char *)(param_1 + 1) = (char)iVar1;
    if (iVar1 == -1) {
      return 4;
    }
    param_1[2] = 0x1000;
    iVar1 = flash_region_get();
    iVar1 = *(int *)(iVar1 + 0xc);
    param_1[3] = iVar1;
    uVar2 = aeabi_uidiv(iVar1,param_1[2]);
    if ((int)((ulonglong)uVar2 >> 0x20) != 0) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if ((uint)uVar2 < 2) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  return 0;
}

// FUNC 0x100042c0  xz_crc32_ccitt_update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CCITT CRC-32 update over decoded bytes */

uint xz_crc32_ccitt_update(uint param_1,byte *param_2,int param_3)

{
  uint uVar1;
  byte *pbVar2;
  char cVar3;
  
  param_1 = ~param_1;
  pbVar2 = param_2 + param_3;
  for (; param_2 != pbVar2; param_2 = param_2 + 1) {
    cVar3 = '\b';
    uVar1 = param_1 ^ (uint)*param_2 << 0x18;
    do {
      param_1 = uVar1 << 1;
      if ((int)uVar1 < 0) {
        param_1 = param_1 ^ _DAT_100042f0;
      }
      cVar3 = cVar3 + -1;
      uVar1 = param_1;
    } while (cVar3 != '\0');
  }
  return ~param_1;
}

// FUNC 0x100042f4  xz_crc32_ccitt_init

/* Initializes the CCITT CRC-32 context */

uint xz_crc32_ccitt_init(undefined1 *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  *param_1 = 0xff;
  if (param_3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = param_3 - 1 >> 3;
    param_1[uVar1] = (byte)(0xff >> (param_3 & 7)) & param_1[uVar1];
  }
  return uVar1;
}

// FUNC 0x10004318  xz_block_data_done

/* Marks an XZ data block as complete */

int xz_block_data_done(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 - 2U;
  do {
    uVar2 = uVar1;
    if (uVar2 == 0xffffffff) break;
    uVar1 = uVar2 - 1;
  } while ((0x80 >> (uVar2 & 7) & (uint)*(byte *)(param_1 + (uVar2 >> 3))) != 0);
  return (uVar2 - (param_2 - 2U)) + param_2 + -1;
}

// FUNC 0x10004346  xz_stream_done

/* Marks the final XZ stream as complete */

undefined8
xz_stream_done(uint param_1,int param_2,int param_3,uint param_4,uint param_5,byte param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = (uint)param_6;
  if (param_4 <= param_5) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar4 = param_1;
  iVar5 = param_2;
  iVar6 = param_3;
  iVar1 = xz_crc32_ccitt_init(param_3);
  uVar2 = 0;
  if (iVar1 != -1) {
    uVar2 = xz_block_len_update(param_1,iVar1 + param_2,param_3 + iVar1,1,uVar3,iVar5,iVar6);
    uVar4 = uVar3;
  }
  return CONCAT44(uVar4,uVar2);
}

// FUNC 0x10004380  FUN_10004380

void FUN_10004380(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  xz_hdr_validate();
  xz_block_data_done(param_3,param_4);
  return;
}

// FUNC 0x1000439c  FUN_1000439c

void FUN_1000439c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}

// FUNC 0x100043a4  kv_mark_ready

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Marks the KV store as initialized */

void kv_mark_ready(int param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = _DAT_100043b8;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x10) = 1;
    if (*pcVar1 == '\0') {
      *pcVar1 = '\x01';
    }
  }
  return;
}

// FUNC 0x100043bc  FUN_100043bc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100043bc(undefined4 param_1)

{
  FUN_100043e4(*_DAT_100043cc,param_1);
  return;
}

// FUNC 0x100043d0  FUN_100043d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100043d0(undefined4 param_1)

{
  FUN_10004c90(*_DAT_100043e0,param_1);
  return;
}

// FUNC 0x100043e4  FUN_100043e4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_100043e4(undefined4 *param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  uint uStack_30;
  
  uVar14 = param_2 + 0xb;
  if (uVar14 < 0x17) {
    if (0x10 < param_2) {
LAB_10004568:
      *param_1 = 0xc;
      return (int *)0x0;
    }
    FUN_10004bb0();
    uVar15 = 0x10;
    uVar14 = 2;
    iVar10 = 0x18;
LAB_1000440c:
    iVar10 = _DAT_1000473c + iVar10;
    iVar12 = *(int *)(iVar10 + 4);
    if (iVar12 == iVar10 + -8) {
      iVar12 = *(int *)(iVar10 + 0xc);
      uVar14 = uVar14 + 2;
      if (iVar10 == iVar12) {
        iVar12 = *(int *)(_DAT_1000473c + 0x10);
        iVar10 = _DAT_1000473c + 8;
        if (iVar12 == iVar10) goto LAB_1000459e;
LAB_100044ac:
        uVar3 = _DAT_1000473c;
        uVar4 = *(uint *)(iVar12 + 4);
        uVar6 = uVar4 & 0xfffffffc;
        uVar5 = uVar6 - uVar15;
        if (0xf < (int)uVar5) {
          iVar7 = iVar12 + uVar15;
          *(uint *)(iVar12 + 4) = uVar15 | 1;
          *(int *)(uVar3 + 0x14) = iVar7;
          *(int *)(uVar3 + 0x10) = iVar7;
          *(int *)(iVar7 + 0xc) = iVar10;
          *(int *)(iVar7 + 8) = iVar10;
          *(uint *)(iVar7 + 4) = uVar5 | 1;
          *(uint *)(iVar12 + uVar6) = uVar5;
          FUN_10004bc0(param_1);
          return (int *)(iVar12 + 8);
        }
        *(int *)(_DAT_1000473c + 0x14) = iVar10;
        *(int *)(uVar3 + 0x10) = iVar10;
        if (-1 < (int)uVar5) goto LAB_1000442c;
        if (uVar6 < 0x200) {
          iVar7 = (uVar4 & 0xfffffff8) + uVar3;
          uVar4 = 1 << (uVar4 >> 5 & 0xff) | *(uint *)(uVar3 + 4);
          iVar10 = *(int *)(iVar7 + 8);
          *(uint *)(uVar3 + 4) = uVar4;
          *(int *)(iVar12 + 0xc) = iVar7;
          *(int *)(iVar12 + 8) = iVar10;
          *(int *)(iVar7 + 8) = iVar12;
          *(int *)(iVar10 + 0xc) = iVar12;
        }
        else {
          uVar5 = uVar4 >> 9;
          if (uVar5 < 5) {
            iVar10 = (uVar4 >> 6) + 0x38;
            iVar7 = ((uVar4 >> 6) + 0x39) * 8;
          }
          else if (uVar5 < 0x15) {
            iVar10 = uVar5 + 0x5b;
            iVar7 = (uVar5 + 0x5c) * 8;
          }
          else if (uVar5 < 0x55) {
            iVar10 = (uVar4 >> 0xc) + 0x6e;
            iVar7 = ((uVar4 >> 0xc) + 0x6f) * 8;
          }
          else if (uVar5 < 0x155) {
            iVar10 = (uVar4 >> 0xf) + 0x77;
            iVar7 = ((uVar4 >> 0xf) + 0x78) * 8;
          }
          else if (_DAT_10004960 < uVar5) {
            iVar10 = 0x7e;
            iVar7 = 0x3f8;
          }
          else {
            iVar10 = (uVar4 >> 0x12) + 0x7c;
            iVar7 = ((uVar4 >> 0x12) + 0x7d) * 8;
          }
          piVar11 = (int *)(uVar3 + iVar7) + -2;
          piVar8 = *(int **)(uVar3 + iVar7);
          if (piVar11 == piVar8) {
            uVar4 = 1 << (iVar10 >> 2 & 0xffU) | *(uint *)(uVar3 + 4);
            *(uint *)(uVar3 + 4) = uVar4;
          }
          else {
            do {
              if ((piVar8[1] & 0xfffffffcU) <= uVar6) break;
              piVar8 = (int *)piVar8[2];
            } while (piVar11 != piVar8);
            piVar11 = (int *)piVar8[3];
            uVar4 = *(uint *)(uVar3 + 4);
          }
          *(int **)(iVar12 + 8) = piVar8;
          *(int **)(iVar12 + 0xc) = piVar11;
          piVar11[2] = iVar12;
          piVar8[3] = iVar12;
        }
        uVar6 = 1 << ((int)uVar14 >> 2 & 0xffU);
        if (uVar6 <= uVar4) goto LAB_100044f6;
        goto LAB_100045aa;
      }
    }
    uVar6 = *(uint *)(iVar12 + 4) & 0xfffffffc;
LAB_10004424:
    iVar7 = *(int *)(iVar12 + 0xc);
    iVar10 = *(int *)(iVar12 + 8);
    *(int *)(iVar10 + 0xc) = iVar7;
    *(int *)(iVar7 + 8) = iVar10;
LAB_1000442c:
    *(uint *)(iVar12 + uVar6 + 4) = *(uint *)(iVar12 + uVar6 + 4) | 1;
    FUN_10004bc0(param_1);
    return (int *)(iVar12 + 8);
  }
  uVar15 = uVar14 & 0xfffffff8;
  if (((int)uVar15 < 0) || (uVar15 < param_2)) goto LAB_10004568;
  FUN_10004bb0();
  if (uVar15 < 0x1f8) {
    uVar14 = uVar14 >> 3;
    iVar10 = uVar15 + 8;
    goto LAB_1000440c;
  }
  uVar3 = uVar14 >> 9;
  if (uVar3 == 0) {
    uVar4 = 0x3f;
    uVar3 = 0x40;
    iVar10 = 0x200;
  }
  else if (uVar3 < 5) {
    uVar4 = (uVar14 >> 6) + 0x38;
    uVar3 = (uVar14 >> 6) + 0x39;
    iVar10 = uVar3 * 8;
  }
  else if (uVar3 < 0x15) {
    uVar4 = uVar3 + 0x5b;
    uVar3 = uVar3 + 0x5c;
    iVar10 = uVar3 * 8;
  }
  else if (uVar3 < 0x55) {
    uVar4 = (uVar14 >> 0xc) + 0x6e;
    uVar3 = (uVar14 >> 0xc) + 0x6f;
    iVar10 = uVar3 * 8;
  }
  else if (uVar3 < 0x155) {
    uVar4 = (uVar14 >> 0xf) + 0x77;
    uVar3 = (uVar14 >> 0xf) + 0x78;
    iVar10 = uVar3 * 8;
  }
  else if (_DAT_10004960 < uVar3) {
    uVar3 = 0x7f;
    uVar4 = 0x7e;
    iVar10 = 0x3f8;
  }
  else {
    uVar4 = (uVar14 >> 0x12) + 0x7c;
    uVar3 = (uVar14 >> 0x12) + 0x7d;
    iVar10 = uVar3 * 8;
  }
  for (iVar12 = *(int *)(_DAT_1000473c + iVar10 + 4); uVar14 = uVar3,
      _DAT_1000473c + iVar10 + -8 != iVar12; iVar12 = *(int *)(iVar12 + 0xc)) {
    uVar6 = *(uint *)(iVar12 + 4) & 0xfffffffc;
    uVar14 = uVar4;
    if (0xf < (int)(uVar6 - uVar15)) break;
    if (-1 < (int)(uVar6 - uVar15)) goto LAB_10004424;
  }
  iVar12 = *(int *)(_DAT_1000473c + 0x10);
  iVar10 = _DAT_1000473c + 8;
  if (iVar12 != iVar10) goto LAB_100044ac;
LAB_1000459e:
  uVar4 = *(uint *)(_DAT_1000473c + 4);
  uVar6 = 1 << ((int)uVar14 >> 2 & 0xffU);
  uVar3 = _DAT_1000473c;
  if (uVar6 <= uVar4) {
LAB_100044f6:
    if ((uVar4 & uVar6) == 0) {
      uVar14 = uVar14 & 0xfffffffc;
      do {
        uVar6 = uVar6 << 1;
        uVar14 = uVar14 + 4;
      } while ((uVar4 & uVar6) == 0);
    }
    do {
      piVar8 = (int *)(uVar14 * 8 + uVar3);
      uVar4 = uVar14;
      piVar11 = piVar8;
      do {
        for (piVar13 = (int *)piVar11[3]; piVar11 != piVar13; piVar13 = (int *)piVar13[3]) {
          uVar9 = piVar13[1] & 0xfffffffc;
          uVar5 = uVar9 - uVar15;
          if (0xf < (int)uVar5) {
            iVar12 = (int)piVar13 + uVar15;
            piVar13[1] = uVar15 | 1;
            iVar10 = piVar13[2];
            iVar7 = piVar13[3];
            *(int *)(iVar10 + 0xc) = iVar7;
            *(int *)(iVar7 + 8) = iVar10;
            *(int *)(uVar3 + 0x14) = iVar12;
            *(int *)(uVar3 + 0x10) = iVar12;
            *(uint *)(iVar12 + 4) = uVar5 | 1;
            *(uint *)(iVar12 + 0xc) = uVar3 + 8;
            *(uint *)(iVar12 + 8) = uVar3 + 8;
            *(uint *)((int)piVar13 + uVar9) = uVar5;
            FUN_10004bc0(param_1);
            return piVar13 + 2;
          }
          if (-1 < (int)uVar5) {
            *(uint *)((int)piVar13 + uVar9 + 4) = *(uint *)((int)piVar13 + uVar9 + 4) | 1;
            iVar12 = piVar13[3];
            iVar10 = piVar13[2];
            *(int *)(iVar10 + 0xc) = iVar12;
            *(int *)(iVar12 + 8) = iVar10;
            FUN_10004bc0(param_1);
            return piVar13 + 2;
          }
        }
        piVar11 = piVar11 + 2;
        uVar4 = uVar4 + 1;
      } while ((uVar4 & 3) != 0);
      do {
        if ((uVar14 & 3) == 0) {
          uVar5 = *(uint *)(uVar3 + 4) & ~uVar6;
          *(uint *)(uVar3 + 4) = uVar5;
          goto LAB_10004832;
        }
        piVar13 = piVar8 + -2;
        piVar11 = (int *)*piVar8;
        uVar14 = uVar14 - 1;
        piVar8 = piVar13;
      } while (piVar11 == piVar13);
      uVar5 = *(uint *)(uVar3 + 4);
LAB_10004832:
      uVar6 = uVar6 * 2;
      if ((uVar5 <= uVar6 && uVar6 - uVar5 != 0) || (uVar14 = uVar4, uVar6 == 0)) break;
      for (; (uVar5 & uVar6) == 0; uVar6 = uVar6 << 1) {
        uVar14 = uVar14 + 4;
      }
    } while( true );
  }
LAB_100045aa:
  puVar1 = _DAT_10004740;
  uVar14 = *(uint *)(uVar3 + 8);
  uVar4 = *(uint *)(uVar14 + 4) & 0xfffffffc;
  if ((uVar15 <= uVar4) && (uVar6 = uVar4 - uVar15, 0xf < (int)uVar6)) goto LAB_100046d2;
  uVar6 = uVar14 + uVar4;
  if (*_DAT_10004740 == 0xffffffff) {
    uStack_30 = uVar15 + *_DAT_10004744 + 0x10;
  }
  else {
    uStack_30 = uVar15 + *_DAT_10004744 + _DAT_10004748 & 0xfffff000;
  }
  uVar5 = FUN_10004bd0(param_1,uStack_30);
  puVar2 = _DAT_1000495c;
  puVar16 = _DAT_1000474c;
  if (uVar5 == 0xffffffff) {
LAB_100047e8:
    uVar5 = *(uint *)(uVar3 + 8);
    uStack_30 = *(uint *)(uVar5 + 4);
  }
  else {
    if (uVar5 < uVar6) {
      if (uVar14 == uVar3) {
        uVar9 = uStack_30 + *_DAT_1000495c;
        *_DAT_1000495c = uVar9;
        puVar16 = puVar2;
        goto LAB_1000461a;
      }
      goto LAB_100047e8;
    }
    uVar9 = uStack_30 + *_DAT_1000474c;
    *_DAT_1000474c = uVar9;
    if ((uVar6 == uVar5) && ((uVar6 & 0xfff) == 0)) {
      uVar5 = *(uint *)(uVar3 + 8);
      uStack_30 = uStack_30 + uVar4 | 1;
      *(uint *)(uVar5 + 4) = uStack_30;
    }
    else {
LAB_1000461a:
      if (*puVar1 == 0xffffffff) {
        *puVar1 = uVar5;
      }
      else {
        *puVar16 = (uVar5 - uVar6) + uVar9;
      }
      uVar6 = uVar5 & 7;
      if ((uVar5 & 7) == 0) {
        uVar9 = -(uStack_30 + uVar5) & 0xfff;
        iVar10 = FUN_10004bd0(param_1,uVar9);
        if (iVar10 == -1) {
          uVar9 = 0;
        }
        else {
LAB_10004668:
          uStack_30 = (iVar10 - uVar5) + uVar9;
        }
      }
      else {
        uVar5 = (uVar5 - uVar6) + 8;
        uVar9 = (_DAT_10004750 - uVar6) - (uStack_30 + uVar5) & 0xfff;
        iVar10 = FUN_10004bd0(param_1,uVar9);
        if (iVar10 != -1) goto LAB_10004668;
        uStack_30 = ((uVar6 - 8) + uStack_30 + uVar5) - uVar5;
        uVar9 = 0;
      }
      uVar9 = *puVar16 + uVar9;
      *puVar16 = uVar9;
      *(uint *)(uVar3 + 8) = uVar5;
      uStack_30 = uStack_30 | 1;
      *(uint *)(uVar5 + 4) = uStack_30;
      if (uVar14 != uVar3) {
        if (uVar4 < 0x10) {
          *(undefined4 *)(uVar5 + 4) = 1;
          goto LAB_100047fc;
        }
        uVar4 = uVar4 - 0xc & 0xfffffff8;
        *(uint *)(uVar14 + 4) = *(uint *)(uVar14 + 4) & 1 | uVar4;
        *(undefined4 *)(uVar14 + uVar4 + 4) = 5;
        *(undefined4 *)(uVar14 + uVar4 + 8) = 5;
        if (uVar4 < 0x10) {
          uStack_30 = *(uint *)(uVar5 + 4);
        }
        else {
          FUN_10004c90(param_1,uVar14 + 8);
          uVar5 = *(uint *)(uVar3 + 8);
          uVar9 = *puVar16;
          uStack_30 = *(uint *)(uVar5 + 4);
        }
      }
    }
    if (*_DAT_10004754 < uVar9) {
      *_DAT_10004754 = uVar9;
    }
    if (*_DAT_10004758 < uVar9) {
      *_DAT_10004758 = uVar9;
    }
  }
  uVar6 = (uStack_30 & 0xfffffffc) - uVar15;
  if ((uVar15 <= (uStack_30 & 0xfffffffc)) && (uVar14 = uVar5, 0xf < (int)uVar6)) {
LAB_100046d2:
    *(uint *)(uVar14 + 4) = uVar15 | 1;
    *(uint *)(uVar3 + 8) = uVar14 + uVar15;
    *(uint *)(uVar14 + uVar15 + 4) = uVar6 | 1;
    FUN_10004bc0(param_1);
    return (int *)(uVar14 + 8);
  }
LAB_100047fc:
  FUN_10004bc0(param_1);
  return (int *)0x0;
}

// FUNC 0x10004964  memcmp

/* Byte compare */

int memcmp(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  bool bVar2;
  
  if (3 < param_3) {
    if ((((uint)param_1 | (uint)param_2) & 3) != 0) goto LAB_1000498a;
    do {
      if (*param_1 != *param_2) goto LAB_1000498a;
      param_3 = param_3 - 4;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (3 < param_3);
  }
  if (param_3 == 0) {
    return 0;
  }
LAB_1000498a:
  iVar1 = 0;
  do {
    if ((uint)*(byte *)((int)param_1 + iVar1) != (uint)*(byte *)((int)param_2 + iVar1)) {
      return (uint)*(byte *)((int)param_1 + iVar1) - (uint)*(byte *)((int)param_2 + iVar1);
    }
    bVar2 = param_3 - 1 != iVar1;
    iVar1 = iVar1 + 1;
  } while (bVar2);
  return 0;
}

// FUNC 0x100049ac  memcpy

/* Forward copy */

void memcpy(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  bool bVar8;
  
  uVar4 = param_3;
  if (0xf < param_3) {
    uVar6 = ((uint)param_2 | (uint)param_1) & 3;
    if ((((uint)param_2 | (uint)param_1) & 3) != 0) {
      iVar5 = param_3 - 1;
      goto LAB_10004a26;
    }
    uVar4 = param_3 - 0x10 >> 4;
    puVar1 = param_1;
    puVar3 = param_2;
    do {
      uVar7 = puVar3[1];
      *puVar1 = *puVar3;
      puVar1[1] = uVar7;
      uVar7 = puVar3[3];
      puVar1[2] = puVar3[2];
      puVar1[3] = uVar7;
      puVar3 = puVar3 + 4;
      bVar8 = puVar1 != param_1 + uVar4 * 4;
      puVar1 = puVar1 + 4;
    } while (bVar8);
    iVar5 = uVar4 + 1;
    param_2 = param_2 + iVar5 * 4;
    uVar4 = param_3 & 0xf;
    param_1 = param_1 + iVar5 * 4;
    if ((param_3 & 0xc) != 0) {
      do {
        *(undefined4 *)((int)param_1 + uVar6) = *(undefined4 *)((int)param_2 + uVar6);
        uVar6 = uVar6 + 4;
      } while (3 < uVar4 - uVar6);
      iVar5 = (uVar4 - 4 >> 2) + 1;
      param_1 = param_1 + iVar5;
      param_2 = param_2 + iVar5;
      uVar4 = param_3 & 3;
    }
  }
  iVar5 = uVar4 - 1;
  if (uVar4 == 0) {
    return;
  }
LAB_10004a26:
  iVar2 = 0;
  do {
    *(undefined1 *)((int)param_1 + iVar2) = *(undefined1 *)((int)param_2 + iVar2);
    bVar8 = iVar5 != iVar2;
    iVar2 = iVar2 + 1;
  } while (bVar8);
  return;
}

// FUNC 0x10004a50  memmove

/* Overlapping copy */

void memmove(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)((int)param_2 + param_3))) {
    iVar2 = param_3 - 1;
    if (param_3 == 0) {
      return;
    }
    do {
      *(undefined1 *)((int)param_1 + iVar2) = *(undefined1 *)((int)param_2 + iVar2);
      bVar8 = iVar2 != 0;
      iVar2 = iVar2 + -1;
    } while (bVar8);
    return;
  }
  uVar6 = param_3;
  if (0xf < param_3) {
    uVar7 = ((uint)param_2 | (uint)param_1) & 3;
    if ((((uint)param_2 | (uint)param_1) & 3) != 0) {
      iVar2 = param_3 - 1;
      goto LAB_10004a80;
    }
    uVar6 = param_3 - 0x10 >> 4;
    puVar4 = param_1;
    puVar5 = param_2;
    do {
      *puVar4 = *puVar5;
      puVar4[1] = puVar5[1];
      puVar4[2] = puVar5[2];
      puVar1 = puVar5 + 3;
      puVar5 = puVar5 + 4;
      puVar4[3] = *puVar1;
      bVar8 = puVar4 != param_1 + uVar6 * 4;
      puVar4 = puVar4 + 4;
    } while (bVar8);
    iVar2 = uVar6 + 1;
    param_2 = param_2 + iVar2 * 4;
    uVar6 = param_3 & 0xf;
    param_1 = param_1 + iVar2 * 4;
    if ((param_3 & 0xc) != 0) {
      do {
        *(undefined4 *)((int)param_1 + uVar7) = *(undefined4 *)((int)param_2 + uVar7);
        uVar7 = uVar7 + 4;
      } while (3 < uVar6 - uVar7);
      iVar2 = (uVar6 - 4 >> 2) + 1;
      param_1 = param_1 + iVar2;
      param_2 = param_2 + iVar2;
      uVar6 = param_3 & 3;
    }
  }
  iVar2 = uVar6 - 1;
  if (uVar6 == 0) {
    return;
  }
LAB_10004a80:
  iVar3 = 0;
  do {
    *(undefined1 *)((int)param_1 + iVar3) = *(undefined1 *)((int)param_2 + iVar3);
    bVar8 = iVar2 != iVar3;
    iVar3 = iVar3 + 1;
  } while (bVar8);
  return;
}

// FUNC 0x10004b08  memset

/* Byte fill */

void memset(undefined4 *param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  
  if (((uint)param_1 & 3) != 0) {
    uVar1 = param_3 - 1;
    puVar2 = param_1;
    if (param_3 == 0) {
      return;
    }
    while( true ) {
      param_1 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)puVar2 = param_2;
      param_3 = uVar1;
      if (((uint)param_1 & 3) == 0) break;
      bVar5 = uVar1 == 0;
      uVar1 = uVar1 - 1;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      if (bVar5) {
        return;
      }
    }
  }
  uVar1 = param_3;
  if (3 < param_3) {
    uVar3 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    if (0xf < param_3) {
      uVar4 = param_3 - 0x10 >> 4;
      puVar2 = param_1;
      do {
        *puVar2 = uVar3;
        puVar2[1] = uVar3;
        puVar2[2] = uVar3;
        puVar2[3] = uVar3;
        puVar2 = puVar2 + 4;
      } while (puVar2 != param_1 + uVar4 * 4 + 4);
      uVar1 = param_3 & 0xf;
      param_1 = param_1 + (uVar4 + 1) * 4;
      uVar4 = param_3 & 0xc;
      param_3 = uVar1;
      if (uVar4 == 0) goto LAB_10004b90;
    }
    uVar1 = param_3 - 4 >> 2;
    puVar2 = param_1;
    do {
      *puVar2 = uVar3;
      puVar2 = puVar2 + 1;
    } while (puVar2 != param_1 + uVar1 + 1);
    param_1 = param_1 + uVar1 + 1;
    uVar1 = param_3 & 3;
  }
LAB_10004b90:
  if (uVar1 != 0) {
    puVar2 = (undefined4 *)((int)param_1 + uVar1);
    do {
      *(undefined1 *)param_1 = param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
    } while (puVar2 != param_1);
  }
  return;
}

// FUNC 0x10004bb0  FUN_10004bb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004bb0(void)

{
  null_callback_1(_DAT_10004bbc);
  return;
}

// FUNC 0x10004bc0  FUN_10004bc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004bc0(void)

{
  null_callback_2(_DAT_10004bcc);
  return;
}

// FUNC 0x10004bd0  FUN_10004bd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004bd0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = _DAT_10004bf0;
  *_DAT_10004bf0 = 0;
  iVar2 = heap_alloc(param_2);
  if ((iVar2 == -1) && (*piVar1 != 0)) {
    *param_1 = *piVar1;
  }
  return;
}

// FUNC 0x10004bf4  FUN_10004bf4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10004bf4(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  FUN_10004bb0();
  iVar2 = _DAT_10004c80;
  uVar4 = *(uint *)(*(int *)(_DAT_10004c80 + 8) + 4) & 0xfffffffc;
  iVar3 = ((uVar4 - param_2) + _DAT_10004c84 >> 0xc) - 1;
  if ((_DAT_10004c84 + 0x11 <= iVar3 * 0x1000) &&
     (iVar1 = FUN_10004bd0(param_1,0), iVar1 == *(int *)(iVar2 + 8) + uVar4)) {
    iVar1 = FUN_10004bd0(param_1,iVar3 * -0x1000);
    if (iVar1 != -1) {
      *(uint *)(*(int *)(iVar2 + 8) + 4) = uVar4 + iVar3 * -0x1000 | 1;
      *_DAT_10004c88 = *_DAT_10004c88 + iVar3 * -0x1000;
      FUN_10004bc0(param_1);
      return 1;
    }
    iVar3 = FUN_10004bd0(param_1,0);
    iVar2 = *(int *)(iVar2 + 8);
    uVar4 = iVar3 - iVar2;
    if (0xf < (int)uVar4) {
      *_DAT_10004c88 = iVar3 - *_DAT_10004c8c;
      *(uint *)(iVar2 + 4) = uVar4 | 1;
    }
  }
  FUN_10004bc0(param_1);
  return 0;
}

// FUNC 0x10004c90  FUN_10004c90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004c90(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  
  if (param_2 == 0) {
    return;
  }
  FUN_10004bb0();
  iVar1 = _DAT_10004e40;
  piVar2 = (int *)(param_2 + -8);
  uVar8 = *(uint *)(param_2 + -4);
  uVar3 = uVar8 & 0xfffffffe;
  puVar11 = (uint *)((int)piVar2 + uVar3);
  uVar5 = puVar11[1] & 0xfffffffc;
  if (*(uint **)(_DAT_10004e40 + 8) == puVar11) {
    uVar3 = uVar3 + uVar5;
    if ((uVar8 & 1) == 0) {
      iVar9 = *piVar2;
      piVar2 = (int *)((int)piVar2 - iVar9);
      iVar6 = piVar2[2];
      uVar3 = uVar3 + iVar9;
      iVar9 = piVar2[3];
      *(int *)(iVar6 + 0xc) = iVar9;
      *(int *)(iVar9 + 8) = iVar6;
    }
    piVar2[1] = uVar3 | 1;
    puVar11 = _DAT_10004e48;
    *(int **)(iVar1 + 8) = piVar2;
    if (*puVar11 <= uVar3) {
      FUN_10004bf4(param_1,*_DAT_10004e4c);
    }
    goto LAB_10004d38;
  }
  puVar11[1] = uVar5;
  if ((uVar8 & 1) == 0) {
    iVar9 = *piVar2;
    piVar2 = (int *)((int)piVar2 - iVar9);
    uVar3 = uVar3 + iVar9;
    iVar9 = piVar2[2];
    if (iVar9 == iVar1 + 8) {
      if ((*(uint *)((int)puVar11 + uVar5 + 4) & 1) == 0) {
        uVar8 = puVar11[2];
        uVar4 = puVar11[3];
        uVar3 = uVar3 + uVar5;
        *(uint *)(uVar8 + 0xc) = uVar4;
        *(uint *)(uVar4 + 8) = uVar8;
        piVar2[1] = uVar3 | 1;
        *(uint *)((int)piVar2 + uVar3) = uVar3;
      }
      else {
        piVar2[1] = uVar3 | 1;
        *puVar11 = uVar3;
      }
      goto LAB_10004d38;
    }
    iVar6 = piVar2[3];
    *(int *)(iVar9 + 0xc) = iVar6;
    *(int *)(iVar6 + 8) = iVar9;
    if ((*(uint *)((int)puVar11 + uVar5 + 4) & 1) != 0) goto LAB_10004d0e;
LAB_10004cea:
    uVar8 = puVar11[2];
    uVar3 = uVar3 + uVar5;
    if (uVar8 == _DAT_10004e44) {
      *(int **)(uVar8 + 0xc) = piVar2;
      *(int **)(uVar8 + 8) = piVar2;
      piVar2[3] = uVar8;
      piVar2[2] = uVar8;
      piVar2[1] = uVar3 | 1;
      *(uint *)((int)piVar2 + uVar3) = uVar3;
      goto LAB_10004d38;
    }
    uVar5 = puVar11[3];
    *(uint *)(uVar8 + 0xc) = uVar5;
    *(uint *)(uVar5 + 8) = uVar8;
    piVar2[1] = uVar3 | 1;
    *(uint *)((int)piVar2 + uVar3) = uVar3;
  }
  else {
    if ((*(uint *)((int)puVar11 + uVar5 + 4) & 1) == 0) goto LAB_10004cea;
LAB_10004d0e:
    piVar2[1] = uVar3 | 1;
    *puVar11 = uVar3;
  }
  if (uVar3 < 0x200) {
    *(uint *)(iVar1 + 4) = 1 << (uVar3 >> 5 & 0xff) | *(uint *)(iVar1 + 4);
    iVar1 = (uVar3 & 0xfffffff8) + iVar1;
    iVar9 = *(int *)(iVar1 + 8);
    piVar2[3] = iVar1;
    piVar2[2] = iVar9;
    *(int **)(iVar1 + 8) = piVar2;
    *(int **)(iVar9 + 0xc) = piVar2;
  }
  else {
    uVar5 = uVar3 >> 9;
    if (uVar5 < 5) {
      iVar6 = (uVar3 >> 6) + 0x38;
      iVar9 = ((uVar3 >> 6) + 0x39) * 8;
    }
    else if (uVar5 < 0x15) {
      iVar6 = uVar5 + 0x5b;
      iVar9 = (uVar5 + 0x5c) * 8;
    }
    else if (uVar5 < 0x55) {
      iVar6 = (uVar3 >> 0xc) + 0x6e;
      iVar9 = ((uVar3 >> 0xc) + 0x6f) * 8;
    }
    else if (uVar5 < 0x155) {
      iVar6 = (uVar3 >> 0xf) + 0x77;
      iVar9 = ((uVar3 >> 0xf) + 0x78) * 8;
    }
    else if (_DAT_10004e50 < uVar5) {
      iVar6 = 0x7e;
      iVar9 = 0x3f8;
    }
    else {
      iVar6 = (uVar3 >> 0x12) + 0x7c;
      iVar9 = ((uVar3 >> 0x12) + 0x7d) * 8;
    }
    piVar7 = *(int **)(iVar1 + iVar9);
    piVar10 = (int *)(iVar1 + iVar9) + -2;
    if (piVar10 == piVar7) {
      *(uint *)(iVar1 + 4) = 1 << (iVar6 >> 2 & 0xffU) | *(uint *)(iVar1 + 4);
    }
    else {
      do {
        if ((piVar7[1] & 0xfffffffcU) <= uVar3) break;
        piVar7 = (int *)piVar7[2];
      } while (piVar10 != piVar7);
      piVar10 = (int *)piVar7[3];
    }
    piVar2[3] = (int)piVar10;
    piVar2[2] = (int)piVar7;
    piVar10[2] = (int)piVar2;
    piVar7[3] = (int)piVar2;
  }
LAB_10004d38:
  FUN_10004bc0(param_1);
  return;
}

// FUNC 0x10004e54  null_callback_1

/* Empty callback used by the libc stubs */

void null_callback_1(void)

{
  return;
}

// FUNC 0x10004e58  null_callback_2

/* Empty callback used by the libc stubs */

void null_callback_2(void)

{
  return;
}

// FUNC 0x10004e60  flash_program_page_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_program_page at 0x10000450 */

void flash_program_page_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004e6c)(param_1);
  return;
}

// FUNC 0x10004e70  flash_controller_init_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_controller_init at 0x100003B8 */

void flash_controller_init_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004e7c)(param_1);
  return;
}

// FUNC 0x10004e80  flash_erase_sector_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_erase_sector at 0x100003D8 */

void flash_erase_sector_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004e8c)(param_1);
  return;
}

// FUNC 0x10004e90  flash_exit_powerdown_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_exit_powerdown at 0x1000015C */

void flash_exit_powerdown_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004e98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004e9c)(param_1);
  return;
}

// FUNC 0x10004ea0  flash_begin_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_begin at 0x10000120 */

void flash_begin_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004ea8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004eac)(param_1);
  return;
}

// FUNC 0x10004eb0  flash_end_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_end at 0x10000134 */

void flash_end_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004eb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004ebc)(param_1);
  return;
}

// FUNC 0x10004ec0  flash_status_veneer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Veneer to flash_status at 0x1000014C */

void flash_status_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10004ec8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_10004ecc)(param_1);
  return;
}

// FUNC 0x100480b0  FUN_100480b0

int FUN_100480b0(uint *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    do {
      uVar2 = *param_1;
      param_1 = param_1 + 1;
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      uVar4 = uVar2 - DAT_10048134 & ~uVar2 & DAT_10048134 << 7;
      if (uVar4 != 0) {
        iVar1 = (uVar2 & 0xff) - (uVar3 & 0xff);
        if ((((uVar4 & 0xff) == 0 && iVar1 == 0) &&
            (iVar1 = (uVar2 & 0xffff) - (uVar3 & 0xffff), (uVar4 & 0xffff) == 0 && iVar1 == 0)) &&
           (iVar1 = (uVar2 & 0xffffff) - (uVar3 & 0xffffff), (uVar4 & 0xffffff) == 0 && iVar1 == 0))
        {
          iVar1 = (uVar2 >> 0x18) - (uVar3 >> 0x18);
        }
        return iVar1;
      }
    } while (uVar2 == uVar3);
    if ((uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18)
        < (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18
          )) {
      return 1;
    }
    return -1;
  }
  while( true ) {
    uVar2 = (uint)(byte)*param_1;
    uVar3 = (uint)(byte)*param_2;
    if ((uVar2 == 0) || (uVar2 != uVar3)) break;
    uVar2 = (uint)*(byte *)((int)param_1 + 1);
    uVar3 = (uint)*(byte *)((int)param_2 + 1);
    param_1 = (uint *)((int)param_1 + 2);
    param_2 = (uint *)((int)param_2 + 2);
    if ((uVar2 == 0) || (uVar2 != uVar3)) break;
  }
  return uVar2 - uVar3;
}

// FUNC 0x10048188  FUN_10048188

int FUN_10048188(void)

{
  int iVar1;
  
  iVar1 = FUN_10049c38();
  return 1 - iVar1;
}

// FUNC 0x10048194  FUN_10048194

undefined4 FUN_10048194(void)

{
  int iVar1;
  
  iVar1 = FUN_10049d80();
  if (-1 < iVar1) {
    return 0;
  }
  return 1;
}

// FUNC 0x100481a8  FUN_100481a8

undefined4 FUN_100481a8(void)

{
  int iVar1;
  
  iVar1 = FUN_10049d80();
  if (0 < iVar1) {
    return 0;
  }
  return 1;
}

// FUNC 0x100481bc  FUN_100481bc

undefined4 FUN_100481bc(void)

{
  int iVar1;
  
  iVar1 = FUN_10049cb8();
  if (iVar1 < 1) {
    return 0;
  }
  return 1;
}

// FUNC 0x100481d0  FUN_100481d0

undefined4 FUN_100481d0(void)

{
  int iVar1;
  
  iVar1 = FUN_10049cb8();
  if (iVar1 < 0) {
    return 0;
  }
  return 1;
}

// FUNC 0x100481e4  FUN_100481e4

void FUN_100481e4(int param_1,int param_2,int param_3,int param_4)

{
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != 0) {
      param_1 = -1;
      param_2 = param_1;
    }
                    /* WARNING: Could not recover jumptable at 0x10048204. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((int)&DAT_10048208 + DAT_10048208))(param_1,param_2);
    return;
  }
  FUN_10048290(param_1);
  return;
}

// FUNC 0x10048224  FUN_10048224

int FUN_10048224(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_1004ad70(param_1,0x4f000000);
  if (iVar1 == 0) {
    iVar1 = FUN_10048e64(param_1);
  }
  else {
    FUN_10048b58(param_1,0x4f000000);
    iVar1 = FUN_10048e64();
    iVar1 = iVar1 + -0x80000000;
  }
  return iVar1;
}

// FUNC 0x10048254  FUN_10048254

int FUN_10048254(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_100481d0(param_1,param_2,0,DAT_1004828c);
  if (iVar1 == 0) {
    iVar1 = FUN_1004a9f0(param_1,param_2);
  }
  else {
    FUN_1004a348(param_1,param_2,0,DAT_1004828c);
    iVar1 = FUN_1004a9f0();
    iVar1 = iVar1 + -0x80000000;
  }
  return iVar1;
}

// FUNC 0x10048290  FUN_10048290

undefined8 FUN_10048290(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  uint local_30;
  uint local_2c;
  
  if ((param_2 <= param_4 && param_4 != param_2) || ((param_4 == param_2 && (param_1 < param_3)))) {
    local_30 = 0;
    local_2c = 0;
  }
  else {
    iVar1 = FUN_1004ad84(param_3,param_4);
    iVar2 = FUN_1004ad84(param_1,param_2);
    uVar4 = iVar1 - iVar2;
    uVar5 = uVar4 - 0x20;
    if ((int)uVar5 < 0) {
      uVar8 = param_4 << (uVar4 & 0xff) | param_3 >> (0x20 - uVar4 & 0xff);
    }
    else {
      uVar8 = param_3 << (uVar5 & 0xff);
    }
    param_3 = param_3 << (uVar4 & 0xff);
    if ((param_2 <= uVar8 && uVar8 != param_2) || ((uVar8 == param_2 && (param_1 < param_3)))) {
      local_30 = 0;
      local_2c = 0;
    }
    else {
      bVar9 = param_1 < param_3;
      param_1 = param_1 - param_3;
      param_2 = (param_2 - uVar8) - (uint)bVar9;
      if ((int)uVar5 < 0) {
        local_2c = 1 >> (0x20 - uVar4 & 0xff);
      }
      else {
        local_2c = 1 << (uVar5 & 0xff);
      }
      local_30 = 1 << (uVar4 & 0xff);
    }
    if (uVar4 != 0) {
      uVar3 = param_3 >> 1 | uVar8 << 0x1f;
      uVar8 = uVar8 >> 1;
      uVar7 = uVar4;
      do {
        while ((param_2 < uVar8 || ((uVar8 == param_2 && (param_1 < uVar3))))) {
          uVar7 = uVar7 - 1;
          bVar9 = CARRY4(param_1,param_1);
          param_1 = param_1 * 2;
          param_2 = param_2 * 2 + (uint)bVar9;
          if (uVar7 == 0) goto LAB_10048378;
        }
        bVar9 = param_1 < uVar3;
        uVar6 = param_1 - uVar3;
        uVar7 = uVar7 - 1;
        param_1 = uVar6 * 2 + 1;
        param_2 = ((param_2 - uVar8) - (uint)bVar9) * 2 + (uint)CARRY4(uVar6,uVar6) +
                  (uint)(0xfffffffe < uVar6 * 2);
      } while (uVar7 != 0);
LAB_10048378:
      bVar9 = CARRY4(local_30,param_1);
      uVar8 = local_30 + param_1;
      iVar1 = local_2c + param_2;
      if ((int)uVar5 < 0) {
        param_1 = param_1 >> (uVar4 & 0xff) | param_2 << (0x20 - uVar4 & 0xff);
      }
      else {
        param_1 = param_2 >> (uVar5 & 0xff);
      }
      param_2 = param_2 >> (uVar4 & 0xff);
      if ((int)uVar5 < 0) {
        uVar5 = param_2 << (uVar4 & 0xff) | param_1 >> (0x20 - uVar4 & 0xff);
      }
      else {
        uVar5 = param_1 << (uVar5 & 0xff);
      }
      uVar4 = param_1 << (uVar4 & 0xff);
      local_30 = uVar8 - uVar4;
      local_2c = ((iVar1 + (uint)bVar9) - uVar5) - (uint)(uVar8 < uVar4);
    }
  }
  if (param_5 != (uint *)0x0) {
    *param_5 = param_1;
    param_5[1] = param_2;
  }
  return CONCAT44(local_2c,local_30);
}

// FUNC 0x10048410  FUN_10048410

uint FUN_10048410(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar6 = -((int)param_1 >> 0x1f);
  uVar5 = (param_1 << 1) >> 0x18;
  uVar4 = (param_1 << 9) >> 6;
  uVar7 = (param_2 << 1) >> 0x18;
  iVar2 = -((int)param_2 >> 0x1f);
  uVar3 = (param_2 << 9) >> 6;
  uVar8 = uVar4;
  if (iVar6 == iVar2) {
    uVar1 = uVar5 - uVar7;
    if ((int)uVar1 < 1) {
      if (uVar1 != 0) {
        if (uVar5 == 0) {
          uVar8 = uVar3;
          uVar5 = uVar7;
          if (uVar4 == 0) goto LAB_1004843e;
          uVar1 = ~uVar1;
          if (uVar1 == 0) goto LAB_10048640;
          if (uVar7 != 0xff) goto LAB_1004862c;
        }
        else if (uVar7 != 0xff) {
          uVar1 = -uVar1;
          uVar4 = uVar4 | 0x4000000;
LAB_1004862c:
          if ((int)uVar1 < 0x1c) {
            uVar4 = (uint)(uVar4 << (0x20 - uVar1 & 0xff) != 0) | uVar4 >> (uVar1 & 0xff);
          }
          else {
            uVar4 = 1;
          }
LAB_10048640:
          uVar8 = uVar4 + uVar3;
          goto LAB_1004850c;
        }
LAB_100486ce:
        uVar8 = uVar3;
        uVar5 = 0xff;
        goto LAB_1004843e;
      }
      uVar7 = uVar5 + 1;
      if ((uVar7 & 0xff) < 2) {
        if (uVar5 == 0) {
          uVar8 = uVar3;
          if ((uVar4 != 0) && (uVar8 = uVar4, uVar3 != 0)) {
            uVar8 = uVar4 + uVar3;
            if (-1 < (int)(uVar8 * 0x20)) goto LAB_100484be;
            uVar8 = uVar8 & DAT_100486f8;
            uVar5 = uVar7;
          }
        }
        else {
          if (uVar4 == 0) goto LAB_100486ce;
          uVar5 = 0xff;
          if (uVar3 != 0) {
            uVar8 = param_1 & 0x7fffff;
            if (((param_1 & 0x400000) != 0) && ((param_2 & 0x400000) == 0)) {
              uVar8 = param_2 & 0x7fffff;
            }
            goto LAB_100486a0;
          }
        }
        goto LAB_1004843e;
      }
      if (uVar7 != 0xff) {
        uVar8 = uVar4 + uVar3 >> 1;
        uVar5 = uVar7;
        goto LAB_1004843e;
      }
    }
    else {
      if (uVar7 == 0) {
        if (uVar3 != 0) {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0) goto LAB_1004850a;
          if (uVar5 != 0xff) goto LAB_100484f4;
        }
      }
      else if (uVar5 != 0xff) {
        uVar3 = uVar3 | 0x4000000;
LAB_100484f4:
        if ((int)uVar1 < 0x1c) {
          uVar3 = (uint)(uVar3 << (0x20 - uVar1 & 0xff) != 0) | uVar3 >> (uVar1 & 0xff);
        }
        else {
          uVar3 = 1;
        }
LAB_1004850a:
        uVar8 = uVar4 + uVar3;
        uVar7 = uVar5;
LAB_1004850c:
        uVar5 = uVar7;
        if (-1 < (int)(uVar8 << 5)) goto LAB_100484be;
        if (uVar7 + 1 == 0xff) goto LAB_100485e0;
        uVar8 = uVar8 >> 1 & DAT_100486f4 | uVar8 & 1;
        uVar5 = uVar7 + 1;
      }
LAB_1004843e:
      if ((uVar8 & 7) != 0) {
LAB_10048442:
        if ((uVar8 & 0xf) != 4) {
          uVar8 = uVar8 + 4;
        }
      }
      if ((int)(uVar8 << 5) < 0) {
        if (uVar5 + 1 == 0xff) {
          uVar8 = 0;
          uVar5 = 0xff;
        }
        else {
          uVar8 = (uVar8 << 6) >> 9;
          uVar5 = uVar5 + 1 & 0xff;
        }
        goto LAB_10048460;
      }
LAB_100484c2:
      uVar8 = uVar8 >> 3;
      if (uVar5 != 0xff) goto LAB_1004852a;
      if (uVar8 != 0) {
LAB_100484d0:
        uVar8 = uVar8 & 0x7fffff | 0x400000;
        uVar5 = 0xff;
        goto LAB_10048460;
      }
    }
LAB_100485e0:
    uVar5 = 0xff;
    uVar8 = 0;
  }
  else {
    uVar1 = uVar5 - uVar7;
    if (0 < (int)uVar1) {
      if (uVar7 == 0) {
        if (uVar3 != 0) {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0) goto LAB_1004848e;
          if (uVar5 != 0xff) goto LAB_10048478;
        }
      }
      else if (uVar5 != 0xff) {
        uVar3 = uVar3 | 0x4000000;
LAB_10048478:
        if ((int)uVar1 < 0x1c) {
          uVar3 = (uint)(uVar3 << (0x20 - uVar1 & 0xff) != 0) | uVar3 >> (uVar1 & 0xff);
        }
        else {
          uVar3 = 1;
        }
LAB_1004848e:
        uVar8 = uVar4 - uVar3;
        goto LAB_10048490;
      }
      goto LAB_1004843e;
    }
    if (uVar1 != 0) {
      if (uVar5 == 0) {
        uVar8 = uVar3;
        uVar5 = uVar7;
        iVar6 = iVar2;
        if (uVar4 == 0) goto LAB_1004843e;
        uVar1 = ~uVar1;
        if (uVar1 != 0) {
          if (uVar7 == 0xff) goto LAB_100486a6;
          goto LAB_100485a8;
        }
      }
      else {
        if (uVar7 == 0xff) {
LAB_100486a6:
          uVar8 = uVar3;
          uVar5 = 0xff;
          iVar6 = iVar2;
          goto LAB_1004843e;
        }
        uVar1 = -uVar1;
        uVar4 = uVar4 | 0x4000000;
LAB_100485a8:
        if ((int)uVar1 < 0x1c) {
          uVar4 = (uint)(uVar4 << (0x20 - uVar1 & 0xff) != 0) | uVar4 >> (uVar1 & 0xff);
        }
        else {
          uVar4 = 1;
        }
      }
      uVar8 = uVar3 - uVar4;
      uVar5 = uVar7;
      iVar6 = iVar2;
LAB_10048490:
      if ((int)(uVar8 << 5) < 0) {
        uVar8 = uVar8 & 0x3ffffff;
        goto LAB_10048498;
      }
LAB_100484be:
      if ((uVar8 & 7) != 0) goto LAB_10048442;
      goto LAB_100484c2;
    }
    if (1 < (uVar5 + 1 & 0xff)) {
      uVar8 = uVar4 - uVar3;
      if ((uVar8 & 0x4000000) == 0) {
        if (uVar8 == 0) {
          iVar6 = 0;
          uVar5 = 0;
          uVar8 = 0;
          goto LAB_1004852a;
        }
      }
      else {
        uVar8 = uVar3 - uVar4;
        iVar6 = iVar2;
      }
LAB_10048498:
      iVar2 = FUN_10056d78(uVar8);
      uVar7 = iVar2 - 5;
      uVar8 = uVar8 << (uVar7 & 0xff);
      if ((int)uVar7 < (int)uVar5) {
        uVar8 = DAT_100486f8 & uVar8;
        uVar5 = uVar5 - uVar7;
      }
      else {
        uVar5 = (uVar7 - uVar5) + 1;
        uVar8 = uVar8 >> (uVar5 & 0xff) | (uint)(uVar8 << (0x20 - uVar5 & 0xff) != 0);
        uVar5 = 0;
      }
      goto LAB_1004843e;
    }
    if (uVar5 != 0) {
      if (uVar4 != 0) {
        uVar5 = 0xff;
        if (uVar3 != 0) {
          uVar8 = param_1 & 0x7fffff;
          if (((param_1 & 0x400000) != 0) && ((param_2 & 0x400000) == 0)) {
            uVar8 = param_2 & 0x7fffff;
            iVar6 = iVar2;
          }
LAB_100486a0:
          uVar8 = uVar8 << 3;
          uVar5 = 0xff;
        }
        goto LAB_1004843e;
      }
      if (uVar3 != 0) {
        uVar8 = uVar3;
        uVar5 = 0xff;
        iVar6 = iVar2;
        goto LAB_1004843e;
      }
      iVar6 = 0;
      uVar8 = 0x400000;
      goto LAB_100484d0;
    }
    if (uVar4 != 0) {
      if (uVar3 != 0) {
        uVar8 = uVar4 - uVar3;
        if ((uVar8 & 0x4000000) == 0) {
          if (uVar8 != 0) goto LAB_100484be;
          iVar6 = 0;
          uVar8 = 0;
          goto LAB_1004852a;
        }
        uVar8 = uVar3 - uVar4;
        iVar6 = iVar2;
      }
      goto LAB_1004843e;
    }
    uVar8 = uVar3;
    iVar6 = iVar2;
    if (uVar3 != 0) goto LAB_1004843e;
    uVar8 = 0;
    iVar6 = 0;
LAB_1004852a:
    uVar8 = uVar8 & 0x7fffff;
    uVar5 = uVar5 & 0xff;
  }
LAB_10048460:
  return iVar6 << 0x1f | uVar8 | uVar5 << 0x17;
}

// FUNC 0x100486fc  FUN_100486fc

void FUN_100486fc(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 & 0x7fffff;
  uVar3 = (param_1 << 1) >> 0x18;
  if (uVar3 == 0) {
    if (uVar2 == 0) {
      uVar2 = 4;
    }
    else {
      FUN_10056d78(uVar2);
      uVar2 = 0;
    }
  }
  else if (uVar3 == 0xff) {
    if (uVar2 == 0) {
      uVar2 = 8;
    }
    else {
      uVar2 = 0xc;
    }
  }
  else {
    uVar2 = 0;
  }
  uVar1 = param_2 & 0x7fffff;
  uVar3 = (param_2 << 1) >> 0x18;
  if (uVar3 == 0) {
    if (uVar1 == 0) {
      uVar3 = 1;
LAB_100487b2:
                    /* WARNING: Could not recover jumptable at 0x100487c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(PTR_PTR_LAB_10048928 + (uVar2 | uVar3) * 4))();
      return;
    }
    FUN_10056d78(uVar1);
    uVar3 = 0;
  }
  else if (uVar3 == 0xff) {
    if (uVar1 == 0) {
      uVar3 = 2;
      goto LAB_100487b2;
    }
    uVar3 = 3;
  }
  else {
    uVar3 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x10048762. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_PTR_LAB_10048924 + (uVar2 | uVar3) * 4))();
  return;
}

// FUNC 0x10048930  FUN_10048930

uint FUN_10048930(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar4 = param_1 & 0x7fffff;
  uVar5 = (param_1 << 1) >> 0x18;
  if (uVar5 == 0) {
    if (uVar4 == 0) {
      uVar7 = 4;
    }
    else {
      iVar6 = FUN_10056d78(uVar4);
      uVar4 = uVar4 << (iVar6 - 5U & 0xff);
      uVar5 = -(iVar6 + 0x76);
      uVar7 = 0;
    }
  }
  else if (uVar5 == 0xff) {
    if (uVar4 == 0) {
      uVar7 = 8;
    }
    else {
      uVar7 = 0xc;
    }
  }
  else {
    uVar7 = 0;
    uVar4 = uVar4 << 3 | 0x4000000;
    uVar5 = uVar5 - 0x7f;
  }
  uVar3 = param_2 & 0x7fffff;
  uVar2 = (param_2 << 1) >> 0x18;
  if (uVar2 == 0) {
    uVar1 = 1;
    if (uVar3 != 0) {
      iVar6 = FUN_10056d78(uVar3);
      uVar3 = uVar3 << (iVar6 - 5U & 0xff);
      uVar2 = -(iVar6 + 0x76);
      uVar1 = 0;
    }
  }
  else if (uVar2 == 0xff) {
    uVar1 = 3 - (uVar3 == 0);
  }
  else {
    uVar1 = 0;
    uVar3 = uVar3 << 3 | 0x4000000;
    uVar2 = uVar2 - 0x7f;
  }
  if ((uVar7 | uVar1) < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x10048998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar5 = (**(code **)(DAT_10048b50 + (uVar7 | uVar1) * 4))();
    return uVar5;
  }
  uVar1 = (uVar4 >> 0x10) * (uVar3 & 0xffff);
  uVar7 = (uVar4 & 0xffff) * (uVar3 & 0xffff);
  iVar6 = (uVar3 >> 0x10) * (uVar4 >> 0x10);
  uVar4 = (uVar7 >> 0x10) + (uVar4 & 0xffff) * (uVar3 >> 0x10) + uVar1;
  if (uVar4 <= uVar1 && uVar1 - uVar4 != 0) {
    iVar6 = iVar6 + 0x10000;
  }
  uVar3 = uVar4 * 0x10000 + (uVar7 & 0xffff);
  uVar7 = (uint)((uVar3 & 0x3ffffff) != 0);
  uVar3 = uVar3 >> 0x1a;
  uVar4 = ((uVar4 >> 0x10) + iVar6) * 0x40 | uVar3 | uVar7;
  iVar6 = uVar5 + uVar2;
  if ((int)(uVar4 << 4) < 0) {
    uVar4 = uVar3 & 1 | uVar7 | uVar4 >> 1;
    iVar6 = uVar5 + uVar2 + 1;
  }
  uVar5 = iVar6 + 0x7f;
  if ((int)uVar5 < 1) {
    uVar5 = 1 - uVar5;
    if ((int)uVar5 < 0x1c) {
      uVar7 = uVar4 >> (uVar5 & 0xff);
      uVar5 = (uint)(uVar4 << (0x20 - uVar5 & 0xff) != 0);
      uVar4 = uVar7 | uVar5;
      if (((uVar7 & 7) != 0 || uVar5 != 0) && ((uVar7 & 0xf | uVar5) != 4)) {
        uVar4 = uVar4 + 4;
      }
      if ((int)(uVar4 << 5) < 0) {
        uVar5 = 1;
        uVar4 = 0;
      }
      else {
        uVar4 = (uVar4 << 6) >> 9;
        uVar5 = 0;
      }
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
    }
  }
  else {
    if (((uVar4 & 7) != 0) && ((uVar4 & 0xf) != 4)) {
      uVar4 = uVar4 + 4;
    }
    if ((int)(uVar4 << 4) < 0) {
      uVar5 = iVar6 + 0x80;
      uVar4 = uVar4 & DAT_10048b54;
    }
    if ((int)uVar5 < 0xff) {
      uVar4 = (uVar4 << 6) >> 9;
      uVar5 = uVar5 & 0xff;
    }
    else {
      uVar5 = 0xff;
      uVar4 = 0;
    }
  }
  return uVar4 | uVar5 << 0x17 | (param_2 ^ param_1) & 0x80000000;
}

// FUNC 0x10048b58  FUN_10048b58

uint FUN_10048b58(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar6 = (param_1 << 1) >> 0x18;
  uVar7 = -((int)param_1 >> 0x1f);
  uVar5 = (param_1 << 9) >> 6;
  uVar8 = (param_2 << 1) >> 0x18;
  uVar3 = param_2 >> 0x1f;
  uVar4 = (param_2 << 9) >> 6;
  if ((uVar8 != 0xff) || (uVar4 == 0)) {
    uVar3 = uVar3 ^ 1;
  }
  uVar1 = uVar6 - uVar8;
  uVar9 = uVar5;
  if (uVar3 == uVar7) {
    if ((int)uVar1 < 1) {
      if (uVar1 != 0) {
        if (uVar6 == 0) {
          uVar9 = uVar4;
          uVar6 = uVar8;
          if (uVar5 == 0) goto LAB_10048b8e;
          uVar1 = ~uVar1;
          if (uVar1 == 0) goto LAB_10048daa;
          if (uVar8 != 0xff) goto LAB_10048d96;
        }
        else if (uVar8 != 0xff) {
          uVar1 = -uVar1;
          uVar5 = uVar5 | 0x4000000;
LAB_10048d96:
          if ((int)uVar1 < 0x1c) {
            uVar5 = (uint)(uVar5 << (0x20 - uVar1 & 0xff) != 0) | uVar5 >> (uVar1 & 0xff);
          }
          else {
            uVar5 = 1;
          }
LAB_10048daa:
          uVar9 = uVar5 + uVar4;
          goto LAB_10048c62;
        }
LAB_10048e36:
        uVar9 = uVar4;
        uVar6 = 0xff;
        goto LAB_10048b8e;
      }
      uVar1 = uVar6 + 1;
      if ((uVar1 & 0xff) < 2) {
        if (uVar6 == 0) {
          uVar9 = uVar4;
          if ((uVar5 != 0) && (uVar9 = uVar5, uVar4 != 0)) {
            uVar9 = uVar5 + uVar4;
            uVar8 = uVar6;
            uVar3 = uVar7;
            if (-1 < (int)(uVar9 * 0x20)) goto LAB_10048c14;
            uVar9 = uVar9 & DAT_10048e60;
            uVar6 = uVar1;
          }
        }
        else {
          if (uVar5 == 0) goto LAB_10048e36;
          uVar6 = 0xff;
          if (uVar4 != 0) {
            uVar6 = param_1 & 0x7fffff;
            if (((param_1 & 0x400000) != 0) && ((param_2 & 0x400000) == 0)) {
              uVar6 = param_2 & 0x7fffff;
            }
            uVar9 = uVar6 << 3;
            uVar6 = 0xff;
            uVar7 = uVar3;
          }
        }
        goto LAB_10048b8e;
      }
      if (uVar1 != 0xff) {
        uVar9 = uVar5 + uVar4 >> 1;
        uVar6 = uVar1;
        goto LAB_10048b8e;
      }
    }
    else {
      if (uVar8 == 0) {
        if (uVar4 != 0) {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0) goto LAB_10048c60;
          if (uVar6 != 0xff) goto LAB_10048c4a;
        }
      }
      else if (uVar6 != 0xff) {
        uVar4 = uVar4 | 0x4000000;
LAB_10048c4a:
        if ((int)uVar1 < 0x1c) {
          uVar4 = (uint)(uVar4 << (0x20 - uVar1 & 0xff) != 0) | uVar4 >> (uVar1 & 0xff);
        }
        else {
          uVar4 = 1;
        }
LAB_10048c60:
        uVar9 = uVar5 + uVar4;
        uVar8 = uVar6;
LAB_10048c62:
        if (-1 < (int)(uVar9 << 5)) goto LAB_10048c14;
        if (uVar8 + 1 == 0xff) goto LAB_10048d4a;
        uVar9 = uVar9 >> 1 & DAT_10048e5c | uVar9 & 1;
        uVar6 = uVar8 + 1;
        uVar7 = uVar3;
      }
LAB_10048b8e:
      uVar8 = uVar6;
      uVar3 = uVar7;
      if ((uVar9 & 7) != 0) {
LAB_10048b92:
        if ((uVar9 & 0xf) != 4) {
          uVar9 = uVar9 + 4;
        }
      }
      uVar6 = uVar8;
      if ((int)(uVar9 << 5) < 0) {
        if (uVar8 + 1 == 0xff) {
          uVar9 = 0;
          uVar6 = 0xff;
        }
        else {
          uVar9 = (uVar9 << 6) >> 9;
          uVar6 = uVar8 + 1 & 0xff;
        }
        goto LAB_10048bb2;
      }
LAB_10048c18:
      uVar9 = uVar9 >> 3;
      if (uVar6 != 0xff) goto LAB_10048c8a;
      if (uVar9 != 0) {
LAB_10048c28:
        uVar9 = uVar9 & 0x7fffff | 0x400000;
        uVar6 = 0xff;
        goto LAB_10048bb2;
      }
    }
LAB_10048d4a:
    uVar6 = 0xff;
    uVar9 = 0;
  }
  else {
    if (0 < (int)uVar1) {
      if (uVar8 == 0) {
        if (uVar4 != 0) {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0) goto LAB_10048be2;
          if (uVar6 != 0xff) goto LAB_10048bcc;
        }
      }
      else if (uVar6 != 0xff) {
        uVar4 = uVar4 | 0x4000000;
LAB_10048bcc:
        if ((int)uVar1 < 0x1c) {
          uVar4 = (uint)(uVar4 << (0x20 - uVar1 & 0xff) != 0) | uVar4 >> (uVar1 & 0xff);
        }
        else {
          uVar4 = 1;
        }
LAB_10048be2:
        uVar9 = uVar5 - uVar4;
        goto LAB_10048be4;
      }
      goto LAB_10048b8e;
    }
    if (uVar1 != 0) {
      if (uVar6 == 0) {
        uVar9 = uVar4;
        uVar6 = uVar8;
        uVar7 = uVar3;
        if (uVar5 == 0) goto LAB_10048b8e;
        uVar1 = ~uVar1;
        if (uVar1 != 0) {
          if (uVar8 == 0xff) goto LAB_10048d40;
          goto LAB_10048d08;
        }
      }
      else {
        if (uVar8 == 0xff) {
LAB_10048d40:
          uVar9 = uVar4;
          uVar6 = 0xff;
          uVar7 = uVar3;
          goto LAB_10048b8e;
        }
        uVar1 = -uVar1;
        uVar5 = uVar5 | 0x4000000;
LAB_10048d08:
        if ((int)uVar1 < 0x1c) {
          uVar5 = (uint)(uVar5 << (0x20 - uVar1 & 0xff) != 0) | uVar5 >> (uVar1 & 0xff);
        }
        else {
          uVar5 = 1;
        }
      }
      uVar9 = uVar4 - uVar5;
      uVar6 = uVar8;
      uVar7 = uVar3;
LAB_10048be4:
      uVar8 = uVar6;
      uVar3 = uVar7;
      if ((int)(uVar9 << 5) < 0) {
        uVar9 = uVar9 & 0x3ffffff;
        goto LAB_10048bec;
      }
LAB_10048c14:
      uVar6 = uVar8;
      if ((uVar9 & 7) != 0) goto LAB_10048b92;
      goto LAB_10048c18;
    }
    if (1 < (uVar6 + 1 & 0xff)) {
      uVar9 = uVar5 - uVar4;
      if ((uVar9 & 0x4000000) == 0) {
        if (uVar9 == 0) {
          uVar3 = 0;
          uVar6 = 0;
          uVar9 = 0;
          goto LAB_10048c8a;
        }
      }
      else {
        uVar9 = uVar4 - uVar5;
        uVar7 = uVar3;
      }
LAB_10048bec:
      iVar2 = FUN_10056d78(uVar9);
      uVar8 = iVar2 - 5;
      uVar9 = uVar9 << (uVar8 & 0xff);
      if ((int)uVar8 < (int)uVar6) {
        uVar9 = DAT_10048e60 & uVar9;
        uVar6 = uVar6 - uVar8;
      }
      else {
        uVar6 = (uVar8 - uVar6) + 1;
        uVar9 = uVar9 >> (uVar6 & 0xff) | (uint)(uVar9 << (0x20 - uVar6 & 0xff) != 0);
        uVar6 = 0;
      }
      goto LAB_10048b8e;
    }
    if (uVar6 != 0) {
      if (uVar5 != 0) {
        uVar6 = 0xff;
        if (uVar4 != 0) {
          uVar6 = param_1 & 0x7fffff;
          if (((param_1 & 0x400000) != 0) && ((param_2 & 0x400000) == 0)) {
            uVar6 = param_2 & 0x7fffff;
            uVar7 = uVar3;
          }
          uVar9 = uVar6 << 3;
          uVar6 = 0xff;
        }
        goto LAB_10048b8e;
      }
      if (uVar4 != 0) {
        uVar9 = uVar4;
        uVar6 = 0xff;
        uVar7 = uVar3;
        goto LAB_10048b8e;
      }
      uVar3 = 0;
      uVar9 = 0x400000;
      goto LAB_10048c28;
    }
    if (uVar5 != 0) {
      if (uVar4 != 0) {
        uVar9 = uVar5 - uVar4;
        if ((uVar9 & 0x4000000) == 0) {
          uVar8 = uVar6;
          uVar3 = uVar7;
          if (uVar9 != 0) goto LAB_10048c14;
          uVar3 = 0;
          uVar9 = 0;
          goto LAB_10048c8a;
        }
        uVar9 = uVar4 - uVar5;
        uVar7 = uVar3;
      }
      goto LAB_10048b8e;
    }
    uVar9 = uVar4;
    uVar7 = uVar3;
    if (uVar4 != 0) goto LAB_10048b8e;
    uVar9 = 0;
    uVar3 = 0;
LAB_10048c8a:
    uVar9 = uVar9 & 0x7fffff;
    uVar6 = uVar6 & 0xff;
  }
LAB_10048bb2:
  return uVar9 | uVar6 << 0x17 | uVar3 << 0x1f;
}

// FUNC 0x10048e64  FUN_10048e64

uint FUN_10048e64(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_1 << 1) >> 0x18;
  uVar1 = 0;
  if (0x7e < uVar3) {
    if (uVar3 < 0x9e) {
      uVar2 = param_1 & 0x7fffff | 0x800000;
      if (uVar3 < 0x96) {
        uVar2 = uVar2 >> (0x96 - uVar3 & 0xff);
      }
      else {
        uVar2 = uVar2 << (uVar3 - 0x96 & 0xff);
      }
      uVar1 = -uVar2;
      if (-1 < (int)param_1) {
        uVar1 = uVar2;
      }
    }
    else {
      uVar1 = DAT_10048ea4 - ((int)param_1 >> 0x1f);
    }
  }
  return uVar1;
}

// FUNC 0x10048ea8  FUN_10048ea8

uint FUN_10048ea8(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    param_1 = 0;
    uVar3 = 0;
    uVar4 = 0;
  }
  else {
    uVar4 = param_1 + ((int)param_1 >> 0x1f) ^ (int)param_1 >> 0x1f;
    param_1 = param_1 >> 0x1f;
    iVar1 = FUN_10056d78(uVar4);
    uVar3 = 0x9e - iVar1;
    if ((int)uVar3 < 0x97) {
      uVar4 = uVar4 << (0x96 - uVar3 & 0xff) & 0x7fffff;
      uVar3 = uVar3 & 0xff;
    }
    else {
      if ((int)uVar3 < 0x9a) {
        uVar4 = uVar4 << (0x99 - uVar3 & 0xff);
      }
      else {
        uVar4 = uVar4 >> (5U - iVar1 & 0xff) | (uint)(uVar4 << (0xb9 - uVar3 & 0xff) != 0);
      }
      uVar2 = DAT_10048f34 & uVar4;
      if (((uVar4 & 7) != 0) && ((uVar4 & 0xf) != 4)) {
        uVar2 = uVar2 + 4;
      }
      if ((int)(uVar2 << 5) < 0) {
        uVar2 = uVar2 & DAT_10048f34;
        uVar3 = 0x9f - iVar1;
      }
      uVar4 = (uVar2 << 6) >> 9;
      uVar3 = uVar3 & 0xff;
    }
  }
  return uVar4 | uVar3 << 0x17 | param_1 << 0x1f;
}

// FUNC 0x10048f38  FUN_10048f38

uint FUN_10048f38(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0;
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_10056d78();
    uVar3 = 0x9e - iVar1;
    if ((int)uVar3 < 0x97) {
      uVar2 = param_1 << (0x96 - uVar3 & 0xff) & 0x7fffff;
      uVar3 = uVar3 & 0xff;
    }
    else {
      if ((int)uVar3 < 0x9a) {
        param_1 = param_1 << (0x99 - uVar3 & 0xff);
      }
      else {
        param_1 = param_1 >> (5U - iVar1 & 0xff) | (uint)(param_1 << (0xb9 - uVar3 & 0xff) != 0);
      }
      uVar2 = DAT_10048fb0 & param_1;
      if (((param_1 & 7) != 0) && ((param_1 & 0xf) != 4)) {
        uVar2 = uVar2 + 4;
      }
      if ((int)(uVar2 << 5) < 0) {
        uVar2 = uVar2 & DAT_10048fb0;
        uVar3 = 0x9f - iVar1;
      }
      uVar2 = (uVar2 << 6) >> 9;
      uVar3 = uVar3 & 0xff;
    }
  }
  return uVar3 << 0x17 | uVar2;
}

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

// FUNC 0x1004960c  FUN_1004960c

undefined8 FUN_1004960c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  int local_3c;
  uint local_38;
  uint local_34;
  
  uVar12 = param_2 & 0xfffff;
  uVar10 = (param_2 << 1) >> 0x15;
  if (uVar10 == 0) {
    if (uVar12 == 0 && param_1 == 0) {
      uVar5 = 0;
      uVar13 = 4;
      uVar12 = 0;
    }
    else {
      if (uVar12 == 0) {
        iVar4 = FUN_10056d78();
        iVar4 = iVar4 + 0x20;
      }
      else {
        iVar4 = FUN_10056d78(uVar12);
      }
      if (iVar4 + -0xb < 0x1d) {
        uVar5 = param_1 << (iVar4 - 8U & 0xff);
        uVar12 = uVar12 << (iVar4 - 8U & 0xff) | param_1 >> (0x1dU - (iVar4 + -0xb) & 0xff);
      }
      else {
        uVar12 = param_1 << (iVar4 - 0x28U & 0xff);
        uVar5 = 0;
      }
      uVar13 = 0;
      uVar10 = -(iVar4 + DAT_100497f8);
    }
  }
  else if (uVar10 == DAT_100497e8) {
    if (param_1 == 0 && uVar12 == 0) {
      uVar5 = 0;
      uVar13 = 8;
      uVar12 = 0;
    }
    else {
      uVar13 = 0xc;
      uVar5 = param_1;
    }
  }
  else {
    uVar12 = uVar12 << 3 | param_1 >> 0x1d | 0x800000;
    uVar13 = 0;
    uVar10 = uVar10 + DAT_100497ec;
    uVar5 = param_1 << 3;
  }
  uVar6 = param_4 & 0xfffff;
  uVar1 = (param_4 << 1) >> 0x15;
  if (uVar1 == 0) {
    if (uVar6 == 0 && param_3 == 0) {
      uVar6 = 0;
      param_3 = 0;
      uVar7 = 1;
    }
    else {
      if (uVar6 == 0) {
        iVar4 = FUN_10056d78(param_3);
        iVar4 = iVar4 + 0x20;
      }
      else {
        iVar4 = FUN_10056d78(uVar6);
      }
      if (iVar4 + -0xb < 0x1d) {
        uVar6 = param_3 >> (0x1dU - (iVar4 + -0xb) & 0xff) | uVar6 << (iVar4 - 8U & 0xff);
        param_3 = param_3 << (iVar4 - 8U & 0xff);
      }
      else {
        uVar6 = param_3 << (iVar4 - 0x28U & 0xff);
        param_3 = 0;
      }
      uVar1 = -(iVar4 + DAT_100497f8);
      uVar7 = 0;
    }
  }
  else if (uVar1 == DAT_100497e8) {
    if (param_3 == 0 && uVar6 == 0) {
      param_3 = 0;
      uVar6 = 0;
      uVar7 = 2;
    }
    else {
      uVar7 = 3;
    }
  }
  else {
    uVar6 = param_3 >> 0x1d | 0x800000 | uVar6 << 3;
    param_3 = param_3 << 3;
    uVar7 = 0;
    uVar1 = uVar1 + DAT_100497ec;
  }
  local_3c = uVar10 - uVar1;
  if ((uVar13 | uVar7) < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x100496a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar14 = (**(code **)(DAT_100497f0 + (uVar13 | uVar7) * 4))();
    return uVar14;
  }
  if ((uVar6 < uVar12) || ((uVar12 == uVar6 && (param_3 <= uVar5)))) {
    uVar10 = uVar12 << 0x1f;
    local_38 = uVar5 << 0x1f;
    uVar12 = uVar12 >> 1;
    uVar5 = uVar10 | uVar5 >> 1;
  }
  else {
    local_3c = local_3c + -1;
    local_38 = 0;
  }
  uVar6 = uVar6 << 8;
  uVar7 = uVar6 | param_3 >> 0x18;
  uVar10 = param_3 * 0x100;
  uVar13 = uVar6 >> 0x10;
  uVar6 = uVar6 & 0xffff | param_3 >> 0x18;
  iVar2 = FUN_10056d58(uVar12,uVar13);
  uVar1 = iVar2 * uVar6;
  FUN_10056d68(uVar12,uVar13);
  uVar12 = uVar5 >> 0x10 | extraout_r1 << 0x10;
  iVar4 = iVar2;
  if (uVar12 <= uVar1 && uVar1 - uVar12 != 0) {
    uVar12 = uVar12 + uVar7;
    iVar4 = iVar2 + -1;
    if ((uVar7 <= uVar12) && (uVar12 <= uVar1 && uVar1 - uVar12 != 0)) {
      iVar4 = iVar2 + -2;
      uVar12 = uVar12 + uVar7;
    }
  }
  uVar3 = FUN_10056d58(uVar12 - uVar1,uVar13);
  uVar8 = uVar6 * uVar3;
  FUN_10056d68(uVar12 - uVar1,uVar13);
  uVar5 = uVar5 & 0xffff | extraout_r1_00 << 0x10;
  uVar12 = uVar3;
  if (uVar5 <= uVar8 && uVar8 - uVar5 != 0) {
    uVar5 = uVar5 + uVar7;
    uVar12 = uVar3 - 1;
    if ((uVar7 <= uVar5) && (uVar5 <= uVar8 && uVar8 - uVar5 != 0)) {
      uVar5 = uVar5 + uVar7;
      uVar12 = uVar3 - 2;
    }
  }
  uVar5 = uVar5 - uVar8;
  uVar1 = uVar12 | iVar4 << 0x10;
  uVar9 = uVar10 >> 0x10;
  uVar3 = uVar10 & 0xffff;
  uVar11 = (uVar1 >> 0x10) * uVar3;
  uVar8 = (uVar12 & 0xffff) * uVar3;
  iVar4 = uVar9 * (uVar1 >> 0x10);
  uVar12 = (uVar8 >> 0x10) + uVar9 * (uVar12 & 0xffff) + uVar11;
  if (uVar12 <= uVar11 && uVar11 - uVar12 != 0) {
    iVar4 = iVar4 + 0x10000;
  }
  uVar11 = (uVar12 >> 0x10) + iVar4;
  uVar12 = uVar12 * 0x10000 + (uVar8 & 0xffff);
  if (uVar5 < uVar11) {
LAB_10049ab6:
    local_38 = local_38 + uVar10;
    uVar5 = (local_38 < uVar10) + uVar7 + uVar5;
    uVar8 = uVar1 - 1;
    if (uVar7 < uVar5) {
LAB_10049ad4:
      if (uVar11 <= uVar5) {
        if (uVar11 != uVar5) goto LAB_10049adc;
        if (uVar12 <= local_38) {
          iVar4 = 0;
          uVar1 = uVar8;
          goto LAB_100498fe;
        }
      }
      uVar1 = uVar1 - 2;
      local_38 = local_38 + uVar10;
      uVar5 = (local_38 < uVar10) + uVar7 + uVar5;
LAB_100498fc:
      iVar4 = uVar5 - uVar11;
    }
    else {
      if (uVar7 == uVar5) {
        if (local_38 < uVar10) {
          iVar4 = uVar7 - uVar11;
          uVar1 = uVar8;
          goto LAB_100498fe;
        }
        goto LAB_10049ad4;
      }
LAB_10049adc:
      iVar4 = uVar5 - uVar11;
      uVar1 = uVar8;
    }
  }
  else {
    if (uVar5 != uVar11) goto LAB_100498fc;
    iVar4 = 0;
    if (local_38 < uVar12) goto LAB_10049ab6;
  }
LAB_100498fe:
  uVar12 = local_38 - uVar12;
  uVar5 = iVar4 - (uint)(local_38 < uVar12);
  if (uVar7 == uVar5) {
    uVar13 = 0xffffffff;
  }
  else {
    iVar2 = FUN_10056d58(uVar5,uVar13);
    uVar8 = iVar2 * uVar6;
    FUN_10056d68(uVar5,uVar13);
    uVar5 = uVar12 >> 0x10 | extraout_r1_01 << 0x10;
    iVar4 = iVar2;
    if (uVar5 <= uVar8 && uVar8 - uVar5 != 0) {
      uVar5 = uVar5 + uVar7;
      iVar4 = iVar2 + -1;
      if ((uVar7 <= uVar5) && (uVar5 <= uVar8 && uVar8 - uVar5 != 0)) {
        iVar4 = iVar2 + -2;
        uVar5 = uVar5 + uVar7;
      }
    }
    uVar11 = FUN_10056d58(uVar5 - uVar8,uVar13);
    uVar6 = uVar11 * uVar6;
    FUN_10056d68(uVar5 - uVar8,uVar13);
    uVar5 = uVar12 & 0xffff | extraout_r1_02 << 0x10;
    uVar12 = uVar11;
    if (uVar5 <= uVar6 && uVar6 - uVar5 != 0) {
      uVar5 = uVar5 + uVar7;
      uVar12 = uVar11 - 1;
      if ((uVar7 <= uVar5) && (uVar5 <= uVar6 && uVar6 - uVar5 != 0)) {
        uVar12 = uVar11 - 2;
        uVar5 = uVar5 + uVar7;
      }
    }
    uVar8 = iVar4 << 0x10 | uVar12;
    uVar5 = uVar5 - uVar6;
    uVar13 = (uVar12 & 0xffff) * uVar3;
    uVar3 = (uVar8 >> 0x10) * uVar3;
    iVar4 = uVar9 * (uVar8 >> 0x10);
    uVar12 = (uVar13 >> 0x10) + uVar9 * (uVar12 & 0xffff) + uVar3;
    if (uVar12 <= uVar3 && uVar3 - uVar12 != 0) {
      iVar4 = iVar4 + 0x10000;
    }
    uVar6 = (uVar12 >> 0x10) + iVar4;
    uVar12 = uVar12 * 0x10000 + (uVar13 & 0xffff);
    if (uVar5 < uVar6) {
LAB_10049a68:
      uVar5 = uVar7 + uVar5;
      uVar13 = uVar8 - 1;
      local_34 = uVar10;
      if (uVar5 < uVar7) {
LAB_10049a70:
        if (uVar5 != uVar6) goto LAB_100499c8;
      }
      else {
        if (uVar5 < uVar6) {
LAB_10049b98:
          uVar13 = uVar8 - 2;
          local_34 = param_3 << 9;
          uVar5 = uVar5 + (local_34 < uVar10) + uVar7;
          goto LAB_10049a70;
        }
        if (uVar6 != uVar5) goto LAB_100499c8;
        if (uVar10 < uVar12) goto LAB_10049b98;
      }
      if (local_34 == uVar12) goto LAB_100499cc;
    }
    else {
      uVar13 = uVar8;
      if (uVar5 == uVar6) {
        if (uVar12 == 0) goto LAB_100499cc;
        goto LAB_10049a68;
      }
    }
LAB_100499c8:
    uVar13 = uVar13 | 1;
  }
LAB_100499cc:
  uVar10 = local_3c + DAT_10049c28;
  if (0 < (int)uVar10) {
    uVar12 = uVar13;
    if (((uVar13 & 7) != 0) && ((uVar13 & 0xf) != 4)) {
      uVar12 = uVar13 + 4;
      uVar1 = uVar1 + (uVar12 < uVar13);
    }
    if ((int)(uVar1 << 7) < 0) {
      uVar1 = uVar1 & DAT_10049c2c;
      uVar10 = local_3c + 0x400;
    }
    if (DAT_10049c30 < (int)uVar10) {
      uVar5 = 0;
      uVar12 = 0;
      uVar10 = DAT_100497e8;
    }
    else {
      uVar12 = uVar1 << 0x1d | uVar12 >> 3;
      uVar5 = (uVar1 << 9) >> 0xc;
      uVar10 = uVar10 & 0x7ff;
    }
    goto LAB_100496d8;
  }
  uVar12 = 1 - uVar10;
  if (0x38 < (int)uVar12) {
    uVar5 = 0;
    uVar12 = 0;
    uVar10 = 0;
    goto LAB_100496d8;
  }
  if ((int)uVar12 < 0x20) {
    uVar5 = uVar13 >> (uVar12 & 0xff) | uVar1 << (0x20 - uVar12 & 0xff);
    uVar10 = (uint)(uVar13 << (0x20 - uVar12 & 0xff) != 0);
    uVar6 = uVar10 | uVar5;
    uVar1 = uVar1 >> (uVar12 & 0xff);
    if ((uVar10 != 0 || (uVar5 & 7) != 0) && (uVar12 = uVar6, (uVar10 | uVar5 & 0xf) != 4)) {
LAB_10049b5a:
      uVar6 = uVar12 + 4;
      uVar1 = uVar1 + (uVar6 < uVar12);
    }
    if ((int)(uVar1 << 8) < 0) {
      uVar12 = 0;
      uVar5 = 0;
      uVar10 = 1;
      goto LAB_100496d8;
    }
LAB_10049be2:
    uVar12 = uVar1 << 0x1d;
    uVar5 = (uVar1 << 9) >> 0xc;
  }
  else {
    uVar10 = uVar1 >> (-uVar10 - 0x1f & 0xff);
    if (uVar12 == 0x20) {
      iVar4 = 0;
    }
    else {
      iVar4 = uVar1 << (0x40 - uVar12 & 0xff);
    }
    uVar13 = (uint)(uVar13 != 0 || iVar4 != 0);
    uVar6 = uVar10 | uVar13;
    uVar12 = uVar10 & 7 | uVar13;
    uVar5 = 0;
    if (uVar12 != 0) {
      uVar1 = 0;
      uVar12 = uVar6;
      if ((uVar10 & 0xf | uVar13) != 4) goto LAB_10049b5a;
      goto LAB_10049be2;
    }
  }
  uVar12 = uVar6 >> 3 | uVar12;
  uVar10 = 0;
LAB_100496d8:
  return CONCAT44(uVar5 & DAT_100497f4 | (uVar10 & 0x7ff) << 0x14 | (param_2 ^ param_4) & 0x80000000
                  ,uVar12);
}

// FUNC 0x10049c38  FUN_10049c38

bool FUN_10049c38(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_2 & 0xfffff;
  uVar3 = (param_2 << 1) >> 0x15;
  uVar2 = (param_4 << 1) >> 0x15;
  if ((((uVar3 != DAT_10049cb4) || (bVar1 = true, uVar4 == 0 && param_1 == 0)) &&
      ((uVar2 != DAT_10049cb4 || (bVar1 = true, param_3 == 0 && (param_4 & 0xfffff) == 0)))) &&
     (((bVar1 = true, uVar3 == uVar2 && (uVar4 == (param_4 & 0xfffff))) && (param_1 == param_3)))) {
    if (-((int)param_2 >> 0x1f) == -((int)param_4 >> 0x1f)) {
      bVar1 = false;
    }
    else if (uVar3 == 0) {
      bVar1 = param_1 != 0 || uVar4 != 0;
    }
  }
  return bVar1;
}

// FUNC 0x10049cb8  FUN_10049cb8

uint FUN_10049cb8(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_4 & 0xfffff;
  uVar4 = param_2 & 0xfffff;
  uVar3 = (param_2 << 1) >> 0x15;
  uVar2 = (param_4 << 1) >> 0x15;
  if (((uVar3 == DAT_10049d7c) && (uVar4 != 0 || param_1 != 0)) ||
     ((uVar2 == DAT_10049d7c && (uVar1 != 0 || param_3 != 0)))) {
    return 0xfffffffe;
  }
  if (uVar3 == 0) {
    if ((uVar2 == 0) && (param_3 == 0 && uVar1 == 0)) {
      if (param_1 == 0 && uVar4 == 0) {
        return 0;
      }
      goto LAB_10049d1a;
    }
    if (param_1 == 0 && uVar4 == 0) {
      return -(uint)(-1 < (int)param_4) | 1;
    }
  }
  else if ((uVar2 == 0) && (param_3 == 0 && uVar1 == 0)) goto LAB_10049d1a;
  if (((int)param_4 >> 0x1f == (int)param_2 >> 0x1f) && (uVar3 <= uVar2)) {
    if (uVar2 <= uVar3) {
      if (uVar1 <= uVar4 && uVar4 != uVar1) goto LAB_10049d1a;
      if (uVar4 == uVar1) {
        if (param_3 < param_1) goto LAB_10049d1a;
        if (param_3 <= param_1) {
          return 0;
        }
      }
      else if (uVar1 <= uVar4) {
        return 0;
      }
    }
    return -(uint)(-1 < (int)param_2) | 1;
  }
LAB_10049d1a:
  return (int)param_2 >> 0x1f | 1;
}

// FUNC 0x10049d80  FUN_10049d80

uint FUN_10049d80(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_4 & 0xfffff;
  uVar4 = param_2 & 0xfffff;
  uVar2 = (param_2 << 1) >> 0x15;
  uVar3 = (param_4 << 1) >> 0x15;
  if ((uVar2 == DAT_10049e50) && (uVar4 != 0 || param_1 != 0)) {
    return 2;
  }
  if ((uVar3 == DAT_10049e50) && (uVar1 != 0 || param_3 != 0)) {
    return 2;
  }
  if (uVar2 == 0) {
    if ((uVar3 == 0) && (param_3 == 0 && uVar1 == 0)) {
      if (param_1 == 0 && uVar4 == 0) {
        return 0;
      }
      goto LAB_10049de6;
    }
    if (param_1 == 0 && uVar4 == 0) goto LAB_10049dc6;
  }
  else if ((uVar3 == 0) && (param_3 == 0 && uVar1 == 0)) goto LAB_10049de6;
  if ((int)param_2 >> 0x1f == (int)param_4 >> 0x1f) {
    if (uVar3 < uVar2) {
      return (int)param_4 >> 0x1f | 1;
    }
    if (uVar2 < uVar3) {
LAB_10049dc6:
      return -(uint)(-1 < (int)param_4) | 1;
    }
    if (uVar4 <= uVar1) {
      if (uVar4 == uVar1) {
        if (param_3 < param_1) goto LAB_10049de6;
        if (param_3 <= param_1) {
          return 0;
        }
      }
      else if (uVar1 <= uVar4) {
        return 0;
      }
      return -(uint)(-1 < (int)param_2) | 1;
    }
  }
LAB_10049de6:
  return (int)param_2 >> 0x1f | 1;
}

// FUNC 0x10049e54  FUN_10049e54

undefined8 FUN_10049e54(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined8 uVar16;
  int local_34;
  
  uVar7 = param_2 & 0xfffff;
  uVar12 = (param_2 << 1) >> 0x15;
  if (uVar12 == 0) {
    if (uVar7 == 0 && param_1 == 0) {
      uVar7 = 0;
      param_1 = 0;
      uVar13 = 4;
    }
    else {
      if (uVar7 == 0) {
        iVar2 = FUN_10056d78();
        iVar2 = iVar2 + 0x20;
      }
      else {
        iVar2 = FUN_10056d78(uVar7);
      }
      if (iVar2 + -0xb < 0x1d) {
        uVar12 = param_1 >> (0x1dU - (iVar2 + -0xb) & 0xff);
        param_1 = param_1 << (iVar2 - 8U & 0xff);
        uVar7 = uVar12 | uVar7 << (iVar2 - 8U & 0xff);
      }
      else {
        uVar7 = param_1 << (iVar2 - 0x28U & 0xff);
        param_1 = 0;
      }
      uVar13 = 0;
      uVar12 = -(iVar2 + DAT_1004a040);
    }
  }
  else if (uVar12 == DAT_1004a030) {
    if (param_1 == 0 && uVar7 == 0) {
      uVar7 = 0;
      param_1 = 0;
      uVar13 = 8;
    }
    else {
      uVar13 = 0xc;
    }
  }
  else {
    uVar7 = param_1 >> 0x1d | 0x800000 | uVar7 << 3;
    param_1 = param_1 << 3;
    uVar13 = 0;
    uVar12 = uVar12 + DAT_1004a034;
  }
  uVar10 = param_4 & 0xfffff;
  uVar1 = (param_4 << 1) >> 0x15;
  if (uVar1 == 0) {
    if (param_3 == 0 && uVar10 == 0) {
      uVar10 = 0;
      param_3 = 0;
      uVar3 = 1;
    }
    else {
      if (uVar10 == 0) {
        iVar2 = FUN_10056d78(param_3);
        iVar2 = iVar2 + 0x20;
      }
      else {
        iVar2 = FUN_10056d78(uVar10);
      }
      if (iVar2 + -0xb < 0x1d) {
        uVar1 = param_3 >> (0x1dU - (iVar2 + -0xb) & 0xff);
        param_3 = param_3 << (iVar2 - 8U & 0xff);
        uVar10 = uVar10 << (iVar2 - 8U & 0xff) | uVar1;
      }
      else {
        uVar10 = param_3 << (iVar2 - 0x28U & 0xff);
        param_3 = 0;
      }
      uVar1 = -(iVar2 + DAT_1004a040);
      uVar3 = 0;
    }
  }
  else if (uVar1 == DAT_1004a030) {
    if (param_3 == 0 && uVar10 == 0) {
      uVar10 = 0;
      param_3 = 0;
      uVar3 = 2;
    }
    else {
      uVar3 = 3;
    }
  }
  else {
    uVar10 = uVar10 << 3 | param_3 >> 0x1d | 0x800000;
    uVar3 = 0;
    param_3 = param_3 << 3;
    uVar1 = uVar1 + DAT_1004a034;
  }
  if ((uVar13 | uVar3) < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x10049eea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar16 = (**(code **)(DAT_1004a038 + (uVar13 | uVar3) * 4))();
    return uVar16;
  }
  uVar13 = param_1 >> 0x10;
  uVar3 = param_3 >> 0x10;
  param_3 = param_3 & 0xffff;
  uVar4 = param_3 * uVar13;
  local_34 = uVar3 * uVar13;
  param_1 = param_1 & 0xffff;
  uVar5 = param_1 * uVar3 + uVar4 + (param_1 * param_3 >> 0x10);
  if (uVar5 <= uVar4 && uVar4 - uVar5 != 0) {
    local_34 = local_34 + 0x10000;
  }
  uVar6 = uVar10 >> 0x10;
  uVar10 = uVar10 & 0xffff;
  uVar4 = uVar10 * uVar13;
  iVar2 = uVar6 * uVar13;
  uVar13 = uVar6 * param_1 + uVar4 + (param_1 * uVar10 >> 0x10);
  if (uVar13 <= uVar4 && uVar4 - uVar13 != 0) {
    iVar2 = iVar2 + 0x10000;
  }
  uVar4 = (uVar13 >> 0x10) + iVar2;
  uVar14 = uVar13 * 0x10000 + (param_1 * uVar10 & 0xffff);
  uVar13 = uVar7 >> 0x10;
  uVar7 = uVar7 & 0xffff;
  uVar8 = uVar13 * param_3;
  iVar2 = uVar13 * uVar3;
  uVar3 = uVar7 * uVar3 + uVar8 + (param_3 * uVar7 >> 0x10);
  if (uVar3 <= uVar8 && uVar8 - uVar3 != 0) {
    iVar2 = iVar2 + 0x10000;
  }
  uVar9 = uVar3 * 0x10000 + (param_3 * uVar7 & 0xffff);
  uVar8 = uVar10 * uVar13;
  iVar11 = uVar6 * uVar13;
  uVar13 = uVar7 * uVar6 + uVar8 + (uVar10 * uVar7 >> 0x10);
  uVar3 = (uVar3 >> 0x10) + iVar2;
  if (uVar13 <= uVar8 && uVar8 - uVar13 != 0) {
    iVar11 = iVar11 + 0x10000;
  }
  uVar15 = local_34 + (uVar5 >> 0x10) + uVar14;
  uVar6 = (uint)(uVar15 < uVar14);
  uVar10 = (uVar10 * uVar7 & 0xffff) + uVar13 * 0x10000 + uVar4;
  uVar15 = uVar15 + uVar9;
  uVar7 = (uint)(uVar15 < uVar9);
  uVar9 = uVar10 + uVar6;
  uVar14 = uVar3 + uVar9;
  uVar8 = uVar7 + uVar14;
  uVar10 = ((uint)(uVar10 < uVar4 || uVar9 < uVar6) + (uVar13 >> 0x10) +
            (uint)(uVar14 < uVar3 || uVar8 < uVar7) + iVar11) * 0x200 | uVar8 >> 0x17;
  uVar7 = (uint)((uVar15 & 0x7fffff) != 0 || uVar5 * 0x10000 + (param_1 * param_3 & 0xffff) != 0);
  uVar13 = uVar8 * 0x200 | uVar7 | uVar15 >> 0x17;
  iVar2 = uVar12 + uVar1;
  if ((int)(uVar10 << 7) < 0) {
    uVar13 = uVar7 | uVar15 >> 0x17 & 1 | uVar13 >> 1 | (uVar8 >> 0x17) << 0x1f;
    uVar10 = uVar10 >> 1;
    iVar2 = uVar12 + uVar1 + 1;
  }
  uVar12 = iVar2 + DAT_1004a338;
  if (0 < (int)uVar12) {
    uVar7 = uVar13;
    if (((uVar13 & 7) != 0) && ((uVar13 & 0xf) != 4)) {
      uVar7 = uVar13 + 4;
      uVar10 = uVar10 + (uVar7 < uVar13);
    }
    if ((int)(uVar10 << 7) < 0) {
      uVar10 = uVar10 & DAT_1004a33c;
      uVar12 = iVar2 + 0x400;
    }
    if (DAT_1004a340 < (int)uVar12) {
      uVar7 = 0;
      uVar13 = 0;
      uVar12 = DAT_1004a030;
    }
    else {
      uVar7 = uVar10 << 0x1d | uVar7 >> 3;
      uVar13 = (uVar10 << 9) >> 0xc;
      uVar12 = uVar12 & 0x7ff;
    }
    goto LAB_10049f20;
  }
  uVar7 = 1 - uVar12;
  if (0x38 < (int)uVar7) {
    uVar12 = 0;
    uVar13 = 0;
    uVar7 = 0;
    goto LAB_10049f20;
  }
  if ((int)uVar7 < 0x20) {
    uVar1 = uVar10 << (0x20 - uVar7 & 0xff) | uVar13 >> (uVar7 & 0xff);
    uVar12 = (uint)(uVar13 << (0x20 - uVar7 & 0xff) != 0);
    uVar3 = uVar1 | uVar12;
    uVar10 = uVar10 >> (uVar7 & 0xff);
    if (((uVar1 & 7) != 0 || uVar12 != 0) && ((uVar1 & 0xf | uVar12) != 4)) {
LAB_1004a2ba:
      uVar10 = uVar10 + (uVar3 + 4 < uVar3);
      uVar3 = uVar3 + 4;
    }
    if ((int)(uVar10 << 8) < 0) {
      uVar12 = 1;
      uVar13 = 0;
      uVar7 = 0;
      goto LAB_10049f20;
    }
LAB_1004a308:
    uVar7 = uVar10 << 0x1d;
    uVar13 = (uVar10 << 9) >> 0xc;
  }
  else {
    uVar12 = uVar10 >> (-uVar12 - 0x1f & 0xff);
    if (uVar7 == 0x20) {
      iVar2 = 0;
    }
    else {
      iVar2 = uVar10 << (0x40 - uVar7 & 0xff);
    }
    uVar1 = (uint)(uVar13 != 0 || iVar2 != 0);
    uVar3 = uVar1 | uVar12;
    uVar7 = uVar1 | uVar12 & 7;
    uVar13 = 0;
    if (uVar7 != 0) {
      uVar10 = 0;
      if ((uVar1 | uVar12 & 0xf) != 4) goto LAB_1004a2ba;
      goto LAB_1004a308;
    }
  }
  uVar7 = uVar3 >> 3 | uVar7;
  uVar12 = 0;
LAB_10049f20:
  return CONCAT44(uVar13 & DAT_1004a03c | (uVar12 & 0x7ff) << 0x14 |
                  (param_4 ^ param_2) & 0x80000000,uVar7);
}

// FUNC 0x1004a348  FUN_1004a348

undefined8 FUN_1004a348(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  
  uVar5 = -((int)param_2 >> 0x1f);
  uVar10 = param_1 * 8;
  uVar6 = param_1 >> 0x1d;
  uVar12 = param_3 >> 0x1d;
  uVar2 = (param_4 << 0xc) >> 9 | uVar12;
  uVar14 = (param_2 << 0xc) >> 9 | uVar6;
  uVar9 = (param_2 << 1) >> 0x15;
  uVar7 = (param_4 << 1) >> 0x15;
  uVar8 = param_4 >> 0x1f;
  uVar4 = param_3 * 8;
  if ((uVar7 != DAT_1004a6ac) || (uVar2 == 0 && uVar4 == 0)) {
    uVar8 = uVar8 ^ 1;
  }
  uVar13 = uVar9 - uVar7;
  uVar11 = uVar10;
  uVar15 = uVar2;
  if (uVar8 == uVar5) {
    if (0 < (int)uVar13) {
      if (uVar7 == 0) {
        uVar15 = uVar14;
        if (uVar2 != 0 || uVar4 != 0) {
          uVar13 = uVar13 - 1;
          if (uVar13 == 0) {
            uVar11 = uVar10 + uVar4;
            uVar15 = (uint)(uVar11 < uVar10) + uVar14 + uVar2;
            goto LAB_1004a526;
          }
          if (uVar9 != DAT_1004a9e8) goto LAB_1004a506;
        }
      }
      else {
        uVar15 = uVar14;
        if (uVar9 != DAT_1004a6ac) {
          uVar2 = uVar2 | 0x800000;
LAB_1004a506:
          if ((int)uVar13 < 0x39) {
            if ((int)uVar13 < 0x20) {
              uVar11 = (uint)(uVar4 << (0x20 - uVar13 & 0xff) != 0) |
                       uVar4 >> (uVar13 & 0xff) | uVar2 << (0x20 - uVar13 & 0xff);
              uVar2 = uVar2 >> (uVar13 & 0xff);
            }
            else {
              if (uVar13 == 0x20) {
                iVar16 = 0;
              }
              else {
                iVar16 = uVar2 << (0x40 - uVar13 & 0xff);
              }
              uVar11 = (uint)(uVar4 != 0 || iVar16 != 0) | uVar2 >> (uVar13 - 0x20 & 0xff);
              uVar2 = 0;
            }
          }
          else {
            uVar11 = (uint)(uVar4 != 0 || uVar2 != 0);
            uVar2 = 0;
          }
          uVar11 = uVar11 + uVar10;
          uVar15 = (uint)(uVar11 < uVar10) + uVar2 + uVar14;
LAB_1004a526:
          uVar5 = uVar8;
          if (-1 < (int)(uVar15 << 8)) goto LAB_1004a4ca;
          uVar7 = uVar9 + 1;
          if (uVar7 == DAT_1004a6ac) goto LAB_1004a7d4;
          uVar9 = uVar7;
          uVar11 = (DAT_1004a6b0 & uVar15) << 0x1f | uVar11 & 1 | uVar11 >> 1;
          uVar15 = (DAT_1004a6b0 & uVar15) >> 1;
        }
      }
LAB_1004a3a0:
      uVar10 = uVar11;
      uVar8 = uVar5;
      if ((uVar11 & 7) != 0) {
LAB_1004a3a4:
        uVar11 = uVar10;
        uVar8 = uVar5;
        if ((uVar10 & 0xf) != 4) {
          uVar11 = uVar10 + 4;
          uVar15 = uVar15 + (uVar11 < uVar10);
        }
      }
      if ((int)(uVar15 << 8) < 0) {
        uVar9 = uVar9 + 1;
        if (uVar9 == DAT_1004a6ac) {
          uVar5 = 0;
          uVar10 = 0;
        }
        else {
          uVar5 = uVar11 >> 3 | (uVar15 & DAT_1004a6b0) << 0x1d;
          uVar10 = ((uVar15 & DAT_1004a6b0) << 9) >> 0xc;
          uVar9 = uVar9 & 0x7ff;
        }
        goto LAB_1004a3e2;
      }
      goto LAB_1004a4d0;
    }
    if (uVar13 != 0) {
      if (uVar9 == 0) {
        uVar9 = uVar7;
        uVar11 = uVar4;
        if (uVar14 != 0 || uVar10 != 0) {
          uVar13 = ~uVar13;
          if (uVar13 == 0) goto LAB_1004a868;
          if (uVar7 != DAT_1004a9e8) goto LAB_1004a82c;
        }
      }
      else {
        uVar9 = uVar7;
        uVar11 = uVar4;
        if (uVar7 != DAT_1004a9e8) {
          uVar13 = -uVar13;
          uVar14 = uVar14 | 0x800000;
LAB_1004a82c:
          if ((int)uVar13 < 0x39) {
            if ((int)uVar13 < 0x20) {
              uVar10 = (uint)(uVar10 << (0x20 - uVar13 & 0xff) != 0) |
                       uVar14 << (0x20 - uVar13 & 0xff) | uVar10 >> (uVar13 & 0xff);
              uVar14 = uVar14 >> (uVar13 & 0xff);
            }
            else {
              uVar9 = uVar14 >> (uVar13 - 0x20 & 0xff);
              if (uVar13 == 0x20) {
                iVar16 = 0;
              }
              else {
                iVar16 = uVar14 << (0x40 - uVar13 & 0xff);
              }
              uVar14 = 0;
              uVar10 = (uVar10 != 0 || iVar16 != 0) | uVar9;
            }
          }
          else {
            uVar10 = (uint)(uVar10 != 0 || uVar14 != 0);
            uVar14 = 0;
          }
LAB_1004a868:
          uVar11 = uVar10 + uVar4;
          uVar15 = (uint)(uVar11 < uVar4) + uVar14 + uVar2;
          uVar9 = uVar7;
          goto LAB_1004a526;
        }
      }
      goto LAB_1004a3a0;
    }
    uVar7 = uVar9 + 1;
    if ((uVar7 & 0x7ff) < 2) {
      if (uVar9 == 0) {
        uVar11 = uVar4;
        if ((uVar14 != 0 || uVar10 != 0) &&
           (uVar11 = uVar10, uVar15 = uVar14, uVar2 != 0 || uVar4 != 0)) {
          uVar11 = uVar10 + uVar4;
          uVar15 = (uint)(uVar11 < uVar10) + uVar14 + uVar2;
          if (-1 < (int)(uVar15 * 0x100)) goto LAB_1004a4ca;
          uVar9 = uVar7;
          uVar15 = uVar15 & DAT_1004a9ec;
        }
      }
      else {
        uVar9 = DAT_1004a9e8;
        uVar11 = uVar4;
        if ((uVar14 != 0 || uVar10 != 0) &&
           (uVar11 = uVar10, uVar15 = uVar14, uVar2 != 0 || uVar4 != 0)) {
          uVar5 = uVar6 << 0x1d | param_1 & 0x1fffffff;
          uVar10 = param_2 & 0xfffff;
          if (((param_2 & 0x80000) != 0) && ((param_4 & 0x80000) == 0)) {
            uVar5 = uVar12 << 0x1d | param_3 & 0x1fffffff;
            uVar10 = param_4 & 0xfffff;
          }
          uVar11 = uVar5 << 3;
          uVar15 = uVar10 << 3 | uVar5 >> 0x1d;
          uVar5 = uVar8;
        }
      }
      goto LAB_1004a3a0;
    }
    if (uVar7 != DAT_1004a6ac) {
      uVar8 = (uint)(uVar10 + uVar4 < uVar10) + uVar14 + uVar2;
      uVar9 = uVar7;
      uVar11 = uVar8 * -0x80000000 | uVar10 + uVar4 >> 1;
      uVar15 = uVar8 >> 1;
      goto LAB_1004a3a0;
    }
LAB_1004a7d4:
    uVar10 = 0;
    uVar5 = 0;
    uVar9 = uVar7;
  }
  else {
    if ((int)uVar13 < 1) {
      if (uVar13 == 0) {
        if ((uVar9 + 1 & 0x7ff) < 2) {
          if (uVar9 == 0) {
            if (uVar14 == 0 && uVar10 == 0) {
              uVar11 = uVar4;
              uVar5 = uVar8;
              if (uVar2 == 0 && uVar4 == 0) {
LAB_1004a960:
                uVar10 = 0;
                uVar8 = 0;
                uVar5 = 0;
                goto LAB_1004a4de;
              }
            }
            else {
              uVar15 = uVar14;
              if (uVar2 != 0 || uVar4 != 0) {
                uVar11 = uVar10 + param_3 * -8;
                uVar15 = (uVar14 - uVar2) - (uint)(uVar10 < uVar11);
                if (-1 < (int)(uVar15 * 0x100)) {
                  if (uVar11 != 0 || uVar15 != 0) goto LAB_1004a4ca;
                  goto LAB_1004a960;
                }
                uVar11 = uVar4 + param_1 * -8;
                uVar15 = (uVar2 - uVar14) - (uint)(uVar4 < uVar11);
                uVar5 = uVar8;
              }
            }
          }
          else if (uVar14 == 0 && uVar10 == 0) {
            uVar9 = DAT_1004a9e8;
            uVar11 = uVar4;
            uVar5 = uVar8;
            if (uVar2 == 0 && uVar4 == 0) {
              uVar8 = 0;
              uVar10 = 0x80000;
              uVar5 = 0;
              goto LAB_1004a4de;
            }
          }
          else {
            uVar9 = DAT_1004a9e8;
            uVar15 = uVar14;
            if (uVar2 != 0 || uVar4 != 0) {
              uVar2 = uVar6 << 0x1d | param_1 & 0x1fffffff;
              uVar10 = param_2 & 0xfffff;
              if (((param_2 & 0x80000) != 0) && ((param_4 & 0x80000) == 0)) {
                uVar2 = uVar12 << 0x1d | param_3 & 0x1fffffff;
                uVar10 = param_4 & 0xfffff;
                uVar5 = uVar8;
              }
              uVar11 = uVar2 << 3;
              uVar15 = uVar2 >> 0x1d | uVar10 << 3;
            }
          }
        }
        else {
          uVar11 = uVar10 + param_3 * -8;
          uVar15 = (uVar14 - uVar2) - (uint)(uVar10 < uVar11);
          if ((int)(uVar15 * 0x100) < 0) {
            uVar11 = uVar4 + param_1 * -8;
            uVar15 = (uVar2 - uVar14) - (uint)(uVar4 < uVar11);
            uVar5 = uVar8;
          }
          else if (uVar11 == 0 && uVar15 == 0) {
            uVar8 = 0;
            uVar9 = 0;
            uVar5 = 0;
            uVar10 = 0;
            goto LAB_1004a4de;
          }
LAB_1004a464:
          if (uVar15 == 0) {
            iVar3 = FUN_10056d78(uVar11);
            iVar16 = iVar3 + 0x20;
            uVar10 = iVar3 + 0x18;
            if ((int)uVar10 < 0x20) goto LAB_1004a47c;
LAB_1004a608:
            uVar2 = uVar11 << (iVar16 - 0x28U & 0xff);
            uVar8 = 0;
          }
          else {
            iVar16 = FUN_10056d78(uVar15);
            uVar10 = iVar16 - 8;
            if (0x1f < (int)uVar10) goto LAB_1004a608;
LAB_1004a47c:
            uVar8 = uVar11 << (uVar10 & 0xff);
            uVar2 = uVar11 >> (0x20 - uVar10 & 0xff) | uVar15 << (uVar10 & 0xff);
          }
          if ((int)uVar10 < (int)uVar9) {
            uVar9 = uVar9 - uVar10;
            uVar11 = uVar8;
            uVar15 = DAT_1004a6b0 & uVar2;
          }
          else {
            uVar4 = (uVar10 - uVar9) + 1;
            if (0x1f < (int)uVar4) {
              if (uVar4 == 0x20) {
                iVar16 = 0;
              }
              else {
                iVar16 = uVar2 << (0x40 - uVar4 & 0xff);
              }
              uVar15 = 0;
              uVar11 = (uint)(uVar8 != 0 || iVar16 != 0) | uVar2 >> ((uVar10 - uVar9) - 0x1f & 0xff)
              ;
              uVar9 = 0;
              goto LAB_1004a4ca;
            }
            uVar9 = 0;
            uVar11 = (uint)(uVar8 << (0x20 - uVar4 & 0xff) != 0) |
                     uVar2 << (0x20 - uVar4 & 0xff) | uVar8 >> (uVar4 & 0xff);
            uVar15 = uVar2 >> (uVar4 & 0xff);
          }
        }
      }
      else if (uVar9 == 0) {
        uVar9 = uVar7;
        uVar11 = uVar4;
        uVar5 = uVar8;
        if (uVar14 != 0 || uVar10 != 0) {
          uVar13 = ~uVar13;
          if (uVar13 == 0) {
            uVar11 = uVar4 + param_1 * -8;
            goto LAB_1004a75e;
          }
          if (uVar7 != DAT_1004a9e8) goto LAB_1004a6ce;
        }
      }
      else {
        uVar9 = uVar7;
        uVar11 = uVar4;
        uVar5 = uVar8;
        if (uVar7 != DAT_1004a9e8) {
          uVar13 = -uVar13;
          uVar14 = uVar14 | 0x800000;
LAB_1004a6ce:
          if ((int)uVar13 < 0x39) {
            if ((int)uVar13 < 0x20) {
              uVar9 = uVar14 << (0x20 - uVar13 & 0xff);
              uVar14 = uVar14 >> (uVar13 & 0xff);
              uVar11 = uVar4 - (uVar9 | uVar10 >> (uVar13 & 0xff) |
                               (uint)(uVar10 << (0x20 - uVar13 & 0xff) != 0));
            }
            else {
              uVar9 = uVar14 >> (uVar13 - 0x20 & 0xff);
              if (uVar13 == 0x20) {
                iVar16 = 0;
              }
              else {
                iVar16 = uVar14 << (0x40 - uVar13 & 0xff);
              }
              uVar14 = 0;
              uVar11 = uVar4 - (uVar9 | (uVar10 != 0 || iVar16 != 0));
            }
          }
          else {
            bVar1 = uVar14 != 0;
            uVar14 = 0;
            uVar11 = uVar4 - (uVar10 != 0 || bVar1);
          }
LAB_1004a75e:
          uVar15 = (uVar2 - uVar14) - (uint)(uVar4 < uVar11);
          uVar9 = uVar7;
          uVar5 = uVar8;
          goto LAB_1004a45a;
        }
      }
      goto LAB_1004a3a0;
    }
    if (uVar7 == 0) {
      uVar15 = uVar14;
      if (uVar2 != 0 || uVar4 != 0) {
        uVar13 = uVar13 - 1;
        if (uVar13 == 0) {
          uVar11 = uVar10 + param_3 * -8;
          uVar15 = (uVar14 - uVar2) - (uint)(uVar10 < uVar11);
          goto LAB_1004a45a;
        }
        if (uVar9 != DAT_1004a6ac) goto LAB_1004a41a;
      }
      goto LAB_1004a3a0;
    }
    uVar15 = uVar14;
    if (uVar9 == DAT_1004a6ac) goto LAB_1004a3a0;
    uVar2 = uVar2 | 0x800000;
LAB_1004a41a:
    if ((int)uVar13 < 0x39) {
      if ((int)uVar13 < 0x20) {
        uVar11 = (uint)(uVar4 << (0x20 - uVar13 & 0xff) != 0) |
                 uVar4 >> (uVar13 & 0xff) | uVar2 << (0x20 - uVar13 & 0xff);
        uVar2 = uVar2 >> (uVar13 & 0xff);
      }
      else {
        if (uVar13 == 0x20) {
          iVar16 = 0;
        }
        else {
          iVar16 = uVar2 << (0x40 - uVar13 & 0xff);
        }
        uVar11 = (uint)(uVar4 != 0 || iVar16 != 0) | uVar2 >> (uVar13 - 0x20 & 0xff);
        uVar2 = 0;
      }
    }
    else {
      uVar11 = (uint)(uVar4 != 0 || uVar2 != 0);
      uVar2 = 0;
    }
    uVar11 = uVar10 - uVar11;
    uVar15 = (uVar14 - uVar2) - (uint)(uVar10 < uVar11);
LAB_1004a45a:
    if ((int)(uVar15 << 8) < 0) {
      uVar15 = uVar15 & 0x7fffff;
      goto LAB_1004a464;
    }
LAB_1004a4ca:
    uVar10 = uVar11;
    uVar8 = uVar5;
    if ((uVar11 & 7) != 0) goto LAB_1004a3a4;
LAB_1004a4d0:
    uVar10 = uVar15 >> 3;
    uVar5 = uVar11 >> 3 | uVar15 << 0x1d;
  }
LAB_1004a4de:
  if (uVar9 == DAT_1004a6ac) {
    if (uVar5 == 0 && uVar10 == 0) {
      uVar10 = 0;
      uVar5 = 0;
    }
    else {
      uVar10 = uVar10 & 0xfffff | 0x80000;
    }
  }
  else {
    uVar10 = uVar10 & 0xfffff;
    uVar9 = uVar9 & 0x7ff;
  }
LAB_1004a3e2:
  return CONCAT44(DAT_1004a6b4 & uVar10 | (uVar9 << 0x15) >> 1 | uVar8 << 0x1f,uVar5);
}

// FUNC 0x1004a9f0  FUN_1004a9f0

uint FUN_1004a9f0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (param_2 << 1) >> 0x15;
  uVar3 = 0;
  if (DAT_1004aa44 < (int)uVar2) {
    if (DAT_1004aa48 < (int)uVar2) {
      uVar3 = DAT_1004aa54 - ((int)param_2 >> 0x1f);
    }
    else {
      uVar1 = param_2 & 0xfffff | 0x100000;
      if ((int)(DAT_1004aa4c - uVar2) < 0x20) {
        uVar1 = uVar1 << (uVar2 + DAT_1004aa58 & 0xff) | param_1 >> (DAT_1004aa4c - uVar2 & 0xff);
      }
      else {
        uVar1 = uVar1 >> (DAT_1004aa50 - uVar2 & 0xff);
      }
      uVar3 = -uVar1;
      if (-1 < (int)param_2) {
        uVar3 = uVar1;
      }
    }
  }
  return uVar3;
}

// FUNC 0x1004aa5c  FUN_1004aa5c

undefined8 FUN_1004aa5c(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    param_1 = 0;
    uVar3 = 0;
    uVar4 = 0;
    iVar2 = 0;
  }
  else {
    uVar4 = param_1 + ((int)param_1 >> 0x1f) ^ (int)param_1 >> 0x1f;
    param_1 = param_1 >> 0x1f;
    iVar1 = FUN_10056d78(uVar4);
    uVar3 = DAT_1004aad0 - iVar1;
    if ((int)(DAT_1004aad4 - uVar3) < 0x20) {
      iVar2 = uVar4 << (DAT_1004aad4 - uVar3 & 0xff);
      uVar4 = uVar4 >> (0xbU - iVar1 & 0xff) & 0xfffff;
      uVar3 = uVar3 & 0x7ff;
    }
    else {
      iVar2 = 0;
      uVar4 = uVar4 << (DAT_1004aad8 - uVar3 & 0xff) & 0xfffff;
      uVar3 = uVar3 & 0x7ff;
    }
  }
  return CONCAT44(uVar4 & DAT_1004aadc | uVar3 << 0x14 | param_1 << 0x1f,iVar2);
}

// FUNC 0x1004aae0  FUN_1004aae0

undefined8 FUN_1004aae0(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    uVar2 = 0;
    uVar3 = 0;
    iVar4 = 0;
  }
  else {
    iVar1 = FUN_10056d78();
    uVar2 = DAT_1004ab40 - iVar1;
    if ((int)(DAT_1004ab44 - uVar2) < 0x20) {
      iVar4 = param_1 << (DAT_1004ab44 - uVar2 & 0xff);
      uVar3 = param_1 >> (0xbU - iVar1 & 0xff) & 0xfffff;
      uVar2 = uVar2 & 0x7ff;
    }
    else {
      iVar4 = 0;
      uVar3 = param_1 << (DAT_1004ab48 - uVar2 & 0xff) & 0xfffff;
      uVar2 = uVar2 & 0x7ff;
    }
  }
  return CONCAT44(uVar3 & DAT_1004ab4c | uVar2 << 0x14,iVar4);
}

// FUNC 0x1004ab50  FUN_1004ab50

undefined8 FUN_1004ab50(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (param_1 << 1) >> 0x18;
  uVar4 = param_1 & 0x7fffff;
  if ((uVar2 + 1 & 0xff) < 2) {
    if (uVar2 == 0) {
      if (uVar4 == 0) {
        uVar3 = 0;
        uVar2 = 0;
      }
      else {
        iVar1 = FUN_10056d78(uVar4);
        if (iVar1 < 0xb) {
          uVar3 = uVar4 >> (0xbU - iVar1 & 0xff);
          uVar4 = uVar4 << (iVar1 + 0x15U & 0xff);
        }
        else {
          uVar3 = uVar4 << (iVar1 - 0xbU & 0xff);
          uVar4 = 0;
        }
        uVar3 = uVar3 & 0xfffff;
        uVar2 = DAT_1004abf0 - iVar1 & 0x7ff;
      }
    }
    else {
      uVar2 = DAT_1004abf4;
      if (uVar4 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (param_1 << 9) >> 0xc | 0x80000;
        uVar4 = uVar4 << 0x1d;
      }
    }
  }
  else {
    uVar4 = uVar4 << 0x1d;
    uVar3 = (param_1 << 9) >> 0xc;
    uVar2 = uVar2 + 0x380;
  }
  return CONCAT44(uVar3 & DAT_1004abec | (uVar2 << 0x15) >> 1 | param_1 & 0x80000000,uVar4);
}

// FUNC 0x1004abf8  FUN_1004abf8

uint FUN_1004abf8(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = (param_2 << 1) >> 0x15;
  uVar3 = param_1 >> 0x1d | (param_2 << 0xc) >> 9;
  uVar6 = param_1 << 3;
  if ((uVar7 + 1 & 0x7ff) < 2) {
    if (uVar7 == 0) {
      uVar3 = uVar3 | uVar6;
      uVar5 = 0;
      if (uVar3 != 0) {
LAB_1004ac86:
        uVar5 = 0;
        uVar3 = 0;
        goto LAB_1004ac88;
      }
LAB_1004ac8e:
      uVar3 = uVar3 & 0x7fffff;
      uVar5 = uVar5 & 0xff;
      goto LAB_1004ac56;
    }
    if (uVar6 != 0 || uVar3 != 0) {
      uVar3 = uVar3 << 3 | 0x2000000;
      uVar5 = 0xff;
      goto LAB_1004ac2e;
    }
  }
  else {
    uVar5 = uVar7 + DAT_1004ad04;
    if ((int)uVar5 < 0xff) {
      if ((int)uVar5 < 1) {
        if ((int)(uVar5 + 0x17) < 0 != SCARRY4(uVar5,0x17)) goto LAB_1004ac86;
        uVar3 = uVar3 | 0x800000;
        uVar2 = 0x1e - uVar5;
        if ((int)uVar2 < 0x20) {
          uVar3 = uVar6 >> (uVar2 & 0xff) |
                  (uint)(uVar6 << (uVar7 + DAT_1004ad08 & 0xff) != 0) |
                  uVar3 << (uVar7 + DAT_1004ad08 & 0xff);
          uVar5 = 0;
        }
        else {
          iVar1 = -uVar5;
          if (uVar2 == 0x20) {
            iVar4 = 0;
          }
          else {
            iVar4 = uVar3 << (uVar7 + DAT_1004ad0c & 0xff);
          }
          uVar5 = 0;
          uVar3 = (uint)(uVar6 != 0 || iVar4 != 0) | uVar3 >> (iVar1 - 2U & 0xff);
        }
      }
      else {
        uVar3 = uVar6 >> 0x1d | (uint)((param_1 & 0x3ffffff) != 0) | uVar3 << 3;
      }
LAB_1004ac2e:
      if (((uVar3 & 7) != 0) && ((uVar3 & 0xf) != 4)) {
        uVar3 = uVar3 + 4;
      }
      if ((uVar3 & 0x4000000) == 0) {
LAB_1004ac88:
        uVar3 = uVar3 >> 3;
        if (uVar5 == 0xff) {
          uVar5 = 0xff;
          if (uVar3 == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = uVar3 & 0x7fffff | 0x400000;
          }
          goto LAB_1004ac56;
        }
        goto LAB_1004ac8e;
      }
      if (uVar5 + 1 != 0xff) {
        uVar3 = (uVar3 << 6) >> 9;
        uVar5 = uVar5 + 1 & 0xff;
        goto LAB_1004ac56;
      }
    }
  }
  uVar5 = 0xff;
  uVar3 = 0;
LAB_1004ac56:
  return uVar5 << 0x17 | uVar3 | param_2 & 0x80000000;
}

// FUNC 0x1004ad70  FUN_1004ad70

undefined4 FUN_1004ad70(void)

{
  int iVar1;
  
  iVar1 = FUN_1004adec();
  if (iVar1 < 0) {
    return 0;
  }
  return 1;
}

// FUNC 0x1004ad84  FUN_1004ad84

int FUN_1004ad84(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = FUN_10056d78();
    iVar1 = iVar1 + 0x20;
  }
  else {
    iVar1 = FUN_10056d78(param_2);
  }
  return iVar1;
}

// FUNC 0x1004adec  FUN_1004adec

uint FUN_1004adec(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 & 0x7fffff;
  uVar3 = param_2 & 0x7fffff;
  uVar2 = (param_1 << 1) >> 0x18;
  uVar1 = (param_2 << 1) >> 0x18;
  if (((uVar2 == 0xff) && (uVar4 != 0)) || ((uVar1 == 0xff && (uVar3 != 0)))) {
    return 0xfffffffe;
  }
  if (uVar2 == 0) {
    if ((uVar1 == 0) && (uVar3 == 0)) {
      if (uVar4 == 0) {
        return 0;
      }
      goto LAB_1004ae2e;
    }
    if (uVar4 == 0) {
      return -(uint)(-1 < (int)param_2) | 1;
    }
  }
  else if ((uVar1 == 0) && (uVar3 == 0)) goto LAB_1004ae2e;
  if (((int)param_2 >> 0x1f == (int)param_1 >> 0x1f) && (uVar2 <= uVar1)) {
    if (uVar1 <= uVar2) {
      if (uVar3 < uVar4) goto LAB_1004ae2e;
      if (uVar3 <= uVar4) {
        return 0;
      }
    }
    return -(uint)(-1 < (int)param_1) | 1;
  }
LAB_1004ae2e:
  return (int)param_1 >> 0x1f | 1;
}

// FUNC 0x1004aefc  reset_handler

/* Copies init image 0x10059118 -> 0x20000800, then calls system_init and main */

void reset_handler(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *puRam1004af68 = 4;
  for (iVar1 = 0; (uint)(iRam1004af70 + iVar1) < uRam1004af74; iVar1 = iVar1 + 4) {
    *(undefined4 *)(iRam1004af70 + iVar1) = *(undefined4 *)(iRam1004af6c + iVar1);
  }
  for (iVar1 = 0; puVar3 = puRam1004af84, (uint)(iRam1004af7c + iVar1) < uRam1004af80;
      iVar1 = iVar1 + 4) {
    *(undefined4 *)(iRam1004af7c + iVar1) = *(undefined4 *)(iRam1004af78 + iVar1);
  }
  for (; puVar2 = puRam1004af8c, puVar3 < puRam1004af88; puVar3 = puVar3 + 1) {
    *puVar3 = 0;
  }
  for (; puVar3 = puRam1004af94, puVar2 < puRam1004af90; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  for (; puVar3 < puRam1004af9c; puVar3 = puVar3 + 1) {
    *puVar3 = uRam1004af98;
  }
  system_init();
  func_0x10056ec8();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x1004afa0  FUN_1004afa0

void FUN_1004afa0(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x1004afa2  FUN_1004afa2

void FUN_1004afa2(int param_1)

{
  for (; param_1 != 0; param_1 = param_1 + -1) {
  }
  return;
}

// FUNC 0x1004afb0  FUN_1004afb0

void FUN_1004afb0(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_c;
  
  iVar1 = FUN_10056d58(*DAT_1004b000,DAT_1004b004);
  uVar2 = FUN_10056d58(iVar1 * param_1,0x11);
  if (uVar2 < 0xc) {
    local_c = 0;
  }
  else {
    local_c = uVar2 - 0xc;
  }
  for (; local_c != 0; local_c = local_c + -1) {
  }
  return;
}

// FUNC 0x1004b008  system_init

void system_init(void)

{
  *puRam1004b020 = 1;
  *puRam1004b024 = 2;
  *puRam1004b028 = 2;
  func_0x1004c794();
  return;
}

// FUNC 0x1004b02c  FUN_1004b02c

void FUN_1004b02c(void)

{
  return;
}

// FUNC 0x1004b02e  FUN_1004b02e

void FUN_1004b02e(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 int param_6,uint param_7,uint param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_3;
  iVar3 = param_6;
  iVar4 = param_3;
  if ((param_8 & 3) == 0) {
    for (; (uint)(iVar2 + (param_6 - param_3)) < param_7; iVar2 = iVar2 + 1) {
      (*param_1)(0x20,param_2,iVar2,param_4,param_2,param_4,iVar4);
    }
  }
  while( true ) {
    iVar1 = param_6 + iVar2;
    if (iVar3 == 0) break;
    (*param_1)(*(undefined1 *)(param_5 + iVar3 + -1),param_2,iVar1 - iVar3,param_4,param_2,param_4,
               iVar4);
    iVar3 = iVar3 + -1;
  }
  if ((int)(param_8 << 0x1e) < 0) {
    for (; (uint)(iVar1 - param_3) < param_7; iVar1 = iVar1 + 1) {
      (*param_1)(0x20,param_2,iVar1,param_4,param_2,param_4,iVar4);
    }
  }
  return;
}

// FUNC 0x1004b098  FUN_1004b098

void FUN_1004b098(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,uint param_6,char param_7,int param_8,uint param_9,uint param_10,
                 uint param_11)

{
  undefined1 uVar1;
  uint uVar2;
  
  if (-1 < (int)(param_11 << 0x1e)) {
    if (((param_10 != 0) && ((int)(param_11 << 0x1f) < 0)) &&
       ((param_7 != '\0' || ((param_11 & 0xc) != 0)))) {
      param_10 = param_10 - 1;
    }
    for (; (param_6 < param_9 && (param_6 < 0x20)); param_6 = param_6 + 1) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
    }
    for (; (((param_11 & 1) != 0 && (param_6 < param_10)) && (param_6 < 0x20));
        param_6 = param_6 + 1) {
      *(undefined1 *)(param_5 + param_6) = 0x30;
    }
  }
  if ((int)(param_11 << 0x1b) < 0) {
    uVar2 = param_6;
    if (((((int)(param_11 << 0x15) < 0) || (param_6 == 0)) ||
        ((param_6 != param_9 && (param_6 != param_10)))) || (uVar2 = param_6 - 1, uVar2 == 0)) {
      param_6 = uVar2;
      if (param_8 == 0x10) goto LAB_1004b120;
LAB_1004b136:
      if (param_8 == 2) {
        param_6 = uVar2;
        if (0x1f < uVar2) goto LAB_1004b170;
        uVar1 = 0x62;
        goto LAB_1004b142;
      }
    }
    else {
      param_6 = param_6 - 2;
      if (param_8 != 0x10) goto LAB_1004b136;
LAB_1004b120:
      if ((int)(param_11 << 0x1a) < 0) {
        uVar1 = 0x58;
      }
      else {
        uVar1 = 0x78;
      }
      uVar2 = param_6;
      if (0x1f < param_6) goto LAB_1004b170;
LAB_1004b142:
      *(undefined1 *)(param_5 + uVar2) = uVar1;
      uVar2 = uVar2 + 1;
    }
    param_6 = uVar2;
    if (0x1f < uVar2) goto LAB_1004b170;
    *(undefined1 *)(param_5 + uVar2) = 0x30;
    param_6 = uVar2 + 1;
  }
  if (param_6 < 0x20) {
    if (param_7 == '\0') {
      if ((int)(param_11 << 0x1d) < 0) {
        uVar1 = 0x2b;
      }
      else {
        if (-1 < (int)(param_11 << 0x1c)) goto LAB_1004b170;
        uVar1 = 0x20;
      }
    }
    else {
      uVar1 = 0x2d;
    }
    *(undefined1 *)(param_5 + param_6) = uVar1;
    param_6 = param_6 + 1;
  }
LAB_1004b170:
  FUN_1004b02e(param_1,param_2,param_3,param_4,param_5,param_6,param_10,param_11);
  return;
}

// FUNC 0x1004b184  FUN_1004b184

void FUN_1004b184(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined1 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,uint param_10)

{
  char cVar1;
  byte extraout_r1;
  char cVar2;
  int iVar3;
  int iVar4;
  char local_38 [36];
  
  if (param_5 == 0) {
    param_10 = param_10 & 0xffffffef;
  }
  if ((-1 < (int)(param_10 << 0x15)) || (iVar3 = 0, param_5 != 0)) {
    cVar2 = 'a';
    if ((int)(param_10 << 0x1a) < 0) {
      cVar2 = 'A';
    }
    iVar4 = 0;
    do {
      FUN_10056d68(param_5,param_7);
      iVar3 = iVar4 + 1;
      cVar1 = cVar2 + -10;
      if (extraout_r1 < 10) {
        cVar1 = '0';
      }
      local_38[iVar4] = extraout_r1 + cVar1;
      param_5 = FUN_10056d58(param_5,param_7);
    } while ((param_5 != 0) && (iVar4 = iVar3, iVar3 != 0x20));
  }
  FUN_1004b098(param_1,param_2,param_3,param_4,local_38,iVar3,param_6,param_7,param_8,param_9,
               param_10);
  return;
}

// FUNC 0x1004b218  FUN_1004b218

void FUN_1004b218(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6,undefined1 param_7,undefined4 param_8,uint param_9,
                 undefined4 param_10,undefined4 param_11,undefined4 param_12,uint param_13)

{
  char cVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  char local_38 [36];
  
  lVar7 = CONCAT44(param_6,param_5);
  if (param_5 == 0 && param_6 == 0) {
    param_13 = param_13 & 0xffffffef;
  }
  if ((-1 < (int)(param_13 << 0x15)) || (iVar5 = 0, param_5 != 0 || param_6 != 0)) {
    cVar3 = 'a';
    if ((int)(param_13 << 0x1a) < 0) {
      cVar3 = 'A';
    }
    iVar6 = 0;
    do {
      uVar4 = (undefined4)((ulonglong)lVar7 >> 0x20);
      uVar2 = param_9;
      FUN_100481e4((int)lVar7,uVar4,param_9,param_10);
      cVar1 = (char)uVar2 + cVar3 + -10;
      iVar5 = iVar6 + 1;
      if ((uVar2 & 0xff) < 10) {
        cVar1 = (char)uVar2 + '0';
      }
      local_38[iVar6] = cVar1;
      lVar7 = FUN_100481e4((int)lVar7,uVar4,param_9,param_10);
    } while ((lVar7 != 0) && (iVar6 = iVar5, iVar5 != 0x20));
  }
  FUN_1004b098(param_1,param_2,param_3,param_4,local_38,iVar5,param_7,param_9,param_11,param_12,
               param_13);
  return;
}

// FUNC 0x1004b2d0  uart_putc_indexed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Writes one byte to UART0..3 selected by the first argument */

void uart_putc_indexed(int param_1)

{
  char cVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    cVar1 = *DAT_1004b328;
    if (cVar1 == '\0') {
      do {
      } while ((_DAT_40000018 & 0x20) != 0);
      piVar2 = (int *)&DAT_40000000;
    }
    else if (cVar1 == '\x01') {
      do {
        piVar2 = DAT_1004b32c;
      } while ((DAT_1004b32c[6] & 0x20U) != 0);
    }
    else if (cVar1 == '\x02') {
      do {
        piVar2 = DAT_1004b330;
      } while ((DAT_1004b330[6] & 0x20U) != 0);
    }
    else {
      if (cVar1 != '\x03') {
        return;
      }
      do {
        piVar2 = DAT_1004b334;
      } while ((DAT_1004b334[6] & 0x20U) != 0);
    }
    *piVar2 = param_1;
  }
  return;
}

// FUNC 0x1004b338  FUN_1004b338

void FUN_1004b338(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,uint param_7,uint param_8,uint param_9)

{
  int iVar1;
  int iVar2;
  char extraout_r1;
  char extraout_r1_00;
  undefined4 uVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  char *pcVar12;
  uint uVar13;
  uint local_58;
  char local_38 [36];
  
  uVar10 = CONCAT44(param_6,param_5);
  iVar1 = FUN_10048188(param_5,param_6);
  if (iVar1 == 0) {
    uVar13 = 3;
    pcVar12 = DAT_1004b610;
    goto LAB_1004b5f4;
  }
  iVar1 = FUN_10048194(param_5,param_6,0xffffffff,DAT_1004b614);
  if (iVar1 != 0) {
    uVar13 = 4;
    pcVar12 = DAT_1004b618;
    goto LAB_1004b5f4;
  }
  iVar1 = FUN_100481bc(param_5,param_6,0xffffffff,DAT_1004b61c);
  if (iVar1 != 0) {
    uVar13 = 4;
    pcVar12 = DAT_1004b620;
    if ((param_9 & 4) == 0) {
      uVar13 = 3;
      pcVar12 = DAT_1004b624;
    }
    goto LAB_1004b5f4;
  }
  iVar1 = FUN_100481bc(param_5,param_6,0,DAT_1004b628);
  if ((iVar1 != 0) || (iVar1 = FUN_10048194(param_5,param_6,0,DAT_1004b62c), iVar1 != 0)) {
    FUN_1004b638(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    return;
  }
  iVar1 = FUN_10048194(param_5,param_6,0,0);
  bVar9 = iVar1 != 0;
  if (bVar9) {
    uVar10 = FUN_1004a348(0,0,param_5,param_6);
  }
  param_6 = (undefined4)((ulonglong)uVar10 >> 0x20);
  param_5 = (undefined4)uVar10;
  if (-1 < (int)(param_9 << 0x15)) {
    param_7 = 6;
  }
  uVar8 = 0;
  do {
    if (param_7 < 10) break;
    local_38[uVar8] = '0';
    uVar8 = uVar8 + 1;
    param_7 = param_7 - 1;
  } while (uVar8 != 0x20);
  local_58 = FUN_1004a9f0(param_5,param_6);
  puVar5 = (undefined4 *)(DAT_1004b630 + param_7 * 8);
  uVar7 = puVar5[1];
  uVar6 = *puVar5;
  uVar10 = FUN_1004aa5c();
  uVar10 = FUN_1004a348(param_5,param_6,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
  uVar10 = FUN_10049e54((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar6,uVar7);
  iVar2 = FUN_10048254();
  uVar11 = FUN_1004aae0();
  uVar10 = FUN_1004a348((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                        (int)((ulonglong)uVar11 >> 0x20));
  uVar3 = (undefined4)((ulonglong)uVar10 >> 0x20);
  iVar1 = FUN_100481bc((int)uVar10,uVar3,0,DAT_1004b634);
  if (iVar1 == 0) {
    iVar1 = FUN_10048194((int)uVar10,uVar3,0,DAT_1004b634);
    if ((iVar1 == 0) && ((iVar2 == 0 || (iVar2 << 0x1f < 0)))) {
      iVar2 = iVar2 + 1;
    }
  }
  else {
    iVar2 = iVar2 + 1;
    uVar10 = FUN_1004aae0(iVar2);
    iVar1 = FUN_100481a8(uVar6,uVar7,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    if (iVar1 != 0) {
      iVar2 = 0;
      local_58 = local_58 + 1;
    }
  }
  if (param_7 == 0) {
    uVar10 = FUN_1004aa5c(local_58);
    uVar10 = FUN_1004a348(param_5,param_6,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    uVar3 = (undefined4)((ulonglong)uVar10 >> 0x20);
    iVar1 = FUN_10048194((int)uVar10,uVar3,0,DAT_1004b634);
    if ((iVar1 == 0) || (iVar1 = FUN_100481bc((int)uVar10,uVar3,0,DAT_1004b634), iVar1 != 0)) {
      local_58 = local_58 + (local_58 & 1);
    }
LAB_1004b584:
    do {
      if (uVar8 == 0x20) goto LAB_1004b588;
      uVar13 = uVar8 + 1;
      FUN_10056ed8(local_58,10);
      local_38[uVar8] = extraout_r1_00 + '0';
      local_58 = FUN_10056e98(local_58,10);
      uVar8 = uVar13;
    } while (local_58 != 0);
  }
  else {
    do {
      if (uVar8 == 0x20) goto LAB_1004b588;
      param_7 = param_7 - 1;
      uVar13 = uVar8 + 1;
      FUN_10056d68(iVar2,10);
      local_38[uVar8] = extraout_r1 + '0';
      iVar2 = FUN_10056d58(iVar2,10);
      uVar8 = uVar13;
    } while (iVar2 != 0);
    param_7 = param_7 + uVar13;
    for (; uVar13 != 0x20; uVar13 = uVar13 + 1) {
      if (param_7 == uVar13) {
        local_38[param_7] = '.';
        uVar8 = param_7 + 1;
        goto LAB_1004b584;
      }
      local_38[uVar13] = '0';
    }
LAB_1004b588:
    uVar13 = 0x20;
  }
  if (((param_9 & 3) == 1) && (param_8 != 0)) {
    if ((bVar9) || ((param_9 & 0xc) != 0)) {
      param_8 = param_8 - 1;
    }
    for (; uVar13 < param_8; uVar13 = uVar13 + 1) {
      if (uVar13 == 0x20) goto LAB_1004b5e6;
      local_38[uVar13] = '0';
    }
  }
  if (uVar13 < 0x20) {
    if (bVar9) {
      cVar4 = '-';
    }
    else if ((int)(param_9 << 0x1d) < 0) {
      cVar4 = '+';
    }
    else {
      if (-1 < (int)(param_9 << 0x1c)) goto LAB_1004b5e6;
      cVar4 = ' ';
    }
    local_38[uVar13] = cVar4;
    uVar13 = uVar13 + 1;
  }
LAB_1004b5e6:
  pcVar12 = local_38;
LAB_1004b5f4:
  FUN_1004b02e(param_1,param_2,param_3,param_4,pcVar12,uVar13,param_8,param_9);
  return;
}

// FUNC 0x1004b638  FUN_1004b638

int FUN_1004b638(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                uint param_6,int param_7,uint param_8,uint param_9)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  int local_4c;
  undefined4 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar1 = FUN_10048188(param_5,param_6,param_5,param_6);
  if (((iVar1 == 0) || (iVar1 = FUN_100481bc(param_5,param_6,0xffffffff,DAT_1004b978), iVar1 != 0))
     || (iVar1 = FUN_10048194(param_5,param_6,0xffffffff,DAT_1004b97c), iVar1 != 0)) {
    iVar1 = FUN_1004b338(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  else {
    iVar1 = FUN_10048194(param_5,param_6,0,0);
    uVar7 = param_6;
    if (iVar1 != 0) {
      uVar7 = param_6 + 0x80000000;
    }
    uVar13 = CONCAT44(uVar7,param_5);
    if ((param_9 & 0x400) == 0) {
      param_7 = 6;
    }
    uVar10 = FUN_1004aa5c(((uVar7 << 1) >> 0x15) + DAT_1004b980);
    uVar10 = FUN_10049e54((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_1004b984,DAT_1004b988);
    uVar10 = FUN_10048fb4((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_1004b98c,DAT_1004b990);
    uVar11 = FUN_1004a348(param_5,DAT_1004b994 | uVar7 & 0xfffff,0,DAT_1004b998);
    uVar11 = FUN_10049e54((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_1004b99c,DAT_1004b9a0);
    FUN_10048fb4((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                 (int)((ulonglong)uVar11 >> 0x20));
    uVar2 = FUN_1004a9f0();
    uVar10 = FUN_1004aa5c();
    uVar4 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar11 = FUN_10049e54((int)uVar10,uVar4,DAT_1004b9a4,DAT_1004b9a8);
    FUN_10048fb4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_1004b9ac);
    iVar1 = FUN_1004a9f0();
    uVar10 = FUN_10049e54((int)uVar10,uVar4,DAT_1004b9b0,DAT_1004b9b4);
    uVar11 = FUN_1004aa5c(iVar1);
    uVar11 = FUN_10049e54((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_1004b9b8,DAT_1004b9bc);
    uVar10 = FUN_1004a348((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                          (int)((ulonglong)uVar11 >> 0x20));
    uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar4 = (undefined4)uVar10;
    uVar10 = FUN_10049e54(uVar4,uVar5,uVar4,uVar5);
    uVar6 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar3 = (undefined4)uVar10;
    uVar10 = FUN_10048fb4(uVar4,uVar5);
    uVar11 = FUN_1004960c(uVar3,uVar6,0,DAT_1004b9c0);
    uVar11 = FUN_10048fb4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_1004b9c4);
    uVar11 = FUN_1004960c(uVar3,uVar6,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
    uVar11 = FUN_10048fb4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_1004b9c8);
    uVar11 = FUN_1004960c(uVar3,uVar6,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
    uVar12 = FUN_1004a348(0,0x40000000,uVar4,uVar5);
    uVar11 = FUN_10048fb4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                          (int)((ulonglong)uVar12 >> 0x20));
    uVar10 = FUN_1004960c((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,
                          (int)((ulonglong)uVar11 >> 0x20));
    uVar10 = FUN_10048fb4((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,DAT_1004b994);
    uVar10 = FUN_10049e54((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,
                          (iVar1 + DAT_1004b9cc) * 0x100000);
    uVar4 = (undefined4)((ulonglong)uVar10 >> 0x20);
    iVar1 = FUN_10048194(param_5,uVar7,(int)uVar10,uVar4);
    if (iVar1 != 0) {
      uVar10 = FUN_1004960c((int)uVar10,uVar4,0,DAT_1004b9c4);
      uVar2 = uVar2 - 1;
    }
    local_2c = (undefined4)((ulonglong)uVar10 >> 0x20);
    local_30 = (undefined4)uVar10;
    uVar8 = 5 - (uVar2 + 99 < 199);
    if ((int)(param_9 << 0x14) < 0) {
      iVar1 = FUN_100481d0(param_5,uVar7,DAT_1004b9d0,DAT_1004b9d4);
      if ((iVar1 == 0) || (iVar1 = FUN_10048194(param_5,uVar7,0,DAT_1004b9d8), iVar1 == 0)) {
        if (param_7 != 0) {
          param_7 = param_7 - (uint)((param_9 & 0x400) != 0);
        }
      }
      else {
        if ((int)uVar2 < param_7) {
          param_7 = (param_7 - uVar2) + -1;
        }
        else {
          param_7 = 0;
        }
        uVar8 = 0;
        param_9 = param_9 | 0x400;
        uVar2 = 0;
      }
    }
    uVar9 = 0;
    if (uVar8 < param_8) {
      uVar9 = param_8 - uVar8;
    }
    if ((param_9 & 2) != 0) {
      uVar9 = uVar9 & -(uint)(uVar8 == 0);
    }
    if (uVar2 != 0) {
      uVar13 = FUN_1004960c(param_5,uVar7,local_30,local_2c);
    }
    local_4c = (int)((ulonglong)uVar13 >> 0x20);
    local_40 = (undefined4)uVar13;
    iVar1 = FUN_10048194(param_5,param_6,0,0);
    if (iVar1 != 0) {
      local_4c = local_4c + -0x80000000;
    }
    iVar1 = FUN_1004b338(param_1,param_2,param_3,param_4,local_40,local_4c,param_7,uVar9,
                         DAT_1004b9dc & param_9);
    if (uVar8 != 0) {
      uVar4 = 0x45;
      if (-1 < (int)(param_9 << 0x1a)) {
        uVar4 = 0x65;
      }
      (*param_1)(uVar4,param_2,iVar1,param_4);
      iVar1 = FUN_1004b184(param_1,param_2,iVar1 + 1,param_4,
                           uVar2 + ((int)uVar2 >> 0x1f) ^ (int)uVar2 >> 0x1f,uVar2 >> 0x1f,10,0,
                           uVar8 - 1,5);
      if ((param_9 & 2) != 0) {
        for (; (uint)(iVar1 - param_3) < param_8; iVar1 = iVar1 + 1) {
          (*param_1)(0x20,param_2,iVar1,param_4);
        }
      }
    }
  }
  return iVar1;
}

// FUNC 0x1004b9e0  FUN_1004b9e0

uint FUN_1004b9e0(code *param_1,int param_2,uint param_3,byte *param_4,uint *param_5)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  char *pcVar10;
  uint *puVar11;
  uint uVar12;
  byte *local_54;
  code *local_4c;
  uint local_44;
  uint *local_40;
  char *local_3c;
  
  local_4c = param_1;
  if (param_2 == 0) {
    local_4c = DAT_1004bccc;
  }
  puVar11 = (uint *)0;
LAB_1004b9f8:
  do {
    while( true ) {
      bVar1 = *param_4;
      if (bVar1 == 0) {
        uVar8 = (uint)puVar11;
        if (param_3 <= puVar11) {
          uVar8 = param_3 - 1;
        }
        (*local_4c)(0,param_2,uVar8,param_3);
        return (uint)puVar11;
      }
      if (bVar1 == 0x25) break;
      (*local_4c)(bVar1,param_2,puVar11,param_3);
LAB_1004ba9c:
      puVar11 = (uint *)((int)puVar11 + 1);
LAB_1004ba9e:
      param_4 = param_4 + 1;
    }
    param_4 = param_4 + 2;
    uVar8 = 0;
LAB_1004ba18:
    pbVar4 = param_4 + -1;
    uVar2 = (uint)*pbVar4;
    if (uVar2 == 0x2b) {
      uVar2 = 4;
LAB_1004ba46:
      uVar8 = uVar8 | uVar2;
LAB_1004bab0:
      param_4 = param_4 + 1;
      goto LAB_1004ba18;
    }
    if (0x2b < uVar2) {
      if (uVar2 == 0x2d) {
        uVar2 = 2;
        goto LAB_1004ba46;
      }
      if (uVar2 != 0x30) goto LAB_1004bab4;
      uVar8 = uVar8 | 1;
      goto LAB_1004bab0;
    }
    if (uVar2 == 0x20) {
      uVar8 = uVar8 | 8;
      goto LAB_1004bab0;
    }
    if (uVar2 == 0x23) {
      uVar2 = 0x10;
      goto LAB_1004ba46;
    }
LAB_1004bab4:
    local_40 = param_5;
    if (uVar2 - 0x30 < 10) {
      local_44 = 0;
      for (; *pbVar4 - 0x30 < 10; pbVar4 = pbVar4 + 1) {
        local_44 = (uint)*pbVar4 + local_44 * 10 + -0x30;
      }
    }
    else {
      local_44 = 0;
      if (uVar2 == 0x2a) {
        local_44 = *param_5;
        pbVar4 = param_4;
        local_40 = param_5 + 1;
        if ((int)local_44 < 0) {
          uVar8 = uVar8 | 2;
          local_44 = -local_44;
        }
      }
    }
    if (*pbVar4 == 0x2e) {
      uVar8 = uVar8 | 0x400;
      local_54 = pbVar4 + 1;
      uVar2 = 0;
      if (pbVar4[1] - 0x30 < 10) {
        for (; *local_54 - 0x30 < 10; local_54 = local_54 + 1) {
          uVar2 = (uint)*local_54 + uVar2 * 10 + -0x30;
        }
      }
      else if (pbVar4[1] == 0x2a) {
        uVar2 = *local_40;
        local_40 = local_40 + 1;
        uVar2 = uVar2 & (int)~uVar2 >> 0x1f;
        local_54 = pbVar4 + 2;
      }
    }
    else {
      uVar2 = 0;
      local_54 = pbVar4;
    }
    bVar1 = *local_54;
    if (bVar1 == 0x6c) {
      if (local_54[1] != 0x6c) {
LAB_1004bb50:
        uVar5 = 0x100;
        goto LAB_1004bb54;
      }
      uVar5 = 0x300;
LAB_1004bb48:
      local_54 = local_54 + 2;
LAB_1004bb5a:
      uVar8 = uVar8 | uVar5;
    }
    else {
      if (bVar1 < 0x6d) {
        if (bVar1 == 0x68) {
          if (local_54[1] == 0x68) {
            uVar5 = 0xc0;
            goto LAB_1004bb48;
          }
          uVar5 = 0x80;
        }
        else {
          if (bVar1 != 0x6a) goto LAB_1004ba6e;
          uVar5 = 0x200;
        }
LAB_1004bb54:
        local_54 = local_54 + 1;
        goto LAB_1004bb5a;
      }
      if ((bVar1 == 0x74) || (bVar1 == 0x7a)) goto LAB_1004bb50;
    }
LAB_1004ba6e:
    bVar1 = *local_54;
    if (bVar1 == 0x65) goto LAB_1004bd62;
    param_4 = local_54;
    if (bVar1 < 0x66) {
      if (bVar1 != 0x47) {
        if (0x47 < bVar1) {
          if (bVar1 == 0x62) {
            uVar6 = 2;
            goto LAB_1004bbee;
          }
          if (bVar1 < 99) {
            if (bVar1 == 0x58) {
              uVar6 = 0x10;
              uVar8 = uVar8 | 0x20;
              goto LAB_1004bbee;
            }
LAB_1004ba8e:
            (*local_4c)(bVar1,param_2,puVar11,param_3);
            param_5 = local_40;
            goto LAB_1004ba9c;
          }
          if (bVar1 != 99) {
            if (bVar1 == 100) goto LAB_1004bbe0;
            goto LAB_1004ba8e;
          }
          uVar8 = uVar8 & 2;
          local_3c = (char *)0x1;
          uVar2 = uVar8;
          uVar5 = (uint)puVar11;
          if (uVar8 == 0) {
            while( true ) {
              local_3c = (char *)(uVar2 + 2);
              uVar5 = (int)puVar11 + uVar2;
              uVar2 = uVar2 + 1;
              if (local_44 <= uVar2) break;
              (*local_4c)(0x20,param_2,uVar5,param_3);
            }
          }
          param_5 = local_40 + 1;
          (*local_4c)(*local_40 & 0xff,param_2,uVar5,param_3);
          puVar11 = (uint *)(uVar5 + 1);
          if (uVar8 != 0) {
            for (; (int)puVar11 + (((int)local_3c + -1) - uVar5) < local_44;
                puVar11 = (uint *)((int)puVar11 + 1)) {
              (*local_4c)(0x20,param_2,puVar11,param_3);
            }
          }
          goto LAB_1004ba9e;
        }
        if (bVar1 != 0x45) {
          if (0x45 < bVar1) goto LAB_1004bd32;
          goto LAB_1004ba8e;
        }
      }
LAB_1004bd62:
      if ((bVar1 & 0xdf) == 0x47) {
        uVar8 = uVar8 | 0x800;
        bVar1 = bVar1 & 0xfd;
      }
      if (bVar1 == 0x45) {
        uVar8 = uVar8 | 0x20;
      }
      puVar9 = (undefined4 *)((int)local_40 + 7U & 0xfffffff8);
      param_5 = puVar9 + 2;
      puVar11 = (uint *)FUN_1004b638(local_4c,param_2,puVar11,param_3,*puVar9,puVar9[1],uVar2,
                                     local_44,uVar8);
    }
    else {
      if (bVar1 == 0x6f) {
        uVar6 = 8;
        goto LAB_1004bbee;
      }
      if (bVar1 < 0x70) {
        if (bVar1 == 0x67) goto LAB_1004bd62;
        if (0x66 < bVar1) {
          if (bVar1 == 0x69) goto LAB_1004bbe0;
          goto LAB_1004ba8e;
        }
LAB_1004bd32:
        if (bVar1 == 0x46) {
          uVar8 = uVar8 | 0x20;
        }
        puVar9 = (undefined4 *)((int)local_40 + 7U & 0xfffffff8);
        param_5 = puVar9 + 2;
        puVar11 = (uint *)FUN_1004b338(local_4c,param_2,puVar11,param_3,*puVar9,puVar9[1],uVar2,
                                       local_44,uVar8);
      }
      else {
        if (bVar1 == 0x73) {
          param_5 = local_40 + 1;
          local_3c = (char *)*local_40;
          if (local_3c == (char *)0x0) {
            local_3c = DAT_1004bf24;
          }
          uVar5 = uVar2;
          if (uVar2 == 0) {
            uVar5 = 0xffffffff;
          }
          for (pcVar10 = local_3c; (*pcVar10 != '\0' && (pcVar10 != local_3c + uVar5));
              pcVar10 = pcVar10 + 1) {
          }
          uVar5 = (int)pcVar10 - (int)local_3c;
          if (((uVar8 & 0x400) != 0) && (uVar2 < uVar5)) {
            uVar5 = uVar2;
          }
          uVar7 = uVar5;
          local_40 = puVar11;
          uVar12 = (uint)puVar11;
          uVar3 = uVar5;
          if ((uVar8 & 2) == 0) {
            while( true ) {
              uVar3 = uVar7 + 1;
              local_40 = (uint *)(((int)puVar11 - uVar5) + uVar7);
              uVar12 = (uint)local_40;
              if (local_44 <= uVar7) break;
              (*local_4c)(0x20,param_2,local_40,param_3);
              uVar7 = uVar3;
            }
          }
          while ((local_3c[(int)local_40 - uVar12] != '\0' &&
                 ((uVar5 = uVar2, (uVar8 & 0x400) == 0 || (uVar5 = uVar2 - 1, uVar2 != 0))))) {
            (*local_4c)(local_3c[(int)local_40 - uVar12],param_2,local_40,param_3);
            uVar2 = uVar5;
            local_40 = (uint *)((int)local_40 + 1);
          }
          puVar11 = local_40;
          if ((uVar8 & 2) != 0) {
            for (; (int)puVar11 + (uVar3 - (int)local_40) < local_44;
                puVar11 = (uint *)((int)puVar11 + 1)) {
              (*local_4c)(0x20,param_2,puVar11,param_3);
            }
          }
          local_40 = puVar11;
          param_4 = local_54 + 1;
          puVar11 = local_40;
          goto LAB_1004b9f8;
        }
        if (bVar1 < 0x74) {
          if (bVar1 != 0x70) goto LAB_1004ba8e;
          param_5 = local_40 + 1;
          puVar11 = (uint *)FUN_1004b184(local_4c,param_2,puVar11,param_3,*local_40,0,0x10,uVar2,8,
                                         uVar8 | 0x21);
          param_4 = local_54 + 1;
          goto LAB_1004b9f8;
        }
        if (bVar1 == 0x75) {
LAB_1004bbe0:
          uVar6 = 10;
          uVar8 = uVar8 & 0xffffffef;
          if ((bVar1 != 0x69) && (bVar1 != 100)) goto LAB_1004bbee;
        }
        else {
          uVar6 = 0x10;
          if (bVar1 != 0x78) goto LAB_1004ba8e;
LAB_1004bbee:
          uVar8 = uVar8 & 0xfffffff3;
        }
        if ((int)(uVar8 << 0x15) < 0) {
          uVar8 = uVar8 & 0xfffffffe;
        }
        if ((bVar1 == 0x69) || (bVar1 == 100)) {
          if ((uVar8 & 0x200) != 0) {
            param_5 = (uint *)((int)local_40 + 7U & 0xfffffff8);
            uVar7 = param_5[1];
            uVar8 = uVar7 >> 0x1f;
            uVar5 = (int)uVar7 >> 0x1f;
            uVar2 = (uVar5 ^ *param_5) - uVar5;
            uVar5 = ((uVar5 ^ uVar7) - uVar5) - (uint)((uVar5 ^ *param_5) < uVar5);
LAB_1004bcbc:
            param_5 = param_5 + 2;
            puVar11 = (uint *)FUN_1004b218(local_4c,param_2,puVar11,param_3,uVar2,uVar5,uVar8);
            goto LAB_1004bd2c;
          }
          if (-1 < (int)(uVar8 << 0x17)) {
            if ((int)(uVar8 << 0x19) < 0) {
              uVar5 = *local_40 & 0xff;
            }
            else {
              uVar5 = *local_40;
              if ((int)(uVar8 << 0x18) < 0) {
                uVar5 = (uint)(short)uVar5;
              }
            }
            uVar7 = uVar5 >> 0x1f;
            uVar5 = uVar5 + ((int)uVar5 >> 0x1f) ^ (int)uVar5 >> 0x1f;
LAB_1004bd1c:
            param_5 = local_40 + 1;
            puVar11 = (uint *)FUN_1004b184(local_4c,param_2,puVar11,param_3,uVar5,uVar7,uVar6,uVar2,
                                           local_44,uVar8);
            goto LAB_1004bd2c;
          }
          uVar7 = *local_40;
          uVar5 = uVar7 >> 0x1f;
          uVar7 = uVar7 + ((int)uVar7 >> 0x1f) ^ (int)uVar7 >> 0x1f;
        }
        else {
          if ((uVar8 & 0x200) != 0) {
            param_5 = (uint *)((int)local_40 + 7U & 0xfffffff8);
            uVar8 = 0;
            uVar5 = param_5[1];
            uVar2 = *param_5;
            goto LAB_1004bcbc;
          }
          if (-1 < (int)(uVar8 << 0x17)) {
            if ((int)(uVar8 << 0x19) < 0) {
              uVar5 = *local_40 & 0xff;
            }
            else {
              uVar5 = *local_40;
              if ((int)(uVar8 << 0x18) < 0) {
                uVar5 = uVar5 & 0xffff;
              }
            }
            uVar7 = 0;
            goto LAB_1004bd1c;
          }
          uVar7 = *local_40;
          uVar5 = 0;
        }
        local_40 = local_40 + 1;
        puVar11 = (uint *)FUN_1004b184(local_4c,param_2,puVar11,param_3,uVar7,uVar5,uVar6,uVar2,
                                       local_44,uVar8);
        param_5 = local_40;
      }
    }
LAB_1004bd2c:
    param_4 = local_54 + 1;
  } while( true );
}

// FUNC 0x1004bf28  log_printf

/* Formatted log output; used for IND DATA SEND and boot messages */

void log_printf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_20;
  undefined4 *local_1c;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_1c = &uStack_c;
  uStack_20 = param_3;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_1004b9e0(DAT_1004bf48,&uStack_20,0xffffffff,param_1,local_1c,param_2);
  return;
}

// FUNC 0x1004c0a4  FUN_1004c0a4

void FUN_1004c0a4(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)getMainStackPointer();
  log_printf(DAT_1004c0fc);
  log_printf(DAT_1004c100,*puVar1);
  log_printf(DAT_1004c104,puVar1[1]);
  log_printf(DAT_1004c108,puVar1[2]);
  log_printf(DAT_1004c10c,puVar1[3]);
  log_printf(DAT_1004c110,puVar1[4]);
  log_printf(DAT_1004c114,puVar1[5]);
  log_printf(DAT_1004c118,puVar1[6]);
  log_printf(DAT_1004c11c,puVar1[7]);
  software_bkpt(1);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x1004c120  FUN_1004c120

void FUN_1004c120(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_1004c134;
  uVar2 = 1 << (param_1 & 0xff);
  *DAT_1004c134 = *DAT_1004c134 | uVar2;
  *puVar1 = *puVar1 & ~uVar2;
  return;
}

// FUNC 0x1004c4ac  irq_dispatch_32

/* Scans 32 pending IRQ bits and calls the registered handler for the first one */

void irq_dispatch_32(void)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = *DAT_1004c4e0;
  do {
    if ((uVar3 & 1 << (uVar2 & 0xff)) != 0) {
      FUN_1004c120(uVar2);
      pcVar1 = *(code **)(uVar2 * 8 + DAT_1004c4e4);
      if (pcVar1 != (code *)0x0) {
        (*pcVar1)(*(undefined4 *)(DAT_1004c4e4 + uVar2 * 8 + 4));
        return;
      }
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0x20);
  return;
}

// FUNC 0x1004c4e8  uart_irq_dispatch

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Per-UART interrupt dispatch: drains RX and calls the registered byte callback */

void uart_irq_dispatch(uint param_1)

{
  code *pcVar1;
  uint *puVar2;
  
  if (param_1 < 4) {
    puVar2 = *(uint **)(param_1 * 4 + DAT_1004c53c);
    if (((int)(puVar2[0x10] << 0x1b) < 0) || ((int)(puVar2[0x10] << 0x19) < 0)) {
      puVar2[0xe] = puVar2[0xe] & 0xffffffaf;
      puVar2[0x11] = puVar2[0x11] | 0x50;
      while ((puVar2[6] & 0x10) == 0) {
        pcVar1 = *(code **)(DAT_1004c540 + param_1 * 4);
        if (pcVar1 != (code *)0x0) {
          (*pcVar1)(*puVar2 & 0xff);
        }
      }
      puVar2[0xe] = puVar2[0xe] | 0x50;
    }
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0x1004c536);
  (*pcVar1)();
}

// FUNC 0x1004c544  uart_apply_baud

void uart_apply_baud(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0x1c200;
  *(undefined1 *)(param_1 + 8) = 3;
  *(undefined1 *)(param_1 + 9) = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 0xc) = 3;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

// FUNC 0x1004c55c  uart_baud_divider

/* Converts a baud rate to the divisor written to the UART */

uint uart_baud_divider(int param_1)

{
  uint uVar1;
  int iVar2;
  int extraout_r1;
  uint uVar3;
  uint uVar4;
  
  uVar1 = 0;
  uVar3 = *DAT_1004c59c;
  if ((param_1 != 0) && (uVar4 = param_1 << 4, uVar4 <= uVar3)) {
    FUN_10056d68(uVar3,uVar4);
    uVar1 = FUN_10056d58(extraout_r1 << 3,param_1);
    iVar2 = FUN_10056d58(uVar3,uVar4);
    uVar1 = iVar2 << 0x10 | (uVar1 >> 1) + (uVar1 & 1) & 0xffff;
  }
  return uVar1;
}

// FUNC 0x1004c5a0  uart_enable

void uart_enable(undefined1 param_1)

{
  *DAT_1004c5a8 = param_1;
  return;
}

// FUNC 0x1004c5ac  uart_putc

void uart_putc(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    do {
    } while ((param_1[6] & 0x20) != 0);
    *param_1 = param_2;
  }
  return;
}

// FUNC 0x1004c5bc  uart_set_config

void uart_set_config(int param_1,uint param_2,int param_3)

{
  if (param_3 == 0) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & ~param_2;
  }
  else {
    *(uint *)(param_1 + 0x38) = param_2 | *(uint *)(param_1 + 0x38);
  }
  return;
}

// FUNC 0x1004c5ce  uart_nvic_priority

undefined4 uart_nvic_priority(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xffffffc7;
  *(uint *)(param_1 + 0x34) = param_2 << 3 | *(uint *)(param_1 + 0x34);
  return 0;
}

// FUNC 0x1004c5e4  uart_irq_enable

undefined4 uart_irq_enable(char *param_1,uint param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *param_1;
  if (cVar1 == '\0') {
    iVar2 = 0x40000000;
  }
  else {
    iVar2 = DAT_1004c628;
    if (((cVar1 != '\x01') && (iVar2 = DAT_1004c62c, cVar1 != '\x02')) &&
       (iVar2 = DAT_1004c624, cVar1 != '\x03')) {
      return 0xffffffff;
    }
  }
  if (param_3 == 1) {
    *(uint *)(iVar2 + 0x48) = param_2 | *(uint *)(iVar2 + 0x48);
  }
  else {
    *(uint *)(iVar2 + 0x48) = *(uint *)(iVar2 + 0x48) & ~param_2;
  }
  return 0;
}

// FUNC 0x1004c630  uart_init

/* uart_init(struct: index, baud, parity, stop) */

undefined4 uart_init(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  bVar1 = *param_1;
  if (bVar1 == 0) {
    iVar6 = 0x40000000;
  }
  else {
    iVar6 = DAT_1004c74c;
    if (((bVar1 != 1) && (iVar6 = DAT_1004c750, bVar1 != 2)) && (iVar6 = DAT_1004c748, bVar1 != 3))
    {
      return 0xffffffff;
    }
  }
  do {
  } while ((*(uint *)(iVar6 + 0x18) & 8) != 0);
  *(undefined4 *)(iVar6 + 0x38) = 0;
  *(undefined4 *)(iVar6 + 0x30) = 0;
  *(undefined4 *)(iVar6 + 0x2c) = 0;
  uVar2 = *(undefined4 *)(param_1 + 4);
  *(uint *)(iVar6 + 0x48) = *(uint *)(iVar6 + 0x48) & 0xfffffffc;
  uVar3 = uart_baud_divider(uVar2);
  *(uint *)(iVar6 + 0x24) = uVar3 >> 0x10;
  *(uint *)(iVar6 + 0x28) = uVar3 & 0x3f;
  *(uint *)(iVar6 + 0x2c) = (uint)param_1[8] << 5 | (uint)param_1[10] << 3 | *(uint *)(iVar6 + 0x2c)
  ;
  bVar1 = param_1[9];
  if (bVar1 == 1) {
    *(uint *)(iVar6 + 0x2c) = *(uint *)(iVar6 + 0x2c) & 0xfffffff9;
    uVar3 = *(uint *)(iVar6 + 0x2c);
    uVar5 = 2;
LAB_1004c6ac:
    uVar3 = uVar3 | uVar5;
  }
  else {
    if (bVar1 != 0) {
      if (bVar1 != 2) goto LAB_1004c6bc;
      uVar5 = 6;
      uVar3 = *(uint *)(iVar6 + 0x2c);
      goto LAB_1004c6ac;
    }
    uVar3 = *(uint *)(iVar6 + 0x2c) & 0xfffffffd;
  }
  *(uint *)(iVar6 + 0x2c) = uVar3;
LAB_1004c6bc:
  if (param_1[0xc] == 0) {
    param_1[0xc] = 3;
  }
  *(uint *)(iVar6 + 0x30) = DAT_1004c754 & *(uint *)(iVar6 + 0x30);
  uVar2 = 0x10;
  *(uint *)(iVar6 + 0x30) =
       (uint)param_1[0xb] << 0xe | (uint)param_1[0xc] << 8 | *(uint *)(iVar6 + 0x30);
  *(uint *)(iVar6 + 0x2c) = *(uint *)(iVar6 + 0x2c) | 0x10;
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) & 0xfffffff8;
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) | 2;
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) & 0xffffffc7;
  iVar4 = *(int *)(param_1 + 0x10);
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) | 0x10;
  if (iVar4 != 0) {
    *(uint *)(iVar6 + 0x38) = *(uint *)(iVar6 + 0x38) | 0x50;
    if (iVar6 == 0x40000000) {
      uVar2 = 8;
    }
    else if (iVar6 == DAT_1004c74c) {
      uVar2 = 4;
    }
    else if (iVar6 != DAT_1004c750) {
      uVar2 = 0x20;
    }
    *DAT_1004c758 = uVar2;
    *(int *)((uint)*param_1 * 4 + DAT_1004c75c) = iVar4;
  }
  *(uint *)(iVar6 + 0x30) = *(uint *)(iVar6 + 0x30) | 1;
  return 0;
}

// FUNC 0x1004c760  FUN_1004c760

void FUN_1004c760(void)

{
  uart_irq_dispatch(0);
  return;
}

// FUNC 0x1004c76a  FUN_1004c76a

void FUN_1004c76a(void)

{
  uart_irq_dispatch(1);
  return;
}

// FUNC 0x1004c774  FUN_1004c774

void FUN_1004c774(void)

{
  uart_irq_dispatch(2);
  return;
}

// FUNC 0x1004c77e  FUN_1004c77e

void FUN_1004c77e(void)

{
  uart_irq_dispatch(3);
  return;
}

// FUNC 0x1004c788  uart_driver_init

void uart_driver_init(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 * 4 + DAT_1004c790) = param_2;
  return;
}

// FUNC 0x1004c79c  FUN_1004c79c

int FUN_1004c79c(int param_1)

{
  return param_1 * 0x14 + DAT_1004c7a8;
}

// FUNC 0x1004c7ac  FUN_1004c7ac

int FUN_1004c7ac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_1004c7d8;
  iVar3 = 0;
  do {
    iVar2 = iVar3 * 0x14 + iVar1;
    iVar2 = FUN_100480b0(param_1,*(undefined4 *)(iVar2 + 4),param_3,iVar2,param_4);
    if (iVar2 == 0) {
      return (int)(char)iVar3;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x10);
  return -1;
}

// FUNC 0x1004c7dc  FUN_1004c7dc

int FUN_1004c7dc(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_1004c824 + param_1 * 0x14;
  if (*(uint *)(iVar1 + 0xc) < (uint)(param_3 + param_2)) {
    iVar1 = -1;
  }
  else {
    uVar2 = param_2 + *(int *)(iVar1 + 8);
    for (uVar3 = uVar2 & 0xfffff000; uVar3 <= ((param_3 + uVar2) - 1 & 0xfffff000);
        uVar3 = uVar3 + 0x1000) {
      iVar1 = FUN_10056d98(DAT_1004c828,uVar3);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

// FUNC 0x1004c82c  FUN_1004c82c

undefined4 FUN_1004c82c(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = FUN_10056da8();
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    iVar3 = DAT_1004c8c0 + param_1 * 0x14;
    if ((uint)(param_4 + *param_2) <= *(uint *)(iVar3 + 0xc)) {
      uVar2 = *param_2 + *(int *)(iVar3 + 8);
      uVar4 = param_4 + uVar2;
      if (iVar1 != 0) {
        FUN_10056dd8();
      }
      for (iVar3 = param_4; iVar3 != 0; iVar3 = iVar3 - iVar5) {
        iVar5 = iVar3;
        if (uVar2 >> 8 < uVar4 >> 8) {
          iVar5 = 0x100 - (uVar2 & 0xff);
        }
        FUN_10056e28(uVar2,iVar5,param_3);
        param_3 = param_3 + iVar5;
        uVar2 = uVar2 + iVar5;
      }
      if (iVar1 != 0) {
        FUN_10056dc8();
      }
      *param_2 = param_4 + *param_2;
      return 0;
    }
  }
  return 0xffffffff;
}

// FUNC 0x1004c8c4  FUN_1004c8c4

undefined4 FUN_1004c8c4(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    iVar1 = DAT_1004c910 + param_1 * 0x14;
    if (((uint)(*param_2 + param_4) <= *(uint *)(iVar1 + 0xc)) &&
       (DAT_1004c914 < param_3 + 0xf0000000U)) {
      rom_memcpy(param_3,*param_2 + *(int *)(iVar1 + 8),param_4);
      *param_2 = *param_2 + param_4;
      return 0;
    }
  }
  return 0xffffffff;
}

// FUNC 0x1004c918  pinmux_set

/* pinmux_set(pin, class); 4-bit field at 0x40110068..0x40110074 */

void pinmux_set(undefined4 *param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (uint *)((((uint)param_1 >> 3) + DAT_1004ca28) * 4);
  iVar2 = ((uint)param_1 & 7) << 2;
  if (param_2 < 0x19) {
    iVar2 = FUN_10056ee8(param_2);
    *param_1 = 0xd;
                    /* WARNING: Could not recover jumptable at 0x1004c948. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(iVar2 + -0x31);
    return;
  }
  *puVar1 = *puVar1 & ~(0xf << iVar2);
  *puVar1 = 0 << iVar2 | *puVar1;
  return;
}

// FUNC 0x1004ca2c  FUN_1004ca2c

void FUN_1004ca2c(void)

{
  uint uVar1;
  
  uVar1 = syscfg_read(2);
  syscfg_write(2,uVar1 & DAT_1004ca4c);
  FUN_1004afa2(1000);
  return;
}

// FUNC 0x1004ca50  FUN_1004ca50

void FUN_1004ca50(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_1004ca88;
  iVar1 = DAT_1004ca84;
  *(undefined4 *)(DAT_1004ca84 + 0xc) = 5;
  iVar3 = *DAT_1004ca8c;
  uVar2 = FUN_10056d58(iVar3,uVar2);
  *(undefined4 *)(iVar1 + 0x10) = uVar2;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  uVar2 = FUN_10056d58(iVar3 * 6,DAT_1004ca90);
  *(undefined4 *)(iVar1 + 0x18) = uVar2;
  if (param_1 != 0) {
    FUN_1004ca2c();
  }
  return;
}

// FUNC 0x1004ca94  FUN_1004ca94

uint FUN_1004ca94(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_1004cab4;
  *DAT_1004cab4 = 0;
  puVar1[1] = 0;
  puVar1[7] = param_1;
  puVar1[2] = 1;
  puVar2 = DAT_1004cab4;
  do {
  } while (puVar1[0xc] == 0);
  DAT_1004cab4[0xb] = 1;
  return puVar2[9] & 0xff;
}

// FUNC 0x1004cab8  FUN_1004cab8

undefined4 FUN_1004cab8(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_1004cad4;
  *DAT_1004cad4 = 0;
  puVar1[1] = 1;
  puVar1[7] = param_1;
  puVar1[2] = 1;
  puVar2 = DAT_1004cad4;
  do {
  } while (puVar1[0xc] == 0);
  DAT_1004cad4[0xb] = 1;
  return puVar2[9];
}

// FUNC 0x1004cad8  FUN_1004cad8

void FUN_1004cad8(int param_1,uint param_2,int param_3)

{
  undefined1 uVar1;
  uint uVar2;
  
  FUN_1004ca50(0);
  for (uVar2 = 0; (uVar2 & 0xffff) < param_2; uVar2 = uVar2 + 1) {
    uVar1 = FUN_1004ca94(param_1 + uVar2 & 0xff);
    *(undefined1 *)(param_3 + uVar2) = uVar1;
  }
  return;
}

// FUNC 0x1004cb00  syscfg_write

/* Writes a 32-bit value to a SYSCFG register by index */

void syscfg_write(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 * 4 + DAT_1004cb0c) = param_2;
  return;
}

// FUNC 0x1004cb10  syscfg_read

/* Reads a 32-bit SYSCFG register by index */

undefined4 syscfg_read(int param_1)

{
  return *(undefined4 *)(param_1 * 4 + DAT_1004cb1c);
}

// FUNC 0x1004cb20  reg_field_write

/* Writes a bit field: block, shift, width, value */

void reg_field_write(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  
  if ((((param_1 != 0xff) && (param_2 < 0x20)) && (param_3 < 0x21)) &&
     (uVar2 = 1 << (param_3 & 0xff), param_4 < uVar2)) {
    puVar1 = (uint *)(param_1 * 4 + DAT_1004cb50);
    *puVar1 = param_4 << (param_2 & 0xff) | *puVar1 & ~(uVar2 - 1 << (param_2 & 0xff));
  }
  return;
}

// FUNC 0x1004cb54  reg_field_read

/* Reads a bit field: block, shift, width */

uint reg_field_read(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (((param_1 == 0xff) || (0x1f < param_2)) || (0x20 < param_3)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = ((1 << (param_3 & 0xff)) + -1 << (param_2 & 0xff) &
            *(uint *)(param_1 * 4 + DAT_1004cb7c)) >> (param_2 & 0xff);
  }
  return uVar1;
}

// FUNC 0x1004cb80  FUN_1004cb80

void FUN_1004cb80(void)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    iVar1 = DAT_1004cbb0;
    uVar2 = 1 << (uVar4 & 0xff);
    if ((uVar2 & *(uint *)(DAT_1004cbac + 0x38)) != 0) {
      *(uint *)(DAT_1004cbac + 0x38) = uVar2;
      pcVar3 = *(code **)(uVar4 * 8 + iVar1);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(*(undefined4 *)(iVar1 + uVar4 * 8 + 4));
      }
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 0x10);
  return;
}

// FUNC 0x1004cbb4  FUN_1004cbb4

void FUN_1004cbb4(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = (undefined4 *)(DAT_1004cbe0 + 0x80);
  do {
    uVar1 = 1 << (uVar3 & 0xff);
    if ((uVar1 & *(uint *)(DAT_1004cbe4 + 0x38)) != 0) {
      *(uint *)(DAT_1004cbe4 + 0x38) = uVar1;
      if ((code *)*puVar2 != (code *)0x0) {
        (*(code *)*puVar2)(puVar2[1]);
      }
    }
    uVar3 = uVar3 + 1;
    puVar2 = puVar2 + 2;
  } while (uVar3 != 0x10);
  return;
}

// FUNC 0x1004cbe8  pin_config

/* Secondary pin configuration select */

undefined4 pin_config(byte *param_1)

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

// FUNC 0x1004ce00  gpio_pin_irq_enable

/* Sets the interrupt enable bit for a GPIO pin descriptor: 0..15 on one block, 16..30 on the other
    */

undefined4 gpio_pin_irq_enable(byte *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  
  if (param_1 == (byte *)0x0) {
LAB_1004ce28:
    uVar2 = 0xffffffff;
  }
  else {
    bVar4 = *param_1;
    if (bVar4 < 0x10) {
      uVar3 = *(uint *)(DAT_1004ce30 + 4);
      iVar1 = DAT_1004ce30;
    }
    else {
      if (0x1e < bVar4) goto LAB_1004ce28;
      bVar4 = bVar4 - 0x10;
      uVar3 = *(uint *)(DAT_1004ce34 + 4);
      iVar1 = DAT_1004ce34;
    }
    *(uint *)(iVar1 + 4) = 1 << (uint)bVar4 | uVar3;
    uVar2 = 0;
  }
  return uVar2;
}

// FUNC 0x1004ce38  gpio_pin_irq_disable

/* Clears the interrupt enable bit for a GPIO pin descriptor */

undefined4 gpio_pin_irq_disable(byte *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  
  if (param_1 == (byte *)0x0) {
LAB_1004ce5e:
    uVar2 = 0xffffffff;
  }
  else {
    bVar4 = *param_1;
    if (bVar4 < 0x10) {
      uVar3 = *(uint *)(DAT_1004ce64 + 4);
      iVar1 = DAT_1004ce64;
    }
    else {
      if (0x1e < bVar4) goto LAB_1004ce5e;
      bVar4 = bVar4 - 0x10;
      uVar3 = *(uint *)(DAT_1004ce68 + 4);
      iVar1 = DAT_1004ce68;
    }
    *(uint *)(iVar1 + 4) = uVar3 & ~(1 << (uint)bVar4);
    uVar2 = 0;
  }
  return uVar2;
}

// FUNC 0x1004cec8  FUN_1004cec8

void FUN_1004cec8(void)

{
  int iVar1;
  
  iVar1 = DAT_1004cedc;
  *(undefined4 *)(DAT_1004cedc + 0xc00) = DAT_1004cee0;
  *(undefined4 *)(iVar1 + 0xc) = 1;
  *(undefined4 *)(iVar1 + 0xc00) = DAT_1004cee4;
  return;
}

// FUNC 0x1004cee8  FUN_1004cee8

void FUN_1004cee8(void)

{
  FUN_1004cec8();
  return;
}

// FUNC 0x1004cf2c  FUN_1004cf2c

void FUN_1004cf2c(void)

{
  FUN_1004cec8();
  return;
}

// FUNC 0x1004cf34  FUN_1004cf34

void FUN_1004cf34(void)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = 1 << (uVar3 & 0xff);
    if ((uVar1 & *(uint *)(DAT_1004cf60 + 0x7c)) != 0) {
      *(uint *)(DAT_1004cf64 + 0x7c) = uVar1;
      pcVar2 = *(code **)(uVar3 * 4 + DAT_1004cf68);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)();
      }
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 6);
  return;
}

// FUNC 0x1004cf6c  led_update_core

void led_update_core(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  
  iVar2 = FUN_10056d58(*DAT_1004d0dc,*(undefined4 *)(param_1 + 8),param_3,DAT_1004d0dc,param_4);
  uVar3 = FUN_10048b58(0x3f800000,*(undefined4 *)(param_1 + 4));
  uVar4 = FUN_10048f38(iVar2);
  FUN_10048930(uVar3,uVar4);
  uVar8 = FUN_1004ab50();
  uVar8 = FUN_10048fb4((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,DAT_1004d0e0);
  FUN_1004a348((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,DAT_1004d0e4);
  uVar1 = FUN_10048254();
  iVar7 = DAT_1004d0e8;
  uVar6 = (uint)uVar1;
  if (*param_1 < 0xc) {
    *(undefined4 *)(DAT_1004d0e8 + 0x34) = *(undefined4 *)(DAT_1004d0e8 + 0x34);
    iVar5 = FUN_10056ee8();
    param_1 = param_1 + iVar5;
    param_1[0] = 0x1d;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    *(uint *)(iVar7 + 0x38) = iVar2 - 0x33U | *(uint *)(iVar7 + 0x38) & 0xffff0000;
    *(uint *)(iVar7 + 0x50) = *(uint *)(iVar7 + 0x50) & 0xffff0000 | uVar6;
    *(undefined4 *)(iVar7 + 0x68) = 0;
  }
  return;
}

// FUNC 0x1004d0ec  led_channel_schedule_cancel

undefined4 led_channel_schedule_cancel(byte *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_1004d134;
  if ((param_1 == (byte *)0x0) || (0xb < *param_1)) {
    uVar2 = 0xffffffff;
  }
  else {
    *DAT_1004d130 = DAT_1004d12c;
    *DAT_1004d13c = DAT_1004d138;
    *DAT_1004d140 = DAT_1004d144 & *DAT_1004d140;
    *puVar1 = *puVar1 & ~(1 << (uint)*param_1);
    led_update_core();
    uVar2 = 0;
    puVar1[1] = 0;
  }
  return uVar2;
}

// FUNC 0x1004d148  led_channel_schedule_set

undefined4 led_channel_schedule_set(byte *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (byte *)0x0) || (0xb < *param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    *DAT_1004d168 = 1 << (uint)*param_1 | *DAT_1004d168;
  }
  return uVar1;
}

// FUNC 0x1004d16c  led_channel_payload_update

undefined4 led_channel_payload_update(byte *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (byte *)0x0) || (0xb < *param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    *DAT_1004d18c = *DAT_1004d18c & ~(1 << (uint)*param_1);
  }
  return uVar1;
}

// FUNC 0x1004d190  led_channel_payload_send

undefined4 led_channel_payload_send(byte *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (byte *)0x0) || (0xb < *param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = led_channel_payload_update();
  }
  return uVar1;
}

// FUNC 0x1004d1a8  FUN_1004d1a8

void FUN_1004d1a8(void)

{
  char cVar1;
  
  cVar1 = '@';
  do {
    if ((*(uint *)(DAT_1004d1c0 + 0x2c) & 0x10) != 0) {
      return;
    }
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

// FUNC 0x1004d1c4  FUN_1004d1c4

void FUN_1004d1c4(void)

{
  char cVar1;
  
  cVar1 = '@';
  do {
    if ((*(uint *)(DAT_1004d1dc + 0xc) & 0x10) != 0) {
      return;
    }
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}

// FUNC 0x1004d1e0  FUN_1004d1e0

void FUN_1004d1e0(void)

{
  reg_field_write(2,0xc,1);
  reg_field_write(0x15,0xd,4,0);
  reg_field_write(0x23,0x1c,1,0);
  reg_field_write(0x23,0x19,3,1);
  reg_field_write(0x23,10,1,0);
  reg_field_write(0x23,0,1);
  reg_field_write(0x23,0x1d,1,0);
  reg_field_write(0x32,0xd,4,7);
  reg_field_write(0x23,9,1);
  return;
}

// FUNC 0x1004d250  FUN_1004d250

void FUN_1004d250(int param_1,uint param_2)

{
  if (param_1 == 2) {
    if (7 < param_2) {
      return;
    }
    if (param_2 - 1 < 7) {
      FUN_10056ee8();
    }
    reg_field_write(0x21,8,1,0);
    reg_field_write(0x21,0x13,1,0);
  }
  else {
    if (param_1 != 3) {
      return;
    }
    if (param_2 < 8) {
      return;
    }
    if (7 < param_2 - 8) {
      return;
    }
    FUN_10056ee8(param_2 - 8,8,1,0);
    reg_field_write(0x21);
    reg_field_write(0x21,0x13,1);
  }
  reg_field_write(0x21,9,2,0);
  return;
}

// FUNC 0x1004d376  FUN_1004d376

void FUN_1004d376(void)

{
  uint uVar1;
  
  reg_field_write(0x15,0x1d,3,7);
  FUN_1004afa2(2);
  reg_field_write(0x15,0x1d,3,0);
  FUN_1004afa2(5);
  reg_field_write(0x15,0xb,2,3);
  reg_field_write(0x31,0x17,1);
  reg_field_write(0x16,0x1f,1,0);
  reg_field_write(0x16,0x1c,1,0);
  reg_field_write(0x16,9,3,0);
  reg_field_write(0x16,2,1,0);
  reg_field_write(0x32,0x1e,1);
  reg_field_write(0x32,0,4,0xb);
  reg_field_write(0x1b,0x12,1);
  reg_field_write(0x1c,0x18,4,0xf);
  reg_field_write(0x16,7,1,0);
  reg_field_write(0x1b,0x12,1,0);
  reg_field_write(0x15,0xb,2,0);
  reg_field_write(0x1c,0x18,4,0);
  reg_field_write(0x32,0x1e,1,0);
  reg_field_write(0x32,0,4);
  reg_field_write(0x16,7,1);
  reg_field_write(0x16,0x1f,1);
  reg_field_write(0x16,0x1c,1);
  reg_field_write(0x16,9,3,7);
  reg_field_write(0x16,2,1);
  reg_field_write(0x31,0x17,1,0);
  do {
    uVar1 = syscfg_read(0x38);
  } while ((uVar1 & 0x40000000) == 0);
  return;
}

// FUNC 0x1004d4b4  FUN_1004d4b4

void FUN_1004d4b4(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int unaff_r5;
  
  if (param_1 < 0xe) {
    FUN_10056ee8();
    *(ushort *)(param_4 + unaff_r5) = (ushort)param_4 | 0x24;
    reg_field_write(0x22,0x11,1);
    reg_field_write(0x22,0xb,3,0);
    reg_field_write(0x20,0x1a,1,0);
  }
  return;
}

// FUNC 0x1004d5c0  FUN_1004d5c0

ulonglong FUN_1004d5c0(int param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint local_20;
  
  iVar1 = DAT_1004d674;
  if (0x10 < param_2) {
    param_2 = 0;
  }
  *(uint *)(DAT_1004d674 + 8) = param_2;
  local_20 = 0;
  uVar4 = 0;
  while ((uVar4 & 0xff) < param_2) {
    pinmux_set(*(undefined1 *)(param_1 + uVar4),3);
    puVar2 = DAT_1004d678;
    uVar3 = (uint)*(byte *)(param_1 + uVar4);
    if (uVar3 < 0x10) {
      *(int *)(DAT_1004d67c + 0x14) = 1 << uVar3;
      *puVar2 = *puVar2 & ~(1 << *(sbyte *)(param_1 + uVar4));
      *DAT_1004d680 = 3 << ((*(byte *)(param_1 + uVar4) & 0x7f) << 1) | *DAT_1004d680;
    }
    else {
      *(int *)(DAT_1004d684 + 0x14) = 1 << (uVar3 - 0x10 & 0xff);
      *puVar2 = *puVar2 | 1 << *(sbyte *)(param_1 + uVar4);
      *DAT_1004d688 = 3 << ((*(byte *)(param_1 + uVar4) - 0x10) * 2 & 0xff) | *DAT_1004d688;
    }
    if (*(byte *)(param_1 + uVar4) < 0xe) {
      local_20 = (uint)(byte)(*(byte *)(param_1 + uVar4) - 6);
    }
    uVar3 = uVar4 + 1;
    if ((uVar4 & 0xff) < 7) {
      *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | local_20 << (uVar3 * 4 & 0xff);
      uVar4 = uVar3;
    }
    else {
      *(uint *)(iVar1 + 0xc) =
           *(uint *)(iVar1 + 0xc) | local_20 << ((uVar4 + DAT_1004d68c) * 4 & 0xff);
      uVar4 = uVar3;
    }
  }
  return CONCAT44(uVar4,local_20) & 0xffffffffff;
}

// FUNC 0x1004d690  mic_pins_config

/* Configures P27/P28/P29 for the audio front end */

undefined8 mic_pins_config(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 local_18;
  undefined1 local_17;
  undefined2 uStack_16;
  undefined4 local_14;
  undefined4 uStack_10;
  
  uStack_16 = (undefined2)((uint)param_1 >> 0x10);
  local_18 = 0x1c;
  uVar1 = (undefined1)param_1;
  local_14 = 0;
  local_17 = uVar1;
  uStack_10 = param_3;
  pin_config(&local_18);
  local_18 = 0x1d;
  local_14 = 0;
  local_17 = uVar1;
  pin_config(&local_18);
  local_18 = 0x1b;
  local_14 = 0;
  local_17 = uVar1;
  pin_config(&local_18);
  FUN_1004afa2(600);
  reg_field_write(1,0x1f,1);
  return CONCAT44(local_14,CONCAT22(uStack_16,CONCAT11(local_17,local_18)));
}

// FUNC 0x1004d6e0  FUN_1004d6e0

void FUN_1004d6e0(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_2 < 2) {
    if (0xf < param_1) {
      return;
    }
    reg_field_write(0x15,0xe,1);
    reg_field_write(0x15,0x10,1);
    reg_field_write(0x15,0xf,1);
    FUN_1004afa2(1);
    reg_field_write(0x15,0xd,1,0);
    reg_field_write(0x15,0xe,1,0);
    reg_field_write(0x15,0x10,1,0);
    reg_field_write(0x15,0xf,1,0);
    reg_field_write(0x23,0xf,2,3);
    reg_field_write(2,0xc,1);
    if (param_2 == 0) {
      reg_field_write(0x23,0x1c,1,0);
      reg_field_write(0x23,0x15,4,param_1);
      if (param_1 != 0xf) {
        FUN_1004d1e0();
        return;
      }
      iVar1 = reg_field_read(3,0x1c,1);
      if (iVar1 != 1) {
        FUN_1004d1e0();
        reg_field_write(0x23,0,1);
        uVar5 = 1;
        uVar3 = 0xc;
        uVar4 = 1;
        uVar2 = 2;
        goto LAB_1004d9d8;
      }
      reg_field_write(2,0xc,1,0);
      reg_field_write(0x15,0xd,4,0);
      reg_field_write(0x23,0x1c,1,0);
      reg_field_write(0x23,0x19,3,1);
      reg_field_write(0x23,0x15,4,0xf);
      reg_field_write(0x23,10,1,0);
      reg_field_write(0x23,0,1,1);
      reg_field_write(0x23,0x1d,1,1);
      reg_field_write(0x32,0xd,4);
      uVar3 = 9;
      uVar4 = 1;
      uVar5 = 1;
    }
    else {
      reg_field_write(0x23,0x1c,1);
      uVar5 = 3;
      uVar4 = 2;
      uVar3 = 0xf;
    }
    uVar2 = 0x23;
  }
  else {
    mic_pins_config(4);
    reg_field_write(0x17,0xb,1);
    reg_field_write(0x17,0x16,1,0);
    if (param_2 == 2) {
      FUN_1004d376();
      reg_field_write(0x15,0x19,1,0);
      reg_field_write(0x15,0x17,1,0);
      reg_field_write(0x15,0x11,2,0);
      reg_field_write(0x15,0x14,1,0);
      reg_field_write(0x15,0x15,1,0);
      reg_field_write(0x15,0x18,1,0);
      reg_field_write(0x15,9,1);
      reg_field_write(0x15,9,1,0);
      syscfg_write(0x20,DAT_1004d9e0);
      syscfg_write(0x21,DAT_1004d9e4);
      reg_field_write(0x21,4,3,5);
      reg_field_write(0x20,0x12,2,1);
      FUN_1004afa2(600);
    }
    else {
      if (param_2 != 3) {
        return;
      }
      reg_field_write(0x15,0xd,1,0);
      reg_field_write(0x20,0x1c,4,0xb);
      reg_field_write(0x15,0x19,7,0);
      reg_field_write(0x15,0x17,1,0);
      reg_field_write(0x15,0xb,2,3);
      reg_field_write(0x15,0xb,1,0);
      reg_field_write(0x15,0xc,1,0);
      FUN_1004afa2(DAT_1004d9e8);
      reg_field_write(0x15,0x11,2,0);
      reg_field_write(0x15,0x14,1,0);
      reg_field_write(0x15,0x15,2,0);
      reg_field_write(0x15,0x18,1,0);
      reg_field_write(0x15,9,1);
      reg_field_write(0x15,9,1,0);
      syscfg_write(0x20,DAT_1004d9e0);
      syscfg_write(0x21,DAT_1004d9ec);
      reg_field_write(0x21,4,3,5);
      reg_field_write(0x20,0x12,2,1);
      FUN_1004afa2(600);
    }
    uVar5 = 3;
    uVar4 = 2;
    uVar3 = 0x12;
    uVar2 = 0x20;
  }
LAB_1004d9d8:
  reg_field_write(uVar2,uVar3,uVar4,uVar5);
  return;
}

// FUNC 0x1004d9f0  FUN_1004d9f0

void FUN_1004d9f0(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  pinmux_set(param_1,3);
  puVar1 = DAT_1004da44;
  if (param_1 < 0x10) {
    uVar2 = 1 << (param_1 & 0xff);
    *(uint *)(DAT_1004da48 + 0x14) = uVar2;
    *puVar1 = *puVar1 & ~uVar2;
    *DAT_1004da4c = 3 << ((param_1 & 0x7f) << 1) | *DAT_1004da4c;
  }
  else {
    *(int *)(DAT_1004da50 + 0x14) = 1 << (param_1 - 0x10 & 0xff);
    *puVar1 = 1 << (param_1 & 0xff) | *puVar1;
    *DAT_1004da54 = 3 << ((param_1 - 0x10) * 2 & 0xff) | *DAT_1004da54;
  }
  return;
}

// FUNC 0x1004da58  tim4_enable

void tim4_enable(int param_1)

{
  if (param_1 == 1) {
    *(uint *)(DAT_1004da70 + 4) = *(uint *)(DAT_1004da70 + 4) | 1;
  }
  else {
    *(uint *)(DAT_1004da70 + 4) = *(uint *)(DAT_1004da70 + 4) & 0xfffffffe;
  }
  return;
}

// FUNC 0x1004da74  tim4_status

undefined4 tim4_status(void)

{
  return *(undefined4 *)(DAT_1004da7c + 0x2c);
}

// FUNC 0x1004da80  tim4_count

uint tim4_count(void)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  iVar3 = reg_field_read(3,0x1c,1);
  iVar1 = DAT_1004dac0;
  if ((iVar3 == 1) && (iVar3 = reg_field_read(0x23,0x15,4), iVar3 == 0xf)) {
    uVar5 = FUN_1004aa5c(*(uint *)(iVar1 + 0x20) & 0xffff);
    FUN_10049e54((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_1004dac4,DAT_1004dac8);
    FUN_1004abf8();
    uVar2 = FUN_10048224();
    uVar4 = (uint)uVar2;
  }
  else {
    uVar4 = *(uint *)(iVar1 + 0x20);
  }
  return uVar4;
}

// FUNC 0x1004dacc  FUN_1004dacc

void FUN_1004dacc(int param_1)

{
  bool bVar1;
  
  bVar1 = param_1 != 1;
  if (bVar1) {
    param_1 = 1;
  }
  reg_field_write(0x15,0x13,param_1,bVar1);
  return;
}

// FUNC 0x1004dae4  tim4_configure

void tim4_configure(undefined4 *param_1)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  undefined1 auStack_19 [5];
  
  puVar6 = DAT_1004dbd8;
  puVar4 = DAT_1004dbd0;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\0') {
    bVar2 = *(byte *)(param_1 + 4);
    FUN_1004d1a8();
    if (bVar2 < 8) {
      FUN_1004d9f0(bVar2 + 6,auStack_19);
    }
    FUN_1004d6e0(bVar2,0);
    iVar5 = DAT_1004dbd4;
    *(uint *)(DAT_1004dbd4 + 4) = *(uint *)(DAT_1004dbd4 + 4) & 0xfffffff7;
    *(uint *)(iVar5 + 4) = *(uint *)(iVar5 + 4) & 0xffffffef;
    *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) | 4;
  }
  else {
    if (cVar1 != '\x01') {
      FUN_1004d1c4();
      FUN_1004d6e0(3,cVar1);
      puVar7 = DAT_1004dbdc;
      *DAT_1004dbdc = *DAT_1004dbdc | 4;
      *puVar7 = *puVar7 & 0xffffffdf;
      puVar7[2] = puVar7[2] | 4;
      *puVar6 = 0x800000;
      FUN_1004d1c4();
      FUN_1004d250(*(undefined1 *)(param_1 + 2),*(undefined1 *)((int)param_1 + 0x13));
      if (*(byte *)((int)param_1 + 0x11) < 0xe) {
        FUN_1004d4b4();
      }
      FUN_1004dacc(*(undefined1 *)((int)param_1 + 0x12));
      puVar4[2] = *param_1;
      puVar4[3] = param_1[1];
      return;
    }
    uVar8 = param_1[5];
    uVar3 = *(undefined1 *)(param_1 + 6);
    FUN_1004d1a8();
    FUN_1004d6e0(3,1);
    FUN_1004d5c0(uVar8,uVar3);
    iVar5 = DAT_1004dbd4;
    *(uint *)(DAT_1004dbd4 + 4) = *(uint *)(DAT_1004dbd4 + 4) | 8;
    *(uint *)(iVar5 + 4) = *(uint *)(iVar5 + 4) & 0xffffffef;
    *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) | 4;
    *puVar6 = 0x400000;
    FUN_1004d1a8();
  }
  *puVar4 = *param_1;
  puVar4[1] = param_1[1];
  return;
}

// FUNC 0x1004dbe0  FUN_1004dbe0

void FUN_1004dbe0(void)

{
  if ((code *)*DAT_1004dbf0 != (code *)0x0) {
    (*(code *)*DAT_1004dbf0)(DAT_1004dbf0[1]);
  }
  return;
}

// FUNC 0x1004dbf4  FUN_1004dbf4

void FUN_1004dbf4(void)

{
  if (*(code **)(DAT_1004dc04 + 8) != (code *)0x0) {
    (**(code **)(DAT_1004dc04 + 8))(*(undefined4 *)(DAT_1004dc04 + 0xc));
  }
  return;
}

// FUNC 0x1004dc24  keypad_irq_enable

/* Sets or clears the keypad interrupt enable bit */

void keypad_irq_enable(int param_1)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_1004dc40 | 0x800;
  }
  else {
    uVar1 = DAT_1004dc44 & *DAT_1004dc40;
  }
  *DAT_1004dc40 = uVar1;
  return;
}

// FUNC 0x1004dcec  keypad_read_matrix

/* Copies the keypad matrix registers into a caller buffer */

void keypad_read_matrix(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = *DAT_1004dd1c;
  uVar3 = 0;
  do {
    uVar1 = uVar3 >> 1;
    uVar4 = uVar3 & 1;
    iVar5 = uVar3 * 4;
    uVar3 = uVar3 + 1 & 0xff;
    *(uint *)(iVar5 + param_1) = *(uint *)(uVar1 * 8 + DAT_1004dd20) >> (uVar4 << 4) & 0xffff;
  } while (uVar3 <= (uint)(iVar2 << 6) >> 0x1d);
  return;
}

// FUNC 0x1004dd24  keypad_irq

/* Matrix scan interrupt: compares state and calls the key callback with row, column, pressed */

void keypad_irq(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  
  puVar1 = DAT_1004ddd4;
  keypad_irq_enable(0);
  log_printf(DAT_1004ddd8);
  puVar2 = DAT_1004dde4;
  puVar7 = DAT_1004dde0;
  if (*DAT_1004dddc == '\x01') {
    uVar3 = DAT_1004dde0[1];
    uVar8 = DAT_1004dde0[2];
    puVar11 = DAT_1004dde0 + 3;
    *DAT_1004dde4 = *DAT_1004dde0;
    puVar2[1] = uVar3;
    puVar2[2] = uVar8;
    iVar9 = 0;
    puVar2[3] = *puVar11;
    keypad_read_matrix(puVar7);
    do {
      uVar5 = puVar2[iVar9];
      uVar6 = DAT_1004dde0[iVar9];
      if ((uVar5 ^ uVar6) != 0) {
        uVar10 = 0;
        do {
          uVar4 = 1 << (uVar10 & 0xff);
          if (((uVar4 & (uVar5 ^ uVar6)) != 0) && ((code *)*DAT_1004dde8 != (code *)0x0)) {
            (*(code *)*DAT_1004dde8)(iVar9,uVar10,(uVar4 & DAT_1004dde0[iVar9]) != 0);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 != 5);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 4);
  }
  else {
    uVar5 = (puVar1[8] << 1) >> 0x1b;
    puVar7 = DAT_1004ddf0;
    if ((uVar5 != 0) && (puVar7 = DAT_1004ddf4, uVar5 == 1)) {
      puVar7 = DAT_1004ddec;
    }
    if ((code *)*puVar7 != (code *)0x0) {
      (*(code *)*puVar7)();
    }
  }
  *puVar1 = *puVar1 | 0x800;
  return;
}

// FUNC 0x1004ddf8  FUN_1004ddf8

void FUN_1004ddf8(void)

{
  log_printf(DAT_1004de04);
  return;
}

// FUNC 0x1004e1a0  app_msg_dispatch

/* App message handler for ids 0x28..0x37 (not wire bytes): 0x28 base frame ready, copies 11 bytes
   and posts 0x0B; 0x29 key highlight tick; 0x2b LED animation tick; 0x34 all LEDs red; 0x35 all
   LEDs green flash; 0x36 all LEDs red flash; 0x37 clear key highlight */

undefined4 app_msg_dispatch(int param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte *pbVar4;
  byte *pbVar5;
  ushort *puVar6;
  undefined4 uVar7;
  uint uVar8;
  
  if (param_1 == 0x28) {
    log_printf(DAT_1004e2ac);
    pbVar5 = DAT_1004e2b4;
    pbVar4 = DAT_1004e2b0;
    bVar1 = *DAT_1004e2b0;
    bVar2 = *DAT_1004e2b4;
    uVar8 = (uint)bVar2;
    *(byte *)(DAT_1004e2b8 + uVar8) = bVar1;
    *pbVar4 = 0;
    puVar6 = DAT_1004e2bc;
    *DAT_1004e2bc = (ushort)bVar1;
    *(uint *)(puVar6 + 2) = uVar8 * 0x20 + DAT_1004e2c0;
    *(undefined4 *)(puVar6 + 4) = DAT_1004e2c4;
    if (uVar8 == 1) {
      *pbVar5 = 0;
    }
    else {
      *pbVar5 = bVar2 + 1;
    }
    FUN_100538e8(0xb);
    return 0;
  }
  if (param_1 == 0x29) {
    key_highlight_tick(0);
    uVar7 = 0x4b;
  }
  else if (param_1 == 0x2d) {
    FUN_1005147c(0);
    if (*DAT_1004e2c8 == '\0') {
      return 0;
    }
    uVar7 = 100;
  }
  else if (param_1 == 0x30) {
    FUN_100512ec(0);
    uVar7 = 0x28;
  }
  else {
    if (param_1 == 0x2a) {
      led_anim_finish(0);
      return 0;
    }
    if (param_1 == 0x2f) {
      FUN_10050488(0);
      uVar7 = 0x21;
      cVar3 = *DAT_1004e2cc;
    }
    else {
      if (param_1 == 0x2e) {
        FUN_10050448(0);
        return 0;
      }
      if (param_1 != 0x2b) {
        if (param_1 == 0x31) {
          FUN_10051654(0);
          return 0;
        }
        if (param_1 == 0x32) {
          FUN_1005032c(0);
          return 0;
        }
        if (param_1 == 0x33) {
          FUN_100502ec();
          return 0;
        }
        if (param_1 == 0x34) {
          all_leds_set();
          return 0;
        }
        if (param_1 == 0x35) {
          all_leds_flash_green();
          return 0;
        }
        if (param_1 == 0x36) {
          all_leds_blink();
          return 0;
        }
        if (param_1 != 0x37) {
          return 0;
        }
        key_highlight_clear();
        return 0;
      }
      led_update(0);
      uVar7 = 200;
      cVar3 = *DAT_1004e2d0;
    }
    if (cVar3 == '\0') {
      return 0;
    }
  }
  app_msg_post(param_1,uVar7);
  return 0;
}

// FUNC 0x1004e2e0  app_ota_start_callback

/* Registered OTA start handler; logs the app version and the callback result */

undefined4 app_ota_start_callback(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_s_app_ota_start_callback_1004e304;
  log_printf(PTR_s__s__s__s_1004e30c,PTR_s_app_ota_start_callback_1004e304,
             PTR_s_app_1_0_2_20240319_1000_1004e308,param_2);
  uVar2 = FUN_10053ae8();
  log_printf(PTR_s__s__s_1004e310,puVar1,uVar2);
  return 0;
}

// FUNC 0x1004e344  ble_legacy_adv_config

/* app_ble_config_legacy_advertising: 0x1c-byte legacy advertising parameters */

void ble_legacy_adv_config(void)

{
  undefined *puVar1;
  int iVar2;
  undefined1 local_2c [2];
  undefined2 local_2a;
  undefined1 local_28;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  
  puVar1 = PTR_s_app_ble_config_legacy_advertisin_1004e390;
  log_printf(PTR_s_APP___s_1004e394,PTR_s_app_ble_config_legacy_advertisin_1004e390);
  FUN_10056f28(local_2c,0,0x1c);
  local_2a = 3;
  local_28 = 0xe2;
  local_1c = 0x40;
  local_18 = 0x40;
  local_14 = 7;
  local_2c[0] = 1;
  local_13 = 1;
  iVar2 = FUN_10053454(0,local_2c);
  if (iVar2 != 0) {
    log_printf(PTR_s_APP___s_ERROR__02X_1004e398,puVar1);
  }
  return;
}

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
  log_printf(DAT_1004e528,DAT_1004e52c);
  FUN_10051b94(5);
  FUN_100533bc(DAT_1004e530);
  FUN_10051e64(DAT_1004e534);
  FUN_100533c8(DAT_1004e538);
  FUN_10053b6c(DAT_1004e53c);
  FUN_100533d4(DAT_1004e540);
  FUN_10055110(DAT_1004e544);
  uVar2 = DAT_1004e548;
  log_printf(uVar1,DAT_1004e548);
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
    log_printf(DAT_1004e54c,uVar2);
  }
  puVar4 = (undefined1 *)ble_get_mac();
  log_printf(DAT_1004e550,puVar4[5],puVar4[4],puVar4[3],puVar4[2],puVar4[1],*puVar4);
  log_printf(DAT_1004e554);
  iVar3 = DAT_1004e558;
  task_queue_add(DAT_1004e558);
  task_queue_add(iVar3 + 8);
  task_queue_add(iVar3 + 0x10);
  return;
}

// FUNC 0x1004e608  FUN_1004e608

void FUN_1004e608(void)

{
  app_msg_post(0x29,0x4b);
  app_msg_post(0x30,0x28);
  if (*(char *)(DAT_1004e638 + 0x12) == '\0') {
    FUN_1004ead0();
  }
  else {
    *DAT_1004e63c = 1;
    app_msg_post(0x2d,100);
  }
  return;
}

// FUNC 0x1004e640  ble_complete_event_handler

/* Handles BLE complete events by option id and advances advertising */

undefined4
ble_complete_event_handler(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  undefined *puVar7;
  uint uVar8;
  undefined *puVar9;
  char *pcVar10;
  undefined1 auStack_2c [24];
  
  puVar9 = PTR_s_app_ble_complete_event_handler_1004e7a0;
  log_printf(PTR_s_APP_COMPLETE___s_opt_id__04X_sta_1004e7a4,
             PTR_s_app_ble_complete_event_handler_1004e7a0,param_1,param_2,param_3,param_4);
  puVar5 = PTR_s_app_ble_start_advertising_1004e7dc;
  puVar4 = PTR_s_APP___s_1004e7c0;
  puVar7 = PTR_s_app_ble_set_adv_data_1004e7bc;
  if (param_1 == DAT_1004e7a8) {
    param_4 = param_4 & 0xffff;
    puVar7 = DAT_1004e7ec;
  }
  else {
    if (DAT_1004e7a8 < param_1) {
      if (param_1 != DAT_1004e7ac) {
        if (param_1 != DAT_1004e7b0) {
          if (param_1 != DAT_1004e7b4) {
            return 0;
          }
          FUN_10051ba0(10);
          if (*DAT_1004e7b8 != '\0') {
            ble_legacy_adv_config();
          }
          FUN_1004e608();
          return 0;
        }
        if (*DAT_1004e7e0 == '\0') {
          FUN_10054ca8();
        }
        if (*DAT_1004e7e4 != '\0') {
          return 0;
        }
        FUN_100550f4();
        return 0;
      }
      log_printf(PTR_s_APP___s_1004e7c0,PTR_s_app_ble_set_adv_data_1004e7bc);
      rom_memcpy(auStack_2c,PTR_hex_digit_table_1004e7c4,0x11);
      iVar6 = DAT_1004e7cc;
      uVar8 = *(uint *)(DAT_1004e7c8 + 4);
      uVar1 = auStack_2c[uVar8 >> 0x10 & 0xf];
      uVar2 = auStack_2c[uVar8 >> 8 & 0xf];
      *(undefined1 *)(DAT_1004e7cc + 0x14) = auStack_2c[(uVar8 >> 0x10 & 0xff) >> 4];
      *(undefined1 *)(iVar6 + 0x15) = uVar1;
      uVar1 = auStack_2c[uVar8 & 0xf];
      uVar3 = auStack_2c[(uVar8 >> 8 & 0xff) >> 4];
      *(undefined1 *)(iVar6 + 0x18) = auStack_2c[(uVar8 & 0xff) >> 4];
      *(undefined1 *)(iVar6 + 0x19) = uVar1;
      *(undefined1 *)(iVar6 + 0x16) = uVar3;
      *(undefined1 *)(iVar6 + 0x17) = uVar2;
      iVar6 = FUN_10053788(0x1a);
      if (iVar6 != 0) {
        log_printf(PTR_s_APP___s_ERROR__02X_1004e7d0,puVar7);
      }
      puVar9 = PTR_s_app_ble_set_scan_response_data_1004e7d4;
      log_printf(puVar4,PTR_s_app_ble_set_scan_response_data_1004e7d4);
      rom_memcpy(auStack_2c,PTR_DAT_1004e7d8,4);
      param_4 = FUN_100537bc(4,auStack_2c);
      puVar7 = PTR_s_APP___s_ERROR__02X_1004e7d0;
    }
    else {
      if (param_1 == 0x11b) {
        pcVar10 = DAT_1004e7e0;
        if ((param_4 == 0x14) || (pcVar10 = DAT_1004e7e4, param_4 == 0x50)) {
          *pcVar10 = '\x01';
        }
        if (*DAT_1004e7e8 != 0) {
          return 0;
        }
        if (param_4 != 0x14) {
          return 0;
        }
        ble_custom_service_add();
        return 0;
      }
      if (param_1 != 0x1a9) {
        return 0;
      }
      log_printf(PTR_s_APP___s_1004e7c0,PTR_s_app_ble_start_advertising_1004e7dc);
      param_4 = FUN_100536d4(0);
      puVar7 = PTR_s_APP___s_ERROR__02X_1004e7d0;
      puVar9 = puVar5;
    }
    PTR_s_APP___s_ERROR__02X_1004e7d0 = puVar7;
    if (param_4 == 0) {
      return 0;
    }
  }
  log_printf(puVar7,puVar9,param_4);
  return 0;
}

// FUNC 0x1004e7f0  uart1_log_init

/* UART1 on P04/P05 at 921600; the J3 log/console port */

void uart1_log_init(void)

{
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_18;
  
  uart_driver_init(1,DAT_1004e848);
  pinmux_set(4,0xe);
  pinmux_set(5,0xe);
  FUN_10056f28(local_24,0,0x14);
  local_20 = 0xe1000;
  local_1c = 3;
  local_18 = 3;
  local_24[0] = 1;
  uart_init(local_24);
  uart_enable(1);
  uart_set_config(DAT_1004e84c,0x50,1);
  *DAT_1004e850 = 4;
  return;
}

// FUNC 0x1004e854  uart3_init

/* P13/P14, 115200; display link to the panel STM8 */

void uart3_init(void)

{
  undefined1 auStack_1c [20];
  
  pinmux_set(0xd,0x10);
  pinmux_set(0xe,0x10);
  FUN_10056f28(auStack_1c,0,0x14);
  auStack_1c[0] = 3;
  uart_apply_baud(auStack_1c);
  uart_init(auStack_1c);
  return;
}

// FUNC 0x1004e888  uart3_write

/* Writes a buffer to UART3, the display link */

void uart3_write(undefined1 *param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = param_1 + param_2;
  for (; param_1 != puVar1; param_1 = param_1 + 1) {
    uart_putc(DAT_1004e8a0,*param_1);
  }
  return;
}

// FUNC 0x1004e8a4  uart0_base_link_init

/* UART0 on P02/P03 at 2400; the base board link */

void uart0_base_link_init(void)

{
  undefined1 auStack_24 [4];
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_18;
  
  uart_driver_init(0,DAT_1004e908);
  pinmux_set(2,0xd);
  pinmux_set(3,0xd);
  FUN_10056f28(auStack_24,0,0x14);
  local_20 = 0x960;
  local_1c = 3;
  local_18 = 3;
  uart_init(auStack_24);
  uart_set_config(0x40000000,0x50,1);
  *DAT_1004e90c = 8;
  uart_irq_enable(auStack_24,2,1);
  uart_nvic_priority(0x40000000,0);
  return;
}

// FUNC 0x1004e968  led_channel3_send_now

void led_channel3_send_now(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_1004e99c;
  *DAT_1004e99c = 7;
  uVar2 = FUN_10048ea8();
  uVar3 = FUN_100486fc(uVar2,DAT_1004e9a0);
  uVar2 = DAT_1004e9a4;
  *(undefined4 *)(puVar1 + 4) = uVar3;
  *(undefined4 *)(puVar1 + 8) = uVar2;
  if (param_1 == 0) {
    led_channel_payload_send(puVar1);
  }
  else {
    led_channel_schedule_cancel();
    led_channel_schedule_set(puVar1);
  }
  return;
}

// FUNC 0x1004e9a8  led_channel4_send_now

void led_channel4_send_now(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_1004e9e4;
  *DAT_1004e9e4 = 6;
  uVar2 = FUN_10048ea8();
  uVar2 = FUN_100486fc(uVar2,DAT_1004e9e8);
  uVar3 = FUN_10048b58(0x3f800000,uVar2);
  uVar2 = DAT_1004e9ec;
  *(undefined4 *)(puVar1 + 4) = uVar3;
  *(undefined4 *)(puVar1 + 8) = uVar2;
  if (param_1 == 0) {
    led_channel_payload_send(puVar1);
  }
  else {
    led_channel_schedule_cancel();
    led_channel_schedule_set(puVar1);
  }
  return;
}

// FUNC 0x1004e9f0  led_channel0_send_now

void led_channel0_send_now(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_1004ea24;
  *DAT_1004ea24 = 3;
  uVar2 = FUN_10048ea8();
  uVar3 = FUN_100486fc(uVar2,DAT_1004ea28);
  uVar2 = DAT_1004ea2c;
  *(undefined4 *)(puVar1 + 4) = uVar3;
  *(undefined4 *)(puVar1 + 8) = uVar2;
  if (param_1 == 0) {
    led_channel_payload_send(puVar1);
  }
  else {
    led_channel_schedule_cancel();
    led_channel_schedule_set(puVar1);
  }
  return;
}

// FUNC 0x1004ea30  led_channel1_send_now

void led_channel1_send_now(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_1004ea64;
  *DAT_1004ea64 = 5;
  uVar2 = FUN_10048ea8();
  uVar3 = FUN_100486fc(uVar2,DAT_1004ea68);
  uVar2 = DAT_1004ea6c;
  *(undefined4 *)(puVar1 + 4) = uVar3;
  *(undefined4 *)(puVar1 + 8) = uVar2;
  if (param_1 == 0) {
    led_channel_payload_send(puVar1);
  }
  else {
    led_channel_schedule_cancel();
    led_channel_schedule_set(puVar1);
  }
  return;
}

// FUNC 0x1004ea70  led_channel2_send_now

void led_channel2_send_now(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_1004eaa4;
  *DAT_1004eaa4 = 4;
  uVar2 = FUN_10048ea8();
  uVar3 = FUN_100486fc(uVar2,DAT_1004eaa8);
  uVar2 = DAT_1004eaac;
  *(undefined4 *)(puVar1 + 4) = uVar3;
  *(undefined4 *)(puVar1 + 8) = uVar2;
  if (param_1 == 0) {
    led_channel_payload_send(puVar1);
  }
  else {
    led_channel_schedule_cancel();
    led_channel_schedule_set(puVar1);
  }
  return;
}

// FUNC 0x1004eab0  FUN_1004eab0

void FUN_1004eab0(void)

{
  gpio_pin_irq_disable(DAT_1004eabc);
  return;
}

// FUNC 0x1004eac0  FUN_1004eac0

void FUN_1004eac0(void)

{
  gpio_pin_irq_enable(DAT_1004eacc);
  return;
}

// FUNC 0x1004ead0  FUN_1004ead0

void FUN_1004ead0(void)

{
  gpio_pin_irq_disable(DAT_1004eadc);
  return;
}

// FUNC 0x1004eae0  FUN_1004eae0

void FUN_1004eae0(void)

{
  gpio_pin_irq_enable(DAT_1004eaec);
  return;
}

// FUNC 0x1004eaf0  FUN_1004eaf0

void FUN_1004eaf0(void)

{
  gpio_pin_irq_disable(DAT_1004eafc);
  return;
}

// FUNC 0x1004eb00  FUN_1004eb00

void FUN_1004eb00(void)

{
  gpio_pin_irq_enable(DAT_1004eb0c);
  return;
}

// FUNC 0x1004ee2c  ble_custom_service_add

/* Logs app custom svc add request and registers the custom service */

void ble_custom_service_add
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  log_printf(PTR_DAT_1004ee4c,PTR_s_app_custom_svc_add_request_1004ee48,param_3,param_4,param_1,
             param_2,param_3);
  FUN_10051eec(0,0,DAT_1004ee54,0x13,DAT_1004ee50);
  return;
}

// FUNC 0x1004ee58  FUN_1004ee58

void FUN_1004ee58(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  
  if (param_2 == 4) {
    if (*DAT_1004eea4 == '\0') {
      return;
    }
    sVar1 = *DAT_1004eea8 + 4;
  }
  else if (param_2 == 9) {
    if (*DAT_1004eeac == '\0') {
      return;
    }
    sVar1 = *DAT_1004eea8 + 9;
  }
  else {
    if (param_2 != 0xe) {
      return;
    }
    if (*DAT_1004eeb0 == '\0') {
      return;
    }
    sVar1 = *DAT_1004eea8 + 0xe;
  }
  FUN_100521b8(param_1,sVar1,param_4,param_3);
  return;
}

// FUNC 0x1004eeb4  FUN_1004eeb4

bool FUN_1004eeb4(undefined4 param_1,short param_2)

{
  bool bVar1;
  ushort uVar2;
  int unaff_r4;
  uint uVar3;
  int unaff_r7;
  undefined4 in_stack_00000004;
  undefined2 uStack_1c;
  
  uVar2 = *DAT_1004f05c;
  uVar3 = (uint)(ushort)(param_2 + ~uVar2);
  log_printf(DAT_1004f064,DAT_1004f060,uVar3);
  bVar1 = uVar3 - 1 < 0x12;
  if (bVar1) {
    FUN_10056ee8();
    *(ushort *)(unaff_r7 + uVar3) = (short)unaff_r7 - (param_2 + ~uVar2);
    *(undefined2 *)(unaff_r4 + 0x34) = uStack_1c;
    FUN_1005226c(in_stack_00000004,*(undefined2 *)(unaff_r4 + 0x14),0,*DAT_1004f068);
  }
  return !bVar1;
}

// FUNC 0x1004f0b0  led_mask_apply

/* Applies a 6-byte LED mask to the 12-nibble payload: each nibble replaces the LED state, 8 leaves
   it unchanged, then re-sends the resulting bytes */

undefined4
led_mask_apply(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
              undefined1 *param_5)

{
  byte bVar1;
  undefined4 extraout_r1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  undefined1 *puVar9;
  byte local_20 [12];
  
  rom_memcpy(local_20,DAT_1004f404 + 8,6);
  uVar8 = param_2 + ~(uint)*DAT_1004f408 & 0xffff;
  uVar2 = uVar8;
  log_printf(DAT_1004f410,DAT_1004f40c,uVar8,param_2,param_3);
  FUN_1004cf2c();
  if (uVar8 - 1 < 0x10) {
    FUN_10056e18();
    log_printf(DAT_1004f414,extraout_r1,uVar2 << 0x1a,(int)param_5 << 2,param_3);
    for (puVar9 = param_5; (int)puVar9 - (int)param_5 < 0; puVar9 = puVar9 + 1) {
      log_printf(DAT_1004f418,*puVar9);
    }
    log_printf(DAT_1004f41c);
    uVar3 = DAT_1004f424;
    if (*(char *)(DAT_1004f420 + 0x11) != '\x02') {
      cVar7 = '\x02';
      iVar6 = 0;
      rom_memcpy(DAT_1004f428,param_5,0);
      *DAT_1004f42c = 0;
      do {
        iVar4 = DAT_1004f428 + iVar6;
        bVar1 = *(byte *)(iVar4 + 1);
        if (bVar1 >> 4 != 8) {
          pbVar5 = (byte *)(iVar6 + 0x57 + DAT_1004f420);
          *pbVar5 = *pbVar5 & 0xf | bVar1 & 0xf0;
          local_20[iVar6] = bVar1;
          if ((bVar1 >> 4) - 2 < 2) {
            FUN_100519ec(cVar7 + -1);
          }
          else {
            led_encode_b_send();
          }
        }
        bVar1 = *(byte *)(iVar4 + 1);
        uVar2 = bVar1 & 0xf;
        if (uVar2 != 8) {
          pbVar5 = (byte *)(iVar6 + 0x57 + DAT_1004f420);
          *pbVar5 = *pbVar5 & 0xf0 | (byte)uVar2;
          local_20[iVar6] = bVar1;
          if (uVar2 - 2 < 2) {
            FUN_100519ec(cVar7);
          }
          else {
            led_encode_b_send();
          }
        }
        iVar4 = DAT_1004f420;
        cVar7 = cVar7 + '\x02';
        iVar6 = iVar6 + 1;
      } while (iVar6 != 6);
      if (*(char *)(DAT_1004f420 + 0x12) == '\0') {
        FUN_10050354(*(undefined1 *)(DAT_1004f420 + 8),*(undefined1 *)(DAT_1004f420 + 9),
                     *(undefined1 *)(DAT_1004f420 + 10),*(undefined1 *)(DAT_1004f420 + 0xb),
                     *(undefined1 *)(DAT_1004f420 + 0xc));
        *(undefined1 *)(iVar4 + 0x12) = 1;
        FUN_1004eae0();
        if (*DAT_1004f430 != '\0') {
          *DAT_1004f434 = 1;
          app_msg_post(0x2d,100);
        }
        FUN_10051564();
      }
      FUN_1004fd78(local_20[0],local_20[1],local_20[2],local_20[3],local_20[4],local_20[5]);
      uVar3 = DAT_1004f438;
    }
    log_printf(uVar3,0);
    uVar3 = 0;
  }
  else {
    uVar3 = 10;
  }
  FUN_100522c8(param_1,param_2,uVar3);
  return 0;
}

// FUNC 0x1004f6c8  FUN_1004f6c8

void FUN_1004f6c8(undefined2 param_1)

{
  *DAT_1004f6d0 = param_1;
  return;
}

// FUNC 0x1004f710  rx_buffer_toggle

/* Flips the receive buffer selector */

void rx_buffer_toggle(void)

{
  char cVar1;
  
  if (*DAT_1004f724 == '\x01') {
    cVar1 = '\0';
  }
  else {
    cVar1 = *DAT_1004f724 + '\x01';
  }
  *DAT_1004f724 = cVar1;
  return;
}

// FUNC 0x1004f728  uart0_rx_callback

/* Feeds received UART0 bytes into the 0x20003481 ring buffer */

void uart0_rx_callback(undefined1 param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  
  app_msg_cancel(0x28);
  app_msg_post(0x28,0x14);
  pbVar2 = DAT_1004f778;
  if ((*DAT_1004f778 + 1 & 1) != *DAT_1004f77c) {
    app_msg_cancel(0x28);
    app_msg_post(0x28,0x14);
    pbVar3 = DAT_1004f780;
    bVar1 = *DAT_1004f780;
    uVar4 = bVar1 + 1;
    iVar5 = DAT_1004f784 + (uint)*pbVar2 * 0x20;
    *DAT_1004f780 = (byte)uVar4;
    *(undefined1 *)(iVar5 + (uint)bVar1) = param_1;
    if (0x1f < (uVar4 & 0xff)) {
      *pbVar3 = 0;
    }
  }
  return;
}

// FUNC 0x1004f788  uart1_rx_callback

/* Feeds received UART1 log bytes into a second ring buffer */

void uart1_rx_callback(undefined1 param_1)

{
  byte bVar1;
  
  app_msg_cancel(0x37);
  app_msg_post(0x37,0x14);
  bVar1 = *DAT_1004f7b4;
  if (bVar1 < 0x20) {
    *DAT_1004f7b4 = bVar1 + 1;
    *(undefined1 *)(DAT_1004f7b8 + (uint)bVar1) = param_1;
  }
  else {
    *DAT_1004f7b4 = 0;
  }
  return;
}

// FUNC 0x1004f7bc  key_highlight_clear

/* Stops the highlight timer and clears the active flag */

void key_highlight_clear(int param_1)

{
  char *pcVar1;
  
  pcVar1 = key_highlight_active;
  if (param_1 == 0x37) {
    if (*key_highlight_active != '\0') {
      console_command_handler(DAT_1004f7dc);
      *pcVar1 = '\0';
    }
  }
  return;
}

// FUNC 0x1004f7e0  key_highlight_tick

/* Decrements the per-key highlight counters, one 0x26-byte entry each */

void key_highlight_tick(void)

{
  short *psVar1;
  short *psVar2;
  
  FUN_100538e8(0xc,0);
  psVar2 = (short *)(DAT_1004f80c + 2);
  psVar1 = (short *)(DAT_1004f80c + DAT_1004f810);
  do {
    if (((char)psVar2[-1] != '\0') && (*psVar2 != 0)) {
      *psVar2 = *psVar2 + -1;
    }
    psVar2 = psVar2 + 0x13;
  } while (psVar2 != psVar1);
  return;
}

// FUNC 0x1004f814  sum8_checksum

/* Low byte of the byte sum, used as the frame checksum */

char sum8_checksum(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1 + param_2;
  cVar1 = '\0';
  for (; param_1 != pcVar2; param_1 = param_1 + 1) {
    cVar1 = cVar1 + *param_1;
  }
  return cVar1;
}

// FUNC 0x1004fcf8  tx_frame_enqueue

/* Builds seq/dir/type/flag/payload/sum into a 0x14-entry TX queue with a per-frame timer */

void tx_frame_enqueue(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                     undefined4 param_5,byte param_6)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = DAT_1004fd74;
  uVar5 = (uint)param_6;
  uVar4 = (uint)*DAT_1004fd70;
  while( true ) {
    if (0x13 < uVar4) {
      return;
    }
    iVar2 = uVar4 * 0x26;
    if (*(char *)(iVar2 + DAT_1004fd74) == '\0') break;
    uVar4 = uVar4 + 1 & 0xff;
    if (uVar4 == 0x14) {
      uVar4 = 0;
    }
    if (uVar4 == *DAT_1004fd70) {
      return;
    }
  }
  *(undefined1 *)(DAT_1004fd74 + iVar2) = 1;
  iVar3 = iVar3 + iVar2;
  *(undefined2 *)(iVar3 + 2) = 0;
  *(undefined1 *)(iVar3 + 6) = param_2;
  *(undefined1 *)(iVar3 + 4) = param_4;
  *(undefined1 *)(iVar3 + 5) = param_1;
  *(undefined1 *)(iVar3 + 7) = param_3;
  rom_memcpy(iVar3 + 8,param_5,uVar5);
  uVar1 = sum8_checksum(iVar3 + 5,uVar5 + 3 & 0xff);
  *(undefined1 *)(iVar3 + uVar5 + 8) = uVar1;
  *(byte *)(iVar3 + 0x25) = param_6 + 4;
  return;
}

// FUNC 0x1004fd78  base_frame_send

void FUN_1004fd78(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5,undefined1 param_6)

{
  char cVar1;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  
  cVar1 = *DAT_1004fdb4;
  *DAT_1004fdb4 = cVar1 + '\x01';
  local_20 = 0xc;
  local_1b = param_5;
  local_1a = param_6;
  local_1f = param_1;
  local_1e = param_2;
  local_1d = param_3;
  local_1c = param_4;
  tx_frame_enqueue(cVar1,0,8,2,&local_20,7);
  return;
}

// FUNC 0x1004fdb8  FUN_1004fdb8

void FUN_1004fdb8(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  char cVar1;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  
  cVar1 = *DAT_1004fdf4;
  *DAT_1004fdf4 = cVar1 + '\x01';
  local_1c = param_5;
  local_1b = param_6;
  local_1a = param_7;
  local_20 = param_1;
  local_1f = param_2;
  local_1e = param_3;
  local_1d = param_4;
  tx_frame_enqueue(cVar1,0,7,2,&local_20,7);
  return;
}

// FUNC 0x1004fdf8  all_leds_blink

/* Alternates an all-off frame and 0x11 (all red) every 200 ms; global only, no per-channel flash */

undefined8 all_leds_blink(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  local_c = (undefined1)param_2;
  local_b = (undefined1)((uint)param_2 >> 8);
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  local_10 = (undefined1)param_1;
  local_f = (undefined1)((uint)param_1 >> 8);
  local_e = (undefined1)((uint)param_1 >> 0x10);
  local_d = (undefined1)((uint)param_1 >> 0x18);
  bVar1 = *all_leds_blink_phase + 1;
  *all_leds_blink_phase = bVar1;
  uStack_8 = param_3;
  if ((int)((uint)bVar1 << 0x1f) < 0) {
    local_10 = 0;
  }
  else {
    if (3 < bVar1) {
      led_frame_send(DAT_1004fe3c);
      goto LAB_1004fe36;
    }
    local_10 = 0x11;
  }
  local_f = local_10;
  local_e = local_10;
  local_d = local_10;
  local_c = local_10;
  local_b = local_10;
  led_frame_send(&local_10);
  app_msg_post(0x36,200);
LAB_1004fe36:
  return CONCAT26(uStack_a,CONCAT15(local_b,CONCAT14(local_c,CONCAT13(local_d,CONCAT12(local_e,
                                                  CONCAT11(local_f,local_10))))));
}

// FUNC 0x1004fe40  all_leds_flash_green

/* Sends 0x55 (green on all LEDs) up to three times, then the stored frame */

undefined8 all_leds_flash_green(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  local_c = (undefined1)param_2;
  local_b = (undefined1)((uint)param_2 >> 8);
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  local_10 = (undefined1)param_1;
  local_f = (undefined1)((uint)param_1 >> 8);
  local_e = (undefined1)((uint)param_1 >> 0x10);
  local_d = (undefined1)((uint)param_1 >> 0x18);
  bVar1 = *all_leds_flash_phase + 1;
  *all_leds_flash_phase = bVar1;
  uStack_8 = param_3;
  if ((int)((uint)bVar1 << 0x1f) < 0) {
    local_10 = 0x44;
  }
  else {
    if (3 < bVar1) {
      led_frame_send(DAT_1004fe84);
      goto LAB_1004fe7e;
    }
    local_10 = 0x55;
  }
  local_f = local_10;
  local_e = local_10;
  local_d = local_10;
  local_c = local_10;
  local_b = local_10;
  led_frame_send(&local_10);
  app_msg_post(0x35,200);
LAB_1004fe7e:
  return CONCAT26(uStack_a,CONCAT15(local_b,CONCAT14(local_c,CONCAT13(local_d,CONCAT12(local_e,
                                                  CONCAT11(local_f,local_10))))));
}

// FUNC 0x1004fe88  all_leds_set

/* Sends 0x11 (red) to all eight LEDs, then posts 0x36 to start the flash loop */

undefined8 all_leds_set(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined2 uStack_a;
  
  local_c = (undefined1)param_2;
  local_b = (undefined1)((uint)param_2 >> 8);
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  local_10 = (undefined1)param_1;
  local_f = (undefined1)((uint)param_1 >> 8);
  local_e = (undefined1)((uint)param_1 >> 0x10);
  local_d = (undefined1)((uint)param_1 >> 0x18);
  *DAT_1004feb8 = 0;
  FUN_1004eac0();
  local_10 = 0x11;
  local_f = 0x11;
  local_e = 0x11;
  local_d = 0x11;
  local_c = 0x11;
  local_b = 0x11;
  led_frame_send(&local_10);
  *DAT_1004febc = 0;
  app_msg_post(0x36,200);
  return CONCAT26(uStack_a,CONCAT15(local_b,CONCAT14(local_c,CONCAT13(local_d,CONCAT12(local_e,
                                                  CONCAT11(local_f,local_10))))));
}

// FUNC 0x1004fec0  FUN_1004fec0

void FUN_1004fec0(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3,undefined4 param_4,
                 ushort param_5,undefined2 param_6)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint extraout_r1;
  
  uVar3 = FUN_10048ea8(param_6);
  uVar3 = FUN_10048930(uVar3,DAT_1004ffd4);
  uVar4 = FUN_10048ea8(100 - (uint)param_5);
  uVar4 = FUN_10048930(uVar4,uVar3);
  uVar5 = FUN_100486fc(uVar4,DAT_1004ffd8);
  FUN_10056d68(param_4,0x3c);
  uVar4 = FUN_10048ea8(extraout_r1 & 0xffff);
  uVar6 = FUN_10048b58(uVar3,uVar5);
  uVar4 = FUN_10048930(uVar4,uVar6);
  uVar4 = FUN_100486fc(uVar4,DAT_1004ffdc);
  bVar1 = FUN_10056d58(param_4,0x3c);
  if (bVar1 < 5) {
    FUN_10056ee8();
    uVar2 = FUN_10048224(uVar3,uVar4);
    *param_1 = uVar2;
    FUN_10048410(uVar5,uVar4);
    uVar2 = FUN_10048224();
    *param_2 = uVar2;
  }
  else {
    uVar2 = FUN_10048224(uVar3);
    *param_1 = uVar2;
    uVar2 = FUN_10048224(uVar5);
    *param_2 = uVar2;
    uVar5 = FUN_10048b58(uVar3,uVar4);
  }
  uVar2 = FUN_10048224(uVar5);
  *param_3 = uVar2;
  return;
}

// FUNC 0x1004ffe0  led_mode_update

/* Updates one channel nibble and sends the frame */

void led_mode_update(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte local_24;
  byte local_20 [4];
  undefined1 local_1c;
  undefined1 local_1b;
  
  rom_memcpy(local_20,DAT_10050158,6);
  iVar3 = DAT_1005015c;
  uVar5 = param_1 - 1U & 0xff;
  *(undefined1 *)(DAT_1005015c + 0x5d) = 0;
  uVar6 = uVar5 >> 1;
  if ((int)(uVar5 << 0x1f) < 0) {
    bVar1 = *(byte *)(iVar3 + uVar6 + 0x57);
    uVar5 = bVar1 & 0xf;
    if (1 < uVar5 - 2) {
      rom_memcpy(local_20,iVar3 + 0x57,6);
    }
    if (param_2 == 1) {
      bVar2 = 1;
      if (((bVar1 & 0xf) != 0) && (bVar2 = 0, uVar5 != 1)) {
        local_24 = (byte)(uVar5 - 2);
        bVar2 = 3;
        if ((((1 < local_24) && ((bVar2 = 5, uVar5 != 4 && (bVar2 = 4, uVar5 != 5)))) &&
            (bVar2 = 7, uVar5 != 6)) && (bVar2 = 6, uVar5 != 7)) {
          bVar2 = 8;
        }
      }
      local_20[uVar6] = bVar2 | local_20[uVar6] & 0xf0;
    }
    else {
      if (param_2 != 3) {
        return;
      }
      if (1 < (*(byte *)(DAT_1005015c + uVar6 + 0x57) & 0xf) - 2) {
        return;
      }
      local_20[uVar6] = local_20[uVar6] & 0xf0 | 2;
    }
    uVar5 = local_20[uVar6] & 0xf;
  }
  else {
    uVar4 = (uint)(*(byte *)(iVar3 + uVar6 + 0x57) >> 4);
    if (1 < uVar4 - 2) {
      rom_memcpy(local_20,iVar3 + 0x57,6);
    }
    if (param_2 == 1) {
      iVar3 = 1;
      if ((uVar4 != 0) && (iVar3 = 0, uVar4 != 1)) {
        local_24 = (byte)(uVar4 - 2);
        iVar3 = 3;
        if ((1 < local_24) &&
           ((((iVar3 = 5, uVar4 != 4 && (iVar3 = 4, uVar4 != 5)) && (iVar3 = 7, uVar4 != 6)) &&
            (iVar3 = 6, uVar4 != 7)))) {
          iVar3 = 8;
        }
      }
      local_20[uVar6] = (byte)(iVar3 << 4) | local_20[uVar6] & 0xf;
    }
    else {
      if (param_2 != 3) {
        return;
      }
      uVar6 = uVar5 >> 1;
      if (1 < (*(byte *)(DAT_1005015c + uVar6 + 0x57) >> 4) - 2) {
        return;
      }
      local_20[uVar6] = local_20[uVar6] & 0xf | 0x20;
    }
    uVar5 = (uint)(local_20[uVar5 >> 1] >> 4);
  }
  if (uVar5 - 2 < 2) {
    FUN_100519ec(param_1,uVar5,local_20);
  }
  else {
    led_encode_b_send(param_1,uVar5,local_20);
  }
  FUN_1004fd78(local_20[0],local_20[1],local_20[2],local_20[3],local_1c,local_1b);
  return;
}

// FUNC 0x10050160  led_color_set

/* Stores a color nibble for one LED: selector 0..3 -> 1, 2, 5, 7 */

void led_color_set(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  if (param_2 == 0) {
    pbVar3 = (byte *)(DAT_100501f8 + (param_1 >> 1) + 0x57);
    if ((param_1 & 1) != 0) {
      bVar2 = *pbVar3 & 0xf0 | 1;
      goto LAB_100501f4;
    }
    bVar2 = *pbVar3 & 0xf;
    bVar1 = 0x10;
  }
  else if (param_2 == 1) {
    pbVar3 = (byte *)(DAT_100501f8 + (param_1 >> 1) + 0x57);
    if ((param_1 & 1) == 0) {
      bVar2 = *pbVar3 & 0xf;
      bVar1 = 0x20;
    }
    else {
      bVar2 = *pbVar3 & 0xf0;
      bVar1 = 2;
    }
  }
  else if (param_2 == 2) {
    pbVar3 = (byte *)(DAT_100501f8 + (param_1 >> 1) + 0x57);
    if ((int)(param_1 << 0x1f) < 0) {
      bVar2 = *pbVar3 & 0xf0;
      bVar1 = 5;
    }
    else {
      bVar2 = *pbVar3 & 0xf;
      bVar1 = 0x50;
    }
  }
  else {
    if (param_2 != 3) {
      return;
    }
    pbVar3 = (byte *)(DAT_100501f8 + (param_1 >> 1) + 0x57);
    if ((int)(param_1 << 0x1f) < 0) {
      bVar2 = *pbVar3 & 0xf0;
      bVar1 = 7;
    }
    else {
      bVar2 = *pbVar3 & 0xf;
      bVar1 = 0x70;
    }
  }
  bVar2 = bVar2 | bVar1;
LAB_100501f4:
  *pbVar3 = bVar2;
  return;
}

// FUNC 0x100501fc  mode_query

/* Searches the per-channel mode list for a value */

undefined4 mode_query(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar1 = 0;
  pcVar3 = DAT_10050234;
  do {
    if (*pcVar3 != '\0') {
      for (uVar2 = 0; (uVar2 & 0xff) < (uint)(byte)pcVar3[1]; uVar2 = uVar2 + 1) {
        if ((byte)pcVar3[uVar2 + 2] == param_1) {
          uVar1 = 1;
        }
      }
    }
    pcVar3 = pcVar3 + 0xe;
  } while (pcVar3 != DAT_10050238);
  return uVar1;
}

// FUNC 0x1005023c  tick_ms_read

undefined4 tick_ms_read(void)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  undefined8 uVar6;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c;
  undefined2 local_2a;
  undefined4 local_28;
  undefined1 local_24;
  
  *(undefined4 *)(DAT_100502c4 + 0x7c) = 0x400000;
  local_28 = 0;
  local_30 = 0;
  local_34 = 0;
  local_2c = 0;
  local_24 = 6;
  local_2a = 10;
  FUN_1004dae4(&local_34);
  FUN_1004da58(1);
  cVar4 = (char)local_2a;
  iVar5 = DAT_100502c8;
  do {
    uVar2 = FUN_1004da74();
    if ((uVar2 & 4) != 0) {
      iVar5 = 0;
      while (cVar4 != '\0') {
        uVar2 = FUN_1004da74();
        if ((uVar2 & 0x10) == 0) {
          uVar1 = FUN_1004da80();
          cVar4 = cVar4 + -1;
          iVar5 = iVar5 + (uint)uVar1;
        }
      }
      FUN_1004da58(0);
      FUN_10056d58(iVar5,local_2a);
      uVar6 = FUN_1004aae0();
      FUN_10049e54((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_100502cc,DAT_100502d0);
      uVar3 = FUN_1004a9f0();
      return uVar3;
    }
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return 0xffffffff;
}

// FUNC 0x100502d4  led_channels_flush

void led_channels_flush(void)

{
  led_channel0_send_now(0);
  led_channel1_send_now(0);
  led_channel2_send_now(0);
  return;
}

// FUNC 0x100502ec  setting_mode_exit

void setting_mode_exit(void)

{
  int iVar1;
  
  iVar1 = DAT_10050320;
  if (*(char *)(DAT_10050320 + 0x12) == '\x01') {
    led_channels_flush();
    led_channel4_send_now(4);
    *(undefined1 *)(iVar1 + 0x12) = 0;
    FUN_1004ead0();
    *DAT_10050324 = 0;
    app_msg_cancel(0x2d);
    FUN_10051564();
  }
  log_printf(DAT_10050328);
  return;
}

// FUNC 0x1005032c  setting_mode_exit_confirm

void setting_mode_exit_confirm(void)

{
  int iVar1;
  
  iVar1 = DAT_10050350;
  if (*(char *)(DAT_10050350 + 0xa4) == '\x01') {
    FUN_100502ec();
  }
  *(undefined1 *)(iVar1 + 0xa4) = 0;
  FUN_1004eac0();
  return;
}

// FUNC 0x10050354  base_frame_process

void FUN_10050354(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined1 param_5)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = FUN_10048f38(param_5);
  uVar3 = FUN_100486fc(uVar3,DAT_10050440);
  uVar5 = param_1;
  if (param_3 < param_1) {
    uVar5 = param_3 & 0xff;
  }
  bVar1 = (byte)uVar5;
  if (param_2 < (uVar5 & 0xff)) {
    bVar1 = (byte)param_2;
  }
  uVar5 = (uint)bVar1;
  bVar1 = FUN_10056e98(uVar5 << 1,3);
  uVar6 = (uint)bVar1;
  uVar4 = FUN_10048ea8((param_1 - uVar5 & 0xff) + uVar6 & 0xff);
  uVar4 = FUN_10048930(uVar4,DAT_10050444);
  uVar4 = FUN_100486fc(uVar4,DAT_10050440);
  FUN_10048930(uVar4,uVar3);
  uVar2 = FUN_10048224();
  led_channel0_send_now(uVar2);
  uVar4 = FUN_10048ea8(uVar6 + (param_2 - uVar5 & 0xff) & 0xff);
  uVar4 = FUN_10048930(uVar4,DAT_10050444);
  uVar4 = FUN_100486fc(uVar4,DAT_10050440);
  FUN_10048930(uVar4,uVar3);
  uVar2 = FUN_10048224();
  led_channel2_send_now(uVar2);
  uVar4 = FUN_10048ea8(uVar6 + (param_3 - uVar5 & 0xff) & 0xff);
  uVar4 = FUN_10048930(uVar4,DAT_10050444);
  uVar4 = FUN_100486fc(uVar4,DAT_10050440);
  FUN_10048930(uVar4,uVar3);
  uVar2 = FUN_10048224();
  led_channel1_send_now(uVar2);
  uVar4 = FUN_10048ea8(param_4);
  uVar4 = FUN_10048930(uVar4,DAT_10050444);
  uVar4 = FUN_100486fc(uVar4,DAT_10050440);
  FUN_10048930(uVar4,uVar3);
  uVar2 = FUN_10048224();
  led_channel3_send_now(uVar2);
  led_channel4_send_now(param_5);
  return;
}

// FUNC 0x10050448  ui_state_reset

undefined8 ui_state_reset(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  
  FUN_1004eb00();
  puVar3 = DAT_10050480;
  iVar2 = DAT_1005047c;
  *(undefined1 *)(DAT_1005047c + 0x11) = 0;
  *puVar3 = 0;
  app_msg_cancel(0x2f);
  app_msg_cancel(0x2e);
  bVar1 = *(byte *)(iVar2 + 0xc);
  FUN_10050354(*(undefined1 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 9),*(undefined1 *)(iVar2 + 10),
               *(undefined1 *)(iVar2 + 0xb));
  log_printf(DAT_10050484);
  return CONCAT44(param_2,(uint)bVar1);
}

// FUNC 0x10050488  ui_countdown

undefined8 ui_countdown(uint param_1,uint param_2)

{
  ushort *puVar1;
  undefined1 *puVar2;
  ushort uVar3;
  uint local_14;
  
  puVar1 = DAT_10050518;
  if (*DAT_10050510 != '\0') {
    *DAT_10050510 = *DAT_10050510 + -1;
    local_14 = param_2;
    goto LAB_1005050c;
  }
  *DAT_10050510 = *DAT_10050514;
  if (*DAT_1005051c == '\0') {
    if (*puVar1 == 0) {
      uVar3 = 0x166;
    }
    else {
      uVar3 = *puVar1 - 1;
    }
LAB_100504b6:
    *puVar1 = uVar3;
  }
  else if (*DAT_1005051c == '\x01') {
    if (*puVar1 < 0x167) {
      uVar3 = *puVar1 + 1;
      goto LAB_100504b6;
    }
    *puVar1 = 1;
  }
  puVar2 = DAT_10050524;
  local_14 = (uint)*DAT_10050520;
  FUN_1004fec0(DAT_10050524,DAT_10050524 + 1,DAT_10050524 + 2,*puVar1,*DAT_10050528);
  puVar2[3] = 0;
  puVar2[4] = 0xff;
  FUN_10050354(*puVar2,puVar2[1],puVar2[2],0,0xff);
  param_1 = (uint)(byte)puVar2[2];
  log_printf(DAT_1005052c,*puVar1,*puVar2,puVar2[1]);
LAB_1005050c:
  return CONCAT44(local_14,param_1);
}

// FUNC 0x10050530  key_event_dispatch

void key_event_dispatch(byte *param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  char cVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  short *psVar7;
  undefined2 *puVar8;
  byte *pbVar9;
  ushort *puVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  byte bVar18;
  short sVar19;
  undefined1 uVar20;
  byte bVar21;
  undefined1 *puVar22;
  int unaff_r4;
  int iVar23;
  undefined1 uVar24;
  undefined1 local_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  
  if (param_2 == 2) {
    puVar22 = (undefined1 *)(uint)param_1[2];
    if (puVar22 == (undefined1 *)0xd) {
      if (*param_1 == 0) goto LAB_100505a8;
      *(undefined1 *)(DAT_10050850 + 0x11) = 3;
      FUN_1004eaf0();
      app_msg_post(0x2e,DAT_10050854);
      app_msg_cancel(0x2c);
      uVar16 = DAT_1005085c;
      puVar22 = DAT_10050858;
      *DAT_10050858 = 0;
      log_printf(uVar16);
      FUN_1005129e();
    }
    if ((puVar22 == (undefined1 *)0xe) && (*param_1 != 0)) {
      cVar1 = *DAT_10050860;
      *DAT_10050860 = cVar1 + '\x01';
      unaff_r4 = 1;
      local_20 = 0;
      tx_frame_enqueue(cVar1,0,0xd,0,&local_20,1);
      *DAT_10050864 = 1;
      FUN_1004eab0();
      app_msg_post(0x34,DAT_10050868);
    }
  }
LAB_100505a8:
  if (param_1 + param_2 * 2 == param_1) {
    FUN_1005129e();
  }
  log_printf(DAT_10050870,DAT_1005086c,*param_1);
  iVar12 = DAT_10050f74;
  iVar11 = DAT_10050f68;
  iVar17 = DAT_10050c00;
  iVar15 = DAT_10050bf8;
  iVar23 = DAT_10050874;
  uVar14 = (uint)*param_1;
  if (uVar14 != 7) {
    if (uVar14 < 8) {
      if (uVar14 == 3) {
        uVar16 = 3;
        iVar15 = DAT_10050874;
        goto LAB_100507a8;
      }
      if (3 < uVar14) {
        if (uVar14 != 5) {
          if (5 < uVar14) {
            if (*(char *)(DAT_10050874 + 0x48) != '\0') {
              FUN_10051294();
            }
            iVar15 = DAT_10050c00;
            if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
              if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
                led_mode_update(6,1);
              }
              goto LAB_10050a60;
            }
            iVar17 = mode_query(6);
            cVar1 = *(char *)(iVar15 + 0x18);
            if (iVar17 == 0) {
              bVar18 = cVar1 + 1;
              if (3 < bVar18) {
LAB_10050a30:
                bVar18 = 0;
              }
LAB_10050a3a:
              *(byte *)(iVar15 + 0x18) = bVar18;
              led_color_set(5,*(undefined1 *)(iVar15 + 0x18));
            }
            else if (cVar1 != '\x01') {
              bVar18 = cVar1 + 1;
              if (3 < bVar18) goto LAB_10050a30;
              if (bVar18 == 1) {
                bVar18 = 2;
              }
              goto LAB_10050a3a;
            }
            app_msg_cancel(0x2a);
            app_msg_post(0x2a,DAT_10050bc8);
LAB_10050a60:
            *(undefined1 *)(iVar23 + 0x48) = 1;
            FUN_100507a0(DAT_10050c08);
            return;
          }
          if (*(char *)(DAT_10050874 + 0x30) != '\0') {
            FUN_10051294();
          }
          iVar23 = DAT_10050850;
          cVar1 = *(char *)(DAT_10050850 + 0x11);
          if (cVar1 != '\x02') {
            if (cVar1 == '\0') {
              led_mode_update(4,1);
            }
            else if (cVar1 == '\x03') {
              app_msg_cancel(0x2e);
              pbVar9 = DAT_10050bf0;
              if (*DAT_10050bcc == '\0') {
                *DAT_10050bd0 = 0xf;
                *DAT_10050bd4 = 0xf;
                *DAT_10050bd8 = 1;
                *DAT_10050bdc = 1;
                app_msg_post(0x2f,0x21);
                puVar10 = DAT_10050be0;
                if (*DAT_10050be0 < 0x167) {
                  *DAT_10050be0 = *DAT_10050be0 + 1;
                }
                else {
                  *DAT_10050be0 = 1;
                }
                puVar22 = DAT_10050be8;
                FUN_1004fec0(DAT_10050be8,DAT_10050be8 + 1,DAT_10050be8 + 2,*puVar10,*DAT_10050bec,
                             *DAT_10050be4);
                uVar20 = 0;
                puVar22[4] = 0xff;
                puVar22[3] = 0;
                uVar2 = puVar22[2];
                uVar3 = puVar22[1];
                uVar5 = *puVar22;
                uVar24 = 0xff;
              }
              else {
                if (*DAT_10050bf0 == 7) {
                  bVar18 = 0;
                }
                else {
                  bVar18 = *DAT_10050bf0 + 1;
                }
                *DAT_10050bf0 = bVar18;
                iVar23 = DAT_10050bf4 + (uint)*pbVar9 * 5;
                uVar20 = *(undefined1 *)(iVar23 + 3);
                uVar2 = *(undefined1 *)(iVar23 + 2);
                uVar3 = *(undefined1 *)(iVar23 + 1);
                uVar24 = *(undefined1 *)(iVar23 + 4);
                uVar5 = *(undefined1 *)((uint)*pbVar9 * 5 + DAT_10050bf4);
              }
              FUN_10050354(uVar5,uVar3,uVar2,uVar20,uVar24);
            }
            goto LAB_1005097e;
          }
          iVar15 = mode_query(4);
          cVar1 = *(char *)(iVar23 + 0x16);
          if (iVar15 == 0) {
            bVar18 = cVar1 + 1;
            if (3 < bVar18) {
LAB_1005084c:
              bVar18 = 0;
            }
LAB_100508be:
            *(byte *)(iVar23 + 0x16) = bVar18;
            led_color_set(3,*(undefined1 *)(iVar23 + 0x16));
          }
          else if (cVar1 != '\x01') {
            bVar18 = cVar1 + 1;
            if (3 < bVar18) goto LAB_1005084c;
            if (bVar18 == 1) {
              bVar18 = 2;
            }
            goto LAB_100508be;
          }
          app_msg_cancel(0x2a);
          app_msg_post(0x2a,DAT_10050bc8);
LAB_1005097e:
          uVar16 = DAT_10050bfc;
          *(undefined1 *)(DAT_10050bf8 + 0x30) = 1;
          FUN_100507a0(uVar16);
          return;
        }
        uVar16 = 5;
        if (*(char *)(DAT_10050874 + 0x3c) != '\0') {
          uVar16 = FUN_10051294();
        }
        iVar15 = DAT_10050c00;
        if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
          if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
            led_mode_update(uVar16,1);
          }
          goto LAB_100509ee;
        }
        iVar17 = mode_query();
        cVar1 = *(char *)(iVar15 + 0x17);
        if (iVar17 == 0) {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) {
LAB_100509c0:
            bVar18 = 0;
          }
LAB_100509ca:
          *(byte *)(iVar15 + 0x17) = bVar18;
          led_color_set(4,*(undefined1 *)(iVar15 + 0x17));
        }
        else if (cVar1 != '\x01') {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) goto LAB_100509c0;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_100509ca;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,DAT_10050bc8);
LAB_100509ee:
        *(undefined1 *)(iVar23 + 0x3c) = 1;
        FUN_100507a0(DAT_10050c04);
        return;
      }
      unaff_r4 = DAT_10050874;
      if (uVar14 != 1) {
        if (uVar14 < 2) {
          FUN_10050ec4();
        }
        if (*(char *)(iVar23 + 0x18) != '\0') {
          FUN_10051294();
        }
        iVar15 = DAT_10050850;
        if (*(char *)(DAT_10050850 + 0x11) != '\x02') {
          if (*(char *)(DAT_10050850 + 0x11) == '\0') {
            led_mode_update(2,1);
          }
          goto LAB_1005079a;
        }
        iVar17 = mode_query();
        cVar1 = *(char *)(iVar15 + 0x14);
        if (iVar17 == 0) {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) {
LAB_1005076a:
            bVar18 = 0;
          }
LAB_10050774:
          *(byte *)(iVar15 + 0x14) = bVar18;
          led_color_set(1,*(undefined1 *)(iVar15 + 0x14));
        }
        else if (cVar1 != '\x01') {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) goto LAB_1005076a;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050774;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,DAT_10050878);
LAB_1005079a:
        uVar16 = DAT_100508b0;
        *(undefined1 *)(iVar23 + 0x18) = 1;
        do {
          log_printf(uVar16);
          uVar16 = FUN_10051294();
          iVar15 = iVar23;
LAB_100507a8:
          cVar1 = *(char *)(iVar15 + 0x24);
          if (cVar1 != '\0') {
            uVar16 = FUN_10051294();
          }
          iVar23 = DAT_10050850;
          if (*(char *)(DAT_10050850 + 0x11) == '\x02') {
            iVar17 = mode_query();
            cVar4 = *(char *)(iVar23 + 0x15);
            if (iVar17 == 0) {
              bVar18 = cVar4 + 1;
              if (bVar18 < 4) {
LAB_100507e8:
                *(byte *)(iVar23 + 0x15) = bVar18;
              }
              else {
                *(undefined1 *)(iVar23 + 0x15) = 0;
              }
LAB_100507ea:
              led_color_set(2,*(undefined1 *)(iVar23 + 0x15));
            }
            else if (cVar4 != '\x01') {
              bVar18 = cVar4 + 1;
              if (bVar18 < 4) {
                if (bVar18 == 1) {
                  bVar18 = 2;
                }
                goto LAB_100507e8;
              }
              *(char *)(iVar23 + 0x15) = cVar1;
              goto LAB_100507ea;
            }
            app_msg_cancel(0x2a);
            app_msg_post(0x2a,DAT_10050878);
          }
          else if (*(char *)(DAT_10050850 + 0x11) == '\0') {
            led_mode_update(uVar16,1);
          }
          iVar23 = iVar15 + 5;
          *(undefined1 *)(iVar15 + 0x24) = 1;
          uVar16 = DAT_100508b4;
        } while( true );
      }
LAB_1005062e:
      if (*(char *)(unaff_r4 + 0xc) != '\0') {
        uVar14 = FUN_10051294();
      }
      iVar23 = DAT_10050850;
      cVar1 = *(char *)(DAT_10050850 + 0x11);
      if (cVar1 != '\x02') {
        if (cVar1 == '\0') {
          led_mode_update(uVar14,uVar14);
        }
        else if (cVar1 == '\x03') {
          app_msg_cancel(0x2e);
          pbVar9 = DAT_100508a4;
          if (*DAT_10050880 == '\0') {
            *DAT_10050884 = 0xf;
            *DAT_10050888 = 0xf;
            *DAT_1005088c = 0;
            *DAT_10050890 = 1;
            app_msg_post(0x2f,0x21);
            puVar8 = DAT_10050898;
            psVar7 = DAT_10050894;
            if (*DAT_10050894 == 0) {
              sVar19 = 0x166;
            }
            else {
              sVar19 = *DAT_10050894 + -1;
            }
            *DAT_10050894 = sVar19;
            puVar22 = DAT_100508a0;
            FUN_1004fec0(DAT_100508a0,DAT_100508a0 + 1,DAT_100508a0 + 2,*psVar7,*DAT_1005089c,
                         *puVar8);
            uVar20 = 0;
            puVar22[4] = 0xff;
            puVar22[3] = 0;
            uVar2 = puVar22[2];
            uVar3 = puVar22[1];
            uVar5 = *puVar22;
            uVar24 = 0xff;
          }
          else {
            if (*DAT_100508a4 == 0) {
              cVar1 = '\a';
            }
            else {
              cVar1 = -1;
            }
            *DAT_100508a4 = *DAT_100508a4 + cVar1;
            iVar23 = DAT_100508a8 + (uint)*pbVar9 * 5;
            uVar20 = *(undefined1 *)(iVar23 + 3);
            uVar2 = *(undefined1 *)(iVar23 + 2);
            uVar3 = *(undefined1 *)(iVar23 + 1);
            uVar24 = *(undefined1 *)(iVar23 + 4);
            uVar5 = *(undefined1 *)((uint)*pbVar9 * 5 + DAT_100508a8);
          }
          FUN_10050354(uVar5,uVar3,uVar2,uVar20,uVar24);
        }
        goto LAB_1005072e;
      }
      iVar15 = mode_query();
      cVar1 = *(char *)(iVar23 + 0x13);
      if (iVar15 == 0) {
        bVar18 = cVar1 + 1;
        if (3 < bVar18) {
LAB_10050660:
          bVar18 = 0;
        }
LAB_1005066a:
        *(byte *)(iVar23 + 0x13) = bVar18;
        led_color_set(0,*(undefined1 *)(iVar23 + 0x13));
      }
      else if (cVar1 != '\x01') {
        bVar18 = cVar1 + 1;
        if (3 < bVar18) goto LAB_10050660;
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_1005066a;
      }
      app_msg_cancel(0x2a);
      app_msg_post(0x2a,DAT_10050878);
      log_printf(DAT_1005087c,*(undefined1 *)(iVar23 + 0x13));
LAB_1005072e:
      uVar16 = DAT_100508ac;
      *(undefined1 *)(DAT_10050874 + 0xc) = 1;
      FUN_100507a0(uVar16);
      return;
    }
    if (uVar14 != 0xb) {
      if (0xb < uVar14) {
        if (uVar14 == 0xd) {
          if (*(char *)(DAT_10050f74 + 0x9c) != '\0') {
            FUN_10051294();
            return;
          }
          if (param_2 == 1) {
            if (*(char *)(DAT_10050f68 + 0x11) == '\x03') {
              *DAT_10050f80 = 1;
              FUN_1004eb00();
              app_msg_cancel(0x2e);
              pcVar13 = DAT_10050f84;
              *(undefined1 *)(iVar11 + 0x11) = 0;
              iVar23 = DAT_10050f98;
              puVar22 = DAT_10050f88;
              if (*pcVar13 == '\0') {
                bVar18 = DAT_10050f88[4];
                uVar14 = (uint)bVar18;
                if (uVar14 != 0) {
                  uVar6 = *DAT_10050f8c;
                  *(undefined1 *)(iVar11 + 8) = *DAT_10050f88;
                  *(undefined2 *)(iVar11 + 0xe) = uVar6;
                  *(undefined1 *)(iVar11 + 9) = puVar22[1];
                  uVar5 = puVar22[2];
                  *(byte *)(iVar11 + 0xc) = bVar18;
                  *(undefined1 *)(iVar11 + 10) = uVar5;
                  *(undefined1 *)(iVar11 + 0xb) = puVar22[3];
                  FUN_10050354();
                  FUN_10051564();
                  puVar22 = DAT_10050f90;
                  *DAT_10050f90 = *(undefined1 *)(iVar11 + 0xc);
                  puVar22[1] = *(undefined1 *)(iVar11 + 8);
                  puVar22[2] = *(undefined1 *)(iVar11 + 9);
                  puVar22[3] = *(undefined1 *)(iVar11 + 10);
                  FUN_1004ee58(0,9,puVar22,4,uVar14);
                }
              }
              else {
                bVar18 = *DAT_10050f94;
                *(byte *)(iVar11 + 0x10) = bVar18;
                iVar15 = (uint)bVar18 * 5;
                iVar17 = iVar23 + iVar15;
                uVar5 = *(undefined1 *)(iVar17 + 1);
                uVar20 = *(undefined1 *)(iVar17 + 2);
                uVar24 = *(undefined1 *)(iVar17 + 3);
                uVar2 = *(undefined1 *)(iVar17 + 4);
                *(undefined1 *)(iVar11 + 8) = *(undefined1 *)(iVar15 + iVar23);
                *(undefined1 *)(iVar11 + 9) = uVar5;
                *(undefined1 *)(iVar11 + 10) = uVar20;
                *(undefined1 *)(iVar11 + 0xb) = uVar24;
                *(undefined1 *)(iVar11 + 0xc) = uVar2;
                FUN_10050354();
                FUN_10051564();
              }
              *DAT_10050f80 = 1;
              local_20 = *(undefined1 *)(DAT_10050f68 + 0xc);
              uStack_1f = *(undefined1 *)(DAT_10050f68 + 8);
              uStack_1e = *(undefined1 *)(DAT_10050f68 + 9);
              uStack_1d = *(undefined1 *)(DAT_10050f68 + 10);
              uStack_1c = *(undefined1 *)(DAT_10050f68 + 0xb);
              cVar1 = *DAT_10050f9c;
              *DAT_10050f9c = cVar1 + '\x01';
              tx_frame_enqueue(cVar1,0xff,0xc,0,&local_20,5);
            }
            puVar22 = DAT_10050fa0;
            iVar23 = DAT_10050f68;
            if (*(char *)(DAT_10050f68 + 0x11) == '\x02') {
              *(undefined1 *)(DAT_10050f68 + 0x11) = 0;
              *puVar22 = 1;
              FUN_10051564();
              *DAT_10050fa4 = 0;
              app_msg_cancel(0x2b);
              app_msg_cancel(0x2a);
              FUN_1004fd78(*(undefined1 *)(iVar23 + 0x57),*(undefined1 *)(iVar23 + 0x58),
                           *(undefined1 *)(iVar23 + 0x59),*(undefined1 *)(iVar23 + 0x5a),
                           *(undefined1 *)(iVar23 + 0x5b),*(undefined1 *)(iVar23 + 0x5c));
            }
            uVar16 = DAT_10050fa8;
            *(undefined1 *)(DAT_10050f74 + 0x9c) = 1;
            FUN_100507a0(uVar16);
            return;
          }
          FUN_10051294();
          return;
        }
        if (0xc < uVar14) {
          if (uVar14 == 0xe) {
            uVar14 = FUN_10050ea2();
          }
          if (uVar14 == 0xff) {
            backlight_change_handler();
          }
          uVar14 = FUN_10051294();
          goto LAB_1005062e;
        }
        if (*(char *)(DAT_10050f74 + 0x90) != '\0') {
          FUN_10051294();
          return;
        }
        if (*(char *)(DAT_10050f68 + 0x11) != '\x02') {
          if (*(char *)(DAT_10050f68 + 0x11) == '\0') {
            led_mode_update(0xc,1);
          }
          goto LAB_10050d60;
        }
        iVar23 = mode_query(0xc);
        cVar1 = *(char *)(iVar11 + 0x1e);
        if (iVar23 == 0) {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) {
LAB_10050d30:
            bVar18 = 0;
          }
LAB_10050d3a:
          *(byte *)(iVar11 + 0x1e) = bVar18;
          led_color_set(0xb,*(undefined1 *)(iVar11 + 0x1e));
        }
        else if (cVar1 != '\x01') {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) goto LAB_10050d30;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050d3a;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,DAT_10050f6c);
LAB_10050d60:
        *(undefined1 *)(iVar12 + 0x90) = 1;
        FUN_100507a0(DAT_10050f7c);
        return;
      }
      if (uVar14 != 9) {
        if (9 < uVar14) {
          if (*(char *)(DAT_10050874 + 0x78) != '\0') {
            FUN_10051294();
            return;
          }
          if (*(char *)(DAT_10050f68 + 0x11) != '\x02') {
            if (*(char *)(DAT_10050f68 + 0x11) == '\0') {
              led_mode_update(10,1);
            }
            goto LAB_10050c7e;
          }
          iVar15 = mode_query(10);
          cVar1 = *(char *)(iVar11 + 0x1c);
          if (iVar15 == 0) {
            bVar18 = cVar1 + 1;
            if (3 < bVar18) {
LAB_10050c4e:
              bVar18 = 0;
            }
LAB_10050c58:
            *(byte *)(iVar11 + 0x1c) = bVar18;
            led_color_set(9,*(undefined1 *)(iVar11 + 0x1c));
          }
          else if (cVar1 != '\x01') {
            bVar18 = cVar1 + 1;
            if (3 < bVar18) goto LAB_10050c4e;
            if (bVar18 == 1) {
              bVar18 = 2;
            }
            goto LAB_10050c58;
          }
          app_msg_cancel(0x2a);
          app_msg_post(0x2a,DAT_10050f6c);
LAB_10050c7e:
          *(undefined1 *)(iVar23 + 0x78) = 1;
          FUN_100507a0(DAT_10050f70);
          return;
        }
        if (*(char *)(DAT_10050874 + 0x60) != '\0') {
          FUN_10051294();
          return;
        }
        if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
          if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
            led_mode_update(8,1);
          }
          goto LAB_10050b50;
        }
        iVar15 = mode_query(8);
        cVar1 = *(char *)(iVar17 + 0x1a);
        if (iVar15 == 0) {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) {
LAB_10050b20:
            bVar18 = 0;
          }
LAB_10050b2a:
          *(byte *)(iVar17 + 0x1a) = bVar18;
          led_color_set(7,*(undefined1 *)(iVar17 + 0x1a));
        }
        else if (cVar1 != '\x01') {
          bVar18 = cVar1 + 1;
          if (3 < bVar18) goto LAB_10050b20;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050b2a;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,DAT_10050bc8);
LAB_10050b50:
        *(undefined1 *)(iVar23 + 0x60) = 1;
        FUN_100507a0(DAT_10050c10);
        return;
      }
      if (*(char *)(DAT_10050874 + 0x6c) != '\0') {
        FUN_10051294();
        return;
      }
      if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
        if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
          led_mode_update(9,1);
        }
        goto LAB_10050bbc;
      }
      iVar15 = mode_query();
      cVar1 = *(char *)(iVar17 + 0x1b);
      if (iVar15 == 0) {
        bVar18 = cVar1 + 1;
        if (3 < bVar18) {
LAB_10050b8e:
          bVar18 = 0;
        }
LAB_10050b98:
        *(byte *)(iVar17 + 0x1b) = bVar18;
        led_color_set(8,*(undefined1 *)(iVar17 + 0x1b));
      }
      else if (cVar1 != '\x01') {
        bVar18 = cVar1 + 1;
        if (3 < bVar18) goto LAB_10050b8e;
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_10050b98;
      }
      app_msg_cancel(0x2a);
      app_msg_post(0x2a,DAT_10050bc8);
LAB_10050bbc:
      *(undefined1 *)(iVar23 + 0x60) = 1;
      FUN_100507a0(DAT_10050c14);
      return;
    }
    if (*(char *)(DAT_10050f74 + 0x84) != '\0') {
      FUN_10051294();
      return;
    }
    if (*(char *)(DAT_10050f68 + 0x11) != '\x02') {
      if (*(char *)(DAT_10050f68 + 0x11) == '\0') {
        led_mode_update(0xb,1);
      }
      goto LAB_10050cee;
    }
    iVar23 = mode_query();
    cVar1 = *(char *)(iVar11 + 0x1d);
    if (iVar23 == 0) {
      bVar18 = cVar1 + 1;
      if (bVar18 < 4) {
LAB_10050cca:
        *(byte *)(iVar11 + 0x1d) = bVar18;
      }
      else {
        *(undefined1 *)(iVar11 + 0x1d) = 0;
      }
LAB_10050ccc:
      led_color_set(10,*(undefined1 *)(iVar11 + 0x1d));
    }
    else if (cVar1 != '\x01') {
      bVar18 = cVar1 + 1;
      if (bVar18 < 4) {
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_10050cca;
      }
      *(undefined1 *)(iVar11 + 0x1d) = 0;
      goto LAB_10050ccc;
    }
    app_msg_cancel(0x2a);
    app_msg_post(0x2a,DAT_10050f6c);
LAB_10050cee:
    *(undefined1 *)(iVar12 + 0x84) = 1;
    FUN_100507a0(DAT_10050f78);
    return;
  }
  bVar18 = *(byte *)(DAT_10050bf8 + 0x54);
  uVar16 = 7;
  if (bVar18 != 0) {
    uVar16 = FUN_10051294();
  }
  iVar23 = DAT_10050c00;
  if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
    if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
      led_mode_update(uVar16,1);
    }
    goto LAB_10050ae0;
  }
  iVar17 = mode_query();
  cVar1 = *(char *)(iVar23 + 0x19);
  if (iVar17 == 0) {
    if ((byte)(cVar1 + 1U) < 4) {
      *(char *)(iVar23 + 0x19) = cVar1 + '\x01';
    }
    else {
      *(undefined1 *)(iVar23 + 0x19) = 0;
    }
    uVar5 = *(undefined1 *)(iVar23 + 0x19);
LAB_10050ac0:
    led_color_set(6,uVar5);
  }
  else if (cVar1 != '\x01') {
    bVar21 = cVar1 + 1;
    if ((bVar21 < 4) && (bVar18 = bVar21, bVar21 == 1)) {
      *(undefined1 *)(iVar23 + 0x19) = 2;
    }
    else {
      *(byte *)(iVar23 + 0x19) = bVar18;
    }
    uVar5 = *(undefined1 *)(DAT_10050c00 + 0x19);
    goto LAB_10050ac0;
  }
  app_msg_cancel(0x2a);
  app_msg_post(0x2a,DAT_10050bc8);
LAB_10050ae0:
  *(undefined1 *)(iVar15 + 0x54) = 1;
  FUN_100507a0(DAT_10050c0c);
  return;
}

// FUNC 0x100505b4  key_event_handler

/* Per-key actions: modes, backlight settings, multi-press work mode, temp all off/restore */

void key_event_handler(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  short *psVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  ushort *puVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  byte bVar18;
  short sVar19;
  undefined1 uVar20;
  byte bVar21;
  int unaff_r4;
  int iVar22;
  int unaff_r7;
  byte *in_stack_00000010;
  byte *in_stack_0000001c;
  
  if (in_stack_0000001c == in_stack_00000010) {
    FUN_1005129e();
  }
  log_printf(DAT_10050870,DAT_1005086c,*in_stack_00000010);
  iVar12 = DAT_10050f74;
  iVar11 = DAT_10050f68;
  iVar17 = DAT_10050c00;
  iVar15 = DAT_10050bf8;
  iVar22 = DAT_10050874;
  uVar14 = (uint)*in_stack_00000010;
  if (uVar14 != 7) {
    if (uVar14 < 8) {
      if (uVar14 == 3) {
        uVar16 = 3;
        iVar15 = DAT_10050874;
        goto LAB_100507a8;
      }
      if (3 < uVar14) {
        if (uVar14 != 5) {
          if (5 < uVar14) {
            if (*(char *)(DAT_10050874 + 0x48) != '\0') {
              FUN_10051294();
            }
            iVar15 = DAT_10050c00;
            if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
              if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
                led_mode_update(6,1);
              }
              goto LAB_10050a60;
            }
            iVar17 = mode_query(6);
            cVar4 = *(char *)(iVar15 + 0x18);
            if (iVar17 == 0) {
              bVar18 = cVar4 + 1;
              if (3 < bVar18) {
LAB_10050a30:
                bVar18 = 0;
              }
LAB_10050a3a:
              *(byte *)(iVar15 + 0x18) = bVar18;
              led_color_set(5,*(undefined1 *)(iVar15 + 0x18));
            }
            else if (cVar4 != '\x01') {
              bVar18 = cVar4 + 1;
              if (3 < bVar18) goto LAB_10050a30;
              if (bVar18 == 1) {
                bVar18 = 2;
              }
              goto LAB_10050a3a;
            }
            app_msg_cancel(0x2a);
            app_msg_post(0x2a,DAT_10050bc8);
LAB_10050a60:
            *(undefined1 *)(iVar22 + 0x48) = 1;
            FUN_100507a0(DAT_10050c08);
            return;
          }
          if (*(char *)(DAT_10050874 + 0x30) != '\0') {
            FUN_10051294();
          }
          iVar22 = DAT_10050850;
          cVar4 = *(char *)(DAT_10050850 + 0x11);
          if (cVar4 != '\x02') {
            if (cVar4 == '\0') {
              led_mode_update(4,1);
            }
            else if (cVar4 == '\x03') {
              app_msg_cancel(0x2e);
              pbVar9 = DAT_10050bf0;
              if (*DAT_10050bcc == '\0') {
                *DAT_10050bd0 = 0xf;
                *DAT_10050bd4 = 0xf;
                *DAT_10050bd8 = 1;
                *DAT_10050bdc = 1;
                app_msg_post(0x2f,0x21);
                puVar10 = DAT_10050be0;
                if (*DAT_10050be0 < 0x167) {
                  *DAT_10050be0 = *DAT_10050be0 + 1;
                }
                else {
                  *DAT_10050be0 = 1;
                }
                puVar8 = DAT_10050be8;
                FUN_1004fec0(DAT_10050be8,DAT_10050be8 + 1,DAT_10050be8 + 2,*puVar10);
                uVar20 = 0;
                puVar8[4] = 0xff;
                puVar8[3] = 0;
                uVar1 = puVar8[2];
                uVar2 = puVar8[1];
                uVar5 = *puVar8;
              }
              else {
                if (*DAT_10050bf0 == 7) {
                  bVar18 = 0;
                }
                else {
                  bVar18 = *DAT_10050bf0 + 1;
                }
                *DAT_10050bf0 = bVar18;
                iVar22 = DAT_10050bf4 + (uint)*pbVar9 * 5;
                uVar20 = *(undefined1 *)(iVar22 + 3);
                uVar1 = *(undefined1 *)(iVar22 + 2);
                uVar2 = *(undefined1 *)(iVar22 + 1);
                uVar5 = *(undefined1 *)((uint)*pbVar9 * 5 + DAT_10050bf4);
              }
              FUN_10050354(uVar5,uVar2,uVar1,uVar20);
            }
            goto LAB_1005097e;
          }
          iVar15 = mode_query(4);
          cVar4 = *(char *)(iVar22 + 0x16);
          if (iVar15 == 0) {
            bVar18 = cVar4 + 1;
            if (3 < bVar18) {
LAB_1005084c:
              bVar18 = 0;
            }
LAB_100508be:
            *(byte *)(iVar22 + 0x16) = bVar18;
            led_color_set(3,*(undefined1 *)(iVar22 + 0x16));
          }
          else if (cVar4 != '\x01') {
            bVar18 = cVar4 + 1;
            if (3 < bVar18) goto LAB_1005084c;
            if (bVar18 == 1) {
              bVar18 = 2;
            }
            goto LAB_100508be;
          }
          app_msg_cancel(0x2a);
          app_msg_post(0x2a,DAT_10050bc8);
LAB_1005097e:
          uVar16 = DAT_10050bfc;
          *(undefined1 *)(DAT_10050bf8 + 0x30) = 1;
          FUN_100507a0(uVar16);
          return;
        }
        uVar16 = 5;
        if (*(char *)(DAT_10050874 + 0x3c) != '\0') {
          uVar16 = FUN_10051294();
        }
        iVar15 = DAT_10050c00;
        if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
          if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
            led_mode_update(uVar16,1);
          }
          goto LAB_100509ee;
        }
        iVar17 = mode_query();
        cVar4 = *(char *)(iVar15 + 0x17);
        if (iVar17 == 0) {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) {
LAB_100509c0:
            bVar18 = 0;
          }
LAB_100509ca:
          *(byte *)(iVar15 + 0x17) = bVar18;
          led_color_set(4,*(undefined1 *)(iVar15 + 0x17));
        }
        else if (cVar4 != '\x01') {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) goto LAB_100509c0;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_100509ca;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,DAT_10050bc8);
LAB_100509ee:
        *(undefined1 *)(iVar22 + 0x3c) = 1;
        FUN_100507a0(DAT_10050c04);
        return;
      }
      unaff_r4 = DAT_10050874;
      if (uVar14 != 1) {
        if (uVar14 < 2) {
          FUN_10050ec4();
        }
        if (*(char *)(iVar22 + 0x18) != '\0') {
          FUN_10051294();
        }
        iVar15 = DAT_10050850;
        if (*(char *)(DAT_10050850 + 0x11) != '\x02') {
          if (*(char *)(DAT_10050850 + 0x11) == '\0') {
            led_mode_update(2,1);
          }
          goto LAB_1005079a;
        }
        iVar17 = mode_query();
        cVar4 = *(char *)(iVar15 + 0x14);
        if (iVar17 == 0) {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) {
LAB_1005076a:
            bVar18 = 0;
          }
LAB_10050774:
          *(byte *)(iVar15 + 0x14) = bVar18;
          led_color_set(1,*(undefined1 *)(iVar15 + 0x14));
        }
        else if (cVar4 != '\x01') {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) goto LAB_1005076a;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050774;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,DAT_10050878);
LAB_1005079a:
        uVar16 = DAT_100508b0;
        *(undefined1 *)(iVar22 + 0x18) = 1;
        do {
          log_printf(uVar16);
          uVar16 = FUN_10051294();
          iVar15 = iVar22;
LAB_100507a8:
          cVar4 = *(char *)(iVar15 + 0x24);
          if (cVar4 != '\0') {
            uVar16 = FUN_10051294();
          }
          iVar22 = DAT_10050850;
          if (*(char *)(DAT_10050850 + 0x11) == '\x02') {
            iVar17 = mode_query();
            cVar3 = *(char *)(iVar22 + 0x15);
            if (iVar17 == 0) {
              bVar18 = cVar3 + 1;
              if (bVar18 < 4) {
LAB_100507e8:
                *(byte *)(iVar22 + 0x15) = bVar18;
              }
              else {
                *(undefined1 *)(iVar22 + 0x15) = 0;
              }
LAB_100507ea:
              led_color_set(2,*(undefined1 *)(iVar22 + 0x15));
            }
            else if (cVar3 != '\x01') {
              bVar18 = cVar3 + 1;
              if (bVar18 < 4) {
                if (bVar18 == 1) {
                  bVar18 = 2;
                }
                goto LAB_100507e8;
              }
              *(char *)(iVar22 + 0x15) = cVar4;
              goto LAB_100507ea;
            }
            app_msg_cancel(0x2a);
            app_msg_post(0x2a,DAT_10050878);
          }
          else if (*(char *)(DAT_10050850 + 0x11) == '\0') {
            led_mode_update(uVar16,1);
          }
          iVar22 = iVar15 + 5;
          *(undefined1 *)(iVar15 + 0x24) = 1;
          uVar16 = DAT_100508b4;
        } while( true );
      }
LAB_1005062e:
      if (*(char *)(unaff_r4 + 0xc) != '\0') {
        uVar14 = FUN_10051294();
      }
      iVar22 = DAT_10050850;
      cVar4 = *(char *)(DAT_10050850 + 0x11);
      if (cVar4 != '\x02') {
        if (cVar4 == '\0') {
          led_mode_update(uVar14,uVar14);
        }
        else if (cVar4 == '\x03') {
          app_msg_cancel(0x2e);
          pbVar9 = DAT_100508a4;
          if (*DAT_10050880 == '\0') {
            *DAT_10050884 = 0xf;
            *DAT_10050888 = 0xf;
            *DAT_1005088c = 0;
            *DAT_10050890 = 1;
            app_msg_post(0x2f,0x21);
            psVar7 = DAT_10050894;
            if (*DAT_10050894 == 0) {
              sVar19 = 0x166;
            }
            else {
              sVar19 = *DAT_10050894 + -1;
            }
            *DAT_10050894 = sVar19;
            puVar8 = DAT_100508a0;
            FUN_1004fec0(DAT_100508a0,DAT_100508a0 + 1,DAT_100508a0 + 2,*psVar7);
            uVar20 = 0;
            puVar8[4] = 0xff;
            puVar8[3] = 0;
            uVar1 = puVar8[2];
            uVar2 = puVar8[1];
            uVar5 = *puVar8;
          }
          else {
            if (*DAT_100508a4 == 0) {
              cVar4 = '\a';
            }
            else {
              cVar4 = -1;
            }
            *DAT_100508a4 = *DAT_100508a4 + cVar4;
            iVar22 = DAT_100508a8 + (uint)*pbVar9 * 5;
            uVar20 = *(undefined1 *)(iVar22 + 3);
            uVar1 = *(undefined1 *)(iVar22 + 2);
            uVar2 = *(undefined1 *)(iVar22 + 1);
            uVar5 = *(undefined1 *)((uint)*pbVar9 * 5 + DAT_100508a8);
          }
          FUN_10050354(uVar5,uVar2,uVar1,uVar20);
        }
        goto LAB_1005072e;
      }
      iVar15 = mode_query();
      cVar4 = *(char *)(iVar22 + 0x13);
      if (iVar15 == 0) {
        bVar18 = cVar4 + 1;
        if (3 < bVar18) {
LAB_10050660:
          bVar18 = 0;
        }
LAB_1005066a:
        *(byte *)(iVar22 + 0x13) = bVar18;
        led_color_set(0,*(undefined1 *)(iVar22 + 0x13));
      }
      else if (cVar4 != '\x01') {
        bVar18 = cVar4 + 1;
        if (3 < bVar18) goto LAB_10050660;
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_1005066a;
      }
      app_msg_cancel(0x2a);
      app_msg_post(0x2a,DAT_10050878);
      log_printf(DAT_1005087c,*(undefined1 *)(iVar22 + 0x13));
LAB_1005072e:
      uVar16 = DAT_100508ac;
      *(undefined1 *)(DAT_10050874 + 0xc) = 1;
      FUN_100507a0(uVar16);
      return;
    }
    if (uVar14 != 0xb) {
      if (0xb < uVar14) {
        if (uVar14 == 0xd) {
          if (*(char *)(DAT_10050f74 + 0x9c) != '\0') {
            FUN_10051294();
            return;
          }
          if (unaff_r7 == 1) {
            if (*(char *)(DAT_10050f68 + 0x11) == '\x03') {
              *DAT_10050f80 = 1;
              FUN_1004eb00();
              app_msg_cancel(0x2e);
              pcVar13 = DAT_10050f84;
              *(undefined1 *)(iVar11 + 0x11) = 0;
              iVar22 = DAT_10050f98;
              puVar8 = DAT_10050f88;
              if (*pcVar13 == '\0') {
                cVar4 = DAT_10050f88[4];
                if (cVar4 != '\0') {
                  uVar6 = *DAT_10050f8c;
                  *(undefined1 *)(iVar11 + 8) = *DAT_10050f88;
                  *(undefined2 *)(iVar11 + 0xe) = uVar6;
                  *(undefined1 *)(iVar11 + 9) = puVar8[1];
                  uVar5 = puVar8[2];
                  *(char *)(iVar11 + 0xc) = cVar4;
                  *(undefined1 *)(iVar11 + 10) = uVar5;
                  *(undefined1 *)(iVar11 + 0xb) = puVar8[3];
                  FUN_10050354();
                  FUN_10051564();
                  puVar8 = DAT_10050f90;
                  *DAT_10050f90 = *(undefined1 *)(iVar11 + 0xc);
                  puVar8[1] = *(undefined1 *)(iVar11 + 8);
                  puVar8[2] = *(undefined1 *)(iVar11 + 9);
                  puVar8[3] = *(undefined1 *)(iVar11 + 10);
                  FUN_1004ee58(0,9,puVar8,4);
                }
              }
              else {
                bVar18 = *DAT_10050f94;
                *(byte *)(iVar11 + 0x10) = bVar18;
                iVar15 = (uint)bVar18 * 5;
                iVar17 = iVar22 + iVar15;
                uVar5 = *(undefined1 *)(iVar17 + 1);
                uVar20 = *(undefined1 *)(iVar17 + 2);
                uVar1 = *(undefined1 *)(iVar17 + 3);
                uVar2 = *(undefined1 *)(iVar17 + 4);
                *(undefined1 *)(iVar11 + 8) = *(undefined1 *)(iVar15 + iVar22);
                *(undefined1 *)(iVar11 + 9) = uVar5;
                *(undefined1 *)(iVar11 + 10) = uVar20;
                *(undefined1 *)(iVar11 + 0xb) = uVar1;
                *(undefined1 *)(iVar11 + 0xc) = uVar2;
                FUN_10050354();
                FUN_10051564();
              }
              *DAT_10050f80 = 1;
              cVar4 = *DAT_10050f9c;
              *DAT_10050f9c = cVar4 + '\x01';
              tx_frame_enqueue(cVar4,0xff,0xc,0);
            }
            puVar8 = DAT_10050fa0;
            iVar22 = DAT_10050f68;
            if (*(char *)(DAT_10050f68 + 0x11) == '\x02') {
              *(undefined1 *)(DAT_10050f68 + 0x11) = 0;
              *puVar8 = 1;
              FUN_10051564();
              *DAT_10050fa4 = 0;
              app_msg_cancel(0x2b);
              app_msg_cancel(0x2a);
              FUN_1004fd78(*(undefined1 *)(iVar22 + 0x57),*(undefined1 *)(iVar22 + 0x58),
                           *(undefined1 *)(iVar22 + 0x59),*(undefined1 *)(iVar22 + 0x5a));
            }
            uVar16 = DAT_10050fa8;
            *(undefined1 *)(DAT_10050f74 + 0x9c) = 1;
            FUN_100507a0(uVar16);
            return;
          }
          FUN_10051294();
          return;
        }
        if (0xc < uVar14) {
          if (uVar14 == 0xe) {
            uVar14 = FUN_10050ea2();
          }
          if (uVar14 == 0xff) {
            backlight_change_handler();
          }
          uVar14 = FUN_10051294();
          goto LAB_1005062e;
        }
        if (*(char *)(DAT_10050f74 + 0x90) != '\0') {
          FUN_10051294();
          return;
        }
        if (*(char *)(DAT_10050f68 + 0x11) != '\x02') {
          if (*(char *)(DAT_10050f68 + 0x11) == '\0') {
            led_mode_update(0xc,1);
          }
          goto LAB_10050d60;
        }
        iVar22 = mode_query(0xc);
        cVar4 = *(char *)(iVar11 + 0x1e);
        if (iVar22 == 0) {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) {
LAB_10050d30:
            bVar18 = 0;
          }
LAB_10050d3a:
          *(byte *)(iVar11 + 0x1e) = bVar18;
          led_color_set(0xb,*(undefined1 *)(iVar11 + 0x1e));
        }
        else if (cVar4 != '\x01') {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) goto LAB_10050d30;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050d3a;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,DAT_10050f6c);
LAB_10050d60:
        *(undefined1 *)(iVar12 + 0x90) = 1;
        FUN_100507a0(DAT_10050f7c);
        return;
      }
      if (uVar14 != 9) {
        if (9 < uVar14) {
          if (*(char *)(DAT_10050874 + 0x78) != '\0') {
            FUN_10051294();
            return;
          }
          if (*(char *)(DAT_10050f68 + 0x11) != '\x02') {
            if (*(char *)(DAT_10050f68 + 0x11) == '\0') {
              led_mode_update(10,1);
            }
            goto LAB_10050c7e;
          }
          iVar15 = mode_query(10);
          cVar4 = *(char *)(iVar11 + 0x1c);
          if (iVar15 == 0) {
            bVar18 = cVar4 + 1;
            if (3 < bVar18) {
LAB_10050c4e:
              bVar18 = 0;
            }
LAB_10050c58:
            *(byte *)(iVar11 + 0x1c) = bVar18;
            led_color_set(9,*(undefined1 *)(iVar11 + 0x1c));
          }
          else if (cVar4 != '\x01') {
            bVar18 = cVar4 + 1;
            if (3 < bVar18) goto LAB_10050c4e;
            if (bVar18 == 1) {
              bVar18 = 2;
            }
            goto LAB_10050c58;
          }
          app_msg_cancel(0x2a);
          app_msg_post(0x2a,DAT_10050f6c);
LAB_10050c7e:
          *(undefined1 *)(iVar22 + 0x78) = 1;
          FUN_100507a0(DAT_10050f70);
          return;
        }
        if (*(char *)(DAT_10050874 + 0x60) != '\0') {
          FUN_10051294();
          return;
        }
        if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
          if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
            led_mode_update(8,1);
          }
          goto LAB_10050b50;
        }
        iVar15 = mode_query(8);
        cVar4 = *(char *)(iVar17 + 0x1a);
        if (iVar15 == 0) {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) {
LAB_10050b20:
            bVar18 = 0;
          }
LAB_10050b2a:
          *(byte *)(iVar17 + 0x1a) = bVar18;
          led_color_set(7,*(undefined1 *)(iVar17 + 0x1a));
        }
        else if (cVar4 != '\x01') {
          bVar18 = cVar4 + 1;
          if (3 < bVar18) goto LAB_10050b20;
          if (bVar18 == 1) {
            bVar18 = 2;
          }
          goto LAB_10050b2a;
        }
        app_msg_cancel(0x2a);
        app_msg_post(0x2a,DAT_10050bc8);
LAB_10050b50:
        *(undefined1 *)(iVar22 + 0x60) = 1;
        FUN_100507a0(DAT_10050c10);
        return;
      }
      if (*(char *)(DAT_10050874 + 0x6c) != '\0') {
        FUN_10051294();
        return;
      }
      if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
        if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
          led_mode_update(9,1);
        }
        goto LAB_10050bbc;
      }
      iVar15 = mode_query();
      cVar4 = *(char *)(iVar17 + 0x1b);
      if (iVar15 == 0) {
        bVar18 = cVar4 + 1;
        if (3 < bVar18) {
LAB_10050b8e:
          bVar18 = 0;
        }
LAB_10050b98:
        *(byte *)(iVar17 + 0x1b) = bVar18;
        led_color_set(8,*(undefined1 *)(iVar17 + 0x1b));
      }
      else if (cVar4 != '\x01') {
        bVar18 = cVar4 + 1;
        if (3 < bVar18) goto LAB_10050b8e;
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_10050b98;
      }
      app_msg_cancel(0x2a);
      app_msg_post(0x2a,DAT_10050bc8);
LAB_10050bbc:
      *(undefined1 *)(iVar22 + 0x60) = 1;
      FUN_100507a0(DAT_10050c14);
      return;
    }
    if (*(char *)(DAT_10050f74 + 0x84) != '\0') {
      FUN_10051294();
      return;
    }
    if (*(char *)(DAT_10050f68 + 0x11) != '\x02') {
      if (*(char *)(DAT_10050f68 + 0x11) == '\0') {
        led_mode_update(0xb,1);
      }
      goto LAB_10050cee;
    }
    iVar22 = mode_query();
    cVar4 = *(char *)(iVar11 + 0x1d);
    if (iVar22 == 0) {
      bVar18 = cVar4 + 1;
      if (bVar18 < 4) {
LAB_10050cca:
        *(byte *)(iVar11 + 0x1d) = bVar18;
      }
      else {
        *(undefined1 *)(iVar11 + 0x1d) = 0;
      }
LAB_10050ccc:
      led_color_set(10,*(undefined1 *)(iVar11 + 0x1d));
    }
    else if (cVar4 != '\x01') {
      bVar18 = cVar4 + 1;
      if (bVar18 < 4) {
        if (bVar18 == 1) {
          bVar18 = 2;
        }
        goto LAB_10050cca;
      }
      *(undefined1 *)(iVar11 + 0x1d) = 0;
      goto LAB_10050ccc;
    }
    app_msg_cancel(0x2a);
    app_msg_post(0x2a,DAT_10050f6c);
LAB_10050cee:
    *(undefined1 *)(iVar12 + 0x84) = 1;
    FUN_100507a0(DAT_10050f78);
    return;
  }
  bVar18 = *(byte *)(DAT_10050bf8 + 0x54);
  uVar16 = 7;
  if (bVar18 != 0) {
    uVar16 = FUN_10051294();
  }
  iVar22 = DAT_10050c00;
  if (*(char *)(DAT_10050c00 + 0x11) != '\x02') {
    if (*(char *)(DAT_10050c00 + 0x11) == '\0') {
      led_mode_update(uVar16,1);
    }
    goto LAB_10050ae0;
  }
  iVar17 = mode_query();
  cVar4 = *(char *)(iVar22 + 0x19);
  if (iVar17 == 0) {
    if ((byte)(cVar4 + 1U) < 4) {
      *(char *)(iVar22 + 0x19) = cVar4 + '\x01';
    }
    else {
      *(undefined1 *)(iVar22 + 0x19) = 0;
    }
    uVar5 = *(undefined1 *)(iVar22 + 0x19);
LAB_10050ac0:
    led_color_set(6,uVar5);
  }
  else if (cVar4 != '\x01') {
    bVar21 = cVar4 + 1;
    if ((bVar21 < 4) && (bVar18 = bVar21, bVar21 == 1)) {
      *(undefined1 *)(iVar22 + 0x19) = 2;
    }
    else {
      *(byte *)(iVar22 + 0x19) = bVar18;
    }
    uVar5 = *(undefined1 *)(DAT_10050c00 + 0x19);
    goto LAB_10050ac0;
  }
  app_msg_cancel(0x2a);
  app_msg_post(0x2a,DAT_10050bc8);
LAB_10050ae0:
  *(undefined1 *)(iVar15 + 0x54) = 1;
  FUN_100507a0(DAT_10050c0c);
  return;
}

// FUNC 0x100507a0  key_log_loop

void key_log_loop(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  int unaff_r4;
  
  do {
    log_printf(param_1);
    uVar4 = FUN_10051294();
    cVar1 = *(char *)(unaff_r4 + 0x24);
    if (cVar1 != '\0') {
      uVar4 = FUN_10051294();
    }
    iVar3 = DAT_10050850;
    if (*(char *)(DAT_10050850 + 0x11) == '\x02') {
      iVar5 = mode_query();
      cVar2 = *(char *)(iVar3 + 0x15);
      if (iVar5 == 0) {
        bVar6 = cVar2 + 1;
        if (bVar6 < 4) {
LAB_100507e8:
          *(byte *)(iVar3 + 0x15) = bVar6;
        }
        else {
          *(undefined1 *)(iVar3 + 0x15) = 0;
        }
LAB_100507ea:
        led_color_set(2,*(undefined1 *)(iVar3 + 0x15));
      }
      else if (cVar2 != '\x01') {
        bVar6 = cVar2 + 1;
        if (bVar6 < 4) {
          if (bVar6 == 1) {
            bVar6 = 2;
          }
          goto LAB_100507e8;
        }
        *(char *)(iVar3 + 0x15) = cVar1;
        goto LAB_100507ea;
      }
      app_msg_cancel(0x2a);
      app_msg_post(0x2a,DAT_10050878);
    }
    else if (*(char *)(DAT_10050850 + 0x11) == '\0') {
      led_mode_update(uVar4,1);
    }
    *(undefined1 *)(unaff_r4 + 0x24) = 1;
    param_1 = DAT_100508b4;
    unaff_r4 = unaff_r4 + 5;
  } while( true );
}

// FUNC 0x10050ea2  key_event_handler_temp_off

void key_event_handler_temp_off(void)

{
  int iVar1;
  int unaff_r7;
  
  iVar1 = DAT_10050f74;
  if (*(char *)(DAT_10050f74 + 0xa8) != '\0') {
    FUN_10051294();
    return;
  }
  if (unaff_r7 != 1) {
    FUN_10051294();
    return;
  }
  FUN_1004eab0();
  *(undefined1 *)(iVar1 + 0xa8) = 1;
  FUN_100507a0(DAT_10050fac);
  return;
}

// FUNC 0x10050ec4  temp_all_off

void temp_all_off(void)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  uint uVar11;
  char *pcVar12;
  int unaff_r4;
  byte *pbVar13;
  int unaff_r7;
  int in_stack_00000010;
  uint uStack00000018;
  
  iVar2 = DAT_10050f68;
  uStack00000018 = (uint)*(byte *)(DAT_10050f68 + 0x11);
  if (uStack00000018 == 3) {
    if ((*(char *)(unaff_r4 + 0xc) != '\0') || (*(char *)(unaff_r4 + 0x30) != '\0')) {
      *DAT_10050fb0 = 0;
      app_msg_cancel(0x2f);
      app_msg_cancel(0x2e);
      app_msg_post(0x2e,DAT_10050fb4);
      uVar4 = app_msg_release(0x2f);
      log_printf(DAT_10050fb8,uVar4);
    }
    if (*(char *)(in_stack_00000010 + 1) == '\x01') {
      *(undefined1 *)(unaff_r4 + 0xc) = 0;
      *(undefined4 *)(unaff_r4 + 0x10) = 0;
    }
    if (*(char *)(in_stack_00000010 + 1) == '\x04') {
      *(undefined1 *)(unaff_r4 + 0x30) = 0;
      *(undefined4 *)(unaff_r4 + 0x34) = 0;
    }
    puVar10 = DAT_10050fbc;
    if (*(char *)(in_stack_00000010 + 1) == '\r') {
      *(undefined1 *)(unaff_r4 + 0x9c) = 0;
      *(undefined4 *)(unaff_r4 + 0xa0) = 0;
      puVar10 = DAT_10050fbc;
    }
  }
  else {
    if (*DAT_10050f80 != '\0') {
      *DAT_10050f80 = '\0';
      FUN_1004eb00();
      goto LAB_100511a0;
    }
    if (*DAT_10050fa0 != '\0') {
      FUN_1004eae0();
      *DAT_10050fa0 = '\0';
      goto LAB_100511a0;
    }
    uVar11 = (uint)*(byte *)(DAT_100512a4 + (uint)*(byte *)(in_stack_00000010 + 1));
    if ((uVar11 == 0xd) && (unaff_r7 == 1)) {
      app_msg_cancel(0x32);
      app_msg_post(0x32,0x15e);
      pcVar12 = (char *)(unaff_r4 + 0xa4);
      cVar1 = *pcVar12;
      *pcVar12 = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x02') {
        *pcVar12 = '\0';
        puVar3 = DAT_100512a8;
        *(undefined4 *)(unaff_r4 + 0xa0) = 0;
        *puVar3 = 1;
        app_msg_post(0x2b,200);
        uVar4 = DAT_100512ac;
        *(undefined1 *)(iVar2 + 0x11) = 2;
        app_msg_post(0x2a,uVar4);
        app_msg_cancel(0x32);
        if (*(char *)(iVar2 + 0x12) == '\0') {
          FUN_10050354(*(undefined1 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 9),
                       *(undefined1 *)(iVar2 + 10),*(undefined1 *)(iVar2 + 0xb));
          *(undefined1 *)(iVar2 + 0x12) = 1;
          FUN_1004eae0();
          FUN_10051564();
        }
        else {
          app_msg_cancel(0x33);
        }
        log_printf(DAT_100512b0,2);
      }
      goto LAB_100511a0;
    }
    if (1 < uVar11 - 0xd) {
      if (uStack00000018 == 0) {
        led_mode_update((uint)*(byte *)(in_stack_00000010 + 1),3);
      }
      goto LAB_100511a0;
    }
    if ((((uStack00000018 != 0) || (uVar11 != 0xe)) || (unaff_r7 != 1)) || (*DAT_100512b4 != '\0'))
    goto LAB_100511a0;
    FUN_1004eac0();
    if (*(char *)(iVar2 + 0x5d) == '\0') {
      pbVar13 = (byte *)(iVar2 + 0x57);
      rom_memcpy(iVar2 + 0x5e,pbVar13,6);
      iVar5 = led_nibble_encode_a(*pbVar13 >> 4);
      uVar11 = led_nibble_encode_a(*pbVar13 & 0xf);
      iVar6 = led_nibble_encode_a(*(byte *)(iVar2 + 0x58) >> 4);
      uVar7 = led_nibble_encode_a(*(byte *)(iVar2 + 0x58) & 0xf);
      iVar8 = led_nibble_encode_a(*(byte *)(iVar2 + 0x59) >> 4);
      uVar9 = led_nibble_encode_a(*(byte *)(iVar2 + 0x59) & 0xf);
      led_nibble_encode_a(*(byte *)(iVar2 + 0x5a) >> 4);
      led_nibble_encode_a(*(byte *)(iVar2 + 0x5a) & 0xf);
      led_nibble_encode_a(*(byte *)(iVar2 + 0x5b) >> 4);
      led_nibble_encode_a(*(byte *)(iVar2 + 0x5b) & 0xf);
      led_nibble_encode_a(*(byte *)(iVar2 + 0x5c) >> 4);
      led_nibble_encode_a(*(byte *)(iVar2 + 0x5c) & 0xf);
      FUN_1004fdb8(uStack00000018,(iVar5 << 4 | uVar11) & 0xff,(iVar6 << 4 | uVar7) & 0xff,
                   (iVar8 << 4 | uVar9) & 0xff);
      puVar10 = PTR_s_temp_all_off_100512b8;
    }
    else {
      FUN_1004fdb8(*(char *)(iVar2 + 0x5d),*(undefined1 *)(iVar2 + 0x5e),
                   *(undefined1 *)(iVar2 + 0x5f),*(undefined1 *)(iVar2 + 0x60));
      puVar10 = PTR_s_temp_all_restore_100512bc;
    }
  }
  log_printf(puVar10);
LAB_100511a0:
  iVar2 = DAT_100512c0;
  *(undefined1 *)((uint)*(byte *)(in_stack_00000010 + 1) * 0xc + DAT_100512c0) = 0;
  *(undefined4 *)(iVar2 + (uint)*(byte *)(in_stack_00000010 + 1) * 0xc + 4) = 0;
  FUN_10051294();
  return;
}

// FUNC 0x100511ba  backlight_change_handler

/* Backlight change state machine; logs BL change 10 and 30 times */

void backlight_change_handler(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  char *pcVar9;
  int unaff_r7;
  int in_stack_00000014;
  
  iVar6 = DAT_100512c4;
  iVar2 = DAT_100512c0;
  if (*(char *)(DAT_100512c4 + 0x11) == '\x03') {
    pcVar9 = (char *)(DAT_100512c0 + 0x30);
    log_printf(DAT_100512c8,*(undefined1 *)(DAT_100512c0 + 0xc),*pcVar9);
    if (*DAT_100512cc == '\0') {
      if (*(char *)(iVar2 + 0xc) == '\0') goto LAB_10051224;
      iVar6 = *(int *)(iVar2 + 0x10);
      puVar5 = (undefined1 *)(iVar6 + 1);
      *(undefined1 **)(iVar2 + 0x10) = puVar5;
      while( true ) {
        uVar3 = DAT_100512d4;
        if (puVar5 == (undefined1 *)0x1) {
          iVar6 = 6;
          *DAT_100512d0 = 6;
          puVar5 = DAT_100512d8;
          *DAT_100512d8 = 6;
          FUN_100507a0(uVar3);
        }
        puVar4 = PTR_s_BL_change_10_times_100512dc;
        if (iVar6 - 1U < 3) {
          *DAT_100512d0 = 3;
          puVar5 = DAT_100512d8;
          *DAT_100512d8 = 3;
          FUN_100507a0(puVar4);
        }
        puVar4 = PTR_s_BL_change_30_times_100512e0;
        if (puVar5 < (undefined1 *)0x5) break;
        *DAT_100512d0 = 0;
        *DAT_100512d8 = 0;
        FUN_100507a0(puVar4);
LAB_10051224:
        if (*pcVar9 == '\0') break;
        iVar6 = *(int *)(iVar2 + 0x34);
        puVar5 = (undefined1 *)(iVar6 + 1);
        *(undefined1 **)(iVar2 + 0x34) = puVar5;
      }
    }
  }
  else if ((*(char *)(in_stack_00000014 + 1) == '\x0e') && (unaff_r7 == 1)) {
    pcVar9 = (char *)(DAT_100512c0 + 0xa8);
    if (*pcVar9 != '\0') {
      puVar8 = (uint *)(DAT_100512c0 + 0xac);
      uVar7 = *puVar8;
      *puVar8 = uVar7 + 1;
      if (9 < uVar7 + 1) {
        led_state_reset();
        FUN_10050354(*(undefined1 *)(iVar6 + 8),*(undefined1 *)(iVar6 + 9),
                     *(undefined1 *)(iVar6 + 10),*(undefined1 *)(iVar6 + 0xb));
        led_frame_send(DAT_100512e4);
        FUN_10051564();
        cVar1 = *DAT_100512e8;
        *DAT_100512e8 = cVar1 + '\x01';
        tx_frame_enqueue(cVar1,0,0xd);
        *puVar8 = 0;
        *pcVar9 = '\0';
      }
    }
  }
  key_event_handler();
  return;
}

// FUNC 0x10051294  key_event_tick

void key_event_tick(void)

{
  key_event_handler();
  return;
}

// FUNC 0x1005129e  key_event_noop

void key_event_noop(void)

{
  return;
}

// FUNC 0x100512ec  FUN_100512ec

void FUN_100512ec(void)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  undefined1 local_40;
  undefined1 local_38 [36];
  
  bVar5 = false;
  FUN_10056f28(local_38,0,0x1e);
  iVar9 = 1;
  FUN_10056d88();
  uVar7 = 0;
  bVar3 = false;
  bVar4 = false;
  pcVar8 = DAT_10051464;
  do {
    cVar1 = pcVar8[5];
    cVar2 = pcVar8[6];
    pcVar8[4] = cVar1;
    pcVar8[5] = cVar2;
    local_40 = (undefined1)iVar9;
    if (cVar1 == '\0') {
      if (cVar2 == '\x01') {
        local_38[uVar7 * 2] = *(undefined1 *)(iVar9 + DAT_10051468);
        local_38[uVar7 * 2 + 1] = local_40;
        uVar7 = uVar7 + 1 & 0xff;
        if (iVar9 == 0xe) {
          bVar5 = true;
        }
        if ((*(char *)(DAT_1005146c + 0x12) == '\0') && (iVar9 == 0xd)) {
          return;
        }
        log_printf(DAT_10051470,iVar9);
        bVar3 = true;
      }
    }
    else if (cVar1 == '\x01') {
      if (cVar2 == '\x01') {
        cVar1 = pcVar8[7];
        pcVar8[7] = cVar1 + 1U;
        iVar6 = uVar7 * 2;
        if ((byte)(cVar1 + 1U) < 0x19) {
          local_38[iVar6] = *(undefined1 *)(iVar9 + DAT_10051468);
          local_38[iVar6 + 1] = local_40;
          bVar4 = true;
        }
        else {
          local_38[iVar6] = 0xff;
          local_38[iVar6 + 1] = local_40;
          pcVar8[7] = '\0';
        }
        uVar7 = uVar7 + 1 & 0xff;
        if (iVar9 == 0xe) {
          bVar5 = true;
        }
      }
      else if (cVar2 == '\0') {
        local_38[uVar7 * 2] = 0;
        local_38[uVar7 * 2 + 1] = local_40;
        uVar7 = uVar7 + 1 & 0xff;
        pcVar8[7] = '\0';
        bVar3 = true;
        if (iVar9 == 0xe) {
          bVar5 = true;
        }
      }
    }
    iVar6 = DAT_1005146c;
    iVar9 = iVar9 + 1;
    pcVar8 = pcVar8 + 4;
  } while (iVar9 != 0xf);
  if ((!bVar3) && (bVar4)) {
    return;
  }
  if (uVar7 == 0) {
    return;
  }
  if ((bVar5) && (uVar7 == 1)) {
    if (*(char *)(DAT_1005146c + 0x12) == '\0') {
      FUN_10050354(*(undefined1 *)(DAT_1005146c + 8),*(undefined1 *)(DAT_1005146c + 9),
                   *(undefined1 *)(DAT_1005146c + 10),*(undefined1 *)(DAT_1005146c + 0xb),
                   *(undefined1 *)(DAT_1005146c + 0xc));
      pcVar8 = DAT_10051474;
      *(undefined1 *)(iVar6 + 0x12) = 1;
      if (*pcVar8 != '\0') {
        *DAT_10051478 = 1;
        app_msg_post(0x2d,100);
      }
      FUN_1004eae0();
      FUN_10051564();
      goto LAB_10051458;
    }
  }
  else if (*(char *)(DAT_1005146c + 0x12) == '\0') {
    FUN_10050354(*(undefined1 *)(DAT_1005146c + 8),*(undefined1 *)(DAT_1005146c + 9),
                 *(undefined1 *)(DAT_1005146c + 10),*(undefined1 *)(DAT_1005146c + 0xb),
                 *(undefined1 *)(DAT_1005146c + 0xc));
    pcVar8 = DAT_10051474;
    *(undefined1 *)(iVar6 + 0x12) = 1;
    if (*pcVar8 != '\0') {
      *DAT_10051478 = 1;
      app_msg_post(0x2d,100);
    }
    FUN_1004eae0();
    FUN_10051564();
    return;
  }
  app_msg_cancel(0x33);
LAB_10051458:
  FUN_10050530(local_38,uVar7);
  return;
}

// FUNC 0x1005147c  periodic_ui_update

undefined8 periodic_ui_update(uint param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  undefined4 local_10;
  
  uVar3 = FUN_1005023c();
  pbVar1 = DAT_10051514;
  bVar4 = 0;
  if (0xb6 < uVar3) {
    if (uVar3 - 0xb7 < 0xb6) {
      bVar4 = 1;
    }
    else if (uVar3 - 0x16d < 0x1b4) {
      bVar4 = 2;
    }
    else if (DAT_1005151c < uVar3 + DAT_10051518) {
      bVar4 = 4;
    }
    else {
      bVar4 = 3;
    }
  }
  *DAT_10051514 = bVar4;
  iVar2 = DAT_10051520;
  bVar4 = *(byte *)(DAT_10051520 + 0xc);
  uVar6 = (uint)bVar4;
  uVar3 = (uint)*(byte *)(DAT_10051524 + (uint)*pbVar1);
  if (uVar3 < uVar6) {
    if (uVar6 < 0x81) {
      if (uVar6 <= uVar3 + 1) {
LAB_100514ea:
        *(byte *)(DAT_10051520 + 0xc) = *(byte *)(DAT_10051524 + (uint)*pbVar1);
        goto LAB_100514f2;
      }
      cVar5 = bVar4 - 2;
    }
    else {
      cVar5 = bVar4 - 10;
    }
  }
  else {
    if (uVar3 <= uVar6) goto LAB_100514f2;
    if (uVar6 < 0x81) {
      cVar5 = bVar4 + 2;
    }
    else {
      cVar5 = bVar4 + 10;
      if ((int)(uVar3 - uVar6) < 10) goto LAB_100514ea;
    }
  }
  *(char *)(DAT_10051520 + 0xc) = cVar5;
LAB_100514f2:
  local_10 = param_1;
  if ((*DAT_10051528 == '\0') && (*(char *)(iVar2 + 0x11) != '\x03')) {
    local_10 = (uint)*(byte *)(iVar2 + 0xc);
    FUN_10050354(*(undefined1 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 9),*(undefined1 *)(iVar2 + 10),
                 *(undefined1 *)(iVar2 + 0xb));
  }
  return CONCAT44(param_2,local_10);
}

// FUNC 0x1005152c  key_event_post

undefined8 key_event_post(undefined4 param_1,undefined3 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  piVar1 = DAT_1005155c;
  uStack_14 = CONCAT13(8,param_2);
  uStack_10 = param_3;
  FUN_100539c0(0x97,(int)&uStack_14 + 3,DAT_1005155c);
  if (*piVar1 != DAT_10051560) {
    *piVar1 = DAT_10051560;
    piVar1[1] = 0;
    FUN_100539ae(0x97,8,piVar1);
  }
  return CONCAT44(uStack_14,param_1);
}

// FUNC 0x10051564  key_event_post_500ms

void key_event_post_500ms(void)

{
  app_msg_cancel(0x31);
  app_msg_post(0x31,500);
  return;
}

// FUNC 0x10051578  hex_decode

uint hex_decode(uint param_1)

{
  return (param_1 >> 4) * 10 + (param_1 & 0xf) & 0xff;
}

// FUNC 0x10051588  console_command_handler

/* Parses CRLF console commands: '?' queries three bytes, '=' sets six hex digits */

undefined8 console_command_handler(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  bool bVar10;
  int local_18;
  
  puVar6 = PTR_s_ERROR_10051650;
  if (((*(char *)(param_1 + param_2 + -2) == '\r') && (*(char *)(param_1 + param_2 + -1) == '\n'))
     && (iVar2 = rom_memcmp(param_1,DAT_1005163c,5), puVar6 = PTR_s_ERROR_10051650, iVar2 == 0)) {
    if (*(char *)(param_1 + 5) == '?') {
      FUN_1005152c();
      uVar9 = *(uint *)(DAT_10051640 + 4);
      uVar3 = FUN_10051578(uVar9 >> 0x10 & 0xff);
      uVar4 = FUN_10051578(uVar9 >> 8 & 0xff);
      local_18 = FUN_10051578(uVar9 & 0xff);
      log_printf(PTR_s__s_02d_02d_02d_10051648,PTR_DAT_10051644,uVar3,uVar4);
      goto LAB_1005163a;
    }
    if ((*(char *)(param_1 + 5) == '=') && (param_2 == 0xe)) {
      pbVar7 = (byte *)(param_1 + 6);
      cVar1 = '\0';
      pbVar8 = pbVar7;
      do {
        if (9 < *pbVar8 - 0x30) goto LAB_10051636;
        cVar1 = cVar1 + '\x01';
        pbVar8 = pbVar8 + 1;
      } while (cVar1 != '\x06');
      uVar5 = 0;
      uVar9 = 0x10;
      do {
        uVar5 = uVar5 | (((*pbVar7 - 0x30 & 0xff) << 4 | pbVar7[1] - 0x30) & 0xff) << (uVar9 & 0xff)
        ;
        pbVar7 = pbVar7 + 2;
        bVar10 = uVar9 != 0;
        uVar9 = uVar9 - 8;
      } while (bVar10);
      *(uint *)(DAT_10051640 + 4) = uVar5;
      FUN_100539ae(0x97,8);
      puVar6 = PTR_DAT_1005164c;
    }
  }
LAB_10051636:
  log_printf(puVar6);
  local_18 = param_1;
LAB_1005163a:
  return CONCAT44(param_2,local_18);
}

// FUNC 0x10051654  key_event_post_100ms

void key_event_post_100ms(void)

{
  int iVar1;
  
  iVar1 = FUN_100539ae(0x96,100,DAT_1005166c);
  if (iVar1 == 0) {
    log_printf(DAT_10051670);
  }
  return;
}

// FUNC 0x10051674  led_state_reset

/* Clears the LED state block at 0x20003908 */

void led_state_reset(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = DAT_100516d0;
  *(undefined1 *)((int)DAT_100516d0 + 9) = 0xff;
  *(undefined1 *)(puVar1 + 3) = 0xff;
  uVar2 = DAT_100516d4;
  *(undefined2 *)((int)puVar1 + 0xe) = 0x78;
  *(undefined1 *)((int)puVar1 + 0x12) = 1;
  *puVar1 = uVar2;
  *(undefined1 *)((int)puVar1 + 0x5d) = 0;
  puVar1[1] = 0;
  *(undefined1 *)((int)puVar1 + 10) = 0;
  *(undefined1 *)(puVar1 + 2) = 0;
  *(undefined1 *)((int)puVar1 + 0xb) = 0;
  *(undefined1 *)(puVar1 + 4) = 0;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  iVar4 = 0;
  do {
    iVar3 = iVar4 + 1;
    *(undefined1 *)((int)puVar1 + iVar4 + 0x13) = 0;
    iVar4 = iVar3;
  } while (iVar3 != 0xc);
  FUN_10056f28((int)puVar1 + 0x1f,0,0x38);
  iVar4 = 0;
  do {
    iVar3 = iVar4 + 1;
    *(undefined1 *)((int)puVar1 + iVar4 + 0x57) = 0;
    *(undefined1 *)((int)puVar1 + iVar4 + 0x5e) = 0;
    iVar4 = iVar3;
  } while (iVar3 != 6);
  return;
}

// FUNC 0x100516d8  led_frame_send

/* Builds 5A 00 <6 bytes> EE and sends it to UART3 */

void led_frame_send(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_1c [16];
  
  local_1c[0] = 0x5a;
  local_1c[2] = *param_1;
  iVar2 = 0;
  local_1c[3] = param_1[1];
  local_1c[4] = param_1[2];
  local_1c[1] = 0;
  local_1c[5] = param_1[3];
  local_1c[6] = param_1[4];
  local_1c[7] = param_1[5];
  local_1c[8] = 0xee;
  uart3_write(local_1c,9);
  log_printf(PTR_s_IND_DATA_SEND__10051728);
  do {
    puVar1 = local_1c + iVar2;
    iVar2 = iVar2 + 1;
    log_printf(PTR_s__02x_1005172c,*puVar1);
  } while (iVar2 != 9);
  log_printf(DAT_10051730);
  return;
}

// FUNC 0x10051734  led_nibble_encode_a

/* Odd to even nibble remap */

int led_nibble_encode_a(int param_1)

{
  if (param_1 == 1) {
    param_1 = 0;
  }
  else if (param_1 == 3) {
    param_1 = 2;
  }
  else if (param_1 == 5) {
    param_1 = 4;
  }
  else if (param_1 == 7) {
    param_1 = 6;
  }
  return param_1;
}

// FUNC 0x10051754  led_encode_a_send

/* Applies encoder A to the six LED payload bytes */

undefined8 led_encode_a_send(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  undefined1 local_19;
  undefined4 uStack_18;
  
  uStack_18 = param_3;
  FUN_1005152c();
  piVar1 = DAT_10051850;
  FUN_100539c0(0x96,&local_19,DAT_10051850);
  if (*piVar1 != DAT_10051854) {
    led_state_reset();
  }
  *DAT_10051858 = *(undefined2 *)((int)piVar1 + 0xe);
  *DAT_1005185c = (char)piVar1[4];
  if (*(char *)((int)piVar1 + 0x11) != '\0') {
    *(undefined1 *)((int)piVar1 + 0x11) = 0;
  }
  *(undefined1 *)((int)piVar1 + 0x5d) = 1;
  bVar2 = *DAT_10051860;
  iVar3 = led_nibble_encode_a(bVar2 >> 4);
  bVar2 = led_nibble_encode_a(bVar2 & 0xf);
  *DAT_10051860 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *DAT_10051864;
  iVar3 = led_nibble_encode_a(bVar2 >> 4);
  bVar2 = led_nibble_encode_a(bVar2 & 0xf);
  *DAT_10051864 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *DAT_10051868;
  iVar3 = led_nibble_encode_a(bVar2 >> 4);
  bVar2 = led_nibble_encode_a(bVar2 & 0xf);
  *DAT_10051868 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *DAT_1005186c;
  iVar3 = led_nibble_encode_a(bVar2 >> 4);
  bVar2 = led_nibble_encode_a(bVar2 & 0xf);
  *DAT_1005186c = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *DAT_10051870;
  iVar3 = led_nibble_encode_a(bVar2 >> 4);
  bVar2 = led_nibble_encode_a(bVar2 & 0xf);
  *DAT_10051870 = bVar2 | (byte)(iVar3 << 4);
  bVar2 = *DAT_10051874;
  iVar3 = led_nibble_encode_a(bVar2 >> 4);
  bVar2 = led_nibble_encode_a(bVar2 & 0xf);
  *DAT_10051874 = bVar2 | (byte)(iVar3 << 4);
  return CONCAT44(param_1,(uint)(*piVar1 + DAT_10051878 == 0));
}

// FUNC 0x1005187c  led_nibble_encode_b

/* Even to odd nibble encode */

int led_nibble_encode_b(int param_1)

{
  if (param_1 == 0) {
    param_1 = 1;
  }
  else if (param_1 == 2) {
    param_1 = 3;
  }
  else if (param_1 == 4) {
    param_1 = 5;
  }
  else if (param_1 == 6) {
    param_1 = 7;
  }
  return param_1;
}

// FUNC 0x1005189c  led_encode_b_send

/* Applies encoder B to the six LED payload bytes */

void led_encode_b_send(uint param_1,uint param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  byte bVar9;
  uint local_28;
  
  iVar2 = DAT_100519e8;
  iVar4 = 0;
  pcVar7 = (char *)(DAT_100519e8 + 0x1f);
  do {
    if (*pcVar7 != '\0') {
      bVar1 = false;
      for (uVar5 = 0; (uVar5 & 0xff) < (uint)(byte)pcVar7[1]; uVar5 = uVar5 + 1) {
        if ((byte)pcVar7[uVar5 + 2] == param_1) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        local_28 = 0;
        iVar4 = DAT_100519e8 + iVar4 * 0xe;
        break;
      }
    }
    iVar4 = iVar4 + 1;
    pcVar7 = pcVar7 + 0xe;
    if (iVar4 == 4) {
      return;
    }
  } while( true );
LAB_100518f2:
  if (*(byte *)(iVar4 + 0x20) <= local_28) {
    return;
  }
  uVar5 = *(byte *)(iVar4 + local_28 + 0x21) - 1 & 0xff;
  if (uVar5 < 0xc) {
    uVar6 = uVar5 >> 1;
    if ((int)(uVar5 << 0x1f) < 0) {
      if (1 < (*(byte *)(iVar2 + uVar6 + 0x57) & 0xf) - 2) {
        if (((param_2 & 0xfffffffb) == 0) || (param_2 == 6)) {
          bVar9 = *(byte *)(param_3 + uVar6) & 0xf0;
          iVar8 = DAT_100519e8 + uVar6;
          *(byte *)(param_3 + uVar6) = bVar9;
          bVar3 = led_nibble_encode_a(*(byte *)(iVar8 + 0x57) & 0xf);
        }
        else {
          if (((param_2 & 0xfffffffb) != 1) && (param_2 != 7)) goto LAB_100519d0;
          iVar8 = DAT_100519e8 + uVar6;
          bVar9 = *(byte *)(param_3 + uVar6) & 0xf0;
          *(byte *)(param_3 + uVar6) = bVar9;
          bVar3 = led_nibble_encode_b(*(byte *)(iVar8 + 0x57) & 0xf);
        }
LAB_100519cc:
        *(byte *)(param_3 + uVar6) = bVar9 | bVar3;
      }
    }
    else if (1 < (*(byte *)(iVar2 + uVar6 + 0x57) >> 4) - 2) {
      if (((param_2 & 0xfffffffb) == 0) || (param_2 == 6)) {
        bVar9 = *(byte *)(param_3 + uVar6) & 0xf;
        *(byte *)(param_3 + uVar6) = bVar9;
        iVar8 = led_nibble_encode_a(*(byte *)(iVar2 + uVar6 + 0x57) >> 4);
      }
      else {
        if (((param_2 & 0xfffffffb) != 1) && (param_2 != 7)) goto LAB_100519d0;
        bVar9 = *(byte *)(param_3 + uVar6) & 0xf;
        *(byte *)(param_3 + uVar6) = bVar9;
        iVar8 = led_nibble_encode_b(*(byte *)(iVar2 + uVar6 + 0x57) >> 4);
      }
      bVar3 = (byte)(iVar8 << 4);
      goto LAB_100519cc;
    }
  }
LAB_100519d0:
  local_28 = local_28 + 1 & 0xff;
  goto LAB_100518f2;
}

// FUNC 0x100519ec  FUN_100519ec

void FUN_100519ec(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  char *pcVar8;
  uint uVar9;
  byte bVar10;
  
  iVar2 = DAT_10051b00;
  iVar5 = 0;
  pcVar8 = (char *)(DAT_10051b00 + 0x1f);
  do {
    if (*pcVar8 != '\0') {
      bVar1 = false;
      for (uVar6 = 0; (uVar6 & 0xff) < (uint)(byte)pcVar8[1]; uVar6 = uVar6 + 1) {
        if ((byte)pcVar8[uVar6 + 2] == param_1) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        uVar6 = 0;
        iVar5 = DAT_10051b00 + iVar5 * 0xe;
        break;
      }
    }
    iVar5 = iVar5 + 1;
    pcVar8 = pcVar8 + 0xe;
    if (iVar5 == 4) {
      return;
    }
  } while( true );
LAB_10051a42:
  if (*(byte *)(iVar5 + 0x20) <= uVar6) {
    return;
  }
  bVar10 = *(char *)(iVar5 + uVar6 + 0x21) - 1;
  if (bVar10 < 0xc) {
    uVar9 = (uint)(bVar10 >> 1);
    if ((bVar10 & 1) == 0) {
      pbVar7 = (byte *)(iVar2 + uVar9 + 0x57);
      if ((*pbVar7 >> 4) - 2 < 2) {
        if (param_2 == 2) {
          bVar10 = *(byte *)(param_3 + uVar9) & 0xf;
          *(byte *)(param_3 + uVar9) = bVar10;
          iVar4 = led_nibble_encode_a(*pbVar7 >> 4);
        }
        else {
          if (param_2 != 3) goto LAB_10051aee;
          bVar10 = *(byte *)(param_3 + uVar9) & 0xf;
          *(byte *)(param_3 + uVar9) = bVar10;
          iVar4 = led_nibble_encode_b(*pbVar7 >> 4);
        }
        bVar3 = (byte)(iVar4 << 4);
        goto LAB_10051aea;
      }
    }
    else {
      pbVar7 = (byte *)(iVar2 + uVar9 + 0x57);
      if ((*pbVar7 & 0xf) - 2 < 2) {
        if (param_2 == 2) {
          bVar10 = *(byte *)(param_3 + uVar9) & 0xf0;
          *(byte *)(param_3 + uVar9) = bVar10;
          bVar3 = led_nibble_encode_a(*pbVar7 & 0xf);
        }
        else {
          if (param_2 != 3) goto LAB_10051aee;
          bVar10 = *(byte *)(param_3 + uVar9) & 0xf0;
          *(byte *)(param_3 + uVar9) = bVar10;
          bVar3 = led_nibble_encode_b(*pbVar7 & 0xf);
        }
LAB_10051aea:
        *(byte *)(param_3 + uVar9) = bVar10 | bVar3;
      }
    }
  }
LAB_10051aee:
  uVar6 = uVar6 + 1 & 0xff;
  goto LAB_10051a42;
}

// FUNC 0x10051b04  led_update

/* Encodes 6 color bytes and sends the 9-byte UART3 LED frame */

undefined8 led_update(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20 [3];
  
  bVar1 = *DAT_10051b74;
  iVar3 = DAT_10051b78 + 0x57;
  *DAT_10051b74 = bVar1 ^ 1;
  local_20[0] = param_1;
  local_20[1] = param_2;
  local_20[2] = param_3;
  rom_memcpy(local_20,iVar3,6);
  if ((bVar1 ^ 1) == 0) {
    iVar3 = 0;
    do {
      bVar1 = *(byte *)((int)local_20 + iVar3);
      iVar2 = led_nibble_encode_a(bVar1 >> 4);
      bVar1 = led_nibble_encode_a(bVar1 & 0xf);
      *(byte *)((int)local_20 + iVar3) = bVar1 | (byte)(iVar2 << 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 != 6);
  }
  else {
    iVar3 = 0;
    do {
      bVar1 = *(byte *)((int)local_20 + iVar3);
      iVar2 = led_nibble_encode_b(bVar1 >> 4);
      bVar1 = led_nibble_encode_b(bVar1 & 0xf);
      *(byte *)((int)local_20 + iVar3) = bVar1 | (byte)(iVar2 << 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 != 6);
  }
  led_frame_send(local_20);
  return CONCAT44(local_20[1],local_20[0]);
}

// FUNC 0x10051b7c  led_anim_finish

/* Sends the encoder A frame, clears the animation flag, cancels the 0x2b tick */

void led_anim_finish(void)

{
  led_encode_a_send();
  *DAT_10051b90 = 0;
  app_msg_cancel(0x2b);
  return;
}

// FUNC 0x10051b94  FUN_10051b94

void FUN_10051b94(undefined1 param_1)

{
  *DAT_10051b9c = param_1;
  return;
}

// FUNC 0x10051ba0  FUN_10051ba0

void FUN_10051ba0(void)

{
  FUN_1005415c();
  return;
}

// FUNC 0x10051ba8  FUN_10051ba8

void FUN_10051ba8(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_10051c10;
  *DAT_10051c10 = *DAT_10051c10 & 0xfffffff0;
  *puVar1 = *puVar1 | 8;
  *puVar1 = *puVar1 & 0xffffff0f;
  *puVar1 = *puVar1 | 0x80;
  *puVar1 = DAT_10051c14 & *puVar1;
  *puVar1 = *puVar1 | 0x800;
  *puVar1 = DAT_10051c18 & *puVar1;
  *puVar1 = *puVar1 | 0x8000;
  uVar2 = DAT_10051c20;
  puVar1 = DAT_10051c1c;
  *DAT_10051c1c = *DAT_10051c1c & 0xfffff000;
  *puVar1 = *puVar1 | uVar2;
  *DAT_10051c24 = 0xd0;
  *DAT_10051c28 = 1;
  return;
}

// FUNC 0x10051c2c  FUN_10051c2c

void FUN_10051c2c(void)

{
  *DAT_10051c70 = DAT_10051c6c;
  *DAT_10051c74 = *DAT_10051c74 & 0xffffff | 0x12000000;
  *DAT_10051c78 = DAT_10051c7c & *DAT_10051c78 | 0x80000;
  *DAT_10051c80 = *DAT_10051c80 & 0xffffff0f | 0x80;
  *DAT_10051c84 = *DAT_10051c84 & 0xffffff0f | 0x80;
  return;
}

// FUNC 0x10051e64  FUN_10051e64

undefined4 FUN_10051e64(undefined4 param_1)

{
  *DAT_10051e6c = param_1;
  return 0;
}

// FUNC 0x10051e70  FUN_10051e70

undefined8 FUN_10051e70(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 *puVar4;
  
  if ((param_4 == 0) || (param_5 != 0)) {
    uVar2 = param_1;
    puVar1 = (undefined2 *)FUN_10056e38(0xb00,6,4,(param_4 + 1) * 0x16,param_1,param_2,param_3);
    puVar1[1] = 4;
    *puVar1 = (short)param_1;
    *(char *)(puVar1 + 2) = (char)param_2;
    *(char *)((int)puVar1 + 5) = (char)param_4;
    param_1 = uVar2;
    if (param_3 != 0) {
      rom_memcpy(puVar1 + 3,param_3,0x10);
      param_1 = uVar2;
    }
    iVar3 = param_5 + param_4 * 0x16;
    puVar4 = puVar1;
    for (; param_5 != iVar3; param_5 = param_5 + 0x16) {
      puVar4[0x13] = *(undefined2 *)(param_5 + 0x10);
      puVar4[0x14] = *(undefined2 *)(param_5 + 0x12);
      puVar4[0x15] = *(undefined2 *)(param_5 + 0x14);
      rom_memcpy(puVar4 + 0xb,param_5,0x10);
      puVar4 = puVar4 + 0xb;
    }
    FUN_10056e78(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x440;
  }
  return CONCAT44(param_1,uVar2);
}

// FUNC 0x10051eec  FUN_10051eec

undefined8 FUN_10051eec(void)

{
  ushort uVar1;
  undefined4 in_stack_00000000;
  
  uVar1 = FUN_10051e70();
  return CONCAT44(in_stack_00000000,(uint)uVar1);
}

// FUNC 0x10051f48  FUN_10051f48

undefined8 FUN_10051f48(int param_1,int param_2)

{
  code *pcVar1;
  int extraout_r1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int unaff_r7;
  
  iVar3 = *DAT_10052068;
  pcVar1 = (code *)0x1;
  if (iVar3 != 0) {
    if ((uint)(param_2 + DAT_1005206c) < 0x27) {
      iVar2 = DAT_1005206c;
      FUN_10056ee8();
      *(char *)(iVar3 + 9) = (char)iVar2;
      *(ushort *)(unaff_r7 + extraout_r1 + -0x2c) = (ushort)*(byte *)(unaff_r7 + 0x15);
      puVar4 = (undefined2 *)(uint)*(byte *)(iVar3 + 0x15);
      pcVar1 = *(code **)(iVar3 + 8);
      if (pcVar1 != (code *)0x0) {
        param_1 = (int)puVar4 + 5;
        pcVar1 = (code *)(*pcVar1)((int)puVar4 << 1,*puVar4,puVar4[1],*(undefined1 *)(puVar4 + 2),
                                   param_1,param_2);
      }
    }
    else {
      pcVar1 = (code *)0x0;
    }
  }
  return CONCAT44(param_1,pcVar1);
}

// FUNC 0x10052166  FUN_10052166

undefined4 FUN_10052166(int param_1,undefined2 param_2,undefined2 param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_4 == 0) || (param_5 != 0)) {
    puVar1 = (undefined1 *)FUN_10056e38(0xc10,param_1 << 8 | 7,4,param_4 + 8U & 0xffff,param_4);
    *puVar1 = 0x12;
    *(short *)(puVar1 + 6) = (short)param_4;
    *(undefined2 *)(puVar1 + 2) = param_2;
    *(undefined2 *)(puVar1 + 4) = param_3;
    if (param_5 != 0) {
      rom_memcpy(puVar1 + 8,param_5,param_4);
    }
    FUN_10056e78(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x440;
  }
  return uVar2;
}

// FUNC 0x100521b8  FUN_100521b8

undefined8 FUN_100521b8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  short sVar2;
  
  sVar2 = *(short *)(DAT_100521d4 + 4) + 1;
  *(short *)(DAT_100521d4 + 4) = sVar2;
  uVar1 = FUN_10052166(param_1,sVar2,param_2,param_3,param_4,param_2);
  return CONCAT44(param_4,(uint)uVar1);
}

// FUNC 0x1005221c  FUN_1005221c

undefined4 FUN_1005221c(int param_1,undefined2 param_2,undefined1 param_3,int param_4,int param_5)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  
  if ((param_4 == 0) || (param_5 != 0)) {
    puVar1 = (undefined2 *)
             FUN_10056e38(DAT_10052268,param_1 << 8 | 7,4,param_4 + 6U & 0xffff,param_4);
    *puVar1 = param_2;
    puVar1[1] = (short)param_4;
    *(undefined1 *)(puVar1 + 2) = param_3;
    if (param_5 != 0) {
      rom_memcpy((int)puVar1 + 5,param_5,param_4);
    }
    FUN_10056e78(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x440;
  }
  return uVar2;
}

// FUNC 0x1005226c  FUN_1005226c

undefined8 FUN_1005226c(void)

{
  ushort uVar1;
  undefined4 in_stack_00000000;
  
  uVar1 = FUN_1005221c();
  return CONCAT44(in_stack_00000000,(uint)uVar1);
}

// FUNC 0x1005227a  FUN_1005227a

longlong FUN_1005227a(uint param_1,undefined2 *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = FUN_10051f48(param_4 >> 8,param_1,param_2,param_4,param_1,param_2,param_3);
  if (iVar1 == 1) {
    param_1 = 0;
    FUN_1005221c(param_4 >> 8,*param_2,1);
  }
  return (ulonglong)param_1 << 0x20;
}

// FUNC 0x100522a0  FUN_100522a0

undefined4 FUN_100522a0(int param_1,undefined2 param_2,undefined1 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_10056e38(DAT_100522c4,param_1 << 8 | 7,4);
  *puVar1 = param_2;
  *(undefined1 *)(puVar1 + 1) = param_3;
  FUN_10056e78();
  return 0;
}

// FUNC 0x100522c8  FUN_100522c8

undefined2 FUN_100522c8(void)

{
  undefined2 uVar1;
  
  uVar1 = FUN_100522a0();
  return uVar1;
}

// FUNC 0x100522d2  FUN_100522d2

undefined4 FUN_100522d2(undefined4 param_1,undefined2 *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = FUN_10051f48(param_4 >> 8,param_1,param_2);
  if (iVar1 == 1) {
    FUN_100522a0(param_4 >> 8,*param_2,1);
  }
  return 0;
}

// FUNC 0x100522f4  FUN_100522f4

undefined4 FUN_100522f4(int param_1,undefined2 param_2,undefined2 param_3,undefined1 param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_10056e38(DAT_1005231c,param_1 << 8 | 7,4,6);
  *puVar1 = param_2;
  puVar1[1] = param_3;
  *(undefined1 *)(puVar1 + 2) = param_4;
  FUN_10056e78();
  return 0;
}

// FUNC 0x10052388  FUN_10052388

undefined4 FUN_10052388(undefined4 param_1,uint param_2,char *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  undefined1 local_24 [2];
  undefined2 local_22;
  undefined2 local_20;
  char local_1e;
  
  piVar3 = DAT_1005264c;
  iVar2 = *DAT_1005264c;
  if (iVar2 == 0) {
    return 1;
  }
  if (param_2 != DAT_10052650) {
    if (param_2 <= DAT_10052650) {
      if (param_2 == DAT_10052654) {
        pcVar4 = *(code **)(iVar2 + 0x9c);
        if (pcVar4 == (code *)0x0) {
          return 1;
        }
        goto LAB_1005255a;
      }
      if (DAT_10052654 < param_2) {
        if (param_2 == DAT_10052668) {
          if (*(code **)(iVar2 + 0x84) != (code *)0x0) {
            uVar1 = (**(code **)(iVar2 + 0x84))
                              (param_1,*(undefined2 *)param_3,*(undefined2 *)(param_3 + 2),
                               *(undefined2 *)(param_3 + 4));
            return uVar1;
          }
          return 0;
        }
        if (param_2 <= DAT_10052668) {
          if (param_2 != DAT_1005266c) {
            if (param_2 != DAT_10052670) {
              return 0;
            }
            if (*(code **)(iVar2 + 0x80) == (code *)0x0) {
              return 1;
            }
            uVar1 = (**(code **)(iVar2 + 0x80))
                              (param_1,*(undefined2 *)param_3,*(undefined2 *)(param_3 + 2),
                               *(undefined2 *)(param_3 + 4),*(undefined2 *)(param_3 + 6));
            return uVar1;
          }
          if ((*(code **)(iVar2 + 0x8c) != (code *)0x0) && (*param_3 == '\0')) {
            (**(code **)(iVar2 + 0x8c))(param_1,*(undefined2 *)(param_3 + 2),param_3 + 4);
          }
LAB_10052516:
          if (*(code **)(*piVar3 + 0xb8) == (code *)0x0) {
            return 1;
          }
          uVar1 = (**(code **)(*piVar3 + 0xb8))(param_1,*(undefined2 *)param_3,param_3 + 2);
          return uVar1;
        }
        if (param_2 != DAT_10052674) {
          if (param_2 == DAT_10052678) goto LAB_10052516;
          if (param_2 != DAT_1005267c) {
            return 0;
          }
          piVar3 = (int *)(iVar2 + 0xac);
          goto LAB_100524ea;
        }
        piVar3 = (int *)(iVar2 + 0xb0);
      }
      else {
        if (param_2 != DAT_10052658) {
          if (DAT_10052658 < param_2) {
            piVar3 = (int *)(iVar2 + 0x98);
            if (param_2 == DAT_10052664) {
              pcVar4 = (code *)*piVar3;
              if (pcVar4 == (code *)0x0) {
                return 0;
              }
              FUN_10056f28(local_24,0,10);
              uVar1 = 8;
              local_24[0] = 4;
              goto LAB_10052602;
            }
            if (param_2 <= DAT_10052664) {
              pcVar4 = (code *)*piVar3;
              if (pcVar4 == (code *)0x0) {
                return 0;
              }
              FUN_10056f28(local_24,0,10);
              local_24[0] = 3;
              local_1e = param_3[4];
              local_20 = *(undefined2 *)(param_3 + 2);
              goto LAB_10052626;
            }
            pcVar4 = (code *)*piVar3;
            if (pcVar4 == (code *)0x0) {
              return 0;
            }
            FUN_10056f28(local_24,0,10);
            local_24[0] = 7;
            goto LAB_100526dc;
          }
          if (param_2 != DAT_1005265c) {
            if (param_2 != DAT_10052660) {
              return 0;
            }
            if (*(code **)(iVar2 + 0x7c) != (code *)0x0) {
              uVar1 = (**(code **)(iVar2 + 0x7c))(param_1,*(undefined2 *)param_3,param_3[2]);
              return uVar1;
            }
            return 0;
          }
          piVar3 = (int *)(iVar2 + 0x90);
LAB_100524ea:
          pcVar4 = (code *)*piVar3;
          if (pcVar4 == (code *)0x0) {
            return 1;
          }
          goto LAB_1005259e;
        }
        piVar3 = (int *)(iVar2 + 0x94);
      }
      pcVar4 = (code *)*piVar3;
      if (pcVar4 == (code *)0x0) {
        return 0;
      }
LAB_1005259e:
      uVar1 = (*pcVar4)(param_1,param_3);
      return uVar1;
    }
    if (param_2 == 0xe30) {
      pcVar4 = *(code **)(iVar2 + 0x98);
      if (pcVar4 == (code *)0x0) {
        return 0;
      }
      FUN_10056f28(local_24,0,10);
      local_24[0] = 0x18;
      local_22._1_1_ = param_3[1];
    }
    else {
      if (param_2 < 0xe31) {
        if (param_2 == DAT_10052680) {
          pcVar4 = *(code **)(iVar2 + 0x98);
          if (pcVar4 == (code *)0x0) {
            return 0;
          }
          FUN_10056f28(local_24,0,10);
          uVar1 = 5;
          local_24[0] = 8;
LAB_10052602:
          rom_memcpy(&local_22,param_3,uVar1);
          goto LAB_100526e0;
        }
        if (DAT_10052680 < param_2) {
          if (param_2 == DAT_1005268c) {
            if (*(code **)(iVar2 + 0xb4) != (code *)0x0) {
              (**(code **)(iVar2 + 0xb4))
                        (param_1,*(undefined2 *)param_3,*(undefined2 *)(param_3 + 2),
                         *(undefined2 *)(param_3 + 4),*(undefined2 *)(param_3 + 6));
              return 0;
            }
            return 0;
          }
          if (param_2 == DAT_10052690) {
            pcVar4 = *(code **)(iVar2 + 200);
            if (pcVar4 == (code *)0x0) {
              return 0;
            }
            goto LAB_1005255a;
          }
          if (param_2 != DAT_10052694) {
            return 0;
          }
          pcVar4 = *(code **)(iVar2 + 0x98);
          if (pcVar4 == (code *)0x0) {
            return 0;
          }
          FUN_10056f28(local_24,0,10);
          local_24[0] = 0x12;
LAB_10052626:
          local_22 = *(undefined2 *)param_3;
          goto LAB_100526e0;
        }
        if (param_2 != DAT_10052684) {
          if (param_2 != DAT_10052688) {
            return 0;
          }
          if (*(code **)(iVar2 + 0xc4) != (code *)0x0) {
            uVar1 = (**(code **)(iVar2 + 0xc4))
                              (param_1,*(undefined4 *)param_3,*(undefined4 *)(param_3 + 4));
            return uVar1;
          }
          return 0;
        }
        piVar3 = (int *)(iVar2 + 0xc0);
        goto LAB_10052532;
      }
      if (param_2 == DAT_10052698) {
        if (*(code **)(iVar2 + 0xd0) != (code *)0x0) {
          uVar1 = (**(code **)(iVar2 + 0xd0))
                            (param_1,*param_3,*(undefined2 *)(param_3 + 2),param_3 + 4);
          return uVar1;
        }
        return 0;
      }
      if (DAT_10052698 < param_2) {
        if (param_2 == DAT_100526a4) {
          piVar3 = (int *)(iVar2 + 0xd4);
        }
        else {
          if (param_2 < DAT_100526a4) {
            pcVar4 = *(code **)(iVar2 + 0x88);
            if (pcVar4 == (code *)0x0) {
              return 0;
            }
            goto LAB_1005258e;
          }
          piVar3 = (int *)(iVar2 + 0xd8);
          if (param_2 != DAT_100526a8) {
            return 0;
          }
        }
        pcVar4 = (code *)*piVar3;
        if (pcVar4 == (code *)0x0) {
          return 0;
        }
LAB_1005258e:
        uVar1 = (*pcVar4)(param_1);
        return uVar1;
      }
      if (param_2 != DAT_1005269c) {
        if (param_2 != DAT_100526a0) {
          return 0;
        }
        pcVar4 = *(code **)(iVar2 + 0xcc);
        if (pcVar4 == (code *)0x0) {
          return 0;
        }
        goto LAB_1005259e;
      }
      pcVar4 = *(code **)(iVar2 + 0x98);
      if (pcVar4 == (code *)0x0) {
        return 0;
      }
      FUN_10056f28(local_24,0,10);
      local_24[0] = 0x19;
    }
LAB_100526dc:
    local_22 = CONCAT11(local_22._1_1_,*param_3);
LAB_100526e0:
    uVar1 = (*pcVar4)(param_1,local_24);
    return uVar1;
  }
  piVar3 = (int *)(iVar2 + 0xbc);
LAB_10052532:
  pcVar4 = (code *)*piVar3;
  if (pcVar4 == (code *)0x0) {
    return 0;
  }
LAB_1005255a:
  uVar1 = (*pcVar4)(param_1,*param_3);
  return uVar1;
}

// FUNC 0x100528ec  FUN_100528ec

undefined4
FUN_100528ec(int param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5
            ,undefined2 param_6,undefined2 param_7,undefined2 param_8)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_1005294c,param_1 << 8 | 9,4,0xe);
  *puVar1 = 9;
  *(undefined2 *)(puVar1 + 6) = param_5;
  puVar1[1] = param_2;
  *(undefined2 *)(puVar1 + 8) = param_6;
  *(undefined2 *)(puVar1 + 2) = param_3;
  *(undefined2 *)(puVar1 + 10) = param_7;
  *(undefined2 *)(puVar1 + 4) = param_4;
  *(undefined2 *)(puVar1 + 0xc) = param_8;
  FUN_10056e78();
  return 0;
}

// FUNC 0x10052a0c  FUN_10052a0c

undefined4 FUN_10052a0c(int param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(0xe10,param_1 << 8 | 9,4,6);
  *(undefined2 *)(puVar1 + 4) = param_4;
  *(undefined2 *)(puVar1 + 2) = param_3;
  *puVar1 = param_2;
  FUN_10056e78();
  return 0;
}

// FUNC 0x10052a34  FUN_10052a34

undefined2 FUN_10052a34(void)

{
  undefined2 uVar1;
  
  uVar1 = FUN_10052a0c();
  return uVar1;
}

// FUNC 0x10052a78  FUN_10052a78

undefined4 FUN_10052a78(int param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_10052a9c,param_1 << 8 | 9,4,2);
  *puVar1 = param_2;
  puVar1[1] = param_3;
  FUN_10056e78();
  return 0;
}

// FUNC 0x10052aa0  FUN_10052aa0

undefined2 FUN_10052aa0(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  
  uVar1 = FUN_10052a78(param_1,0,param_2);
  return uVar1;
}

// FUNC 0x10052aae  FUN_10052aae

undefined4 FUN_10052aae(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = FUN_10052388(param_4 >> 8,param_1,param_2);
  if (iVar1 == 1) {
    FUN_10052a78(param_4 >> 8,0,0x48);
  }
  return 0;
}

// FUNC 0x10052be0  FUN_10052be0

undefined4 FUN_10052be0(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_2 == 0) || (param_3 != 0)) {
    puVar1 = (undefined1 *)FUN_10056e38(DAT_10052c28,param_1 << 8 | 9,4,param_2 + 10U & 0xffff);
    *puVar1 = 0;
    *(short *)(puVar1 + 2) = (short)param_2;
    if (param_3 != 0) {
      rom_memcpy(puVar1 + 4,param_3,param_2);
    }
    FUN_10056e78(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x340;
  }
  return uVar2;
}

// FUNC 0x10052c2c  FUN_10052c2c

undefined2 FUN_10052c2c(undefined4 param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    uVar1 = 0x100;
  }
  else {
    uVar1 = FUN_10052be0();
  }
  return uVar1;
}

// FUNC 0x10052c44  FUN_10052c44

undefined4 FUN_10052c44(int param_1,undefined2 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_10052c68,param_1 << 8 | 9,4,10);
  *(undefined2 *)(puVar1 + 2) = param_2;
  *puVar1 = 1;
  FUN_10056e78();
  return 0;
}

// FUNC 0x10052c6c  FUN_10052c6c

undefined2 FUN_10052c6c(void)

{
  undefined2 uVar1;
  
  uVar1 = FUN_10052c44();
  return uVar1;
}

// FUNC 0x10052c78  FUN_10052c78

undefined4
FUN_10052c78(int param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,undefined2 param_5
            )

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_10052ca8,param_1 << 8 | 9,4,10,param_4);
  *(undefined2 *)(puVar1 + 2) = param_2;
  *(undefined2 *)(puVar1 + 4) = param_3;
  *(short *)(puVar1 + 6) = (short)param_4;
  *puVar1 = 2;
  *(undefined2 *)(puVar1 + 8) = param_5;
  FUN_10056e78();
  return 0;
}

// FUNC 0x10052cac  FUN_10052cac

ulonglong FUN_10052cac(void)

{
  ushort uVar1;
  undefined2 in_stack_00000000;
  
  uVar1 = FUN_10052c78();
  return (ulonglong)CONCAT24(in_stack_00000000,(uint)uVar1);
}

// FUNC 0x10053204  FUN_10053204

undefined4
FUN_10053204(undefined1 param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)FUN_10056e38(0xda0,8,4,(byte)param_2[0x27] + 0x2c,param_4);
  *puVar2 = 0xa0;
  puVar1 = DAT_100532b0;
  puVar2[1] = param_1;
  *puVar1 = 0xff;
  puVar2[4] = *param_2;
  puVar2[5] = param_2[1];
  *(undefined2 *)(puVar2 + 6) = *(undefined2 *)(param_2 + 2);
  puVar2[8] = param_2[4];
  puVar2[9] = param_2[5];
  rom_memcpy(puVar2 + 10,param_2 + 6,6);
  puVar2[0x10] = param_2[0xc];
  *(undefined4 *)(puVar2 + 0x14) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(puVar2 + 0x18) = *(undefined4 *)(param_2 + 0x14);
  puVar2[0x1c] = param_2[0x18];
  puVar2[0x1d] = param_2[0x19];
  puVar2[0x20] = param_2[0x1c];
  puVar2[0x21] = param_2[0x1d];
  puVar2[0x22] = param_2[0x1e];
  *(undefined2 *)(puVar2 + 0x24) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(puVar2 + 0x26) = *(undefined2 *)(param_2 + 0x14);
  puVar2[0x28] = param_2[0x24];
  puVar2[0x29] = param_2[0x25];
  puVar2[0x2a] = param_2[0x26];
  puVar2[0x2b] = param_2[0x27];
  rom_memcpy(puVar2 + 0x2c,param_2 + 0x28,param_2[0x27]);
  FUN_10056e78(puVar2);
  return 0;
}

// FUNC 0x100533bc  FUN_100533bc

undefined4 FUN_100533bc(undefined4 param_1)

{
  *DAT_100533c4 = param_1;
  return 0;
}

// FUNC 0x100533c8  FUN_100533c8

undefined4 FUN_100533c8(undefined4 param_1)

{
  *DAT_100533d0 = param_1;
  return 0;
}

// FUNC 0x100533d4  FUN_100533d4

undefined4 FUN_100533d4(undefined4 param_1)

{
  *DAT_100533dc = param_1;
  return 0;
}

// FUNC 0x10053454  FUN_10053454

undefined2 FUN_10053454(undefined4 param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  undefined1 local_38;
  undefined1 local_37;
  undefined2 local_36;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 auStack_32 [6];
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined1 local_1f;
  
  local_38 = 0;
  local_37 = *param_2;
  local_36 = *(undefined2 *)(param_2 + 2);
  local_34 = param_2[4];
  local_33 = param_2[5];
  rom_memcpy(auStack_32,param_2 + 6);
  local_2c = param_2[0xc];
  local_24 = *(undefined4 *)(param_2 + 0x14);
  local_28 = *(undefined4 *)(param_2 + 0x10);
  local_1f = param_2[0x19];
  local_20 = param_2[0x18];
  uVar1 = FUN_10053204(param_1,&local_38);
  return uVar1;
}

// FUNC 0x100534a4  FUN_100534a4

undefined2
FUN_100534a4(undefined4 param_1,undefined4 param_2,int param_3,int param_4,ushort param_5,
            short param_6,undefined2 param_7,undefined2 param_8)

{
  undefined2 uVar1;
  
  if ((((DAT_10053500 < (param_4 - 6U & 0xffff)) || (DAT_10053500 < (param_3 - 6U & 0xffff))) ||
      (DAT_10053504 < (ushort)(param_6 - 10))) || (499 < param_5)) {
    uVar1 = 0x340;
  }
  else {
    uVar1 = FUN_100528ec(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  return uVar1;
}

// FUNC 0x10053544  FUN_10053544

undefined4 FUN_10053544(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_10053560,8,4,1);
  *puVar1 = 1;
  FUN_10056e78();
  return 0;
}

// FUNC 0x10053564  FUN_10053564

undefined4 FUN_10053564(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_10053594;
  if (param_1 == 0) {
    uVar1 = 0x340;
  }
  else {
    *DAT_10053590 = *(undefined1 *)(param_1 + 0x28);
    *DAT_10053598 = 1;
    rom_memcpy(uVar1,param_1,0x2a);
    FUN_10053544();
    uVar1 = 0;
  }
  return uVar1;
}

// FUNC 0x1005359c  FUN_1005359c

undefined2 FUN_1005359c(void)

{
  undefined2 uVar1;
  
  uVar1 = FUN_10053564();
  return uVar1;
}

// FUNC 0x100535a8  FUN_100535a8

void FUN_100535a8(void)

{
  if (*DAT_100535b8 != '\0') {
    FUN_10051c2c();
  }
  return;
}

// FUNC 0x100536a8  FUN_100536a8

undefined4 FUN_100536a8(undefined1 param_1,undefined2 param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_100536d0,8,4,0x3a);
  puVar1[1] = param_1;
  *(undefined2 *)(puVar1 + 2) = param_2;
  *puVar1 = 0xa4;
  puVar1[4] = param_3;
  FUN_10056e78();
  return 0;
}

// FUNC 0x100536d4  FUN_100536d4

undefined2 FUN_100536d4(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  
  uVar1 = FUN_100536a8(*DAT_100536e8,param_1,param_2);
  return uVar1;
}

// FUNC 0x10053738  FUN_10053738

undefined8 FUN_10053738(undefined4 param_1,undefined1 param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_3 == 0) || (param_4 != 0)) {
    uVar2 = param_1;
    puVar1 = (undefined1 *)
             FUN_10056e38(DAT_10053784,8,4,param_3 + 4U & 0xffff,param_1,param_1,param_3);
    puVar1[1] = param_2;
    *puVar1 = (char)uVar2;
    *(short *)(puVar1 + 2) = (short)param_3;
    if (param_4 != 0) {
      rom_memcpy(puVar1 + 4,param_4,param_3);
    }
    FUN_10056e78(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x340;
  }
  return CONCAT44(param_1,uVar2);
}

// FUNC 0x10053788  FUN_10053788

undefined8 FUN_10053788(int param_1,int *param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  int iStack_10;
  int *piStack_c;
  
  uVar1 = *DAT_100537b4;
  iStack_10 = param_1;
  piStack_c = param_2;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    rom_memcpy(&iStack_10,DAT_100537b8,8);
    param_1 = 8;
    param_2 = &iStack_10;
  }
  uVar2 = FUN_10053738(0xa9,uVar1,param_1,param_2);
  return CONCAT44(iStack_10,(uint)uVar2);
}

// FUNC 0x100537bc  FUN_100537bc

undefined8 FUN_100537bc(int param_1,int *param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  int iStack_10;
  int *piStack_c;
  
  uVar1 = *DAT_100537e8;
  iStack_10 = param_1;
  piStack_c = param_2;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    rom_memcpy(&iStack_10,DAT_100537ec,8);
    param_1 = 8;
    param_2 = &iStack_10;
  }
  uVar2 = FUN_10053738(0xaa,uVar1,param_1,param_2);
  return CONCAT44(iStack_10,(uint)uVar2);
}

// FUNC 0x100537f0  FUN_100537f0

undefined8
FUN_100537f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_4 == 0) || (param_5 != 0)) {
    uVar2 = param_1;
    puVar1 = (undefined1 *)
             FUN_10056e38(DAT_10053848,8,4,param_4 + 8U & 0xffff,param_1,param_2,param_3);
    *(undefined2 *)(puVar1 + 4) = 4;
    *puVar1 = 0x1b;
    puVar1[1] = (char)param_2;
    *(short *)(puVar1 + 2) = (short)param_1;
    *(short *)(puVar1 + 6) = (short)param_3;
    param_1 = uVar2;
    if (param_5 != 0) {
      rom_memcpy(puVar1 + 8,param_5,param_4);
      param_1 = uVar2;
    }
    FUN_10056e78(puVar1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x340;
  }
  return CONCAT44(param_1,uVar2);
}

// FUNC 0x100538e8  post_task_msg

undefined4 FUN_100538e8(undefined1 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined1 *)FUN_10056e38(DAT_10053910,4,4,8);
  uVar2 = DAT_10053914;
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = param_1;
    *(undefined4 *)(puVar1 + 4) = param_2;
    FUN_10056e78();
    uVar2 = 0;
  }
  return uVar2;
}

// FUNC 0x10053918  app_msg_post

/* Posts app message id (0xF00 + code + 0x27) with a payload and a delay in ms */

undefined4 app_msg_post(char param_1,undefined4 param_2)

{
  func_0x1000df44((byte)(param_1 + 0x27) + 0xf00,4,param_2);
  return 0;
}

// FUNC 0x10053930  app_msg_cancel

void app_msg_cancel(char param_1)

{
  func_0x1000e050((byte)(param_1 + 0x27) + 0xf00,4);
  return;
}

// FUNC 0x10053944  app_msg_release

void app_msg_release(char param_1)

{
  func_0x1000e0d0((byte)(param_1 + 0x27) + 0xf00,4);
  return;
}

// FUNC 0x10053958  task_queue_add

/* Appends an entry to the 0x20-slot task queue */

undefined4 task_queue_add(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_10053974;
  iVar3 = *DAT_10053974;
  uVar2 = DAT_10053978;
  if (iVar3 < 0x20) {
    DAT_10053974[iVar3 + 1] = param_1;
    *piVar1 = iVar3 + 1;
    uVar2 = 0;
  }
  return uVar2;
}

// FUNC 0x100539ae  FUN_100539ae

undefined4 FUN_100539ae(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 7;
  if (param_1 < 0xb1) {
    uVar1 = func_0x1000fe40();
  }
  return uVar1;
}

// FUNC 0x100539c0  FUN_100539c0

undefined4 FUN_100539c0(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 7;
  if (param_1 < 0xb1) {
    uVar1 = func_0x1000fd8c();
  }
  return uVar1;
}

// FUNC 0x100539d4  ble_get_mac

/* Returns the 6-byte BLE MAC through a caller buffer */

undefined4 ble_get_mac(void)

{
  int iVar1;
  code *pcVar2;
  char local_20 [20];
  
  if ((((undefined4 *)*DAT_10053a78 != (undefined4 *)0x0) &&
      (pcVar2 = *(code **)*DAT_10053a78, pcVar2 != (code *)0x0)) &&
     (iVar1 = (*pcVar2)(), iVar1 == 1)) {
    local_20[8] = 6;
    iVar1 = func_0x1000fd8c(1,local_20 + 8,DAT_10053a7c);
    if (iVar1 == 0) {
      return DAT_10053a7c;
    }
  }
  FUN_1004ca50(0);
  FUN_10056f28(local_20,0,6);
  FUN_1004cad8(0x16,6,local_20);
  iVar1 = 0;
  do {
    if (local_20[iVar1] != '\0') {
      iVar1 = 0;
      do {
        local_20[iVar1 + 8] = local_20[5 - iVar1];
        iVar1 = iVar1 + 1;
      } while (iVar1 != 6);
      goto LAB_10053a58;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 6);
  FUN_1004cad8(0x10,6,local_20);
  iVar1 = 0;
  while (local_20[iVar1] == '\0') {
    iVar1 = iVar1 + 1;
    if (iVar1 == 6) {
      local_20[8] = 6;
      func_0x1000fd8c(1,local_20 + 8,DAT_10053a7c);
      return DAT_10053a7c;
    }
  }
  iVar1 = 0;
  do {
    local_20[iVar1 + 8] = local_20[5 - iVar1];
    iVar1 = iVar1 + 1;
  } while (iVar1 != 6);
LAB_10053a58:
  rom_memcpy(DAT_10053a7c);
  return DAT_10053a7c;
}

// FUNC 0x10053ae8  FUN_10053ae8

undefined4 FUN_10053ae8(void)

{
  return DAT_10053aec;
}

// FUNC 0x10053b6c  FUN_10053b6c

undefined4 FUN_10053b6c(undefined4 param_1)

{
  *DAT_10053b74 = param_1;
  return 0;
}

// FUNC 0x10053b78  FUN_10053b78

void FUN_10053b78(void)

{
  int *piVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  pcVar2 = DAT_10053bbc;
  piVar1 = DAT_10053bb8;
  if (*DAT_10053bb8 != 0) {
    if ((*DAT_10053bbc != '\0') && (-1 < (int)((uint)*(byte *)(*DAT_10053bb8 + 0xc) << 0x1f))) {
      (*(code *)*DAT_10053bc0)(0x2000);
      uVar3 = 10;
      if (*(char *)(*piVar1 + 2) == '\0') {
        uVar3 = 2000;
      }
      app_msg_post(0xe9,uVar3);
    }
    *pcVar2 = '\0';
  }
  return;
}

// FUNC 0x10053cf8  FUN_10053cf8

void FUN_10053cf8(void)

{
  rom_memcpy(DAT_10053d0c + 0x3d4,DAT_10053d10,6);
  return;
}

// FUNC 0x10053f00  FUN_10053f00

void FUN_10053f00(int param_1,undefined4 param_2)

{
  *(undefined4 *)((param_1 + DAT_10053f14) * 4) = param_2;
  FUN_10056e48(10);
  return;
}

// FUNC 0x10053f18  FUN_10053f18

void FUN_10053f18(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  if (param_3 < 0x20) {
    uVar1 = (1 << (param_3 & 0xff)) - 1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  if ((((param_1 != 0xff) && (param_2 < 0x20)) && (param_3 < 0x21)) && (param_4 <= uVar1)) {
    FUN_10053f00(param_1,param_4 << (param_2 & 0xff) |
                         *(uint *)((param_1 + DAT_10053f54) * 4) & ~(uVar1 << (param_2 & 0xff)));
  }
  return;
}

// FUNC 0x10053f64  FUN_10053f64

void FUN_10053f64(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((code *)*DAT_10054014 != (code *)0x0) {
    (*(code *)*DAT_10054014)();
    return;
  }
  FUN_10056e58(0x17,0x12,1,0);
  FUN_10056e58(0x1e,0x11,4,7);
  FUN_10056e58(0x15,0x1a,3,0);
  FUN_10056e58(0x15,10,1);
  uVar3 = *DAT_10054018;
  if ((uVar3 & 9) != 0) goto LAB_10053ff8;
  if ((uVar3 & 2) == 0) {
    if ((int)(uVar3 << 0x1d) < 0) {
LAB_10053fee:
      uVar5 = 0;
      uVar2 = 1;
    }
    else {
      if ((uVar3 & 0x20) == 0) {
        if (-1 < (int)(uVar3 << 0x1b)) goto LAB_10053ff8;
        FUN_10056e58(0x1d,0xb,1);
        goto LAB_10053fee;
      }
      uVar5 = 1;
      uVar2 = 0xb;
    }
    uVar4 = 1;
    uVar1 = 0x1d;
  }
  else {
    FUN_10056e58(0x1e,1,1);
    uVar5 = 1;
    uVar4 = 2;
    uVar2 = 0x1a;
    uVar1 = 0x1f;
  }
  FUN_10056e58(uVar1,uVar2,uVar4,uVar5);
LAB_10053ff8:
  FUN_10056e48(100);
  FUN_10056e58(0x15,10,1,0);
  do {
  } while (-1 < *DAT_1005401c);
  return;
}

// FUNC 0x10054020  FUN_10054020

undefined8 FUN_10054020(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  FUN_10056e58(0x2d,0,1,0,param_1,param_2,param_3);
  FUN_10056e58(0x2d,0,1);
  FUN_10056e48(0x32);
  uVar2 = *DAT_1005414c;
  uVar3 = *DAT_1005414c;
  uVar5 = *DAT_1005414c;
  uVar7 = *DAT_1005414c;
  *DAT_1005414c = DAT_10054150;
  FUN_10056e48(10);
  if (param_1 == 1) {
    FUN_10053f18(0,4,3,1);
    uVar4 = 3;
    uVar1 = 0x17;
LAB_10054088:
    FUN_10056e58(0x33,uVar1,4,uVar4);
  }
  else if (param_1 == 2) {
    FUN_10053f18(0,4,3);
    uVar4 = 7;
    uVar1 = 0x1b;
    goto LAB_10054088;
  }
  FUN_10056e58(0x2f,0x17,1,0);
  FUN_10056e58(0x2f,0x17,1);
  FUN_10056e48(DAT_10054154);
  FUN_10056e58(0x2f,0x17,1,0);
  uVar6 = *DAT_10054158;
  if (param_1 == 1) {
    uVar1 = FUN_10056d58(64000,uVar6 >> 10);
    FUN_10053f18(6,0x10,8,uVar1);
    FUN_10053f18(6,0x18,5,10);
    FUN_10053f18(6,0,8,uVar7 & 0xff);
    uVar5 = (uVar5 << 0x13) >> 0x1b;
  }
  else {
    if (param_1 != 2) goto LAB_1005413c;
    FUN_10053f18(6,0x10,8,uVar3 >> 0x10 & 0xff);
    FUN_10053f18(6,0x18,5,(uVar2 << 3) >> 0x1b);
    uVar1 = FUN_10056d58(0x1f400,uVar6 >> 10);
    FUN_10053f18(6,0,8,uVar1);
    uVar5 = 10;
  }
  FUN_10053f18(6,8,5,uVar5);
LAB_1005413c:
  FUN_10053f18(0,4,3);
  return CONCAT44(uVar2,uVar3);
}

// FUNC 0x1005415c  FUN_1005415c

undefined4 FUN_1005415c(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = 0;
  do {
    if (*(char *)(iVar2 * 2 + DAT_100541cc) == param_1) {
      bVar1 = *(byte *)(DAT_100541cc + iVar2 * 2 + 1);
      if (bVar1 < 0x10) {
        FUN_10056e58(0x31,0,4,2);
        FUN_10056e58(0x34,0x17,3);
        uVar3 = 7;
      }
      else {
        FUN_10056e58(0x31,0,4,3);
        FUN_10056e58(0x34,0x17,3,6);
        uVar3 = 0xd;
      }
      FUN_10056e58(0x33,1,4,uVar3);
      FUN_10053f18(1,0x18,5,bVar1);
      return 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x20);
  return 0;
}

// FUNC 0x100541d0  FUN_100541d0

void FUN_100541d0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  (*(code *)*DAT_1005420c)();
  uVar1 = (*(code *)*DAT_10054210)(0x1c);
  uVar2 = uVar1 >> 0x10 & 0xff;
  uVar3 = uVar1 >> 8 & 0xff;
  if (((uVar2 != 0) || (uVar2 = uVar3, uVar3 != 0)) || (uVar2 = uVar1 & 0xff, (uVar1 & 0xff) != 0))
  {
    FUN_10056e58(0x35,0,8,uVar2);
  }
  return;
}

// FUNC 0x10054214  FUN_10054214

void FUN_10054214(void)

{
  uint *puVar1;
  
  FUN_10056e58(2,1,4,8);
  *DAT_10054614 = DAT_10054610;
  FUN_10056e48(100);
  FUN_10056e58(0x16,4,1,0);
  FUN_10056e58(0x17,0xe,1,0);
  FUN_10056e58(0x17,0x17,1);
  FUN_10056e58(0x17,0x16,1);
  FUN_10056e58(0x17,0x15,1);
  FUN_10056e58(0x17,0x14,1);
  FUN_10056e58(0x17,0x13,1);
  FUN_10056e58(0x17,0x12,1);
  FUN_10056e58(0x17,0x11,1);
  FUN_10056e58(0x17,0x10,1);
  FUN_10056e58(0x17,0xf,1);
  FUN_10056e58(0x17,0xb,1);
  FUN_10053f64();
  FUN_10056e58(0x17,0x15,1,0);
  FUN_10056e58(0x15,0xd,1,0);
  FUN_10056e58(0x16,8,1,0);
  FUN_10056e58(0x3a,0x12,1);
  puVar1 = DAT_10054618;
  do {
  } while ((*DAT_10054618 >> 0xe & 1) != 1);
  FUN_10056e58(0x3a,0x12,1,0);
  FUN_10056e58(0x16,8,1,1);
  FUN_10056e58(0x15,0xd,1,1);
  FUN_10056e58(0x30,6,1,1);
  FUN_10056e58(0x30,5,1,0);
  FUN_10056e58(0x17,0x17,1,0);
  FUN_10056e58(0x17,0x11,1,0);
  FUN_10056e58(0x17,0xf,1,0);
  FUN_10056e58(0x31,0x17,1,1);
  FUN_10056e58(0x16,0x1c,1,0);
  FUN_10056e58(0x16,10,1,0);
  FUN_10056e58(0x16,2,1,0);
  FUN_10056e58(0x15,1,2,0);
  FUN_10056e58(0x33,0x15,2);
  FUN_10056e58(0x2d,0x18,1,1);
  FUN_10056e58(0x2d,0,1,1);
  FUN_10056e58(0x2d,2,1,1);
  FUN_10056e58(0x16,5,2,0);
  FUN_10056e58(0x2d,0x19,7,0x28);
  FUN_10056e58(0x2d,0xe,2,3);
  FUN_10056e58(0x2d,0x10,5,0x18);
  FUN_10056e58(0x2d,3,1,0);
  FUN_10056e48(1);
  FUN_10056e58(0x2d,3,1,1);
  FUN_10056e48(1);
  FUN_10056e58(0x2d,3,1,0);
  FUN_10056e48(0x32);
  FUN_10056e58(0x2d,0xe,2,0);
  FUN_10056e58(0x30,0xd,1,0);
  FUN_10056e58(0x2d,5,1,0);
  FUN_10056e48(1);
  FUN_10056e58(0x2d,5,1,1);
  FUN_10056e48(1);
  FUN_10056e58(0x2d,5,1,0);
  FUN_10056e48(1000);
  FUN_10056e58(0x2d,0xf,1,1);
  FUN_10056e58(0x30,0xd,1,1);
  FUN_10056e58(0x2d,0x19,7,0);
  FUN_10054020(1);
  FUN_10054020(2);
  FUN_10056e58(0x31,0x17,1,0);
  FUN_10056e58(0x17,0x17,1,0);
  FUN_10056e58(0x17,0x11,1,0);
  FUN_10056e58(0x17,0xf,1,0);
  FUN_10056e58(0x33,0x16,1,0);
  FUN_10056e58(0x2d,0x18,1,0);
  FUN_10056e58(0x2d,0xf,1,1);
  FUN_10056e58(0x2d,0xe,1,0);
  FUN_10056e58(0x17,0x17,1,0);
  FUN_10056e58(0x17,0x10,1,0);
  FUN_10056e58(0x15,8,1,0);
  FUN_10056e58(0x3a,0xe,1,0);
  FUN_10056e58(0x17,0x15,1,0);
  FUN_10056e58(0x15,0xd,1,0);
  FUN_10056e58(0x16,8,1,0);
  FUN_10056e58(0x3a,0x12,1,1);
  do {
  } while ((*puVar1 >> 0xe & 1) != 1);
  FUN_10056e58(0x3a,0x12,1,0);
  FUN_10056e58(0x16,8,1,1);
  FUN_10056e58(0x15,0xd,1,1);
  FUN_10056e58(0x31,0x17,1,0);
  FUN_10056e58(0x17,0x17,1,0);
  FUN_10056e58(0x17,0xf,1,0);
  FUN_10056e58(0x15,8,1,0);
  FUN_10056e58(0x3a,0xe,1,0);
  FUN_10056e58(0x17,0x15,1,0);
  FUN_10056e58(0x15,0xd,1,0);
  FUN_10056e58(0x16,8,1,0);
  FUN_10056e58(0x3a,0x12,1,1);
  do {
  } while ((*puVar1 >> 0xe & 1) != 1);
  FUN_10056e58(0x3a,0x12,1,0);
  FUN_10056e58(0x16,8,1,1);
  FUN_10056e58(0x15,0xd,1,1);
  FUN_10056e58(0x31,0x17,1,0);
  *DAT_100546ec = 0x100;
  FUN_10056e48(100);
  *DAT_100546f4 = DAT_100546f0;
  FUN_10056e48(100);
  *DAT_100546fc = DAT_100546f8;
  FUN_10056e48(100);
  FUN_10056e58(3,0x16,1,0);
  FUN_10056e58(0x17,0xb,1,1);
  FUN_10056e58(0x16,4,1,0);
  FUN_10056e58(0x15,8,1,0);
  *DAT_10054704 = DAT_10054700;
  FUN_10056e48(100);
  FUN_10056e58(1,0xd,6,0x24);
  FUN_10056e58(1,0x17,1,1);
  if ((*DAT_10054708 == 0) || (*(char *)(*DAT_10054708 + 0x18) == '\0')) {
    FUN_10056f08();
  }
  log_printf(DAT_1005470c);
  return;
}

// FUNC 0x100549f0  FUN_100549f0

undefined4 FUN_100549f0(byte param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_10054a3c;
  if (param_1 != 0x26) {
    if (param_1 < 0x27) {
      puVar2 = DAT_10054a38;
      if ((param_1 != 0x14) && (puVar2 = DAT_10054a30, param_1 != 0x24)) {
        return 0;
      }
    }
    else {
      puVar2 = DAT_10054a44;
      if (((param_1 != 0x50) && (puVar2 = DAT_10054a40, param_1 != 200)) &&
         (puVar2 = DAT_10054a34, param_1 != 0x28)) {
        return 0;
      }
    }
  }
  uVar1 = (*(code *)*puVar2)();
  return uVar1;
}

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

// FUNC 0x10054b70  FUN_10054b70

undefined4 FUN_10054b70(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = DAT_10054b94 + iVar2 * 0x14;
    if (*(ushort *)(iVar1 + 0x12) == param_1) {
      return *(undefined4 *)(iVar1 + 0xc);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 10);
  return 0;
}

// FUNC 0x10054bdc  FUN_10054bdc

uint FUN_10054bdc(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = 0;
  do {
    iVar3 = DAT_10054c08 + iVar1 * 0x14;
    if ((uint)*(ushort *)(iVar3 + 0x12) == (param_1 & 0xff)) {
      uVar2 = (uint)*(ushort *)(iVar3 + 0x10);
      goto LAB_10054c00;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 10);
  uVar2 = 0xff;
LAB_10054c00:
  return param_1 & 0xffffff00 | uVar2;
}

// FUNC 0x10054ca8  FUN_10054ca8

void FUN_10054ca8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 local_c;
  undefined2 uStack_a;
  
  _local_c = CONCAT22((short)((uint)param_4 >> 0x10),(short)DAT_10054cc4);
  FUN_100537f0(0x14,0,0,2,&local_c,param_2,param_3);
  return;
}

// FUNC 0x10054cc8  FUN_10054cc8

void FUN_10054cc8(void)

{
  *DAT_10054cdc = DAT_10054cd8;
  *DAT_10054ce4 = DAT_10054ce0;
  return;
}

// FUNC 0x10054d18  FUN_10054d18

uint FUN_10054d18(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 1;
  uVar2 = 0;
  do {
    if ((param_1 >> (uVar2 & 0xff) & 1U) != 0) {
      uVar1 = uVar1 | 3 << (uVar2 * 2 + 1 & 0xff);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 9);
  return uVar1;
}

// FUNC 0x10054d40  FUN_10054d40

int FUN_10054d40(int param_1,ushort *param_2,ushort param_3,uint param_4,ushort *param_5)

{
  int iVar1;
  ushort *puVar2;
  undefined4 uVar3;
  undefined4 local_1c [2];
  
  local_1c[0] = FUN_10054d18(*param_5);
  iVar1 = func_0x1002f20c(param_2,DAT_10054dc8,local_1c,0x13,0,*(undefined2 *)(param_1 + 0x10),
                          DAT_10054dc4,param_4 & 0x1e);
  if (iVar1 == 0) {
    puVar2 = (ushort *)FUN_10056f18(0x20,1);
    *(ushort **)(param_1 + 0xc) = puVar2;
    puVar2[0xc] = *param_2;
    puVar2[0xd] = *param_5;
    uVar3 = DAT_10054dcc;
    if (-1 < (int)(param_4 << 0x1f)) {
      uVar3 = 0;
    }
    *puVar2 = (ushort)uVar3 | param_3;
    puVar2[1] = *(ushort *)(param_1 + 0x10);
    *(undefined2 *)(param_1 + 0x12) = 0x14;
    FUN_10055030(param_1);
    FUN_10056f38(puVar2 + 2);
    func_0x1000dc44(*(undefined2 *)(param_1 + 0x10),0);
  }
  return iVar1;
}

// FUNC 0x10055030  FUN_10055030

void FUN_10055030(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10054b70(0x14);
  *param_1 = DAT_1005504c;
  *(undefined2 *)((int)param_1 + 10) = 3;
  param_1[1] = iVar1 + 0x1e;
  *(undefined2 *)(param_1 + 2) = 1;
  return;
}

// FUNC 0x100550d4  FUN_100550d4

void FUN_100550d4(void)

{
  *DAT_100550e8 = DAT_100550e4;
  *DAT_100550f0 = DAT_100550ec;
  return;
}

// FUNC 0x100550f4  FUN_100550f4

void FUN_100550f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_c;
  undefined3 uStack_b;
  
  _local_c = CONCAT31((int3)((uint)param_4 >> 8),3);
  FUN_100537f0(0x50,0,0,1,&local_c,param_2,param_3);
  return;
}

// FUNC 0x10055110  FUN_10055110

undefined4 FUN_10055110(undefined4 param_1)

{
  *DAT_10055118 = param_1;
  return 0;
}

// FUNC 0x1005513c  FUN_1005513c

int FUN_1005513c(int param_1,ushort *param_2,ushort param_3,uint param_4,byte *param_5)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 uVar4;
  undefined1 local_19 [5];
  
  local_19[0] = 0x3f;
  iVar2 = func_0x1002f20c(param_2,*DAT_100551b8,local_19,6,0,*(undefined2 *)(param_1 + 0x10),
                          DAT_100551bc,param_4 & 0x1e);
  if (iVar2 == 0) {
    puVar3 = (ushort *)FUN_10056f18(10,1);
    uVar1 = *param_2;
    *(ushort **)(param_1 + 0xc) = puVar3;
    puVar3[2] = uVar1;
    puVar3[3] = (ushort)*param_5;
    uVar4 = DAT_100551c0;
    if (-1 < (int)(param_4 << 0x1f)) {
      uVar4 = 0;
    }
    *puVar3 = (ushort)uVar4 | param_3;
    puVar3[1] = *(ushort *)(param_1 + 0x10);
    *(undefined2 *)(param_1 + 0x12) = 0x50;
    otas_task_init(param_1);
    func_0x1000dc44(*(undefined2 *)(param_1 + 0x10),0);
    FUN_100556b4();
  }
  return iVar2;
}

// FUNC 0x100556b4  FUN_100556b4

void FUN_100556b4(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_100556d8;
  *DAT_100556dc = DAT_100556d8;
  puVar2 = DAT_100556e0;
  *DAT_100556e0 = 0;
  *(undefined2 *)(puVar2 + 2) = 0;
  *(undefined4 *)(puVar2 + 4) = 0;
  puVar2[1] = 0;
  uVar3 = (**(code **)(iVar1 + 0x14))();
  log_printf(DAT_100556e4,uVar3);
  return;
}

// FUNC 0x100556e8  otas_task_init

/* OTAS task init; allocates the task block and sets the entry point */

void otas_task_init(undefined4 *param_1)

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

// FUNC 0x10055714  FUN_10055714

void FUN_10055714(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  byte local_70 [64];
  undefined1 local_30 [40];
  
  disableIRQinterrupts();
  iVar1 = syscfg_read(1);
  uVar3 = DAT_100557c0;
  if (iVar1 << 1 < 0) {
    uVar3 = DAT_100557bc;
  }
  syscfg_write(1,uVar3);
  uVar2 = syscfg_read(1);
  syscfg_write(1,uVar2 & DAT_100557c4);
  uVar2 = syscfg_read(7);
  syscfg_write(7,uVar2 | 0x800000);
  uVar2 = 0;
  do {
    uVar4 = uVar2;
    if ((uVar4 & 1) == 0) {
      local_30[uVar4] = 0;
    }
    else {
      local_30[uVar4] = 0x10;
    }
    uVar2 = uVar4 + 1;
  } while (uVar4 + 1 != 0x25);
  iVar1 = 0;
  pbVar5 = local_70 + uVar4;
  do {
    if (iVar1 < 0x10) {
      pbVar5[0x1c] = pbVar5[0x1c] | 5;
      pbVar5[0x1d] = pbVar5[0x1d] | 5;
    }
    else {
      *pbVar5 = *pbVar5 | 10;
      pbVar5[1] = pbVar5[1] | 10;
    }
    iVar1 = iVar1 + 1;
    pbVar5 = pbVar5 + 2;
  } while (iVar1 != 0x20);
  iVar1 = 0;
  do {
    syscfg_write(0x14,local_30[iVar1]);
    iVar1 = iVar1 + 1;
    FUN_1004afb0(10);
  } while (iVar1 != 0x25);
  return;
}

// FUNC 0x100557c8  FUN_100557c8

undefined4 FUN_100557c8(void)

{
  log_printf(DAT_100557dc);
  log_printf(DAT_100557e0);
  return 0xffffffff;
}

// FUNC 0x100557e4  FUN_100557e4

undefined4 FUN_100557e4(void)

{
  log_printf(DAT_100557f0);
  return DAT_100557f4;
}

// FUNC 0x10055a18  image_header_verify

/* Verifies image length and CRC before a jump */

undefined4 image_header_verify(void)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  
  log_printf(DAT_10055a7c);
  piVar1 = DAT_10055a80;
  FUN_10055b42(DAT_10055a80 + 4,DAT_10055a80 + 4);
  puVar3 = DAT_10055a84;
  if (*piVar1 == piVar1[2] + 0x80) {
    if (piVar1[2] != *(int *)(DAT_10055a88 + 0x50)) {
      log_printf(PTR_s_image_length_compare_fail____d____10055a8c,*(int *)(DAT_10055a88 + 0x50));
      return 0xffffffff;
    }
    puVar3 = PTR_s_image_crc_compare_fail_10055a90;
    if ((*(uint *)(DAT_10055a88 + 0x54) == (uint)*(ushort *)(piVar1 + 4)) &&
       (iVar2 = FUN_10055ca8(*DAT_10055a9c,DAT_10055a88,(int)*DAT_10055a98,(int)*DAT_10055a94),
       puVar3 = DAT_10055aa0, iVar2 == 0)) {
      return 0;
    }
  }
  log_printf(puVar3);
  return 0xffffffff;
}

// FUNC 0x10055aa4  FUN_10055aa4

uint FUN_10055aa4(uint param_1,uint param_2)

{
  param_2 = param_2 | 0x100;
  do {
    param_2 = param_2 << 1;
    param_1 = param_1 * 2 + (uint)((param_2 & 0x100) != 0);
    if ((param_1 & 0x10000) != 0) {
      param_1 = param_1 ^ DAT_10055ad0;
    }
  } while ((param_2 & 0x10000) == 0);
  return param_1 & 0xffff;
}

// FUNC 0x10055ad4  FUN_10055ad4

int FUN_10055ad4(byte *param_1,byte *param_2,undefined4 *param_3,uint param_4)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  for (pbVar3 = param_1; *pbVar3 != 0; pbVar3 = pbVar3 + 1) {
  }
  *param_3 = param_1;
  do {
    do {
      pbVar2 = param_1;
      if (pbVar3 == pbVar2) {
        return -(uint)(*param_2 < 2);
      }
      param_1 = pbVar2 + 1;
    } while ((*pbVar2 != param_4) || (*pbVar2 = 0, pbVar2[1] == param_4));
    param_3[*param_2] = param_1;
    bVar1 = *param_2;
    *param_2 = bVar1 + 1;
  } while ((byte)(bVar1 + 1) < 8);
  return 0;
}

// FUNC 0x10055b20  FUN_10055b20

void FUN_10055b20(undefined2 *param_1)

{
  *param_1 = 0;
  return;
}

// FUNC 0x10055b26  FUN_10055b26

void FUN_10055b26(undefined2 *param_1,undefined1 *param_2,int param_3)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  
  puVar2 = param_2 + param_3;
  for (; param_2 < puVar2; param_2 = param_2 + 1) {
    uVar1 = FUN_10055aa4(*param_1,*param_2);
    *param_1 = uVar1;
  }
  return;
}

// FUNC 0x10055b42  FUN_10055b42

void FUN_10055b42(undefined2 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_10055aa4(*param_1,0);
  uVar1 = FUN_10055aa4(uVar2,0);
  *param_1 = uVar1;
  *param_2 = uVar1;
  return;
}

// FUNC 0x10055b5c  FUN_10055b5c

undefined4 FUN_10055b5c(void)

{
  undefined4 uVar1;
  
  uVar1 = *DAT_10055b6c;
  *DAT_10055b70 = 0xfffffffe;
  return uVar1;
}

// FUNC 0x10055b74  FUN_10055b74

void FUN_10055b74(uint param_1)

{
  *DAT_10055b80 = param_1 & 0xfffffffe;
  return;
}

// FUNC 0x10055b84  bootloader_version_check

/* Parses ASRBOOTLOADER-560X and the version or slip string */

undefined4 bootloader_version_check(undefined1 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined *puVar4;
  byte *pbVar5;
  byte local_39;
  undefined4 local_38 [9];
  
  local_39 = 0;
  log_printf(DAT_10055c50,DAT_10055c4c);
  uVar1 = DAT_10055c58;
  pbVar5 = DAT_10055c4c;
  while (*pbVar5 != 0) {
    if ((0x5e < *pbVar5 - 0x20) || (pbVar5 = pbVar5 + 1, pbVar5 == DAT_10055c54)) {
      log_printf(PTR_s_bl_ver_isn_t_str_10055c70);
      return 0xffffffff;
    }
  }
  rom_memcpy(DAT_10055c58,DAT_10055c4c,pbVar5 + DAT_10055c5c);
  iVar2 = FUN_10056af4(uVar1,PTR_s_ASRBOOTLOADER_560X_10055c60,0x12);
  puVar4 = PTR_s_bl_ver_or_slip___error___d_10055c6c;
  if (iVar2 == 0) {
    local_39 = 1;
    iVar2 = FUN_10055ad4(uVar1,&local_39,local_38,0x2d);
    puVar4 = PTR_s_bl_ver_or_slip___error___d_10055c6c;
    if (iVar2 == 0) {
      if (local_39 < 3) {
        return 0xffffffff;
      }
      pcVar3 = (char *)local_38[local_39 - 1];
      if (*pcVar3 != 'V') {
        return 0xffffffff;
      }
      pcVar3 = pcVar3 + 1;
      puVar4 = PTR_s_bl_slip___error___d_10055c68;
      if (pcVar3 != (char *)0x0) {
        local_39 = 1;
        iVar2 = FUN_10055ad4(pcVar3,&local_39,local_38,0x2e);
        puVar4 = PTR_s_bl_slip___error___d_10055c68;
        if (iVar2 == 0) {
          iVar2 = FUN_10056cd8(local_38[0],0,10);
          if (iVar2 < 2) {
            *param_1 = 0;
          }
          else {
            *param_1 = 1;
          }
          log_printf(PTR_s_bl_first_ver__s_10055c64,local_38[0]);
          return 0;
        }
      }
    }
  }
  log_printf(puVar4,local_39);
  return 0xffffffff;
}

// FUNC 0x10055c74  FUN_10055c74

void FUN_10055c74(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = sys_env_kv_init(0), iVar1 == 0)) {
    log_printf(DAT_10055c90);
  }
  return;
}

// FUNC 0x10055c94  FUN_10055c94

int FUN_10055c94(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 == 3) {
    iVar1 = -(uint)(*(int *)(param_1 + 0x40) != 0);
  }
  return iVar1;
}

// FUNC 0x10055ca8  FUN_10055ca8

int FUN_10055ca8(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 local_84 [8];
  undefined1 auStack_64 [32];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_1 == 0) {
    if (*(int *)(param_2 + 0x40) == 0) {
      uVar5 = 0;
      if (param_4 != 3) {
        uVar5 = 0xffffffff;
      }
      *(undefined4 *)(param_2 + 0x44) = uVar5;
    }
    puVar2 = DAT_10055ddc;
    puVar1 = DAT_10055dd8;
    *(undefined4 *)(param_2 + 0x48) = 0;
    *(undefined4 *)(param_2 + 0x60) = 0;
    uVar6 = *puVar1;
    *puVar2 = 0xfffffffe;
    local_84[0] = 0x1000;
    iVar3 = FUN_1004c7dc(5,0x1000,0x80);
    *puVar1 = uVar6 & 0xfffffffe;
    if (iVar3 == 0) {
      uVar6 = *puVar1;
      *puVar2 = 0xfffffffe;
      local_84[0] = 0x1000;
      iVar3 = FUN_1004c82c(5,local_84,param_2,0x80);
      *puVar1 = uVar6 & 0xfffffffe;
      iVar4 = FUN_1004c79c(param_3);
      uVar5 = *(undefined4 *)(iVar4 + 8);
      iVar4 = FUN_1004c79c(param_4);
      uVar7 = *(undefined4 *)(iVar4 + 8);
      iVar4 = FUN_1004c79c(param_4);
      log_printf(DAT_10055de0,uVar5,uVar7,*(undefined4 *)(iVar4 + 0xc),
                 *(undefined4 *)(param_2 + 0x40),*(undefined4 *)(param_2 + 0x44),
                 *(undefined4 *)(param_2 + 0x4c));
    }
  }
  else {
    rom_memcpy(local_84,param_2,0x20);
    rom_memcpy(auStack_64,param_2 + 0x20);
    local_44 = 0;
    local_20 = *(undefined4 *)(param_2 + 0x60);
    local_1c = *(undefined4 *)(param_2 + 100);
    local_28 = *(undefined4 *)(param_2 + 0x58);
    local_24 = *(undefined4 *)(param_2 + 0x5c);
    local_30 = *(undefined4 *)(param_2 + 0x50);
    local_2c = *(undefined4 *)(param_2 + 0x54);
    if (*(int *)(param_2 + 0x40) == 0) {
      local_40 = 0;
      if (param_4 != 3) {
        local_40 = 1;
      }
    }
    else if (*(int *)(param_2 + 0x4c) == 0) {
      local_40 = 3;
    }
    else {
      local_40 = 2;
    }
    iVar3 = FUN_1004c79c(param_3);
    local_3c = *(undefined4 *)(iVar3 + 8);
    iVar3 = FUN_1004c79c(param_4);
    local_38 = *(undefined4 *)(iVar3 + 8);
    iVar3 = FUN_1004c79c(param_4);
    local_34 = *(undefined4 *)(iVar3 + 0xc);
    log_printf(DAT_10055dd4,local_3c,local_38,local_34,local_40);
    iVar3 = FUN_10055e64(3,local_84,0x6c);
  }
  return iVar3;
}

// FUNC 0x10055e0c  sys_env_kv_init

/* Registers two callbacks and initializes the SYS ENV and SYS KV areas */

int sys_env_kv_init(int param_1,int param_2)

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

// FUNC 0x10055e64  FUN_10055e64

void FUN_10055e64(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1c [20];
  
  uVar1 = FUN_100569b6(auStack_1c);
  FUN_1005661c(DAT_10055e80,param_1,uVar1);
  return;
}

// FUNC 0x10055eb6  FUN_10055eb6

undefined4 FUN_10055eb6(undefined4 param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int local_58;
  undefined1 auStack_4c [8];
  int local_44;
  uint local_40;
  undefined2 local_3c;
  undefined1 auStack_38 [36];
  
  FUN_10056a4a(param_1,*(undefined4 *)(param_2 + 0x10),auStack_4c,0x14);
  uVar1 = FUN_10056936(auStack_4c,6);
  *param_2 = uVar1;
  if (local_40 < 0x81) {
    *(uint *)(param_2 + 8) = local_40;
    uVar3 = 0;
    uVar2 = local_40 + 8;
    local_58 = 0;
    do {
      iVar4 = 0x20;
      if (uVar2 <= uVar3 + 0x20) {
        iVar4 = uVar2 - uVar3;
      }
      FUN_10056a4a(param_1,*(int *)(param_2 + 0x10) + 0xc + uVar3,auStack_38,iVar4);
      local_58 = FUN_100568d8(local_58,auStack_38,iVar4);
      uVar3 = uVar3 + iVar4;
    } while (uVar3 < uVar2);
    if (local_58 == local_44) {
      param_2[1] = 1;
      *(undefined2 *)(param_2 + 0xc) = local_3c;
      *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x10) + 0x14;
      return 0;
    }
  }
  else {
    *(undefined4 *)(param_2 + 8) = 0x80;
    *param_2 = 5;
  }
  param_2[1] = 0;
  return 2;
}

// FUNC 0x10055f3c  FUN_10055f3c

void FUN_10055f3c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int extraout_r1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 local_14;
  
  uStack_18 = param_3;
  local_14 = param_4;
  FUN_10056f28(&uStack_18,0,8,param_4,param_1,param_2);
  uVar2 = *(undefined4 *)(param_1 + 8);
  FUN_10056d68(param_2,uVar2);
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = FUN_10056a5c(param_1,param_2,uVar2);
  if (iVar1 == 0) {
    FUN_10056f28(&uStack_18,0xff,8);
    FUN_10056910(&uStack_18,4,1);
    FUN_10056910((int)&uStack_18 + 1,4,1);
    local_14 = DAT_10055fa4;
    FUN_10056a6e(param_1,param_2,&uStack_18,8,1);
  }
  return;
}

// FUNC 0x10056000  FUN_10056000

uint FUN_10056000(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_2c [4];
  int local_28;
  
  uVar3 = *param_3;
  if (uVar3 == 0xffffffff) {
    uVar3 = *(int *)(param_2 + 4) + 8;
  }
  else {
    uVar1 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
    if (uVar3 <= uVar1) {
      uVar1 = uVar1 - 8;
      uVar3 = uVar3 + 0x94;
      do {
        uVar2 = uVar3;
        if ((uVar1 <= uVar2) || (uVar1 <= uVar2 + 0x94)) {
          uVar2 = 0xffffffff;
          break;
        }
        FUN_10056a4a(param_1,uVar2,auStack_2c,0x14);
        uVar3 = uVar2 + 0x94;
      } while (local_28 != DAT_10056064);
      if (uVar2 <= (uint)(*(int *)(param_2 + 4) + *(int *)(param_1 + 8))) {
        return uVar2;
      }
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

// FUNC 0x10056068  FUN_10056068

undefined4 FUN_10056068(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int extraout_r1;
  undefined1 uStack_38;
  undefined1 auStack_37 [3];
  int local_34;
  byte local_30;
  char local_2f;
  int local_20 [3];
  
  FUN_10056f28(&uStack_38,0,8);
  FUN_10056d68(param_2,*(undefined4 *)(param_1 + 8));
  if (extraout_r1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_3 != (undefined1 *)0x0) {
    FUN_10056a4a(param_1,param_2,&uStack_38,8);
    iVar1 = DAT_10056140;
    *(undefined4 *)(param_3 + 4) = param_2;
    *(int *)(param_3 + 8) = local_34;
    if (local_34 == iVar1) {
      *param_3 = 1;
      uVar2 = FUN_10056936(&uStack_38,4);
      param_3[1] = uVar2;
      uVar2 = FUN_10056936(auStack_37,4);
      param_3[2] = uVar2;
      if (param_4 != 0) {
        local_20[0] = *(int *)(param_3 + 4) + 8;
        *(undefined4 *)(param_3 + 0xc) = 0;
        *(int *)(param_3 + 0x10) = local_20[0];
        if (param_3[1] == '\x01') {
          *(int *)(param_3 + 0xc) = *(int *)(param_1 + 8) + -8;
        }
        else if (param_3[1] == '\x02') {
          *(int *)(param_3 + 0xc) = *(int *)(param_1 + 8) + -8;
          do {
            FUN_10055eb6(param_1,&local_30);
            if ((local_2f == '\0') && ((local_30 & 0xfb) != 1)) {
              *(undefined4 *)(param_3 + 0xc) = 0;
              return 2;
            }
            *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 0x94;
            *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + -0x94;
            if (param_3[1] == '\x01') {
              local_20[0] = -1;
            }
            else {
              local_20[0] = FUN_10056000(param_1,param_3,local_20);
            }
          } while (local_20[0] != -1);
        }
      }
      uVar3 = 0;
    }
    else {
      *param_3 = 0;
      uVar3 = 8;
    }
    return uVar3;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// FUNC 0x1005615e  FUN_1005615e

undefined4 FUN_1005615e(undefined4 param_1,int param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  undefined1 auStack_14 [8];
  
  if (*(char *)(param_2 + 1) == '\x01') {
    uVar1 = FUN_10056960(param_1,*(undefined4 *)(param_2 + 4),auStack_14,4,2,1);
  }
  else {
    uVar1 = 0;
    if (*(char *)(param_2 + 1) == '\x02') {
      if (*(uint *)(param_2 + 0xc) < 0x128) {
        uVar1 = FUN_10056960(param_1,*(undefined4 *)(param_2 + 4),auStack_14,4,3,1);
        if (param_3 != (undefined1 *)0x0) {
          *param_3 = 1;
        }
      }
      else if (param_3 != (undefined1 *)0x0) {
        *param_3 = 0;
      }
    }
  }
  return uVar1;
}

// FUNC 0x100561b6  FUN_100561b6

undefined8
FUN_100561b6(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            code *param_6,byte param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (uint)param_7;
  uVar4 = param_3;
  do {
    uVar3 = 0;
    while( true ) {
      FUN_10056068(param_1,uVar3,param_2,0,param_4,uVar2,uVar4);
      if ((param_3 == 0) || (*(byte *)(param_2 + 1) == param_3)) {
        if (uVar2 != 0) {
          FUN_10056068(param_1,uVar3,param_2,1,param_4,uVar2,uVar4);
        }
        if ((param_6 != (code *)0x0) && (iVar1 = (*param_6)(param_2,param_4,param_5), iVar1 != 0))
        goto LAB_1005621a;
      }
      if (*(int *)(param_2 + 4) == -1) break;
      uVar3 = *(int *)(param_2 + 4) + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar3) || (uVar3 == 0xffffffff)) {
LAB_1005621a:
        return CONCAT44(uVar2,param_4);
      }
    }
  } while( true );
}

// FUNC 0x1005621c  FUN_1005621c

int FUN_1005621c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int local_28;
  uint local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int *local_14;
  
  local_28 = -1;
  local_14 = &local_28;
  local_24 = 0;
  local_20 = 0;
  local_1c = param_1;
  local_18 = param_3;
  FUN_100561b6(param_1,param_2,0,&local_24,&local_20,DAT_100562a4,0);
  if (local_20 != 0) {
    FUN_100561b6(param_1,param_2,2,&local_1c,0,DAT_100562a8,1);
  }
  if ((local_24 != 0) && (local_28 == -1)) {
    if ((local_24 < 2) && (*(char *)(param_1 + 0x28) == '\0')) {
      *(char *)(param_1 + 0x28) = '\x01';
    }
    else {
      FUN_100561b6(param_1,param_2,1,&local_1c,0,DAT_100562a8,1);
    }
  }
  return local_28;
}

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

// FUNC 0x100562f4  FUN_100562f4

void FUN_100562f4(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  while( true ) {
    iVar2 = FUN_1005621c(param_1,param_2,param_3);
    if (iVar2 != -1) {
      return;
    }
    if (*(char *)(param_1 + 0x28) == '\0') break;
    if (bVar1) goto LAB_10056328;
    FUN_100562ac(param_1);
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
LAB_10056328:
  *(char *)(param_1 + 0x28) = '\0';
  return;
}

// FUNC 0x1005634e  FUN_1005634e

void FUN_1005634e(int param_1,int param_2,undefined4 param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 uStack_2c;
  byte local_2b;
  int local_28;
  
  do {
    uVar2 = 0;
    while( true ) {
      iVar1 = FUN_10056068(param_1,uVar2,&uStack_2c,0);
      if (((iVar1 == 0) && (param_5 != (code *)0x0)) && (local_2b - 2 < 2)) {
        *(int *)(param_2 + 0x10) = local_28 + 8;
        do {
          FUN_10055eb6(param_1,param_2);
          iVar1 = (*param_5)(param_2,param_3,param_4);
          if (iVar1 != 0) {
            return;
          }
          if (local_2b == 1) {
            iVar1 = -1;
          }
          else {
            iVar1 = FUN_10056000(param_1,&uStack_2c,param_2 + 0x10);
          }
          *(int *)(param_2 + 0x10) = iVar1;
        } while (iVar1 != -1);
      }
      if (local_28 == -1) break;
      uVar2 = local_28 + *(int *)(param_1 + 8);
      if ((*(uint *)(param_1 + 0xc) <= uVar2) || (uVar2 == 0xffffffff)) {
        return;
      }
    }
  } while( true );
}

// FUNC 0x100563d0  FUN_100563d0

undefined1 FUN_100563d0(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  undefined2 local_12 [4];
  undefined1 local_9;
  
  local_9 = 0;
  local_12[0] = param_2;
  FUN_1005634e(param_1,param_3,local_12,&local_9,DAT_100563f8);
  return local_9;
}

// FUNC 0x100563fc  FUN_100563fc

int FUN_100563fc(int param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [28];
  
  if (param_3 == (undefined1 *)0x0) {
    iVar1 = FUN_100563d0(param_1,param_2,auStack_30);
    if (iVar1 == 0) {
      return 5;
    }
    param_3 = auStack_30;
  }
  if (param_4 != 0) {
    iVar1 = FUN_10056960(param_1,*(undefined4 *)(param_3 + 0x10),auStack_34,6,4,1);
  }
  else {
    iVar1 = FUN_10056960(param_1,*(undefined4 *)(param_3 + 0x10),auStack_34,6,3,0);
  }
  *(bool *)(param_1 + 0x58) = param_4 == 0;
  if (iVar1 == 0) {
    iVar3 = (*(uint *)(param_3 + 0x10) & -*(int *)(param_1 + 8)) + 1;
    iVar2 = FUN_1005699a(param_1,iVar3,auStack_34,4);
    if (iVar2 == 1) {
      iVar1 = FUN_10056960(param_1,iVar3,auStack_34,4,2,1);
    }
  }
  return iVar1;
}

// FUNC 0x10056486  FUN_10056486

undefined4 FUN_10056486(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_5c;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [20];
  undefined1 auStack_38 [36];
  
  if (*param_2 == '\x02') {
    FUN_100563fc(param_1,0,param_2);
  }
  iVar1 = FUN_1005621c(param_1,auStack_4c,0x94);
  local_5c = 7;
  if (iVar1 != -1) {
    if ((*(char *)(param_1 + 0x29) == '\0') ||
       (iVar2 = FUN_100563d0(param_1,*(undefined2 *)(param_2 + 0xc),auStack_38), iVar2 == 0)) {
      iVar2 = *(int *)(param_2 + 8);
      FUN_1005615e(param_1,auStack_4c,0);
      FUN_10056960(param_1,iVar1,auStack_50,6,1,0);
      uVar3 = iVar2 + 0x10;
      local_5c = 0;
      for (uVar4 = 0; uVar4 < uVar3; uVar4 = uVar4 + iVar2) {
        iVar2 = 0x20;
        if (uVar3 <= uVar4 + 0x20) {
          iVar2 = uVar3 - uVar4;
        }
        FUN_10056a4a(param_1,*(int *)(param_2 + 0x10) + 4 + uVar4,auStack_38,iVar2);
        local_5c = FUN_10056a6e(param_1,iVar1 + 4 + uVar4,auStack_38,iVar2,1);
      }
      FUN_10056960(param_1,iVar1,auStack_50,6,2,1);
    }
    else {
      local_5c = 0;
    }
    FUN_100563fc(param_1,0,param_2,1);
  }
  return local_5c;
}

// FUNC 0x1005655e  FUN_1005655e

bool FUN_1005655e(char *param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_14 [8];
  
  if ((param_1[1] == '\0') || (*param_1 != '\x03')) {
    bVar2 = false;
    if (*param_1 == '\x01') {
      FUN_10056960(param_2,*(undefined4 *)(param_1 + 0x10),auStack_14,6,5,1);
      bVar2 = true;
    }
  }
  else {
    iVar1 = FUN_10056486(param_2,param_1);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}

// FUNC 0x1005659e  FUN_1005659e

undefined4 FUN_1005659e(char *param_1,undefined4 param_2)

{
  undefined1 auStack_2c [4];
  byte local_28;
  char local_27;
  int local_18 [2];
  
  if ((*param_1 != '\0') && ((byte)param_1[2] - 2 < 2)) {
    FUN_10056960(param_2,*(int *)(param_1 + 4) + 1,auStack_2c,4,3,1);
    local_18[0] = *(int *)(param_1 + 4) + 8;
    do {
      FUN_10055eb6(param_2,&local_28);
      if ((local_27 != '\0') && (local_28 - 2 < 2)) {
        FUN_10056486(param_2,&local_28);
      }
      if (param_1[1] == '\x01') {
        local_18[0] = -1;
      }
      else {
        local_18[0] = FUN_10056000(param_2,param_1,local_18);
      }
    } while (local_18[0] != -1);
    FUN_10055f3c(param_2,*(undefined4 *)(param_1 + 4));
  }
  return 0;
}

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

// FUNC 0x100567a4  FUN_100567a4

int FUN_100567a4(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(code **)(param_1 + 0x14) != (code *)0x0) {
    (**(code **)(param_1 + 0x14))();
  }
  for (uVar2 = 0; uVar2 < *(uint *)(param_1 + 0xc); uVar2 = uVar2 + *(int *)(param_1 + 8)) {
    iVar1 = FUN_10055f3c(param_1,uVar2);
    if (iVar1 != 0) goto LAB_100567cc;
  }
  iVar1 = 0;
LAB_100567cc:
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  return iVar1;
}

// FUNC 0x100567dc  FUN_100567dc

undefined4 FUN_100567dc(int param_1)

{
  int iVar1;
  int local_40;
  undefined1 auStack_3c [20];
  undefined1 auStack_28 [28];
  
  *(undefined1 *)(param_1 + 0x29) = 1;
  local_40 = 0;
  FUN_100561b6(param_1,auStack_3c,0,&local_40,param_1,PTR_LAB_10056144_1_10056864,0);
  iVar1 = FUN_10056d58(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
  if (iVar1 == local_40) {
    FUN_100567a4(param_1);
  }
  if (*(code **)(param_1 + 0x14) != (code *)0x0) {
    (**(code **)(param_1 + 0x14))(param_1);
  }
  FUN_100561b6(param_1,auStack_3c,0,param_1,0,PTR_LAB_1005632e_1_10056868,0);
  while( true ) {
    FUN_1005634e(param_1,auStack_28,param_1,0,PTR_FUN_1005655e_1_1005686c);
    if (*(char *)(param_1 + 0x28) == '\0') break;
    FUN_100562ac(param_1);
  }
  *(undefined1 *)(param_1 + 0x29) = 0;
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  return 0;
}

// FUNC 0x10056870  FUN_10056870

void FUN_10056870(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 < 4) {
    uVar1 = FUN_10056ee8(param_2);
    if (*(char *)(param_1 + 0x10) != '\0') {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(uVar1 >> 4);
  }
  return;
}

// FUNC 0x100568a2  FUN_100568a2

int FUN_100568a2(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_10056a80();
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x28) = 0;
    *(undefined1 *)(param_1 + 0x29) = 0;
    uVar2 = FUN_10056d58(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
    if (uVar2 < 2) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar1 = FUN_100567dc(param_1);
  }
  FUN_100569bc(param_1,iVar1);
  return iVar1;
}

// FUNC 0x100568d8  FUN_100568d8

uint FUN_100568d8(uint param_1,byte *param_2,int param_3)

{
  uint uVar1;
  byte *pbVar2;
  char cVar3;
  
  param_1 = ~param_1;
  pbVar2 = param_2 + param_3;
  for (; param_2 != pbVar2; param_2 = param_2 + 1) {
    cVar3 = '\b';
    uVar1 = param_1 ^ (uint)*param_2 << 0x18;
    do {
      param_1 = uVar1 << 1;
      if ((int)uVar1 < 0) {
        param_1 = param_1 ^ DAT_1005690c;
      }
      cVar3 = cVar3 + -1;
      uVar1 = param_1;
    } while (cVar3 != '\0');
  }
  return ~param_1;
}

// FUNC 0x10056910  FUN_10056910

uint FUN_10056910(undefined1 *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  *param_1 = 0xff;
  if (param_3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = param_3 - 1 >> 3;
    param_1[uVar1] = (byte)(0xff >> (param_3 & 7)) & param_1[uVar1];
  }
  return uVar1;
}

// FUNC 0x10056936  FUN_10056936

int FUN_10056936(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_2 - 2U;
  do {
    iVar2 = (param_2 - 2U) - uVar1;
    if (uVar1 == 0xffffffff) break;
    uVar3 = uVar1 & 7;
    uVar4 = uVar1 >> 3;
    uVar1 = uVar1 - 1;
  } while ((0x80 >> uVar3 & (uint)*(byte *)(param_1 + uVar4)) != 0);
  return (param_2 + -1) - iVar2;
}

// FUNC 0x10056960  FUN_10056960

undefined8 FUN_10056960(uint param_1,int param_2,int param_3,uint param_4,uint param_5,byte param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = (uint)param_6;
  if (param_4 <= param_5) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar4 = param_1;
  iVar5 = param_2;
  iVar6 = param_3;
  iVar1 = FUN_10056910(param_3,param_4);
  uVar2 = 0;
  if (iVar1 != -1) {
    uVar2 = FUN_10056a6e(param_1,iVar1 + param_2,param_3 + iVar1,1,uVar3,iVar5,iVar6);
    uVar4 = uVar3;
  }
  return CONCAT44(uVar4,uVar2);
}

// FUNC 0x1005699a  FUN_1005699a

void FUN_1005699a(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  FUN_10056a4a();
  FUN_10056936(param_3,param_4);
  return;
}

// FUNC 0x100569b6  FUN_100569b6

void FUN_100569b6(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}

// FUNC 0x100569bc  FUN_100569bc

void FUN_100569bc(int param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = DAT_100569d0;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x10) = 1;
    if (*pcVar1 == '\0') {
      *pcVar1 = '\x01';
    }
  }
  return;
}

// FUNC 0x10056a4a  FUN_10056a4a

undefined4 FUN_10056a4a(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x1c))(param_1);
  }
  return uVar1;
}

// FUNC 0x10056a5c  FUN_10056a5c

undefined4 FUN_10056a5c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x24))();
  }
  return uVar1;
}

// FUNC 0x10056a6e  FUN_10056a6e

undefined4 FUN_10056a6e(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 3;
  if (*(code **)(param_1 + 0x20) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x20))(param_1);
  }
  return uVar1;
}

// FUNC 0x10056a80  FUN_10056a80

undefined4 FUN_10056a80(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int extraout_r1;
  int iVar3;
  
  iVar1 = DAT_10056ae8;
  if (param_1 == (int *)0x0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_3 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((char)param_1[4] == '\0') {
    *param_1 = param_2;
    param_1[7] = iVar1;
    param_1[8] = DAT_10056aec;
    param_1[9] = DAT_10056af0;
    iVar1 = FUN_1004c7ac(param_3);
    *(char *)(param_1 + 1) = (char)iVar1;
    if (iVar1 == -1) {
      return 4;
    }
    param_1[2] = 0x1000;
    iVar1 = FUN_1004c79c();
    iVar3 = *(int *)(iVar1 + 0xc);
    param_1[3] = iVar3;
    iVar1 = param_1[2];
    FUN_10056d68(iVar3,iVar1);
    if (extraout_r1 != 0) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uVar2 = FUN_10056d58(iVar3,iVar1);
    if (uVar2 < 2) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  return 0;
}

// FUNC 0x10056af4  FUN_10056af4

int FUN_10056af4(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    if ((((((uint)param_1 | (uint)param_2) & 3) == 0) && (3 < param_3)) &&
       (uVar2 = *param_1, uVar2 == *param_2)) {
      param_3 = param_3 - 4;
      if (param_3 == 0) {
        return 0;
      }
      if ((uVar2 + DAT_10056b84 & ~uVar2 & DAT_10056b88) != 0) {
        return 0;
      }
      do {
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((param_3 < 4) || (uVar2 = *param_1, uVar2 != *param_2)) goto LAB_10056b48;
        param_3 = param_3 - 4;
      } while ((param_3 != 0) && ((uVar2 + DAT_10056b84 & ~uVar2 & DAT_10056b88) == 0));
    }
    else {
LAB_10056b48:
      uVar2 = (uint)(byte)*param_2;
      if (uVar2 != (byte)*param_1) {
        return (byte)*param_1 - uVar2;
      }
      if (param_3 - 1 != 0) {
        puVar1 = (uint *)((int)param_2 + (param_3 - 1));
        do {
          if (uVar2 == 0) {
            return 0;
          }
          param_2 = (uint *)((int)param_2 + 1);
          param_1 = (uint *)((int)param_1 + 1);
          uVar2 = (uint)*(byte *)param_1;
          if (uVar2 != *(byte *)param_2) {
            return uVar2 - *(byte *)param_2;
          }
        } while (puVar1 != param_2);
      }
    }
  }
  return 0;
}

// FUNC 0x10056b8c  FUN_10056b8c

uint FUN_10056b8c(undefined4 *param_1,byte *param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int extraout_r1;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  pbVar9 = param_2;
  do {
    pbVar10 = pbVar9;
    uVar8 = (uint)*pbVar10;
    iVar2 = FUN_10056d04(param_5);
    pbVar9 = pbVar10 + 1;
  } while ((*(byte *)(iVar2 + uVar8 + 1) & 8) != 0);
  if (uVar8 == 0x2d) {
    bVar1 = true;
    pbVar9 = pbVar10 + 2;
    uVar8 = (uint)pbVar10[1];
  }
  else {
    bVar1 = false;
    if (uVar8 == 0x2b) {
      pbVar9 = pbVar10 + 2;
      uVar8 = (uint)pbVar10[1];
    }
  }
  if (param_4 == 0) {
    if (uVar8 != 0x30) {
      iVar2 = 10;
      param_4 = 10;
      goto LAB_10056bd8;
    }
    if ((*pbVar9 & 0xdf) != 0x58) {
      iVar2 = 8;
      param_4 = 8;
      goto LAB_10056bd8;
    }
  }
  else {
    iVar2 = param_4;
    if (param_4 != 0x10) goto LAB_10056bd8;
    if ((uVar8 != 0x30) || ((*pbVar9 & 0xdf) != 0x58)) {
      iVar2 = 0x10;
      goto LAB_10056bd8;
    }
  }
  uVar8 = (uint)pbVar9[1];
  iVar2 = 0x10;
  pbVar9 = pbVar9 + 2;
  param_4 = 0x10;
LAB_10056bd8:
  FUN_10056d68(-0x80000000 - (uint)!bVar1,iVar2);
  uVar3 = FUN_10056d58(-0x80000000 - (uint)!bVar1,iVar2);
  iVar5 = 0;
  uVar4 = 0;
  do {
    uVar7 = uVar8 - 0x30;
    if (9 < uVar7) {
      if (uVar8 - 0x41 < 0x1a) {
        uVar7 = uVar8 - 0x37;
      }
      else {
        if (0x19 < uVar8 - 0x61) break;
        uVar7 = uVar8 - 0x57;
      }
    }
    if (param_4 <= (int)uVar7) break;
    uVar6 = uVar4;
    if (iVar5 != -1) {
      if ((uVar3 < uVar4) || ((uVar3 == uVar4 && (uVar6 = uVar3, extraout_r1 < (int)uVar7)))) {
        iVar5 = -1;
      }
      else {
        iVar5 = 1;
        uVar6 = uVar7 + iVar2 * uVar4;
      }
    }
    uVar8 = (uint)*pbVar9;
    pbVar9 = pbVar9 + 1;
    uVar4 = uVar6;
  } while( true );
  if (iVar5 == -1) {
    uVar4 = 0x80000000 - !bVar1;
    *param_1 = 0x22;
    if (param_3 == (undefined4 *)0x0) {
      return uVar4;
    }
  }
  else {
    if (bVar1) {
      uVar4 = -uVar4;
    }
    if (param_3 == (undefined4 *)0x0) {
      return uVar4;
    }
    if (iVar5 == 0) goto LAB_10056c46;
  }
  param_2 = pbVar9 + -1;
LAB_10056c46:
  *param_3 = param_2;
  return uVar4;
}

// FUNC 0x10056cd8  FUN_10056cd8

void FUN_10056cd8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*DAT_10056cfc + 0x34);
  if (iVar1 == 0) {
    iVar1 = DAT_10056d00;
  }
  FUN_10056b8c(*DAT_10056cfc,param_1,param_2,param_3,iVar1);
  return;
}

// FUNC 0x10056d04  FUN_10056d04

undefined4 FUN_10056d04(int param_1)

{
  return *(undefined4 *)(param_1 + 0xec);
}

// FUNC 0x10056d58  FUN_10056d58

void FUN_10056d58(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056d64)(param_1);
  return;
}

// FUNC 0x10056d68  FUN_10056d68

void FUN_10056d68(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056d70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056d74)(param_1);
  return;
}

// FUNC 0x10056d78  FUN_10056d78

void FUN_10056d78(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056d80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056d84)(param_1);
  return;
}

// FUNC 0x10056d88  FUN_10056d88

void FUN_10056d88(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056d90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056d94)(param_1);
  return;
}

// FUNC 0x10056d98  FUN_10056d98

void FUN_10056d98(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056da0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056da4)(param_1);
  return;
}

// FUNC 0x10056da8  FUN_10056da8

void FUN_10056da8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056db0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056db4)(param_1);
  return;
}

// FUNC 0x10056dc8  FUN_10056dc8

void FUN_10056dc8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056dd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056dd4)(param_1);
  return;
}

// FUNC 0x10056dd8  FUN_10056dd8

void FUN_10056dd8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056de0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056de4)(param_1);
  return;
}

// FUNC 0x10056de8  rom_memcpy

/* Indirect jump into the ROM/runtime copy routine; called as (dst, src, len) */

void rom_memcpy(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056df0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056df4)(param_1);
  return;
}

// FUNC 0x10056df8  FUN_10056df8

void FUN_10056df8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056e04)(param_1);
  return;
}

// FUNC 0x10056e18  FUN_10056e18

void FUN_10056e18(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056e24)(param_1);
  return;
}

// FUNC 0x10056e28  FUN_10056e28

void FUN_10056e28(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056e34)(param_1);
  return;
}

// FUNC 0x10056e38  FUN_10056e38

void FUN_10056e38(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056e44)(param_1);
  return;
}

// FUNC 0x10056e48  FUN_10056e48

void FUN_10056e48(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056e54)(param_1);
  return;
}

// FUNC 0x10056e58  FUN_10056e58

void FUN_10056e58(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056e64)(param_1);
  return;
}

// FUNC 0x10056e68  FUN_10056e68

void FUN_10056e68(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056e74)(param_1);
  return;
}

// FUNC 0x10056e78  FUN_10056e78

void FUN_10056e78(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056e84)(param_1);
  return;
}

// FUNC 0x10056e88  rom_memcmp

/* Indirect jump into the ROM/runtime compare routine; called as (a, b, len), 0 on match */

void rom_memcmp(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056e90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056e94)(param_1);
  return;
}

// FUNC 0x10056e98  FUN_10056e98

void FUN_10056e98(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056ea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056ea4)(param_1);
  return;
}

// FUNC 0x10056ea8  FUN_10056ea8

void FUN_10056ea8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056eb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056eb4)(param_1);
  return;
}

// FUNC 0x10056ed8  FUN_10056ed8

void FUN_10056ed8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056ee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056ee4)(param_1);
  return;
}

// FUNC 0x10056ee8  FUN_10056ee8

void FUN_10056ee8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056ef0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056ef4)(param_1);
  return;
}

// FUNC 0x10056f08  FUN_10056f08

void FUN_10056f08(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056f10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056f14)(param_1);
  return;
}

// FUNC 0x10056f18  FUN_10056f18

void FUN_10056f18(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056f20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056f24)(param_1);
  return;
}

// FUNC 0x10056f28  FUN_10056f28

void FUN_10056f28(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056f30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056f34)(param_1);
  return;
}

// FUNC 0x10056f38  FUN_10056f38

void FUN_10056f38(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056f44)(param_1);
  return;
}

// FUNC 0x10056f48  FUN_10056f48

void FUN_10056f48(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10056f50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_10056f54)(param_1);
  return;
}

