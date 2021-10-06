/**
 * 这是双向链表的结构体定义
 * 
*/
#define ElemType int

typedef struct DuLNode
{
    ElemType data;          // 数据域
    struct DuLNode *prior;  // 指向直接前驱
    struct DuLNode *next;   //指向直接后继
}DuLNode,*DuLinkList;
