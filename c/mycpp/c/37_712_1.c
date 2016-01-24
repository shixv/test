#include <stdio.h>

int main(void)
{
	int sp=0,en=0,ot=0;
	char c;
	while((c=getchar())!='#')
	{
		if(c==' '){sp++;continue;}
		if(c=='\n'){en++;continue;}
		ot++;continue;
	}
	printf("space=%d enter=%d other=%d\n",sp,en,ot);
	return 0;
}
