#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void at(void){
    printf("这句话在进程结束前会打印出来\n");
}

void main(){
    atexit(at); // 注册进程结束时要调用的函数
    sleep(5);
    printf("开始退出进程...\n");
    sleep(5);
    exit(0);
    printf("这句话不会被打印出来\n");
}