#include "stack.h"
#include <stdlib.h>

Status InitStack(SqStack *s)
{
	S=(SqStack *)malloc(sizeof(SqStack));
	S->base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S->base)exit(OVERFLOW);
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S,ElemType *e)
{
	if(S->top==S->base)return ERROR;
	*e=*(S->top-1);
	return OK;
}

Status Push(SqStack *S,ElemType e)
{
	if((S->top-S->base)>=S->stacksize)
	{
		S->base=(ElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!S->base)exit(OVERFLOW);

		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e;
	return OK;
}

Status Pop(SqStack *S,ElemType *e)
{
	if(S->top==S->base)return ERROR;
	*e=*S->top;
	free(S->top);
	--S->top;
	return OK;
}
