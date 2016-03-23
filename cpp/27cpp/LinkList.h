#ifndef LINKLIST_H
#define LINKLIST_H
#include<stdio.h>
#include<stdlib.h>
typedef struct _LinkNode
{
	void* data;
	struct _LinkNode* next;
}LinkNode;
typedef struct _LinkList
{
	LinkNode* head;
	LinkNode* tail;
	int length;
}LinkList;
typedef void(*PRINTNODE)(void*);
//链表初始化
LinkList* Init_LinkList();
//插入数据
void* Insert_LinkList(LinkList* list,int pos, void* data);
//删除指定位置数据
void DeleteByPos_LinkList(LinkList* list, int pos);
//获得链表长度
int Length_LinkList(LinkList* list);
//判断是否为空
int IsEmpty_LinkList(LinkList* list);
//清空链表
void Clear_LinkList(LinkList* list);
//获得指定位置的数据
void* GetDataByPos_LinkList(LinkList* list, int pos);
//销毁链表
void Destroy_LinkList(LinkList* list);
//打印函数
void Print_LinkList(LinkList* list, PRINTNODE print);
#endif
