/*
 * ServoMotor_program.c
 *
 * Created: 9/27/2023
 *  Author: Khaled Waled
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_register.h"
#include "Servo_Interface.h"
#include "Servo_config.h"
#include "Servo_private.h"


void HSERVO_voidInit(void)
{
	/* Set servo pin as output pin */
	DIO_voidSetPinDirection(PORTD_ID,PIN5,PIN_OUTPUT);
	TIMER1_voidInit();
	ICR1=19999; // to implement duty cycle with 20ms time period (20000*tick_time(==1ms) )
}

void HSERVO_voidRotate(f32 Copy_f32Angle)
{
	if ( (Copy_f32Angle>=MINIMUM_ANGLE) && (Copy_f32Angle<=MAXIMUM_ANGLE) )
	{
		if (Copy_f32Angle==-90)
		{
			OCR1A=1000;
		}
		else if (Copy_f32Angle==0)
		{
			OCR1A=1500;
			
		}
		else if (Copy_f32Angle==90)
		{
			OCR1A=2000;
		}
	}
}
