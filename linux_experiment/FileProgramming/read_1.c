#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void main(){
    int fd, i, j;
    char filename[10];
    for (i = 1; i <= 10; i++){
        sprintf(filename,"%d.dat",i);
        fd = open(filename,O_RDWR);
        if(fd == -1){
            perror("打开文件失败\n");
            return;
        }
        read(fd,&j,sizeof(int));
        printf("%d\n",j);
    }
}