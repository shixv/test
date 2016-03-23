#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
    int fd;
    fd = open("hello.c", O_RDONLY);
    printf("fd = %d\n", fd);

    // 使用read 读数据
    char buf[1024] = {0};
    int ret = read(fd, buf, 10);
    printf("ret = %d\n", ret);
    printf("read buf date = %s\n", buf);

    // 使用write 写数据
    int fd1;
    fd1 = open("a.c", O_WRONLY);
    printf("fd1 = %d\n", fd1);
    int ret1 = write(fd1, buf, strlen(buf));
    printf("ret1 = %d\n", ret1);


    ret = close(fd);
    printf("clsoe return value: %d\n", ret);

    return 0;
}
