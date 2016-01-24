#include <unistd.h>
#include <stdio.h>
#include <termios.h>

int main(void)
{
	struct termios newtc,oldtc;
	tcgetattr(fileno(stdin),&oldtc);
	newtc=oldtc;
	newtc.c_lflag&=~ICANON;
	newtc.c_cc[VMIN]=1;
	newtc.c_cc[VTIME]=0;
	tcsetattr(fileno(stdin),TCSANOW,&newtc);
	putchar(getchar());
	tcsetattr(fileno(stdin),TCSANOW,&oldtc);
	return 0;
}

