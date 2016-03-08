#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdlib.h>
#include<stdio.h>

//链表结点
typedef struct _LinkNode{
	struct _LinkNode* next;
}LinkNode;

//链表结构体
typedef struct _LinkList{
	LinkNode header;
	int length;
}LinkList;

//回调打印
typedef void(*PRINTNODE)(LinkNode*);

//初始化链表
LinkList* Init_LinkList();
//插入操作
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);
//删除操作
void Remove_LinkList(LinkList* list, int pos);
//清空链表
void Clear_LinkList(LinkList* list);
//销毁链表
void Destroy_LinkList(LinkList* list);
//打印链表
void Print_LinkList(LinkList* list, PRINTNODE print);



#endif