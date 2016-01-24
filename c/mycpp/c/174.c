//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000
int main(void)
{
	int flag[SIZE+1]={0};
	int A[SIZE]={0};
	srand((unsigned int)time(0));
	int randn=rand()%SIZE+1;
	for(int i=0;i<SIZE;i++)
	{
		while(flag[randn]!=0)randn=rand()%SIZE+1;
		A[i]=randn;
		flag[randn]=1;
	}
//	for(int i=0;i<SIZE;i++)
//		printf("%d,",A[i]);	
	return 0;
}
