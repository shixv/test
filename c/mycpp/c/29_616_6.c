#include <stdio.h>
#include <string.h>

int main(void)
{
	char T[50];
	scanf("%s",T);
	int i;
	for(i=strlen(T);i>=0;i--)
		printf("%c",T[i]);
	printf("\n");
	return 0;
}
