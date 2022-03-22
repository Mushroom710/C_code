
// 队列的链接存储实现文件。
// 采用循环链表，具有附加头节点，使用尾结点指针。
// CLQ_   Circularly Linked Queue
////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "struct.cpp"

LNode *CLQ_Create()
// 创建一个队列。
{
    LNode *rear = (LNode *)malloc(sizeof(LNode));
    rear->data = 0;
    rear->next = rear;
    return rear;
}
void CLQ_Free(LNode *rear)
// rear指向尾结点。
{
    CLQ_MakeEmpty(rear);
    free(rear);
}

void CLQ_MakeEmpty(LNode *rear)
// rear指向尾结点。
// 将队列变为空队列。
{
    T item;
    while (!CLQ_IsEmpty(rear))
        CLQ_Out(rear, item);
}

bool CLQ_IsEmpty(LNode *rear)
// 判断队列是否为空。
{
    // 请在Begin-End之间补充代码，完成队列是否为空的判断。
    /********** Begin *********/
    if (rear->next == rear)
    {
        return true;
    }
    return false;

    /********** End **********/
}

int CLQ_Length(LNode *rear)
// 返回队列长度，rear指向尾结点。
{
    // 请在Begin-End之间补充代码，获取队列长度。
    /********** Begin *********/
    if (rear->next == rear)
    {
        return 0;
    }
    LNode *head = rear->next->next;
    int count = 1;
    while (head != rear)
    {
        head = head->next;
        count++;
    }
    return count + 1;

    /********** End **********/
}

void CLQ_In(LNode *&rear, T x)
// 入队列, 新结点加入链表尾部。rear指向尾结点。
{
    // 请在Begin-End之间补充代码，完成新结点入队操作。
    /********** Begin *********/
    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    tmp->data = x;
    rear->next = tmp;
    tmp->next = rear;
    rear = rear->next;

    /********** End **********/
}

bool CLQ_Out(LNode *&rear, T &item)
// 出队列。空队列时，返回值为false。rear指向尾结点。
{
    // 请在Begin-End之间补充代码，完成结点出队操作。
    /********** Begin *********/
    if (rear->next == rear)
    {
        return false;
    }
    LNode *head = rear->next;
    LNode *tmp = head->next;
    item = head->next->data;
    head->next = tmp->next;
    free(tmp);
    return true;

    /********** End **********/
}

bool CLQ_Head(LNode *rear, T &item)
// rear指向尾结点。
// 获取队列头。空队列时返回值为false。
{
    if (CLQ_IsEmpty(rear))
        return false;

    item = rear->next->next->data;
    return true;
}
void CLQ_Print(LNode *rear)
// 打印队列。
{
    if (CLQ_IsEmpty(rear))
    {
        printf("The queue is: empty. \n");
        return;
    }
    LNode *node = rear->next->next;
    do
    {
        printf("%d  ", node->data);
        node = node->next;
    } while (node != rear->next);
    //printf("\n");
}
