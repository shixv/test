#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int getKeyByValue(char *keyvaluebuf,char *keybuf,char *valuebuf,int *valuebuflen)
{
	if(keyvaluebuf==NULL||keybuf==NULL)
		return -1;
	char *tmp=(char *)malloc(sizeof(char)*(strlen(keyvaluebuf)+1));
	int i=0;int j=0;
	while(keyvaluebuf[i]!='\0')
	{
		if(!isspace(keyvaluebuf[i]))
		{
			tmp[j]=keyvaluebuf[i];
			j++;
			tmp[j]='\0';
		}
		i++;
	}
	if(!strcmp(strtok(tmp,"="),keybuf))
	{
		strcpy(valuebuf,strtok(NULL,"="));
		*valuebuflen=strlen(valuebuf);
		free(tmp);
		return 0;
	}
	free(tmp);
	return -2;
}

int main(int argc,char *argv[])
{
	char *c=(char *)malloc(sizeof(char)*(strlen(argv[1])+1));
	int	d=1;
	getKeyByValue(argv[1],argv[2],c,&d);
	printf("%s,%d\n",c,d);
	free(c);
	return 0;
}
