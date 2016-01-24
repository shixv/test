#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
int main()
{
	srand((unsigned int)time(0));

	int ch;
	while((ch=getchar())!=EOF){
		putchar(ch+(int)(rand()%10+1));
	}
	exit(0);
}
