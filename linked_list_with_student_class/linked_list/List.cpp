
#include "List.h"
#include <iostream>

using namespace std;

List::List() {
   head = 0;
}

List::~List() {
  Node* cursor = head;
  while(head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}

void List::insertBeforeFirst(void* dat) {
  head = new Node(dat, head);
}

void List::insertAfterLast(void* dat) {
  Node* p = head;
  Node* q = head;

  if (head == 0)
     head = new Node(dat,head);
  else {
     while (q != 0) {
        p = q;
        q = p->getNext();
     }
     p->setNext(new Node(dat,0));
  }
}

void* List::readFirst() {
   return head->getData(); 
}

void* List::removeFirst() {
  void* retval = 0;
  if (head != 0){
     cout << "Removendo: " << head << endl;
     cout << "e fica:" << head->getData() << endl;
     retval = head->getData();
     Node* oldHead = head;
     head = head->getNext();
     delete oldHead;
  }
  return retval;
}

/* The next method works for a list of integers
   (void* data is a pointer to an int)

   Just remove the comments, if this is the case,
   and add the method definition in the class header
*/
/*
void List::insertionSort(int value) {
  Link* p = head;
  Link* q = head;

  if (head == 0)
  {
     head = new Link(new int(value),head);
	 int* i;
	 i = (int*)head->getData();
  }
  else
  {
	  int* pint;
	  int auxint;
	  pint = (int*)q->getData();
	  auxint = *pint;
	  while ((q != 0) && (auxint < value))
	  {
		  p = q;
		  q = p->getNext();
		  if (q != 0)
		  {
			pint = (int*)q->getData();
			auxint = *pint;
		  }
	  }
	  if (p == q)
		  head = new Node(new int(value),head);
	  else
			p->setNext(new Node(new int(value),q)_;
  }
}
*/

void* List::removeNode(void* dat) {
  Node* p = head;
  Node* q = head;
  void* result;

  if (head == 0)
     result = 0;
  else {
	  while ((q != 0) && (q->getData() != dat)){  // Error!! the addresses will always be different!
		  p = q;
		  q = p->getNext();
	  }
	  if (q != 0) {
		  if (q == head){	// it is the first node
			  result = q->getData();
			  head = q->getNext();
			  delete q;
		  }
		  else{				// the node is in the middle
			  result = q->getData();
			  p->setNext(q->getNext());
			  delete q;
		  }
	  }
	  else
		  result = 0;		// node not found!
  }

  return result;
}

void List::listar() {
  Node* aux = head;
  while (aux != 0){
     cout << aux << endl;
     aux = aux->getNext();
  }
}