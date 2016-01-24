#include <stdio.h>

int main(void)
{
	int n,i,k,j;
	printf("请输入一个数： \n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n-i;j++)printf(" ");
		for(k=1;k<=i*2-1;k++)printf("*");
		putchar('\n');
	}
	return 0;
}
			
