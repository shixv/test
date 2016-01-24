#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	char *p=argv[1];
	printf("%d\n",strstr(p,argv[2])-p);
	return 0;
}
