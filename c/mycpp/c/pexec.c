#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("Running ps with execlp\n");
	execlp("ps","ps","-ax",0);
	printf("done.\n");
	return 0;
}
