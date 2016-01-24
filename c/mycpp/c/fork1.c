#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	char *message;
	int n;

	printf("fork progam starting\n");
	pid=fork();
	switch(pid)
	{
		case -1:
			perror("fork failed");
			return 1;
		case 0:
			message="tis is the chiled\n";
			n=5;
			break;
		default:
			message="this is the parents\n";
			n=3;
			break;
	}
	for(;n>0;n--)
	{
		puts(message);
		sleep(1);
	}
	return 0;

}
