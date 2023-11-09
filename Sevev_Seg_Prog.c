/*
 * Seven_Segment.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Khaled Waled
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "Sevev_Seg_config.h"
#include "Sevev_Seg_private.h"
#include "Sevev_Seg_interface.h"

void Sev_Seg_Intialize(void)
{
	// pins of seven segment on the kit
	DIO_voidSetPinDirection(PORTB_ID,PIN0,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID,PIN1,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID,PIN2,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID,PIN4,PIN_OUTPUT);

	DIO_voidSetPinDirection(PORTB_ID,PIN6,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID,PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA_ID,PIN2,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA_ID,PIN3,PIN_OUTPUT);
}
void Sev_Seg_Disable_1(void)
{
	DIO_voidSetPinValue(PORTB_ID,PIN6,PIN_HIGH);
}
void Sev_Seg_Disable_2(void)
{
	DIO_voidSetPinValue(PORTB_ID,PIN5,PIN_HIGH);
}
void Sev_Seg_Disable_3(void)
{
	DIO_voidSetPinValue(PORTA_ID,PIN2,PIN_HIGH);
}
void Sev_Seg_Disable_4(void)
{
	DIO_voidSetPinValue(PORTA_ID,PIN3,PIN_HIGH);
}
void Sev_Seg_Enable_1(void)
{
	DIO_voidSetPinValue(PORTB_ID,PIN6,PIN_LOW);
}

void Sev_Seg_Enable_2(void)
{
	DIO_voidSetPinValue(PORTB_ID,PIN5,PIN_LOW);
}
void Sev_Seg_Enable_3(void)
{
	DIO_voidSetPinValue(PORTA_ID,PIN2,PIN_LOW);
}
void Sev_Seg_Enable_4(void)
{
	DIO_voidSetPinValue(PORTA_ID,PIN3,PIN_LOW);
}
void Sev_Seg_WriteNumber(u8 Number)
{
	if (Number<10)
	{
		DIO_voidSetPinValue(PORTB_ID ,PIN0 ,GET_BIT(Number,0));
		DIO_voidSetPinValue(PORTB_ID ,PIN1 ,GET_BIT(Number,1));
		DIO_voidSetPinValue(PORTB_ID ,PIN2 ,GET_BIT(Number,2));
		DIO_voidSetPinValue(PORTB_ID ,PIN4 ,GET_BIT(Number,3));
	}

}

