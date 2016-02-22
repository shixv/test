#ifndef _stack_h
#define _stack_h
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ElemType int
typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S);
Status DestroyStack(SqStack *S);
Status ClearStack(SqStack *S);
Status StackEmpty(SqStack *S);
int StackLength(SqStack *S);
Status GetTop(SqStack *S,ElemType *e);
Status Push(SqStack *S,ElemType e);
Status Pop(SqStack *S,ElemType *e);
Status StackTraverse(SqStack *S,Status(*visit)());

#endif
