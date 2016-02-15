#include <stdio.h>

int main(void)
{
	int a,b;
	for(a=4,b=6;a+b;a++,++a);
	printf("%d\n",a);
	return 0;
}
