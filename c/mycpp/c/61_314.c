#include <stdio.h>

int main(int argc,char *argv[])
{
	int i=0;
	while((&argv[1][i])!=NULL)
	{
		if(argv[1][i]==argv[2][0]){printf("%d\n",i+1);break;}
		i++;
	}
	return 0;
}
