#include <stdio.h>
#include <stdlib.h>
#define SIZE 48

int main(int argc,char *argv[])
{
	FILE *p1=fopen(argv[1],"r");
	FILE *p2=fopen(argv[2],"w");
	int rc;
	int *ch=(int *)malloc(sizeof(int)*SIZE);
	while((rc=fread(ch,1,SIZE,p1))!=0){
	printf("%d\n",rc);
	//	for(int i=0;i<1024;i++)
	//		ch[i]+=1;
		fwrite(ch,1,SIZE,p2);
	}
	fclose(p1);
	fclose(p2);
	return 0;
}
