#include <stdio.h>
#include <errno.h>

int main(void)
{
	printf("%s\n",strerror(0));
	return 0;
}
