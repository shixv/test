#include <stdio.h>
#include <string.h>

int main(void)
{
	int arr[6][6];
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
		{
			arr[i][j]=-1;
			if((i==0||i==5)||(i==j)||((i+j)==5))
				arr[i][j]=1;
		}
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			printf("%2d",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

