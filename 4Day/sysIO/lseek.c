#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    fd = open("hello.c", O_RDWR);
    if(fd == -1)
    {
        perror("file open:");
        exit(1);
    }
    
    // 获取文件的长度
    int fileLen = lseek(fd, 0, SEEK_END);
    printf("fileLen = %d\n", fileLen);
    // 获取文件指针当前的位置
    int pos = lseek(fd, 0, SEEK_CUR);
    printf("pos = %d\n", pos);
    
    // 从头部移动文件指针
    int ret = lseek(fd, 10, SEEK_SET);
    char buf[1024] = {0};
    ret = read(fd, buf, 100);
    printf("ret = %d, buf = %s\n", ret, buf);


    // 文件拓展
    ret = lseek(fd, 500, SEEK_CUR);
    // 想完成拓展，必须进行一次写操作
    write(fd, "a", 1);
    close(fd);

    return 0;
}

