#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
	int i;
	char *s;
}st;
int main(void)
{
	FILE *p=fopen("a.txt","r");
	st *a=(st *)malloc(sizeof(st));
	fread(a,sizeof(st),1,p);
	a->s=(char *)malloc(16);
	fread(a->s,16,1,p);	
	printf("%d,%s\n",a->i,a->s);
	free(a->s);
	free(a);
	fclose(p);
	return 0;
}
