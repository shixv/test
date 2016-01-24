#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	st *s;
}st;
int main(void)
{
	st *a=(st *)malloc(sizeof(st));
	a->s=(char *)malloc(sizeof(char)*16);
	printf("input age,name.\n");
	scanf("%d,%s",&(a->i),a->s);;
	printf("%d,%s\n",a->i,a->s);
	FILE *p=fopen("a.txt","w");
	fwrite(a,sizeof(st),1,p);
	fwrite(a->s,16,1,p);
	free(a->s);
	free(a);
	fclose(p);
	return 0;
}
