#include <iostream>
#include "list.h"
#include "student.h"


int main()
{
	std::string auxstr, str;
	Student *bruno, *elco, *frata;
	List<Student*> test;
	int i;
	
//	cout << "Nome: ";
  //  cin >> auxstr;
    
	bruno = new Student();
   // bruno->setName(auxstr);
    bruno->setName("Bruno");
    bruno->setRegistration("14101328");
    test.pushFinal(bruno);
    
    elco = new Student();
    elco->setName("Elco");
    elco->setRegistration("14106067");
 	test.pushFinal(elco);
 	
	frata = new Student();
    frata->setName("Frata");
    frata->setRegistration("14200025");
 	test.pushFinal(frata);   
    
 	test.showAllElements();
		 
    int n = test.getPosition("14106067");
	cout << n;
	
	cout << "\n Deletando o elco\n";
	test.deleteStudent(elco);
	
 	test.showAllElements();
    
  /*
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
	*/
	
	
    return 0;       
};