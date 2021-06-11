#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include<errno.h>
#include<sys/wait.h>
#include <unistd.h>

// who | wc –l

int main(int argc, char const *argv[])
{
    int a[2]; 
    pipe(a);

    if(!fork()){
        dup2(a[1],1); // Replacing STDINPUT
        close(a[0]); //CLOSING OUTPUT
        execlp("who","who",NULL);
    }else{
        dup2(a[0],0);
        close(a[1]);
        execlp("wc -l", "wc -l",NULL);
    }
    return 0;
}
