#include <stdio.h>
#define MAX 10

int main(void)
{
	int arr[MAX]={12,32,34,54,576,34,346,68,132,3546};
	int max=0,i;
	for(i=0;i<MAX;i++)arr[i]>=max?max=arr[i]:max;
	printf("\n%d",max);
	return 0;
}
		
	
