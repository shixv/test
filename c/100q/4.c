#include <stdio.h>

int main(void)
{
	int arr[]={1,2,3,4,5,6,7,8,9,10,0};
	
	int sum1=0;
	int count1=0;
	int sum2=0;
	int count2=0;
	int i=0;
	while(arr[i]!=0)
	{
		if(arr[i]%2)
		{
			sum1+=arr[i];
			count1++;
		}
		else
		{
			sum2+=arr[i];
			count2++;
		}
		i++;
	}
	printf("count1=%d,sum1=%d,count2=%d,sum2=%d\n",count1,sum1,count2,sum2);
	return 0;
}
