#include <stdio.h>
#include <string.h>
#include <ctype.h>

int trimSpace(char *in,char *out)
{
	if(!*in)return 0;
	int i,j=0;
	for(i=0;in[i];i++)
	{
		if(!isspace(in[i]))
			out[j++]=in[i];
	}
	out[j]='\0';
	return j-1;
}

int trimSpace1(char *in,char *out)\
{
	if(!*in)return 0;
	int i=0;
	int j=strlen(in)-1;
	while(isspace(in[i])&&in[i]!='\0')i++;
	while(isspace(in[j])&&j>i)j--;
	int len=j-i+1;
	strncpy(
	return 0;
}

int main(void)
{
	char *in="      h    e  l  l o    w  o rl   d!      ";
	char out[100]={0};
	trimSpace(in,out);
	printf("%s\n",out);
	trimSpace1(in,out);
	printf("%s\n",out);
	return 0;
}
