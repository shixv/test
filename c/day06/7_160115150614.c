#include <stdio.h>
#include <stdlib.h>
#define HEHE 1024*1024
typedef struct sta
{
	char c[HEHE];
	struct sta *s;
}st;
int main(void)
{
	st *head=(st *)malloc(sizeof(st));
	head->s=NULL;
	st *tmp=head;
	st *p=NULL;
	while(1)
	{
		p=(st *)malloc(sizeof(st));
		tmp->s=p;
		tmp=p;
	}
	return 0;
}
