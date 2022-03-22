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
        for (; i < size; i++)
        {
            // 取出队列的第一个元素并打印
            BiTNode *node;
            DeQueue(&queue, &node);
            printf("%d\t", node->data);
            // 判断这个结点的左子树是否空，若非空，就加入队列
            if (node->lchild != NULL)
            {
                EnQueue(&queue, node->lchild);
            }
            // 判断这个结点的右子树是否空，若非空，就加入队列
            if (node->rchild != NULL)
            {
                EnQueue(&queue, node->rchild);
            }
        }
    }
}

/**
 * @brief BFS
 * 广度优先搜索
 * 搜索二叉树中与传入的data相同的结点所在的层数
 * @param root 二叉树
 * @param data 待搜索的数据
 */
void BFS(BiTree root,int data)
{
    InitQueue(&queue);//初始化一个队列
    EnQueue(&queue, root);//root入队
    int ceng = 1;//记录遍历到哪一层
    // 外层循环是二叉树的层数
    while (queue.front != queue.rear)
    {
        // 记录当前队列的大小
        int size = QueueSize(queue);
        int i = 0;
        BiTNode *node;
        // 遍历这一层的结点
        for (; i < size; i++)
        {
            // 取出队列的第一个元素并与data比较，若比较成功，则打印所在的层数，并return
            DeQueue(&queue, &node);
            if(node->data == data){
                printf("结点在第 %d 层,data=%d,在该层第 %d 位置处\n", ceng,node->data,i+1);
                return;
            }
            // 判断这个结点的左子树是否空，若非空，就加入队列
            if (node->lchild != NULL)
            {
                EnQueue(&queue, node->lchild);
            }
            // 判断这个结点的右子树是否空，若非空，就加入队列
            if (node->rchild != NULL)
            {
                EnQueue(&queue, node->rchild);
            }
        }
        ceng++;//for遍历完后，层数加一
    }
}

// 前序创建一颗二叉树
/**
 * 说明：以字符 0 作为子树的结束
 * 每一次读入一个字符
 * 二叉树字符序列如：123004506007000
 * 按先序次序输入二叉树中结点的值（单个字符），创建二叉树
 * */
void PreCreateTree(BiTree *root)
{
    int val;
    printf("读入字符(输入0表示当前子树结束)：");
    scanf("%d", &val);
    if (val == 0)
    { //递归结束，建立空树
        *root = NULL;
    }
    else
    {
        (*root) = (BiTNode *)malloc(sizeof(BiTNode)); //生成当前子树的根结点
        // **root->data = val;
        (*root)->data = val;
        PreCreateTree(&(*root)->lchild);
        PreCreateTree(&(*root)->rchild);
    }
}
/**
 * 计算二叉树的深度
 * 1.递归计算左子树的深度记为m
 * 2.递归计算有子树的深度记为n
 * 3.如果m>n，二叉树深度为m+1，否则为n+1
 * */
//这两个全局变量分别用于记录左右子树的深度
int m = 0;
int n = 0;
int Depth(BiTree T)
{
    if (T == NULL)
    { //如果是空树，深度为0，递归结束
        return 0;
    }
    else
    {
        m = Depth(T->lchild); //递归计算左子树的深度记为m
        n = Depth(T->rchild); //递归计算右子树的深度记为n
        if (m > n)
        { //二叉树的深度为m与n的较大者加 1
            return (m + 1);
        }
        else
        {
            return (n + 1);
        }
    }
}