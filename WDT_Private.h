/*
 * WDT_Private.h
 *
 *  Created on: Apr 28, 2023
 *      Author: Khaled Waled
 */

#ifndef INC_WDT_PRIVATE_H_
#define INC_WDT_PRIVATE_H_

#define WDCTR *((volatile u8*)(0x41))

#define WDCTR_WDE        		  3
#define WDCTR_WDTOE 			  4


#endif /* INC_WDT_PRIVATE_H_ */
