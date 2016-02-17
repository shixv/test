#include <stdio.h>

int main(void)
{
	int arr[10]={1,2,2,3,3,3,3,3,3,3};
	int count=1;
	int pcount=0;
	for(int i=1;i<10;i++)
	{
		if(arr[i-1]==arr[i])
			count++;
		if(arr[i-1]>arr[i])
			return 0;
		if(arr[i-1]<arr[i])
		{
			if(pcount<count)
				pcount=count;
			count=1;
		}
	}
	printf("%d\n",count>pcount?count:pcount);
	return 0;
}
