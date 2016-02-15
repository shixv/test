#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *in=fopen("dict.txt","r");
	FILE *out=fopen("file.out","w");
	int c;

	while((c=fgetc(in))!=EOF)
		fputc(c,out);

	exit(0);
}
