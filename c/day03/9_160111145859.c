#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(char **my_array,int len)
{
	int i=0;
	for(i=0;i<len;i++)
	{
		printf("%s\n",my_array[i]);
	}
}

int sort_array(char *my_array[],int len)
{
	int i=0;
	int j=0;
	char *tmp=NULL;
	for(i=0;i<len;i++)
		for(j=i;j<len;j++)
			if(strcmp(my_array[i],my_array[j])>0)
			{
				tmp=my_array[j];
				my_array[j]=my_array[i];
				my_array[i]=tmp;
			}
	return 0;
}
int main(void)
{
	char *my_array[]={"aaaaaa","ccccc","bbbbbb","1111111"};
	int len = sizeof(my_array)/sizeof(my_array[0]);
	sort_array(my_array,len);
	print_array(my_array,len);
	return 0;
}
