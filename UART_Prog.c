/*
 * USART_Prog.C
 *
 *  Created on: Apr 29, 2023
 *      Author: Khaled Waled
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "UART_Cfg.h"
#include "UART_Interface.h"
#include "UART_Private.h"
void (*GlobalPTFCTCcallback_rx)(void)=NULL;
void (*GlobalPTFCTCcallback_tx)(void)=NULL;
void (*GlobalPTFCTCcallback_Empty_Regester)(void)=NULL;
u8 *PTR_TO_RECEIVED_DATA = NULL;

void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
    if(NULL != GlobalPTFCTCcallback_rx)
    {
    	*PTR_TO_RECEIVED_DATA=USART_UDR;

    	 GlobalPTFCTCcallback_rx();

    }
}

void __vector_14 (void) __attribute__((signal));
void __vector_14 (void)
{
      if(NULL != GlobalPTFCTCcallback_tx)
    {
        GlobalPTFCTCcallback_tx();
    }
}

void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
      if(NULL != GlobalPTFCTCcallback_Empty_Regester)
    {
        GlobalPTFCTCcallback_Empty_Regester();
    }
}


void UART_voidInit(void)
{
    u8 Local_var =0;


    #if UART_NUM_OF_DATA_BIT == _5_DATA_BIT
    CLR_BIT(Local_var,UCSRC_UCSZ0);
    CLR_BIT(Local_var,UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB,UCSRB_UCSZ2);
    #elif UART_NUM_OF_DATA_BIT == _6_DATA_BIT
    SET_BIT(Local_var,UCSRC_UCSZ0);
    CLR_BIT(Local_var,UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB,UCSRB_UCSZ2);
    #elif UART_NUM_OF_DATA_BIT == _7_DATA_BIT
    CLR_BIT(Local_var,UCSRC_UCSZ0);
    SET_BIT(Local_var,UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB,UCSRB_UCSZ2);
    #elif UART_NUM_OF_DATA_BIT == _8_DATA_BIT
    SET_BIT(Local_var,UCSRC_UCSZ0);
    SET_BIT(Local_var,UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB,UCSRB_UCSZ2);
    #elif UART_NUM_OF_DATA_BIT == _9_DATA_BIT
    SET_BIT(Local_var,UCSRC_UCSZ0);
    SET_BIT(Local_var,UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB,UCSRB_UCSZ2);
   #endif

    #if UART_PARITY_MODE == DIASBLE_PARITY_MODE
    CLR_BIT(Local_var,UCSRC_UPM0);
    CLR_BIT(Local_var,UCSRC_UPM1);
    #elif UART_PARITY_MODE == EVEN_PARITY_MODE 
    CLR_BIT(Local_var,UCSRC_UPM0);
    SET_BIT(Local_var,UCSRC_UPM1);
    #elif UART_PARITY_MODE == ODD_PARITY_MODE 
    SET_BIT(Local_var,UCSRC_UPM0);
    SET_BIT(Local_var,UCSRC_UPM1);
    #endif
    #if UART_BAUD_RATE ==_9600_BAUD_RATE
    USART_UBRRL= 103 ; //51 at 8 MHz
    #endif
    #if  UART_RX_INT ==  OFF
    CLR_BIT(USART_UCSRB,UCSRB_RXCIE);
    #elif  UART_RX_INT ==  ON
    SET_BIT(USART_UCSRB,UCSRB_RXCIE);
    #endif
    #if  UART_TX_INT ==  OFF
    CLR_BIT(USART_UCSRB,UCSRB_TXCIE);
    #elif  UART_RX_INT ==  ON
    SET_BIT(USART_UCSRB,UCSRB_TXCIE);
    #endif
    #if  UART_DATA_REGISTER_INT == OFF
    CLR_BIT(USART_UCSRB,UCSRB_UDRIE);
    #elif  UART_DATA_REGISTER_INT == ON
    SET_BIT(USART_UCSRB,UCSRB_UDRIE);
    #endif
    #if UART_STOP_BITS == _1_STOP_BITS
    CLR_BIT(Local_var,UCSRC_USBS);
    #elif UART_STOP_BITS == _2_STOP_BITS
    SET_BIT(Local_var,UCSRC_USBS);
    #endif
	#if UART_ASYNC_SYNC == ASYNCHRONOUS
    SET_BIT(Local_var,UCSRC_UMSEL);
    #elif UART_ASYNC_SYNC == SYNCHRONOUS
    CLR_BIT(Local_var,UCSRC_UMSEL);
    #endif
    SET_BIT(USART_UCSRB,UCSRB_RXEN);
    SET_BIT(USART_UCSRB,UCSRB_TXEN);
    SET_BIT(Local_var,7);
    USART_UCSRC = Local_var ;
}
void UART_voidSendData_sync(u8 copy_u16transmitdata)
{
    while (GET_BIT(USART_UCSRA,UCSRA_UDRE)==0); //waiting until transmit data buffer is empty 
    USART_UDR = copy_u16transmitdata;
    while (GET_BIT(USART_UCSRA,UCSRA_TXC )==0);
    SET_BIT(USART_UCSRA,UCSRA_TXC );
}
u8 UART_voidReceiveData_sync(void)
{
    while (GET_BIT(USART_UCSRA,UCSRA_RXC)==0); //waiting until receive data buffer is empty
     return USART_UDR ;
}

/*this function used when the transmitting interrupt is on*/

void UART_voidReceiveData_Async(u8 * Copy_pu8ReceivedData , void(*Copy_ptrToFunc)(void))
{
   if(Copy_ptrToFunc!= NULL)
   {
	   GlobalPTFCTCcallback_rx = Copy_ptrToFunc ;
   }

   PTR_TO_RECEIVED_DATA = Copy_pu8ReceivedData;
}
/*this function used when the receiving interrupt is on*/
void UART_voidSendData_Async(u8  Copy_u8Data , void(*Copy_ptrToFunc)(void))
{
	while(GET_BIT(USART_UCSRA,UCSRA_TXC)==0);
	USART_UDR = Copy_u8Data ;
	 if(Copy_ptrToFunc!= NULL )
	   {
		 GlobalPTFCTCcallback_tx=Copy_ptrToFunc ;
	   }
}
void UART_voidSendString_sync(u8 arr[])
{
	u8 local_itirator_variable =0;
	while(arr[local_itirator_variable]!='\0')
	{
		UART_voidSendData_sync(arr[local_itirator_variable]);
		local_itirator_variable ++;
	}
}


void UART_SetCallBack_RX(void *funcptr(void))
{
    GlobalPTFCTCcallback_rx = funcptr;
}
void UART_SetCallBack_TX(void *funcptr(void))
{
    GlobalPTFCTCcallback_tx = funcptr;
}
void UART_SetCallBack_EMPTY_REG(void *funcptr(void))
{
    GlobalPTFCTCcallback_Empty_Regester = funcptr;
}
