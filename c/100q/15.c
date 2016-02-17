#include <stdio.h>

static int arr[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main(void)
{
	int i,j;
	int sum=0;
	scanf("%d,%d",&i,&j);
	for(int k=0;k<i-1;k++)
		sum+=arr[k];
	sum+=j;
	printf("%d\n",sum);
	return 0;
}
