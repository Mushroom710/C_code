#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main(){
    int fd,i;
    char filename[10];
    for (i = 1; i <= 10; i++){
        sprintf(filename,"%d.dat",i);
        fd = open(filename,O_RDWR | O_CREAT,644);
        if(fd == -1){
            perror("打开失败\n");
            return;
        }
        int ssize = write(fd,&i,sizeof(int));
        if(ssize == -1){
            perror("写入失败\n");
            return;
        }
    }
}