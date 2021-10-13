#include "stdio.h"
#include "Methods.c"

int key;
LinkQueue q;
int state;
int value;
int flag = false; //标记，用于判断是否退出程序

void Menu(){
    printf("\n1.初始化队列\n2.入队\n3.出队\n4.取队头元素\n6.输入其他数退出\n");
    printf("请选择：");
}

void main(){
    Menu();
    for (;;)
    {
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            state = InitQueue(&q);
            if(state){
                printf("队列初始化成功！！！\n");
            }else{
                printf("队列初始化失败！！！\n");
            }
            break;
        case 2:
            printf("\n请输入 入队元素：");
            scanf("%d",&value);
            state = EnQueue(&q,value);
            if (state)
            {
                printf("入队成功！！！\n");
            }
            else
            {
                printf("入队失败！！！\n");
            }
            break;
        case 3:
            state = DeQueue(&q,&value);
            // printf("state的值：%d\n",state);
            if (!state)
            {
                printf("队列空！！！\n");
            }
            else
            {
                printf("出队元素：%d\n",value);
            }
            break;
        case 4:
            if(q.front != q.rear){  
                printf("队头元素为：%d\n",GetHead(q));
            }else{
                printf("队列空...\n");
            }
            break;
        case 5:
            // printf("队列长度为：%d\n",QueueLength(q));
            break;
        default:
            flag = true;
            break;
        }
        if(flag){
            printf("退出程序...\n");
            break;
        }
        Menu();
    }
}