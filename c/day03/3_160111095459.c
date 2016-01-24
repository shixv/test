#include <stdio.h>

int main(void)
{
	const int a=10;

	int p=(int)a;

//	int =&p;

	*p=9;

	printf("%d\n",a);

	return 0;
}
