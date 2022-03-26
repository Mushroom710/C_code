#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void main(){
    int fd;
    fd = open("open_test.txt",O_RDWR);
    if(fd == -1){
        perror("打开失败\n");
    }else{
        printf("打开成功\n");
    }
}