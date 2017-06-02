#include "serverCommunication.h"

serverCommunication::serverCommunication() : UCA0(USCI_A0_BASE, 9600){

}

serverCommunication::~serverCommunication(){

}

void serverCommunication::sendData(uint8_t* data){

	UCA0.transmit(data);
}

uint8_t serverCommunication::readCredit(uint8_t ID){

//	sendData(read_command);
//	sendData(char(ID));
	return (UCA0.receive_USCI_A0());

}

void serverCommunication::writeCredit(uint8_t ID, uint8_t credit){

	UCA0.transmit("ABC");
//	sendData(char(ID));
//	sendData(char(credit));
}

