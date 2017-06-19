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
    uint8_t totalPeopleInRU;

public:
    dataManagement();
    ~dataManagement();
    bool hasEnoughCredit(uint8_t ID);
    void subtractCredit(uint8_t ID);
    void insertInRegisteredPeopleList(Student* new_student);
    void removeFromRegisteredPeopleList(Student* student);
    void insertInRU(Student* new_student);
    void removeFromRU(uint8_t ID);
    void increaseTotalPeopleInRU(void);
    void decreaseTotalPeopleInRU(void);
};



#endif // _DATAMANAGEMENT_H
