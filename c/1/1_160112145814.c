#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	printf("nihao\n");
	remove(argv[0]);
	printf("zaijian\n");
	return 0;
}
