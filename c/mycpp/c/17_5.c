#include <stdio.h>
#define BOOK "War and Peace"

int main(void)
{
	float cost = 12.99;
	float percent = 80.0;
	printf("This copy of %s sell for $%.2f.\nThat is %.0f%% of list.\n",BOOK,cost,percent);
	return 0;
}
