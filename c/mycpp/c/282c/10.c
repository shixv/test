#include <stdio.h>

int main(void)
{
	int i=2,n=10;
	float fac=1;
	if(n==0||n==1)
	{
		printf("factorial is 1\n");
		return 0;
	}
	while(i<=n)
	{
		fac*=i;
		i++;
	}
	printf("factorial of %d is:%2f.\n",n,fac);
	return 0;
}
