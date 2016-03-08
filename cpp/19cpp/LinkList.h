#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdlib.h>
#include<stdio.h>

#define LINKLIST_TRUE 1
#define LINKLIST_FAlSE 0


//结点的类型
typedef struct _LinkNode{
	void* data; //无类型指针
	struct _LinkNode* next; //指针域
}LinkNode;

//链表的结构体
typedef struct _LinkList{
	LinkNode* head; //头结点
	int length; //链表长度
}LinkList;

//定义打印回调
typedef void(*PRINTLINKNODE)(void*);

//链表初始化
LinkList* Init_LinkList();
//插入数据
void Insert_LinkList(LinkList* list, int pos, void* data);
//删除数据
void Remove_LinkList(LinkList* list,int pos);
//获得链表长度
int Length_LinkList(LinkList* list);
//判断是否为空
int IsEmpty_LinkList(LinkList* list);
//清空链表
void Clear_LinkList(LinkList* list);
//获得指定位置的数据
void* Get_LinkList(LinkList* list,int pos);
//销毁链表
void Destroy_LinkList(LinkList* list);
//打印函数
void Print_LinkList(LinkList* list, PRINTLINKNODE print);



#endif