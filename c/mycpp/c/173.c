#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000

int main(void)
{
	int A[SIZE]={
		0
	};
	int randn=rand()%SIZE+1;
	srand((unsigned int)time(0));
	for(int j=0;j<SIZE;j++)
	{
		for(int i=0;i<j;i++)
			if(A[i]==randn)
			{
				randn=rand()%SIZE+1;
				i=-1;
			}
		A[j]=randn;
	}
	for(int i=0;i<SIZE;i++)
		printf("%d,",A[i]);
}
