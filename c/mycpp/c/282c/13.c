#include <stdio.h>

int  main(void)
{
	int i,x,y,z=1;
	printf("Please input two number:\n");
	scanf("%d%d",&x,&y);
	for(i=1;i<y;i++)
		z=z*x%1000;
	if(z>=100)
		printf("zui hou san wei shu: %d\n",z);
	else
		printf("%d\n",z);
	return 0;
}
