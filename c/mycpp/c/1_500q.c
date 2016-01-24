#include <stdio.h>

int main(void)
{
	int x,y,z;
	for(x=0;x<=10;x++)
		for(y=0;y<=25;y++)
			for(z=0;z<=50;z++)
			{
				if((5*x+2*y+z)==50){printf("%4d%4d%4d\n",x,y,z);continue;}
				else continue;
			}
	return 0;
}
