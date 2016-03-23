#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char* argv[])
{
    int fd=open(argv[1],O_RDONLY|O_CREAT);
    int ch=0;
    while(read(fd,(void*)&ch,1)==1)
        write(1,(const void *)&ch,1);
    close(fd);
    return 0;
}
