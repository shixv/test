#include <stdio.h>
#include <unistd.h>
#include <curses.h>

int main(void)
{
	int line;
	int i;
	char c;

	initscr();
	refresh();
	for(line=0;line<LINES;line++){
		move(line,line);
		c=line+'0';
		addch(c);
		usleep(200000);
		refresh();
	}
	endwin();
}

