#include "tableadt.h"
#include <stdlib.h>

struct Node
{
	ElementType Element;
	Position Next;
};

int IsEmpty(List L)
{
	return L->Next==NULL;
}

int IsLast(Position P,List L)
{
	return P->Next==NULL;
}

Position Find(ElementType X,List L)
{ 
	Position P;
	P=L->Next;
	while(P!=NULL&&P->Element!=X)
		P=P->Next;
	return P;
}

Position FindPrevious(ElementType X,List L)
{
	Position P;
	P=L;
	while(P->Next!=NULL&&P->Next->Element!=X)
		P=P->Next;
	return P;
}

void Delete(ElementType X,List L)
{
	Position P,TmpCell;
	P=FindPrevious(X,L);
	if(!IsLast(P,L))
	{
		TmpCell=P->Next;
		P->Next=TmpCell->Next;
		free(TmpCell);
	}
}

void Insert(ElementType X,List L,Position P)
{
	Position TmpCell;
	TmpCell=malloc(sizeof(struct Node));
	if(TmpCell==NULL)
		return;
	TmpCell->Element=X;
	TmpCell->Next=P->Next;
	P->Next=TmpCell;
}

void DeleteList(List L)
{
	Position P,Tmp;
	P=L->Next;
	L->Next=NULL;
	while(P!=NULL)
	{
		Tmp=P->Next;
		free(p);
		P=Tmp;
	}
}

Position Header(List L)
{
	return L;
}

Position First(List L)
{
	return L->Next;
}

Position Advance(Position P)
{
	return P->Next;
}

ElementType Retrieve(Position P)
{
	return P->Element;
}

List MakeEmpty(List L)
{

}
