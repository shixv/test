#include <stdio.h>
#include "mystack.h"
int evaluateExp(char *s);
int test(char *s);
int main(int argc,char *argv[])
{
//	printf("%d\n",evaluateExp(argv[1]));
	printf(test(argv[1]));
	return 0;
}
int evaluateExp(char *s)
{
	return 0;
}
int test(char *s)
{
	Stack *tmp=NULL;
	InitStack(&tmp);
	int len=strlen(s);
	char ch;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(')
		{
			Push(tmp,s[i]);
