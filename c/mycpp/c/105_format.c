#include <stdio.h>
#define MAX 20

int main(void)
{
	char first[MAX];
	char last[MAX];
	char formal[2*MAX+10];
	double prize;
	
	puts("Enter your first name: \n");
	gets(first);
	puts("Enter your last name: \n");
	gets(last);
	puts("Enter your prize money: \n");
	scanf("%lf",&prize);
	sprintf(formal,"%s %-19s: $%6.2f\n",last,first,prize);
	puts(formal);
	
	return 0;
}