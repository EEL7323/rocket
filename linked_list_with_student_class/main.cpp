#include <msp430.h>
#include "list.h"
#include "student.h"


int main()
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

	Student* bruno;
	List<Student*> test;

	bruno = new Student();
    bruno->setName("Bruno");
    bruno->setRegistration("14101328");
    bruno->setCred(10);

	test.pushFinal(bruno);

	while(1);

    return 0;       
}
