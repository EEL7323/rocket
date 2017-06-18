#ifndef _LIST_H_
#define _LIST_H_
#include <cstddef>

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
		bool existElement(T v)
		{
			Node<T>* c = head;
			while(c)
			{
				if(c->getValue() == v)
					return true;
				c = c->getNext();	
			}
			return false;
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
	
};

#endif
