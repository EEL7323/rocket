/*
   File llist.h

   Header file for class list

   Class list is definition for a linked list, with the following operations:

   1. Initialize a list to the empty list.
   2. Free the nodes of a list.
   3. Determine whether a list is empty.
   4. (NOT YET!) Add a node with a given value into the list following
      the first node with another given value.
   5. Add a node with a given value to the front of the list.
   6. Add a node with a given value to the end of the list.
   7. Delete the first node from the list. (pop operator).

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include "Node.h"

class List {

  Node* head;

public:
  List();
  ~List();
  void insertBeforeFirst(void* dat);
  void insertAfterLast(void* dat);
  void* readFirst();
  void* removeFirst();
//  void insertionSort(int value);
  void* removeNode(void* dat);
  void listar();
};
