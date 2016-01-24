#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	for(int i=atoi(argv[1]);i<=atoi(argv[2]);printf("%d\t%d\t%d\n",i,i*i,i*i*i),i++);
	return 0;
}
