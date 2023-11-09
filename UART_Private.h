/*
 * USART_Private.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Khaled Waled
 */

#ifndef INC_USART_PRIVATE_H_
#define INC_USART_PRIVATE_H_

#define USART_UDR           *((volatile u8*)(0x2C))  //reading and writing


#define USART_UCSRA         *((volatile u8*)(0x2B))  //USART Control and Status Register A

#define UCSRA_RXC               7 //This flag bit is set when there are unread data in the receive buffer and cleared when the receive buffer is empty
#define UCSRA_TXC               6 //
#define UCSRA_UDRE              5 //The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data
#define UCSRA_FE                4 //This bit is set if the next character in the receive buffer had a Frame Error when received.
#define UCSRA_DOR               3 //This bit is set if a Data OverRun condition is detected.
#define UCSRA_PE                2 //This bit is set if the next character in the receive buffer had a Parity Error
#define UCSRA_U2X               1 //

#define USART_UCSRB         *((volatile u8*)(0x2A))  //USART Control and Status Register B

#define UCSRB_RXCIE             7 //RX Complete Interrupt Enable
#define UCSRB_TXCIE             6 //TX Complete Interrupt Enable      
#define UCSRB_UDRIE             5 //USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN              4 //Receiver Enable 
#define UCSRB_TXEN              3 //transmitting Enable
#define UCSRB_UCSZ2             2 //Character Size
#define UCSRB_RXB8              1 //Receive Data Bit 8
#define UCSRB_TXB8              0 //Transmit Data Bit 8

#define USART_UCSRC          *((volatile u8*)(0x40)) //USART Control and Status Register c


#define UCSRC_URSEL             7 // Register Select
#define UCSRC_UMSEL             6 // This bit selects between Asynchronous and Synchronous mode of operation
#define UCSRC_UPM1              5 // Parity Mode 2
#define UCSRC_UPM0              4 // Parity Mode 1
#define UCSRC_USBS              3 //Stop Bit Select 
#define UCSRC_UCSZ1             2 //Character Size
#define UCSRC_UCSZ0             1 //Character Size
#define UCSRC_UCPOL             0 //clock polarity

#define USART_UBRRH          *((volatile u8*)(0x40))
#define USART_UBRRL          *((volatile u8*)(0x29))
#define UBRRH_URSEL

#endif /* INC_USART_PRIVATE_H_ */
