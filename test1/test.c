#include <stdio.h>

int main(void)
{
	FILE *open=fopen("a.txt","w+");                                  	fseek(open,-12L,SEEK_END);
	char rc='l';

	for(int i=0;i<2;i++){	fwrite(&rc,1,1,open);
	}
	return 0;
}
