#include "stdio.h"
#include "queue/QueueMethods.c"

//这是二叉树的构造函数
// 用于初始化左右子节点
void Construction(BiTree root, BiTNode *lchild, BiTNode *rchild)
{
    root->lchild = lchild;
    root->rchild = rchild;
    lchild->lchild = NULL;
    rchild->rchild = NULL;
}

// 先序遍历-递归
void PreTraverse(BiTree root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        PreTraverse(root->lchild);
        PreTraverse(root->rchild);
    }
}
// 中序遍历-递归
void InOrderTraverse(BiTree root)
{
    if (root != NULL)
    {
        InOrderTraverse(root->lchild);
        printf("%d\t", root->data);
        InOrderTraverse(root->rchild);
    }
}
// 后序遍历-递归
void AfterTraverse(BiTree root)
{
    if (root != NULL)
    {
        AfterTraverse(root->lchild);
        AfterTraverse(root->rchild);
        printf("%d\t", root->data);
    }
}

// 层序遍历
LinkQueue queue;
void SequenceTraversal(BiTree root)
{
    InitQueue(&queue);
    EnQueue(&queue, root);
    // 外层循环是二叉树的层数
    while (queue.front != queue.rear)
    {
        // 记录当前队列的大小
        int size = QueueSize(queue);
        int i = 0;
        // 遍历这一层的结点
        for (; i < size;i++)
        {
            // 取出队列的第一个元素并打印
            BiTNode *node;
            DeQueue(&queue,&node);
            printf("%d\t",node->data);
            // 判断这个结点的左子树是否空，若非空，就加入队列
            if(node->lchild != NULL){
                EnQueue(&queue,node->lchild);
            }
            // 判断这个结点的右子树是否空，若非空，就加入队列
            if(node->rchild != NULL){
                EnQueue(&queue,node->rchild);
            }
        }
    }
}

// 前序创建一颗二叉树
/**
 * 说明：以字符 0 作为子树的结束
 * 每一次读入一个字符
 * 二叉树字符序列如：123004506007000
 * 按先序次序输入二叉树中结点的值（单个字符），创建二叉树
 * */ 
void PreCreateTree(BiTree* root){
    int val;
    printf("读入字符(输入0表示当前子树结束)：");
    scanf("%d", &val);
    if(val == 0){//递归结束，建立空树
        *root = NULL;
    }else{
        (*root) = (BiTNode *)malloc(sizeof(BiTNode));//生成当前子树的根结点
        // **root->data = val;
        (*root)->data = val;
        PreCreateTree(&(*root)->lchild);
        PreCreateTree(&(*root)->rchild);
    }
}