/**
 * 这个文件包含一些队列的操作函数
 * 
 * 说明：队尾指针始终指向最后一个元素的后一个位置
 * 也就是预留一个空间不使用，这个空间就用来判断队列是否满、空的状态
*/
#include "QueueStruct.c"
#include "stdlib.h"

typedef int Status;
#define ok 1
#define overflow 0
#define false 0
#define true 1
#define error 0;

// 循环队列的初始化
Status InitQueue(SqQueue* q){
    //构造一个空队列
    //为队列分配一个最大容量为MAXSIZE的数组空间
    q->base = (QElemType *)malloc(sizeof(QElemType)*MAXSIZE);
    if(!q->base){
        exit(overflow); //空间分配失败
    }
    q->front = 0;
    q->rear = 0;//头尾指针置为零，队列为空
    return ok;
}

//返回队列的长度, 循环队列求长度
int QueueLength(SqQueue q){
    return (q.rear - q.front + MAXSIZE)%MAXSIZE;
}

// 入队操作
Status EnQueue(SqQueue* q,QElemType e){
    //插入元素e为q的新的队尾元素
    if((q->rear+1)%MAXSIZE == q->front){
        return error;
    }
    q->base[q->rear] = e;   //新元素入队
    q->rear = (q->rear + 1) % MAXSIZE; //队尾指针后移
    return ok;
}

//出队,取出队头元素，并返回其值
Status DeQueue(SqQueue* q,QElemType* e){
    if(q->front == q->rear){
        return error;//队列空
    }
    *e = q->base[q->front];//保存队头元素
    q->front = (q->front+1)%MAXSIZE;//队头指针后移
    return ok;
}

//去队头元素
QElemType GetHead(SqQueue q){
    //返回q的队头元素，不修改队头指针
    if(q.front != q.rear){//队列非空
        return q.base[q.front];
    }
}

Status IsEmpty(SqQueue q){
    return (q.front == q.rear);
}