#include <stdio.h>

int main(void)
{
	int arr2[3][4]={
		{3,4,5,6},
		{1,3,5,7},
		{5,6,7,8}
	};
	int r=sizeof(arr2)/sizeof(arr2[0]);
	int c=sizeof(arr2[0])/sizeof(arr2[0][0]);
	for(r=0;r<3;r++)
	{
		int sum =0;
		for(c=0;c<4;c++)
		{
			sum+=arr2[r][c];
		}
		printf("the %d row average = %d\n",r,sum/4);
	}
	for(c=0;c<4;c++)
	{
		int sum =0;
		for(r=0;r<3;r++)
		{
			sum+=arr2[r][c];
		}
		printf("the %d col average = %d\n",c,sum/3);
	}
	return 0;
}
