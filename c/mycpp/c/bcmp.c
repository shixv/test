#include <stdio.h>
#include <string.h>

int main(void)
{
	char *a="abccd";
	char *b="abcer";
	printf("%d\n",bcmp(a,b,4));
	return 0;
}
