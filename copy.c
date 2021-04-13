#include<fcntl.h>

int main(int argc, char **argv[])
{
    int fd1, fd2;
    int n;
    char buff[1024];
    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2], O_WRONLY| O_CREAT,0744);
    n= read(fd1,buff,1024);
    write(fd2, buff,n);
    return 0;
}
