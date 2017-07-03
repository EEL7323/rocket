#include "dataManagement.h"


dataManagement::dataManagement(){

    Student* aux;
    aux = new Student();
    aux->setRegistration("00");
    aux->setCred(1);
    insertInRU(aux);
    delete aux;
    totalPeopleInRU = 0;
}


dataManagement::~dataManagement(){

}

bool dataManagement::hasEnoughCredit(uint8_t ID){

    char* ID_str;
    ID_str = new char;
    sprintf(ID_str, "%2.2d", ID);
    volatile uint8_t x = registeredPeopleList.getRegCred(ID_str);
    if(x > 0){
        delete ID_str;
        return true;
    }
    else{
        delete ID_str;
        return false;
    }
}

void dataManagement::subtractCredit(uint8_t ID){

    char* ID_str;
    ID_str = new char;
    sprintf(ID_str, "%2.2d", ID);
    registeredPeopleList.decreaseRegCred(ID_str);
    delete ID_str;
}



void dataManagement::insertInRU(Student* new_student){

    peopleInRU.pushFinal(new_student);
}



void dataManagement::removeFromRU(uint8_t ID){

    Student* aux;
    aux = new Student();
    char* ID_str;
    ID_str = new char;
    sprintf(ID_str, "%2.2d", ID);
    aux = peopleInRU.getElement(ID_str);
    peopleInRU.deleteStudent(aux);
    delete ID_str;
}



void dataManagement::insertInRegisteredPeopleList(Student* new_student){

    registeredPeopleList.pushFront(new_student);
    __no_operation();
}



void dataManagement::removeFromRegisteredPeopleList(Student* student){

}



void dataManagement::increaseTotalPeopleInRU(void){

    totalPeopleInRU++;
}


void dataManagement::decreaseTotalPeopleInRU(void){

    totalPeopleInRU--;
}

Student dataManagement::getFromRegisteredPeopleList(uint8_t ID){

    Student* aux;
    char* ID_str;
    ID_str = new char;
    sprintf(ID_str, "%2.2d", ID);
    aux = registeredPeopleList.getElement(ID_str);
    delete ID_str;
    return *aux;
}


bool dataManagement::existRegisteredPeopleList(std::string v)
{
    return  registeredPeopleList.existElementReg(v);
}

uint8_t dataManagement::getPeopleInRu(){
    return totalPeopleInRU;
}

void dataManagement::rechargeCredit(uint8_t ID, uint8_t cred){

    char* ID_str;
    ID_str = new char;
    sprintf(ID_str, "%2.2d", ID);
    registeredPeopleList.setRegCred(ID_str, cred);
    delete ID_str;
}
