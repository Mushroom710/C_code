/**
 * 这是队列的结构代码
 * 使用数组来模拟队列
 * 通过一些技巧来模拟循环队列
 * 
*/

#define MAXSIZE 100 //队列可能到达的最大长度
typedef int QElemType;
typedef struct
{
    QElemType *base; //存储空间基地址
    int front;       //头指针
    int rear;        //尾指针
}SqQueue;
