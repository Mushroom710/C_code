#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void main(){
    int fd;
    fd = open("open_test.txt",O_RDONLY | O_CREAT,740);
    if(fd == -1){
        perror("创建失败\n");
        return;
    }else{
        printf("创建成功\n");
    }
}