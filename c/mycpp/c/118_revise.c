#include <stdio.h>

int main(void)
{
	int arr[]={1,2,3,4,5,6,7,8,9,10,2,3,4,5};
	int temp,i,n;
	n=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<(n/2);i++)
	{
		temp=arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i]=temp;
	}
	for(i=0;i<n;i++)printf("%d\t",arr[i]);
	putchar('\n');
	return 0;
}
