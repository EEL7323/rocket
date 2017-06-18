#include "dataManagement.h"

dataManagement::dataManagement(){

}

dataManagement::~dataManagement(){

}

bool dataManagement::hasEnoughCredit(uint8_t ID){
    char ID_str[2];
    sprintf(ID_str, "%d", ID);
    if(registeredPeopleList.getRegCred(ID_str) > 0)
        return true;
    else
        return false;
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
