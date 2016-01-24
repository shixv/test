#include <time.h>
#include <stdio.h>
#include <stdlib.h>

nt main(void)
{
	time_t t=9;
	printf("%d\n",sizeof(time_t));
	printf("%ld\n",t);
	printf("%d\n",sizeof(long int));
	printf("%ld\n",~(1L<<31));
	t=(time_t)~(1L<<31);
	printf("%s\n",ctime(&t));
	return 0;
}


