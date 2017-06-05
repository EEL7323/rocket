#ifndef _serverCommunication_H_
#define _serverCommunication_H_

#include <msp430.h>
#include <sstream>
#include "uart.h"

#define write_command "w"
#define read_command 'r'


class serverCommunication{

private:

	uart UCA0;
	void sendData(uint8_t* data);


public:

	serverCommunication();
	~serverCommunication();
	uint8_t readCredit(uint8_t ID);
	void writeCredit(uint8_t ID, uint8_t credit);
};







#endif // _serverCommunication_H_
