#include <stdio.h>


void printone(unsigned long int n);
int main(void)
{
	printone(1212212412lu);
	return 0;
}

void printone(unsigned long int n)
{
	if(n>=10)
		printf("%lu",n/10lu);
	printf("%lu",n-(n/10lu)*10lu);
}
