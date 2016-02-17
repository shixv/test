#include <stdio.h>
#include <string.h>

char *ind(char *src,char *sub)
{
	int i=0,j=0;
	while(src[i]!='\0')
		if(src[i++]==sub[j])
		{
			if(sub[++j]=='\0')
				return src+i-j;
			continue;
		}
		else
		{
			i-=j;
			j=0;
		}
	return NULL;
}
int main(void)
{
	printf("%s\n",ind("deadeddeedebcdeffefedeg","def"));
	return 0;
}
