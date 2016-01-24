#include <stdio.h>

#define _SIZE int 
#define _SEP ','
#define _END ';'

_SIZE fgetarr(unsigned int n,FILE *name)
{
	unsigned int i=0u;
	char ch;
	while(i<n)
	{
		ch=getc(name);
		if(ch==_END)
	}
}
