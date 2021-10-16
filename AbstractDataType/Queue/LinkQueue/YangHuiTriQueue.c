#include "Methods.c"
#include "stdio.h"

void main(){
    LinkQueue q;
    int i,j,temp,n;
    InitQueue(&q);
    EnQueue(&q,1);
    printf("打印几层：");
    scanf("%d", &n);
    printf("\n");
    //i定义为 第一层，不从零 开始
    for (i = 1; i <= n;i++)
    {
        EnQueue(&q,1);
        //因为每一层有两个一是不需要计算的，直接入队即可，所以除去这两个一
        for (j = 0; j <= i - 2;j++)
        {
            DeQueue(&q,&temp);//出队
            printf("%d\t",temp);
            EnQueue(&q,temp+GetHead(q));
        }
        EnQueue(&q, 1);
        DeQueue(&q, &temp);
        printf("%d\t", temp);
        printf("\n");
    }
}