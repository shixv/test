#include <stdio.h>
#include <time.h>

int main(void)
{
	int i;
	char abc[26]={0};
	srand((int)time(0));
	for(i=0;i<26;i++)
		abc[i]=(char)('a'+rand()%26);
	for(i=0;i<26;i++)
		printf("%c,",abc[i]);
	putchar('\b');
	return 0;
}
