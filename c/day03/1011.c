#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_array(char array[][6],int len)
{
	int i=0;
	for(i=0;i<len;i++)
	{
		printf("%s\n",*(array+i));
	}
}
int sort_array(char *array[6],int len)
{
	char buf[6]={0};
	for(int i=0;i<len;i++)
		for(int j=i;j<len;j++)
			if(strcmp(array[i],array[j])>0)
			{
				strcpy(buf,array[i]);
				strcpy(array[i],array[j]);
				strcpy(array[j],buf);
			}
	return 0;
}

int main(void)
{
	char my_array[4][6]={"aaaaa","ccccc","bbbbb","lllll"};
	int len=4;
	print_array(my_array,len);
	sort_array(my_array,len);
	print_array(my_array,len);
	return 0;
}
