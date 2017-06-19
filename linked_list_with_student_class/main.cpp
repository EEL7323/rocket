#include <iostream>
#include "list.h"
#include "student.h"


int main()
{
<<<<<<< Updated upstream
	std::string auxstr, str;
=======
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    volatile bool var;
>>>>>>> Stashed changes
	Student* bruno;
	List<Student*> test,jo;
	int i;
	
	cout << "Nome: ";
    cin >> auxstr;
    
	bruno = new Student();
<<<<<<< Updated upstream
    bruno->setName(auxstr);
    bruno->setRegistration("14101328");
  
	test.pushFinal(bruno);
	if(test.existElement(bruno)){ // existElement verifica se o aluno ta na lista
		cout<<"Lista com nego\n";
		str = test.retElement(bruno); // retElement retorna o nome do aluno obj
		cout << str;
		cout<<"\n";
		cout << "\Get cred from list: ";
		i = test.getRegCred("14101328"); // getRegCred retorna quantos cred um aluno obj tem
		cout << i;
		cout<<"\n";
		test.setRegCred("14101328",20);// setRegCred coloca cred p/ aluno obj
		cout<<"\n";
		cout << "\Get cred from list after set cred: ";
		i = test.getRegCred("14101328");
		cout << i;
		cout<<"\n";
		test.decreaseRegCred("14101328"); // decreaseRegCred faz cred-- p/ oaluno obj
		i = test.getRegCred("14101328");
		cout << i;
		cout<<"\n";
	}
	else cout<<"LISTA VAZIa";
=======
    bruno->setName("Bruno");
    bruno->setRegistration("5");
    bruno->setCred(10);
    test.pushFinal(bruno);
    var = test.existElement(bruno);

	while(1);

>>>>>>> Stashed changes
    return 0;       
};