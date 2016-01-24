#include <stdio.h>

int main(int argc,char *argv[])
{
	if(argc==1)
		return 0;
	FILE *fp1=fopen(argv[1],"r");
	FILE *fp2=fopen("tmp.txt","w");
	long int i=0L;
	while(getc(fp1)!=EOF)
		i++;
	for(long int j=-2;j>=-i;j--)
	{
		fseek(fp1,j,SEEK_END);
		putc(getc(fp1),fp2);
	}
	fseek(fp1,-1L,SEEK_END);
	putc(getc(fp1),fp2);
	fclose(fp1);
	fclose(fp2);
	remove(argv[1]);
	rename("tmp.txt",argv[1]);
	return 0;
}
