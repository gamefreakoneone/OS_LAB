#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

// Displays the contents in the file

main(int argc, char *argv[])
{
    int fd, i;
    char buf[2];
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
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