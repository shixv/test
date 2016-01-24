#include <stdio.h>

int main(void)
{
	int year=0;
	double B=1000000.0;
	while(B>=0.0)
	{
		B=B*1.08-100000.0;
		year++;
	}
	printf("%d\n",year);
	return 0;
}
