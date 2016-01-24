#include <stdio.h>
#include <stdlib.h>

typedef long long int INT;

INT facsum(INT n)
{
	INT i=1LL;
	INT sum=0LL;
	while((i+2LL)<=n)
	{
		if((n%i)==0LL)
			sum+=i;
		i++;
	}
	return sum;
}

int Behavecp(INT n)
{
	return facsum(facsum(n))==n;
}

int main(int argc,char *argv[])
{
	printf("%d\n",Behavecp(atoll(argv[1])));
	return 0;
}
