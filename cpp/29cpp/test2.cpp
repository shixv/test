#include <unistd.h>
#include <curses.h>
int main(void)
{
	initscr();
	noecho();
	addch('x');
	waddch(stdscr,'y'|A_UNDERLINE|A_BOLD);
	mvaddch(2,1,'z'|A_BOLD);
	refresh();
	sleep(3);
	clear();
	addstr("heheda");
	waddstr(stdscr,"\n");
	mvwaddstr(stdscr,2,1,"heheda");
	refresh();
	sleep(3);
	clear();
	printw("%s%d    %c","name",10,'m');
	refresh();
	endwin();
}
