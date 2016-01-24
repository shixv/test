#include <stdio.h>

int main(int argc,char *argv[])
{
	FILE *p1=fopen(argv[0],"r");
	FILE *p2=fopen("tmp","w");
	char ch=' ';
	int n=1;
	while(n!=0)
	{
		n=fread(&ch,1,1,p1);
		fwrite(&ch,1,1,p2);
	}
	n=2;
	fwrite(&n,sizeof(int),1,p2);
	remove(argv[0]);
	rename("tmp",argv[0]);
	fclose(p1);
	fclose(p2);
	return 0;
}
