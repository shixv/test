#include <stdio.h>

unsigned int getBit(unsigned int x,int pos,int n)
{
	unsigned int sum=0u;
	for(int i=pos,int j=0;i<pos+n;i++,j++)
		 if((x>>i)&1u)
			 sum+=2u<<j;
	return sum;
}
