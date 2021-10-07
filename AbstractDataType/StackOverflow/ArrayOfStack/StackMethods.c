#include "StackStruct.c"
#include "stdlib.h"

#define true 1
#define false 0
#define overflow 0
#define ok 1
#define error 0

typedef int Status;

//栈的初始化，构造一个空栈
Status InitStack(SqStack *s)
{
    //分配MAXSIZE大小的空间
    s->base = (SELemType *)malloc(sizeof(SELemType) * MAXSIZE);
    if (s->base == NULL)
    {
        printf("exit");
        exit(overflow); //分配失败
    }
    s->top = s->base;
    s->stacksize = MAXSIZE;
    return ok;
}

//判断栈是否满
Status isFull(SqStack *s)
{
    if (s->top - s->base == s->stacksize)
    {
        return error; //栈满
    }
    else
    {
        return ok; //栈未满
    }
}
//判断是否空
Status iSEmpty(SqStack *s)
{
    if (s->top == s->base)
    { //栈是否空的判定
        return error;
    }
    return ok;
}

//入栈
Status Push(SqStack *s, SELemType e)
{
    //插入元素e成为新的栈顶元素
    if (!isFull(s))
    {
        return error; //栈满
    }
    *s->top = e;
    *s->top++;
    return ok;
}

//出栈
Status Pop(SqStack *s, SELemType *e)
{
    //删除栈顶元素，并返回其值
    if (!iSEmpty(s))
    {
        return error; //栈空
    }
    *s->top--;
    *e = *s->top;
    return ok;
}

//取栈顶元素
static GetTop(SqStack *s)
{
    if (iSEmpty(s))
    {
        return *(s->top - 1); //返回栈顶元素，栈顶指针不变
    }
    else
    {
        return error; //栈空
    }
}

void StackShow(SqStack *s)
{
    if (!iSEmpty(s))
    {
        printf("栈空了...\n");
        return;
    }
    printf("从栈顶到栈底的元素为：\n");
    SELemType *p = s->top - 1;
    while (p >= s->base)
    {
        printf("%d\n", *p);
        p--;
    }
}