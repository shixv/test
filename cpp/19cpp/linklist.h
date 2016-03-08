#ifndef LINK_H
#define LINK_H

typedef struct _LinkNode{
	void* data;
	struct _LinkNode* next;
}LinkNode;

typedef struct _LinkList{
	LinkNode* head;
	int length;
}LinkList;

typedef void(*PRINTLINKNODE)(void*);
LinkList* Init_LinkList();
void Insert_LinkList(LinkList* list,int pos,void* data);
void Remove_LinkList(LinkList* list,int pos);
int Length_LinkList(LinkList* list);
int isEmpty_LinkList(LinkList* list);
void Clear_LinkList(LinkList* list);
void* Get_LinkList(LinkList* list,int pos);
void Destroy_LinkList(LinkList* list);
void Print_LinkList(LinkList* list,PRINTLINKNODE print);
#endif
