#include "stdlib.h"
#include "LinkQueueStruct.c"

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
    if(q->front == q->rear){
        return error;
    }
    QueuePtr p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear = p){//最后一个结点被删除
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