#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <string.h>

int main(int argc, char const *argv[])
{
    int bytes_written;
    int fd1, fd2;
    int n;
    char buff[4096];
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_WRONLY | O_APPEND); // importnat to mention O_WRONLY | O_APPEND
    n = read(fd1, buff, 4096);
    bytes_written = write(fd2, buff, n);
    printf("%d", bytes_written);
    return 0;
}
