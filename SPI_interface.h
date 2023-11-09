
#ifndef _SPI_INT_H
#define _SPI_INT_H






void SPI_voidMasterInit (void);
void SPI_voidSlaveInit (void);

u8 SPI_voidWriteChar(u8 copy_data);
u8 SPI_voidReadChar(void);
void SPI_voidWriteAsysChar(u8 *pt);

#endif
