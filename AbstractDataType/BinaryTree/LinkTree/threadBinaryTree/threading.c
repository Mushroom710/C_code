#include "ThreadedBinaryTree.c"

void main(){
    BiThrTree root;
    BiThrTree Thrt;
    printf("开始先序建立二叉树：\n");
    PreCreateTree(&root);
    printf("\n未中序线索化\n");
    InOrderTraverse(root);
    printf("\n开始中序线索化。。。\n");
    InOrderThreading(&Thrt,root);
    InOrderTraverse_Thr(Thrt);
    printf("\n");
}