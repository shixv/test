#include <stdio.h>

int main(void)
{
	int a[10]={2,33,5,356,1,2,3,4,4,9};
	int i,j,temp;
	for(i=9;i>0;i--)
		for(j=0;j<i;j++)
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	for(i=0;i<10;i++)
		printf("%d\t",a[i]);
	return 0;
}
