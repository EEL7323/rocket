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
	uint16_t baseAddress;
	port uartPort;
	void PM_UCA1(void);

public:
	uart(uint16_t p_baseAddress, uint16_t p_baudRate);
	~uart();
	void transmit(uint8_t *data);
	void receive(uint8_t *buffer);
};



#endif /* UART_H_ */
