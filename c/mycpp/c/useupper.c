#include <unistd.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
	char *filename;

	if(argc!=2)
	{
		fprintf(stderr,"useage: upper file\n");
		return 1;
	}
	filename=argv[1];
	if(!freopen(filename,"r",stdin))
	{
		fprintf(stderr,"could not redirect stdin from file %s\n",filename);
		return 2;
	}
	execl("./upper","upper",0);
	perror("could not exec ./upper\n");
	return 3;
}
