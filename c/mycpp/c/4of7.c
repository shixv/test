#include <stdio.h>

void rmspace(char *,int);
void printstr(char *,int);
void movestr(char *,int,int);
int main(int argc,char *argv[])
{
	if(argc==1)
	{
		char str[15]="We Are Family!";
		rmspace(str,15);
		printstr(str,15);
	}
	else
	{
		printf("加参数时需用双引号括起\n");
		int n=0;
		while(argv[1][n]!='\0')n++;
		char *pstr=argv[1];
		rmspace(pstr,n+1);
		printstr(pstr,n+1);
	}
	return 0;
}
void rmspace(char *str,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(str[i]==' ')movestr(str,i,n);
}
void printstr(char *str,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%c",str[i]);
	putchar('\n');
}
void movestr(char *str,int i,int n)
{
	for(;i<n;i++)
		str[i]=str[i+1];
	str[n-1]='\0';
}

