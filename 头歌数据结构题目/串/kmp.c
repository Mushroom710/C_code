#include <stdio.h>
#include <string.h>
void Next(char *T, int *next)
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while (i < strlen(T))
    {
        if (j == 0 || T[i - 1] == T[j - 1])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}
int KMP(char *S, char *T)
{
    /** 实现KMP算法， 若匹配返回匹配字符串长度，若不匹配返回 -1 **/

    /*************** begin *******************/
    int len = strlen(T);

    int next[len];
    Next(T,next);
    int i = 0;
    int j = 0;
    while(i<strlen(S) && j < strlen(T)){
        if(j == 0 || *(S+i) == *(T+j)){
            printf("%d\n",j);
            printf("%c-%c\n",*(S+i),*(T+j));
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j > strlen(T)-1){
        return i - strlen(T) + 1;
    }else{
        return 0;
    }
    /*************** end *********************/
}
int main()
{

    char a[1000], b[100];
    scanf("%s %s", a, b);
    int i = KMP(a, b);
    printf("%d", i);
    return 0;
}