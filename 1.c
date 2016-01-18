#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replaceSubstr(char *src,char **dst,char *sub,char *new_sub)
{
	if(src==NULL&&src[0]=='\0'&&sub==NULL&&sub[0]=='\0'&&new_sub==NULL&&new_sub[0]=='\0')
		return -1;
	char *source=src;
	char *old=sub;
	char *new=new_sub;
	char *tmp=source;
	int i=0,j;
	int n=0;
	while((tmp=strstr(tmp,old))!=NULL)
	{
		tmp++;
		i++;
	}
	*dst=(char *)malloc(sizeof(char)*(j=(strlen(source)+(strlen(new)-strlen(old))*i+1)));
	if(*dst==NULL)
		return -1;
	memset(*dst,0,j);
	while(strstr(source,old)!=NULL)
	{
		n=strstr(source,old)-source;
		strncat(*dst,source,n);
		strcat(*dst,new);
		source+=n+strlen(old);
	}
	strcat(*dst,source);
	if(*dst==NULL)
		return -1;
	return 0;
}
int main(int argc,char *argv[])
{
	char *s=NULL;
	replaceSubstr(argv[1],&s,argv[2],argv[3]);
	printf("%s\n",s);
	return 0;
}
