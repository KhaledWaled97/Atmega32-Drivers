/*
 * WDT_Prog.c
 *
 *  Created on: Apr 28, 2023
 *      Author: Khaled Waled
 */
#include "WDT_Cfg.h"
#include "WDT_Interface.h"
#include "WDT_Private.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

void WDT_voidEnable(void)
{
	SET_BIT(WDCTR,WDCTR_WDE);
}
void WDT_voidDisable(void)
{

	WDCTR= 0b00011000;
		WDCTR =0;
}
void WDT_voidSleepTIME(u8 time)
{
	WDCTR &= 0b1111100;
	WDCTR |= time;
}

