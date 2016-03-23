#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;
    // fd = open("hello.c", O_RDONLY);
    // 创建新文件 
//     fd = open("hello.c", O_RDONLY | O_CREAT, 0777);
    // 判断文件是否存在
//    fd = open("hello.c", O_RDONLY | O_CREAT | O_EXCL, 0777);
    
    // 文件截断为0 
    fd = open("aaa.c", O_WRONLY | O_TRUNC);
    printf("fd = %d\n", fd);
    if(fd == -1)
    {
        perror("file open:");
        exit(1);
    }
    int ret = close(fd);
    printf("close return value: %d\n", ret);
    return 0;
}
