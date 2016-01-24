#include <stdio.h>

void *test1(void);
void *test2(void);
int main(void)
{
	printf("%p\n",test1());
	printf("%p\n",test2());
	return 0;
}
void *test1(void)
{
	return (void *)(&"1234556");
}
void *test2(void)
{
	return (void *)(&"1234551");
}

