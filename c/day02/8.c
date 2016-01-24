#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void funcB(char *buf)
{
	printf("in funcB  funcA: stack memory: buf: %s\n", buf);

	return ;
}

char * funcA(char *buf)
{
	char bufA[128] = "abcdefg";

	//printf("in funcA  main: heap memory: buf: %s\n", buf);
	printf("in funcA  funcA: stack memory: bufA: %s\n", bufA);


	funcB(bufA);

	return bufA;
}

int main(void)
{
	//char buf[128] = "1234567"; //stack
	char *buf = NULL;

	char *funcA_buf = NULL;

	buf = malloc(128);
	if (buf == NULL) {
		return 0;
	}
	memset(buf, 0, 128);
	strcpy(buf, "1234567");

	//free(buf);

	funcA_buf = funcA(buf);
	printf("in main: funA:statck memory : bufA = %s\n", funcA_buf);
	strcpy(funcA_buf, "XXXXXXXXX");
	printf("in main: funA:statck memory : bufA = %s\n", funcA_buf);


	free(buf);

	return 0;
}
