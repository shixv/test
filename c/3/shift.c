#include <stdio.h>

int main(void)
{
	unsigned int n=1000u;
	int count=0;
	int i=0;
	while(n>>i)
	{
		if((n>>i)&1)
			count++;
		i++;
	}
	printf("%d\n",count);
	return 0;
}
