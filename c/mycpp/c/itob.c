#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main1(int argc,char *argv[])
{
	unsigned long long int sum=0LLU;
	for(int i=strlen(argv[1])-1;i>=0;i--)
		sum+=(unsigned long long int)(argv[1][i]-48)<<(strlen(argv[1])-1-i);
	printf("%lld\n",sum);
	return 0;
}

int main(int argc,char *argv[])
{
	int n=atoi(argv[1]);
	int i=0;
	while(n!=0)
	{
		n/=2;
		i++;
	}
	n=atoi(argv[1]);
	int *ar=(int *)malloc(sizeof(int)*i);
	for(int j=i-1;j>=0;j--)
	{
		ar[j]=n%2;
		n/=2;
	}
	for(int j=0;j<i;j++)
		printf("%d",ar[j]);
	printf("\n");
	return 0;
}
