#include <stdio.h>
#define MAX 10

void arr(char *p);

int main(void)
{
	char string[MAX];
	arr(string);
	puts(string);
	return 0;
}
void arr(char *p)
{
	int i;
	for(i=0;i<MAX-1;i++)
	{
		p[i]=getchar();
	}
	p[i]='\0';
}
