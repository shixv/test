#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_mem(char ***array_p,int count)
{
	char **array=*array_p;
	int  i=0;
	if(array_p==NULL)
		return; 
	if(array!=NULL)
	{
		for(i=0;i<count;i++)
		{
			if(array[i]!=NULL)
			{
				free(array[i]);
				array[i]=NULL;
			}
		}
		free(array);
		*array_p=NULL;
	}

}
int spit_string(char *src,char ch,char ***array_p,int *count_p)
{
	char **array=NULL;
	char *p=src;
	char *q=p;
	int temp_count=0;
	int str_len=0;
	int ret=0;
	while((p=strchr(p,ch))!=NULL)
	{
		temp_count++;
		p++;
		q=p;
		if(*q=='\0')
			break;
	}
	if(*q!='\0')
		temp_count++;
	array=(char**)malloc(sizeof(char*)*temp_count);
	if(array==NULL)
	{
		printf("malloc array error\n");
		ret=-1;
		goto END;
	}
	memset(array,0,sizeof(char*)*temp_count);
	p=src;
	q=p;
	temp_count=0;
	while((p=strchr(p,ch))!=NULL)
	{
		str_len=p-q;
		array[temp_count]=(char *)malloc(str_len+1);
		if(array[temp_count]==NULL)
		{
			printf("array[%d] malloc error\n",temp)
		}
	}
}

