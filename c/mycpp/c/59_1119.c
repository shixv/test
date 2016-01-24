#include <stdio.h>


void stor(char *p,int i);
int main(void)
{
	char ar[40];int i;
	stor(ar,40);
	putchar('\n');
//	puts(ar);
	for(i=0;i<40;i++)putchar(ar[i]);
	return 0;
}
void stor(char *p,int i)
{
	char c;int n=0;
	while((n<i)&&(c=getchar())!='\0')
	{
		p[n]=c;
		n++;
	}
}
	
