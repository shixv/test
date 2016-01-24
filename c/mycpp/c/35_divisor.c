#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isP(unsigned long n);
int main(int argc,char *argv[])
{
	unsigned long xnum,dnum,i,j;
//	scanf("%lu %lu",&xnum,&dnum);
	xnum=(unsigned long)(atoi(argv[1]));
	dnum=(unsigned long)(atoi(argv[2]));
	for(i=xnum,j=0;i<=dnum;i++)
	{
		if(isP(i)){printf("%lu\t",i);j++;
		if(j%10==0)putchar('\n');}
	}
	putchar('\n');
	return 0;
}
bool isP(unsigned long n)
{
	unsigned long div;
	bool isPrime;

	for(div=2ul,isPrime=true;(div*div)<=n;div++)
	{
		if(n%div==0)isPrime=false;
	}
	return isPrime;
}

