#include <curses.h>
int main(void)
{
	initscr();

//	attron(A_REVERSE);
//	attron(A_BLINK);
//	attron(A_BOLD);
	start_color();
	init_pair(1,COLOR_RED,COLOR_RED);
	attron(A_STANDOUT);
	attrset(COLOR_PAIR(1));
	addch(ACS_BLOCK);
	move(1,0);
	addch(ACS_BLOCK);
	move(2,0);
	addch(ACS_BLOCK);
	move(2,1);
	addch(ACS_BLOCK);
//	attroff(A_BLINK);
//	attroff(A_REVERSE);

	refresh();
//	attroff(A_REVERSE);
	getchar();
	endwin();
	return 0;
}
