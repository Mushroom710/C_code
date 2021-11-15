/**
 * 串的模式匹配算法
 * */ 
// 经典BF算法
#include "StringStruct.c"
#include "stdio.h"
int i,j;

int Index_BF(SString s,SString t,int pos){
    //返回模式t在主串中第pos个字符开始第一次出现的位置。若不存在，则返回值为0
    //t非空
    i = pos;
    j = 1;
    while (i<=s.length && j<=t.length) //两个串均未比较到末尾
    {
        if(s.ch[i] == t.ch[j]){//继续比较后继字符串
            printf("%c;%c\n",s.ch[i],t.ch[j]);
            i++;
            j++;

        }else{
            i = i - j + 2;//指针后退重新匹配
            j = 1;
        }
    }
    if(j>t.length){
        return i - t.length;//匹配成功
    }
    return 0;//匹配失败
}