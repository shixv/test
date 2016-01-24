#include <stdio.h>
#include <unistd.h>
#include <curses.h>

int main(void)
{
	for(int i=0;i<6;i++)
	{
		fflush(stdout);
		printf("%d",i);
		sleep(1);
	}
	delch();
	refresh();
	sleep(1);
	return 0;
}
