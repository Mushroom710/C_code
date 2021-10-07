#include "stdio.h"
#include "StackMethods.c"

int key;
SqStack s;

int boo;
int value = 0;
int flag = false;

void Menu(){
    printf("\n1.构造一个空栈\n2.入栈\n3.出栈\n4.返回栈顶元素\n5.显示栈中的元素\n6.输入其他数退出\n");
    printf("请选择：");
}

void main(){
    Menu();
    for (;;)
    {
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            boo = InitStack(&s);
            if (boo)
            {
                printf("构造一个空栈成功\n");
            }
            else
            {
                printf("构造一个空栈失败\n");
            }
            printf("栈地址为：%p\n",&s);
            break;
        case 2:
            printf("请输入入栈元素：");
            scanf("%d",&value);
            boo = Push(&s, value);
            if(boo){
                printf("入栈成功\n");
            }else{
                printf("栈满，无法入栈\n");
            }
            break;
        case 3:
            boo = Pop(&s,&value);
            if (boo)
            {
                printf("出栈元素为：%d\n",value);
            }
            else
            {
                printf("栈空\n");
            }
            break;
        case 4:
            boo = GetTop(&s);
            if (boo)
            {
                printf("栈顶元素为：%d\n", boo);
            }
            else
            {
                printf("栈空\n");
            }
            break;
        case 5:
            StackShow(&s);
            break;
        default:
            flag = true;
            break;
        }
        if(flag){
            printf("flag");
            break;
        }
        Menu();
    }
    printf("退出。。\n");
}