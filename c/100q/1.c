#include <stdio.h>

int main(void)
{
	for(int x=0;x<=10;x++)
		for(int y=0;y<=25;y++)
			for(int z=0;z<=50;z++)
				if((5*x+2*y+z)==50)
					printf("x=%d,y=%d,z=%d\n",x,y,z);
	return 0;
}
