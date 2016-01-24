#include "hashsep.h"
#include <stdlib.h>
#define MinTableSize 20


struct ListNode
{
	ElementType Element;
	Position Next;
};

typedef Position List;

struct HashTbl
{
	int TableSize;
	List *TheLists;
};

int IsPrime(int N)
{
	int i=1;
	int flag=1;
	while(i*i<=N)
		if(N%i==0)
		{
			flag=0;
			break;
		}
}

int NextPrime(int TableSize)
{
	while(!IsPrime(TableSize))
		TableSize++;
	return TableSize;
}

Index Hash(const char *Key,int TableSize)
{
	unsigned int HashVal;
	while(*Key!='\0')
		HashVal=(HashVal<<5)+*Key++;
	return HashVal%TableSize;
}

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;

	if(TableSize<MinTableSize)
		return NULL;
	H=malloc(sizeof(struct HashTbl));
	if(H==NULL)
		return NULL;
	H->TableSize=NextPrime(TableSize);
	H->TheLists=malloc(sizeof(List)*H->TableSize);
	if(H->TheLists==NULL)
		return NULL;
	for(i=0;i<H->TableSize;i++)
	{
		H->TheLists[i]=malloc(sizeof(struct ListNode));
		if(H->TheLists[i]==NULL)
			return NULL;
		else
			H->TheLists[i]->Next=NULL;
	}
	return H;
}

Position Find(ElementType Key,HashTable H)
{
	Position P;
	List L;

	L=H->TheLists[Hash(Key,TableSize)];
	P=L->Next;
	while(P!=NULL&&P->Element!=Key)    //strcmp;
		P=P->Next;
	return P;
}

void Insert(ElementType Key,HashTable H)
{
	Position Pos,NewCell;
	List L;
	Pos=Find(Key,H);
	if(Pos==NULL)
	{
		NewCell=malloc(sizeof(struct ListNode));
		if(NewCell==NULL)
			return;
		else
		{
			L=H->TheLists[Hash(Key,H->TableSize)];
			NewCell->Next=L->Next;
			NewCell->Element=Key;    //strcpy;
			L->Next=NewCell;
		}
	}
}


