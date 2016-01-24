#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

int main(void)
{
	initscr();

	if(!has_colors()){
		endwin();
		fprintf(stderr,"Error - no color support on this terminal\n");
		exit(1);
	}
	if(start_color()!=OK){
		endwin();
		fprintf(stderr,"Error-could not initialize colors\n");
		exit(2);
	}

	clear();
	mvprintw(5,5,"There are %d COLORS,and %d COLORS_PAIRS avalable",COLORS,COLOR_PAIRS);
	refresh();

	init_pair(1,COLOR_RED,COLOR_BLACK);
	init_pair(2,COLOR_RED,COLOR_GREEN);
	init_pair(3,COLOR_GREEN,COLOR_RED);
	init_pair(4,COLOR_YELLOW,COLOR_BLUE);
	init_pair(
