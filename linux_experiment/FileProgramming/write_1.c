#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main(){
    int fd;
    fd = open("open_test.txt", O_RDWR);
    if(fd == -1){
        perror("打开失败\n");
        return;
    }else{
        int ssize = write(fd,"hello",5);
        if(ssize == -1){
            perror("写入失败\n");
            return;
        }else{
            printf("写入成功\n");
        }
    }
}