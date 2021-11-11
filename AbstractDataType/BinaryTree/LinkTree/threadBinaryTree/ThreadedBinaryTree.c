#include "threadTreeStruct.c"
#include "stdio.h"
#include "stdlib.h"

// 前序创建一颗二叉树
/**
 * 说明：以字符 0 作为子树的结束
 * 每一次读入一个字符
 * 二叉树字符序列如：123004506007000
 * 按先序次序输入二叉树中结点的值（单个字符），创建二叉树
 * */
void PreCreateTree(BiThrTree *root)
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
        (*root) = (BiThrNode *)malloc(sizeof(BiThrNode)); //生成当前子树的根结点
        // **root->data = val;
        (*root)->data = val;
        PreCreateTree(&(*root)->lchild); //向左递归创建
        PreCreateTree(&(*root)->rchild); //向右递归创建
    }
}
// 中序遍历-递归
void InOrderTraverse(BiThrTree root)
{
    if (root != NULL)
    {
        InOrderTraverse(root->lchild);
        printf("%d\t", root->data);
        InOrderTraverse(root->rchild);
    }
}

/**
 * 以结点p为根的子树中序线索化
 * */
BiThrNode *pre; //全局变量，初始化时其右孩子指针为空，便于在树的最左点开始建线索

void InThreading(BiThrTree p)
{
    if (p)
    {                           //树非空
        InThreading(p->lchild); //左子树递归线索化
        if (!p->lchild)
        {                    //p的左孩子为空
            p->LTag = 1;     //给p加上左线索
            p->lchild = pre; //p的左孩子指针指向pre（前驱）
            // printf("%d\n",p->data);
        }
        else
        {
            p->LTag = 0; //lchild域指示结点的左孩子
            // printf("%d\n", p->data);
        }
        if (!pre->rchild)
        {                    //pre的右孩子为空
            pre->RTag = 1;   //给pre加上右线索
            pre->rchild = p; //pre的右孩子指针指向p（后继）
            // printf("%d\n", p->data);
        }
        else
        {
            pre->RTag = 0; //rchild域指示结点的右孩子
            // printf("%d\n", p->data);
        }
        pre = p;                //保持pre指向p的前驱
        InThreading(p->rchild); //右子树递归线索化
    }
}
//带头结点的二叉树中序线索化
void InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
    // 中序遍历二叉树T，并将其中序线索化，Thrt指向头结点
    (*Thrt) = (BiThrNode *)malloc(sizeof(BiThrNode)); //建立头结点
    (*Thrt)->LTag = 0;                                //头结点有左孩子，若树非空，则其左子树为树根
    (*Thrt)->RTag = 1;                                //头结点的右孩子指针为右线索
    (*Thrt)->rchild = (*Thrt);                        //初始化时右指针指向自己
    if (!T)
    {
        (*Thrt)->lchild = (*Thrt); //若树为空，则左指针也指向自己
    }
    else
    {
        (*Thrt)->lchild = T;   //头结点的左孩子指向根
        pre = (*Thrt);         //pre初值指向头结点
        InThreading(T);        //对以T为根的二叉树进行中序线索化
        pre->rchild = (*Thrt); //调用结束后，pre为最右结点，pre的右线索指向头结点
        pre->RTag = 1;
        (*Thrt)->rchild = pre; //头结点的右线索指向pre
    }
}

/**
 * 遍历中序线索二叉树
 * */
void InOrderTraverse_Thr(BiThrTree T)
{
    // T指向头结点，头结点的左链lchild指向根结点
    // 中序遍历二叉线索树T的非递归算法
    BiThrNode *p = T->lchild; //p指向根结点
    while (p != T)
    { //空树或遍历结束时 p == T
        while (p->LTag == 0)
        {
            p = p->lchild; //沿左孩子向下
        }
        printf("%d\t", p->data); //访问其左子树为空的结点
        while (p->RTag == 1 && p->rchild != T)
        {
            p = p->rchild;
            printf("%d\t", p->data); //沿右线索访问后继结点
        }
        p = p->rchild; //转向p的右子树
    }
}