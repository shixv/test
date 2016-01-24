#include <stdio.h>

int main(int argc,char *argv[])
{
	char ch;
	FILE *fp=fopen(argv[1],"r");
	if(fp==NULL)return 0;
	while((ch=getc(fp))!=EOF)
	{
		putc(ch,stdout);
	}
	return 0;
}
