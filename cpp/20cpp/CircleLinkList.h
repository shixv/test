#ifndef CIRCLELINKLIST_H
#define CIRCLELINKLIST_H

#include<stdio.h>
#include<stdlib.h>

//链表结点
typedef struct _CircleLinkNode{
	struct _CircleLinkNode* next;
}CircleLinkNode;

//链表结构体
typedef struct _CircleLinkList{
	CircleLinkNode header;  //头结点
	int length;
}CircleLinkList;

//定义回调函数
typedef void(*PRINTLINKNODE)(CircleLinkNode*);


//初始化链表
CircleLinkList* Init_CircleLinkList();
//插入数据
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);
//删除 根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos);
//删除 根据值删除(新增)
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data);
//获取长度
int Length_CircleLinkList(CircleLinkList* clist);
//根据值修改
void Modify_CircleLinkList(CircleLinkList* clist, CircleLinkNode* oldvalue, CircleLinkNode* newvalue);
//清空链表
void Clear_CircleLinkList(CircleLinkList* clist);
//根据位置返回数据
CircleLinkNode* GetByPos_CircleLinkList(CircleLinkList* clist,int pos);
//销毁
void Destroy_CircleLinkList(CircleLinkList* clist);
//打印
void Print_CircleLinkList(CircleLinkList* clist,PRINTLINKNODE print);


#endif
