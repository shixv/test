#include <stdio.h>

int main(void)
{
	int a[3]={
		1,2,3
	};
	int b[3]={
		4,5,6
	};
	int *i=a;
	printf("*i= %d\n",*i);
	printf("a[0]= %d\n",a[0]);
	int (*p)[3]=&a;
	printf("*p= %d\n",*p);
	printf("b[0]= %d\n",*b);
	*p=b;
	printf("*i= %d\n",*i);
	printf("a[0]= %d\n",a[0]);
	return 0;
}
