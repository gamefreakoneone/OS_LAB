#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    // fd[0] => Read
// fd[1] = > Write
    int fd[2];
    if(pipe(fd)==-1){
        printf("Error has occured!\n");
    }
    int id = fork();
    
    if(id==0){
        close(fd[0]);
        int x;
        printf("Input a number:\n");
        scanf("%d",&x);
        write(fd[1],&x,sizeof(int));
        close(fd[1]);
    }else{
        int y ;
        close(fd[1]);
        read(fd[0], &y, sizeof(int));
        close(fd[0]);
        printf("Got from child process %d \n",y);
    }
    return 0;
}
