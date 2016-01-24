#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replaceSubstr(/* in */char *src,/* out */char **dst,/* in */char *sub,/* in */char *new_sub);
int main(int argc,char *argv[])
	 
	if(argc<4)

	char *s=NULL;
	replaceSubstr(argv[1],&s,argv[2],argv[3]);
	printf("%s\n",s);
	return 0;
}

int replaceSubstr(char *src,char **dst,char *sub,char *new_sub)
{
	if(src==NULL&&src[0]=='\0'&&sub==NULL&&sub[0]=='\0'&&new_sub==NULL&&new_sub[0]=='\0')
		return -1;
	int i=0;
	char *tmp=src;
	while((tmp=strstr(tmp,sub))!=NULL)
	{
		i++;
		tmp++;
	}
	*dst=(char *)malloc(sizeof(char)*(strlen(src)+(strlen(new_sub)-strlen(sub))*i)+1);
	if(*dst==NULL)
		return -1;
	memset(*dst,0,sizeof(char)*(strlen(src)+(strlen(new_sub)-strlen(sub))*i)+1);
	*dst=strcat(*dst,strtok(src,sub));
	*dst=strcat(*dst,new_sub);
	for(int j=0;j<i;j++)
	{
		*dst=strcat(*dst,strtok(NULL,sub));
		*dst=strcat(*dst,new_sub);
	}
	if(*dst==NULL)
		return -1;
	return 0;
}

