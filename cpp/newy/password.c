#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN 8

int main(void)
{
	struct termios initialrsettings,newrsettings;
	char password[LEN+1];
	tcgetattr(fileno(stdin),&initialrsettings);
	newrsettings=initialrsettings;
	newrsettings.c_lflag&=~ECHO;

	printf("Enter password: ");

	if(tcsetattr(fileno(stdin),TCSAFLUSH,&newrsettings)!=0){
		fprintf(stderr,"Could not set attributes\n");
	}
	else{
		fgets(password,LEN,stdin);
		tcsetattr(fileno(stdin),TCSANOW,&initialrsettings);
		fprintf(stdout,"\nYou entered %s\n",password);
	}
	exit(0);
}
