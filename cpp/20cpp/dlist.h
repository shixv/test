#ifndef dlist_h
#define dlist_h

typedef struct _DoubleNode{
	void* data;
	struct _DoubleNode* prev;
	struct _DoubleNode* next;
}DoubleNode;

typedef struct _DoubleLinkList{
	DoubleNode* head;
	DoubleNode* rear;
	int length;
}DoubleLinkList;


DoubleLinkList* Init_DoubleLinkList()
{


void Insert_DoubleLinkList(DoubleLinkList* dist,int ps,void* data);

void Remove_DoubleLikenList(DoubleLinkList* dist,int pos);

void Print_DoubleLinkList(DoubleLinkList* dist, PRINTNODE print);

#endif
