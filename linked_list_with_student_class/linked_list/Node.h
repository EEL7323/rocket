/*
   File Node.h

   Class Node

   Class Node stores Employees data for a linked list.
   
   This file has the Node's interface (header file).

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include "headers.h"

class Node {

      int matricula;
      string nome;
      float salario;
      int horasTrab;
      float desconto;
      char status;         // 'e' p/ estagiario; 'f' p/ funcionario
      int quadrienio;
      Node* next;

  public:
         
      Node(int mat, string nom, float sal, int horas, float dec, char sta, int quad);

      int getMatricula ();
      string getNome ();
      float getSalario ();
      int getHorasTrab ();
      float getDescontos ();
      char getStatus ();
      int getQuadrienio ();

      Node* getNext();
      
      void setMatricula (int);
      void setNome (string);
      void setSalario (float);
      void setHorasTrab (int);
      void setDescontos (float);
      void setStatus (char);
      void setQuadrienio (int);

      void setNext(Node* nxt);

      float calcSalarioBruto();
      float calcSalarioLiq();    
};
