#include <stdio.h>

int main(int argc,char *argv[])
{
	char *s=argv[1];
	int flag=0;
	int i=0;
	int count=0;
	while(s[i++]!='\0')
	{
		if(s[i]=='A')
			flag=flag^1;
		if(flag)
			count++;
	}
	printf("%d\n",count-1);
	return 0;
}
