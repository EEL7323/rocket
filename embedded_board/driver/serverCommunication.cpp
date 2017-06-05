#include <stdio.h>
#include "serverCommunication.h"

serverCommunication::serverCommunication() : UCA0(USCI_A0_BASE, 9600){

}

serverCommunication::~serverCommunication(){

}

void serverCommunication::sendData(uint8_t* data){

	UCA0.transmit(data);
}

uint8_t serverCommunication::readCredit(uint8_t ID){

	char string[2];
	sendData((uint8_t*)read_command);
	sprintf(string, "%2.2d", ID);
	sendData((uint8_t*)string);
	return (UCA0.receive_USCI_A0());

}

void serverCommunication::writeCredit(uint8_t ID, uint8_t credit){
	char string[3];
	sprintf(string, "%2.2d", ID);
	sendData((uint8_t*)write_command);
	sendData((uint8_t*)string);
	sprintf(string, "%3.3d", credit);
	sendData((uint8_t*)string);
}

