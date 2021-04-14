#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

main(int argc, char *argv[3])
{
    int fd,i;
    char buf[2]; // Creating a buffer
    fd = open(argv[1], O_RDONLY); // Opening a read only file
    if(fd==-1){
        printf("Error");
    }
    else{
        while ((i=read(fd, buf,1))>0)
        {
            printf("%c", buf[0]);
        }
        close(fd);
    }
}