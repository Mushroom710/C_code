#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    // 创建管道
    if(mkfifo("pipe",0666) < 0){
        printf("管道创建失败\n");
        return -1;
    }

    // 写 打开管道
    int fd = open("pipe", O_WRONLY);
    if(fd == -1){
        printf("写 打开管道失败\n");
        return -1;
    }

    unlink("pipe");

    int i = 0;
    for (i = 50; i < 100; i++)
    {
        write(fd,&i,sizeof(int));
        printf("%d\n",i);
        sleep(1);
    }

    // 关闭管道
    close(fd);
}