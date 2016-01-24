#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int spit_string(char *src,char ch,char (*array)[30],int *count_p)
{
	char *p=src;
	char *q=p;
	int temp_count=0;
	int len=0;

	temp_count=0;

	while((p=strchr(p,ch))!=NULL)
	{
		strncpy(array[temp_count],q,p-q);
		array[temp_count][p-q]='\0';
		temp_count++;
		p++;
		q=p;
		if(*q=='\0')
			break;
	}
	if(*q!='\0')
	{
		len=(src+strlen(src))-q;
		strncpy(array[temp_count],q,len);
		array[temp_count][len]='\0';
		temp_count++;
	}
	*count_p=temp_count;
	return 0;
}
int main(void)
{
	char *str="abdkj,jskdfk,hdjksh,hjdh,kdsfh,sdkfh";
	char array[10][30];
	int count=0;
	int ret=0;
	int i=0;

	ret=spit_string(str,',',array,&count);
	if(ret<0)
	{
		printf("spit_string error\n");
		return -1;
	}
	for(i=0;i<count;i++)
		printf("array[%d]:%s\n",i,array[i]);
	return 0;
}
