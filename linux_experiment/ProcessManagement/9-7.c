#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(){
    int p1;
    printf("父子进程共享的部分 x \n");
    while((p1 = fork()) == -1){
        ;
    }
    if(p1 == 0){
        printf("子进程输出 b \n");
        exit(0);
    }else{
        printf("父进程输出 a \n");
    }
    printf("父子进程共享的部分 y \n");
}