#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void main(){
    int pid;
    pid = fork();
    if (pid < 0)
    {
        printf("error in fork\n");
        return;
    }
    else if (pid == 0)
    {
        printf("i am child process\n");
    }
    else
    {
        printf("i am parent process\n");
    }
}