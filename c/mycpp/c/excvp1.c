#include <unistd.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
	char *const ps_argv[]={
		"cat",
		"test.c",
		0
	};
	char *const ps_envp[]={
		"PATH=/bin:/usr/bin",
		"TERM=xterm",
		0
	};
//	execl("/bin/cat","cat","test.c",0);
	execlp("cat","cat","test.c",0);
	execle("/bin/cat","cat","test.c",0,ps_envp);

	execv("/bin/cat",ps_argv);
	execvp("cat",ps_argv);
	execve("/bin/cat",ps_argv,ps_envp);
	return 0;

}
