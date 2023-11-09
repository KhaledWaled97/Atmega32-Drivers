/*
 * USART_Cfg.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Khaled Waled
 */

#ifndef INC_USART_CFG_H_
#define INC_USART_CFG_H_

/****************************************************************/
/** !comment : Please Enter UART_NUM_OF_DATA_BIT				*/
/** 		   				_5_DATA_BIT							*/
/*					    	_6_DATA_BIT							*/
/*							_7_DATA_BIT							*/
/*				    		_8_DATA_BIT							*/
/*							_9_DATA_BIT							*/
/****************************************************************/
#define UART_NUM_OF_DATA_BIT            _8_DATA_BIT
/****************************************************************/
/** !comment : Please Enter UART_PARITY_MODE					*/
/** 		   				DIASBLE_PARITY_MODE					*/
/*					    	EVEN_PARITY_MODE   					*/
/*							ODD_PARITY_MODE    					*/
/****************************************************************/
#define UART_PARITY_MODE                DIASBLE_PARITY_MODE

#define UART_BAUD_RATE                  _9600_BAUD_RATE
/****************************************************************/
/** !comment : Please Enter UART_RX_INT & UART_TX_INT			*/
/** 		   				OFF									*/
/*					    	ON				   					*/
/****************************************************************/
#define UART_RX_INT                     OFF
#define UART_TX_INT                     OFF
#define UART_DATA_REGISTER_INT          OFF
/****************************************************************/
/** !comment : Please Enter UART_STOP_BITS						*/
/** 		   				_1_STOP_BITS 						*/
/*					    	_2_STOP_BITS 	   					*/
/****************************************************************/
#define UART_STOP_BITS                  _1_STOP_BITS
/****************************************************************/
/** !comment : Please Enter UART_ASYNC_SYNC						*/
/** 		   				ASYNCHRONOUS 						*/
/*					    	SYNCHRONOUS 	   					*/
/****************************************************************/
#define UART_ASYNC_SYNC                  SYNCHRONOUS
#endif /* INC_USART_CFG_H_ */
