#ifndef _aqlist_h
#define _aplist_h
#define LIST_INIT_SIZE
#define LISTINCREAMENT
#define ElemType int

typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

void InitList(SqList *);
void DestroyList(SqList *);
void ClearList(SqList *);
int ListEmpty(SqList);
int ListLength(SqList);
void GetElem(SqList,int,ElemType *);
int LocateElem(SqList,ElemType,int(*)(ElemType,ElemType));
void PriorElem(SqList,ElemType,ElemType *);
void NextElem(SqList,ElemType,ElemType *);
void ListInsert(SqList *,int,ElemType);
void ListDelete(SqList *,int,ElemType *);
void ListTraverse(SqList,int(*)(void *,void *));
#endif
