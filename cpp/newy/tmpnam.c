#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char tmpname[L_tmpnam];
	char *filename;
	FILE *tmpfp;

	filename=tmpnam(tmpname);

	printf("Temporary file name is: %s\n",filename);
	tmpfp=tmpfile();
	if(tmpfp)
		printf("Opened a tmporary file OK\n");
	else
		perror("tmpfile");
	exit(0);
}
