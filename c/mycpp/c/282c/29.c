#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int INT;
int Isprime(INT n)
{
	INT i=2LLU;
	while(i*i<n)
		if(n%(i++)==0)
			return 0;	
	return 1;
}
int Isdevide(INT n)
{
	for(INT i=n/2LLU;i>1LLU;i--)
		if(Isprime(i)&&Isprime(n-i))
			return 1;
	return 0;
}

int main(int argc,char *argv[])
{
	printf("%d\n",Isdevide((INT)atoi(argv[1])));
	return 0;
}
