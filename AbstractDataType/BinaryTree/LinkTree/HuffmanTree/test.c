#include "stdio.h"

// 这是找出一个数组中较小的两个数
void main(){
    int a[7] = {1,2,3,4,5,6,7};
    int s1;
    int s2;
    if(a[0]<a[1]){
        s1 = a[0];
    }
    s2 = a[1];

    int i = 2;
    for(;i<7;i++){
        if(s1 > a[i]){
            s2 = s1;
            s1 = a[i];
        }else if(s2 > a[i]){
            s2 = a[i];
        }
    }
    printf("\n%d --- %d",s1,s2);
}