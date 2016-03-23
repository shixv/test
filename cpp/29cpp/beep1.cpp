#include <curses.h>

int main(void)
{
    initscr();
//   beep();
    move(0,0);
    printw("af");
    flash();
    refresh();
    getchar();
    endwin();
    return 0;
}
