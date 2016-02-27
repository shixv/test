#include <stdio.h>
#include <stdlib.h>
#define FILENAM "prime.dat"

struct node 
{
	int n;
	struct node *next;
};

int isPrime(struct node *arr,int n)
{
	if(n<2)
		return 0;
	struct node *array=arr;
	while((array->next!=NULL)&&((array->n)*(array->n)<=n))
	{
		if(n%(array->n)==0)
			return 0;
		array=array->next;
	}
	return 1;
}
struct node *CreatePrimeArray(int n,int *count)
{
	if(n<2)
		return NULL;
	struct node *array=(struct node *)malloc(sizeof(struct node));
	array->n=2;
	array->next=NULL;
	struct node *p=array;
	int j=3;
	*count=1;
	while(j<=n)
	{
		if(isPrime(array,j))
		{
			p->next=(struct node *)malloc(sizeof(struct node));
			p=p->next;
			p->n=j;
			(*count)++;
			p->next=NULL;
		}
		j++;
	}
	return array;
}
void  freearr(struct node *p)
{
	while(p!=NULL)
	{
		free(p);
		p=p->next;
	}
	p=NULL;
}
void printarr(struct node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->n);
		p=p->next;
	}
	printf("\n");
}
void writefile(struct node *p)
{
	FILE *fp=fopen(FILENAM,"w");
	while(p!=NULL)
	{
		fwrite(&(p->n),sizeof(int),1,fp);
		p=p->next;
	}
	fclose(fp);
}
int main(int argc,char *argv[])
{
	if(argc<2)
		return 0;
	struct node *arr=NULL;
	int count=0;
	arr=CreatePrimeArray(atoi(argv[1]),&count);
//	writefile(arr);
	printf("%d\n",count);
	freearr(arr);
	return 0;
}
