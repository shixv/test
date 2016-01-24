#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

int main(void)
{
	srand((unsigned int)time(0));
	initscr();
	while(1){
	move(rand()%26,rand()%104);
	printw("Hello world.");
	refresh();
	usleep(500000);
	clear();
	}

	endwin();
	return 0;
}
