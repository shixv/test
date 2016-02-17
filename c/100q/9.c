#include <stdio.h>

int main(void)
{
	for(int i=2;i<10;i++)
		for(int j=1;j<10;j++)
			for(int k=1;k<10;k++)
				for(int l=0;l<10;l++)
					for(int m=0;m<10;m++)
						if(((i*(j*10+3+k))*(i*(j*10+3+k)))==(8*1000+l*100+m*10+9))
							printf("[%d*(%d3+%d)]^2=8%d%d9\n",i,j,k,l,m);
	return 0;
}
