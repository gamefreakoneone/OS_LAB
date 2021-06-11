#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    pid=fork();
    if(pid==0){
        sleep(30);
        printf("In child process\n");
    }else{
        printf("In parent process");
    }
    return 0;
}