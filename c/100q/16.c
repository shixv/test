#include <stdio.h>

int main(void)
{
	 int arr[6][6];
	 arr[0][0]=1;
	 arr[0][1]=2;
	 for(int i=2;i<6;i++)
		 arr[0][i]=arr[0][i-1]+arr[0][i-2];
	 for(int i=1;i<6;i++)
	 {
		 arr[i][0]=1;
		 for(int j=1;j<6;j++)
			 arr[i][j]=arr[i][j-1]+arr[i-1][j-1]+arr[i-1][j];
	 }
	 for(int i=0;i<6;i++)
	 {
		 for(int j=0;j<6;j++)
			 printf("%d\t",arr[i][j]);
		 printf("\n");
	 }
	 return 0;
}
