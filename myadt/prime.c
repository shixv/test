#include <stdio.h>
#include <stdlib.h>
#include "mystack.h"
#define FILENAM "prime.dat"
int isPrime(Stack *arr,int n)
{
	if(n<2)
		return 0;
	Stack *array=arr;
	while((!IsEmpty(array))&&(GetTop(array)*GetTop(array)<=n))
	{
		if(n%(GetTop(arr))==0)
			return 0;
		array->top=array->top->next;
	}
	return 1;
}
Stack *CreatePrimeArray(int n)
{
	if(n<2)
		return NULL;
	Stack *array=NULL;
	InitStack(&array);
	Push(array,2);
	int j=3;
	while(j<=n)
	{
		if(isPrime(array,j))
		{
			Push(array,j);
		}
		j++;
	}
	return array;
}
void  freearr(Stack *p)
{
	DestroyStack(p);
}
void printarr(Stack *p)
{
	while(!IsEmpty(p))
	{
		int n;
		Pop(p,&n);
		printf("%d ",n);
	}
	printf("\n");
}
int main(int argc,char *argv[])
{
	if(argc<2)
		return 0;
	Stack *arr=NULL;
	arr=CreatePrimeArray(atoi(argv[1]));
	printarr(arr);
	freearr(arr);
	return 0;
}
