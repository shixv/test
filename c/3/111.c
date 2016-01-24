#include <stdio.h>

struct A
{
	int i:8;
	int j:4;
	int a:3;
	double b;
};
struct B
{
	int i:8;
	int j:4;
	double b;
	int a:3;
};
int main(void)
{
	printf("%d\n",sizeof(struct A));
	printf("%d\n",sizeof(struct B));
	return 0;
}

