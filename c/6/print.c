#include <termios.h>
#include <stdio.h>

void initkeyboard();
void closekeyboard();
int main(void)
{
	struct termios setting;
	char ch;

	initkeyboard(&setting);

	while((ch=getchar())!='q')
	{
		switch(ch){
			case 'j':
				printf("j");
				break;
			case 'k':
				printf("k");
				break;
			case 'h':
				printf("h");
				break;
			case 'l':
				printf("l");
				break;
		}
	}

	closekeyboard(&setting);
	return 0;
}
void initkeyboard(struct termios *t)
{
	tcgetattr(0,t);
	struct termios new=*t;
	new.c_lflag&=~ICANON;
	new.c_lflag&=~ECHO;
	new.c_cc[VMIN]=1;
	new.c_cc[VTIME]=1;
	tcsetattr(0,TCSANOW,&new);
}
void closekeyboard(struct termios *t)
{
	tcsetattr(0,TCSANOW,t);
}
