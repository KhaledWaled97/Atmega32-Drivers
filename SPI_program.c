
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_INTERFACE.h"
#include"SPI_interface.h"
#include"SPI_config.h"
#include"SPI_private.h"
 void (*call_back)(void);
 volatile static u8*ptr;

 void SPI_voidMasterInit (void)
 {
	 DIO_voidSetPinDirection(PORTB_ID,PIN4,PIN_INPUT);
	 DIO_voidSetPinDirection(PORTB_ID,PIN5,PIN_OUTPUT);
	 DIO_voidSetPinDirection(PORTB_ID,PIN6,PIN_INPUT);
	 DIO_voidSetPinDirection(PORTB_ID,PIN7,PIN_OUTPUT);
	 DIO_voidSetPinValue(PORTB_ID,PIN4,PIN_HIGH);
	  DIO_voidSetPinDirection(PORTA_ID,PIN6,PIN_OUTPUT);
	  DIO_voidSetPinValue(PORTA_ID,PIN6,PIN_HIGH);
	  DIO_voidSetPinDirection(PORTA_ID,PIN7,PIN_OUTPUT);
	  DIO_voidSetPinValue(PORTA_ID,PIN7,PIN_HIGH);

	  SPCR->MSTR=1;


	  SPCR->SPE=1;
	  SPCR->SPR0_1=0b00;
	  SPSR &= ~(1<<SPI2X);
	  SPCR->DORD=0b1;  //sent LSB IN first
	  SPCR->CPOL=0b0;
	  SPCR->CPHA=0x0;
 }
 void SPI_voidSlaveInit (void)
  {
 	  DIO_voidSetPinDirection(PORTB_ID,PIN4,PIN_INPUT);
 	  DIO_voidSetPinDirection(PORTB_ID,PIN5,PIN_INPUT);
 	  DIO_voidSetPinDirection(PORTB_ID,PIN6,PIN_OUTPUT);
 	  DIO_voidSetPinDirection(PORTB_ID,PIN7,PIN_INPUT);
 	  SPCR->MSTR=0;
 	  SPCR-> SPIE=0b1;   //enable interrupt

 	  SPCR->SPE=1;
 	  SPCR->SPR0_1=0b00;
 	  SPSR &= ~(1<<SPI2X);
 	  SPCR->DORD=0b1;  //sent LSB IN first
 	  SPCR->CPOL=0b0;
 	  SPCR->CPHA=0x0;
  }
u8 SPI_voidWriteChar(u8 copy_data)
{

	SPDR = copy_data;
	while(!(SPSR & (1<<SPIF)));

	return(SPDR);
}
u8 SPI_voidReadChar(void)
{
	//SPDR = 0x00;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;	
}
void SPI_voidWriteAsysChar(u8 *pt)
{
	ptr=pt;
}
void __vector_12(void)  __attribute__((signal,used));

void __vector_12(void)
{  
	SPDR=*ptr;
	//DIO_voidTogglePin(PORTA_ID,PIN3);

	//ADC_voidStartConversion();

}
