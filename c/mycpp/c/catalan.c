#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long int INT;
INT catalan(int n);
int main(int argc,char *argv[])
{
	printf("%d caltalan is %lld\n",atoi(argv[1]),catalan(atoi(argv[1])));
	return 0;
}
INT catalan(int n)
{
	INT sum=0LL;
	if(n==0)
		return 1LL;
	if(n==1)
		return 1LL;
	for(int k=0;k<n;k++)
	{
		sum+=catalan(k)*catalan(n-k-1);
	}
	return sum;
}
