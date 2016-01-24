#include <stdio.h>
#include <stdlib.h>

typedef long long int INT;
int main(int argc,char *argv[])
{
	if(argc==1)
		return 0;
	INT n=atoll(argv[1]);
	while(n!=0)
	{
		printf("%lld",n%2LL);
		n/=2LL;
	}
	putchar('\n');
	return 0;
}
