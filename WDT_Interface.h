/*
 * WDT_Interface.h
 *
 *  Created on: Apr 28, 2023
 *      Author: Khaled Waled
 */

#ifndef INC_WDT_INTERFACE_H_
#define INC_WDT_INTERFACE_H_
#include "STD_TYPES.h"

void WDT_voidEnable(void);
void WDT_voidDisable(void);
void WDT_voidSleepTIME(u8 time);
#endif /* INC_WDT_INTERFACE_H_ */
