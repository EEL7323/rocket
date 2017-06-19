/*
   File Student.h

   Class Student

   Defines a student

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include <string>

class Student {

    string name;
    string course;
    int registration;
    float grade;

  public:
    Student();
    ~Student();
    void setName(string);
    void setCourse(string);
    void setRegistration(int);
    void setGrade(float);
    string getName();
    string getCourse();
    int getRegistration();
    float getGrade();
};

Student::Student(){
   name = "";
   course = "";
   registration = 0;
   grade = 0.0;
}

Student::~Student(){
}


void Student::setName(string s){
   name = s;
}

void Student::setCourse(string c){
   course = c;
}

void Student::setRegistration(int r){
   registration = r;
}

void Student::setGrade(float g){
   grade = g;
}

string Student::getName(){
   return name;
}

string  Student::getCourse(){
   return course;
}

int  Student::getRegistration(){
   return registration;
}

float  Student::getGrade(){
   return grade;
}
