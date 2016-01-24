#include <stdio.h>
#include <curses.h>
#include <term.h>

int main(void)
{
	setupterm("unlisted",fileno(stdout),(int *)0);
	printf("Done.\n");
	return 0;
}
