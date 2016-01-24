#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_mem(char *a,char *b,int *al,int *bl)
{
	a=malloc(sizeof(char)*100);
	b=malloc(sizeof(char)*100);
	strcpy(a,"ahkdshfajgajkdsgfdsj");
	strcpy(b,"sehaflkgfjkaeeglaskjdg");
	*al=strlen(a);
	*bl=strlen(b);
	free(a);
	free(b);
}
int main(void)
{
	char *p1=NULL;
	char *p2=NULL;
	int len1=0;
	int len2=0;

	get_mem(p1,p2,&len1,&len2);
	printf("%d,%d\n",len1,len2);
	return 0;
}
