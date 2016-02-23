#include "node.h"
template<class ElemType>
class Queue
{
	private:
		Node<ElemType> *front;
		Node<ElemType> *rear;
		int length;
		int maxlength;
	public:
		Queue(int maxlength=10)
		{
			front=rear=NULL;
			length=0;
			this->maxlength=maxlength;
		}
		~Queue()
		{
			Node<ElemType> *tmp=NULL;
			while(front!=rear)
			{
				tmp=front;
				front=front->next;
				delete tmp;
			}
			if(front!=NULL)
				delete front;
		}
		int getlength()
		{
			return length;
		}
		bool enqueue(ElemType &e)
		{
			if(length==maxlength)
				return false;
			Node<ElemType> *tmp=new Node<ElemType>(e,NULL);
			if(front==NULL&&front==rear)
			{
				front=rear=tmp;
				return true;
			}
			rear->next=tmp;
			rear=tmp;
			length++;
			return true;
		}
		bool dequeue(ElemType &e)
		{
			if(front==NULL)
				return false;
			e=*(front->data);
			Node<ElemType> *tmp=NULL;
			tmp=front;
			front=front->next;
			if(front==NULL)
				rear=NULL;
			delete tmp;
			length--;
			return true;
		}
};

