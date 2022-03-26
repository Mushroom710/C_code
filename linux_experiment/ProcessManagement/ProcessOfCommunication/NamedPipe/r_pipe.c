#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    // 读打开管道
    int fd = open("pipe", O_RDONLY);
    if(fd == -1){
        printf("读 打开管道失败\n");
        return -1;
    }
    int i = 0;
    int num = 0;
    for (i = 0; i < 50; i++){
        read(fd,&num,sizeof(int));
        printf("%d\n",num);
        fflush(stdout);
        // setbuf(stdout, NULL);
    }

    printf("\n");
    // 关闭管道
    close(fd);
}