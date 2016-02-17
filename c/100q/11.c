#include <stdio.h>

int main(void)
{
	int arr[5][5];
	for(int i=0;i<5;i++)
		for(int j=0;j<2;j++)
		{
			if(arr[i][j]!=arr[i][4-j])
			{
				printf("not\n");
				return 0;
			}
			continue;
		}
	printf("yes\n");
}
