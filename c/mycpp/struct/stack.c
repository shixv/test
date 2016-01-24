#include "stack.h"


struct Node
{
	ElementType Element;
	PtrToNode Next;
};


int IsEmpty(Stack S)
{
	return S->Next==NULL;
}

Stack CreatStack(void)
{
	Stack S;
	S=malloc(sizeof(struct Node));
	if(S==NULL)return;
	S->Next=NULL;
	MakeEmpty(S);
	return S;
}

void MakeEmpty(Stack S)
{
	if(S==NULL)
		return;
	else
		while(!IsEmpty(S))
			Pop(S);
}

void Push(ElementType X,Stack S)
{
	PtrToNode TmpCell;
	TmpCell=malloc(sizeof(struct Node));
	if(TmpCell==NULL)return;
	else
	{
		TmpCell->Element=X;
		TmpCell->Next=S->Next;
		S->Next=TmpCell;
	}
}

ElementType Top(Stack S)
{
	if(!IsEmpty(S))
		return S->Next->Element;
	return 0;
}

void Pop(Stack S)
{
	PtrToNode FirstCell;
	if(IsEmpty(S))
		return;
	else
	{
		FirstCell=S->Next;
		S->Next=S->Next->Next;
		free(TmpCell);
	}
}


