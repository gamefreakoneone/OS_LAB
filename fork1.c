#include<stdio.h>

main(){
int id;
id=fork();
if(id==0){
printf("pid of child is %d and its pis is %d",getpid(),getppid());
}else{
printf("pid of parent is %d and its pis is %d",getpid(),getppid());
}
}
