#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    int fd[2];
    /**
     * 创建无名管道
     * 返回一个读文件描述符 fd[0]  
     * 返回一个写文件描述符 fd[1]
     * 
     */
    pipe(fd);
    pid_t pid = fork();
    if(pid > 0){
        // 父进程写管道，关闭读端
        close(fd[0]);
        int i = 0;
        for (i = 100; i <= 105; i++)
        {
            write(fd[1], &i, sizeof(int));
            printf("父进程写...\n");
            sleep(1);
        }
        // 关闭写端
        close(fd[1]);
        exit(0);
    }
    // 子进程读管道
    close(fd[1]); // 关闭写端
    int x;
    int i = 0;
    for (; i <= 5; i++)
    {
        read(fd[0],&x,sizeof(int));
        printf("子进程读：%d\n",x);
        setbuf(stdout,NULL);
    }
    close(fd[0]);
    printf("\n");
}