#ifndef CIRCLELINKLIST_H
#define CIRCLELINKLIST_H

#include<stdio.h>
#include<stdlib.h>

//������
typedef struct _CircleLinkNode{
	struct _CircleLinkNode* next;
}CircleLinkNode;

//����ṹ��
typedef struct _CircleLinkList{
	CircleLinkNode header;  //ͷ���
	int length;
}CircleLinkList;

//����ص�����
typedef void(*PRINTLINKNODE)(CircleLinkNode*);


//��ʼ������
CircleLinkList* Init_CircleLinkList();
//��������
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);
//ɾ�� ����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos);
//ɾ�� ����ֵɾ��(����)
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data);
//��ȡ����
int Length_CircleLinkList(CircleLinkList* clist);
//����ֵ�޸�
void Modify_CircleLinkList(CircleLinkList* clist, CircleLinkNode* oldvalue, CircleLinkNode* newvalue);
//�������
void Clear_CircleLinkList(CircleLinkList* clist);
//����λ�÷�������
CircleLinkNode* GetByPos_CircleLinkList(CircleLinkList* clist,int pos);
//����
void Destroy_CircleLinkList(CircleLinkList* clist);
//��ӡ
void Print_CircleLinkList(CircleLinkList* clist,PRINTLINKNODE print);


#endif
