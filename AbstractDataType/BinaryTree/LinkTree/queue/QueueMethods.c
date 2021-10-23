#include "stdlib.h"
#include "LinkQueueStruct.c"
//如果main那里出错的话，注释掉这行即可
// 这是给YangHuiTriQueue用的
#include "stdio.h"

typedef int Status;
#define ok 1
#define overflow 0
#define false 0
#define true 1
#define error 0;

// 初始化一个队列
Status InitQueue(LinkQueue* q){
    QNode *node = (QueuePtr)malloc(sizeof(QNode));
    q->front = node;
    q->rear = node;
    q->front->next = NULL;
    return ok;
}

//入队
Status EnQueue(LinkQueue* q,QElemType e){
    QNode *p = (QNode*)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return ok;
}

// 出队
Status DeQueue(LinkQueue* q,QElemType* e){
    // printf("%p,%p\n",q->front,q->rear);
    if (q->front == q->rear)
    {
        return error;
    }
    QNode* p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p){//最后一个结点被删除，之前少写了一个等号，导致一直出错
        q->rear = q->front;
    }
    free(p);
    return ok;
}

// 取链队头元素

QElemType GetHead(LinkQueue q){
    if(q.front != q.rear){
        return q.front->next->data;
    }
}

void ShowQueue(LinkQueue q){
    // printf("%p,%p\n", q.front, q.rear);
    QNode *p = q.front->next;
    if(!p){
        printf("队列空！\n");
    }
    while(p){
        printf("%d\n",p->data);
        p = p->next;
    }
    // printf("\nq.front->next->data：%d\n", q.front->next->data);
    // printf("q.rear->data：%d\n", q.rear->data);
}
// 获取队列的长度
int QueueSize(LinkQueue q){
    QNode *p = q.front->next;
    int i = 1;
    if(!p){
        return 0;
    }
    while (p != q.rear)
    {
        p = p->next;
        i++;
    }
    return i;
}