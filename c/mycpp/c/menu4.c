#include <unistd.h>
#include <stdio.h>
#include <termios.h>


char *menu[]={
	
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL,
};
int getchoice(char *greet,char *choices[],FILE *in,FILE *out);
int main(void)
{
	int choice = 0;
	FILE *input,*output;
	struct termios initial_settings,new_settings;
	if(!isatty(fileno(stdout))){
		fprintf(stderr,"You are not a terminal!\n");
		return 1;
	}
	input = fopen("/dev/tty","r");
	output = fopen("/dev/tty","w");
	if(!input||!output){
		fprintf(stderr,"Unable to open /dev/tty\n");
		return 1;
	}
	tcgetattr(fileno(input),&initial_settings);
	new_settings = initial_settings;
	new_settings.c_lflag&=~ICANON;
	new_settings.c_lflag&=~ECHO;
	new_settings.c_lflag&=~ISIG;
	new_settings.c_cc[VMIN]=1;
	new_settings.c_cc[VTIME]=0;
	if(tcsetattr(fileno(input),TCSANOW,&new_settings)!=0)
	{
		fprintf(stderr,"could not set attributes\n");
	}
	do
	{
		choice = getchoice("Please select an action",menu,input,output);
		printf("You have chosen: %c\n",choice);
	}while(choice!='q');
	tcsetattr(fileno(input),TCSANOW,&initial_settings);
	return 0;
}
int getchoice(char *greet,char *choices[],FILE *in,FILE *out)
{
	int chosen = 0;
	int selected;
	char **option;
	do{
		fprintf(out,"Choice: %s\n",greet);
		option=choices;
		while(*option){
			fprintf(out,"%s\n",*option);
			option++;
		}
		do
		{
	    	selected=fgetc(in);
		}while(selected=='\n'||selected=='\r');
		option=choices;
		while(*option){
			if(selected==*option[0]){
				chosen=1;
				break;
			}
			option++;
		}
		if(!chosen){
			fprintf(out,"Incorret choice, select again\n");
		}
	}while(!chosen);
	return selected;
}
