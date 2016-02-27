#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	struct tm *tm_ptr;
	time_t the_time;
	(void)time(&the_time);
	tm_ptr=gmtime(&the_time);
	char *a=ctime(&the_time);
	printf("%s\n",a);
	char* week=strtok(a," ");
	char* month=strtok(NULL," ");
	int dayofmonth=strtok(NULL," ");
	strtok(NULL," ");
	char *year=strtok(NULL," ");
/*
	for(int i=0;i<48;i++)
	{
		switch(i%8){
			case 0:
				printf("\n");
			case 1:
				printf("\n");
			case 2:
				printf("\n");
			case 3:
				printf("\n");
			case 4:
				printf("\n");
			case 5:
				printf("\n");
			case 6:
				printf("\n");
			case 7:
				printf("\n");
		}
	}
*/	
	return 0;
}
