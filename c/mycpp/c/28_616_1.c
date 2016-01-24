#include <stdio.h>
#define AS 255
int main(void)
{
	char A[AS];int i;
	for(i=0;i<AS;i++)
		A[i]=(char)(i);
	for(i=0;i<AS;i++)
		printf("%2c",A[i]);
	printf("\n");
	return 0;
}
		
