#ifndef __CARTMEM_H__
#define __CARTMEM_H__

#define CART_EEPROM_LENGTH 0x200 /* 512 bytes */
#define CART_2XEEPROM_LENGTH 0x800 /* 2048 bytes */
#define CART_SRAM_LENGTH 0x8000  /* 32KB */
#define CART_FLASHRAM_LENGTH 0x20000  /* 128KB */
#define CONTROLLER_MEMPAK_LENGTH 0x8000 /* 32KB */

#define CART_SRAM_ADDR 0xa8000000
#define CART_FLASHRAM_ADDR CART_SRAM_ADDR

#endif
