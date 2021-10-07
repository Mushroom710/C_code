//顺序栈的存储结构
#define MAXSIZE 3 //顺序栈初始空间分配量

typedef int SELemType;

typedef struct {
    SELemType *base; // 栈底指针
    SELemType *top; //栈顶指针
    int stacksize; //栈可用的最大容量
} SqStack;
