#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IN
#define OUT
int sort(IN char **array1,IN int num1,IN char (*array2)[30],IN int num2,OUT char ***myp3,OUT int *num3) 
{
	char *temp;
	*num3=num1+num2;
	*myp3=(char **)malloc(sizeof(char *)*(*num3+1));
	for(int i=0;i<num1;i++)
	{
		(*myp3)[i]=(char *)malloc(sizeof(char)*(strlen(array1[i])+1));
		strcpy(*(*myp3+i),array1[i]);
	}
	for(int i=num1;i<num2+num1;i++)
	{
		(*myp3)[i]=(char *)malloc(sizeof(char)*(strlen(array2[i-num1])+1));
		strcpy(*(*myp3+i),*(array2+i-num1));
	}
	(*myp3)[*num3]=NULL;
	for(int i=0;i<*num3;i++)
		for(int j=i;j<*num3;j++)
			if(strcmp((*myp3)[i],(*myp3)[j])>0)
			{
				temp=(*myp3)[i];
				(*myp3)[i]=(*myp3)[j];
				(*myp3)[j]=temp;
			}
	return 0;	
}
int myfree(char **p)
{
	int i=0;
	while(p[i]!=NULL)
	{
		free(p[i]);
		i++;
	}
	free(p[i]);
	free(p);
	return 0;
}
int main(int argc,char *argv[])
{
	int ret=0;
	char *p1[]={
		"aa","ccccccc","bbbbbb"
	};
	char buf2[10][30]={
		"111111",
		"3333333",
		"2222222"
	};
	char **p3=NULL;
	int len1,len2,len3;

	len1=sizeof(p1)/sizeof(*p1);
	len2=3;

	ret=sort(p1,len1,buf2,len2,&p3,&len3);

	for(int i=0;i<len1+len2;i++)
	{
		printf("%s\n",p3[i]);
	}
	myfree(p3);

	return ret;
}
