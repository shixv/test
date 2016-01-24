#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IN
#define OUT

void free_mem(char ***array,int num)
{
	char **array= *array_p;
	int i=0;
	if(array_p==NULL){
		return;
	}
	if(array!=NULL){
		for(i=0;i<num;i++){
			if(array[i]!=NULL){
				free(array[i]);
				array[i]=NULL;
			}
		}
		free(array);
		*array_p=NULL;
	}
}
int sort(IN char *array_1[],IN int num1,IN char(*array_2)[30],IN int num2,OUT char ***array_3p,OUT int *num3_p)
{
	char **p=NULL;
	int ret=0;
	int num3=0;
	int len=0;
	int i=0;
	int j=0;
	char *temp=NULL;
	if(array_1==NULL||array_2==NULL||array_3p==NULL||mum3_p==NULL){
		printf("array_1");
		return -1;
	}
	num3=num1+num2;
	p=(char **)malloc(sizeof(char *)*num3);
	if(p==NULL){
		printf("malloc char **p error\n");
		ret=-1;
		goto END;
	}
	memset(p,0,sizeof(char *)*num3);
	for(i=0;i<num1;i++){
		len=strlen(array_1[i]);
		p[i]=(char *)malloc(sizeof(char)*(len+1));
		if(p[i]==NULL){
			printf("malloc p[%d] error\n",i);
			ret=0;
			goto END;
		}
	}
}
