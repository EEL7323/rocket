#ifndef _serverCommunication_H_
#define _serverCommunication_H_

#include <msp430.h>
#include <sstream>
#include "uart.h"
#include "dataManagement.h"

#define write_command "w"
#define read_command "r"

#define asciiToInt(x) (x - '0')

class serverCommunication{

private:

	uart UCA0;
	void sendData(uint8_t* data);


public:

	serverCommunication();
	~serverCommunication();
	uint32_t readCredit(uint8_t ID);
	void writeCredit(uint8_t ID, uint8_t credit);
	void readDatabase(dataManagement &manager);
};







#endif // _serverCommunication_H_
