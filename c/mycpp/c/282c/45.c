#include <stdio.h>
#include <math.h>


int main(int argc,char *argv[])
{
	char c;
	c=getchar();
	if(c>=65&&c<=90)
		printf("uppercase letter!\n");
	else
		printf("other letter\n");
	return 0;
}
