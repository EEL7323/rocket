#include "studentHandler.h"
using namespace std;

#define NUM_STUDENTS 20

bool studentHandler::register_student(uint8_t ID, uint8_t credit){
    uint8_t empty_index = 0;
    uint8_t empty_flag = 0;
    for(int i = 0; i < NUM_STUDENTS; i++){
        if(students[i].getID() == ID){
            return false;
        }
        if(students[i].getID() == 0 && empty_flag == 0){
            empty_index = i;
            empty_flag = 1;
        }
    }
    if(empty_flag == 0) {
        return false;
    }
    else{
        students[empty_index].setID(ID);
        students[empty_index].setCredit(credit);
    }
    return true;
}

uint8_t studentHandler::getCredit(uint8_t ID){
    volatile uint8_t studentIndex;
    volatile bool studentMatchFlag;
    for(int i = 0; i < NUM_STUDENTS; i++){
        if(ID == students[i].getID()){
            studentIndex = i;
            studentMatchFlag = true;
        }
    }
    if(studentMatchFlag == false)
        return 0;
    else{
    	return students[studentIndex].getCredit();
    }
}

void studentHandler::remove_student(uint8_t ID){
    volatile uint8_t studentMatchIndex;
    volatile bool studentMatchFlag;
    for(int i = 0; i < NUM_STUDENTS; i++){
        if(ID == students[i].getID()) {
            studentMatchFlag = true;
            studentMatchIndex = i;
        }
    }

    if(studentMatchFlag == true){
        students[studentMatchIndex].setID(0);
        students[studentMatchIndex].setCredit(0);
    }
}

void studentHandler::setCredit(uint8_t ID, uint8_t credit){
    volatile uint8_t studentIndex;
    volatile bool studentMatchFlag;
    for(int i = 0; i < NUM_STUDENTS; i++){
        if(ID == students[i].getID()){
            studentIndex = i;
            studentMatchFlag = true;
        }
    }
    if(studentMatchFlag == false)
        return;
    else{
    	students[studentIndex].setCredit(credit);
    }
}
