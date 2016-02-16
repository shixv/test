#include <stdio.h>
#include <stdlib.h>

#define Filename "prime.dat"

int *CreateArray(int n)
{
	if(n<6)
		return NULL;
	FILE *p=fopen(Filename,"r");
	int ch=0;
	int count=0;
	while(fread(&ch,sizeof(int),1,p)==1)
		if(ch<=n)
			count++;
		else
			break;
	int *arr=malloc(sizeof(int)*(count+1));
	fseek(p,0,SEEK_SET);
	for(int i=0;i<count;i++)
	{
		fread(&ch,sizeof(int),1,p);
		arr[i]=ch;
	}
	arr[count]=0;
	return arr;
}
int Isinarray(int n,int *arr)
{
	int i=0;
	while(arr[i]!=0)
		if(arr[i++]==n)
			return 1;
	return 0;
}
int gdbh(int n,int *arr,int *a,int *b)
{
	int i=0;
	if(n%2==1)
	{
		*a=0;
		*b=0;
		return 0;
	}
	while(arr[i]!=0)
	{
		*a=arr[i];
		*b=n-arr[i++];
		if(Isinarray(*a,arr)&&Isinarray(*b,arr))
			return 1;
	}
	*a=0;
	*b=0;
	return 0;
}
int main(int argc,char *argv[])
{
	int n=atoi(argv[1]);
	if(n%2==1&&n>=6)
		return 0;
	int a,b;
	int *array=CreateArray(n);
	//	for(int i=6;i<=n;i+=2)
	//		if(gdbh(i,array,&a,&b))
	if(gdbh(n,array,&a,&b))
		printf("%d=%d+%d\n",n,a,b);
	free(array);
	return 0;
}
