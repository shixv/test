#include <stdio.h>

char *itobs(int,char *);
void show_bstr(const char *);

int main(void)
{
	char bin_str[sizeof(int)*8+1];
	int number;

	puts("Enter integers and see them in binary.\n");
	puts("Non-numeric input terminates program.\n");
	while(scanf("%d",&number)==1)
	{
		itobs(number,bin_str);
		printf("%d is ",number);
		show_bstr(bin_str);
		putchar('\n');
	}
	puts("Bye!\n");
	return 0;
}

char *itobs(int n,char *ps)
{
	int i;
	static int size=8*sizeof(int);
	for(i=size-1;i>=0;i--,n>>=1)
		ps[i]=(01&n)+'0';
	ps[size]='\0';
	return ps;
}

void show_bstr(const char *str)
{
	int i=0;
	while(str[i])
	{
		putchar(str[i]);
		if(++i%4==0&&str[i])
			putchar(' ');
	}
}
