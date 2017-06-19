#include "accessHandler.h"

accessHandler::accessHandler(): P1(P1_address), P4(P4_address){
    P1.setPinDirection(BIT0, output);
    P4.setPinDirection(BIT7, output);
}

accessHandler::~accessHandler(){

}

bool accessHandler::accessRequestHandler(uint8_t request_ID, dataManagement &manager){

    if(manager.hasEnoughCredit(request_ID) == false){
        closeTurnstile();
        return false;
    }

    manager.subtractCredit(request_ID);

    Student* aux;
    aux = new Student();
    char aux_str[2];
    sprintf(aux_str, "%d", request_ID);
    aux->setRegistration(aux_str);

    manager.insertInRU(aux);
    delete aux;
    manager.increaseTotalPeopleInRU();
    openTurnstile();
    return true;
}

void accessHandler::leaveRequestHandler(uint8_t request_ID, dataManagement &manager){
	manager.removeFromRU(request_ID);
	manager.decreaseTotalPeopleInRU();
	openTurnstile();
}

void accessHandler::openTurnstile(void){
    P1.clearPin(BIT0);
    P4.setPin(BIT7);
    __delay_cycles(10*400000);
    closeTurnstile();

}

void accessHandler::closeTurnstile(void){
    P4.clearPin(BIT7);
    P1.setPin(BIT0);
}

