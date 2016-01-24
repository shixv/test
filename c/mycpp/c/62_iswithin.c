#include <stdio.h>

int is_within(char c,char *p);
int main(void)
{
	char c=' ';
	char str[51];
	while(c!='#')
	{
		scanf("%c %s",&c,str);
		printf("%d\n",is_within(c,str));
	}
	return 0;
}

int is_within(char c,char *p)
{
	int i=0;
	while(p[i]!='\0')
	{
		if(p[i]==c)return 1;
		i++;
	}
	return 0;
}
		

