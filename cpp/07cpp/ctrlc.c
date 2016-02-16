#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int sig)
{
	printf("Ouch! - I got signal %d\n",sig);
	(void)signal(SIGINT,SIG_DFL);
}

int main(void)
{
	(void)signal(SIGINT,ouch);

	while(1)
	{
		printf("Hello World!\n");
		sleep(1);
	}
	return 0;
}
