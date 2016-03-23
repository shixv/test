#include <curses.h>

int main(void)
{
	initscr();
	mvaddch(22,22,ACS_LTEE);
	mvaddch(22,23,ACS_CKBOARD);
	mvaddch(22,24,ACS_DIAMOND);
	box(stdscr,ACS_VLINE,ACS_HLINE);
	refresh();
	getchar();
	endwin();
	return 0;
}
