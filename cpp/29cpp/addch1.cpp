#include <curses.h>

int main(void)
{
    initscr();

    move(11,11);
    addch('a');
    move(12,11);
    const chtype *a=(const chtype *)"heheda";
    addchstr(a);


    refresh();
    getchar();

    endwin();
    return 0;
}
