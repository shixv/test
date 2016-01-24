#include <stdio.h>
#include <string.h>

int main(void)
{
	char first[40],last[40];
	scanf("%s %s",first,last);
	printf("%*d %*d\n",strlen(first),strlen(first),strlen(last),strlen(last));
	return 0;
}
