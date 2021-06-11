#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int id;
    for (int i = 0; i < 10; i++)
    {
        id = fork();
        if(id==0){
            printf("id %d, pid %d, ppid %d \n", i, getpid(), getppid());
            exit(0);
        }else{
            wait();
        }
    }
    
    return 0;
}
