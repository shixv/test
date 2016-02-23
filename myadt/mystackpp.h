#ifndef _mystackpp_h
#define _mystackpp_h
#include <cstring>
#include "node.h"
template<class ElemType>
class Stack
{
	private:
		Node<ElemType> *base;
		Node<ElemType> *top;
		int size;
	public:
		Stack()
		{
			top=base=new Node<ElemType>;
			size=0;
		}
		~Stack()
		{
			Node<ElemType> *tmp=NULL;
			while(top!=NULL)
			{
				tmp=top;
				top=top->next;
				delete tmp;
			}
		}
		bool push(const ElemType &e)
		{
			Node<ElemType> *tmp=new Node<ElemType>(e,top);
			top=tmp;
			size++;
			return true;
		}
		bool pop()
		{
			if(isempty())
				return false;
			Node<ElemType> *tmp=top;
			top=top->next;
			delete tmp;
			size--;
			return true;
		}
		bool gettop(ElemType *e)
		{
			*e=*(top->data);
			return true;
		}
		bool isempty()
		{
			return top==base;
		}
};
#endif
