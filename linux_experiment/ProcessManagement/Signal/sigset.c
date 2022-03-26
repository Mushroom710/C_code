#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void alrm_run(int signo){
    printf("the signo is %d \n", signo);
}

int main(){
    signal(SIGALRM,alrm_run);
    alarm(5);
    int count = 1;
    while (1)
    {
        printf("count = %d \n", count++);
        sleep(1);
    }
    
    return 0;
}