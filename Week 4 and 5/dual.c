#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
    if ( argc == 1 || argc == 2){
        printf("Executing wc < f1 > f2");
    }else{
        int outfd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        dup2(outfd, 1);
        close(outfd);
        int fd = open(argv[1], O_CREAT | O_WRONLY);
        execlp("wc","wc",argv[1],0);
    }
    return 0;
}
