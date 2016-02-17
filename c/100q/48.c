#include <stdio.h>
#include <stdlib.h>

int **fillarr(int n);
int main(void)
{
	int **arr;
	int n=19;
	arr=fillarr(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}
	return 0;
}
int **fillarr(int n)
{
	int **arr=(int **)malloc(sizeof(int *)*n);
	for(int i=0;i<n;i++)
		arr[i]=(int *)malloc(sizeof(int)*n);

	for(int i=0;i<n/2;i++)
	{
		for(int j=i;j<n-i;j++)
			for(int k=i;k<n-i;k++)
				arr[j][k]=i+1;
	}
	if(n%2==1)
		arr[n/2][n/2]=n/2+1;
	return arr;
}
