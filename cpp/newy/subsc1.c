#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

int main(void)
{
	WINDOW *sub_window_ptr;
	int x_loop;
	int y_loop;
	int counter;
	char a_letter=' ';

	initscr();

	for(y_loop=0;y_loop<LINES-1;y_loop++){
		for(x_loop=0;x_loop<COLS-1;x_loop++){
			mvwaddch(stdscr,y_loop,x_loop,a_letter);
		}
	}

	sub_window_ptr=subwin(stdscr,10,20,10,10);
	box(sub_window_ptr,'|','-');
	scrollok(sub_window_ptr,1);

	touchwin(stdscr);
	refresh();
	sleep(1);

	werase(sub_window_ptr);
	box(sub_window_ptr,'|','-');
	mvwprintw(sub_window_ptr,2,0,"%s","This window will now scroll");
	wrefresh(sub_window_ptr);
	sleep(1);

	for(counter=1;counter<10;counter++){
		box(sub_window_ptr,'|','-');
		wprintw(sub_window_ptr,"%s","This text is both wrapping and \
				scrolling.");
		wrefresh(sub_window_ptr);
		sleep(1);
	}

	delwin(sub_window_ptr);

	touchwin(stdscr);
	refresh();
	sleep(1);

	endwin();
	exit(EXIT_SUCCESS);
}
