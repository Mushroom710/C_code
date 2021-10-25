#include "stack/LinkStackMethods.c"

/**
 * 非递归遍历二叉树
*/
//需要使用栈
/**
 * 中序遍历的非递归算法
 * 
 * */
void IterationInOrder(BiTree root)
{
    LinkStack s;
    InitStack(&s);
    BiTree p = root;
    BiTNode *q = (BiTNode *)malloc(sizeof(BiTNode)); //临时结点
    while (p || !isEmpty(s))
    {
        if (p)
        {
            Push(&s, p);  //根结点入栈
            p = p->lchild; //遍历左子树
        }
        else
        {
            Pop(&s, &q);
            printf("%d\t", q->data);
            p = q->rchild; //遍历右子树
        }
    }
}

/**
 * 先序遍历的非递归算法
 * 只需要改动一处代码即可实现
 * */
void IterationPre(BiTree root)
{
    LinkStack s;
    InitStack(&s);
    BiTree p = root;
    BiTNode *q = (BiTNode *)malloc(sizeof(BiTNode)); //临时结点
    while (p || !isEmpty(s))
    {
        if (p)
        {
            Push(&s, p);   //根结点入栈
            printf("%d\t", p->data);//先序遍历，遍历到这个结点，就打印
            p = p->lchild; //遍历左子树
        }
        else
        {
            Pop(&s, &q);
            p = q->rchild; //遍历右子树
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