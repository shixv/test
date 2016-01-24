#include <stdio.h>

int main(void)
{
	char pre;
	char ch=getchar();
	int i=0;
	while(ch!='#')
	{
		pre=ch;
		ch=getchar();
		if(pre=='e'&&ch=='i')i++;
	}
	printf("%d\n",i);
	return 0;
}
