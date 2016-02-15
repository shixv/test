#include <unistd.h>
#include <curses.h>

int main(void)
{
	initscr();
	WINDOW *w=newwin(12,12,2,2);
	box(w,'a','a');
	mvwprintw(w,5,2,"%s","HEHE");
	wrefresh(w);
	sleep(1);
	delwin(w);
	endwin();
	return 0;
}
