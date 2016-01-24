#include <stdio.h>
int put2(const char * string)
{
	int count=0;
	while(*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');
	
	return count;
}
int main(void)
{
	char a[101];
	gets(a);
	printf("%d chars.\n",put2(a));
	return 0;
}
