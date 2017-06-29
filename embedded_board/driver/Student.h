#ifndef STUDENT_H
#define STUDENT_H

#include <stdint.h>

class student{
    uint8_t ID;
    uint8_t credit;
    public:
    student();
    ~student();
    void setID(uint8_t newID);
    uint8_t getID(void);
    void setCredit(uint8_t newCredit);
    uint8_t getCredit(void);
};

#endif
