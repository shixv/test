#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "hehe"
#define BUFFER_SIZE PIPE_BUF
#define TEN_MEG (1024*1024*10)

int main(void)
{
	int pipe_fd;
	int res;
	int open_mode=O_WRONLY;
	int bytes_sent=0;
	char buffer[BUFFER_SIZE+1];
	if(access(FIFO_NAME,F_OK)==-1){
		res=mkfifo(FIFO_NAME,0777);
		if(res!=0){
			fprintf(stderr,"Could not create fifo %s\n",FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}
