#include <stdio.h>

void binary_search(int key,int a[],int n)
{
	int low,high,mid,count=0,count=1;
	low=0;
	high=n-1;
	while(low<high)
	{
		count++;
		mid=(low+high)/2;
		if(key<a[mid])
			high=mid-1;
		else if(key>a[mid])
			low=mid+1;
		else if(key==a[mid])
		{
			printf("%d  ci  a[%d]=%d",count,mid,key);
			count1++;
			break;
		}
	}
	if(count1==0)
		printf("failure.\n");
}

int main(void)
{
	int i,key,a[100],n;
	printf("please"
}
