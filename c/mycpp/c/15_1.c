#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	unsigned long long int sum=0LLU;
	for(int i=strlen(argv[1])-1;i>=0;i--)
		sum+=(unsigned long long int)(argv[1][i]-48)<<(strlen(argv[1])-1-i);
	printf("%lld\n",sum);
	return 0;
}
