#include <stdio.h>
#include <string.h>
//串普通模式匹配算法的实现函数，其中 B是伪主串，A是伪子串

int mate(char *B, char *A)
{
    /** 请在此处填写代码 **/
    /********** Begin *********/
    int number = 0;
    int i = 0;
    int j = 0;
    while (i < strlen(B) && j < strlen(A))
    {
        if(*(B+i) == *(A+j)){
            printf("%d\n",j);
            printf("%c=%c\n",*(B+i),*(A+j));
            i++;
            j++;
        }else{
            i = i - j + 2;
            j = 1;
        }
    }
    printf("%d=%d\n",strlen(A),strlen(B));
    if (j > strlen(A)-1)
    {
        return i - strlen(A);
    }
    else
    {
        return 0;
    }

    /********** End **********/
}
int main()
{
    int number = mate("ababcabcacbab", "abcac");
    printf("%d", number);
    return 0;
}