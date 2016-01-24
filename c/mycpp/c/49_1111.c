#include <stdio.h>

int main(void)
{
	char name[81];
	printf("Hi!What's your name? \n");
	gets(name);
	printf("Nice name %s \n",name);
	return 0;
}

