#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>

int main(void)
{
	initscr();
	move(0,0);
	flash();
	printw("nihao\n");
	refresh();
	sleep(2);
	endwin();
	return 0;
}
