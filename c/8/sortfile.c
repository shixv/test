#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b)
{
		return *(int *)a-*(int *)b;
}
void Qsortstd(int *a,int n)
{
		qsort(a,n,sizeof(int),compare);
}
int main(int argc,char *argv[])
{
	int count=0;
	FILE *p=fopen(argv[1],"r");
	int *rc=(int *)malloc(sizeof(int));
	while(!feof(p))
	{
		fscanf(p,"%d",rc);
		count++;
	}
	free(rc);
	fseek(p,0,SEEK_SET);
	rc=(int *)malloc(sizeof(int)*count);
	for(int i=0;i<count;i++)
		fscanf(p,"%d",rc+i);
	fclose(p);
	Qsortstd(rc,count);
	p=fopen(".tmp","w");
	for(int i=0;i<count;i++)
	{
		if(i%10==0)
			fprintf(p,"\n");
		fprintf(p,"%d ",rc[i]);
	}
	free(rc);
	fclose(p);
	remove(argv[1]);
	rename(".tmp",argv[1]);
	return 0;
}	
