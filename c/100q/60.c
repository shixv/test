#include <stdio.h>
#include <stdlib.h>

int reverse(int n)
{
	int ret=0;
	while(n!=0)ret=ret*10+n%10,n/=10;
	return ret;
}

int main(int argc,char *argv[])
{
	int n=atoi(argv[1]);
	while(reverse(n)!=n||n<100)n+=reverse(n);
	printf("%d\n",n);
	return 0;
}
		
