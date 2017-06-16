#include "List.cpp"
#include "Student.h"
#include "Professor.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

  Student* s, s1;
  Professor* p;
  List ll1, ll2, ll3;

  string auxstr;
  int auxint;
  float auxfloat;


  for (int i = 0; i < 3; i++){
     s = new Student();
     cout << "Nome: ";
     cin >> auxstr;
     s->setName(auxstr);

     cout << "Curso: ";
     cin >> auxstr;
     s->setCourse(auxstr);

     cout << "Matricula: ";
     cin >> auxint;
     s->setRegistration(auxint);

     cout << "Nota final: ";
     cin >> auxfloat;
     s->setGrade(auxfloat);

     ll1.insertBeforeFirst(s);
  }
  
  cout << "Listando todos:" << endl;
  ll1.listar();
  cout << endl << "Fim da listagem!" << endl;

  // Le o primeiro da fila de estudantes
  s = (Student*)ll1.readFirst();
  cout << "Mostra primeiro: " << s->getName() << endl;
  // Remove o primeiro da fila de estudantes
  s = (Student*)ll1.removeFirst();
  cout << "Remove primeiro: " <<  s->getName() << endl;
  // Le o segundo da fila de estudantes (ex-primeiro)
  s = (Student*)ll1.readFirst();
  cout <<  "Mostra segundo: " << s->getName() << endl;
  s = (Student*)ll1.removeFirst();
  cout <<  "Remove segundo: " << s->getName() << endl;


  for (int i = 0; i < 2; i++){
     p = new Professor();
     cout << "Nome: ";
     cin >> auxstr;
     p->setName(auxstr);

     cout << "Curso: ";
     cin >> auxstr;
     p->setCourse(auxstr);

     ll2.insertBeforeFirst(p);
  }

  p = (Professor*)ll2.removeFirst();
  cout <<  "Remove prof: " << p->getName() << endl;
  p = (Professor*)ll2.removeFirst();
  cout <<  "Remove prof: " << p->getName() << endl;

}