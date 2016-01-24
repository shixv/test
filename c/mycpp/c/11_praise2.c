#include <stdio.h>
#include <string.h>
#define PRAISE "What a super marvelous name! "

int main(void)
{
	char name[40];
	
	printf("What is your name?\n");
	scanf("%s",name);
	printf("Hello, %s. %s\n",name,PRAISE);
	printf("Your name of %d letters occupies %d memory cell.\n",strlen(name),sizeof name);
	printf("The phrase of prise has %d letters",strlen(PRAISE));
	printf("and occupies %d memory cell.\n",sizeof PRAISE);
	return 0;
}
