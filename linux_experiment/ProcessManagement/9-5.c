#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(){
    int p1, p2;
    while((p1 = fork()) == -1){ // 一直创建子进程，直到成功
        ;
    }
    if(p1 == 0){ // 子进程返回
		printf("子进程 p1 b \n");
    }else{
        while ((p2 = fork()) == -1)
            ;
        if(p2 == 0){
			printf("子进程 p2 c \n");
        }
        else{
			printf("父进程 a \n");
        }
    }
}
