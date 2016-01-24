#include <stdio.h>

unsigned long  x32(unsigned long n);
int main(void)
{
	unsigned long n;
	printf("input a number: ");
	scanf("%ld",&n);
	printf("the nuber is %ld \n",x32(n));
	return 0;
}
unsigned long x32(unsigned long n)
{
	int i;
	for(i=0;n!=1;i++,n=((n%2)?(3*n+1):(n/2)));
	return i;
}
	
