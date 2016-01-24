#include <stdio.h>

int main(void)
{
	int a=9;
	printf("%d\n",(int)&a);
	int b=(int)&a;
	*((int *)b)=10;
	printf("%d\n",a);
	return 0;
}
