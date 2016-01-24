#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	FILE *p=fopen(argv[1],"r");
	char ch;
	int rc;
	while((rc=fread(&ch,1,1,p))!=0)
	{
	putchar(ch);
	}
	putchar('\n');
	fclose(p);
	return 0;
}

