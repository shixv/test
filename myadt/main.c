#include <stdio.h>
#include "mystack.h"
void conversion(void)
{
	Stack *s=NULL;
	int n=0;
	InitStack(&s);
	scanf("%d",&n);
	while(n)
	{
		Push(s,n%8);
		n/=8;
	}
	while(!IsEmpty(s))
	{
		Pop(s,&n);
		printf("%d",n);
	}
	printf("\n");
	DestroyStack(s);
}
/*
void LineEdit()
{
	Stack *s=NULL;
	InitStack(&s);
	char ch=getchar();
	while(ch!=EOF){
		while(ch!=EOF&&ch!='\n'){
			switch(ch){
				case '#':Pop(s,&ch);
				case '@':ClearStack(s);
				default:Push(s,ch);
			}
			ch=getchar();
		}
		ClearStack(s);
		if(ch!=EOF)ch=getchar();
	}
	DestroyStack(s);
}
*/
int main(void)
{
//	printf("%d\n",MAX(10,1,1,1,2));
// printf("%d,%d\n",floor(2.01),ceil(2.01));
	conversion();	
//	LineEdit();
//	Stack *s=NULL;
//	InitStack(&s);
//	printf("%d\n",s->top->data);
//	Push(s,12);

	return 0;
}
