#include <cstring>
#ifndef _node_h
#define _node_h
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
#endif
