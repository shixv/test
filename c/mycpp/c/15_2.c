#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	for(int i=0;i<strlen(argv[1]);i++)
		printf("%d",(argv[1][i]-48)?0:1);
	printf("\n");
	for(int i=0;i<strlen(argv[1]);i++)
		printf("%d",(argv[1][i]-48)&(argv[2][i]-48));
	printf("\n");
	return 0;
}
