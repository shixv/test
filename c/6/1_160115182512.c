#include <stdio.h>
#include <stdlib.h>
#define LL unsigned long long int


int main(int argc,char *argv[])
{
	LL T=(LL)atoll(argv[1]);
	printf("%lld",T);
	while(T!=1ull)
	{
		if(T&1)
			T=T*3+1;
		else
			T>>=1;
		printf("->%lld",T);
	}
	printf("\n");
	return 0;
}
