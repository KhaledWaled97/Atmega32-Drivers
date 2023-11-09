/*
 * Interrupt_prog.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Khaled Waled
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Interrupt_interface.h"
#include "Interrupt_private.h"
//function to enable global interrupts
void GIE_voidEnable(void)
{
	SET_BIT(SREG,GLOBAL_INTERRUPT);  //set pin of global interrupts
}

//function to disable global interrupts
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,GLOBAL_INTERRUPT); //clear pin of global interrupts
}

