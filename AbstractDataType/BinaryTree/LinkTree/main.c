#include "stdio.h"
#include "stdlib.h"
#include "BinaryMethods.c"


void main()
{
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = 1;
    root->lchild = NULL;
    root->rchild = NULL;
    BiTNode *node = (BiTNode *)malloc(sizeof(BiTNode));
    node->data = 2;
    BiTNode *node1 = (BiTNode *)malloc(sizeof(BiTNode));
    node1->data = 3;
    Construction(root, node, node1);
    BiTNode *node2 = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *node3 = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *node4 = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *node5 = (BiTNode *)malloc(sizeof(BiTNode));
    node2->data = 4;
    node3->data = 5;
    node4->data = 6;
    node5->data = 7;
    node2->lchild = NULL;
    node2->rchild = NULL;

    node3->lchild = NULL;
    node3->rchild = NULL;
    node4->lchild = NULL;
    node4->rchild = NULL;
    node5->lchild = NULL;
    node5->rchild = NULL;
    Construction(node, node2, node3);
    Construction(node1,node4,node5);
    printf("先序遍历：\n");
    PreTraverse(root);
    printf("\n");
    printf("中序遍历；\n");
    InOrderTraverse(root);
    printf("\n");
    printf("后序遍历；\n");
    AfterTraverse(root);
    printf("\n");
    printf("层序遍历；\n");
    SequenceTraversal(root);
    printf("\n");
}