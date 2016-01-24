#include <stdio.h>

int main(int argc,char *argv[])
{
	if(argc==1){printf("参数需用双引号括起\n");return 0;}
	char *ps=argv[1];
	int n=0,i;
	while(ps[n]!='\0')n++;
	for(i=0;i<n/2;i++)
	{
		if(ps[i]==ps[n-i-1]){continue;}
		else{printf("不是回文\n");return 0;}
	}
	printf("是回文\n");
	return 0;
}

