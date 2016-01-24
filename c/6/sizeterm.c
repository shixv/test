#include <stdio.h>

#include <ncurses.h>

int main(void)
{
	int x,y;
	setupterm(NULL,fileno(stdout),NULL);
	x=tigetnum("cols");
	y=tigetnum("lines");
	printf("%d,%d\n",x,y);
	return 0;
}
