#include "stdio.h"
#include "LinkStackMethods.c"

//疑问：
/**
 * 为甚么一级指针就不行
 * 而二级指针就可以解决问题
 * LinkStack : StackNode*
 * 函数参数：LinkStack* s;
 * 
 * 一级指针参数：LinkStack s;
 * */

int key;
SElemType value;
LinkStack s;
int flag;
Status boo;

void Menu(){
    printf("\n1.初始化一个链栈\n2.入栈操作\n3.出栈操作\n4.取栈顶元素\n5.显示链栈\ndefault.键入其他数退出程序\n");
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
            boo = InitStack(&s);
            if(boo){
                printf("链栈初始化成功....\n");
            }else{
                printf("链栈初始化失败....\n");
            }
            printf("%p\n",&s);
            break;
        case 2:
            printf("请输入入栈的元素：");
            scanf("%d",&value);
            printf("%d\n",value);
            boo = Push(&s, value);
            if(boo){
                printf("入栈成功...\n");
            }else{
                printf("入栈出错...\n");
            }
            break;
        case 3:
            boo = Pop(&s,&value);
            if(boo){
                printf("出栈元素是：%d\n",value);
            }else{
                printf("栈空...\n");
            }
            // printf("%p\n",&s);
            break;
        case 4:
            value = GetTop(&s);
            if(value){
                printf("栈顶元素是：%d\n",value);
            }else{
                printf("栈空...\n");
            }
            break;
        case 5:
            Show(&s);
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