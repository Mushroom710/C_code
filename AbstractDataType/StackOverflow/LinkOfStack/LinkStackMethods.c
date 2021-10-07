#include "LinkStackStruct.c"
#include "stdlib.h"

#define true 1
#define false 0
#define ok 1
#define error 0

typedef int Status;

//链栈初始化，不需要头结点
Status InitStack(LinkStack* s){
    //构造一个空栈，栈顶指针置为空
    *s = NULL;
    return ok;
}

//链栈入栈
Status Push(LinkStack* s,SElemType e){
    //在栈顶插入元素e
    //动态分配一个结点空间
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    p->data = e;    //新结点数据域赋值为e
    p->next = *s;    //新结点插入栈顶
    *s = p;          //修改栈顶指针为p
    return ok;
}

//链栈出栈
Status Pop(LinkStack* s,SElemType* e){
    //删除s栈顶元素，用e返回其值
    if(*s == NULL){
        return error;//链栈为空
    }
    *e = (*s)->data; //用e接收栈顶的值
    StackNode *temp = *s; //用一个临时结点保存栈顶元素空间，以便释放
    *s = (*s)->next; //修改栈顶指针
    free(temp); //释放原来的栈顶元素空间
    return ok;
}

// 取栈顶元素
SElemType GetTop(LinkStack* s){
    //返回栈顶元素，不修改栈顶指针
    // if(s==NULL){ //栈非空
    //     printf("栈空...\n");
    // }else{
    //     return s->data; //返回栈顶元素
    // }
    if((*s)!=NULL){
        return (*s)->data;
    }
}

//显示链栈
void Show(LinkStack* s){
    if(*s == NULL){
        printf("栈空....\n");
        return;
    }
    LinkStack p = *s;
    while (p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}