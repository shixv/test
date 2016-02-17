#include <stdio.h>
#include <string.h>
#include <ctype.h>

int f(char *s)
{
	int i=0;
	int count=0,count1=0,count2=0;
	static int flag=0;
	while(s[i]!='\0')
	{
		if(isalpha(s[i]))
			count++;
		if(isdigit(s[i]))
			count1++;
		if(isspace(s[i++]))
			count2++;
	}
	if(flag==0)
	{
		flag++;
		return count;
	}
	if(flag==1)
	{
		flag++;
		return count1;
	}
	if(flag==2)
	{
		return strlen(s)-count-count1-count2;
	}
	return 0;
}

int main(void)
{
	char *s="a\a 1";
	printf("%d\n",f(s));
	printf("%d\n",f(s));
	printf("%d\n",f(s));
	return 0;
}
