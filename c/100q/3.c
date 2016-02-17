#include <stdio.h>

int main(void)
{
	char *s="abcdefghijklmnopqrstuvwxy";
	printf("%c",s[12]);
	for(int i=1;i<13;i++)
	{
		printf("%c",s[12-i]);
		printf("%c",s[12+i]);
	}
	printf("\n");
	return 0;
}
