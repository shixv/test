#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdlib.h>
#include<stdio.h>

#define LINKLIST_TRUE 1
#define LINKLIST_FAlSE 0


//��������
typedef struct _LinkNode{
	void* data; //������ָ��
	struct _LinkNode* next; //ָ����
}LinkNode;

//����Ľṹ��
typedef struct _LinkList{
	LinkNode* head; //ͷ���
	int length; //������
}LinkList;

//�����ӡ�ص�
typedef void(*PRINTLINKNODE)(void*);

//�����ʼ��
LinkList* Init_LinkList();
//��������
void Insert_LinkList(LinkList* list, int pos, void* data);
//ɾ������
void Remove_LinkList(LinkList* list,int pos);
//���������
int Length_LinkList(LinkList* list);
//�ж��Ƿ�Ϊ��
int IsEmpty_LinkList(LinkList* list);
//�������
void Clear_LinkList(LinkList* list);
//���ָ��λ�õ�����
void* Get_LinkList(LinkList* list,int pos);
//��������
void Destroy_LinkList(LinkList* list);
//��ӡ����
void Print_LinkList(LinkList* list, PRINTLINKNODE print);



#endif