#include <stdio.h>

int main(void)
{
	FILE *p=fopen("fuck.c","w");
	if(p==NULL)
		printf("open file error.\n");
	else
		printf("open file success.\n");
	fclose(p);
	return 0;
}
