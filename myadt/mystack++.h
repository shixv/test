#include <cstring>
template<class ElemType> 
class Node
{
	private:
	public:
		ElemType *data;
		Node *next;
		Node()
		{
			data=new ElemType;
			next=NULL;
		}
		Node(const Node &node)
		{
			data=new ElemType;
			memcpy(data,node->data,sizeof(ElemType));
			next=node->next;
		}
		Node(const ElemType &e,Node *next)
		{
			data=new ElemType;
			memcpy(data,&e,sizeof(ElemType));
			this->next=next;
		}
		~Node()
		{
			delete data;
			next=NULL;
		}

};
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
