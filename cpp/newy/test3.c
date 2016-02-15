#include <unistd.h>
#include <ncurses.h>

int main(void)
{
	char *s="123451231234";
	initscr();

	box(stdscr,'#','#');
	move(12,12);
	addch('4');
	move(13,12);
	beep();
	refresh();

	sleep(2);

	endwin();

	return 0;
}
