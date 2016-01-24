#include <unistd.h>
#include <stdio.h>

int main(void)
{
	if(isatty(fileno(stdin))&&isatty(fileno(stdout)))
		fprintf(stderr,"It's a tty.\n");
	else 
		fprintf(stderr,"Not a tty.\n");
	return 0;
}
