/*
 * uart.h
 *
 *  Created on: 10 de mai de 2017
 *      Author: mfrata
 */

#ifndef UART_H_
#define UART_H_

#include <msp430.h>
#include <stdint.h>
#include "io.h"


class uart{

private:
	uint16_t baudRate;
	volatile uint16_t baseAddress;
	static uint32_t UCA0RxBuffer;
	static uint32_t UCA1RxBuffer;
	port uartPort;
	void PM_UCA1(void);

public:
	uart(uint16_t p_baseAddress, uint16_t p_baudRate);
	~uart();
	void transmit(uint8_t *data);
	static uint32_t receive_USCI_A0(void);
	static uint8_t receive_USCI_A1(void);
	static interrupt void USCI_A0_ISR(void);
	static interrupt void USCI_A1_ISR(void);
};



#endif /* UART_H_ */
