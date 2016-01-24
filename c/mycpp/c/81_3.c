#include <stdio.h>
#define SIZE 10

int arr_max(int *ar,int n);
int main(void)
{
	int array[SIZE]={12,222,31,4,35,46,57,678,9,19};
	printf("The max number of array is %d.\n",arr_max(array,SIZE));
	return 0;
}
int arr_max(int *ar,int n)
{
	int temp;
	temp=ar[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(temp<ar[i])temp=ar[i];
	}
	return temp;
}
		
	
