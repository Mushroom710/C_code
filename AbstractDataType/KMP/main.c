#include "stdio.h"
#include "string.h"


void get_next(char ch[],int next[]){
    int i = 1;
    next[1] = 0;
    int j = 0;
    while(i<next[0]){
        if(j == 0 || ch[i] == ch[j]){
            i++;
            j++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}

void get_nextVal(char ch[],int nextVal[]){
    int i = 1;
    int j = 0;
    nextVal[1] = 0;
    while (i < nextVal[0])
    {
        if(j == 0 || ch[i] == ch[j]){
            i++;
            j++;
            if(ch[i] != ch[j]){
                nextVal[i] = j;
            }else{
                nextVal[i] = nextVal[j];
            }
        }else{
            j = nextVal[j];
        }
    }
    
}

void main(){
    //模式串从第一位开始比较，所以 ch[0] 无意义
    // char ch[] = " abcaabbabcab";
    char ch[] = " abcabaa";
    int len = strlen(ch);
    int next[len - 1];
    int nextVal[len - 1];
    int i;
    next[0] = len;
    nextVal[0] = len;
    get_next(ch, next);
    for (i = 0; i < len; i++)
    {
        printf("%d ", next[i]);
    }
    printf("\n");
    get_nextVal(ch,nextVal);
    for (i = 0; i < len; i++)
    {
        printf("%d ",nextVal[i]);
    }
}