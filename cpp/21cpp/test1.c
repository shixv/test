#include <stdio.h>
#include <syslog.h>
#include <limits.h>
#include <time.h>
#include <sys/resource.h>
int main(void)
{
//	syslog(LOG_EMERG,"\m-hhe");
//	printf("%m\n");
//	printf("%ld\n",NAME_SIZE);
	printf("%d\n",CHAR_BIT);
	printf("%d\n",INT_MAX);
	printf("%d\n",RLIMIT_CORE);
	printf("%d\n",RLIMIT_CPU);
	return 0;
}
