#include <unistd.h>
#include <stdio.h>
#include <curses.h>

int main(void)
{
		start_color();
		printf("%hd\n",COLOR_PAIRS);
	return 0;
}
