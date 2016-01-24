#include <stdio.h>

long int getfilesize(FILE *fp)
{
	fseek(fp,0,2);
	long int ret=ftell(fp);
	fseek(fp,0,0);
	return ret;
}

int main(int argc,char *argv[])
{
	FILE *p=fopen(argv[1],"r");
	printf("%ld\n",getfilesize(p));
	printf("%d,%d\n",p,SEEK_SET);
	fclose(p);
	return 0;
}
