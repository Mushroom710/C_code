#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    pid_t pid;
    int count = 0;
    pid = vfork();

    if(pid == 0){
        count++;
        printf("count = %d \n",count);
        exit(0);
    }else{
        count++;
        printf("count = %d \n",count);
        return 0;
    }
}