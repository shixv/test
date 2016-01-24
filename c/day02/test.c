#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *a=malloc(100);
	tmpnam(a);
	printf("%d\n",TMP_MAX);
	puts(a);
	free(a);
	return 0;
}
