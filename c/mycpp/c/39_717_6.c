#include <stdio.h>

int main(void)
{
	int i;char c,temp;
//	while(c!='\n')
//	{
//		temp=c;
//		c=getchar();
//		if(temp=='e'&&c=='i')i++;
//	}
	for(i=0,c=' ',temp=' ';c!='\n';temp=c,c=getchar(),(temp=='e'&&c=='i')?i++:i);
	printf("%d\n",i);
	return 0;
}
