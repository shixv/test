#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
	chmod("dict.txt",S_IRWXU);
	chown("dict.txt",0,0);
	return 0;
}
