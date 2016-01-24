#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int breakarray(int *array,int count);
int main(void)
{
	srand((unsigned int)time(0));
	int n;
	printf("input N:");
	scanf("%d",&n);
	int count=2*n;
	int *array=(int *)malloc(sizeof(int)*count);
	for(int i=0;i<count;i++)
	{
		array[i]=i+1;
		printf("%4d",array[i]);
	}
	printf("\n");
	int j,k;
	while(1){
		j=rand()%count;
		k=rand()%count;
		if(breakarray(array,count))
				break;
		if(array[j]==0||array[k]==0)
			continue;
		array[j]=abs(array[j]-array[k]);
		array[k]=0;
	}
	for(int i=0;i<2*n;i++)
		printf("%4d",array[i]);
	printf("\n");
	return 0;
}

int breakarray(int *array,int count)
{
	int j=0;
	for(int i=0;i<count;i++)
	{
		if(array[i]!=0)
		{
			j++;
		}
	}
	if(j==1)
		return 1;
	return 0;
}

	
