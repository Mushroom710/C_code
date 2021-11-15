#include "Methods.c"
#include "stdio.h"
#include "string.h"

int k;

void main(){
    SString s;
    SString T;
    //最后一个字符是 \0 表示字符串结束
    char ch[] = " abababa";
    char t[] = " aba";
    s.length = strlen(ch);
    T.length = strlen(t);
    k = 0;
    //给SString 的ch[]数组赋值
    while (k<s.length)
    {
        s.ch[k] = ch[k];
        k++;
    }
    k = 0;
    while (k < T.length)
    {
        T.ch[k] = t[k];
        k++;
    }
    printf("%s\n",T.ch);
    int result = Index_BF(s, T, 0);
    printf("位置在：%d\n",result);
}