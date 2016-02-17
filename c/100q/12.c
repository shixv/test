#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *join(char *s1,char *s2)
{
	int len=strlen(s1)+strlen(s2);
	char *ret=(char *)malloc(len+1);
	strcpy(ret,s1);
	strcpy(ret+strlen(s1),s2);
	ret[len]='\0';
	return ret;
}
int main(void)
{
	char *s1="fuck ";
	char *s2="you";
	printf("%s\n",join(s1,s2));
	return 0;
}
