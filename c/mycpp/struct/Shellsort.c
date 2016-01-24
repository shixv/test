#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ElementType int
#define ARRSIZE 100

void Shellsort(ElementType A[],int N)
{
	int i,j,Increment;
	ElementType Tmp;

	start=clock();
	for(Increment=N/2;Increment>0;Increment/=2)
		for(i=Increment;i<N;i++)
		{
			Tmp=A[i];
			for(j=i;j>=Increment;j-=Increment)
				if(Tmp<A[j-Increment])
					A[j]=A[j-Increment];
				else
					break;
			A[j]=Tmp;
		}
}

void initrandafile(int n)
{
	FILE *p=fopen("randmarr.dat","w");
	srand((unsigned int)time(0));
	ElementType randn;
	for(int i=0;i<n;i++)
	{
		randn=(ElementType)(rand()%10000);
		fwrite(&randn,sizeof(ElementType),1,p);
	}
	fclose(p);
}

ElementType *readrandafile(int n)
{
	ElementType *arr=malloc(sizeof(ElementType)*n);
	FILE *p=fopen("randmarr.dat","r");
	for(int i=0;i<n;i++)
	{
		fread(arr+i,sizeof(ElementType),1,p);
	}
	fclose(p);
	return arr;
}

void writerandafile(ElementType *A,int n)
{
	FILE *p=fopen("randmarr.dat","w");
	for(int i=0;i<n;i++)
	{
		fwrite(A+i,sizeof(ElementType),1,p);
	}
	fclose(p);
}

void printrandafile(int n)
{
	FILE *p=fopen("randmarr.dat","r");
	ElementType m;
	for(int i=0;i<n;i++)
	{
		if(i%10==0)
			printf("\n");
		fread(&m,sizeof(ElementType),1,p);
		printf("%d\t",m);
	}
	printf("\n--------------------------\n");
	fclose(p);
}

clock_t tick(p(ElementType,int)
int main(void)
{
	initrandafile(ARRSIZE);
	printrandafile(ARRSIZE);
	int *arr=readrandafile(ARRSIZE);

//	Shellsort(arr,ARRSIZE);

	writerandafile(arr,ARRSIZE);
	printrandafile(ARRSIZE);
	return 0;
}
