// 这里需要写绝对路径（艹）
#include "G:\C_code\AbstractDataType\BinaryTree\LinkTree\BinaryTreeStruct.c"

// 需要什么类型，直接改成对应的类型即可
typedef BiTNode* QElemType;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;