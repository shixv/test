#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	FILE *fp=fopen("prime.dat","r");
	int n;
	fseek(fp,4*atoi(argv[1])-4,SEEK_SET);
	fread(&n,4,1,fp);
	printf("%d ",n);
	return 0;
}
