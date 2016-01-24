#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *keywords[]={
	"while",
	"case",
	"static",
	"do"
};
int searchKeyTable(const char* table[],const int size,const char* key,int *pos)
{
	for(int i=0;i<size;i++)
	{
		if(strcmp(table[i],key)==0)
			*pos=i+1;
	}
	return 0;
}
int main(int argc,char *argv[])
{
	char *key1="case";
	int p1=0;
	searchKeyTable(keywords,4,key1,&p1);
	printf("%d\n",p1);
	return 0;
}
