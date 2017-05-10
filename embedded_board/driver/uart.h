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


class uart{

	uint16_t baudRate;
	uint16_t baseAddress;

public:
	uart();
	~uart();
	uint16_t getBaudRate();
	uint8_t
	void send(* uint8_t);
	*uint8_t receive();
}



#endif /* UART_H_ */
