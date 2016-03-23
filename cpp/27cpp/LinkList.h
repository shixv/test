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
//�����ʼ��
LinkList* Init_LinkList();
//��������
void* Insert_LinkList(LinkList* list,int pos, void* data);
//ɾ��ָ��λ������
void DeleteByPos_LinkList(LinkList* list, int pos);
//���������
int Length_LinkList(LinkList* list);
//�ж��Ƿ�Ϊ��
int IsEmpty_LinkList(LinkList* list);
//�������
void Clear_LinkList(LinkList* list);
//���ָ��λ�õ�����
void* GetDataByPos_LinkList(LinkList* list, int pos);
//��������
void Destroy_LinkList(LinkList* list);
//��ӡ����
void Print_LinkList(LinkList* list, PRINTNODE print);
#endif
