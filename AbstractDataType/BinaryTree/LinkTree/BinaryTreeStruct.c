// 这是二叉树的存储结构
typedef int TElemType;

typedef struct BiTNode1{
    TElemType data;
    struct BiTNode1 *lchild, *rchild;
} BiTNode, *BiTree;