#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	execlp("ps","ps","ax",0);
	printf("Done.\n");
	exit(0);
}
