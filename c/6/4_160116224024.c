#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *s=(char *)malloc(128);
	FILE *in=fopen("/dev/tty","r");
	FILE *out=fopen("/dev/tty","w"); 
	fputs(fgets(s,128,in),out);
	fclose(in);
	fclose(out);
	free(s);
	return 0;
}
