#include <stdio.h>
int sum(int a)
{
	int c=0;
	static int b=3;
	c++;
	b+=2;
	return (a+b+c);
}
int main(void)
{
	int i;
	int a=2;
	for(i=0;i<5;++i)
	{
		printf("%d\n",sum(a));
	}
	return 0;
}
