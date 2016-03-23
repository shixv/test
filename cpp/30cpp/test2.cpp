#include <curses.h>
#include "kbhit.h"

int main(void)
{
	initscr();
	start_color();
	keypad(stdscr,TRUE);
	noecho();
	init_pair(1,COLOR_WHITE,COLOR_RED);
	curs_set(0);
	int ch=0,x=0,y=0;
	chtype cht=ACS_BLOCK|A_BOLD|COLOR_PAIR(1);
	while(ch!='q'){
		mvaddch(0,0,ACS_BLOCK);
		refresh();
		//		if(kbhit(ch,1)){
		//			mvprintw(5,5,(const char*)&ch);
		ch=getch();
		mvdelch(y,x);
		switch(ch){
			case KEY_UP:
				mvaddch(--y,x,cht);
				break;
			case KEY_DOWN:
				mvaddch(++y,x,cht);
				break;
			case KEY_LEFT:
				mvaddch(y,--x,cht);
				break;
			case KEY_RIGHT:
				mvaddch(y,++x,cht);
				break;
			default:
				mvaddch(y,x,cht);
				break;
		}
		mvdelch(0,0);
		refresh();
		//		}
	}
	//	move(0,0);
	//	addch(ACS_BULLET|A_BOLD|COLOR_PAIR(1));
	refresh();
	getchar();
	endwin();
	return 0;
}	
