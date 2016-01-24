#include <unistd.h>
#include <sys/ioctl.h>
int main(void)
{
	ioctl(tty_fd,KDSETLED,LED_NUM|LED_CAP|LED_SCR);
	return 0;
}


