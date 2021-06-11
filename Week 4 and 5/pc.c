#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    if(fork()==0){
        printf("Chid id is %d, parent id is %d\n", getpid(), getppid());
    }else
    {
        printf("Parent id is %d\n", getpid());
    }
    
    return 0;
}
