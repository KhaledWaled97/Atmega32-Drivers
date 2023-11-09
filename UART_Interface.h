/*
 * USART_Interface.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Khaled Waled
 */

#ifndef INC_USART_INTERFACE_H_
#define INC_USART_INTERFACE_H_
#include "STD_TYPES.h"


#define ON                           1
#define OFF                          2

/****************************/
#define _5_DATA_BIT                  0
#define _6_DATA_BIT                  1
#define _7_DATA_BIT                  2
#define _8_DATA_BIT                  3
#define _9_DATA_BIT                  8

/****************************/

#define DIASBLE_PARITY_MODE          0
#define EVEN_PARITY_MODE             1
#define ODD_PARITY_MODE              2

/*****************************/   
#define  _9600_BAUD_RATE             9600
/*****************************/
#define _1_STOP_BITS                  0
#define _2_STOP_BITS                  1
/*****************************/
#define ASYNCHRONOUS                 0
#define SYNCHRONOUS                  1
/*****************************/
void UART_voidInit(void);
void UART_voidSendData_sync(u8 copy_u16transmitdata);
u8 UART_voidReceiveData_sync(void);
void UART_voidSendString_sync(u8 arr[]);
void UART_voidSendData_Async(u8  Copy_u8Data , void(*Copy_ptrToFunc)(void));
void UART_voidReceiveData_Async(u8 * Copy_pu8ReceivedData , void(*Copy_ptrToFunc)(void));
void UART_SetCallBack_RX(void *funcptr(void));
void UART_SetCallBack_TX(void *funcptr(void));
void UART_SetCallBack_EMPTY_REG(void *funcptr(void));

#endif /* INC_USART_INTERFACE_H_ */
