#include <stdio.h>

int main(void)
{
	int i,j,t;
	int a[]={
		1,9,8,7,6,5,4,3,2,1,0
	};
	for(i=1;i<=9;i++)
		for(j=i+1;j<=10;j++)
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	putchar('\n');
	return 0;
}
