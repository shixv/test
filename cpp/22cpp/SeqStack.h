#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<stdlib.h>
#include<stdio.h>

#define MAXSIZE 128

//栈的结构体
typedef struct _SeqStack{
	void* data[MAXSIZE];
	int length;
}SeqStack;

//初始化
SeqStack* Init_SeqStack();
//入栈
void Push_SeqStack(SeqStack* stack,void* data);
//出栈
void Pop_SeqStack(SeqStack* stack);
//获得栈顶元素
void* Top_SeqStack(SeqStack* stack);
//获得栈大小
int Length_SeqStack(SeqStack* stack);
//清空栈
void Clear_SeqStack(SeqStack* stack);
//销毁栈
void Destroy_SeqStack(SeqStack** stack);

#endif
