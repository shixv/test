#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	int nread;
	int in,out;
	char block[1024];

	in = open("file.in",O_RDONLY);
	out = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	while((nread=read(in,block,sizeof(block)))>0)
		write(out,block,nread);

	exit(0);
}
