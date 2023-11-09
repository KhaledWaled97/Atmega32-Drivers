/*
 * PWM_Private.h
 *
 *  Created on: Apr 27, 2023
 *      Author: Khaled Waled
 */

#ifndef INC_PWM_PRIVATE_H_
#define INC_PWM_PRIVATE_H_

#define TCCR1A                *((volatile u8*)(0x4F))


#define TCCR1A_WGM10				0
#define TCCR1A_WGM11				1
#define TCCR1A_COM1B1				4
#define TCCR1A_COM1B0				5
#define TCCR1A_COM1A0				6
#define TCCR1A_COM1A1				7

#define TCCR1B                *((volatile u8*)(0x4E))

#define TCCR1B_CS10					0
#define TCCR1B_CS11					1
#define TCCR1B_CS12					2
#define TCCR1B_WGM12				3
#define TCCR1B_WGM13				4
#define TCCR1B_COM1A1				7

#define TCCR0				*((volatile u8*)(0x53))

#define TCCR0_WGM00					6
#define TCCR0_COM01					5
#define TCCR0_CS01					1
#define TCCR0_CS00					0
#define TCCR0_WGM01					3
#define OCR0                *((volatile u8*)(0x5C))

#define PWM_OCR1AL         *((volatile u16*)(0x4A))
#define PWM_OCR1BL         *((volatile u16*)(0x48))
#define PWM_ICR1L          *((volatile u16*)(0x46))

#endif /* INC_PWM_PRIVATE_H_ */
