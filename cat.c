#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

main(int argc, char *argv[3])
{
    int fd, i;
    char buf[2]; // Creating a buffer where I am storing in the characters
    fd = open(argv[1], O_RDONLY, 0777); //read only
    if (fd == -argc)
    {
        printf("file open error");
    }
    else
    {
        while ((i = read(fd, buf, 1)) > 0)
        {
            printf("%c", buf[0]);
        }
    close(fd);
    }
}