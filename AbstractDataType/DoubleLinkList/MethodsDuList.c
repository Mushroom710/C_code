#include "StructDulLinkList.c"
#include "stdlib.h"
#include "stdio.h"
/**
 * 定义一些状态码
 * */ 

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;
int MAXSIZE = 5;//构造一个多长的链表
int value;//保存一些临时值
DuLinkList fp;
/**
 * 初始化一个有头结点的双向链表
 * */

DuLinkList Init(DuLinkList dul){
    dul = (DuLNode *)malloc(sizeof(DuLNode));
    dul->data = 65535;//头结点的数据初始化为一个不可能的数
    dul->prior = dul;
    dul->next = dul;
    printf("初始化成功...\n");
    return dul;
}

/**
 * 默认构造一个双向链表
 * */ 
void DefaultDu(DuLinkList dul){
    printf("进入Default...\n");
    printf("构建链表中....\n");
    DuLinkList pre = dul; //头指针不能动，用一个辅助指针
    // int a;//一个随机数
    int i;//循环次数
    srand((unsigned)time(0)); //每次使用不同的随机数种子
    for (i = 0; i < MAXSIZE;i++)
    {
        DuLNode *p = (DuLNode *)malloc(sizeof(DuLNode));
        p->data = rand()%100;
        pre->next = p;
        p->prior = pre;
        pre = pre->next;
        pre->next = NULL;
    }
    dul->prior = pre;
    pre->next = dul;
    printf("构建链表成功....\n");
}

/**
 * 获取第 i 个节点的位置
*/
DuLinkList GetElem(DuLinkList dul,int i){
    if(i<1){
        printf("插入位置不合法。。。\n");
        return NULL;
    }
    DuLinkList temp = dul->next;
    int k = 0;
    while (temp != dul && k < i - 1)
    {
        temp = temp->next;
        printf("%d\n",k);
        k++;
    }
    if(temp == dul || k>i-1){
        printf("没有这个位置。。\n");
        return NULL;
    }
    return temp;
}

/**
 * 插入操作
 * */ 

void DulInsert(DuLinkList dul,int i,ElemType e){
    if(!(fp = GetElem(dul,i))){
        return;
    }
    DuLNode *newNode = (DuLNode *)malloc(sizeof(DuLNode));
    newNode->data = e;
    newNode->prior = fp->prior;
    newNode->next = fp;
    fp->prior = newNode;
    newNode->prior->next = newNode;
    printf("插入成功...\n");
}

/**
 * 删除一个结点
 * */ 
void DeleteNode(DuLinkList dul,int i){
    if(!(fp = GetElem(dul,i))){
        return;
    }
    printf("你删除了数据为 %d 的结点\n",fp->data);
    DuLinkList temp = fp;
    fp->prior->next = fp->next;
    fp->next->prior = fp->prior;
    free(temp);
    printf("删除成功。。\n");
}

/**
 * 显示双向链表
 * */ 

void Show(DuLinkList dul){
    if(dul == NULL || dul->next == dul){
        printf("没有数据");
    }
    printf("显示链表：\n");
    DuLinkList cur = dul->next;
    while (cur != dul)
    {
        printf("%d\t",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

/**
 * 清空双向链表
*/

void ClearDuList(DuLinkList dul){
    fp = dul->next;
    fp->prior

}