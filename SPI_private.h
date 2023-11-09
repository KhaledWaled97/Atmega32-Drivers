
#ifndef _SPI_PRIV_H
#define _SPI_PRIV_H

typedef struct{

	volatile u8   SPR0_1:2;
	volatile u8   CPHA :1;
	volatile u8   CPOL:1;
	volatile u8   MSTR:1;
	volatile u8   DORD:1;
	volatile u8   SPE:1;
	volatile u8   SPIE:1;
}SPCR;

#define     		 SPI2X    0x00
#define     		 SPIF     0x07

#define SPCR		((volatile SPCR * )(0x2D))
#define SPDR		(*((volatile u8 * ) (0X2F)))
#define SPSR	    (*((volatile u8 * ) (0X2E)))

#endif
