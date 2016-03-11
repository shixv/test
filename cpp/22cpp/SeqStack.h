#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<stdlib.h>
#include<stdio.h>

#define MAXSIZE 128

//ջ�Ľṹ��
typedef struct _SeqStack{
	void* data[MAXSIZE];
	int length;
}SeqStack;

//��ʼ��
SeqStack* Init_SeqStack();
//��ջ
void Push_SeqStack(SeqStack* stack,void* data);
//��ջ
void Pop_SeqStack(SeqStack* stack);
//���ջ��Ԫ��
void* Top_SeqStack(SeqStack* stack);
//���ջ��С
int Length_SeqStack(SeqStack* stack);
//���ջ
void Clear_SeqStack(SeqStack* stack);
//����ջ
void Destroy_SeqStack(SeqStack** stack);

#endif
