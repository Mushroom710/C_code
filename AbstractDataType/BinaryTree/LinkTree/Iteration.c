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
        /**
         * 说明：因为传过来的是一个指针的地址，所以需要对指针的地址解引用，取值出指针
         * */
        (*root) = (BiTNode *)malloc(sizeof(BiTNode)); //生成当前子树的根结点
        // **root->data = val;
        (*root)->data = val;
        PreCreateTree(&(*root)->lchild);//向左递归创建
        PreCreateTree(&(*root)->rchild);//向右递归创建
    }
}

/**
 * 复制一个二叉树,此用先序的方式
 * */ 

void CopyTree(BiTree T,BiTree* NewT){
    // 复制一棵和T完全相同的二叉树
    if(T == NULL){//空树，递归结束
        *NewT = NULL;
        return;
    }else{
        /**
         * 说明：因为传过来的是一个指针的地址，所以需要对指针的地址解引用，取值出指针
         * */ 
        (*NewT) = (BiTNode *)malloc(sizeof(BiTNode));//分配存储空间
        (*NewT)->data = T->data;
        CopyTree(T->lchild,&(*NewT)->lchild);//向左递归复制左子树
        CopyTree(T->rchild,&(*NewT)->rchild);//向右递归复制右子树
    }
}

/**
 * 计算二叉树的深度
 * 1.递归计算左子树的深度记为m
 * 2.递归计算有子树的深度记为n
 * 3.如果m>n，二叉树深度为m+1，否则为n+1
 * */
//这两个全局变量分别用于记录左右子树的深度
int m;
int n;
int Depth(BiTree T)
{
    if(T == NULL){//如果是空树，深度为0，递归结束
        return 0;
    }else{
        m = Depth(T->lchild);//递归计算左子树的深度记为m
        n = Depth(T->rchild);//递归计算右子树的深度记为n
        if(m>n){//二叉树的深度为m与n的较大者加 1
            return m + 1;
        }else{
            return n + 1;
        }
    }
}

/**
 * 统计二叉树T中的结点个数
 * 实际上等于左右子树的结点个数之和，具有递归性质
 * */ 
int NodeCount(BiTree T){
    // 统计二叉树T中的结点的个数
    if(T == NULL){
        return 0;//如果是空树，则结点个数为0，递归结束
    }else{
        // 否则结点个数为左子树的结点个数+右子树的结点个数+1
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    }
}