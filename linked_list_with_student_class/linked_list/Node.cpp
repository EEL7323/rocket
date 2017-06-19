/*
   File Node.cpp

   Class Node

   Class Node stores Employees data for a linked list.
   
   This file has the implementation for the Node's interface.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include "Node.h"

// Constructor - initializes the node
//
Node::Node(int mat, string nom, float sal, int horas, float desc, char sta, int quad){
       matricula = mat;
       nome = nom;
       salario = sal;
       horasTrab = horas;
       desconto = desc;
       status = sta;
       quadrienio = quad;
       next = 0;
}

int Node::getMatricula(){
      return matricula;
}

string Node::getNome (){
       return nome;
}

float Node::getSalario (){
       return salario;
}

int Node::getHorasTrab (){
       return horasTrab;
}

float Node::getDescontos (){
       return desconto;
}

char Node::getStatus (){
       return status;
}

int Node::getQuadrienio (){
       return quadrienio;
}

// getNext returns a pointer to the next node in the linked list
//
Node* Node::getNext(){
     return next;
}

void Node::setMatricula(int novoMatricula){
   matricula = novoMatricula;
}

void Node::setNome(string novoNome){
   nome = novoNome;
}

void Node::setSalario (float novoSalario){
     salario = novoSalario;
}

void Node::setHorasTrab (int novoHorasTrab){
     horasTrab = novoHorasTrab;
}

void Node::setDescontos (float novoDesconto){
     desconto = novoDesconto;
}

void Node::setStatus (char novoStatus){
     status = novoStatus;
}

void Node::setQuadrienio (int novoQuadrienio){
     quadrienio = novoQuadrienio;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
void Node::setNext(Node* nxt){
       next = nxt;
}
      
float Node::calcSalarioBruto(){
      float novoSalario;
      
      if (status == 'e')
         novoSalario = 250.0;
      else
      {
          novoSalario = horasTrab * 15.0;
          novoSalario = ((novoSalario * 10.0) / 100.0) * quadrienio  + novoSalario;
      }
      
       return novoSalario;
}

float Node::calcSalarioLiq(){
      float novoSalario;
      
      if (status == 'e')
         novoSalario = 250.0;
      else
          novoSalario = calcSalarioBruto() - desconto;
      
       return novoSalario;
}
