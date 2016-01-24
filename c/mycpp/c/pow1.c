#include <stdio.h>
int pow1(int a,int b);
int main(void)
{
	printf("%d\n",pow1(2,1000));
}
int pow1(int a,int b)
{
	int r=1;
	int base=a;
	while(b!=0)
	{
		if(b&1)r*=base;
		base*=base;
		b>>=1;
	}
	return r;
}
