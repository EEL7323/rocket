#ifndef _LIST_H_
#define _LIST_H_

//#include <iostream>
#include "student.h"
using namespace std;


template<class T>
class Node
{   
	private:
		T v;
		Node* next;
	public:
		Node(T v)
		{
			this->v = v;
			this->next = NULL;
		}
		
	T  getValue()
	{
		return v;
	}
	Node* getNext()
	{
		return next;
	}
	void setNext(Node* p)
	{
		next = p;
	}
};

template<class T>
class List
{
	private:
		Node<T>* head;			// first element
		Node<T>* tail;			// last element
	public:
		List()
		{
			head = NULL;
			tail = NULL;
		}
		List(T v)
		{
			head = new Node<T>(v);
			tail = head;
		}
		
		virtual ~List()
		{
			delete head;
		}
		
		void showAllElements()
		{
			cout << "\n Show all Elements \n";
			std::string str;
			Node<T>* c = head;
			if(emptyList())
				cout << "List is empty\n";
			else 
			{
				while (c)
				{
					str = c->getValue()->getRegistration();
					cout << str << "\n";
					c = c->getNext();
				}
				cout << endl;	
			}	
			
		}
			
		bool emptyList()			// show if list is empty
		{
			return (head == NULL);
		} 		
		
		void pushFront(T v)
		{
			Node<T>* new_node = new Node<T>(v);
			
			new_node->setNext(head);
			head = new_node;
			
		}
		void pushFinal(T v)
		{
			Node<T>* new_node = new Node<T>(v);
			if(emptyList())
			{
				head = new_node;
				tail = new_node;
			}
			else 
			{
				tail->setNext(new_node);
				tail = new_node;
			}		
		}
		
		int listSize()
		{
			if(emptyList())
				return 0;
			Node<T>* c = head;
			int size = 0;
			do
			{
				c  = c->getNext();
				size++;
			}
			while(c);
			return size;
		}
		
		void popBack()		// removes from the last
		{
			if(!emptyList())
			{
				// if list have 1 element
				if(head->getNext() == NULL)
					head = NULL;
				// if have 2 elements
				else if(head->getNext()->getNext() == NULL)
					head->setNext(NULL);
				// if list have more than 2 elements
				else 
				{
					Node<T>* previous_prev = head;
					Node<T>* prev = head->getNext();
					Node<T>* chain = head->getNext()->getNext();
					
					while(chain)
					{
						Node<T>* aux = prev;
						prev = chain;
						previous_prev = aux;
						chain = chain->getNext();
					}
					delete previous_prev->getNext();
					previous_prev->setNext(NULL);
					tail = previous_prev;
				}
			}
		}
		bool existElement(T v)
		{
			if(emptyList())
				return 0;
			Node<T>* c = head;
			while(c)
			{
				if(c->getValue() == v)
					return true;
				c = c->getNext();	
			}
			return false;
		}
		
		T retStudent(T v)
		{
			if(existElement(v))
				return v;
			else 
				return 0;	
		}
		
		std::string retElement(T v)  // return student's name 
		{	
			if(emptyList())
				return 0;
			Node<T>* c = head;
			while(c)
			{
				if(c->getValue() == v)
					return (c->getValue()->getName());
				c = c->getNext();	
			}
		//	return false;
		}
	
		
		int getPosition(std::string v)
		{	
			if(emptyList())
				return 0;
			std::string str;
			Node<T>* c = head;
			int n=0;
			while(c)
			{
				str = c->getValue()->getRegistration();
				n++;
				if(str==v)
					return n;
				c = c->getNext();
			}
		}
		
		T getElement(std::string v)
		{	
			if(emptyList())
				return 0;
			std::string str;
			Node<T>* c = head;
			while(c)
			{
				str = c->getValue()->getRegistration();
				if(str==v)
					return c->getValue();
				c = c->getNext();
			}
			return 0;
		}
		
		void deleteStudent(T val)
		{	
			if(emptyList())
				return;
			Node<T> *pPre = NULL, *pDel = NULL;
    
		    /* Check whether it is the head node?
		     if it is, delete and update the head node */
		    if (head->getValue() == val) {
		        /* point to the node to be deleted */
		        pDel = head;
		        /* update */
		        head = pDel->getNext();
		        delete pDel;
		        return;
		    }
		    pPre = head;
		    pDel = head->getNext();
		    
		    /* traverse the list and check the value of each node */
		    while (pDel != NULL) {
		        if (pDel->getValue() == val) {
		            /* Update the list */
		            pPre->setNext(pDel->getNext());
		            pPre = pDel;
		            /* If it is the last node, update the tail */
		            if (pDel == tail) {
		                tail = pPre;
		            }
		            delete pDel; /* Here only remove the first node with the given value */
		            break; /* break and return */
		        }
		        pPre = pDel;
		        pDel = pDel->getNext();
		    }
		}
		
		
		int getRegCred(std::string v)
		{	
			if(emptyList())
				return 0;
			std::string str;
			Node<T>* c = head;
			while(c)
			{
				str = c->getValue()->getRegistration();
				if(str==v)
					return (c->getValue()->getCred());
				c = c->getNext();
			}
			return 0;
		}
		void decreaseRegCred(std::string v)
		{	if(emptyList());
			else{
				std::string str;
				Node<T>* c = head;
				while(c)
				{
					str = c->getValue()->getRegistration();
					if(str==v)
						c->getValue()->decreaseCred();
					c = c->getNext();
				}
			}
		}
		void setRegCred(std::string v, int cred)
		{	
			if(emptyList())
				return;
			else{
				std::string str;
				Node<T>* c = head;
				while(c)
				{
					str = c->getValue()->getRegistration();
					if(str==v)
					{
						c->getValue()->setCred(cred);
						break;
					}
					c = c->getNext();
				}
			}
		}
		
		void changeRegInside(std::string v)
		{
			if(emptyList())
				return;
			else{
				std::string str;
				Node<T>* c = head;
				while(c)
				{
					str = c->getValue()->getRegistration();
					if(str==v)
					{
						c->getValue()->changeInside();
						break;
					}
					c = c->getNext();
				}
			}
		}
		
		bool getRegInside(std::string v)
		{
			if(emptyList())
				return;
			else{
				std::string str;
				Node<T>* c = head;
				while(c)
				{
					str = c->getValue()->getRegistration();
					if(str==v)
					{
						c->getValue()->getInside();
						break;
					}
					c = c->getNext();
				}
			}
		}
		
	
};

#endif
