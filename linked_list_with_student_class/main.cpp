#include <iostream>
#include "list.h"
#include "student.h"


int main()
{
	string auxstr;
	Student* bruno;
	List<Student*> test;
	
	bruno = new Student();
	cout << "Nome: ";
    cin >> auxstr;
    bruno->setName(auxstr);
    bruno->setRegistration("14101328");
    bruno->setCred(10);
    bruno->showAllinfo();
    
	test.pushFinal(bruno);
	test.showAllElements();

    return 0;       
}