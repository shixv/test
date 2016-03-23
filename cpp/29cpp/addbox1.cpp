#include <curses.h>

int main(void)
{
	initscr();
	box(stdscr,ACS_VLINE,ACS_HLINE);

	refresh();
	getchar();
	endwin();
	return 0;
}
