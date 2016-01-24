#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024

void append(FILE *source,FILE *dest);

int main(int argc,char *argv[])
{
	if(argc<3)
		return 0;
	FILE *fs=(argv[1],"r");
	FILE *fa=(argv[2],"a");
	
}
