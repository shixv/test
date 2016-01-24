#include <stdio.h>

void itod(int n)
{
	if(n>=16)
	{
		itod(n/16);
	}
		switch(n%16)
		{
		case 0 : putchar('0');break;
		case 1 : putchar('1');break;
		case 2 : putchar('2');break;
		case 3 : putchar('3');break;
		case 4 : putchar('4');break;
		case 5 : putchar('5');break;
		case 6 : putchar('6');break;
		case 7 : putchar('7');break;
		case 8 : putchar('8');break;
		case 9 : putchar('9');break;
		case 10 : putchar('a');break;
		case 11 : putchar('b');break;
		case 12 : putchar('c');break;
		case 13 : putchar('d');break;
		case 14 : putchar('e');break;
		case 15 : putchar('f');break;
		default:break;
		}
	
}
int main(void)
{
	int n;
	scanf("%d",&n);
	itod(n);
	putchar('\n');
	return 0;
}
