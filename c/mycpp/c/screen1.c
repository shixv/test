#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

int main(void)
{
	initscr();
	move(5,15);
	printw("%s","Hello World");
	refresh();
	flash();
	sleep(2);
	beep();

	endwin();
	exit(EXIT_SUCCESS);
}
