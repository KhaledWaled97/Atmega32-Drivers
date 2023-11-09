/*
 * DC_MOTOR_program.c
 *
 * Created: 2/11/2023
 *  Author: Khaled Waled
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_config.h"
#include "DC_MOTOR_private.h"
void HDC_Init(u8 Copy_u8MotorPort,u8 Copy_u8MotorTerminal1Pin,u8 Copy_u8MotorTerminal2Pin)
{
  	switch(Copy_u8MotorPort)
	{
	   case PORTA_ID :
		   DIO_voidSetPinDirection(PORTA_ID,Copy_u8MotorTerminal1Pin,PIN_OUTPUT);
		   DIO_voidSetPinDirection(PORTA_ID,Copy_u8MotorTerminal2Pin,PIN_OUTPUT);
		   break;
	   case PORTB_ID :
		   DIO_voidSetPinDirection(PORTB_ID,Copy_u8MotorTerminal1Pin,PIN_OUTPUT);
		   DIO_voidSetPinDirection(PORTB_ID,Copy_u8MotorTerminal2Pin,PIN_OUTPUT);
		   break;
	   case PORTC_ID :
		   DIO_voidSetPinDirection(PORTC_ID,Copy_u8MotorTerminal1Pin,PIN_OUTPUT);
		   DIO_voidSetPinDirection(PORTC_ID,Copy_u8MotorTerminal2Pin,PIN_OUTPUT);
		   break;
	   case PORTD_ID :
		   DIO_voidSetPinDirection(PORTD_ID,Copy_u8MotorTerminal1Pin,PIN_OUTPUT);
		   DIO_voidSetPinDirection(PORTD_ID,Copy_u8MotorTerminal2Pin,PIN_OUTPUT);
		   break;
	   default:
		   /* return error  */
		   break;
    }

}

void HDC_RotateCW(u8 Copy_u8MotorPort,u8 Copy_u8MotorTerminal1Pin,u8 Copy_u8MotorTerminal2Pin)
{
	// Terminal 1  of the DC motor will be connected to high pin and Terminal 2 to low pin
	switch(Copy_u8MotorPort)
	{
		case PORTA_ID :
		   DIO_voidSetPinValue(PORTA_ID,Copy_u8MotorTerminal1Pin,PIN_HIGH);
		   DIO_voidSetPinValue(PORTA_ID,Copy_u8MotorTerminal2Pin,PIN_LOW);
		   break;
        case PORTB_ID :
           DIO_voidSetPinValue(PORTB_ID,Copy_u8MotorTerminal1Pin,PIN_HIGH);
           DIO_voidSetPinValue(PORTB_ID,Copy_u8MotorTerminal2Pin,PIN_LOW);
           break;
		case PORTC_ID :
		   DIO_voidSetPinValue(PORTC_ID,Copy_u8MotorTerminal1Pin,PIN_HIGH);
		   DIO_voidSetPinValue(PORTC_ID,Copy_u8MotorTerminal2Pin,PIN_LOW);
		   break;
		case PORTD_ID :
		   DIO_voidSetPinValue(PORTD_ID,Copy_u8MotorTerminal1Pin,PIN_HIGH);
		   DIO_voidSetPinValue(PORTD_ID,Copy_u8MotorTerminal2Pin,PIN_LOW);
		   break;
		default:
		/* return error  */
		break;
	}
}
void HDC_RotateCCW(u8 Copy_u8MotorPort,u8 Copy_u8MotorTerminal1Pin,u8 Copy_u8MotorTerminal2Pin)
{
	// Terminal 1  of the DC motor will be connected to LOW pin and Terminal 2 to HIGH pin
	switch(Copy_u8MotorPort)
	{
		case PORTA_ID :
		   DIO_voidSetPinValue(PORTA_ID,Copy_u8MotorTerminal1Pin,PIN_LOW);
		   DIO_voidSetPinValue(PORTA_ID,Copy_u8MotorTerminal2Pin,PIN_HIGH);
		   break;
		case PORTB_ID :
		   DIO_voidSetPinValue(PORTB_ID,Copy_u8MotorTerminal1Pin,PIN_LOW);
		   DIO_voidSetPinValue(PORTB_ID,Copy_u8MotorTerminal2Pin,PIN_HIGH);
		   break;
		case PORTC_ID :
		   DIO_voidSetPinValue(PORTC_ID,Copy_u8MotorTerminal1Pin,PIN_LOW);
		   DIO_voidSetPinValue(PORTC_ID,Copy_u8MotorTerminal2Pin,PIN_HIGH);
		   break;
		case PORTD_ID :
		   DIO_voidSetPinValue(PORTD_ID,Copy_u8MotorTerminal1Pin,PIN_LOW);
		   DIO_voidSetPinValue(PORTD_ID,Copy_u8MotorTerminal2Pin,PIN_HIGH);
		   break;
		default:
		/* return error  */
		break;
	}

}

void HDC_voidStopMotor(u8 Copy_u8MotorPort,u8 Copy_u8MotorTerminal1Pin,u8 Copy_u8MotorTerminal2Pin)
{
	switch(Copy_u8MotorPort)
	{
		case PORTA_ID :
		   DIO_voidSetPinValue(PORTA_ID,Copy_u8MotorTerminal1Pin,PIN_LOW);
		   DIO_voidSetPinValue(PORTA_ID,Copy_u8MotorTerminal2Pin,PIN_LOW);
		   break;
		case PORTB_ID :
		   DIO_voidSetPinValue(PORTB_ID,Copy_u8MotorTerminal1Pin,PIN_LOW);
		   DIO_voidSetPinValue(PORTB_ID,Copy_u8MotorTerminal2Pin,PIN_LOW);
		   break;
		case PORTC_ID :
		   DIO_voidSetPinValue(PORTC_ID,Copy_u8MotorTerminal1Pin,PIN_LOW);
		   DIO_voidSetPinValue(PORTC_ID,Copy_u8MotorTerminal2Pin,PIN_LOW);
		   break;
		case PORTD_ID :
		   DIO_voidSetPinValue(PORTD_ID,Copy_u8MotorTerminal1Pin,PIN_LOW);
		   DIO_voidSetPinValue(PORTD_ID,Copy_u8MotorTerminal2Pin,PIN_LOW);
		   break;
		default:
		/* return error  */
		break;
	}

}
