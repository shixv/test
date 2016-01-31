#include <stdio.h>
#define FN "test.txt"
int main(void)
{
	FILE *fp=fopen(FN,"w+");
	if(fp==NULL)
		return -1;
	char ch='a';
	char ret=0;
	if(ret!=EOF)
	{
		printf("success\n");
	}
	ret=fputc(ch,fp);
	fseek(fp,0,SEEK_SET);
	ret=fgetc(fp);
	if(ret==EOF)
	{
		printf("fgetc errorl\n");
	}
//	fclose(fp);
//	fp=fopen(FN,"r+");
	printf("%c\n",ret);
	if(fp!=NULL)
	{
		fclose(fp);
	}
	return 0;
}
