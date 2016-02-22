#include "define.h"
#include "sqlist.h"
#include <stdlib.h>

void InitList(SqList *L)
{
	L=(SqList *)malloc(sizeof(SqList));
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem)exit(OVERFLOW);
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
	return OK;
}
void DestroyList(SqList *L)
{
	free(L->elem);
	free(L);
}
void ClearList(SqList *L)
{
	DestroyList(L);
	InitList(L);
}
int ListEmpty(SqList *L)
{
	if(L->length==0)
		return TRUE;
	else
		return FALSE;
}
int ListLength(SqList *L)
{
	return L->length;
}
ElemType GetElem(SqList *L,int i,ElemType *e)
{
	if(e!=NULL)
		if(L!=NULL&&i>=1&&i<=ListLength(L))
			*e=*(L->elem+i-1);
	return *(L->elem+i-1);
}
int LocateElem(SqList *L,ElemType e,int(*compare)(ElemType,ElemType))
{
	if(L!=NULL)
	{
		for(int i=0;i<ListLength(L);i++)
		{
			if(compare(e,GetElem(L,i,NULL)))
				return i;
		}
	}
	return 0;
}
int LocateElem(SqList *L,ElemType e,Status (*compare)(ElemType,ElemType))
{
	i=1;
	p=L->elem;
	while(i<=L->length&&!(*compare)(*p++,e))++i;
	if(i<L->length)return i;
	return 0;
}
void MergeList(SqList *La,SqList *Lb,SqList *c)
{
	ElemType *pa=La->elem;ElemType *pb=Lb.elem;
	SqList *Lc=(SqList *)malloc(sizeof(SqList));
	Lc->listsize=Lc->length=La->length+Lb->length;
	ElemType *pc=Lc->elem=(ElemType *)malloc(Lc->listsize*sizeof(ElemType));
	if(!Lc->elem)exit(OVERFLOW);
	ElemType *pa_last=La->elem+La->length-1;
	ElemType *pb_last=Lb->elem+Lb->length-1;
	while(pa<=pa_last&&pb<pb_last)
	{
		if(*pa<=*pb)*pc++=*pa++;
		else*pc++=*pb++;
	}
	while(pa<=pa_last)*pc++=*pa++;
	while(pb<=pb_last)*pc++=*pb++;
}
void PriorElem(SqList *L,ElemType cure,ElemType *pree)
{
	*pree=*(L->elem+LocateElem(L,cure,compare)-2);
}
void NextElem(SqList *L,ElemType cure,ElemType *nexte)
{
	*nexte=*(L->elem+LocateElem(L,cure,compare));
}
Status ListInsert(SqList *L,int i,ElemType e)
{
	if(i<1||i>L->length+1)return ERROR;
	if(L->length>=L->listsize)
	{
		newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREAMENT)*sizeof(ElemType));
		if(!newbase)exit(OVERFLOW);
		L->elem=newbase;
		L->listsize+=LISTINCREAMENT;
	}
	q=L->elem+i-1;
	for(p=L->elem+L->length-1;p>=q;--p)*(p+1)=*p;
	*q=e;
	++L->length;
	return OK;
}
Status ListDelete(SqList *L,int i,ElemType *e)
{
	if((i<1)||(i>L->length))return ERROR;
	p=L->elem+i-1;
	*e=*p;
	q=L->elem+L->length-1;
	for(++p;p<=q;++p)*(p-1)=*p;
	--L->length;
	return OK;
}
