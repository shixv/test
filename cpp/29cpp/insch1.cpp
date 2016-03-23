#include <curses.h>

int main(void)
{
    initscr();

    move(0,0);
    printw("Hello World!");
    refresh();
    getchar();

    move(0,0);
    insch('T');

    refresh();
    getchar();

    endwin();
    return 0;
}
