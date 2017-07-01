#include <stdio.h>
#include "serverCommunication.h"

serverCommunication::serverCommunication() : UCA0(USCI_A0_BASE, 9600){

}

serverCommunication::~serverCommunication(){

}

void serverCommunication::sendData(uint8_t* data){

	UCA0.transmit(data);
}

uint32_t serverCommunication::readCredit(uint8_t ID){

	char string[2];
	sendData((uint8_t*)read_command);
	sprintf(string, "%2.2d", ID);
	sendData((uint8_t*)string);
	__delay_cycles(800000);
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

void serverCommunication::readDatabase(dataManagement &manager){

    Student aux[14];
    volatile uint32_t received_data = 0;
    volatile uint8_t aux_credit = 0;
    char* aux_registration;
    aux_registration = new char;

    for(volatile uint8_t i = 1; i < 5; i++){
        received_data = readCredit(i);
        aux_credit = asciiToInt((received_data >> 16) & 0xFF)*100 + asciiToInt((received_data >> 8) & 0xFF)*10 + asciiToInt(received_data & 0xFF);
        sprintf(aux_registration, "%2.2d", i);
        (aux+i)->setRegistration(aux_registration);
        (aux+i)->setCred(aux_credit);
        manager.insertInRegisteredPeopleList(aux+i);
    }

    delete aux_registration;
}

