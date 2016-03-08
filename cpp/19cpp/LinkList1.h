#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdlib.h>
#include<stdio.h>

//������
typedef struct _LinkNode{
	struct _LinkNode* next;
}LinkNode;

//����ṹ��
typedef struct _LinkList{
	LinkNode header;
	int length;
}LinkList;

//�ص���ӡ
typedef void(*PRINTNODE)(LinkNode*);

//��ʼ������
LinkList* Init_LinkList();
//�������
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);
//ɾ������
void Remove_LinkList(LinkList* list, int pos);
//�������
void Clear_LinkList(LinkList* list);
//��������
void Destroy_LinkList(LinkList* list);
//��ӡ����
void Print_LinkList(LinkList* list, PRINTNODE print);



#endif