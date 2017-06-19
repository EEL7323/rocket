#include "dataManagement.h"

dataManagement::dataManagement(){
	totalPeopleInRU = 0;
}

dataManagement::~dataManagement(){

}

bool dataManagement::hasEnoughCredit(uint8_t ID){
    char* ID_str;
    ID_str = (char*) malloc(2);
    sprintf(ID_str, "%2.2d", ID);
    if(registeredPeopleList.getRegCred(ID_str) > 0){
    	free(ID_str);
        return true;
    }
    else{
    	free(ID_str);
        return false;
    }

}

void dataManagement::subtractCredit(uint8_t ID){
    char* ID_str;
    ID_str = (char*) malloc(2);
    sprintf(ID_str, "%2.2d", ID);
    registeredPeopleList.decreaseRegCred(ID_str);
    free(ID_str);
}

void dataManagement::insertInRU(Student* new_student){
    peopleInRU.pushFinal(new_student);
}

void dataManagement::removeFromRU(uint8_t ID){

}

void dataManagement::insertInRegisteredPeopleList(Student* new_student){
    registeredPeopleList.pushFinal(new_student);
}

void dataManagement::removeFromRegisteredPeopleList(Student* student){
}

void dataManagement::increaseTotalPeopleInRU(void){
	totalPeopleInRU++;
}

void dataManagement::decreaseTotalPeopleInRU(void){
	totalPeopleInRU--;
}
