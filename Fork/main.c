#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    if (fork() && fork())
    {
        fork();
    }
    if (fork() || fork())
    {
        fork();
    }
    printf("Sessional");
}
