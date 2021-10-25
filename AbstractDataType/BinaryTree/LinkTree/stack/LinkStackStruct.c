// 路径得写成绝对路径

#include "G:\C_code\AbstractDataType\BinaryTree\LinkTree\BinaryTreeStruct.c"

typedef BiTNode* ElemType;
typedef BiTNode* SElemType;



//链栈存储结构
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;
