typedef int TElemType;
/**
 * 二叉树的二叉线索存储表示
 * 规定：
 * LTag: 0 lchild域指示结点的左孩子
 *       1 lchild域指示结点的前驱
 * RTag: 0 rchild域指示结点的右孩子
 *       1 rchild域指示结点的后继
 * */
// 二叉树的二叉线索存储表示
typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild; //左右孩子指针
    int LTag, RTag;                    //左右标志
} BiThrNode, *BiThrTree;