#include <unistd.h>
#include <termios.h>
#include <stdio.h>

int main(void)
{
	struct termios *p=NULL;
	tcgetattr(fileno(stdin),p);
//	printf("%x\n",p->c_iflag);
	return 0;
}
