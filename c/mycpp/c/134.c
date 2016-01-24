#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int rand_m(void);
void print_st(int a,int b);
int main(void)
{
	srand((long int)time(0));
	print_st(rand_m(),rand_m());
	return 0;
}
int rand_m(void)
{
	return (int)(rand()%100);
}
void print_st(int a,int b)
{
	printf("%d * %d = %d\n",a,b,a*b);
}
