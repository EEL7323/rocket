#include <iostream>
#include "list.h"



int main()
{
	List<string> test;

	test.pushFinal("BrunoGriep");
	test.pushFinal("Frata");
	test.pushFinal("Elco");
	test.pushFront("Bruno Eiterer");
	
	test.showAllElements();
	if(test.emptyList())
		cout << "\n Lista vazia \n";
	else 
		cout << "\n Lista NAO vazia \n";
	test.showAllElements();
	
	cout << "tamanho da lista \n" << test.listSize() << endl;
	
    return 0;       
}