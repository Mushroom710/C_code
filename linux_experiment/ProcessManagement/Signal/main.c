#include <stdio.h>
#include <stdlib.h>

void main(){
    int i = 10;
    while (i--)
    {
        printf("i = %d \n",i);
        sleep(1);
        if(i == 6){
            int j = i / 0;
            exit(1);
        }
    }
}