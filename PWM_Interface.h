/*
 * PWM_Interface.h
 *
 *  Created on: Apr 27, 2023
 *      Author: Khaled Waled
 */

#ifndef INC_PWM_INTERFACE_H_
#define INC_PWM_INTERFACE_H_
#include "STD_TYPES.h"

/*************************/

#define CONFIGRATION_VALID      1
#define CONFIGRATION_INVALID    2

/*************************/
#define PWM_CHANNEL_1           1
#define PWM_CHANNEL_2           2

/*************************/ 
#define PRESCALER_1             1
#define PRESCALER_8             2    
#define PRESCALER_64            3    
#define PRESCALER_256           4
#define PRESCALER_1024          5

/**************************/

#define FREQ_20_HZ              1
#define FREQ_25_HZ              2
#define FREQ_40_HZ              3
#define FREQ_50_HZ              4 
#define FREQ_80_HZ              5 
#define FREQ_100_HZ             6
#define FREQ_125_HZ             7 
#define FREQ_200_HZ             8
#define FREQ_250_HZ             9
#define FREQ_400_HZ             10 
#define FREQ_500_HZ             11 
#define FREQ_1000_HZ            12
#define FREQ_1250_HZ            13
#define FREQ_2000_HZ            14 
#define FREQ_2500_HZ            15
#define FREQ_4000_HZ            16
#define FREQ_5000_HZ            17
#define FREQ_10000_HZ           18
#define FREQ_25000_HZ           19
#define FREQ_50000_HZ           20

void PWM_voidPWM_run(u8 frequency,u8 channel);
void PWM_voidPWM_DutyCycle(u8 percentage,u8 channel,u8 frequency);
void PWM_voidPWM_OCR_Value(u16 value , u8 channel,u8 frequency);
void PWM_Config(void);
void PWM_duty(u32 duty);

#endif /* INC_PWM_INTERFACE_H_ */
