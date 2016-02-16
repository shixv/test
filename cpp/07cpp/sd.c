#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	execlp("/sbin/shutdown","shutdown","-h","now",0);
	exit(0);
}
