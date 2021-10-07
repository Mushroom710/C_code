typedef int ElemType;
typedef int SElemType;



//链栈存储结构
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;
