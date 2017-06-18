#ifndef _DATAMANAGEMENT_H
#define _DATAMANAGEMENT_H

#include <msp430.h>
#include <sstream>
#include <stdint.h>
#include "list.h"
#include "student.h"

class dataManagement{
private:
    List<Student*> registeredPeopleList;
    List<Student*> peopleInRU;

public:
    dataManagement();
    ~dataManagement();
    bool hasEnoughCredit(uint8_t ID);
    void insertInRegisteredPeopleList(Student* new_student);
    void removeFromRegisteredPeopleList(Student* student);
    void insertInRU(uint8_t ID);
    void removeFromRU(uint8_t ID);
};



#endif // _DATAMANAGEMENT_H
