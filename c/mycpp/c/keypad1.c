#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

#define LOCAL_ESCAPE_KEY 27

int main(void)
{
	int key;

	initscr();
	crmode();
	keypad(stdscr,true);

	noecho();
	clear();
	mvprintw(5,5,"Key pad demonstratioin. press 'q' to quit");
	move(7,5);
	refresh();
	key=getch();

	while(key!=ERR&&key!='q'){
		move(7,5);
		clrtoeol();

		if((key>='A'&&key<='Z')||(key>='a'&&key<='z')){
			printw("Key was %c",(char)key);
		}
		else{
			switch(key){
				case LOCAL_ESCAPE_KEY: printw("%s","Escape Key");break;
				case KEY_END: printw("%s","End key");break;
				case KEY_BEG: printw("%s","BEGINING key");break;
				case KEY_RIGHT: printw("%s","RIGHT KEY");break;
				case KEY_LEFT: printw("%s","LEFT KEY");break;
				case KEY_UP: printw("%s","UP KEY");break;
				case KEY_DOWN: printw("%s","DOWN KEY");break;
				default: printw("Unmatched - %d",key);break;
			}
		}
		refresh();
		key=getch();
	}
	endwin();
	exit(EXIT_SUCCESS);
}

