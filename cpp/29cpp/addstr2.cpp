#include <curses.h>
int main(void)
{
	initscr();
	move(1,1);
	addstr("asdfjasld");
	refresh();
	getchar();
	endwin();
	return 0;
}

