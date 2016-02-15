#include <unistd.h>

int main(void)
{
	char buff[64]={0};
	write(1,getcwd(buff,64),64);
	write(1,"\n",1);
	return 0;
}
