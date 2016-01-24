#include "stacka.h"
#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

Stack CreatStack(int MaxElements)
{
	Stack S;
	if(MaxElements<MinStackSize)
		return NULL;
	S=malloc(sizeof(struct StackRecord));
	if(S==NULL)return;
	S->Array=malloc(sizeof(ElementType)*MaxElements);
	if(S->Array==NULL)return;
	S->Capacity=MaxElements;
	MakeEmpty(S);
	return 0;
}

void DisposeStack(Stack S)
{
	if(S!=NULL)
	{
		free(S->Array);
		free(S);
	}
}

int IsEmpty(Stack S)
{
	return S->TopOfStack==EmptyTOS;
}

void MakeEmpty(Stack S)
{
	S->TopOfStack=EmptyTOS;
}

void Push(ElementType X,Stack S)
{
	if(IsFull(S))
		return;
	else
		S->Array[++S->TopOfStack]=X;
}

ElementType Top(Stack S)
{
	if(!IsEmpty(S))
		return S->Array[S->TopOfStack];
	return 0;
}

void Pop(Stack S)
{
	if(IsEmpty(S))
		return;
	else
		S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
	if(!IsEmpty(S))
		return S->Array[S->TopOfStack--];
	return 0;
}
