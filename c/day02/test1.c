#include <stdio.h>

int main(int argc,char *argv[])
{
	FILE *p1=fopen(argv[0],"r");
	fseek(p1,-1L,SEEK_END);
	char ch=fgetc(p1);
	printf("%c\n",ch);
	return 0;
}
