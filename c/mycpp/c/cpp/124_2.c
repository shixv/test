#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int n=atoi(argv[1]);
	for(int i=0;i<=10;i++)
		printf("%d ",n+i);
	printf("\n");
	return 0;
}
