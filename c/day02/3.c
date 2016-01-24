#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	srand((unsigned int)time(0));
	int n;
	for(int i=0;i<1000;i++)
	{
		n=rand()%10;
		switch(n){
			case 1:putchar('!');break;
			case 2:putchar('@');break;
			case 3:putchar('#');break;
			case 4:putchar('$');break;
			case 5:putchar('%');break;
			case 6:putchar('^');break;
			case 7:putchar('&');break;
			case 8:putchar('*');break;
			case 9:putchar('(');break;
			case 0:putchar(')');break;
		}
	}
	printf("\n");
	return 0;
}
