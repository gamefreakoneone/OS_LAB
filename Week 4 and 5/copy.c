#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd1, fd2;
    int n;
    char buff[1024];
    fd1 = open(argv[1], O_RDONLY); 
    fd2 = open(argv[2], O_WRONLY | O_CREAT);
    n = read(fd1, buff, 1024);
    write(fd2, buff, n);
    return 0;
}
