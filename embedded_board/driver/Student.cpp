#include "student.h"

student::student(){
    setID(0);
    setCredit(0);
}

student::~student(){

}

void student::setID(uint8_t newID){
    ID = newID;
}

uint8_t student::getID(void){
    return ID;
}

void student::setCredit(uint8_t newCredit){
	credit = newCredit;
}

uint8_t student::getCredit(void){
	return credit;
}
