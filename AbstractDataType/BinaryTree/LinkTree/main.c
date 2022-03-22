#include "stdio.h"
#include "stdlib.h"
//这两个文件分开启用，同时启用会出一堆错误，暂时无法解决
#include "BinaryMethods.c" 
// #include "Iteration.c"


void main()
{
    // BiTree root = (BiTree)malloc(sizeof(BiTNode));
    // root->data = 1;
    // root->lchild = NULL;
    // root->rchild = NULL;
    // BiTNode *node = (BiTNode *)malloc(sizeof(BiTNode));
    // node->data = 2;
    // BiTNode *node1 = (BiTNode *)malloc(sizeof(BiTNode));
    // node1->data = 3;
    // Construction(root, node, node1);
    // BiTNode *node2 = (BiTNode *)malloc(sizeof(BiTNode));
    // BiTNode *node3 = (BiTNode *)malloc(sizeof(BiTNode));
    // BiTNode *node4 = (BiTNode *)malloc(sizeof(BiTNode));
    // BiTNode *node5 = (BiTNode *)malloc(sizeof(BiTNode));
    // node2->data = 4;
    // node3->data = 5;
    // node4->data = 6;
    // node5->data = 7;
    // node2->lchild = NULL;
    // node2->rchild = NULL;

    // node3->lchild = NULL;
    // node3->rchild = NULL;
    // node4->lchild = NULL;
    // node4->rchild = NULL;
    // node5->lchild = NULL;
    // node5->rchild = NULL;
    // Construction(node, node2, node3);
    // Construction(node1,node4,node5);
    // printf("先序遍历：\n");
    // PreTraverse(root);
    // printf("\n");
    // printf("中序遍历；\n");
    // InOrderTraverse(root);
    // printf("\n");
    // printf("后序遍历；\n");
    // AfterTraverse(root);
    // printf("\n");
    // printf("层序遍历；\n");
    // SequenceTraversal(root);
    // printf("\n");

    //这是使用先序遍历的顺序建立二叉树
    BiTree root,copyRoot;
    PreCreateTree(&root);
    // 这一段代码需要引入 BinaryMethod.c文件
    // 如果同时引入BinaryMethod.c和Iteration.c文件会报一堆不明错误
    // 还是分开引入，省事
    // 启用这一截代码需要引入 BinaryMethod.c文件
    printf("先序遍历：\n");
    PreTraverse(root);
    printf("\n中序遍历：\n");
    InOrderTraverse(root);
    printf("\n后序遍历：\n");
    AfterTraverse(root);
    printf("\n层序遍历：\n");
    SequenceTraversal(root);
    printf("\n二叉树的深度：%d\n", Depth(root));
    printf("请输入待搜索的结点：");
    int data;
    scanf("%d",&data);
    BFS(root,data);
    // 启用这一截代码需要引入 Iteration.c文件
    // printf("\n中序非递归遍历：\n");
    // IterationInOrder(root);
    // printf("\n");
    // printf("\n先序非递归遍历：\n");
    // IterationPre(root);
    // printf("\n");
    // printf("\n后序非递归遍历太复杂，暂时不会写：\n");
    // printf("复制一棵二叉树\n");
    // CopyTree(root,&copyRoot);
    // printf("\n遍历复制的二叉树：\n");
    // IterationPre(copyRoot);
    // printf("\n计算二叉树的深度:\n");
    // printf("深度为：%d\n",Depth(root));
    // printf("统计二叉树的结点个数：\n");
    // printf("结点个数为：%d\n",NodeCount(root));
}