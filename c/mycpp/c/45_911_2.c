#include <stdio.h>

void chline(char c,int i,int j);
int main(void)
{
	char c;int i,j;
	printf("input a charactor,two number: ");
	scanf("%c %d %d",&c,&i,&j);
	chline(c,i,j);
	return 0;
}
void chline(char c,int i,int j)
{
	int t;
	for(t=1;t<i;t++)putchar(' ');
	for(;i<=j;i++)putchar(c);
	putchar('\n');
}
	
