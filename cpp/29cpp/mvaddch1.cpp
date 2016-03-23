#include <curses.h>
#include <unistd.h>
int main(void)
{
	int ch=0;
	initscr();

	mvaddch(2,0,'a');
	halfdelay(10);
//	nodelay(stdscr,TRUE);
	refresh();
	while(ch!='q'){
		ch=getchar();
		printf("adsf");
		mvprintw(0,0,"%c",ch);
		refresh();
	}

	endwin();
	return 0;
}
