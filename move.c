#include <term.h>
#include <curses.h>
#include <unistd.h>

void getboarder(int *y,int *x);
void convertboarder(int *y,int *x);

int main(void)
{
	initscr();
	noecho();
	int x=0,y=0;
	char ch;
	move(y,x);
	while((ch=getch())!='q')
	{
		switch(ch){
			case 'w':
				y--;
				break;
			case 'a':
				x--;
				break;
			case 's':
				y++;
				break;
			case 'd':
				x++;
				break;
		}
		convertboarder(&y,&x);
		move(0,0);
		printw("(%d,%d)\n",x,y);
		move(y,x);
		refresh();
	}
	endwin();
	return 0;
}
void getboarder(int *y,int *x)
{
	*x=getmaxx(stdscr);
	*y=getmaxy(stdscr);
}

void convertboarder(int *y,int *x)
{
	int by,bx;
	getboarder(&by,&bx);
	if(*y<0)
		*y+=by;
	if(*y>by-1)
		*y-=by;
	if(*x<0)
		*x+=bx;
	if(*x>bx-1)
		*x-=bx;
}
