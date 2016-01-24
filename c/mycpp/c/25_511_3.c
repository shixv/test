#include <stdio.h>

int main(void)
{
	int d=1;
	while(d>0)
	{
		scanf("%d",&d);
		printf("%d days are %d weeks %d days.\n",d,(d-d%7)/7,d%7);
	}
	return 0;
}
