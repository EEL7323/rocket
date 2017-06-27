#ifndef STUDENT_HANDLER_H
#define STUDENT_HANDLER_H

#include "student.h"
#include <stdint.h>

#define NUM_STUDENTS 20

class studentHandler{
    student students[NUM_STUDENTS];
    public:
    uint8_t getCredit(uint8_t ID);
    bool register_student(uint8_t ID, uint8_t credit);
    void remove_student(uint8_t ID);
    void setCredit(uint8_t ID, uint8_t credit);
};

#endif
