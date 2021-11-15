/**
 * 哈夫曼树的存储表示
 * */ 
typedef struct{
    int weight; //结点的权值
    int parent;
    int lchild;
    int rchild; //结点的双亲、左孩子、右孩子的下标
}HTNode,*HuffmanTree;