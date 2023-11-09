/*
 * PWM_Prog.c
 *
 *  Created on: Apr 27, 2023
 *      Author: Khaled Waled
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PWM_Cfg.h"
#include "PWM_Interface.h"
#include "PWM_Private.h"
#include "DIO_interface.h"


void PWM_voidPWM_run(u8 frequency,u8 channel )
{
        /*setting timer 1 mode-->14 */
    	CLR_BIT(TCCR1A,TCCR1A_WGM10);
    	SET_BIT(TCCR1A,TCCR1A_WGM11);
    	SET_BIT(TCCR1B,TCCR1B_WGM12);
	   	SET_BIT(TCCR1B,TCCR1B_WGM13);

        /*****************************/
         /*setting the compare mode*/
        if(channel == PWM_CHANNEL_1)
        {
			CLR_BIT(TCCR1A,TCCR1A_COM1A0);
			SET_BIT(TCCR1A,TCCR1A_COM1A1);
        }
         if(channel == PWM_CHANNEL_2)
        {
			CLR_BIT(TCCR1A,TCCR1A_COM1B0);
			SET_BIT(TCCR1A,TCCR1A_COM1B1);
        }
        switch (frequency)
        {
		   	case FREQ_20_HZ  :
			PWM_ICR1L = 50000;
			 break;
			case FREQ_25_HZ  :
			PWM_ICR1L = 40000;
			 break;
			case FREQ_40_HZ  :
			PWM_ICR1L = 25000;
			  break;
			case FREQ_50_HZ  :
			PWM_ICR1L = 20000;
			 break;
			case FREQ_80_HZ  :
			PWM_ICR1L = 20000;
			break;
			case FREQ_100_HZ  :
			PWM_ICR1L = 20000;
			break;
			case FREQ_125_HZ  :
			PWM_ICR1L = 8000;
			break;
			case FREQ_200_HZ  :
			PWM_ICR1L = 5000;
			break;
			case FREQ_250_HZ  :
			PWM_ICR1L = 4000;
			break;
			case FREQ_400_HZ  :
			PWM_ICR1L = 2500;
			break;
			case FREQ_500_HZ  :
			PWM_ICR1L = 2000;
			break;
			case FREQ_1000_HZ  :
			PWM_ICR1L = 1000;
			break;
			case FREQ_1250_HZ  :
			PWM_ICR1L = 800;
			break;
			case FREQ_2000_HZ  :
			PWM_ICR1L = 500;
			break;
			case FREQ_2500_HZ  :
			PWM_ICR1L = 400;
			break;
			case FREQ_4000_HZ  :
			PWM_ICR1L = 250;
			break;
			case FREQ_5000_HZ  :
			PWM_ICR1L = 200;
			break;
			case FREQ_10000_HZ  :
			PWM_ICR1L = 100;
			break;
			case FREQ_25000_HZ  :
			PWM_ICR1L = 40;
			break;
			case FREQ_50000_HZ  :
			PWM_ICR1L = 20;
			break;
         }
 		/*choosing pre-scaler -->8*/

 		CLR_BIT(TCCR1B,TCCR1B_CS10);
 		SET_BIT(TCCR1B,TCCR1B_CS11);
 		CLR_BIT(TCCR1B,TCCR1B_CS12);
}
void PWM_voidPWM_DutyCycle(u8 percentage,u8 channel,u8 frequency)
{
	if (channel == PWM_CHANNEL_1)
    {
		switch (frequency)
        {
			case FREQ_20_HZ  :
			PWM_OCR1AL = ((50000/100)*percentage) ;
			break;
			case FREQ_25_HZ  :
			PWM_OCR1AL = ((40000/100)*percentage);
			 break;
			case FREQ_40_HZ  :
			PWM_OCR1AL= ((25000/100)*percentage);
			  break;
			case FREQ_50_HZ  :
			PWM_OCR1AL= ((20000/100)*percentage);
			 break;
			case FREQ_80_HZ  :
			PWM_OCR1AL= ((12500/100)*percentage);
			break;
			case FREQ_100_HZ  :
			PWM_OCR1AL= ((10000/100)*percentage);
			break;
			case FREQ_125_HZ  :
			PWM_OCR1AL= ((8000/100)*percentage);
			break;
			case FREQ_200_HZ  :
			PWM_OCR1AL= ((5000/100)*percentage);
			break;
			case FREQ_250_HZ  :
			PWM_OCR1AL= ((4000/100)*percentage);
			break;
			case FREQ_400_HZ  :
			PWM_OCR1AL = ((2500/100)*percentage);
			break;
			case FREQ_500_HZ  :
			PWM_OCR1AL= ((2000/100)*percentage);
			break;
			case FREQ_1000_HZ  :
			PWM_OCR1AL= ((1000/100)*percentage);
			break;
			case FREQ_1250_HZ  :
			PWM_OCR1AL= ((800/100)*percentage);
			break;
			case FREQ_2000_HZ  :
			PWM_OCR1AL= ((500/100)*percentage);
			break;
			case FREQ_2500_HZ  :
			PWM_OCR1AL= ((400/100)*percentage);
			break;
			case FREQ_4000_HZ  :
			PWM_OCR1AL= ((250/100)*percentage);
			break;
			case FREQ_5000_HZ  :
			PWM_OCR1AL=((200/100)*percentage);
			break;
			case FREQ_10000_HZ  :
			PWM_OCR1AL= ((100/100)*percentage);
			break;
			case FREQ_25000_HZ  :
			PWM_OCR1AL= ((40/100)*percentage);
			break;
			case FREQ_50000_HZ  :
			PWM_OCR1AL= ((20/100)*percentage);
			break;
        }
    }
	if (channel == PWM_CHANNEL_2)
	{
		switch (frequency)
        {
			case FREQ_20_HZ  :
			PWM_OCR1BL = ((50000/100)*percentage) ;
			break;
			case FREQ_25_HZ  :
			PWM_OCR1BL = ((40000/100)*percentage);
			 break;
			case FREQ_40_HZ  :
			PWM_OCR1BL= ((25000/100)*percentage);
			  break;
			case FREQ_50_HZ  :
			PWM_OCR1BL= ((20000/100)*percentage);
			 break;
			case FREQ_80_HZ  :
			PWM_OCR1BL= ((12500/100)*percentage);
			break;
			case FREQ_100_HZ  :
			PWM_OCR1BL= ((10000/100)*percentage);
			break;
			case FREQ_125_HZ  :
			PWM_OCR1BL= ((8000/100)*percentage);
			break;
			case FREQ_200_HZ  :
			PWM_OCR1BL= ((5000/100)*percentage);
			break;
			case FREQ_250_HZ  :
			PWM_OCR1BL= ((4000/100)*percentage);
			break;
			case FREQ_400_HZ  :
			PWM_OCR1BL = ((2500/100)*percentage);
			break;
			case FREQ_500_HZ  :
			PWM_OCR1BL= ((2000/100)*percentage);
			break;
			case FREQ_1000_HZ  :
			PWM_OCR1BL= ((1000/100)*percentage);
			break;
			case FREQ_1250_HZ  :
			PWM_OCR1BL= ((800/100)*percentage);
			break;
			case FREQ_2000_HZ  :
			PWM_OCR1BL= ((500/100)*percentage);
			break;
			case FREQ_2500_HZ  :
			PWM_OCR1BL= ((400/100)*percentage);
			break;
			case FREQ_4000_HZ  :
			PWM_OCR1BL= ((250/100)*percentage);
			break;
			case FREQ_5000_HZ  :
			PWM_OCR1BL=((200/100)*percentage);
			break;
			case FREQ_10000_HZ  :
			PWM_OCR1BL= ((100/100)*percentage);
			break;
			case FREQ_25000_HZ  :
			PWM_OCR1BL= ((40/100)*percentage);
			break;
			case FREQ_50000_HZ  :
			PWM_OCR1BL= ((20/100)*percentage);
			break;
        }
	}
}
void PWM_voidPWM_OCR_Value(u16 value,u8 channel,u8 frequency)
{
	if (channel == PWM_CHANNEL_1)
	{
		switch (frequency)
		{
			case FREQ_20_HZ  :
			PWM_OCR1AL = value ;
			break;
			case FREQ_25_HZ  :
			PWM_OCR1AL = value;
			 break;
			case FREQ_40_HZ  :
			PWM_OCR1AL= value;
			  break;
			case FREQ_50_HZ  :
			PWM_OCR1AL= value;
			 break;
			case FREQ_80_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_100_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_125_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_200_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_250_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_400_HZ  :
			PWM_OCR1AL = value;
			break;
			case FREQ_500_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_1000_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_1250_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_2000_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_2500_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_4000_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_5000_HZ  :
			PWM_OCR1AL=value;
			break;
			case FREQ_10000_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_25000_HZ  :
			PWM_OCR1AL= value;
			break;
			case FREQ_50000_HZ  :
			PWM_OCR1AL= value;
			break;
		}
    }
	if (channel == PWM_CHANNEL_2)
	{
		switch (frequency)
		{
			case FREQ_20_HZ  :
			PWM_OCR1BL = value ;
			break;
			case FREQ_25_HZ  :
			PWM_OCR1BL = value;
			 break;
			case FREQ_40_HZ  :
			PWM_OCR1BL= value;
			  break;
			case FREQ_50_HZ  :
			PWM_OCR1BL= value;
			 break;
			case FREQ_80_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_100_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_125_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_200_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_250_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_400_HZ  :
			PWM_OCR1BL = value;
			break;
			case FREQ_500_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_1000_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_1250_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_2000_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_2500_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_4000_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_5000_HZ  :
			PWM_OCR1BL=value;
			break;
			case FREQ_10000_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_25000_HZ  :
			PWM_OCR1BL= value;
			break;
			case FREQ_50000_HZ  :
			PWM_OCR1BL= value;
			break;
		}
	}
}

