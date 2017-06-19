#include <string>
#include "student.h"
using namespace std;

Student::Student()
{
    name = "";
    registration = "";
    cred = 0;
}
Student::~Student(){
}

void Student::setName(string s)
{
    name = s;
}

void Student::setRegistration(string s)
{
    registration = s;
}

void Student::setCred(int c)
{
    cred = c;
}

string Student::getName()
{
    return name;
}

string Student::getRegistration()
{
    return registration;
}

int Student::getCred()
{
    return cred;
}



