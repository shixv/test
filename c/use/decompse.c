//质因数分解   int类型下最大值为2^32-1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAM "prime.dat"      //素数列表文件

int *decompose(int n,int *parr,int plen);
void printdarr(int *darr,int *parr);
int *readfile(char *filename,int *n);
int main(int argc,char *argv[])
{
	int n=0;
	int *parray=readfile(FILENAM,&n);
	int *darray=decompose(atoi(argv[1]),parray,n);
	printdarr(darray,parray);
	return 0;	
}
int *decompose(int n,int *parr,int plen)
{
	int *darr=(int *)malloc((plen+1)*sizeof(int));
	memset(darr,0,plen*sizeof(int));
	int i=0;
	while(n>1)
	{
		if(n%parr[i]==0)
		{
			n/=parr[i];
			darr[i]++;
			continue;
		}
		else
		{
			i++;
		}
	}
	i++;
	darr[i]=-1;
	return darr;
}
void printdarr(int *darr,int *parr)
{
	int flag=0;
	if(darr[0]==0)
	{
		flag=1;
	}
	else if(darr[0]==1)
	{
		printf("%d",parr[0]);
	}
	else
	{
		printf("(%d^%d)",parr[0],darr[0]);
	}
	for(int i=1;i;i++)
	{
		if(darr[i]==-1)
			break;
		if(darr[i]==0)
		{
		}
		else if(darr[i]==1)
		{
			if(flag)
				printf("%d",parr[i]);
			else
				printf("*%d",parr[i]);
			flag=0;
		}
		else
		{
			if(flag)
				printf("(%d^%d)",parr[i],darr[i]);
			else
				printf("*(%d^%d)",parr[i],darr[i]);
			flag=0;
		}
	}
	printf("\n");
	free(darr);
	free(parr);
}
int *readfile(char *filename,int *n)
{
	FILE *p=fopen(filename,"r");
	(*n)=0;
	int d;
	while(fread(&d,sizeof(int),1,p)!=0)(*n)++;
	fseek(p,0,SEEK_SET);
	int *parr=(int *)malloc(sizeof(int)*(*n));
	fread(parr,sizeof(int),*n,p);
	fclose(p);
	return parr;
}
