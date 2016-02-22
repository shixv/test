#include <stdlib.h>
#define ElemType int
typedef struct node{
	ElemType data;
	struct node *next;
}Node;
typedef struct{
	Node *base;
	Node *top;
	int size;
}Stack;

int InitStack(Stack **s)
{
	*s=(Stack *)malloc(sizeof(Stack));
	(*s)->top=(*s)->base=(Node *)malloc(sizeof(Node));
	(*s)->top->data=0;
	(*s)->base->next=NULL;
	(*s)->size=0;
	return 0;
}
int DestroyStack(Stack *s)
{
	Node *tmp=NULL;
	while(s->top!=NULL)
	{
		tmp=s->top;
		s->top=s->top->next;
		free(tmp);
	}
	free(s);
	s=NULL;
	return 0;
}
int Push(Stack *s,ElemType e)
{
	Node *tmp=(Node *)malloc(sizeof(Node));
	tmp->data=e;
	tmp->next=s->top;
	s->top=tmp;
	s->size++;
	return 0;
}
int Pop(Stack *s,ElemType *e)
{
	if(s->top==s->base||s==NULL)
		return -1;
	*e=s->top->data;
	Node *tmp=s->top;
	s->top=s->top->next;
	free(tmp);
	s->size--;
	return 0;
}
int IsEmpty(Stack *s)
{
	return s->top==s->base;
}
int ClearStack(Stack *s)
{
	DestroyStack(s);
	InitStack(&s);
	return 0;
}
ElemType GetTop(Stack *s)
{
	return s->top->data;
}
