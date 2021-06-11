#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
    execlp("ls","ls", "-l", NULL);
    return 0;
}