#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int n=atoi(argv[1]);
	for(int i=31;i>=0;i--)
	{
		printf("%d",(n>>i)&1);
		if((i)%4==0)
			printf(" ");
	}
	printf("\n");
	return 0;
}
