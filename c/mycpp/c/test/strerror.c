#include <stdio.h>
#include <string.h>

int main(void)
{
	for(int i=0;i<134;i++)
	printf("%3d : %s\n",i,strerror(i));
	return 0;
}
